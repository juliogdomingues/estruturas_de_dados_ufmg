#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *p;

  p = (char *) malloc(19);
  if (p == NULL) // verificação de erro na alocação de memoria
  {
    perror("Error: memory allocation failed");
    return 1;
  }
  free(p); // liberando a memoria alocada

  p = (char *) malloc(12);
  if (p == NULL) // verificação de erro na alocação de memoria
  {
    perror("Error: memory allocation failed");
    return 1;
  }
  free(p); // liberando a memoria alocada
  
  p = (char *) malloc(16);
  if (p == NULL) // verificação de erro na alocação de memoria
  {
    perror("Error: memory allocation failed");
    return 1;
  }
  free(p); // liberando a memoria alocada

  return 0;
}

