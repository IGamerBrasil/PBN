#include <stdio.h>
#include "ex01.h"

int main(int argc, char* agrv[]){
    int escolha;
    int valor;
    int bit;

    menu(&escolha);
    while(escolha){
        switch (escolha){
            case 1:            
                printf("Informe o valor a ser \"limpo\":");
                scanf("%d",&valor);
                //imprime decimal
                printf(" O valor base10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                //aplica funcao
                valor = clear(valor);
                //imprime decimal
                printf(" O valor base10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                break;
            case 2 :
                printf("Informe o valor a ser \"setado\":");
                scanf("%d",&valor);
                printf("Informe o bit a ser \"setado\":");
                scanf("%d",&bit);
                //imprime decimal
                printf(" O valor base10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                //aplica funcao
                valor = setbit(valor,bit);
                //imprime decimal
                printf(" O valor base10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                break;
            case 3:
                printf("Informe o valor a ser \"resetado\":");
                scanf("%d",&valor);
                printf("Informe o bit a ser \"resetado\":");
                scanf("%d",&bit);
                //imprime decimal
                printf(" O valor base10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                //aplica funcao
                valor = clearbit(valor,bit);
                //imprime decimal
                printf(" O valor base10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                break;
            case 4:
                printf("Informe o valor a ser \"modificado\":");
                scanf("%d",&valor);
                printf("Informe o bit a ser \"invertido\":");
                scanf("%d",&bit);
                //imprime decimal
                printf(" O valor base10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                //aplica funcao
                valor = invertbit(valor,bit);
                //imprime decimal
                printf(" O valor base10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                break;
            case 5:
                 printf("Informe o valor a ser \"testado\":");
                scanf("%d",&valor);
                printf("Informe o bit a ser \"testado\":");
                scanf("%d",&bit);
                //imprime decimal
                printf(" O valor bas10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                //aplica funcao
                valor = testbit(valor,bit);
                //imprime decimal
                printf(" O valor base10: %d\n",valor);
                //imprime binario
                printBinario(valor);
                break;
            default:
                break;
        }
        menu(&escolha);
    }
}

void menu(int* opcao){
    printf("Escolha uma das opcoes:\n ");
    printf("[1] - clear\n ");
    printf("[2] - setBit\n ");
    printf("[3] - clearBit\n ");
    printf("[4] - invertBit\n ");
    printf("[5] - testBit\n ");
    scanf("%d",opcao);
}

unsigned int clear(unsigned int val){
    return val ^ val;
}

unsigned int setbit(unsigned int x, int bit){
    int defPos = (1<<bit); //pega o bit
    int res = x | defPos;
    return res; 
}

unsigned int clearbit(unsigned int x, int bit){
    int defPos = (1<<bit); //pega o bit
    int res = x & ~defPos;
    return res;
}

unsigned int invertbit(unsigned int x, int bit){
    int defPos = (1<<bit); //pega o bit
    int res;
    if(x & defPos)//se 0 - false se 1 - true
        res = x & ~defPos;
    else
        res = x | defPos;
    return res;
}

int testbit(unsigned int x, int bit){
    int defPos = (1<<bit); //pega o bit
    int res = (x & defPos)>>bit;//verifica se eh 1 ou 0
    return res;
}

void printBinario(unsigned int val){
    int index=(sizeof(val)*8)-1;//numero de bit -1

    while(index >= 0){
        int bit = val & (1<<index); //0001 = 1 e bit = 1010
        --index;                    //                 1000 = 1000
        printf("%d",(bit==0)?0:1);
    }
    printf("\n");

}
