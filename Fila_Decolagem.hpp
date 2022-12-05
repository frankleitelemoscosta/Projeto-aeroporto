//
// Created by jeje on 04/10/22.
//

#ifndef Fila_Decolagem_HPP
#define Fila_Decolagem_HPP

#include "Aviao.hpp"

class Fila_Decolagem
{
    private:

        Aviao *ponta;
        Aviao *dianteira;
        int tamanho;
        int contador_decolagem1;
        int contador_decolagem2;
        int contador_decolagem3;
        int Numerador1;
        int Numerador2;
        int Numerador3;

    public:
        Fila_Decolagem();
        Fila_Decolagem(int num_passageiros, int minutos_de_combustivel);

        
        int Declarar_tamanho(int tamanho);
        int Pegar_tamanho();

        bool vazia();
        void inserir_final(int id,int filaa,int minutos_combustivel, int numero_passageiros, string nome_da_companhia);
        void mostrar_todos();
        int size();
        void remover();
        void tempo_medio(int fila);

        void aumentar_tempo();

};

#endif //F_PROVA_Fila_Decolagem_HPP
