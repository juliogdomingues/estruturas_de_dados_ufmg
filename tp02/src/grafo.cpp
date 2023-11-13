#include "../include/grafo.hpp"

#include <iostream>
#include <stdexcept>

Grafo::Grafo(int numeroVertices) : numeroVertices(numeroVertices), grafo(new Vetor[numeroVertices]), vertices(Vetor(numeroVertices)) {
    for (int i = 0; i < numeroVertices; i++) {
        vertices.adicionar(Item(i)); 
    }        
}

void Grafo::insereAresta(int v1, int v2) {
    if (v1 < 0 || v1 >= numeroVertices || v2 < 0 || v2 >= numeroVertices) {
        throw std::out_of_range("Índice de vértice fora do intervalo");
    }
    Item item(v2); 
    grafo[v1].adicionar(item); 
}

void Grafo::setCor(int vertice, int cor) {
    if (vertice < 0 || vertice >= numeroVertices) {
        throw std::out_of_range("Índice de vértice fora do intervalo");
    }
    vertices[vertice].valor = cor;
}

int Grafo::Greedy(Vetor grafo[], Vetor& vertices, int n) {
    for (int i = 0; i < n; ++i) {
        if (i >= vertices.getTamanho()) {
            std::cerr << "Erro: Índice i (" << i << ") fora dos limites para cores.\n";
            throw std::out_of_range("Índice i fora dos limites para cores");
        }
        int corAtual = vertices[i].valor;

        for (int c = 1; c < corAtual; c++) {
            bool existeCorVizinha = false;
            for (int j = 0; j < grafo[i].getTamanho(); ++j) {
                int indiceVizinho = grafo[i][j].chave;
                if (indiceVizinho >= vertices.getTamanho()) {
                    std::cerr << "Erro: Índice indiceVizinho (" << indiceVizinho << ") fora dos limites para cores.\n";
                    throw std::out_of_range("Índice indiceVizinho fora dos limites para cores");
                }

                if (vertices[indiceVizinho].valor == c) existeCorVizinha = true;
            }
            if  (!existeCorVizinha) {
                return 0;
            }
        }
    }
    return 1;
}