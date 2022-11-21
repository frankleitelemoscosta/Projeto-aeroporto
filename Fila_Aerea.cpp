//
// Created by jeje on 04/10/22.
//

// compile com: g++ Fila_Aerea.hpp Fila_Aerea.cpp Fila_jur.hpp Fila_jur.cpp Aviao.hpp Aviao.cpp Pessoa_jur.hpp Pessoa_jur.cpp Pessoa.hpp Pessoa.hpp main.cpp -o ex


//inicio das bibliotecas
    #include "Fila_Aerea.hpp"
    #include <iostream>
    #include <string>
    #include <cstring>
    #include<iomanip>
    using namespace std;
//fim das bibliotecas

//Construtores:
Fila_Aerea::Fila_Aerea()
{
    ponta = nullptr;
    dianteira = nullptr;
    this->contador_aterrissagem_fila1 = 1;//serve para inicializar
    this->Dividendo_fila1 = 0;//serve para inicializar
    this->contador_aterrissagem_fila2 = 1;
    this->Dividendo_fila2 = 0;
    this->contador_aterrissagem_fila3 = 1;
    this->Dividendo_fila3 = 0;
    this->contador_aterrissagem_fila4 = 1;
    this->Dividendo_fila4 = 0;

}


//Outros Métodos:
bool Fila_Aerea::vazia() //verifica se a carrinho está vazia
{
    return (ponta == nullptr);
}



//Insere elemento no final do carrinho:
void Fila_Aerea::inserir_na_fila(int id, int minutos_combustivel, int numero_de_passageiros,string nome_companhia,int id_fila) {

    //incio das variaveis locais
        Aviao *novo_no = new Aviao();
        int ID,erro = 1;
    //fim das variaveis locais

    if (vazia()) {

        ponta = novo_no;
        dianteira = novo_no;
        ponta->Inserir_proximo(nullptr);
    
    } else {

        dianteira->Inserir_proximo(novo_no);
        dianteira = novo_no;
        dianteira->Inserir_proximo(nullptr);
    
    }

    dianteira->Inserir_ID(id);
    dianteira->Inserir_minutos_de_combustivel(minutos_combustivel);
    dianteira->Inserir_num_passageiros(numero_de_passageiros);
    dianteira->Inserir_companhia(nome_companhia);
    dianteira->Iniciando_tempo_aterrissagem();
    dianteira->Inserir_identificador_fila(id_fila);

    cout << endl;
    cout << endl;
    cout << "CADASTRO REALIZADO COM SUCESSO!!";
    cout << endl;
    cout << endl;
}

void Fila_Aerea::mostrar_todos()
{
    //inicio das variaveis locais
        Aviao *ponteiro = new Aviao();
        ponteiro = ponta;
    //fim das variaveis locais

    if(vazia())
    {
        cout<<"A fila está vazia!"<<endl<<endl;
    }
    else
    {
        while(ponteiro)
        {
                //Mostrar todos os atributos:
            cout<<"Número de passageiros: "<<ponteiro->Pegar_num_passageiros()<<endl;
            cout<<"Minutos de Combustível: "<<ponteiro->Pegar_minutos_de_combustivel()<<endl;
            cout<<"Compania: "<<ponteiro->Pegar_companhia()<<endl;
            cout<<"ID: "<<ponteiro->Pegar_ID()<<endl;
            cout<<"Tempo de espera: "<<ponteiro->Pegar_tempo_aterrissagem()<<endl;
            cout<<"Fila a qual pertence: "<<ponteiro->Pegar_fila_aviao()<<endl;
            cout<<endl;
            cout<<endl;

            ponteiro = ponteiro->Pegar_proximo();
        }
    }
}


