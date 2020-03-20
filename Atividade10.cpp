#include <iostream>
#include <fstream>
//Matheus Felipe De Castro Martins

using namespace std;

typedef struct
{
    char nome [50];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
    float media;
} Alunos;

void Escrever()
{
    Alunos aluno;
    char opcao;
    ofstream arq;
    arq.open("alunos.bin", ios::out | ios::binary);
    if(!arq.is_open())
    {
        cout<<"Erro na criacao do arquivo"<<endl;
        //return 1;
    }
    do
    {
        cout<< "Nome: ";
        cin.getline(aluno.nome, 50);
        cout<< "Matricula: ";
        cin>> aluno.matricula;
        cout<<"Nota 1: ";
        cin>>aluno.nota1;
        cout<<"Nota 2: ";
        cin>>aluno.nota2;
        cout<<"Nota 3: ";
        cin>>aluno.nota3;
        arq.write((char *)&aluno, sizeof(Alunos));
        cout<<"Adiiona outro aluno (S/N)? "<<endl;
        cin>>opcao;
        cin.ignore();
    }
    while(toupper(opcao) == 'S');
    arq.close();
}

void Ler()
{
    ifstream arq;
    Alunos aluno;
    arq.open ("alunos.bin", ios::in | ios::binary);
    if(!arq.is_open())
    {
        cout<<"Erro na abertura do arquivo" <<endl;
        // return 1;
    }

    while(arq)
    {
        if(arq.read((char *)&aluno, sizeof(Alunos)))
        {
            cout<<"Nome : "<< aluno.nome <<endl;
            cout<<"Matricula : "<< aluno.matricula <<endl;
            cout<<"Nota 1 : "<< aluno.nota1 <<endl;
            cout<<"Nota 2 : "<< aluno.nota2 <<endl;
            cout<<"Nota 3: "<< aluno.nota3 <<endl;
            aluno.media=(aluno.nota1+aluno.nota2+aluno.nota3)/3;
            cout<<"Media: "<<aluno.media<<endl;

            if(aluno.media>=8.5)
            {
                cout<<"Conceito: Excelente"<<endl;
            }
            else if(aluno.media<8.5 && aluno.media >=7)
            {
                cout<<"Conceito: Bom"<<endl;
            }
            else
            {
                cout<<"Conceito: Preoucupante"<<endl;
            }
        }
    }

}


int main()
{

    Escrever();
    Ler();


    return 0;
}

