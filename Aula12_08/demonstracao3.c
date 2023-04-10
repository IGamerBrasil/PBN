#include <stdio.h>

int main(){
    int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* p = c;

    printf("*p:  %d\n", *p); //exibe o primeiro elemento do array
    printf("p[0]: %d\n", p[0]); 

    printf("p: %p\n", p); 
    printf("c: %p\n", c); 
    printf("&c[0]: %p\n", &c[0]); 

    printf("&p: %p\n", &p); 
    printf("&c: %d\n", &c); 

    printf("Acessando o vetor indice \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d: %d\n",i,c[i]);
    }
    
    printf("Acessando o vetor aritmetoca de ponteiro\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%p: %d\n",p+i,*(p+i));
    }
}