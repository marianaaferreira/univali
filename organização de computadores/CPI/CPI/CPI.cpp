#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void calculaciclos(int& qtd_ciclos, string mnemonico) {
    //r-type and i-type
    if (mnemonico == "ADD" || mnemonico == "ADDI")
        qtd_ciclos += 4;
    //load instructions
    else if (mnemonico == "LW")
        qtd_ciclos += 5;
    else if (mnemonico == "LHU")
        qtd_ciclos += 5;
    else if (mnemonico == "LH")
        qtd_ciclos += 5;
    else if (mnemonico == "LBU")
        qtd_ciclos += 5;
    else if (mnemonico == "LB")
        qtd_ciclos += 5;
    //store instructions
    else if (mnemonico == "SW")
        qtd_ciclos += 4;
    else if (mnemonico == "SH")
        qtd_ciclos += 4;
    else if (mnemonico == "SB")
        qtd_ciclos += 4;
    //jump instructions
    else if (mnemonico == "JR")
        qtd_ciclos += 3;
    else if (mnemonico == "JALR")
        qtd_ciclos += 3;
    else if (mnemonico == "JAL")
        qtd_ciclos += 3;
    else if (mnemonico == "J")
        qtd_ciclos += 3;
    //branch instructions
    else if (mnemonico == "BNE")
        qtd_ciclos += 3;
    else if (mnemonico == "BLEZ")
        qtd_ciclos += 3;
    else if (mnemonico == "BGTZ")
        qtd_ciclos += 3;
    else if (mnemonico == "BEQ")
        qtd_ciclos += 3;

}

string mnemonico(string bits) {
    if (bits == "100000")
        return "ADD";
    if (bits == "100011")
        return "LW";
    if (bits == "101011")
        return "SW";
    if (bits == "101001")
        return "SH";
    if (bits == "101000")
        return "SB";
    if (bits == "100101")
        return "LHU";
    if (bits == "100001")
        return "LH";
    if (bits == "100100")
        return "LBU";
    if (bits == "100000")
        return "LB";
    if (bits == "001000")
        return "JR";
    if (bits == "001001")
        return "JALR";
    if (bits == "000011")
        return "JAL";
    if (bits == "000010")
        return "J";
    if (bits == "000101")
        return "BNE";
    if (bits == "000110")
        return "BLEZ";
    if (bits == "000111")
        return "BGTZ";
    if (bits == "000100")
        return "BEQ";
    return "";
}

int main(){
    string linha, opcode, funct;
    int qtd_ciclos=0, qtd_inst=0;
    float cpi;
    ifstream fin("instrucoes.txt");

    if (!fin) {
        cout << "arquivo nao pode ser aberto"; exit(0);
    }

    while(getline(fin, linha)){
        cout << linha << endl;
        opcode = linha.substr(0, 6);
        if (opcode == "000000") { // R-type instruction
            funct = linha.substr(25, 6);
            calculaciclos(qtd_ciclos, mnemonico(funct));
        }
        else
            calculaciclos(qtd_ciclos, mnemonico(opcode));
        qtd_inst++;
    }

    cpi = float(qtd_ciclos) / qtd_inst;
    cout << cpi;


    fin.close();
    return 0;
}