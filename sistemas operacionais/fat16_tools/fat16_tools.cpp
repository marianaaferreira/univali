#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <cstdint>
#include <cctype>
#include <algorithm>
#include <cstdio>

using namespace std;

#pragma pack(push,1)
struct BPB {
    uint8_t BS_jmpBoot[3];
    uint8_t BS_OEMName[8];
    uint16_t BPB_BytsPerSec;
    uint8_t BPB_SecPerClus;
    uint16_t BPB_RsvdSecCnt;
    uint8_t BPB_NumFATs;
    uint16_t BPB_RootEntCnt;
    uint16_t BPB_TotSec16;
    uint8_t BPB_Media;
    uint16_t BPB_FATSz16;
    uint16_t BPB_SecPerTrk;
    uint16_t BPB_NumHeads;
    uint32_t BPB_HiddSec;
    uint32_t BPB_TotSec32;
    uint8_t BS_DrvNum;
    uint8_t BS_Reserved1;
    uint8_t BS_BootSig;
    uint32_t BS_VolID;
    uint8_t BS_VolLab[11];
    uint8_t BS_FilSysType[8];
};

struct DirEntry {
    uint8_t Name[11];
    uint8_t Attr;
    uint8_t NTRes;
    uint8_t CrtTimeTenth;
    uint16_t CrtTime;
    uint16_t CrtDate;
    uint16_t LstAccDate;
    uint16_t FstClusHI;
    uint16_t WrtTime;
    uint16_t WrtDate;
    uint16_t FstClusLO;
    uint32_t FileSize;
};
#pragma pack(pop)

static const uint8_t ATTR_READ_ONLY = 0x01;
static const uint8_t ATTR_HIDDEN = 0x02;    
static const uint8_t ATTR_SYSTEM = 0x04;
static const uint8_t ATTR_VOLUME_ID = 0x08;
static const uint8_t ATTR_DIRECTORY = 0x10;
static const uint8_t ATTR_ARCHIVE = 0x20;

struct FAT16 {
    BPB bpb;
    uint32_t firstRootSector;
    uint32_t rootDirSectors;
    uint32_t firstDataSector;
    uint32_t dataSectors;
    uint32_t totalClusters;
    uint32_t fatOffsetBytes;
    uint32_t rootDirOffsetBytes;
    uint32_t dataOffsetBytes;
    vector<uint8_t> fat;
};


string trim_string(const string& s) {
    size_t i = 0; while (i < s.size() && isspace((unsigned char)s[i])) i++;
    size_t j = s.size(); while (j > i && isspace((unsigned char)s[j - 1])) j--;
    return s.substr(i, j - i);
}

string dos_name_to_string(const uint8_t name[11]) {
    string s;
    if (name[0] == 0x00) return string();
    if (name[0] == 0xE5) s.push_back('?');
    for (int i = 0; i < 8; i++) if (name[i] != ' ') s.push_back(name[i]);
    string ext;
    for (int i = 8; i < 11; i++) if (name[i] != ' ') ext.push_back(name[i]);
    if (!ext.empty()) s += "." + ext;
    return s;
}

void string_to_dos_name(const string& in, uint8_t out[11]) {
    string name = in;
    for (auto& c : name) c = toupper((unsigned char)c);
    string part = name, ext;
    size_t pos = name.find('.');
    if (pos != string::npos) { part = name.substr(0, pos); ext = name.substr(pos + 1); }
    memset(out, ' ', 11);
    for (size_t i = 0; i < part.size() && i < 8; i++) out[i] = part[i];
    for (size_t i = 0; i < ext.size() && i < 3; i++) out[8 + i] = ext[i];
}

string dos_date_time_to_string(uint16_t dosDate, uint16_t dosTime) {
    if (dosDate == 0 && dosTime == 0) return "(n/a)";
    int day = dosDate & 0x1F;
    int month = (dosDate >> 5) & 0x0F;
    int year = ((dosDate >> 9) & 0x7F) + 1980;
    int second = (dosTime & 0x1F) * 2;
    int minute = (dosTime >> 5) & 0x3F;
    int hour = (dosTime >> 11) & 0x1F;
    char buf[64];
    sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);
    return string(buf);
}

