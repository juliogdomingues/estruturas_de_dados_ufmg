#include <stdlib.h>
#include <stdio.h>

void f(void) {
    int* x = malloc(11 * sizeof(int)); // alocando um valor válido para acessar o indice 10
    if (x == NULL) // verificação de erro na alocação de memoria
    {
        printf("Error: memory allocation failed");
        exit(1); // sair do programa com o código de erro 1
    }
    x[10] = 0; 
    free(x); // liberando a memória alocada
}

int main(void) {
    f();

    return 0;
}


