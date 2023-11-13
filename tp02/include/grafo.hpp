#ifndef TP2_ED_GRAFO_HPP
#define TP2_ED_GRAFO_HPP

#include "../include/item.hpp"
#include "../include/vetor.hpp"

class Grafo {
public:
    Grafo(int numeroVertices);
    ~Grafo() { delete[] grafo; }
    void insereAresta(int v1, int v2);
    void setCor(int vertice, int cor);
    Vetor* getGrafo() { return grafo; }
    Vetor& getVertices() { return vertices; }
    int getNumeroVertices() const { return numeroVertices; }
    int Greedy(Vetor grafo[], Vetor& vertices, int n);

private:
    int numeroVertices;
    Vetor* grafo; // Array de Vetor para as listas de adjacências
    Vetor vertices; // Vértices do grafo
};

#endif