// Read BPB from image
bool load_bpb(istream& f, FAT16& fs) {
    f.seekg(0, ios::beg);
    BPB bpb;
    f.read((char*)&bpb, sizeof(BPB));
    if (!f) return false;
    fs.bpb = bpb;
    uint16_t BytesPerSector = bpb.BPB_BytsPerSec;
    uint8_t SecPerClus = bpb.BPB_SecPerClus;
    uint16_t RsvdSecCnt = bpb.BPB_RsvdSecCnt;
    uint8_t NumFATs = bpb.BPB_NumFATs;
    uint16_t RootEntCnt = bpb.BPB_RootEntCnt;
    uint16_t FATSz16 = bpb.BPB_FATSz16;
    uint32_t TotSec = (bpb.BPB_TotSec16 != 0) ? bpb.BPB_TotSec16 : bpb.BPB_TotSec32;
    fs.rootDirSectors = ((RootEntCnt * 32) + (BytesPerSector - 1)) / BytesPerSector;
    fs.firstRootSector = RsvdSecCnt + (NumFATs * FATSz16);
    fs.firstDataSector = fs.firstRootSector + fs.rootDirSectors;
    fs.dataSectors = TotSec - (RsvdSecCnt + (NumFATs * FATSz16) + fs.rootDirSectors);
    fs.totalClusters = fs.dataSectors / SecPerClus;
    fs.fatOffsetBytes = RsvdSecCnt * BytesPerSector;
    fs.rootDirOffsetBytes = fs.firstRootSector * BytesPerSector;
    fs.dataOffsetBytes = fs.firstDataSector * BytesPerSector;
    // read first FAT into memory
    fs.fat.resize(FATSz16 * BytesPerSector);
    f.seekg(fs.fatOffsetBytes, ios::beg);
    f.read((char*)fs.fat.data(), fs.fat.size());
    return true;
}

uint16_t fat_get(const FAT16& fs, uint16_t cluster) {
    size_t off = cluster * 2;
    if (off + 1 >= fs.fat.size()) return 0xFFFF;
    return fs.fat[off] | (fs.fat[off + 1] << 8);
}

void fat_set_in_memory(FAT16& fs, uint16_t cluster, uint16_t val) {
    size_t off = cluster * 2;
    if (off + 1 >= fs.fat.size()) return;
    fs.fat[off] = val & 0xFF;
    fs.fat[off + 1] = (val >> 8) & 0xFF;
}

// Write FAT from memory back to disk (first FAT only)
void flush_fat(fstream& f, FAT16& fs) {
    f.seekp(fs.fatOffsetBytes, ios::beg);
    f.write((char*)fs.fat.data(), fs.fat.size());
    // also update all FAT copies
    for (int i = 1; i < fs.bpb.BPB_NumFATs; i++) {
        uint32_t off = fs.fatOffsetBytes + i * fs.bpb.BPB_FATSz16 * fs.bpb.BPB_BytsPerSec;
        f.seekp(off, ios::beg);
        f.write((char*)fs.fat.data(), fs.fat.size());
    }
    f.flush();
}

// Read directory entry at index (root entries)
bool read_root_entry(istream& f, const FAT16& fs, int index, DirEntry& de) {
    uint32_t off = fs.rootDirOffsetBytes + index * sizeof(DirEntry);
    f.seekg(off, ios::beg);
    f.read((char*)&de, sizeof(DirEntry));
    return f.good();
}

bool write_root_entry(fstream& f, const FAT16& fs, int index, const DirEntry& de) {
    uint32_t off = fs.rootDirOffsetBytes + index * sizeof(DirEntry);
    f.seekp(off, ios::beg);
    f.write((char*)&de, sizeof(DirEntry));
    f.flush();
    return f.good();
}

int root_entry_count(const FAT16& fs) {
    return fs.bpb.BPB_RootEntCnt;
}

