#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char *msg = malloc(10); // alocar memória para "Holberton" mais o caractere nulo '\0'
    if (msg == NULL) // verificação de erro na alocação de memoria
    {
        perror("Error: memory allocation failed");
        return 1;
    }

    strcpy(msg, "Holberton");
    msg[0] = 'R';
    printf("%ld, %s\n", (long)getpid(), msg);

    free(msg);
    return (0);
}
