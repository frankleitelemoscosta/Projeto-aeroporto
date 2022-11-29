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
        float Dividendo_fila1;
        float Dividendo_fila2;
        float Dividendo_fila3;
        float Dividendo_fila4;
        float contador_aterrissagem_fila1;
        float contador_aterrissagem_fila2;
        float contador_aterrissagem_fila3;
        float contador_aterrissagem_fila4;

//fim dos atributos
    public:

        Fila_Aerea();//construtor

        bool vazia();

        void inserir_na_fila(int id,int minutos_combustivel, int numero_de_passageiros,string nome_companhia,int id_fila);
        
        void mostrar_todos();
        
        void Buscar_Aviao(int ID);
        
        int size();
        
        void remover();
        
        void tempo_medio_filas(int fila);
        
        void diminuir_tempo();

        void emergencia();//para caso algum avião chega a 3 de combustível 
//fim dos métodos
};

#endif //F_PROVA_Fila_Aerea_HPP
