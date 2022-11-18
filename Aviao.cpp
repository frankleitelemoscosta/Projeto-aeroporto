//inicio das bibliotecas
  #include "Aviao.hpp"
//fim das bibliotecas

Aviao::Aviao(){//construtor vazio
  
}

Aviao::Aviao(int num_passageiros, int minutos_de_combustivel, string compania)
{
    this-> proximo = nullptr;
    this->num_passageiros = num_passageiros;
    this->minutos_de_combustivel = minutos_de_combustivel;
    this->ID = 0;
    this->compania = compania; 
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

string Aviao::Pegar_compania() 
{
  return this->compania;
}

string Aviao::Inserir_compania(string compania) 
{
  return this->compania = compania;
}

int Aviao::Pegar_espera_para_decolagem() 
{
  return this->espera_para_decolagem;
}

int Aviao::Inserir_espera_para_decolagem(int espera_para_decolagem) 
{
  return this->espera_para_decolagem = espera_para_decolagem;
}



//fim dos gets e sets


//fim do código
