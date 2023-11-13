#include <algorithm>
#include <cassert>
#include <cstring>
#include <getopt.h>
#include <iostream>
#include <stdexcept>

#include <chrono>
#include <fstream>


#include "../include/sort.hpp"
#include "../include/item.hpp"

int main() {

auto start = std::chrono::high_resolution_clock::now();

    char metodo;
    int nVertices;
    int max = 0;

    if (!(std::cin >> metodo >> nVertices)) {
        std::cerr << "Erro ao ler entrada.\n";
        return 1;
    }

    // Verifica se o número de vértices é positivo
    if (nVertices <= 0) {
        std::cerr << "Número de vértices deve ser positivo.\n";
        return 1;
    }

    Grafo *grafo = new Grafo(nVertices);
    try {
        grafo = new Grafo(nVertices);
    } catch (const std::bad_alloc& e) {
        std::cerr << "Falha na alocação de memória: " << e.what() << '\n';
        return 1;
    }

    for (int i = 0; i < nVertices; i++) {
        int numeroVizinhos, adjacente;
        std::cin >> numeroVizinhos;

        for (int j = 0; j < numeroVizinhos; j++) {
            std::cin >> adjacente;
            grafo->insereAresta(i, adjacente);
        }
    }

    for (int i = 0; i < nVertices; i++) {
        int corVertice;
        std::cin >> corVertice;
        grafo->setCor(i, corVertice); // Define a cor de cada vértice
        if (corVertice > max) max = corVertice;
    }

    Ordenacao ordenacao(grafo); 
    Vetor& vertices = grafo->getVertices(); // Obtém os vértices do grafo

    // Verifica se a coloração é gulosa
    int resultadoColoracao = grafo->Greedy(grafo->getGrafo(), grafo->getVertices(), nVertices);

    // Imprime o resultado da verificação
    if (resultadoColoracao == 0) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << "1 ";
        ordenacao.Ordena(metodo); // Ordena os vértices

        for (unsigned int i = 0; i < vertices.getTamanho(); ++i) {
            std::cout << vertices[i].chave << " ";
        }
        std::cout << std::endl;
    }

    delete grafo; // Liberar a memória alocada


    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    std::cout << "Tempo de execução: " << duration.count() << " microssegundos" << std::endl;

std::ofstream file("resultados.txt");
file << "Tempo de execução para o método " << metodo << ": " << duration.count() << " microssegundos" << std::endl;
file.close();

    return 0;
}