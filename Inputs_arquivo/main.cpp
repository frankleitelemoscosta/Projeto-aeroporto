//NOTAS:   ( ) - Programar inserção de variáveis por arquivo 
         //( ) - Programar a redistribuição de aviões [caso o avião tenha 1 minuto de combustível apenas o avião troca de fila]
         //( ) - 
         //( ) - 


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
    #include"Aeroporto.hpp"
//fim das inclusões de bibliotecas


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
        int id, minutos_combustivel;
        int contador_inserc = 0;
        int numero_de_passageiros = 0;
        int entrada_aletoria_avioes_chegando = 0;
        int entrada_aletoria_minutos_combustivel = 0;
        vector <string> companias{"Tam", "Gol", "Azul", "Avianca", "American Airlines"};
        vector<int> dados_do_arquivo;
        // vector<aviao> avioes;

    //fim das variaveis locais

        //Iniciando a leitura do arquivo;
        arquivo_de_leitura = fopen("arquivo_de_leitura.txt","r");
        chave_de_leitura.open("arquivo_de_leitura.txt");

        if(chave_de_leitura.is_open())
        {
            while(getline(chave_de_leitura, linha_do_arquivo))       
            {
                fscanf(arquivo_de_leitura,"%i",&auxiliar_de_leitura);

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
        cout<<"|2- Mostrar filas               |"<<endl;
        cout<<"|0- Sair do programa            |"<<endl;
        
        //Leitura da linha  1 do arquivo
        op = dados_do_arquivo[contador_de_leitura];
        contador_de_leitura+=1;


        switch(op)
        {
            case 0:
                cout<<"Saindo..."<<endl;
            break;

            case 1:{

                //Início da geração e registro de aviões aleatórios:

                //Leitura da linha  2 do arquivo
                entrada_aletoria_avioes_chegando = dados_do_arquivo[contador_de_leitura];
                contador_de_leitura+=1;
                
                do
                {
                    if((entrada_aletoria_avioes_chegando>3) || (entrada_aletoria_avioes_chegando<0))
                    {
                        cout<<"Entrada inválida para avioes chegando";
                        contador_de_leitura+=1;
                        entrada_aletoria_avioes_chegando = dados_do_arquivo[contador_de_leitura];
                    }
                }while((entrada_aletoria_avioes_chegando>3) || (entrada_aletoria_avioes_chegando<0));
                
                cout<<"Estão chegando: "<< entrada_aletoria_avioes_chegando <<" aviões"<<endl;

                for(int contador_avioes_inseridos = 0; contador_avioes_inseridos < entrada_aletoria_avioes_chegando ; contador_avioes_inseridos++)
                {
                    //Inicio das sementes que representam variáveis locais aletórias:
                    do{
                        entrada_aletoria_minutos_combustivel = dados_do_arquivo[contador_de_leitura];
                        contador_de_leitura+=1;
                    }while(0>entrada_aletoria_minutos_combustivel||entrada_aletoria_minutos_combustivel==0);
                    
                    int entrada_aletoria_numero_de_passageiros = dados_do_arquivo[contador_de_leitura];
                    contador_de_leitura+=1;

                    int entrada_aletoria_do_id = dados_do_arquivo[contador_de_leitura];
                    contador_de_leitura+=1;
                    
                    string entrada_aletoria_nome_da_compania = companias[dados_do_arquivo[contador_de_leitura]];
                    contador_de_leitura+=1;

                    //Fim das variaveis aleatórias                    

                    //Início da apresentação do que será cadastrado na fila
                    cout<<"O "<<contador_avioes_inseridos+1<<"º avião tem:"<<endl;
                    cout<<entrada_aletoria_minutos_combustivel<<" minutos de combustível"<<endl;
                    cout<<entrada_aletoria_numero_de_passageiros<<" passageiros"<<endl;
                    cout<<"Tem o ID: "<<entrada_aletoria_do_id<<endl;
                    cout<<"E pertence a compania: "<<entrada_aletoria_nome_da_compania<<endl;
                    
                    aeroporto.inserir_aviao_na_aterrissagem(entrada_aletoria_do_id,entrada_aletoria_minutos_combustivel,entrada_aletoria_numero_de_passageiros,entrada_aletoria_nome_da_compania);
                    //Fim de uma iteração do laço criado para inserir vários aviões na fila

                    contador_inserc++;//para que seja possível saber quando se passou um minuto no programa.

                    cout<<endl<<endl;

                }
                //Fim da geração e registro de aviões aleatórios:
            
            break;

            }

            case 2:
                aeroporto.impressao_filas();
            break;

            default:
                cout<<"Digite uma opção existente no menu!"<<endl;
            break;
        }

        //vai imprimir periodicamente dados dos avioẽs
        if(contador_inserc>=3)
        {
            aeroporto.diminuindo_tempo();
            aeroporto.tempo_medio_por_fila();
            aeroporto.remover_da_fila_aterrissagem();
            aeroporto.impressao_filas();
            contador_inserc = 0;
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
                op=op;
            }
            else
            {
                op=0;
                break;
            }
            //Fim da proposição para parar o programa
            contador_loops =0;
        }

    }while(op!=0);
    //fim do menu

    return 0;
}

//fim do código