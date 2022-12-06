#ifndef __PISTA_EMERGENCIA_HPP
#define __PISTA_EMERGENCIA_HPP

#include"Fila_Aterrissagem_P3.hpp"
#include"Fila_Decolagem.hpp"


class Pista_de_emergencia
{
    private:

    Fila_Aterrissagem_P3 fila_1;
    Fila_Decolagem fila;

//fim dos atributos
    public:

    Pista_de_emergencia();//construtor

    void inserir_na_aterrissagem(int id,int minutos_combustivel, int numero_de_passageiros, string nome_companhia,int id_fila1);

    void remover_da_aterrissagem();

    void inserir_na_decolagem(int id,int minutos_combustivel,int numero_passageiros, string nome_da_companhia);

    int tamanho_filas();

    void mostrar_filas();
    
    void tempo_medio_filas(int fila);

    void diminuir_tempo();
 
//fim dos métodos
};

#endif


//fim do codigo