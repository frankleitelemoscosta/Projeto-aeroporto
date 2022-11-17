//inicio das inclusões de bibliotecas
    #include <string>
    #include <cstring>
    #include <iostream>
    #include <ctime>
    #include"Aeroporto.hpp"
    using namespace std;
//fim das inclusões de bibliotecas

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


    //fim das variaveis locais

    //inicio do menu
    do{

        //inicio das sementes que representam variáveis locais aletórias:

        //fim das variaveis aleatórias

        cout<<"|-------------MENU--------------|"<<endl;
        cout<<"|1- Inserir um avião em uma fila|"<<endl;
        cout<<"|2- Mostrar filas|"<<endl;
        cout<<"|0- Sair do programa            |"<<endl;
        cin>>op;

        switch(op)
        {
            case 0:
                cout<<"Saindo..."<<endl;
            break;

            case 1:{
                
                unsigned semente_avioes_chegando = time(0);
                srand(semente_avioes_chegando);
                entrada_aletoria_avioes_chegando = 1+rand()%3;

                cout<<"Estão chegando"<<entrada_aletoria_avioes_chegando<<" aviões";

                for(int contador_avioes_inseridos=0;contador_avioes_inseridos<entrada_aletoria_avioes_chegando;contador_avioes_inseridos++)
                {

                    unsigned semente_minutos_combustivel = time(0);
                    srand(semente_minutos_combustivel);
                    entrada_aletoria_minutos_combustivel = 1+rand()%15;

                    unsigned semente_numero_de_passageiros = time(0);
                    srand(semente_numero_de_passageiros);
                    entrada_aletoria_numero_de_passageiros = 1+rand()%853;

                    cout<<"O "<<contador_avioes_inseridos<<"º avião tem:"<<endl;
                    cout<<entrada_aletoria_minutos_combustivel<<"minutos de combustível"<<endl;
                    cout<<entrada_aletoria_numero_de_passageiros<<" passageiros"<<endl;
                    
                    cout<<"Agora insira um id: "<<endl;
                    cin>>id;

                    aeroporto.inserir_aviao_na_aterrissagem(id,entrada_aletoria_minutos_combustivel,entrada_aletoria_numero_de_passageiros);

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

        contador_minutos++;

        //vai imprimir periodicamente dados dos avioẽs
        if(contador_minutos==3)
        {
            aeroporto.remover_da_fila_aterrissagem();
            aeroporto.impressao_filas();
            contador_minutos = 0;
        }

    }while(op!=0);
    //fim do menu

    string end = "\n";
    cout<<end;
    return 0;
}

//fim do código