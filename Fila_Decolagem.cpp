//
// Created by jeje on 04/10/22.
//

// compile com: g++ Fila_Decolagem.hpp Fila_Decolagem.cpp Fila_jur.hpp Fila_jur.cpp Aviao.hpp Aviao.cpp Pessoa_jur.hpp Pessoa_jur.cpp Pessoa.hpp Pessoa.hpp main.cpp -o ex

//inicio das bibliotecas
    #include "Fila_Decolagem.hpp"
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <iomanip>
//fim das bibliotecas

using namespace std;
//Construtores:
Fila_Decolagem::Fila_Decolagem()
{
    dianteira = nullptr;
    ponta = nullptr;
    contador_decolagem1 = 1;
    contador_decolagem2 = 1;
    contador_decolagem3 = 1;
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
    return (ponta == nullptr);
}



//Insere elemento no final do carrinho:
void Fila_Decolagem::inserir_final(int id,int fila, int minutos_combustivel ,int numero_passageiros, string nome_da_companhia) {
   
    Aviao *novo_no = new Aviao();
    
     int espera_estimada_minutos;

    //Criar um número de espera para os aviões de pista de Decolagem que siga o parâmetro apresentado pelo Frank no quadro, ou seja
        //Veja quantos aviões estão em sua frente... o número estimado de espera é igual ao número de aviões
        //em sua frente +1:
    
    espera_estimada_minutos = this->size()+1;
    novo_no->Inserir_espera_para_decolagem(espera_estimada_minutos);


    if (vazia()) {
        ponta = novo_no;
        dianteira = novo_no;
        dianteira->Inserir_proximo(nullptr);
    } else {
        dianteira->Inserir_proximo(novo_no);
        dianteira = novo_no;
        dianteira->Inserir_proximo(nullptr);
    }

    dianteira->Inserir_ID(id);
    dianteira->Inserir_companhia(nome_da_companhia);
    dianteira->Inserir_minutos_de_combustivel(minutos_combustivel);
    dianteira->Inserir_num_passageiros(numero_passageiros);
    dianteira->Iniciando_tempo_aterrissagem();
    dianteira->Inserir_identificador_fila(fila);
    dianteira->Iniciando_tempo_decolagem();


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
                //Mostrar todos os atributos:
                contador+=1;
                cout<<"Avião número: "<<contador<<endl;
                cout<<"Número de passageiros: "<<ponteiro->Pegar_num_passageiros()<<endl;
                cout<<"Minutos de Combustível: "<<ponteiro->Pegar_minutos_de_combustivel()<<endl;
                cout<<"Compania: "<<ponteiro->Pegar_companhia()<<endl;
                cout<<"ID: "<<ponteiro->Pegar_ID()<<endl;
                cout<<"fila a qual pertence: "<<ponteiro->Pegar_fila_aviao();
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
        if(ponta->Pegar_fila_aviao()==1)
        {
            this->contador_decolagem1 = this->contador_decolagem1 + 1;
        }
        else if(ponta->Pegar_fila_aviao()==2)
        {
            this->contador_decolagem2 = this->contador_decolagem2 + 1;
        }
        else if(ponta->Pegar_fila_aviao()==3)
        {
            this->contador_decolagem3 = this->contador_decolagem3 + 1;
        }
    }

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

void Fila_Decolagem::aumentar_tempo()
{
    Aviao *ponteiro = ponta;

    if(!vazia())
    {
        while(ponteiro)
        {
            ponteiro->Aumentar_tempo_decolagem();

            ponteiro = ponteiro->Pegar_proximo();
        }
    }
}

void Fila_Decolagem::tempo_medio(int pista)
{
    Aviao *ponteiro = ponta;
    float tempo_medio1;
    float tempo_medio2;
    float tempo_medio3;

    if(!vazia())
    {
        while(ponteiro)
        {
        if(ponteiro->Pegar_fila_aviao()==1)
            {
                this->Numerador1 = this->Numerador1 + ponteiro->Pegar_tempo_aterrissagem();
                        
            }
            else if(ponteiro->Pegar_fila_aviao()==2)
            {
                this->Numerador2 = this->Numerador2 + ponteiro->Pegar_tempo_aterrissagem();
                        
            }
            else if(ponteiro->Pegar_fila_aviao()==3)
            {
                this->Numerador3 = this->Numerador3 + ponteiro->Pegar_tempo_aterrissagem();

            }
                    
            ponteiro = ponteiro->Pegar_proximo();
        }

                //procedimento para calcular tempo medio de aterrissagem na fila
                    if(pista==1)
                    {
                        tempo_medio1 = this->Numerador1/this->contador_decolagem1;
                        cout<<setprecision(2)<<"Tempo médio de decola para pista1: "<<tempo_medio1<<" minutos"<<endl;
                        cout<<endl;
                        cout<<endl;
                    }
                //fim do procedimento

            
                //procedimento para calcular tempo medio de aterrissagem na fila dois
                    if(pista==2)
                    {
                        tempo_medio2 = this->Numerador2/this->contador_decolagem2;
                        cout<<setprecision(2)<<"Tempo médio de Decolagem na pista2: "<<tempo_medio2<<" minutos"<<endl;
                        cout<<endl;
                        cout<<endl;
                    }
                //fim do procedimento


                //procedimento para calcular tempo medio de aterrissagem na fila três
                    if(pista==3)
                    {
                        tempo_medio3 = this->Numerador3/this->contador_decolagem3;
                        cout<<setprecision(2)<<"Tempo médio de Decolagem na pista 3: "<<tempo_medio3<<" minutos"<<endl;
                        cout<<endl;
                        cout<<endl;
                    }
                //fim do procedimento
        
        ponteiro = ponta;
    }
}

//fim do codigo