// Find free root entry index, or -1
int find_free_root_entry(fstream& f, FAT16& fs) {
    int cnt = root_entry_count(fs);
    for (int i = 0; i < cnt; i++) {
        DirEntry de;
        read_root_entry(f, fs, i, de);
        if (de.Name[0] == 0x00 || de.Name[0] == 0xE5) {
            return i;
        }
    }
    return -1;
}

// Read cluster content into buffer (cluster number >=2)
vector<uint8_t> read_cluster(istream& f, const FAT16& fs, uint16_t cluster) {
    uint32_t BytesPerSector = fs.bpb.BPB_BytsPerSec;
    uint32_t SecPerClus = fs.bpb.BPB_SecPerClus;
    uint32_t firstSectorOfCluster = fs.firstDataSector + (cluster - 2) * SecPerClus;
    uint32_t off = firstSectorOfCluster * BytesPerSector;
    size_t size = BytesPerSector * SecPerClus;
    vector<uint8_t> buf(size);
    f.seekg(off, ios::beg);
    f.read((char*)buf.data(), size);
    return buf;
}

void write_cluster(fstream& f, const FAT16& fs, uint16_t cluster, const vector<uint8_t>& buf) {
    uint32_t BytesPerSector = fs.bpb.BPB_BytsPerSec;
    uint32_t SecPerClus = fs.bpb.BPB_SecPerClus;
    uint32_t firstSectorOfCluster = fs.firstDataSector + (cluster - 2) * SecPerClus;
    uint32_t off = firstSectorOfCluster * BytesPerSector;
    size_t size = BytesPerSector * SecPerClus;
    f.seekp(off, ios::beg);
    f.write((char*)buf.data(), size);
    f.flush();
}

// Follow FAT chain and return clusters vector
vector<uint16_t> get_chain(const FAT16& fs, uint16_t start) {
    vector<uint16_t> chain;
    if (start < 2) return chain;
    uint16_t cur = start;
    while (cur < 0xFFF8) {
        chain.push_back(cur);
        uint16_t next = fat_get(fs, cur);
        if (next == 0x0000) break;
        if (next >= 0xFFF8) break;
        cur = next;
    }
    return chain;
}

// Free chain: set FAT entries to 0
void free_chain(FAT16& fs, uint16_t start) {
    if (start < 2) return;
    uint16_t cur = start;
    while (cur < 0xFFF8) {
        uint16_t next = fat_get(fs, cur);
        fat_set_in_memory(fs, cur, 0x0000);
        if (next >= 0xFFF8 || next == 0x0000) break;
        cur = next;
    }
}

// Allocate N clusters, return vector of allocated cluster numbers, or empty if not enough
vector<uint16_t> allocate_clusters(FAT16& fs, size_t n) {
    vector<uint16_t> alloc;
    uint32_t maxClusters = fs.totalClusters + 2;
    for (uint16_t c = 2; c < maxClusters && alloc.size() < n; c++) {
        if (fat_get(fs, c) == 0x0000) {
            alloc.push_back(c);
        }
    }
    if (alloc.size() < n) return {};
    for (size_t i = 0; i < alloc.size(); i++) {
        uint16_t next = (i + 1 < alloc.size()) ? alloc[i + 1] : 0xFFF8;
        fat_set_in_memory(fs, alloc[i], next);
    }
    return alloc;
}

// Helper to print attributes
string attributes_to_string(uint8_t attr) {
    vector<string> parts;
    if (attr & ATTR_READ_ONLY) parts.push_back("READ_ONLY");
    if (attr & ATTR_HIDDEN) parts.push_back("HIDDEN");
    if (attr & ATTR_SYSTEM) parts.push_back("SYSTEM");
    if (attr & ATTR_VOLUME_ID) parts.push_back("VOLUME_ID");
    if (attr & ATTR_DIRECTORY) parts.push_back("DIRECTORY");
    if (attr & ATTR_ARCHIVE) parts.push_back("ARCHIVE");
    if (parts.empty()) return string("NONE");
    string out;
    for (size_t i = 0; i < parts.size(); i++) {
        if (i) out += ",";
        out += parts[i];
    }
    return out;
}

