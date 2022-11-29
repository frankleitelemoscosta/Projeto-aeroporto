#ifndef __PISTA_HPP
#define __PISTA_HPP

//inicio das bibliotecas
#include"Fila_Aerea.hpp"
#include"Fila_Decolagem.hpp"
//fim das bibliotecas 

class Pista
{
    private:

    Fila_Aerea fila_1,fila_2;
    Fila_Decolagem fila;

//fim dos atributos
    public:

    Pista();//construtor

    void inserir_na_aterrissagem(int id,int minutos_combustivel, int numero_de_passageiros, string nome_companhia,int id_fila1, int id_fila2);

    void remover_da_aterrissagem();

    int tamanho_filas();

    void mostrar_filas();
    
    void tempo_medio_filas(int fila,int fila2);

    void diminuir_tempo();

    void emergencia();
 
//fim dos métodos
};

#endif

//fim do codigo