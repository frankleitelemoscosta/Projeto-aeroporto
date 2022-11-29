//inicio das bibliotecas
    #include"Aeroporto.hpp"
//fim das bibliotecas

Aeroporto::Aeroporto()//construtor
{

}

void Aeroporto::inserir_aviao_na_aterrissagem(int id, int minutos_combustivel, int numero_de_passageiros, string nome_companhia)
{

    if(pista_1.tamanho_filas()<pista_2.tamanho_filas())//para inserir na menor fila visando deixa-las com o mesmo tamanho
    {
        pista_1.inserir_na_aterrissagem(id, minutos_combustivel, numero_de_passageiros,nome_companhia,1,2);
    }else
    {
        pista_2.inserir_na_aterrissagem(id, minutos_combustivel, numero_de_passageiros, nome_companhia,3,4);
    }
    
}

void Aeroporto::inserir_aviao_na_decolagem()
{

}

void Aeroporto::remover_da_fila_aterrissagem()
{
    

    if(pista_1.tamanho_filas()>pista_2.tamanho_filas())
    {
        pista_1.remover_da_aterrissagem();
    }
    else
    {
        pista_2.remover_da_aterrissagem();
    }
    
    pista_3.remover_da_aterrissagem();
}

void Aeroporto::remover_da_fila_decolagem()
{

}

void Aeroporto::impressao_filas()
{
    //aqui o que ocorre é que o programa acessa as duas pistas com suas duas filas para ler as filas por completo
    pista_1.mostrar_filas();
    pista_2.mostrar_filas();
}

void Aeroporto::tempo_medio_por_fila()
{
    pista_1.tempo_medio_filas(1,2);
    pista_2.tempo_medio_filas(3,4);
}

void Aeroporto::diminuindo_tempo()
{
    pista_1.diminuir_tempo();
    pista_2.diminuir_tempo();
}

void Aeroporto::emergencia()
{
    pista_1.emergencia();
}

//fim do código