// Command implementations
void cmd_list(istream& fin, FAT16& fs) {
    int cnt = root_entry_count(fs);
    cout << left << setw(20) << "NAME" << setw(10) << "SIZE" << "ATTR" << "\n";
    for (int i = 0; i < cnt; i++) {
        DirEntry de;
        read_root_entry(fin, fs, i, de);
        if (de.Name[0] == 0x00) break;
        if (de.Name[0] == 0xE5) continue;
        if (de.Attr & ATTR_VOLUME_ID) continue;
        if (de.Attr & ATTR_DIRECTORY) continue;
        string name = dos_name_to_string(de.Name);
        if (name.empty()) continue;
        cout << left << setw(20) << name << setw(10) << de.FileSize << attributes_to_string(de.Attr) << "\n";
    }
}

// find root entry index by filename (8.3 or name.ext case-insensitive)
int find_root_entry_index(istream& f, FAT16& fs, const string& filename) {
    uint8_t dn[11];
    string_to_dos_name(filename, dn);
    int cnt = root_entry_count(fs);
    for (int i = 0; i < cnt; i++) {
        DirEntry de;
        read_root_entry(f, fs, i, de);
        if (de.Name[0] == 0x00) break;
        if (de.Name[0] == 0xE5) continue;
        if (memcmp(de.Name, dn, 11) == 0) return i;
    }
    return -1;
}

void cmd_cat(istream& fin, FAT16& fs, const string& filename) {
    int idx = find_root_entry_index(fin, fs, filename);
    if (idx < 0) { cout << "Arquivo nao encontrado\n"; return; }
    DirEntry de;
    read_root_entry(fin, fs, idx, de);
    uint16_t start = de.FstClusLO;
    if (start < 2) {
        if (de.FileSize == 0) return;
        cout << "(arquivo sem cluster)\n";
        return;
    }
    vector<uint16_t> chain = get_chain(fs, start);
    uint32_t bytesLeft = de.FileSize;
    for (uint16_t c : chain) {
        vector<uint8_t> buf = read_cluster(fin, fs, c);
        size_t toWrite = std::min<size_t>(buf.size(), bytesLeft);
        cout.write((char*)buf.data(), toWrite);
        bytesLeft -= toWrite;
        if (bytesLeft == 0) break;
    }
    cout.flush();
}

void cmd_attrs(istream& fin, FAT16& fs, const string& filename) {
    int idx = find_root_entry_index(fin, fs, filename);
    if (idx < 0) { cout << "Arquivo nao encontrado\n"; return; }
    DirEntry de;
    read_root_entry(fin, fs, idx, de);
    string name = dos_name_to_string(de.Name);
    cout << "Nome: " << name << "\n";
    cout << "Tamanho: " << de.FileSize << " bytes\n";
    cout << "Atributos: " << attributes_to_string(de.Attr) << "\n";
    cout << "Criacao: " << dos_date_time_to_string(de.CrtDate, de.CrtTime) << "\n";
    cout << "Ultima Modificacao: " << dos_date_time_to_string(de.WrtDate, de.WrtTime) << "\n";
}

void cmd_rename(fstream& f, FAT16& fs, const string& oldn, const string& newn) {
    int idx = find_root_entry_index(f, fs, oldn);
    if (idx < 0) { cout << "Arquivo nao encontrado\n"; return; }
    DirEntry de;
    read_root_entry(f, fs, idx, de);
    uint8_t newdn[11];
    string_to_dos_name(newn, newdn);
    memcpy(de.Name, newdn, 11);
    write_root_entry(f, fs, idx, de);
    cout << "Renomeado: " << oldn << " -> " << newn << "\n";
}

