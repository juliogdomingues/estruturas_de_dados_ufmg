#include "../include/bubble.hpp"

void Bolha::Bolha (Item *v, int n) 
{
	int i, j;

  for(i = 0; i < n-1; i++)
    for(j = 1; j < n-i; j++)
      if (v[j].chave < v[j-1].chave) 
        Troca(v[j-1], v[j]);
}
