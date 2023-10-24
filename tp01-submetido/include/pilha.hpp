#ifndef TP1_ED_PILHA_H
#define TP1_ED_PILHA_H

#include <iostream>

class TipoCelula
{
    public:
        TipoCelula();

    private:
        char item;
        TipoCelula *prox;

    friend class PilhaEncadeada;
};

class Pilha
{
public:
    Pilha() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };

    virtual void Empilha(char item) = 0;
    virtual char Desempilha() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};

class PilhaEncadeada : public Pilha
{
    public:
        PilhaEncadeada();
        ~PilhaEncadeada() { Limpa(); };
        void Empilha(char item);
        char Desempilha();
        char GetTopo();
        void Limpa();

    private:
        TipoCelula* topo;
};

#endif
