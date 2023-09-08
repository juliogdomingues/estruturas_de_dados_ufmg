#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    char* destination = calloc(27, sizeof(char));
    char* source = malloc(27 * sizeof(char)); // alocando memória para source com o mesmo tamanho de destination
    if (destination == NULL || source == NULL) // verificação de erro na alocação de memoria
    {
        perror("Error: memory allocation failed");
        return 1;
    }

    for(uint8_t i = 0; i < 27; i++) {
        *(destination + i) = *(source + i); //Look at the last iteration.
    }

    free(destination);
    free(source);
    return 0;
}