void cmd_delete(fstream& f, FAT16& fs, const string& name) {
    int idx = find_root_entry_index(f, fs, name);
    if (idx < 0) { cout << "Arquivo nao encontrado\n"; return; }
    DirEntry de;
    read_root_entry(f, fs, idx, de);
    uint16_t start = de.FstClusLO;
    DirEntry de2 = de;
    de2.Name[0] = 0xE5;
    write_root_entry(f, fs, idx, de2);
    if (start >= 2) {
        free_chain(fs, start);
        flush_fat(f, fs);
    }
    cout << "Arquivo apagado: " << name << "\n";
}

void cmd_create(fstream& f, FAT16& fs, const string& name, const string& localfile) {
    ifstream in(localfile, ios::binary);
    if (!in) { cout << "Nao foi possivel abrir arquivo local: " << localfile << "\n"; return; }
    in.seekg(0, ios::end);
    streampos s = in.tellg();
    size_t size = (s > 0) ? (size_t)s : 0;
    in.seekg(0, ios::beg);
    vector<uint8_t> data(size);
    if (size > 0) in.read((char*)data.data(), size);
    // find free root entry
    int ridx = find_free_root_entry(f, fs);
    if (ridx < 0) { cout << "Sem entrada livre no diretorio raiz\n"; return; }
    uint32_t bytesPerCluster = fs.bpb.BPB_BytsPerSec * fs.bpb.BPB_SecPerClus;
    size_t clustersNeeded = (size + bytesPerCluster - 1) / bytesPerCluster;
    vector<uint16_t> alloc = allocate_clusters(fs, clustersNeeded);
    if (alloc.empty()) { cout << "Sem clusters livres suficientes\n"; return; }
    size_t off = 0;
    for (size_t i = 0; i < alloc.size(); i++) {
        vector<uint8_t> buf(bytesPerCluster, 0);
        size_t toCopy = std::min<size_t>(bytesPerCluster, (size > off) ? size - off : 0);
        if (toCopy > 0) memcpy(buf.data(), data.data() + off, toCopy);
        write_cluster(f, fs, alloc[i], buf);
        off += toCopy;
    }
    DirEntry de;
    memset(&de, 0, sizeof(de));
    string_to_dos_name(name, de.Name);
    de.Attr = ATTR_ARCHIVE;
    de.FstClusHI = 0;
    de.FstClusLO = alloc[0];
    de.FileSize = size;
    write_root_entry(f, fs, ridx, de);
    flush_fat(f, fs);
    cout << "Criado arquivo: " << name << " tamanho=" << size << " bytes\n";
}

int main() {
    ios::sync_with_stdio(false);
    string image;
    cout << "Digite o nome da imagem FAT16: ";
    cin >> image;

    fstream f(image, ios::in | ios::out | ios::binary);
    if (!f) {
        cerr << "Nao foi possivel abrir imagem: " << image << "\n";
        return 1;
    }

    FAT16 fs;
    if (!load_bpb(f, fs)) {
        cerr << "Falha ao ler BPB\n";
        return 1;
    }

    while (true) {
        cout << "\nComandos disponiveis:\n";
        cout << "1) list\n2) cat <file>\n3) attrs <file>\n4) rename <old> <new>\n5) delete <file>\n6) create <name> <localfile>\n7) exit\n";
        cout << "Escolha uma opcao: ";
        string cmd;
        cin >> cmd;

        if (cmd == "list") cmd_list(f, fs);
        else if (cmd == "cat") {
            string fname; cin >> fname;
            cmd_cat(f, fs, fname);
        }
        else if (cmd == "attrs") {
            string fname; cin >> fname;
            cmd_attrs(f, fs, fname);
        }
        else if (cmd == "rename") {
            string oldn, newn; cin >> oldn >> newn;
            cmd_rename(f, fs, oldn, newn);
        }
        else if (cmd == "delete") {
            string fname; cin >> fname;
            cmd_delete(f, fs, fname);
        }
        else if (cmd == "create") {
            string newn, localfile; cin >> newn >> localfile;
            cmd_create(f, fs, newn, localfile);
        }
        else if (cmd == "exit") break;
        else cout << "Comando invalido\n";
    }

    return 0;
}
