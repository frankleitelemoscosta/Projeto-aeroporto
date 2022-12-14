
//inicio das bibliotecas
#include"/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/SEGUNDO PERIODO/PROG2/SEGUNDO TRABALHO/Entrada_Aleatoria/hpp/pista.hpp"
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

void Pista::inserir_na_aterrissagem(int id, int minutos_combustivel, int numero_de_passageiros,string nome_companhia,int id_fila,int id_fila2,int pista)
{
    if(fila_1.vazia() && fila_2.vazia())//para a primeira inserção
    {
        fila_1.inserir_na_fila(id,minutos_combustivel, numero_de_passageiros, nome_companhia,id_fila,pista);
    }
    else if (!fila_1.vazia())//para o programa saber como deixar as filas com tamanhos parecidos
    {
        if(fila_1.size()<fila_2.size())
        {
            fila_1.inserir_na_fila(id,minutos_combustivel, numero_de_passageiros, nome_companhia,id_fila,pista);
        }
        else
        {
            fila_2.inserir_na_fila(id,minutos_combustivel, numero_de_passageiros, nome_companhia,id_fila2,pista);
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

void Pista::Tempo_Global_Aterrissagem()
{
    fila_1.Tempo_Gobal();//não importa qual vai ser chamada, pois o membro é static e vai estar apos os calculos de tempo medio no menu
}

void Pista::Tempo_Global_Decolagem()
{
    fila.Tempo_Global_Decolagem();
}

void Pista::Prioridade_Combustivel()
{
    fila_1.Prioridade_combustivel();
    fila_2.Prioridade_combustivel();
}

int Pista::Pegar_prioridade_P1()
{
    return fila_1.contador_auxiliar1();
}

int Pista::Pegar_prioridade_P2()
{
    return fila_2.contador_auxiliar2();
}

void Pista::Zerando_contadores()
{
    fila_1.Zerando_contadores();
    fila_2.Zerando_contadores();
}
//fim do código