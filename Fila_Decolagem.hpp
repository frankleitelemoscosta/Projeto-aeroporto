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

    public:
        Fila_Decolagem();
        Fila_Decolagem(int num_passageiros, int minutos_de_combustivel);

        
        int Declarar_tamanho(int tamanho);
        int Pegar_tamanho();

        bool vazia();
        void inserir_final(int id);
        void mostrar_todos();
        int size();
        void remover();
};

#endif //F_PROVA_Fila_Decolagem_HPP
