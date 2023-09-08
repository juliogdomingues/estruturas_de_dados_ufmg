#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf[50]; // alocando memoria para buf

int sum_to_n(int num)
{
    int i,sum=0;
    for(i=1;i<=num;i++)
        sum+=i;
    return sum;
}

void printSum()
{
    char line[10];
    printf("enter a number:\n");
    fgets(line, 10, stdin);
    if(line[0] != '\n')
    { 
        strtok(line, "\n"); 
        sprintf(buf,"sum=%d",sum_to_n(atoi(line)));
        printf("%s\n",buf);
    }
    else 
    {
        printf("Invalid input\n");
    }
}

int main(void)
{
    printSum();
    return 0;
}
