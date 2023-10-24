#include <algorithm>
#include "../include/heap.hpp"

Heap::Heap(int maxsize) : maxsize(maxsize) {
    tamanho = 0;
    data = new Aresta[maxsize];
}

Heap::~Heap() {
    delete[] data;
}

void Heap::Inserir(Aresta aresta) {
    if (tamanho < maxsize) {
        int posicao = tamanho;
        data[posicao] = aresta;
        tamanho++;

        HeapifyPorCima(posicao);
    }
}

Aresta Heap::Remover() {
    Aresta aresta_invalida = { -1, -1, -1 };

    if (tamanho == 0) {
        return aresta_invalida;
    }

    Aresta raiz = data[0];
    data[0] = data[tamanho - 1];
    tamanho--;

    HeapifyPorBaixo(0);

    return raiz;
}

bool Heap::Vazio() {
    return tamanho == 0;
}

int Heap::GetAncestral(int posicao) {
    return (posicao - 1) / 2;
}

int Heap::GetSucessorEsq(int posicao) {
    return 2 * posicao + 1;
}

int Heap::GetSucessorDir(int posicao) {
    return 2 * posicao + 2;
}


void Heap::HeapifyPorBaixo(int posicao) {
    int menor = posicao;
    int esq = GetSucessorEsq(posicao);
    int dir = GetSucessorDir(posicao);

    if (esq < tamanho && data[esq].custo < data[menor].custo) {
        menor = esq;
    }
    if (dir < tamanho && data[dir].custo < data[menor].custo) {
        menor = dir;
    }
    if (menor != posicao) {
        std::swap(data[posicao], data[menor]);
        HeapifyPorBaixo(menor);
    }
}

void Heap::HeapifyPorCima(int posicao) {
    int ancestral = GetAncestral(posicao);

    if (posicao > 0 && data[posicao].custo < data[ancestral].custo) {
        std::swap(data[posicao], data[ancestral]);
        HeapifyPorCima(ancestral);
    }
}