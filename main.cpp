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
        int op;
        Aeroporto aeroporto;
        int id, minutos_combustivel;
        int contador_minutos = 0;
        int numero_de_passageiros = 0;
        int entrada_aletoria_avioes_chegando = 0;
        int entrada_aletoria_minutos_combustivel = 0;
        int entrada_aletoria_numero_de_passageiros = 0;
        int entrada_aletoria_nome_da_compania = 0;
        int entrada_aletoria_do_id = 0;
        vector <string> companias{"Tam", "Gol", "Azul", "Avianca", "American Airlines"};


    //fim das variaveis locais

    //inicio do menu
    
    do{

        //inicio das sementes que representam variáveis locais aletórias:

        //fim das variaveis aleatórias

        cout<<"|-------------MENU--------------|"<<endl;
        cout<<"|1- Inserir um avião em uma fila|"<<endl;
        cout<<"|2- Mostrar filas               |"<<endl;
        cout<<"|0- Sair do programa            |"<<endl;
        cin>>op;

        switch(op)
        {
            case 0:
                cout<<"Saindo..."<<endl;
            break;

            case 1:{


                entrada_aletoria_avioes_chegando = numero_aleatorio(1,3);

                cout<<"Estão chegando: "<< entrada_aletoria_avioes_chegando <<" aviões"<<endl;

                for(int contador_avioes_inseridos = 0; contador_avioes_inseridos < entrada_aletoria_avioes_chegando ; contador_avioes_inseridos++)
                {

                    entrada_aletoria_minutos_combustivel = numero_aleatorio(1,15);

                    entrada_aletoria_numero_de_passageiros = numero_aleatorio(1,853);

                    entrada_aletoria_do_id = numero_aleatorio(1000,9999);
                    
                    string entrada_aletoria_nome_da_compania = companias[numero_aleatorio(0,(companias.size()-1))];
                    

                    cout<<"O "<<contador_avioes_inseridos+1<<"º avião tem:"<<endl;
                    cout<<entrada_aletoria_minutos_combustivel<<" minutos de combustível"<<endl;
                    cout<<entrada_aletoria_numero_de_passageiros<<" passageiros"<<endl;
                    cout<<"Tem o ID: "<<entrada_aletoria_do_id<<endl;
                    cout<<"E pertence a compania: "<<entrada_aletoria_nome_da_compania<<endl;
                    
                    aeroporto.inserir_aviao_na_aterrissagem(entrada_aletoria_do_id,entrada_aletoria_minutos_combustivel,entrada_aletoria_numero_de_passageiros,entrada_aletoria_nome_da_compania);

                    contador_minutos++;//para que seja possível saber quando se passou um minuto no programa.

                    cout<<endl<<endl;
                }

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
        if(contador_minutos>=3)
        {
            aeroporto.diminuindo_tempo();
            aeroporto.tempo_medio_por_fila();
            aeroporto.remover_da_fila_aterrissagem();
            aeroporto.impressao_filas();
            contador_minutos = 0;
        }

    }while(op!=0);
    //fim do menu

    return 0;
}

//fim do código