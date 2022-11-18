//inicio das bibliotecas
  #include "Aviao.hpp"
//fim das bibliotecas

Aviao::Aviao(){//construtor vazio
  
}

Aviao::Aviao(int num_passageiros, int minutos_de_combustivel, string companhia)
{
    this-> proximo = nullptr;
    this->num_passageiros = num_passageiros;
    this->minutos_de_combustivel = minutos_de_combustivel;
    this->ID = 0;
    this->companhia = companhia; 
    this->espera_para_decolagem = -1; 
}

//para alocação de memoria:
void Aviao::Inserir_proximo(Aviao *ponteiro)
{
  this->proximo = ponteiro;
}

Aviao* Aviao::Pegar_proximo() 
{
  return this->proximo;
}
//fim 


//Gets e Sets da classe:

int Aviao::Pegar_num_passageiros() 
{
  return this->num_passageiros;
}

int Aviao::Inserir_num_passageiros(int num_passageiros) 
{
  return this->num_passageiros = num_passageiros;
}

int Aviao::Pegar_minutos_de_combustivel() 
{
  return this->minutos_de_combustivel;
}

int Aviao::Inserir_minutos_de_combustivel(int minutos_de_combustivel) 
{
  return this->minutos_de_combustivel = minutos_de_combustivel;
}

int Aviao::Pegar_ID() 
{
  return this->ID;
}

int Aviao::Inserir_ID(int ID) 
{
  return this->ID = ID;
}

string Aviao::Pegar_companhia() 
{
  return this->companhia;
}

string Aviao::Inserir_companhia(string companhia) 
{
  return this->companhia = companhia;
}

int Aviao::Pegar_espera_para_decolagem() 
{
  return this->espera_para_decolagem;
}

int Aviao::Inserir_espera_para_decolagem(int espera_para_decolagem) 
{
  return this->espera_para_decolagem = espera_para_decolagem;
}

int Aviao::Pegar_tempo_aterrissagem()
{
    return this->minutos_ate_aterrissar;
}

void Aviao::Diminuir_tempo_aterrissagem()
{
    this->minutos_de_combustivel = this->minutos_de_combustivel - 1;
    this->minutos_ate_aterrissar = this->minutos_ate_aterrissar + 1;
}

void Aviao::Iniciando_tempo_aterrissagem()//esse método foi criado pois o construtor só é chamado uma vez, e no caso desse programa é necessário que isso ocorra toda vez que um nó for criado
{
    this->minutos_ate_aterrissar = 0;
}

void Aviao::Inserir_identificador_fila(int id_fila)
{
    this->identificador_fila = id_fila;//a ideia é filtrar o calculo onde ele é feito na fila aerea, utilizando ifs
}

int Aviao::Pegar_fila_aviao()
{
    return this->identificador_fila;//traz a qual fila o avião está
}

//fim dos gets e sets


//fim do código
