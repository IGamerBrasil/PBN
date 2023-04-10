#include <stdio.h>

typedef union
{
    char caracter[4];
    int vet[2];
    double frac;
}algo;

void printAlgo(algo a);

void main(){

    algo u1;

    u1.frac = 2.5;
    printAlgo(u1);
    
    u1.caracter[0] = 'x';
    printAlgo(u1);

}

void printAlgo(algo a){
    printf("o tamanho eh %d",sizeof(a));
}