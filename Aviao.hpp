


#ifndef AVIAO_HPP
#define AVIAO_HPP
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

//Definindo uma lista encadeada de obejtos:
class Aviao
{    
    private:
        Aviao* prox = NULL;
        int num_passageiros = 0, minutos_de_combustivel = 0, ID = 0;
        string compania = " ";

    public:
        //Construtores de Avião:
        Aviao();
        Aviao(int num_passageiros, int minutos_de_combustivel, string compania);

        //Gets e Sets de Avião:
        void Declarar_prox(Aviao *v);
        Aviao* Pegar_prox();

        int Declarar_num_passageiros(int num_passageiros);
        int Pegar_num_passageiros();

        int Declarar_minutos_de_combustivel(int minutos_de_combustivel);
        int Pegar_minutos_de_combustivel();

        int Declarar_ID(int ID);
        int Pegar_ID();

        string Declarar_compania(string compania);
        string Pegar_compania();

};
#endif