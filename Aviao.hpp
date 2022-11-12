

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
        int minutos_para_emergencia;
        int ID;
        string compania;
        int espera_para_decolagem;
    //fim dos atributos
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

        int Declarar_minutos_para_emergencia(int minutos_para_emergencia);
        int Pegar_minutos_para_emergencia();

        int Declarar_espera_para_decolagem(int espera_para_decolagem);
        int Pegar_espera_para_decolagem();
        //fim dos métodos
};

#endif

//fim do código