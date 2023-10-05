#include "../include/pilha.hpp"

PilhaArranjo::PilhaArranjo()
{
    topo = -1;
}

void PilhaArranjo::Empilha(char item)
{
    if (tamanho == MAXTAM)
        throw "A pilha está cheia!";

    topo++;
    itens[topo] = item;
    tamanho++;
}

char PilhaArranjo::Desempilha()
{
    char aux;

    if (tamanho == 0)
        throw "A pilha está vazia!";

    aux = itens[topo];
    topo--;
    tamanho--;
    return aux;
}

void PilhaArranjo::Limpa()
{
    topo = -1;
    tamanho = 0;
}

char PilhaArranjo::GetTopo() const
{
    if (tamanho == 0)
        throw "A pilha está vazia!";
    
    return itens[topo];
}
