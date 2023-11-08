#include "../include/insertion.hpp"


void Insercao(Item *v, int n) {
int i,j;
Item aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    j = i - 1;
    while (( j >= 0 ) && (aux.Chave < v[j].Chave)) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
  }
}


// void Insercao(Item *v, Indice n){ 
//   Indice i, j;
//   Item aux;
//   for (i = 2; i <= n; i++){ 
//     aux = v[i]; 
//     j = i -1;
//     V[0] = aux; /* sentinela */
//     while (aux.Chave < v[j].Chave){
//       v[j+1] = v[j]; 
//       j--;
//     }
//     v[j+1] = aux;
//   }
// }

