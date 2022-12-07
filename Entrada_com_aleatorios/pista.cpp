
//inicio das bibliotecas
#include"pista.hpp"
//fim das bibliotecas

Pista::Pista()
{

}

int Pista::tamanho_filas()
{

    //inicio das variaveis locais
        int menor;
    //fim das variaveis locais
      
        if(fila_1.size()<fila_2.size())
        {
            menor = fila_1.size();
        }
        else
        {
            menor = fila_2.size();
        }
    
 
    return menor;//se trata de um número, pois é necessário ser feito uma comparação em outro arquivo que no caso é o arquivo Aeroporto
}

void Pista::inserir_na_aterrissagem(int id, int minutos_combustivel, int numero_de_passageiros,string nome_companhia,int id_fila,int id_fila2)
{
    if(fila_1.vazia() && fila_2.vazia())//para a primeira inserção
    {
        fila_1.inserir_na_fila(id,minutos_combustivel, numero_de_passageiros, nome_companhia,id_fila);
    }
    else if (!fila_1.vazia())//para o programa saber como deixar as filas com tamanhos parecidos
    {
        if(fila_1.size()<fila_2.size())
        {
            fila_1.inserir_na_fila(id,minutos_combustivel, numero_de_passageiros, nome_companhia,id_fila);
        }
        else
        {
            fila_2.inserir_na_fila(id,minutos_combustivel, numero_de_passageiros, nome_companhia,id_fila2);
        }
    }
    
}

void Pista::remover_da_aterrissagem()
{
    if(fila_1.size()>fila_2.size())//para o programa saber como deixar as filas com o mesmo tamanho
    {
        fila_1.remover();
    }
    else{
        fila_2.remover();
    }
}

void Pista::mostrar_filas()
{
    fila_1.mostrar_todos();//filas de aterrissagem
    fila_2.mostrar_todos();
    fila.mostrar_todos();
}

void Pista::tempo_medio_filas(int fila, int fila2)
{
    fila_1.tempo_medio_filas(fila);
    fila_2.tempo_medio_filas(fila2);
}

void Pista::diminuir_tempo()
{
    fila_1.diminuir_tempo();
    fila_2.diminuir_tempo();
}

void Pista::emergencia()
{
    fila_1.emergencia();
    fila_2.emergencia();
}

void Pista::inserir_decolagem(int id,int filaa, int minutos_combustivel, int numero_passageiros, string nome_da_companhia)
{
    fila.inserir_final(id, filaa, minutos_combustivel, numero_passageiros, nome_da_companhia);
}

int Pista::tamanho_fila_decolagem()
{
    return fila.size();
}

void Pista::tempo_medio_decolagem(int pista)
{
    fila.tempo_medio(pista);
}

void Pista::aumentar_tempo()
{
    fila.aumentar_tempo();
}

void Pista::remover_da_decolagem()
{
    fila.remover();
}

//fim do código