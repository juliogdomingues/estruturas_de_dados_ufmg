#include<stdlib.h>
#include<stdio.h>
#include<time.h>

const int ARR_SIZE = 1000;

int main() {
    // create an array of ARR_SIZE ints
    int *intArray = malloc(sizeof(int) * ARR_SIZE);
    if (intArray == NULL) // verificação de erro na alocação de memoria
    {
        perror("Error: memory allocation failed");
        return 1;
    }

    // populate them
    for (int i=0; i < ARR_SIZE; i++) {
        intArray[i] = i;
    }

    // print one out
    // first, seed the random number generator
    srand(time(NULL));
    int randNum = rand() % ARR_SIZE;

    printf("intArray[%d]: %d\n", randNum, intArray[randNum]);


    free(intArray); // liberando a memória alocada
    return 0;
}

