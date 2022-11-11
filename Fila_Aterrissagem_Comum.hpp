//
// Created by jeje on 04/10/22.
//

#ifndef Fila_Aterrissagem_Comum_HPP
#define Fila_Aterrissagem_Comum_HPP

#include "Aviao.hpp"

class Fila_Aterrissagem_Comum
{
    private:
        Aviao *ponta;
        Aviao *dianteira;
        int tamanho;

    public:
        Fila_Aterrissagem_Comum();
        Fila_Aterrissagem_Comum(int num_passageiros, int minutos_de_combustivel, string compania);

        
        int Declarar_tamanho(int tamanho);
        int Pegar_tamanho();

        bool vazia();
        void inserir_final(int num_passageiros, int minutos_de_combustivel, string compania);
        void mostrar_todos();
        void Buscar_Aviao(int ID);
        int size();
        void remover();
};

#endif //F_PROVA_Fila_Aterrissagem_Comum_HPP
