//inicio das bibliotecas
    #include"/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/SEGUNDO PERIODO/PROG2/SEGUNDO TRABALHO/Entrada_com_arquivo/hpp/Aeroporto.hpp"
//fim das bibliotecas

Aeroporto::Aeroporto()//construtor
{

}

void Aeroporto::inserir_aviao_na_aterrissagem(int id, int minutos_combustivel, int numero_de_passageiros, string nome_companhia)
{

    if(pista_1.tamanho_filas() < pista_2.tamanho_filas())//para inserir na menor fila visando deixa-las com o mesmo tamanho
    {
        pista_1.inserir_na_aterrissagem(id, minutos_combustivel, numero_de_passageiros,nome_companhia,1,2,1);
    }else
    {
        pista_2.inserir_na_aterrissagem(id, minutos_combustivel, numero_de_passageiros, nome_companhia,3,4,2);
    }
    
}


void Aeroporto::impressao_filas()
{
    //aqui o que ocorre é que o programa acessa as duas pistas com suas duas filas para ler as filas por completo
    pista_1.mostrar_filas();
    pista_2.mostrar_filas();
    pista_3.mostrar_filas();
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
    pista_1.Zerando_contadores();
    pista_2.Zerando_contadores();
    pista_1.emergencia();
    pista_2.emergencia();
}

void Aeroporto::inserir_aviao_na_decolagem(int id,int minutos_combustivel,int numero_passageiros, string nome_da_companhia)
{
    if(pista_1.tamanho_fila_decolagem() < pista_2.tamanho_fila_decolagem())
    {
        pista_1.inserir_decolagem(id,1,minutos_combustivel,numero_passageiros,nome_da_companhia);
    } 
    else if(pista_2.tamanho_fila_decolagem() < pista_3.tamanho_filas())
    {
        pista_2.inserir_decolagem(id,2,minutos_combustivel,numero_passageiros,nome_da_companhia);
    } 
    else
    {
        pista_3.inserir_na_decolagem(id, minutos_combustivel, numero_passageiros, nome_da_companhia);
    } 
}

void Aeroporto::tempo_medio_decolagem()
{
    pista_1.tempo_medio_decolagem(1);
    pista_2.tempo_medio_decolagem(2);
    pista_3.tempo_medio_fila_decolagem(3);
}

void Aeroporto::aumentar_tempo()
{
    pista_1.aumentar_tempo();
    pista_2.aumentar_tempo();
    pista_3.aumentar_tempo();
}

void Aeroporto::Decisao_para_pista(int Pista1,int Pista2)
{
    int Pista3 = 1;

    if(pista_1.Pegar_prioridade_P1() == 1)
    {
        Pista1 = 0;
        cout<<"Foi pousado um aviao na primeira pista por falta de combustivel"<<endl;

    }else if(pista_1.Pegar_prioridade_P1() == 2)
    {
        Pista1 = 0;
        Pista2 = 0;
        cout<<"Foi pousado dois avioes um na pista 2 e outro na pista 1, por falta de combustivel"<<endl;

    }else if(pista_1.Pegar_prioridade_P1() >= 3)
    {
        Pista1 = 0;
        Pista2 = 0;
        Pista3 = 0;
        cout<<"Foram pousados três avioes nas tres pistas, por falta de combustivel"<<endl;
    }

    if(pista_2.Pegar_prioridade_P2() == 1)
    {
        Pista1 = 0;

        cout<<"Foi pousado um aviao na segunda pista por falta de combustivel"<<endl;

    }else if(pista_1.Pegar_prioridade_P2() == 2)
    {
        Pista1 = 0;
        Pista2 = 0;
        cout<<"Foi pousado dois avioes um na pista 2 e outro na pista 1, por falta de combustivel"<<endl;
    }else if(pista_1.Pegar_prioridade_P2() >= 3)
    {
        Pista1 = 0;
        Pista2 = 0;
        Pista3 = 0;
        cout<<"Foram pousados três avioes nas tres pistas, por falta de combustivel"<<endl;
    }
    
    //para pista 1
    if(Pista1 != 0)
    {
        switch(Pista1)
        {
            case 1:
                pista_1.remover_da_decolagem();
            break;
            case 2:
                pista_1.remover_da_aterrissagem();
            break;
        }
    }

    if(Pista1 == 1)
    {
        cout<<"Aconteceu uma decolagem na Primeira pista!"<<endl<<endl;
    }else{
        cout<<"Aconteceu um pouso na pista um"<<endl<<endl;
    }
    
    if(Pista2 != 0)
    {
        switch(Pista2)
        {
            case 1:
                pista_2.remover_da_decolagem();
            break;
            case 2:
                pista_2.remover_da_aterrissagem();
            break;
        }
    }

    if(Pista2 == 1)
    {
        cout<<"Aconteceu uma decolagem na segunda pista!"<<endl<<endl;
    }else{
        cout<<"Aconteceu um pouso na pista dois"<<endl<<endl;
    }

    if(pista_3.Aterrissagem_vazia()==false)
    {
        Pista3 = 2;
    }

    if(Pista3 == 1)
    {
        cout<<"Aconteceu uma decolagem na terceira pista!"<<endl<<endl;
    }else{
        cout<<"Aconteceu um pouso de emergencia na pista três"<<endl<<endl;
    }

    if(Pista3 != 0)
    {
        switch (Pista3)
        {
            case 1:
                pista_3.remover_decolagem();
            break;
            case 2:
                pista_3.remover_da_aterrissagem();
            break;
        }
    }
}

void Aeroporto::Tempo_Global_aterrissagem()
{
    pista_1.Tempo_Global_Aterrissagem();
}

void Aeroporto::Tempo_Global_Decolagem()
{
    pista_1.Tempo_Global_Decolagem();
}
//fim do código