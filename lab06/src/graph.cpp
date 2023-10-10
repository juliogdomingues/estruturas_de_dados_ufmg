#include <climits>
#include <iostream>

#include "../include/graph.hpp"

Grafo::Grafo() {
    // Construtor: inicializa o grafo
}

Grafo::~Grafo() {
    // Destrutor: pode ser usado para liberar recursos, se necessário
    // Delete lista de adjacentes de cada vertice
}

void Grafo::InsereVertice() {
    // Insere um vértice no grafo
    TipoItem vertex = TipoItem();
    ListaEncadeada *adjacentes = new ListaEncadeada();
    vertex.SetValor(adjacentes);
    vertices.InsereFinal(vertex);
}

void Grafo::InsereAresta(int v, int w) {
    GetAdjacentes(v)->InsereFinal(TipoItem(w));
}

int Grafo::QuantidadeVertices() {
    // Retorna o número de vértices no grafo
    return vertices.GetTamanho();
}

int Grafo::QuantidadeArestas() {
    // Retorna o número de arestas no grafo
    // Considerando que cada chamada de InsereAresta insere duas arestas, divida o tamanho da lista por 2
    int numArestas = 0;
    for (int i = 0; i < vertices.GetTamanho(); i++) {
        numArestas += GetAdjacentes(i)->GetTamanho();
    }
    return numArestas / 2;
}

int Grafo::GrauMinimo() {
    // Calcula e retorna o grau mínimo no grafo
    int grauMinimo = INT_MAX; // Inicializa com um valor grande
    for (int i = 0; i < vertices.GetTamanho(); i++) {
        int grau = GetAdjacentes(i)->GetTamanho();
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
        int grau = GetAdjacentes(i)->GetTamanho();
        if (grau > grauMaximo) {
            grauMaximo = grau;
        }
    }
    return grauMaximo;
}

void Grafo::ImprimeVizinhos(int v) {
    // Imprime os vizinhos do vértice v
    ListaEncadeada *adjacentes = GetAdjacentes(v);
    for (int i = 0; i < adjacentes->GetTamanho(); i++) {
        std::cout << adjacentes->GetItem(i).GetChave() << " ";
    }
}

bool Grafo::GrafoCompleto() {
    int numVertices = QuantidadeVertices();
    return QuantidadeArestas() == numVertices * (numVertices - 1) / 2;
}

ListaEncadeada *Grafo::GetAdjacentes(int vertex) {
    TipoItem vertexItem = vertices.GetItem(vertex);
    return ((ListaEncadeada *)(vertexItem.GetValor()));
}