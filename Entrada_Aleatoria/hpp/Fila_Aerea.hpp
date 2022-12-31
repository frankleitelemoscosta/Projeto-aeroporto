//
// Created by jeje on 04/10/22.
//

#ifndef FILA_AEREA_HPP
#define FILA_AEREA_HPP

//inicio das bibliotecas
    #include "Aviao.hpp"
//fim das bibliotecas

class Fila_Aerea
{
    private:

        Aviao *ponta;
        Aviao *dianteira;
        int tamanho;
        float Dividendo_fila1;
        float Dividendo_fila2;
        float Dividendo_fila3;
        float Dividendo_fila4;
        float contador_aterrissagem_fila1;
        float contador_aterrissagem_fila2;
        float contador_aterrissagem_fila3;
        float contador_aterrissagem_fila4;
        static int contador;
        static int contador2;//esse auxiliar a variavel contador
        static float tempo_Global;
        int contaddor_auxiliar1;
        int contaddor_auxiliar2;

//fim dos atributos
    public:

        Fila_Aerea();//construtor

        bool vazia();

        void inserir_na_fila(int id,int minutos_combustivel, int numero_de_passageiros,string nome_companhia,int id_fila,int pista);
        
        void mostrar_todos();
        
        void Buscar_Aviao(int ID);
        
        int size();
        
        void remover();
        
        void tempo_medio_filas(int fila);
        
        void diminuir_tempo();

        void emergencia();//para caso algum avião chega a 3 de combustível 

        void Tempo_Gobal();

        void Prioridade_combustivel();

        int contador_auxiliar1();

        int contador_auxiliar2();

        void Zerando_contadores();
//fim dos métodos
};

#endif //F_PROVA_Fila_Aerea_HPP
