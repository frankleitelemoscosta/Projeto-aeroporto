//
// Created by jeje on 04/10/22.
//

#ifndef FILA_AEREA_HPP
#define FILA_AEREA_HPP

//inicio das bibliotecas
    #include "Aviao.hpp"
//fim das bibliotecas

class Fila_Aerea
{
    private:

        Aviao *ponta;
        Aviao *dianteira;
        int tamanho;

//fim dos atributos
    public:

        Fila_Aerea();//construtor

        bool vazia();
        void inserir_na_fila(int id,int minutos_combustivel, int numero_de_passageiros,string nome_companhia);
        void mostrar_todos();
        void Buscar_Aviao(int ID);
        int size();
        void remover();

//fim dos métodos
};

#endif //F_PROVA_Fila_Aerea_HPP
