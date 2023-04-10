#include <stdio.h>

typedef struct {
    int numerador, denominador;
} Fracao;

int calculaPorValor(Fracao);
int calculaPorRefA(Fracao);
int calculaPorRefB(Fracao);

int main(int argc, char*argv[]){

}

int calculaPorValor(Fracao f){
    return f.numerador/f.denominador;
}

int calculaPorRefA(Fracao*f){
    return (*f).numerador/(*f).denominador;
}

int calculaPorRefB(Fracao*f){
    return f->numerador/f->denominador;
}

void dissecarEstrutura(Fracao *f){
    printf("Tamanho da *Fracao: %d\n", sizeof(f));
    printf("Tamanho da Fracao: %d\n", sizeof((*f)));

    printf("ptr int")
    int size = sizeof(*f);
    while(size){}
}