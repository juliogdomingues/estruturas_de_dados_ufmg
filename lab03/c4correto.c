#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int rows, cols;
  int **data;
};

int main(){
  int i;
  // char *text; -> não está sendo utilizado
  struct Matrix *rotation3D;

  rotation3D = (struct Matrix *) malloc(sizeof(struct Matrix)); // alocando memória para o struct
  if (rotation3D == NULL) // verificação de erro na alocação de memoria
  {
    perror("Error: memory allocation failed");
    return 1;
  }
  
  rotation3D->rows=4;
  rotation3D->cols=4;

  rotation3D->data= (int**)malloc(sizeof(int*) * rotation3D->rows);
  if (rotation3D->data==NULL) // verificação de erro na alocação de memoria
  {
    perror("Error: memory allocation failed");
    return 1;
  }

  for(i=0;i<rotation3D->rows;i++) // alocando memória para cada linha do array de inteiros
  {
    rotation3D->data[i]=(int*) malloc(sizeof(int) * rotation3D->cols);
    if (rotation3D->data[i] == NULL) // verificação de erro na alocação de memoria
    {
      perror("Error: memory allocation failed for rotation3D->data[i]");
      // liberando a memória alocada anteriormente
      for (int j=0; j< i; j++) 
      {
        free(rotation3D->data[j]);
      }
      free(rotation3D->data);
      free(rotation3D);
      return 1;
    }
  }

  for(i=0;i<rotation3D->rows;i++)
  {
   free(rotation3D->data[i]);
  }
  free(rotation3D->data);
  free(rotation3D);

  return 0;
}

