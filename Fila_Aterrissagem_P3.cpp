//
// Created by jeje on 04/10/22.
//

// compile com: g++ Fila_Aterrissagem_P3.hpp Fila_Aterrissagem_P3.cpp Fila_jur.hpp Fila_jur.cpp Aviao.hpp Aviao.cpp Pessoa_jur.hpp Pessoa_jur.cpp Pessoa.hpp Pessoa.hpp main.cpp -o ex

//inicio das bibliotecas
    #include "Fila_Aterrissagem_P3.hpp"
    #include <iostream>
    #include <string>
    #include <cstring>
    using namespace std;
//fim das bibliotecas

//Construtores:
Fila_Aterrissagem_P3::Fila_Aterrissagem_P3()
{
    dianteira = nullptr;
    ponta = nullptr;
}


int Fila_Aterrissagem_P3::Pegar_tamanho() 
{
  return this->tamanho;
}

int Fila_Aterrissagem_P3::Inserir_tamanho(int tamanho) 
{
  return this->tamanho = tamanho;
}



//Outros Métodos:
bool Fila_Aterrissagem_P3::vazia() //verifica se a carrinho está vazia
{
    return (ponta == nullptr);
}



//Insere elemento no final do carrinho:
void Fila_Aterrissagem_P3::inserir_final(int num_passageiros, int minutos_de_combustivel, string companhia) {

    Aviao *novo_no = new Aviao(num_passageiros, minutos_de_combustivel, companhia);
    
    if (vazia()) {
        ponta = novo_no;
        dianteira = novo_no;
    } else {
        dianteira->Inserir_proximo(novo_no);
        dianteira = novo_no;
    }

    cout << endl;
    cout << endl;
    cout << "CADASTRO REALIZADO COM SUCESSO!!";
    cout << endl;
    cout << endl;
    this->tamanho+=1;
}

void Fila_Aterrissagem_P3::mostrar_todos()
{
    Aviao *ponteiro = ponta;

    int contador = 0;

    cout<<endl<<endl<<endl;
    cout<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~Fila Aterrisagem~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
    if(vazia())
    {
        cout<<"A pista está vazia!"<<endl<<endl;
    }
    else
    {
        while(ponteiro)
        {
            if(ponteiro->Pegar_num_passageiros()!=0)
            {
                //Mostrar todos os atributos:contador+=1;
                cout<<"Avião número: "<<contador<<endl;
                cout<<"Número de passageiros: "<<ponteiro->Pegar_num_passageiros()<<endl;
                cout<<"Minutos de Combustível: "<<ponteiro->Pegar_minutos_de_combustivel()<<endl;
                cout<<"Compania: "<<ponteiro->Pegar_companhia()<<endl;
                cout<<"ID: "<<ponteiro->Pegar_ID()<<endl;
                cout<<endl;
                cout<<endl;

            }
            ponteiro = ponteiro->Pegar_proximo();
        }
    }    
    cout<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
}


void Fila_Aterrissagem_P3::Buscar_Aviao(int ID)
{
    //inicio das variaveis
        Aviao *ponteiro = new Aviao();
        ponteiro = ponta;
        int token_de_busca = 0;
    //fim das variaveis

    if(vazia())
    {
        cout<<"Não há ninguém nesta pista!";
    }
    else
    {
        while(ponteiro)
        {
            if(ponteiro->Pegar_ID()==ID)
            {
                //Mostrar todos os atributos:
                cout<<"O ID está presente em uma pista de aterrissagem!"<<endl;
                token_de_busca = 1;
                break;
            }
            else
            {
                ponteiro = ponteiro->Pegar_proximo();
                token_de_busca = 0;
            }
        }
        if(token_de_busca == 1)
        {
            token_de_busca=1;
        }
        else
        {
            cout<<"Não foi possível encontrar esta pessoa na fila!!";
        }
    }
}


int Fila_Aterrissagem_P3::size()
{
    if(vazia())
    {
        return 0;
    }
    //inicio das variaveis locais
    Aviao* ponteiro = ponta;
    int tamanho = 0;
    //fim das variaveis locais

    while(ponteiro)
    {
        tamanho++;
        ponteiro = ponteiro->Pegar_proximo();
    }
    return tamanho;
}

void Fila_Aterrissagem_P3::remover()
{
    Aviao *ponteiro = ponta; 

    if(vazia()==false)
    {
        if(ponta->Pegar_minutos_de_combustivel() <=0)
        cout<<"um avião tinha 0 de combustivel porque foi levado pela alcaida, ele não caiu"<<endl;
    }

    if(vazia()==false)
    {
        cout<<"Acaba de aterrissar um avião por emergencia!!!!!!!!!!!!!!!!"<<endl;
        ponta = ponta->Pegar_proximo();
        free(ponteiro);
        return;
    }

    else
    {
        cout<<"Esta fila da pista 3 está vazia"<<endl<<endl;
    }

}

//fim do código