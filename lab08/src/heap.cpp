#include <algorithm>
#include "../include/heap.hpp"

Heap::Heap(int maxsize) {
    tamanho = 0;
    data = new int[maxsize];
}

Heap::~Heap() {
    delete[] data;
}

void Heap::Inserir(int x) {
    if (tamanho == 0) {
        data[0] = x;
        tamanho++;
    } else {
        int posicao = tamanho;
        data[posicao] = x;
        tamanho++;

        HeapifyPorCima(posicao);
    }
}

int Heap::Remover() {
    if (tamanho == 0) {
        return -1;
    }

    int raiz = data[0];
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

    if (esq < tamanho && data[esq] < data[menor]) {
        menor = esq;
    }
    if (dir < tamanho && data[dir] < data[menor]) {
        menor = dir;
    }
    if (menor != posicao) {
        std::swap(data[posicao], data[menor]);
        HeapifyPorBaixo(menor);
    }
}

void Heap::HeapifyPorCima(int posicao) {
    int ancestral = GetAncestral(posicao);

    if (posicao > 0 && data[posicao] < data[ancestral]) {
        std::swap(data[posicao], data[ancestral]);
        HeapifyPorCima(ancestral);
    }
}