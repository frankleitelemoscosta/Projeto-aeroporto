//
// Created by jeje on 04/10/22.
//

// compile com: g++ Fila_Aerea.hpp Fila_Aerea.cpp Fila_jur.hpp Fila_jur.cpp Aviao.hpp Aviao.cpp Pessoa_jur.hpp Pessoa_jur.cpp Pessoa.hpp Pessoa.hpp main.cpp -o ex


//inicio das bibliotecas
    #include "/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/SEGUNDO PERIODO/PROG2/SEGUNDO TRABALHO/Entrada_com_arquivo/hpp/Fila_Aerea.hpp"
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <iomanip>
    #include"/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/SEGUNDO PERIODO/PROG2/SEGUNDO TRABALHO/Entrada_com_arquivo/hpp/Fila_Aterrissagem_P3.hpp"
    using namespace std;
//fim das bibliotecas

int Fila_Aerea::contador = 0;
int Fila_Aerea::contador2 = 0;
float Fila_Aerea::tempo_Global = 0;


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
    this->contaddor_auxiliar1 = 0;
    this->contaddor_auxiliar2 = 0;

}


//Outros Métodos:
bool Fila_Aerea::vazia() //verifica se a carrinho está vazia
{
    return (ponta == nullptr);
}



//Insere elemento no final do carrinho:
void Fila_Aerea::inserir_na_fila(int id, int minutos_combustivel, int numero_de_passageiros,string nome_companhia,int id_fila,int pista) {

    //incio das variaveis locais
        Aviao *novo_no = new Aviao();
        
    //fim das variaveis locais

    if (vazia()) {

        ponta = novo_no;
        dianteira = novo_no;
        ponta->Inserir_proximo(nullptr);
        ponta->Inserir_anterior(nullptr);

    } else {

        dianteira->Inserir_proximo(novo_no);
        dianteira->Inserir_anterior(dianteira);
        dianteira = novo_no;
        dianteira->Inserir_proximo(nullptr);
    }

    if(id%2==0)//tratamento para caso o numero não seja um impar
    {   
        id = id*2;
    }

    dianteira->Inserir_ID(id);
    dianteira->Inserir_minutos_de_combustivel(minutos_combustivel);
    dianteira->Inserir_num_passageiros(numero_de_passageiros);
    dianteira->Inserir_companhia(nome_companhia);
    dianteira->Iniciando_tempo_aterrissagem();
    dianteira->Inserir_identificador_fila(id_fila);
    dianteira->Inserir_pista(pista);

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
    int contador = 0;
    //fim das variaveis locais

    cout<<endl<<endl<<endl;
    cout<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~Fila Aerea~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
    if(vazia())
    {
        cout<<"A fila aerea está vazia!"<<endl<<endl;
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
            cout<<"Tempo de espera: "<<ponteiro->Pegar_tempo_aterrissagem()<<endl;
            cout<<"Fila a qual pertence: "<<ponteiro->Pegar_fila_aviao()<<endl;
            cout<<endl;
            cout<<endl;

            ponteiro = ponteiro->Pegar_proximo();
        }
    }
    cout<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
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

    if(!vazia())
    {
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
    }


    if(!vazia())
    {

        //daqui em diante se faz a remoção
            cout<<"ID do avião que sai: "<<ponta->Pegar_ID()<<endl<<endl;
            cout<<"Fila que pertence: "<<ponta->Pegar_fila_aviao()<<endl<<endl;
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
        float tempo_medio1 = 0;
        float tempo_medio2 = 0;
        float tempo_medio3 = 0;
        float tempo_medio4 = 0;
    //fim das variaveis locais

    this->Dividendo_fila1 = 0;
    this->Dividendo_fila2 = 0;
    this->Dividendo_fila3 = 0;
    this->Dividendo_fila4 = 0;

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
                    tempo_medio1 = this->Dividendo_fila1/this->contador_aterrissagem_fila1;
                    cout<<setprecision(2)<<"Tempo médio de aterrissagem para fila1: "<<tempo_medio1<<" minutos"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            //fim do procedimento

        
            //procedimento para calcular tempo medio de aterrissagem na fila dois
                if(fila==2)
                {
                    tempo_medio2 = this->Dividendo_fila2/this->contador_aterrissagem_fila2;
                    cout<<setprecision(2)<<"Tempo médio de aterrissagem na fila2: "<<tempo_medio2<<" minutos"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            //fim do procedimento


            //procedimento para calcular tempo medio de aterrissagem na fila três
                if(fila==3)
                {
                    tempo_medio3 = this->Dividendo_fila3/this->contador_aterrissagem_fila3;
                    cout<<setprecision(2)<<"Tempo médio de aterrissagem na fila 3: "<<tempo_medio3<<" minutos"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            //fim do procedimento
        
            //procedimento para calcular tempo medio de aterrissagem na fila dois
                if(fila==4)
                {
                    tempo_medio4 = this->Dividendo_fila4/this->contador_aterrissagem_fila4;
                    cout<<setprecision(2)<<"Tempo médio de aterrissagem na fila 4: "<<tempo_medio4<<" minutos"<<endl;
                    cout<<endl;
                    cout<<endl;
                }
            //fim do procedimento

            this->tempo_Global = this->tempo_Global + (tempo_medio1 + tempo_medio2 + tempo_medio3 + tempo_medio4);
    
    }
}

void Fila_Aerea::diminuir_tempo()
{
    //inicio das variaveis locais
        Aviao *ponteiro = new Aviao();
        ponteiro = ponta;
    //fim das variaveis locais

    //Esse procedimento será responsável por reduzir o tempo de todos os aviões
        if(!vazia())
        {
            while(ponteiro)
            {
                ponteiro->Diminuir_tempo_aterrissagem();

                ponteiro = ponteiro->Pegar_proximo();
            }
        }
    //fim deste procedimento
}

void Fila_Aerea::emergencia()
{
    //inicio das variaveis locais
        Aviao *ponteiro = new Aviao();
        ponteiro = ponta;
        Aviao *aux = new Aviao();
        Aviao *aux2 = new Aviao();
        Fila_Aterrissagem_P3 fila_emergencia;
        int combustivel;
        string companhia;
        int numero_passageiros;
        int cont1 = 0,cont2 = 0;
    //fim das variaveis locais

     Prioridade_combustivel();
    
    
    if(!vazia())
    {
        if(this->contador2 == 4)
        {
            this->contador = 0;
        }
        this->contador2++;
    }//o erro não esta no looping

    if(!vazia() && (this->contaddor_auxiliar1 + this->contaddor_auxiliar2) < 3)
    {
        while(ponteiro)
        {
            if(ponteiro->Pegar_minutos_de_combustivel() <= 3)//é aqui que esta o erro
            {
                companhia = ponteiro->Pegar_companhia();

                combustivel = ponteiro->Pegar_minutos_de_combustivel();

                numero_passageiros = ponteiro->Pegar_num_passageiros();

                fila_emergencia.inserir_final(numero_passageiros,combustivel,companhia);//não é aqui

                this->contador++;
                
                cont1 = 0;
                cont2 = 0;

                //excluindo o avião da atinga fila
                
                //aqui é feito um reconhecimento da fila
                if(ponteiro->pegar_anterior()!=nullptr)//isso garante que não vai existir erro por pegar posição inexistente
                {
                    aux2 = ponteiro->pegar_anterior();

                    cont1++;
                }
                if(ponteiro->Pegar_proximo()!=nullptr)//isso garante que não vai existir erro por pegar posição inexistente
                {
                    aux = ponteiro->Pegar_proximo();

                    cont2++;
                }

                //a partir daqui se decidi qual caso é e o que acontece

                if(cont1!=0 && cont2!=0)//aqui é o caso onde pego um nó no meio da fila
                {
                    aux2->Inserir_proximo(aux);

                    aux->Inserir_anterior(aux2);

                    ponteiro = aux;

                    aux = nullptr;

                    free(aux);

                    cont1 = 0;
                    cont2 = 0;

            
                }
                else if(cont1!=0 && cont2==0)//aqui é o caso onde pegou um nó final da fila
                {
                    aux2->Inserir_proximo(nullptr);

                    dianteira = aux2;

                    ponteiro = aux2;

                    aux2 = nullptr;

                    free(aux2);
                    
                    cont1 = 0;
                    
                }
                else if(cont2!=0  && cont1==0)//aqui é um caso no inicio da lista
                {
                    aux->Inserir_anterior(nullptr);

                    cont2 = 0;

                    ponta = aux;
                    
                    aux = nullptr;

                    free(aux);

                    ponteiro = ponta;
                    
                }
                else if(cont1==0 && cont2==0)///caso onde tem se apenas um elemento//o  erro esta aqui
                {
                    dianteira->Inserir_anterior(nullptr);
                    ponta->Inserir_proximo(nullptr);
                    dianteira->Inserir_proximo(nullptr);
                    ponta->Inserir_anterior(nullptr);
                    dianteira = nullptr;
                    ponta = nullptr;

                    
                    
                }

                cont1 = 0;
                cont2 = 0;


                //fim da exclusão do aviao da fila

                cout<<contador<<" aviões tiveram problemas e foram enviados para a terceira pista"<<endl<<endl;

                if(contador >= 3)
                {
                    cout<<"Temos três avioes com problema, desse jeito a alcaida vem, entramos em estado critico"<<endl<<endl;
                    this->contador = 0;
                }
            }

            if(ponteiro->Pegar_proximo()!=nullptr && ponteiro != nullptr)
            {
                ponteiro = ponteiro->Pegar_proximo();
            }
            else
            {
                return;
            }
            
        }
    }
}

void Fila_Aerea::Tempo_Gobal()
{
    cout<<"Tempo Medio Global para Aterrissagem : "<<this->tempo_Global<<endl<<endl;
}

void Fila_Aerea::Prioridade_combustivel()
{
    //o que tem de ser feito aqui é uma leitura da fila, porem tenho de identificar em qual pista estou para que seja possível eu dizer para qual pista mandei 
    //e bloquear a seleção do que ocorre com o que ocorre em cada pista

    Aviao *ponteiro = new Aviao();
    ponteiro = ponta;
    Aviao *aux = new Aviao();
    Aviao *aux2 = new Aviao();
    int cont1 = 0;
    int cont2 = 0;
    

    while(ponteiro)
    {
        if(ponteiro->Pegar_minutos_de_combustivel() <= 3)
        {
                cont1 = 0;
                cont2 = 0;

                //excluindo o avião da atinga fila
                
                //aqui é feito um reconhecimento da fila
                if(ponteiro->pegar_anterior()!=nullptr)//isso garante que não vai existir erro por pegar posição inexistente
                {
                    aux2 = ponteiro->pegar_anterior();

                    cont1++;
                }
                if(ponteiro->Pegar_proximo()!=nullptr)//isso garante que não vai existir erro por pegar posição inexistente
                {
                    aux = ponteiro->Pegar_proximo();

                    cont2++;
                }

                //a partir daqui se decidi qual caso é e o que acontece

                if(cont1!=0 && cont2!=0)//aqui é o caso onde pego um nó no meio da fila
                {
                    aux2->Inserir_proximo(aux);

                    aux->Inserir_anterior(aux2);

                    ponteiro = aux;

                    aux = nullptr;

                    free(aux);

                    cont1 = 0;
                    cont2 = 0;

            
                }
                else if(cont1!=0 && cont2==0)//aqui é o caso onde pegou um nó final da fila
                {
                    aux2->Inserir_proximo(nullptr);

                    dianteira = aux2;

                    ponteiro = aux2;

                    aux2 = nullptr;

                    free(aux2);
                    
                    cont1 = 0;
                    
                }
                else if(cont2!=0  && cont1==0)//aqui é um caso no inicio da lista
                {
                    aux->Inserir_anterior(nullptr);

                    cont2 = 0;

                    ponta = aux;
                    
                    aux = nullptr;

                    free(aux);

                    ponteiro = ponta;
                    
                }
                else if(cont1==0 && cont2==0)///caso onde tem se apenas um elemento//o  erro esta aqui
                {
                    dianteira->Inserir_anterior(nullptr);
                    ponta->Inserir_proximo(nullptr);
                    dianteira->Inserir_proximo(nullptr);
                    ponta->Inserir_anterior(nullptr);
                    dianteira = nullptr;
                    ponta = nullptr;

                    
                    return;
                }

                if(ponteiro->Pegar_pista() == 1)//valor recebido de outro arquivo
                {       
                    this->contaddor_auxiliar1 ++;
                }
                else if(ponteiro->Pegar_pista() == 2){
                    this->contaddor_auxiliar2 ++;
                }

                cont1 = 0;
                cont2 = 0;

           
        }
        ponteiro = ponteiro->Pegar_proximo();
    }
}

int Fila_Aerea::contador_auxiliar1()
{
    return this->contaddor_auxiliar1;
}

int Fila_Aerea::contador_auxiliar2()
{
    return this->contaddor_auxiliar2;
}

void Fila_Aerea::Zerando_contadores()
{
    this->contaddor_auxiliar1 = 0;
    this->contaddor_auxiliar2 = 0;
}

//fim do código