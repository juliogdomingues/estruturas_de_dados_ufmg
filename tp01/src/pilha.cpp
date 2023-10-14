#include "../include/pilha.hpp"

TipoCelula::TipoCelula()
{
    item = -1; // Initialize with a char value
    prox = nullptr;
}

PilhaEncadeada::PilhaEncadeada() : Pilha()
{
    topo = nullptr;
}

PilhaEncadeada::~PilhaEncadeada()
{
    Limpa();
}

void PilhaEncadeada::Empilha(char item){
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};


char PilhaEncadeada::Desempilha(){
    char aux; TipoCelula *p;

    if(tamanho == 0)
        throw "A pilha está vazia!";

    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;

    return aux;
};

char PilhaEncadeada::GetTopo() {
    if (topo != NULL) {
        return topo->item;
    } else {
        // Handle the case when the stack is empty. You can throw an exception or return a default value.
        throw std::runtime_error("A pilha está vazia!"); // Or return a default TipoItem object
    }
}

void PilhaEncadeada::Limpa(){
    while(!Vazia())
        Desempilha();
}
