#include <stdio.h>
#include <string.h>

int main() {
    char* text = "Prog. Sofware Basico";
    int v[] = { 0, 1, 2, 3, 4 };
    int matriz[4][4] = {
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15
    };

    char *ptr;

    for(int i = 0; i < 256; i++){
        printf("%d: %c\n", i, i);
    }
    printf("\n");

    //consumindo o vetor de caracteres
    ptr = text;
    for(int i = 0; i < strlen(text); i++){
        printf("%c; ", *ptr++);
    }
    printf("\n");

    //consumindo o vetor de inteiros
    ptr = (char*) v;
    for(int i = 0; i < sizeof(int)*5; i++){
        printf("%c; ", '0'+*ptr++);
    }
    printf("\n\n");

    //consumindo o vetor de matriz
    ptr = (char*) matriz;
    for(int i = 0; i < sizeof(int)*4*4; i++){
        printf("%c; ", '0'+*ptr++);
        if((i+1)%4==0)
            printf("\n");
    }

    char a = 122;
    int b = 122;
    float c = 122;
    double d = 122;
    long e = 122;

    ptr=&a;
    printf("%c -> ", a);
    for(int bit=7; bit>=0; bit--){
        printf("%c", '0'+((*ptr++)>>bit)&0x01);
    }
    printf("\n");

    printf("%d -> ", b);
    for(int i=sizeof(int); i < d; i++){
        ptr = (char*) &b+i;
        for (int bit = 7; bit>=0; bit--)
            printf("%c", '0'+((*ptr++)>>bit)&0x01);
    }
    printf("\n");
}