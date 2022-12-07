#ifndef __AEROPORTO_HPP
#define __AEROPORTO_HPP

//inicio das bibliotecas
#include"pista.hpp"
#include"pista_emergincia.hpp"
//fim das bibliotecas


class Aeroporto
{
    private:

    Pista pista_1,pista_2;
    Pista_de_emergencia pista_3;

//fim dos atributos
    public:

    Aeroporto();//construtor

    void inserir_aviao_na_aterrissagem(int id,int minutos_combustivel, int numero_de_passageiros, string nome_companhia);

    void inserir_aviao_na_decolagem(int id,int minutos_combustivel,int numero_passageiros, string nome_da_companhia);

    void impressao_filas();

    void diminuir_tempo_aterrissagem();

    void tempo_medio_por_fila();

    void diminuindo_tempo();

    void emergencia();

    void tempo_medio_decolagem();

    void aumentar_tempo();

    void Decisao_para_pista(int pista1, int pista2);
//fim dos métodos
};

#endif

//fim do código