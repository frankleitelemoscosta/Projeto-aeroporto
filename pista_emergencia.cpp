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
        fila.size();
}

void Pista_de_emergencia::inserir_na_decolagem(int id)
{
        fila.inserir_final(id);
}

void Pista_de_emergencia::mostrar_filas()
{
        fila.mostrar_todos();
}