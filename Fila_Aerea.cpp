//
// Created by jeje on 04/10/22.
//

// compile com: g++ Fila_Aerea.hpp Fila_Aerea.cpp Fila_jur.hpp Fila_jur.cpp Aviao.hpp Aviao.cpp Pessoa_jur.hpp Pessoa_jur.cpp Pessoa.hpp Pessoa.hpp main.cpp -o ex

//inicio das bibliotecas
    #include "Fila_Aerea.hpp"
    #include <iostream>
    #include <string>
    #include <cstring>
    using namespace std;
//fim das bibliotecas

//Construtores:
Fila_Aerea::Fila_Aerea()
{
   ponta = nullptr;
   dianteira = nullptr;
}


//Outros Métodos:
bool Fila_Aerea::vazia() //verifica se a carrinho está vazia
{
    return (ponta == nullptr);
}



//Insere elemento no final do carrinho:
void Fila_Aerea::inserir_na_fila(int id, int minutos_combustivel, int numero_de_passageiros) {

    //incio das variaveis locais
        Aviao *novo_no = new Aviao();
        int ID,erro=1;
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
            cout<<"Compania: "<<ponteiro->Pegar_compania()<<endl;
            cout<<"ID: "<<ponteiro->Pegar_ID()<<endl;
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

    //para mostrar ao usuário quem esta saindo da pista de aterrissagem
        cout<<endl;
        cout<<endl;
        cout<<"|*******INFORMAÇÕES DO AVIÃO QUE ESTA SAINDO DA FILA DE ATERRISSAGEM********|"<<endl;
        cout<<" Número de identificação do avião que saiu: "<<ponteiro->Pegar_ID()<<endl;  
        cout<<" Tempo de combustível que ainda lhe restava em minutos:"<<ponteiro->Pegar_minutos_de_combustivel()<<endl;  
        cout<<"|***************************************************************************|"<<endl;
        cout<<endl;
        cout<<endl;
    //fim desse procedimento

    if(!vazia())
    {
        ponta = ponta->Pegar_proximo();
        free(ponteiro);//deletando da memoria o nó anterior
        return;
    }
    else
    {
        cout<<"Esta fila está vazia"<<endl<<endl;
    }

}

//fim do código