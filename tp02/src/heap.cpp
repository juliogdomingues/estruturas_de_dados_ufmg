#include "../include/heap.hpp"

void Constroi(Item *A, int n) {
  int Esq;
  
  Esq = n / 2 + 1;
  while (Esq > 1) { 
    Esq--;
    Refaz(Esq, n, A);
  }
}

void  Refaz(int Esq, int Dir, Item *A){
  int i, j; 
  Item x;
  i = Esq;
  j = i * 2;
  x = A[i];
  while (j <= Dir){
    if (j < Dir)
       if (A[j].Chave < A[j+1].Chave) j++;
    if (x.Chave >= A[j].Chave) break;
    A[i] = A[j];
    i = j; 
    j = i *2;
  }
  A[i] = x;
}

Item RetiraMax(Item *A, int *n) {
  Item Maximo;
  if (*n < 1)
    printf(“Erro: heap vazio\n”);
  else { 
    Maximo = A[1]; 
    A[1] = A[*n]; 
    (*n)--;
    Refaz(1, *n, A);
  }
  return Maximo;
}

void Heapsort(Item *A, int *n) {
  int Esq, Dir;
  Item x;
  Constroi(A, n); /* constroi o heap */
  Esq = 1; Dir = *n;
  while (Dir > 1){ /* ordena o vetor */
    x = A[1]; 
    A[1] = A[Dir]; 
    A[Dir] = x; 
    Dir--;
    Refaz(Esq, Dir, A);
  }
}
