#include "../include/pilha.hpp"

TipoCelula::TipoCelula() {
    item = -1; 
    prox = nullptr;
}

PilhaEncadeada::PilhaEncadeada() : Pilha() {
    topo = nullptr;
}

void PilhaEncadeada::Empilha(char item){
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};

char PilhaEncadeada::Desempilha() {
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
    if (topo != nullptr) {
        return topo->item;
    } else {
        throw std::runtime_error("A pilha está vazia!");
    }
}

void PilhaEncadeada::Limpa(){
    while(!Vazia())
        Desempilha();
}
