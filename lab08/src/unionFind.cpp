#include "../include/unionFind.hpp"

UnionFind::UnionFind(int quantidade_subconjuntos) {
    tamanho = quantidade_subconjuntos;
    subconjuntos = new Subconjunto[quantidade_subconjuntos];
    for (int i = 0; i < quantidade_subconjuntos; i++) {
        subconjuntos[i].representante = i;
        subconjuntos[i].rank = 0;
    }
}

UnionFind::~UnionFind() {
    delete[] subconjuntos;
}

void UnionFind::Make(int x) {
    if (x >= 0 && x < tamanho) {
        subconjuntos[x].representante = x;
        subconjuntos[x].rank = 0;
    }
}

int UnionFind::Find(int x) {
    if (x >= 0 && x < tamanho) {
        if (subconjuntos[x].representante != x) {
            subconjuntos[x].representante = Find(subconjuntos[x].representante);
        }
        return subconjuntos[x].representante;
    } else {
        return -1; // invalido
    }
}

void UnionFind::Union(int x, int y) {
    int raiz_x = Find(x);
    int raiz_y = Find(y);

    if (raiz_x != -1 && raiz_y != -1 && raiz_x != raiz_y) {
        if (subconjuntos[raiz_x].rank < subconjuntos[raiz_y].rank) {
            subconjuntos[raiz_x].representante = raiz_y;
        } else if (subconjuntos[raiz_x].rank > subconjuntos[raiz_y].rank) {
            subconjuntos[raiz_y].representante = raiz_x; 
        } else {
            subconjuntos[raiz_y].representante = raiz_x;
            subconjuntos[raiz_x].rank++;
        }
    }
}