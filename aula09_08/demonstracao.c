#include <stdio.h>

int main(){
    int b=200;
    printf("&b: %p\n", &b);
    printf("b: %d\n", b);

    int* a;

    a = &b;
    printf("Endereco de a: %p \n", &a);
    printf("Valor de a: %p \n", a);
    printf("Conteudo apontado por a: %d \n", *a);

    int* c;//o que tem dentro do endereco eh o que tinha antes

    printf("Endereco de a: %p \n", &c);
    printf("Valor de a: %p \n", c);
    printf("Conteudo apontado por a: %d \n", *c);

    c=0;
    printf("Endereco de a: %p \n", &c);
    printf("Valor de a: %p \n", c);
    printf("Conteudo apontado por a: %d \n", *c);

}