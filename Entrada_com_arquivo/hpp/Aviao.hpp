

//inicio das bibliotecas
    #ifndef AVIAO_HPP
    #define AVIAO_HPP
    #include <string>
    #include <iostream>
    #include <stdlib.h>
    using namespace std;
//fim das bibliotecas

//Definindo uma lista encadeada de obejtos:
class Aviao
{    
    private:

        Aviao *proximo;
        Aviao *anterior;
        int num_passageiros;
        int minutos_de_combustivel;
        int ID;
        string companhia;
        int espera_para_decolagem;
        int minutos_ate_aterrissar;//armazena quanto tempo um avião levou para aterrissar
        int identificador_fila;//com essa variavel se torna possível distinguir as filas
        int decolagem_tempo;
        int identificador_pista;

    //fim dos atributos
    public:
        //Construtores de Avião:
        Aviao();
        Aviao(int num_passageiros, int minutos_de_combustivel, string companhia);

        //Gets e Sets de Avião:
        void Inserir_proximo(Aviao *ponteiro);
        Aviao *Pegar_proximo();

        int Inserir_num_passageiros(int num_passageiros);
        int Pegar_num_passageiros();

        int Inserir_minutos_de_combustivel(int minutos_de_combustivel);
        int Pegar_minutos_de_combustivel();

        int Inserir_ID(int ID);
        int Pegar_ID();

        string Inserir_companhia(string compania);
        string Pegar_companhia();

        int Inserir_espera_para_decolagem(int espera_para_decolagem);
        int Pegar_espera_para_decolagem();

        void Diminuir_tempo_aterrissagem();
        void Iniciando_tempo_aterrissagem();
        int Pegar_tempo_aterrissagem();

        void Inserir_identificador_fila(int id_fila);
        int Pegar_fila_aviao();

        void Inserir_anterior(Aviao *ponteiro);
        Aviao *pegar_anterior();

        void Aumentar_tempo_decolagem();
        void Iniciando_tempo_decolagem();
        int Pegar_tempo_decolagem();

        void Inserir_pista(int pista);
        int Pegar_pista();
        //fim dos métodos
};

#endif

//fim do código