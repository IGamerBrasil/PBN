#include <stdio.h>

int main(int argc, char const* argv[]){
    unsigned int var = -1;
    unsigned char c;

    printf("var = %d\n",var);

    if(var>=0){
        printf("Var eh zero ou positivo\n");
    }else{printf("Eh negativo\n");}


    c = 0b10000001;

    printf("var inteiro: %d\n", c);
    printf("var sem sinal: %u\n", (c & 0x0ff));
    printf("var char: %c\n", c);

    return 0;
}