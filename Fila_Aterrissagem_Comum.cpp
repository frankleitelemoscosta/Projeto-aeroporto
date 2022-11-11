//
// Created by jeje on 04/10/22.
//

// compile com: g++ Fila_Aterrissagem_Comum.hpp Fila_Aterrissagem_Comum.cpp Fila_jur.hpp Fila_jur.cpp Aviao.hpp Aviao.cpp Pessoa_jur.hpp Pessoa_jur.cpp Pessoa.hpp Pessoa.hpp main.cpp -o ex

#include "Fila_Aterrissagem_Comum.hpp"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
//Construtores:
Fila_Aterrissagem_Comum::Fila_Aterrissagem_Comum()
{
    Aviao* ponta = new Aviao(0, 0, " ");
    dianteira = ponta;
    tamanho=0;
}

Fila_Aterrissagem_Comum::Fila_Aterrissagem_Comum(int num_passageiros, int minutos_de_combustivel, string compania)//"/Declarando método da classe nó que cria a frente da carrinho com um objeto do tipo Node na frente e um objeto na parte de trás que também tem o mesmo valor e da frente.
{
    Aviao* ponta = new Aviao(num_passageiros, minutos_de_combustivel, compania);
    dianteira = ponta;
    tamanho=1;
}

int Fila_Aterrissagem_Comum::Pegar_tamanho() 
{
  return this->tamanho;
}

int Fila_Aterrissagem_Comum::Declarar_tamanho(int tamanho) 
{
  return this->tamanho = tamanho;
}



//Outros Métodos:
bool Fila_Aterrissagem_Comum::vazia() //verifica se a carrinho está vazia
{
    return (ponta == NULL);
}



//Insere elemento no final do carrinho:
void Fila_Aterrissagem_Comum::inserir_final(int num_passageiros, int minutos_de_combustivel, string compania) {
    Aviao *novo_no = new Aviao(num_passageiros, minutos_de_combustivel, compania);
    
    if (vazia()) {
        ponta = novo_no;
        dianteira = novo_no;
    } else {
        dianteira->Declarar_prox(novo_no);
        dianteira = novo_no;
    }

    cout << endl;
    cout << endl;
    cout << "CADASTRO REALIZADO COM SUCESSO!!";
    cout << endl;
    cout << endl;
    this->tamanho+=1;
}

void Fila_Aterrissagem_Comum::mostrar_todos()
{
    Aviao* ponteiro = ponta;

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
                //Mostrar todos os atributos:
                cout<<"Número de passageiros: "<<ponteiro->Pegar_num_passageiros()<<endl;
                cout<<"Minutos de Combustível: "<<ponteiro->Pegar_minutos_de_combustivel()<<endl;
                cout<<"Compania: "<<ponteiro->Pegar_compania()<<endl;
                cout<<"ID: "<<ponteiro->Pegar_ID()<<endl;
                cout<<endl;
                cout<<endl;

            }
            ponteiro = ponteiro->Pegar_prox();
        }
    }
}


void Fila_Aterrissagem_Comum::Buscar_Aviao(int ID)
{
    Aviao* ponteiro = ponta;
    int token_de_busca = 0;

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
                ponteiro = ponteiro->Pegar_prox();
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


int Fila_Aterrissagem_Comum::size()
{
  if(vazia())
  {
    return 0;
  }
  Aviao* p = ponta;
  int tamanho = 0;

  while(p)
  {
    p = p->Pegar_prox();
    tamanho+=1;
  }
  return tamanho;
}

void Fila_Aterrissagem_Comum::remover()
{
  if(!vazia())
  {
    ponta = ponta->Pegar_prox();
    return;
  }

  else
  {
    cout<<"Esta fila está vazia"<<endl<<endl;
  }

}