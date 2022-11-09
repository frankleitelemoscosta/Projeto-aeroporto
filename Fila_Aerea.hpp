//
// Created by jeje on 04/10/22.
//

#ifndef FILA_AEREA_HPP
#define FILA_AEREA_HPP

#include "Aviao.hpp"

class Fila_Aerea
{
    private:
        Aviao *ponta;
        Aviao *dianteira;

    public:
        Fila_Aerea();
        Fila_Aerea(int num_passageiros, int minutos_de_combustivel, string compania);

        bool vazia();
        void inserir_final(int num_passageiros, int minutos_de_combustivel, string compania);
        void mostrar_todos();
        void Buscar_Aviao(int ID);
        int size();
        void remover();
};

#endif //F_PROVA_Fila_Aerea_HPP
