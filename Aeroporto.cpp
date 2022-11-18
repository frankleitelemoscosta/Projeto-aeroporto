//inicio das bibliotecas
    #include"Aeroporto.hpp"
//fim das bibliotecas

Aeroporto::Aeroporto()//construtor
{

}

void Aeroporto::inserir_aviao_na_aterrissagem(int id, int minutos_combustivel, int numero_de_passageiros, string nome_companhia)
{
    //inicio das variaveis locais
        int id_das_filas;
        int id_das_filas2;
    //fim das variaveis locais

    if(pista_1.tamanho_filas()<pista_2.tamanho_filas())//para inserir na menor fila visando deixa-las com o mesmo tamanho
    {
        id_das_filas = 1;
        id_das_filas2 = 2;
        pista_1.inserir_na_aterrissagem(id, minutos_combustivel, numero_de_passageiros,nome_companhia,id_das_filas,id_das_filas2);

    }else
    {
        id_das_filas = 3;
        id_das_filas2 = 4;
        pista_2.inserir_na_aterrissagem(id, minutos_combustivel, numero_de_passageiros, nome_companhia,id_das_filas,id_das_filas2);
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
    else{
        pista_2.remover_da_aterrissagem();
    }
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

//fim do código