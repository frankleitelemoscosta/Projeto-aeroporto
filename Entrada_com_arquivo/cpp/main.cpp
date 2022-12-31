
//inicio das inclusões de bibliotecas
    #include <string>
    #include <cstring>
    #include <iostream>
    #include <ctime>
    #include <vector>
    #include <iomanip>
    #include <random>
    #include <fstream>
    #include <stdlib.h>
    #include <stdio.h>
    #include"/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/SEGUNDO PERIODO/PROG2/SEGUNDO TRABALHO/Entrada_com_arquivo/hpp/Aeroporto.hpp"
//fim das inclusões de bibliotecas

using namespace std;
int numero_aleatorio(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b);
    return dis(gen);
}


using namespace std;
int main()
{
    //inicio das variaveis locais
        FILE *arquivo_de_leitura;
        ifstream chave_de_leitura;
        int contador_de_leitura = 0;
        int auxiliar_de_leitura = 0;
        string linha_do_arquivo;
        int op, continuar;
        int contador_loops = 0;
        Aeroporto aeroporto;
        int id;//aleatorio
        int contador_inserc = 0;
        int numero_passageiros = 0;//aleatorio
        int entrada_aleatoria_id = 0;
        int avioes_chegando = 0;//aleatorio
        string nome_da_compania;
        int minutos_combustivel = 0;//aleatorio
        vector <string> companias{"Tam", "Gol", "Azul", "Avianca", "American Airlines"};
        vector<int> dados_do_arquivo;
        int validar_variavel = 0;
        
        
        int numero_avioes = 0;
        int minutos_combustivel2 = 0;//para o caso 2 aleatorio
        int decisao = 0;
        int contador =  0;


    //fim das variaveis locais

    //Iniciando a leitura do arquivo;
        arquivo_de_leitura = fopen("arquivo_de_leitura.txt","r");
        chave_de_leitura.open("arquivo_de_leitura.txt");

        if(chave_de_leitura.is_open())
        {
            while(getline(chave_de_leitura, linha_do_arquivo))       
            {
                fscanf(arquivo_de_leitura,"%i", &auxiliar_de_leitura);

                dados_do_arquivo.push_back(auxiliar_de_leitura);
            }
        
        }
        else
            cout<<"Não foi possível ler o arquivo, todas as variáveis do programa provavelmente são 0";
        
        chave_de_leitura.close();
        fclose(arquivo_de_leitura);
    //Fim da leitura do arquivo;



    //inicio do menu
    do{

        contador_loops+=1;

        cout<<"|-------------MENU--------------|"<<endl;
        cout<<"|1- Inserir um avião em uma fila|"<<endl;
        cout<<"|2- Inserir na fila de decolagem|"<<endl;
        cout<<"|0- Sair do programa            |"<<endl;
        op = dados_do_arquivo[contador_de_leitura];
        contador_de_leitura+=1;

        if(contador_inserc >= 2)
        {   
            decisao = 0;

            if(numero_avioes >= 3)
            {
                decisao = numero_aleatorio(0,1);
            }
            if(decisao == 0)
            {
                op = 2;
            }
               
        }

        switch(op)
        {
            case 0:
                cout<<"Saindo..."<<endl;
            
            break;

            //Cadastrar um avião na fila aerea de aterrissagem:
            case 1:
                if(contador != 3)
                {

                    //Início da geração e registro de aviões aleatórios: 

                    do
                    {
                        if((dados_do_arquivo[contador_de_leitura]>3) || (dados_do_arquivo[contador_de_leitura]<=0))
                        {
                            cout<<"Entrada inválida para avioes chegando";
                            contador_de_leitura+=1;
                        }
                        else
                        {
                            avioes_chegando = dados_do_arquivo[contador_de_leitura];
                            contador_de_leitura+=1;
                            break;
                        }
                    }while((dados_do_arquivo[contador_de_leitura]>3) || (dados_do_arquivo[contador_de_leitura]<0));

                    

                    cout<<"Estão chegando: "<< avioes_chegando <<" aviões"<<endl;

                    numero_avioes = numero_avioes + avioes_chegando;
                    
                    for(int contador_avioes_inseridos = 0; contador_avioes_inseridos < avioes_chegando ; contador_avioes_inseridos++)
                    {
                        
                        //Inicio das sementes que representam variáveis locais aletórias:

                        do
                       {
                            if(dados_do_arquivo[contador_de_leitura]<=0 || dados_do_arquivo[contador_de_leitura]>15)
                            {
                                contador_de_leitura+=1;
                            }
                            else
                            {
                                minutos_combustivel = dados_do_arquivo[contador_de_leitura];
                                contador_de_leitura+=1;
                                break;
                            }
                       } while(dados_do_arquivo[contador_de_leitura]<=0 || dados_do_arquivo[contador_de_leitura]>15);
                        
                        contador++;

                        do
                       {
                            if(dados_do_arquivo[contador_de_leitura]<0 || dados_do_arquivo[contador_de_leitura]>853)
                            {
                                contador_de_leitura+=1;
                            }
                            else
                            {
                                numero_passageiros = dados_do_arquivo[contador_de_leitura];
                                contador_de_leitura+=1;
                                break;
                            }
                       } while(dados_do_arquivo[contador_de_leitura]<0 || dados_do_arquivo[contador_de_leitura]>853);


                        do
                       {
                            if(dados_do_arquivo[contador_de_leitura]%2==0)
                            {
                                contador_de_leitura+=1;
                            }
                            else
                            {
                                entrada_aleatoria_id = dados_do_arquivo[contador_de_leitura];
                                contador_de_leitura+=1;
                                break;
                            }
                       } while(dados_do_arquivo[contador_de_leitura]%2==0); 

                    
                       
                       do
                       {
                            if(dados_do_arquivo[contador_de_leitura]>4)
                            {
                                contador_de_leitura+=1;
                            }
                            else
                            {
                                nome_da_compania = companias[dados_do_arquivo[contador_de_leitura]];
                                contador_de_leitura+=1;
                                break;
                            }
                       } while(dados_do_arquivo[contador_de_leitura]>4);
                       
                       contador_de_leitura+=1;

                        //Fim das variaveis aleatórias                    

                        //Início da apresentação do que será cadastrado na fila
                        cout<<endl;
                        cout<<"O "<<contador_avioes_inseridos+1<<"º avião tem: "<<minutos_combustivel<<" minutos de combustível"<<endl;
                        cout<<numero_passageiros<<" passageiros"<<endl;
                        cout<<"Tem o ID: "<<entrada_aleatoria_id<<endl;
                        cout<<"E pertence a compania: "<<nome_da_compania<<endl;
                        
                        aeroporto.inserir_aviao_na_decolagem(entrada_aleatoria_id, minutos_combustivel, numero_passageiros, nome_da_compania);
                        
                        //Fim de uma iteração do laço criado para inserir vários aviões na fila

                        contador_inserc++;//para que seja possível saber quando se passou um minuto no programa.

                        cout<<endl<<endl;
                    }
                }

                //Fim da geração e registro de aviões aleatórios:
            
            break;

            
            //Cadastrar um avião na fila de decolagem:
            case 2:
                if(contador != 3)
                    {
                    //Início da geração e registro de aviões aleatórios: 
                    
                    do
                    {
                        if((dados_do_arquivo[contador_de_leitura]>3) || (dados_do_arquivo[contador_de_leitura]<=0))
                        {
                            cout<<"Entrada inválida para avioes chegando";
                            contador_de_leitura+=1;
                        }
                        else
                        {
                            avioes_chegando = dados_do_arquivo[contador_de_leitura];
                            contador_de_leitura+=1;
                            break;
                        }
                    }while((dados_do_arquivo[contador_de_leitura]>3) || (dados_do_arquivo[contador_de_leitura]<0));

                    cout<<"Estão chegando: "<< avioes_chegando <<" aviões"<<endl;

                    numero_avioes = numero_avioes + avioes_chegando;
                    

                    for(int contador_avioes_inseridos = 0; contador_avioes_inseridos < avioes_chegando ; contador_avioes_inseridos++)
                    {
                        //Inicio das sementes que representam variáveis locais aletórias:
                        
                        do
                       {
                            if(dados_do_arquivo[contador_de_leitura]<=0 || dados_do_arquivo[contador_de_leitura]>15)
                            {
                                contador_de_leitura+=1;
                            }
                            else
                            {
                                minutos_combustivel = dados_do_arquivo[contador_de_leitura];
                                contador_de_leitura+=1;
                                break;
                            }
                       } while(dados_do_arquivo[contador_de_leitura]<=0 || dados_do_arquivo[contador_de_leitura]>15);
                        
                    
                        
                        contador++;

                        do
                       {
                            if(dados_do_arquivo[contador_de_leitura]<0 || dados_do_arquivo[contador_de_leitura]>853)
                            {
                                contador_de_leitura+=1;
                            }
                            else
                            {
                                numero_passageiros = dados_do_arquivo[contador_de_leitura];
                                contador_de_leitura+=1;
                                break;
                            }
                       } while(dados_do_arquivo[contador_de_leitura]<0 || dados_do_arquivo[contador_de_leitura]>853); 

                        do
                       {
                            if(dados_do_arquivo[contador_de_leitura]%2==0)
                            {
                                contador_de_leitura+=1;
                            }
                            else
                            {
                                entrada_aleatoria_id = dados_do_arquivo[contador_de_leitura];
                                contador_de_leitura+=1;
                                break;
                            }
                       } while(dados_do_arquivo[contador_de_leitura]%2==0); 

                        do
                       {
                            if(dados_do_arquivo[contador_de_leitura]>4)
                            {
                                contador_de_leitura+=1;
                            }
                            else
                            {
                                nome_da_compania = companias[dados_do_arquivo[contador_de_leitura]];
                                contador_de_leitura+=1;
                                break;
                            }
                       } while(dados_do_arquivo[contador_de_leitura]>4);
                       
                        
                        //Fim das variaveis lidas pelo arquivo                    

                        //Início da apresentação do que será cadastrado na fila
                        cout<<endl;
                        cout<<"O "<<contador_avioes_inseridos+1<<"º avião tem: "<<minutos_combustivel<<" minutos de combustível"<<endl;
                        cout<<numero_passageiros<<" passageiros"<<endl;
                        cout<<"Tem o ID: "<<entrada_aleatoria_id<<endl;
                        cout<<"E pertence a compania: "<<nome_da_compania<<endl;
                        
                        aeroporto.inserir_aviao_na_aterrissagem(entrada_aleatoria_id,minutos_combustivel,numero_passageiros,nome_da_compania);
                        //Fim de uma iteração do laço criado para inserir vários aviões na fila

                        contador_inserc++;//para que seja possível saber quando se passou um minuto no programa.

                        decisao = 1;

                        numero_avioes = numero_avioes + 1;

                        cout<<endl<<endl;
                    }
                }
            break;
            
            //Cadastrar um avião na fila de decolagem:
            case 3:
                cout<<"Em manutenção"<<endl;
            break;
            
            //Cadastrar um avião na fila de decolagem:
            case 4:
                cout<<"Em manutenção"<<endl;
            break;

            default:

                cout<<"Digite uma opção existente no menu!"<<endl;
            
            break;
        }

        int pista1;
        int pista2;

        pista1 = numero_aleatorio(1,2);
        pista2 = numero_aleatorio(1,2);

        //vai imprimir periodicamente dados dos avioẽs
        if(contador_inserc>=3 && decisao == 1)
        {
            aeroporto.emergencia();
            aeroporto.diminuindo_tempo();
            aeroporto.tempo_medio_por_fila();
            aeroporto.Tempo_Global_aterrissagem();
            //tem de ser colocado para ser decidido se vai ocorrer uma aterrissagem ou decolagem
            aeroporto.Decisao_para_pista(pista1,pista2);
            aeroporto.impressao_filas();
            aeroporto.aumentar_tempo();
            aeroporto.tempo_medio_decolagem();//a excessão de ponto flutuante vemm daqui
            aeroporto.Tempo_Global_Decolagem();
            contador_inserc = 0;
            numero_avioes = 0;
            contador = 0;
            decisao = 0;
        }

        if(contador_loops==2)
        {
            //Inicio de proposição para parar o programa:
            cout<<"Deseja continuar?"<<endl;
            cout<<"1-sim"<<endl;
            cout<<"2-não"<<endl;
            cin>>continuar;

            if(continuar==1)
            {
                op = op;
            }
            else
            {
                op = 0;
            }
            //Fim da proposição para parar o programa
            contador_loops = 0;
        }

    }while(op!=0);
    //fim do menu

    return 0;
}

//fim do código