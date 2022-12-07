//
// Created by jeje on 04/10/22.
//

#ifndef FILA_ATERRISSAGEM_P3_hPP
#define FILA_ATERRISSAGEM_P3_HPP

//incio das bibliotecas
#include "Aviao.hpp"
//fim das bibliotecas

class Fila_Aterrissagem_P3
{
    private:

        Aviao *ponta;
        Aviao *dianteira;
        int tamanho;

//fim dos atributos
    public:
    
        Fila_Aterrissagem_P3();
        Fila_Aterrissagem_P3(int num_passageiros, int minutos_de_combustivel, string compania);

        
        int Inserir_tamanho(int tamanho);
        int Pegar_tamanho();

        bool vazia();
        void inserir_final(int num_passageiros, int minutos_de_combustivel, string compania);
        void mostrar_todos();
        void Buscar_Aviao(int ID);
        int size();
        void remover();

//fim dos métodos
};

#endif //F_PROVA_Fila_Aterrissagem_P3_HPP
