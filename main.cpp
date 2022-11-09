//inicio das inclusões de bibliotecas
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
//fim das inclusões de bibliotecas

int main()
{
    //inicio das variaveis locais
    int op;
    //fim das variaveis locais

    //inicio do menu
    do{

        cout<<"|-------------MENU--------------|"<<endl;
        cout<<"|0- Sair do programa            |"<<endl;
        cin>>op;

        switch(op)
        {
            case 0:
                cout<<"Saindo..."<<endl;
            break;
            default:
                cout<<"Digite uma opção existente no menu!"<<endl;
            break;
        }

    }while(op!=0);
    //fim do menu

    string end = "\n";
    cout<<end;
    return 0;
}

//fim do código