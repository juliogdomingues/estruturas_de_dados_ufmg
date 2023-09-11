#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b, int *c){
  if (b==0)
  {
    fprintf(stderr, "Erro: divisão por zero!\n");
    return 1; // retorna um código de erro caso falhe
  }
  *c=a/b;
  return 0;
}

int calc(){
  int a;
  int b;
  int c; // variável para armazenar o resultado da divisao
  a=13;
  b=0;

  if (actual_calc(a, b, &c) != 0)
  {
    return 1; // retorna um código de erro se a divisão por zero ocorrer
  }
  return 0;
}

int main(){
  if (calc() != 0)
  {
    return 1; // retorna um código de erro
  }
  return 0;
}
