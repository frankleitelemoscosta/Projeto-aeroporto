//inicio das inclusões de bibliotecas
    #include <string>
    #include <cstring>
    #include <iostream>
    using namespace std;
    #include"Aeroporto.hpp"
//fim das inclusões de bibliotecas

int main()
{
    //inicio das variaveis locais
        int op;
        Aeroporto aeroporto;
        int id, minutos_combustivel;
        int contador = 0;
    //fim das variaveis locais

    //inicio do menu
    do{

        cout<<"|-------------MENU--------------|"<<endl;
        cout<<"|1- Inserir um avião em uma fila|"<<endl;
        cout<<"|0- Sair do programa            |"<<endl;
        cin>>op;

        switch(op)
        {
            case 0:
                cout<<"Saindo..."<<endl;
            break;
            case 1:
                cout<<"Insira um id: "<<endl;
                cin>>id;

                cout<<"Inserir o tempo de combustível "<<endl;
                cin>>minutos_combustivel;

                aeroporto.inserir_aviao_na_aterrissagem(id,minutos_combustivel);
            break;
            default:
                cout<<"Digite uma opção existente no menu!"<<endl;
            break;
        }

        contador++;

        //vai imprimir periodicamente dados dos avioẽs
        if(contador==3)
        {
            aeroporto.remover_da_fila_aterrissagem();
            aeroporto.impressao_filas();
            contador = 0;
        }

    }while(op!=0);
    //fim do menu

    string end = "\n";
    cout<<end;
    return 0;
}

//fim do código