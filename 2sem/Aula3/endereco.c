#include <stdio.h>
int main()
{
    int b = 200;
    int* a = &b; // a armazenará o endereço de b

    printf("Valor de b: %d\n", b);
    printf("End. de b: %p\n", &b);
    printf("Valor de a: %d\n", a);
    printf("End. de a: %p\n", &a);
    printf("Conteúdo apontado por a: %d\n", *a);

    b = 100;

    printf("Valor de b: %d\n", b);
    printf("End. de b: %p\n", &b);
    printf("Valor de a: %d\n", a);
    printf("End. de a: %p\n", &a);
    printf("Conteúdo apontado por a: %d\n", *a);

    b = 400;

    printf("Valor de b: %d\n", b);
    printf("End. de b: %p\n", &b);
    printf("Valor de a: %d\n", a);
    printf("End. de a: %p\n", &a);
    printf("Conteúdo apontado por a: %d\n", *a);

    //conteudo do endereco de a
    *a = 300;

    printf("Valor de b: %d\n", b);
    printf("End. de b: %p\n", &b);
    printf("Valor de a: %d\n", a);
    printf("End. de a: %p\n", &a);
    printf("Conteúdo apontado por a: %d\n", *a);

    while(b>0){
        b--;
        printf("%p - %c\n", a, *a);
        a++;
    }
}