#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct _List {
    int32_t* data;
    int32_t length;
};
typedef struct _List List;

List* resizeArray(List* array) {
    int32_t* dPtr = array->data;
    int32_t* newDPtr = realloc(dPtr, 15 * sizeof(int32_t));
    if (newDPtr == NULL) // verificação de erro na alocação de memoria
    {
        perror("Error: memory allocation failed");
        return array; // retornar o array original caso falhe a alocação
    }

    array->data = newDPtr; // atualizar o campo data com o novo valor de dPtr
    return array;
}

int main() {
    List* array = calloc(1, sizeof(List));
    array->data = calloc(10, sizeof(int32_t));
    array = resizeArray(array);

    free(array->data);
    free(array);
    return 0;
}
