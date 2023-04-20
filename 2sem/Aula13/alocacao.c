#include <stdio.h>
#include <stdlib.h>
#define SIZE 2000000 // dois milhões
int main()
{
    /*
    
    double array[SIZE];
    printf("tam. mem: %zu\n", sizeof(double)*SIZE);
    for(int i=0; i<SIZE; i++)
        array[i] = i;
    NAO VAI FUNCIONAR PORQUE EH MAIOR QUE 8MB
    */

    // Aloca um array de 10 int
    //int* numbers = malloc(sizeof(int) * 10);
    // Faz o mesmo, e é considerado mais seguro
    //int* numbers = malloc(10 * sizeof *numbers);
    // Aloca e zera um array de 10 int
    //int* numbers = calloc(10, sizeof(*numbers));
    //int* newarray = realloc(numbers, 30);
    //garbage collector manual
    //free(numbers);

    double* array = malloc(sizeof *array * SIZE);
    printf("tam. mem: %zu\n", sizeof *array * SIZE);
    for(int i=0; i<SIZE; i++)
          array[i] = i;
    free(array);

}
