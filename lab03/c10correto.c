#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *p;
    int max_allocations = 10; // definindo um número máximo de alocações

    for (int i = 0; i < max_allocations; i++)
    {
        p = malloc(128);
        if (p == NULL) // verificação de erro na alocação de memoria
        {
            perror("Error: memory allocation failed");
            break;
        }
        printf("%ld\n", (long)p);
        free(p); // liberando a memória alocada
    }
    return (0);
}
