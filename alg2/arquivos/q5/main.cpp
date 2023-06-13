#include <iostream>
#include <fstream>
#include <list>

using namespace std;
/*5. Considere um arquivo de acesso sequencial ALUNOS1.TXT onde cada linha desse arquivo contém
nome do aluno (string), nome da disciplina cursada (string) e nota obtida (real). Os dados no referido
arquivo não apresentam qualquer tipo de ordenação. Escreva um algoritmo que gere um outro arquivo
de acesso sequencial ALUNOS2.TXT contendo a relação de alunos ordenada alfabeticamente. O
arquivo usado para leitura somente poderá ser lido uma única vez. Utilize uma lista encadeada em
memória para fazer a ordenação dos dados.*/

typedef struct{
    string nome, disc;
    float nota;
}Aluno;

int main(){
    string nome, linha;
    char ch;
    list<string>alunos;
    list<string>::iterator k;
    ifstream fin("alunos1.txt");
    ofstream fout("alunos2.txt");

    while(getline(fin, linha)){
        nome="";
        while(fin.get(ch)){
            if(ch!='.')
                nome += ch;
            else
                break;
        }
        alunos.insert(alunos.begin(), nome);
    }
    alunos.sort();
    for(k = alunos.begin(); k!= alunos.end(); k++){
        fout << *k << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
