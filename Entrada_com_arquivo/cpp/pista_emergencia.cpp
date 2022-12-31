//inicio das bibliotecas
#include"pista_emergincia.hpp"
//fim das bibliotecas

Pista_de_emergencia::Pista_de_emergencia()
{
    
}

void Pista_de_emergencia::remover_da_aterrissagem()
{
        fila_1.remover();    
}

int Pista_de_emergencia::tamanho_filas()
{
        return fila.size();
}

void Pista_de_emergencia::inserir_na_decolagem(int id,int minutos_combustivel,int numero_passageiros, string companhia)
{
        fila.inserir_final(id,3,minutos_combustivel,numero_passageiros,companhia);
}

void Pista_de_emergencia::mostrar_filas()
{
        fila.mostrar_todos();
}

void Pista_de_emergencia::tempo_medio_fila_decolagem(int pista)
{
        fila.tempo_medio(pista);
}

void Pista_de_emergencia::remover_decolagem()
{
        fila.remover();
}

void Pista_de_emergencia::aumentar_tempo()
{
        fila.aumentar_tempo();
}

bool Pista_de_emergencia::Aterrissagem_vazia()
{
        return fila.vazia();
}