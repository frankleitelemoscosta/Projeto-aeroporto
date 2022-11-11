//
// Created by jeje on 04/10/22.
//

// compile com: g++ Fila_Decolagem.hpp Fila_Decolagem.cpp Fila_jur.hpp Fila_jur.cpp Aviao.hpp Aviao.cpp Pessoa_jur.hpp Pessoa_jur.cpp Pessoa.hpp Pessoa.hpp main.cpp -o ex

#include "Fila_Decolagem.hpp"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
//Construtores:
Fila_Decolagem::Fila_Decolagem()
{
    Aviao* ponta = new Aviao(0, 0, " ");
    dianteira = ponta;
    tamanho=0;
}

Fila_Decolagem::Fila_Decolagem(int num_passageiros, int minutos_de_combustivel, string compania)//"/Declarando método da classe nó que cria a frente da carrinho com um objeto do tipo Node na frente e um objeto na parte de trás que também tem o mesmo valor e da frente.
{
    Aviao* ponta = new Aviao(num_passageiros, minutos_de_combustivel, compania);
    dianteira = ponta;
    tamanho=1;
}

int Fila_Decolagem::Pegar_tamanho() 
{
  return this->tamanho;
}

int Fila_Decolagem::Declarar_tamanho(int tamanho) 
{
  return this->tamanho = tamanho;
}



//Outros Métodos:
bool Fila_Decolagem::vazia() //verifica se a carrinho está vazia
{
    return (ponta == NULL);
}



//Insere elemento no final do carrinho:
void Fila_Decolagem::inserir_final(int num_passageiros, int minutos_de_combustivel, string compania) {
    Aviao *novo_no = new Aviao(num_passageiros, minutos_de_combustivel, compania);
    
    //!!! DÚVIDA!!! - é necessário que seja concedido um ID(número aleatório ímpar) e um número que representa quanto tempo aquele avião pode permanecer em vôo
                    //OU é necessaŕio que seja concedido um ID sendo este um número que representa quanto tempo aquele avião pode permanecer em vôo esperando na fila aerea 

    //Gerando ID de um avião que chega em uma lista de espera:
    /*ID - É uma quantidade de tempo ímpar que um avião deve permanecer em uma fila aerea antes de decolar*/
    int ID;

    /*Caso esse ID seja par é importante que consideremos sempre uma quantidade de combustível segura, sendo assim
    fazemos com que o programa interprete que ele tem menos combustível que na realidade*/
    if((novo_no->Pegar_minutos_de_combustivel())%2==0)
    {
        ID = novo_no->Pegar_minutos_de_combustivel();
    }
    else
    {
        ID = novo_no->Pegar_minutos_de_combustivel()-1;
    }

    novo_no->Declarar_ID(ID);


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

void Fila_Decolagem::mostrar_todos()
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


void Fila_Decolagem::Buscar_Aviao(int ID)
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


int Fila_Decolagem::size()
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

void Fila_Decolagem::remover()
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