#ifndef TP1_ED_PILHA_H
#define TP1_ED_PILHA_H

#include <iostream>

// typedef int TipoChave; // TipoChave é um inteiro
// typedef char TipoItem; // TipoItem é um char

class TipoCelula
{
    public:
        TipoCelula();

    private:
        char item;
        TipoCelula *prox;

    friend class PilhaEncadeada;
};

class TipoItem
{
    public:
        TipoItem();
        TipoItem(char c);
        void SetChave(char c);
        char GetChave();
        void Imprime();

    private:
        char chave;
        // outros membros
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
        virtual ~PilhaEncadeada();

        void Empilha(char item);
        char Desempilha();
        char GetTopo();

        void Limpa();

    private:
        TipoCelula* topo;
};

#endif
