#include "../include/pilha.hpp"

template <typename T>
TipoCelula<T>::TipoCelula()
{
    prox = nullptr;
}

template <typename T>
PilhaEncadeada<T>::PilhaEncadeada() : Pilha<T>()
{
    topo = nullptr;
}

template <typename T>
void PilhaEncadeada<T>::Empilha(T item)
{
    TipoCelula<T> *nova;
    nova = new TipoCelula<T>();
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    this->tamanho++;
}

template <typename T>
T PilhaEncadeada<T>::Desempilha()
{
    T aux;
    TipoCelula<T> *p;

    if (this->tamanho == 0)
        throw "A pilha está vazia!";

    aux = topo->item;
    p = topo;
    topo = topo->prox;

    delete p;
    this->tamanho--;

    return aux;
}

template <typename T>
T PilhaEncadeada<T>::GetTopo()
{
    if (topo != nullptr)
    {
        return topo->item;
    }
    else
    {
        throw std::runtime_error("A pilha está vazia!");
    }
}

template <typename T>
void PilhaEncadeada<T>::Limpa()
{
    while (!this->Vazia())
        Desempilha();
}

// Explicit instantiation for supported types (char and int)
template class TipoCelula<char>;
template class TipoCelula<int>;
template class PilhaEncadeada<char>;
template class PilhaEncadeada<int>;
