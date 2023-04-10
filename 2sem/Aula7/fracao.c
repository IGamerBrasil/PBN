#include <stdio.h>

//Definição de tipo se declara antes de ser utilizado
typedef struct{
    float numerador;
    float denominador;
}Fracao;

float calcula(Fracao* frac);

int main(){
    Fracao f1;
    f1.numerador = 1;
    f1.denominador = 4;

    printf("Valor: %.2f", calcula(&f1));
}

float calcula(Fracao* frac){
    //forma melhor que (frac*).num...
    return frac->numerador / frac->denominador;
}