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
    #include"Aeroporto.hpp"
//fim das inclusões de bibliotecas

using namespace std;
int numero_aleatorio(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b);
    return dis(gen);
}

// using namespace std;
// int numero_aleatorio(int a, int b)
// {
//     srand(time(NULL));
//     return (rand()%b) + a;
    
// }


using namespace std;
int main()
{
    //inicio das variaveis locais
        int op, continuar;
        int contador_loops = 0;
        Aeroporto aeroporto;
        int id, minutos_combustivel;
        int contador_inserc = 0;
        int numero_de_passageiros = 0;
        int entrada_aletoria_avioes_chegando = 0;
        int entrada_aletoria_minutos_combustivel = 0;
        vector <string> companias{"Tam", "Gol", "Azul", "Avianca", "American Airlines"};



    //fim das variaveis locais

    //inicio do menu
    do{

        contador_loops+=1;

        cout<<"|-------------MENU--------------|"<<endl;
        cout<<"|1- Inserir um avião em uma fila|"<<endl;
        cout<<"|2- Mostrar filas               |"<<endl;
        cout<<"|0- Sair do programa            |"<<endl;
        op = numero_aleatorio(1,2);


        switch(op)
        {
            case 0:
                cout<<"Saindo..."<<endl;
            break;

            case 1:{

                //Início da geração e registro de aviões aleatórios: 
                entrada_aletoria_avioes_chegando = numero_aleatorio(1,3);

                cout<<"Estão chegando: "<< entrada_aletoria_avioes_chegando <<" aviões"<<endl;

                for(int contador_avioes_inseridos = 0; contador_avioes_inseridos < entrada_aletoria_avioes_chegando ; contador_avioes_inseridos++)
                {
                    //Inicio das sementes que representam variáveis locais aletórias:
                    do{
                        entrada_aletoria_minutos_combustivel = numero_aleatorio(1,15);
                    }while(0>entrada_aletoria_minutos_combustivel||entrada_aletoria_minutos_combustivel==0);
                    
                    int entrada_aletoria_numero_de_passageiros = numero_aleatorio(1,853);
                    
                    int entrada_aletoria_do_id = numero_aleatorio(1000,9999);
                    
                    string entrada_aletoria_nome_da_compania = companias[numero_aleatorio(0,(companias.size()-1))];

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