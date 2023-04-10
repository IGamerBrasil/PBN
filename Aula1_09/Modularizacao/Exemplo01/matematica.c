#include "matematica.h"

float somatorio(int v){
    int aux, sum; 
    do{
        sum = 0; //somatorio

        for(aux=1 ; aux<=v ; aux++)
            sum += aux;

    }while(v);
    return sum;
}

float fatorial(int v){
    int fat; //fatorial
    for(fat = 1; v > 1; v = v - 1)
        fat = fat * v;

    return fat;
}