#include <stdio.h>

int main(){
    char c[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char* p = c;

    printf("*p:  %c\n", *p); //exibe o primeiro elemento do array
    printf("p[0]: %c\n", p[0]); 

    printf("p: %p\n", p); 
    printf("c: %p\n", c); 
    printf("&c[0]: %p\n", &c[0]); 

    printf("&p: %p\n", &p); 
    printf("&c: %c\n", &c); 

    printf("Acessando o vetor indice \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d: %c\n",i,c[i]);
    }
    
    printf("Acessando o vetor aritmetoca de ponteiro");
    for (int i = 0; i < 10; i++)
    {
        printf("%p: %c\n",p+(sizeof(char))*i,*(p+i));
    }
}