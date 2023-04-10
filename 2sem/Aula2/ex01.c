#include <stdio.h>

void moedas(int* dinheiro, int* c100, int* c50, int* c10, int* c05, int* c01);

int main(){
    int money = 1000;

    int cedula_100, cedula_50, cedula_10, cedula_05, cedula_01;

    moedas(&money, &cedula_100, &cedula_50, &cedula_10, &cedula_05, &cedula_01);

    printf("C100 = %d C50 = %d C10 = %d C05 = %d C01 = %d", cedula_100, cedula_50, cedula_10, cedula_05, cedula_01);

}

void moedas(int* dinheiro, int* c100, int* c50, int* c10, int* c05, int* c01){

    int aux;
    int v = dinheiro;
    aux = v/100;
    *c100 = aux;

    aux = v-(*c100*100)/50;
    *c50 = aux;

    aux = v -((*c100*100)+(*c50*50))/10;
    *c10 = aux;

    aux = v - ((*c100*100)+(*c50*50)+(*c10*10))/5;
    *c05 = aux;

    aux = v - ((*c100*100)+(*c50*50)+(*c10*10)+(*c05*5));
    *c01 = aux;

}
