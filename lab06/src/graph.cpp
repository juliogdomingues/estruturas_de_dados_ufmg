#include <climits>
#include <iostream>

#include "../include/graph.hpp"

Grafo::Grafo() {
    // Construtor: inicializa o grafo
}

Grafo::~Grafo() {
    // Destrutor: pode ser usado para liberar recursos, se necessário
}

void Grafo::InsereVertice() {
    // Insere um vértice no grafo
    vertices.InsereFinal(TipoItem());
}

void Grafo::InsereAresta(int v, int w) {
    // Insere uma aresta entre os vértices v e w no grafo
    TipoItem item_w(w);
    vertices.InsereFinal(item_w);

    TipoItem item_v(v);
    vertices.InsereFinal(item_v);
}

int Grafo::QuantidadeVertices() {
    // Retorna o número de vértices no grafo
    return vertices.GetTamanho();
}

int Grafo::QuantidadeArestas() {
    // Retorna o número de arestas no grafo
    // Considerando que cada chamada de InsereAresta insere duas arestas, divida o tamanho da lista por 2
    return vertices.GetTamanho() / 2;
}

int Grafo::GrauMinimo() {
    // Calcula e retorna o grau mínimo no grafo
    int grauMinimo = INT_MAX; // Inicializa com um valor grande
    for (int i = 0; i < vertices.GetTamanho(); i++) {
        int grau = vertices.GetItem(i).GetChave();
        if (grau < grauMinimo) {
            grauMinimo = grau;
        }
    }
    return grauMinimo;
}

int Grafo::GrauMaximo() {
    // Calcula e retorna o grau máximo no grafo
    int grauMaximo = 0;
    for (int i = 0; i < vertices.GetTamanho(); i++) {
        int grau = vertices.GetItem(i).GetChave();
        if (grau > grauMaximo) {
            grauMaximo = grau;
        }
    }
    return grauMaximo;
}

void Grafo::ImprimeVizinhos(int v) {
    // Imprime os vizinhos do vértice v
    std::cout << "Vizinhos de " << v << ": ";
    for (int i = 0; i < vertices.GetTamanho(); i++) {
        int vizinho = vertices.GetItem(i).GetChave();
        if (vizinho == v) {
            continue; // Não imprime o próprio vértice como vizinho
        }
        std::cout << vizinho << " ";
    }
    std::cout << std::endl;
}
