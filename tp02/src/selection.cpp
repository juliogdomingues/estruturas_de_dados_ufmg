#include "../include/selection.hpp"

void Selecao::Selecao (Item *v, int n){ 
  int i, j, Min;

  for (i = 0; i < n - 1; i++){ 
    Min = i;
    for (j = i + 1 ; j < n; j++){
      if (v[j].chave < v[Min].chave) 
        Min = j;
    }
    Troca(v[i], v[Min]);
  }
}