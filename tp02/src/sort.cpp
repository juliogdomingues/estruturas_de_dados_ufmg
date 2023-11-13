#include "../include/sort.hpp"

#include <iostream>

#define Troca(A, B) {Item c = A; A = B; B = c; }

void Ordenacao::BolhaImparPar(Item *v, int n) {
    bool estaOrdenado = false; // Inicialmente, o array não está ordenado

    while (!estaOrdenado) {
        estaOrdenado = true;

        // Realiza Bubble Sort nos elementos de índices ímpares
        for (int i = 1; i <= n - 2; i += 2) {
            if (v[i] > v[i + 1]) {
                Troca(v[i], v[i + 1]);
                estaOrdenado = false;
            }
        }

        // Realiza Bubble Sort nos elementos de índices pares
        for (int i = 0; i <= n - 2; i += 2) {
            if (v[i] > v[i + 1]) {
                Troca(v[i], v[i + 1]);
                estaOrdenado = false;
            }
        }
    }
}


void Ordenacao::Bolha (Item *v, int n) {
	int i, j;

  for(i = 0; i < n-1; i++)
    for(j = 1; j < n-i; j++)
      if (v[j] < v[j-1]) 
        Troca(v[j-1], v[j]);
}

void Ordenacao::Selecao (Item *v, int n){ 
  int i, j, Min;

  for (i = 0; i < n - 1; i++){ 
    Min = i;
    for (j = i + 1 ; j < n; j++){
      if (v[j] < v[Min]) 
        Min = j;
    }
    Troca(v[i], v[Min]);
  }
}

void Ordenacao::Insercao(Item *v, int n) {
int i,j;
Item aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    j = i - 1;
    while (( j >= 0 ) && (aux < v[j])) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
  }
}

void Ordenacao::Particao(int Esq, int Dir, 
			  int *i, int *j, Item *A) { 
  Item x, w;
  *i = Esq; *j = Dir;
  x = A[(*i + *j)/2]; /* obtem o pivo x */
  do { 
    while (x > A[*i]) (*i)++;
    while (x < A[*j]) (*j)--;
    if (*i <= *j)
    { 
		w = A[*i]; A[*i] = A[*j]; A[*j] = w;
      (*i)++; (*j)--;
    }
  } while (*i <= *j);
}

/* Entra aqui o procedimento Particao */
void Ordenacao::OrdenaQuick(int Esq, int Dir, Item *A) {
  int i, j;
  Particao(Esq, Dir, &i, &j, A);
  if (Esq < j) OrdenaQuick(Esq, j, A);
  if (i < Dir) OrdenaQuick(i, Dir, A);
}

void Ordenacao::QuickSort(Item *A, int n) { 
  OrdenaQuick(0, n-1, A); 
}

// Função merge modificada para trabalhar com Item
Item* Ordenacao::merge(Item *valuesL, Item *valuesR, int nl, int nr) {
    Item *result = new Item[nl + nr];
    int i = 0, j = 0, k = 0;

    while (i < nl && j < nr) {
        if (valuesL[i] < valuesR[j]) {
            result[k++] = valuesL[i++];
        } else {
            result[k++] = valuesR[j++];
        }
    }

    while (i < nl) {
        result[k++] = valuesL[i++];
    }

    while (j < nr) {
        result[k++] = valuesR[j++];
    }

    return result;
}

// Função auxiliar para o merge sort
void Ordenacao::mergeSortAux(Item *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortAux(arr, left, mid);
        mergeSortAux(arr, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        Item *L = new Item[n1];
        Item *R = new Item[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        Item *merged = merge(L, R, n1, n2);
        for (int i = 0; i < n1 + n2; i++) {
            arr[left + i] = merged[i];
        }

        delete[] L;
        delete[] R;
        delete[] merged;
    }
}

// Função principal do merge sort
void Ordenacao::mergeSort(Item *arr, int n) {
    mergeSortAux(arr, 0, n - 1);
}

void Ordenacao::Refaz(int Esq, int Dir, Item *A) {
    int i = Esq;
    int j = 2 * i + 1; // Filho da esquerda
    Item x = A[i];
    while (j <= Dir) {
        if (j < Dir && A[j] < A[j + 1]) {
            j++; // j é o filho da direita
        }
        if (x >= A[j]) break;
        A[i] = A[j];
        i = j;
        j = 2 * i + 1;
    }
    A[i] = x;
}

void Ordenacao::Constroi(Item *A, int n) {
    int Esq = (n / 2) - 1;
    while (Esq >= 0) { 
        Refaz(Esq, n - 1, A);
        Esq--;
    }
}

void Ordenacao::Heapsort(Item *A, int n) {
    Constroi(A, n); // Constroi o heap
    for (int Dir = n - 1; Dir > 0; Dir--) { // Ordena o vetor
        Item x = A[0];
        A[0] = A[Dir];
        A[Dir] = x;
        Refaz(0, Dir - 1, A);
    }
}

Item Ordenacao::RetiraMax(Item *A, int *n) {
  Item Maximo;
  if (*n < 1)
    std::cout << "Erro: heap vazio" << std::endl;
  else { 
    Maximo = A[1]; 
    A[1] = A[*n]; 
    (*n)--;
    Refaz(1, *n, A);
  }
  return Maximo;
}
    
void Ordenacao::Ordena(char metodo) {
    switch (metodo) {
        case 'b':
            Bolha(grafo->getVertices().getArray(), grafo->getNumeroVertices());
            break;
        case 's':
            Selecao(grafo->getVertices().getArray(), grafo->getNumeroVertices());
            break;
        case 'i':
            Insercao(grafo->getVertices().getArray(), grafo->getNumeroVertices());
            break;
        case 'q':
            QuickSort(grafo->getVertices().getArray(), grafo->getNumeroVertices());
            break;
        case 'm':
            mergeSort(grafo->getVertices().getArray(), grafo->getNumeroVertices());
            break;
        case 'p':
            Heapsort(grafo->getVertices().getArray(), grafo->getNumeroVertices());
            break;
        case 'y':
            BolhaImparPar(grafo->getVertices().getArray(), grafo->getNumeroVertices());
            break;
        default:
            std::cerr << "Método de ordenação desconhecido." << std::endl;
            break;
    }
}
