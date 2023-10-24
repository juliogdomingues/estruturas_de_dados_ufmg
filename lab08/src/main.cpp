#include <iostream>
#include "../include/heap.hpp"
#include "../include/unionFind.hpp"

int main() {
    int n, m;
    int contaUnioes = 0, custo = 0;

    std::cin >> n >> m;

    Heap minHeap(n);

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        Aresta aresta = {u, v, c};

        minHeap.Inserir(aresta);
    }

    UnionFind unionFind(n);

    while (!minHeap.Vazio() && contaUnioes < n - 1) {
        Aresta aresta = minHeap.Remover();
        int u = unionFind.Find(aresta.u);
        int v = unionFind.Find(aresta.v);

        if (u != v) {
            unionFind.Union(u, v);
            custo += aresta.custo;
            contaUnioes++;
        }
    }

    std::cout << custo << std::endl;

    return 0;
}
