
#include "Aviao.hpp"

Aviao::Aviao(){
  
}

Aviao::Aviao(int num_passageiros, int minutos_de_combustivel, string compania)
{
  this-> proximo = nullptr;
  this->num_passageiros = num_passageiros;
  this->minutos_de_combustivel = minutos_de_combustivel;
  this->ID = 0;
  this->compania = compania;
  this->minutos_para_emergencia = -1; 
  this->espera_para_decolagem = -1; 
}


void Aviao::Declarar_prox(Aviao *ponteiro)
{
  this->proximo = ponteiro;
}
Aviao* Aviao::Pegar_prox() 
{
  return this->proximo;
}


//Gets e Sets da classe:

int Aviao::Pegar_num_passageiros() 
{
  return this->num_passageiros;
}

int Aviao::Declarar_num_passageiros(int num_passageiros) 
{
  return this->num_passageiros = num_passageiros;
}

int Aviao::Pegar_minutos_de_combustivel() 
{
  return this->minutos_de_combustivel;
}

int Aviao::Declarar_minutos_de_combustivel(int minutos_de_combustivel) 
{
  return this->minutos_de_combustivel = minutos_de_combustivel;
}

int Aviao::Pegar_ID() 
{
  return this->ID;
}

int Aviao::Declarar_ID(int ID) 
{
  return this->ID = ID;
}

string Aviao::Pegar_compania() 
{
  return this->compania;
}

string Aviao::Declarar_compania(string compania) 
{
  return this->compania = compania;
}


int Aviao::Pegar_minutos_para_emergencia() 
{
  return this->minutos_para_emergencia;
}

int Aviao::Declarar_minutos_para_emergencia(int minutos_para_emergencia) 
{
  return this->minutos_para_emergencia = minutos_para_emergencia;
}

int Aviao::Pegar_espera_para_decolagem() 
{
  return this->espera_para_decolagem;
}

int Aviao::Declarar_espera_para_decolagem(int espera_para_decolagem) 
{
  return this->espera_para_decolagem = espera_para_decolagem;
}


//fim dos gets e sets


//fim do código
