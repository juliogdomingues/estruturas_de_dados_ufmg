#ifndef TP1_ED_PILHA_H
#define TP1_ED_PILHA_H

#include <iostream>

template <typename T>
class TipoCelula
{
public:
    TipoCelula();

private:
    T item;
    TipoCelula *prox;

    template <typename U>
    friend class PilhaEncadeada;
};

template <typename T>
class Pilha
{
public:
    Pilha() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };

    virtual void Empilha(T item) = 0;
    virtual T Desempilha() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};

template <typename T>
class PilhaEncadeada : public Pilha<T>
{
public:
    PilhaEncadeada();
    ~PilhaEncadeada() { Limpa(); };
    void Empilha(T item);
    T Desempilha();
    T GetTopo();
    void Limpa();

private:
    TipoCelula<T> *topo;
};

#endif