

//inicio das bibliotecas
    #ifndef AVIAO_HPP
    #define AVIAO_HPP
    #include <string>
    #include <iostream>
    #include <stdlib.h>
    using namespace std;
//fim das bibliotecas

//Definindo uma lista encadeada de obejtos:
class Aviao
{    
    private:

        Aviao *proximo;
        int num_passageiros;
        int minutos_de_combustivel;
        int ID;
        string compania;
        int espera_para_decolagem;

    //fim dos atributos
    public:
        //Construtores de Avião:
        Aviao();
        Aviao(int num_passageiros, int minutos_de_combustivel, string compania);

        //Gets e Sets de Avião:
        void Inserir_proximo(Aviao *Ponteiro);
        Aviao *Pegar_proximo();

        int Inserir_num_passageiros(int num_passageiros);
        int Pegar_num_passageiros();

        int Inserir_minutos_de_combustivel(int minutos_de_combustivel);
        int Pegar_minutos_de_combustivel();

        int Inserir_ID(int ID);
        int Pegar_ID();

        string Inserir_compania(string compania);
        string Pegar_compania();

        int Inserir_espera_para_decolagem(int espera_para_decolagem);
        int Pegar_espera_para_decolagem();
        //fim dos métodos
};

#endif

//fim do código