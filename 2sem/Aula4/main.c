#include <stdio.h>
int main()
{
    int a = 200;
    int* b = NULL;
    if(b != NULL)
        printf("Conteúdo apontado por b: %d\n", *b); // b é válido
    else
        printf("Ponteiro inválido!\n");
}