void Fila_Aerea::Buscar_Aviao(int ID)
{
    //inicio das variaveis locais
        Aviao *ponteiro = new Aviao();
        ponteiro = ponta;
        int token_de_busca = 0;
    //fim das variaveis locais

    if(vazia())
    {
        cout<<"Não há ninguém nesta fila!";
    }
    else
    {
        while(ponteiro)
        {
            if(ponteiro->Pegar_ID()==ID)
            {
                //Mostrar todos os atributos:
                cout<<"O ID está presente próximo ao aeroporto ou dentro dele!"<<endl;
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


int Fila_Aerea::size()
{
    if(vazia())
    {
        return 0;
    }

    //inicio das variaveis locais
        Aviao* ponteiro = new Aviao();
        ponteiro = ponta;
        int tamanho = 0;
    //fim das variaveis locais

    while(ponteiro)
    {
        tamanho++;
        ponteiro = ponteiro->Pegar_proximo();
    }
    
    return tamanho;
}

void Fila_Aerea::remover()
{

    //inicio das variaveis locais
        Aviao *ponteiro = new Aviao();
        ponteiro = ponta;
    //fim das variaveis locais


    if(ponta->Pegar_fila_aviao()==1)
    {
        this->contador_aterrissagem_fila1 = this->contador_aterrissagem_fila1 + 1;
    }
    else if(ponta->Pegar_fila_aviao()==2)
    {
        this->contador_aterrissagem_fila2 = this->contador_aterrissagem_fila2 + 1;
    }
    else if(ponta->Pegar_fila_aviao()==3)
    {
        this->contador_aterrissagem_fila3 = this->contador_aterrissagem_fila3 + 1;
    }
    else if(ponta->Pegar_fila_aviao()==4)
    {
        this->contador_aterrissagem_fila4 = this->contador_aterrissagem_fila4 + 1;
    }



    if(!vazia())
    {

        //daqui em diante se faz a remoção
            ponta = ponta->Pegar_proximo();
            free(ponteiro);//deletando da memoria o nó anterior
        //fim da remoção
        return;
    }
    else
    {
        cout<<"Esta fila está vazia"<<endl<<endl;
    }

}

void Fila_Aerea::tempo_medio_filas(int fila)
{
    //inicio das variaveis locais
        Aviao *ponteiro = new Aviao();
        ponteiro = ponta;
        float tempo_medio;
    //fim das variaveis locais

    if(!vazia())
    {    
            while(ponteiro)
            {
                if(ponteiro->Pegar_fila_aviao()==1)
                {
                    this->Dividendo_fila1 = this->Dividendo_fila1 + ponteiro->Pegar_tempo_aterrissagem();
                    
                }
                else if(ponteiro->Pegar_fila_aviao()==2)
                {
                    this->Dividendo_fila2 = this->Dividendo_fila2 + ponteiro->Pegar_tempo_aterrissagem();
                    
                }
                else if(ponteiro->Pegar_fila_aviao()==3)
                {
                    this->Dividendo_fila3 = this->Dividendo_fila3 + ponteiro->Pegar_tempo_aterrissagem();

                }
                else if(ponteiro->Pegar_fila_aviao()==4)
                {
                    this->Dividendo_fila4 = this->Dividendo_fila4 + ponteiro->Pegar_tempo_aterrissagem();

                }
                ponteiro = ponteiro->Pegar_proximo();
            }

            //procedimento para calcular tempo medio de aterrissagem na fila
                if(fila==1)
                {         
                    tempo_medio = this->Dividendo_fila1/this->contador_aterrissagem_fila1;
                    cout<<setprecision(2)<<"Tempo médio de aterrissagem para fila1: "<<tempo_medio<<" minutos"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            //fim do procedimento

        
            //procedimento para calcular tempo medio de aterrissagem na fila dois
                if(fila==2)
                {
                    tempo_medio = this->Dividendo_fila2/this->contador_aterrissagem_fila2;
                    cout<<setprecision(2)<<"Tempo médio de aterrissagem na fila2: "<<tempo_medio<<" minutos"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            //fim do procedimento


            //procedimento para calcular tempo medio de aterrissagem na fila três
                if(fila==3)
                {
                    tempo_medio = this->Dividendo_fila3/this->contador_aterrissagem_fila3;
                    cout<<setprecision(2)<<"Tempo médio de aterrissagem na fila 3: "<<tempo_medio<<" minutos"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            //fim do procedimento
        
            //procedimento para calcular tempo medio de aterrissagem na fila dois
                if(fila==4)
                {
                    tempo_medio = this->Dividendo_fila4/this->contador_aterrissagem_fila4;
                    cout<<setprecision(2)<<"Tempo médio de aterrissagem na fila 4: "<<tempo_medio<<" minutos"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            //fim do procedimento
    
    }
}

void Fila_Aerea::diminuir_tempo()
{
    //inicio das variaveis locais
        Aviao *ponteiro = new Aviao();
        ponteiro = ponta;
    //fim das variaveis locais

    //Esse procedimento será responsável por reduzir o tempo de todos os aviões
        while(ponteiro)
        {
            ponteiro->Diminuir_tempo_aterrissagem();

            ponteiro = ponteiro->Pegar_proximo();
        }
    //fim deste procedimento
}

//fim do código