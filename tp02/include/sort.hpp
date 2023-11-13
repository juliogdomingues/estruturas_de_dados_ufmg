#ifndef TP2_ED_SORT_HPP
#define TP2_ED_SORT_HPP

#include "../include/item.hpp"
#include "../include/grafo.hpp"
#include "../include/vetor.hpp"

class Ordenacao {
public:
    Ordenacao(Grafo *g) : grafo(g) {}
    void Ordena(char metodo);
    
    // Métodos de ordenação

    void Bolha (Item *v, int n);
    void BolhaImparPar(Item *v, int n);
    void Insercao(Item *v, int n);
    void Selecao (Item *v, int n);

    // QuickSort
    void Particao(int Esq, int Dir, int *i, int *j, Item *A);
    void OrdenaQuick(int Esq, int Dir, Item *A);
    void QuickSort(Item *A, int n);

    // MergeSort
    Item *merge(Item *valuesL, Item *valuesR, int nl, int nr);
    void mergeSortAux(Item *arr, int left, int right);
    void mergeSort(Item *arr, int n);

    // HeapSort
    void Constroi(Item *A, int n);
    void Refaz(int Esq, int Dir, Item *A);
    Item RetiraMax(Item *A, int *n);
    void Heapsort(Item *A, int n);

private:
    Grafo *grafo;
};

#endif
