//inicio das inclusões de bibliotecas
    #include <string>
    #include <cstring>
    #include <iostream>
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
        int avioes_chegando = 0;
        int numero_de_passageiros = 0; 
        
    //fim das variaveis locais

    //inicio do menu
    do{

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

            case 1:
                cout<<"Insira aqui quantos aviões devem serão inseridos:"<<endl;
                cin>>avioes_chegando;


                for(int contador_avioes_inseridos=0;contador_avioes_inseridos<avioes_chegando;contador_avioes_inseridos++)
                {
                    cout<<"Insira um id: "<<endl;
                    cin>>id;

                    cout<<"Inserir o tempo de combustível "<<endl;
                    cin>>minutos_combustivel;

                    cout<<"Inserir o número de passageiros"<<endl;
                    cin>>numero_de_passageiros;


                    aeroporto.inserir_aviao_na_aterrissagem(id,minutos_combustivel,numero_de_passageiros);
                }
            break;

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