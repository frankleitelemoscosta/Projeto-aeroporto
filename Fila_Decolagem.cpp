//
// Created by jeje on 04/10/22.
//

// compile com: g++ Fila_Decolagem.hpp Fila_Decolagem.cpp Fila_jur.hpp Fila_jur.cpp Aviao.hpp Aviao.cpp Pessoa_jur.hpp Pessoa_jur.cpp Pessoa.hpp Pessoa.hpp main.cpp -o ex

//inicio das bibliotecas
    #include "Fila_Decolagem.hpp"
    #include <iostream>
    #include <string>
    #include <cstring>
//fim das bibliotecas

using namespace std;
//Construtores:
Fila_Decolagem::Fila_Decolagem()
{
    dianteira = nullptr;
    ponta = nullptr;
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
void Fila_Decolagem::inserir_final(int id) {
    Aviao *novo_no = new Aviao();
    
     int ID,erro=1,espera_estimada_minutos;

    //Criar um número de espera para os aviões de pista de Decolagem que siga o parâmetro apresentado pelo Frank no quadro, ou seja
        //Veja quantos aviões estão em sua frente... o número estimado de espera é igual ao número de aviões
        //em sua frente +1:
    
    espera_estimada_minutos = this->size()+1;
    novo_no->Inserir_espera_para_decolagem(espera_estimada_minutos);

    while(erro==1)
    {
        cout<<"Insira aqui um ID par para o seu avião:";
        cin>>ID;
        novo_no->Inserir_ID(ID);
        
        if(ID%2!=0)
            erro=1;
        
        else
        {
            erro=0;
        }
    
    }


    if (vazia()) {
        ponta = novo_no;
        dianteira = novo_no;
        dianteira->Inserir_proximo(nullptr);
    } else {
        dianteira->Inserir_proximo(novo_no);
        dianteira = novo_no;
        dianteira->Inserir_proximo(nullptr);
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
    
    int contador = 0;

    cout<<endl<<endl<<endl;
    cout<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~Fila Decolagem~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;

    if(vazia())
    {
        cout<<"A pista está vazia!"<<endl<<endl;
    }
    else
    {
        while(ponteiro)
        {   
                //Mostrar todos os atributos:contador+=1;
                cout<<"Avião número: "<<contador<<endl;
                cout<<"Número de passageiros: "<<ponteiro->Pegar_num_passageiros()<<endl;
                cout<<"Minutos de Combustível: "<<ponteiro->Pegar_minutos_de_combustivel()<<endl;
                cout<<"Compania: "<<ponteiro->Pegar_companhia()<<endl;
                cout<<"ID: "<<ponteiro->Pegar_ID()<<endl;
                cout<<endl;
                cout<<endl;

            
            ponteiro = ponteiro->Pegar_proximo();
        }
    }

    cout<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;

}


int Fila_Decolagem::size()
{
  
    if(vazia())
    {
        return 0;
    }
    
    //inicio das variaveis locais
    Aviao *ponteiro =  ponta;
    int tamanho = 0;
    //fim das variaveis locais

    while(ponteiro)
    {
        ponteiro = ponteiro->Pegar_proximo();
        tamanho+=1;
    }

    return tamanho;

}

void Fila_Decolagem::remover()
{

    Aviao *ponteiro = new Aviao();
    ponteiro = ponta;

    if(!vazia())
    {
        ponta = ponta->Pegar_proximo();
        free(ponteiro);
        return;
    }

    else
    {
        cout<<"Esta fila está vazia"<<endl<<endl;
    }

}

//fim do codigo