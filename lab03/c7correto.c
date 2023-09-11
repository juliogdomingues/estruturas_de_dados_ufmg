#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    char* alphabet = calloc(27, sizeof(char)); // alocando 27 bytes
    if (alphabet == NULL)  // verificação de erro na alocação de memoria
    {
        perror("Error: memory allocation failed");
        return 1;
    }

    for(uint8_t i = 0; i < 26; i++) {
        *(alphabet + i) = 'A' + i;
    }
    *(alphabet + 26) = '\0'; //null-terminate the string?

    free(alphabet);
    return 0;
}

