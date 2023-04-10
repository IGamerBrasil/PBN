#include <stdio.h>

int busca(int valorBuscado, int * vetor, int tamDoVet);

int main(){
    int vetor[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};


    int valor;
    printf("Informe o valor a ser procurado: ");
    scanf("%d", &valor);

    int pos = busca(valor, vetor, 19);

    if(pos==-1){
        printf("Valor %d nao foi encontrado na lista\n", valor);
    }else{
        printf("Valor %d esta na pos %d do vetor\n", valor, pos);
    }
}

int busca(int valorBuscado, int * vetor, int tamDoVet){
    /*
    for(int i = 0; i<tamDoVet; ++i){
          //incrementa a posicao
        if(*vetor++==valorBuscado){
            return i;
        }
    }
    return -1;
    */
   printf("Valor buscado: %d\n", valorBuscado);
   printf("Endereco do vetor: %p\n", vetor);
   printf("Tamanho do vetor: %d\n", tamDoVet);
   while(tamDoVet){
        if(*(vetor+tamDoVet)==valorBuscado){
            return tamDoVet;
        }
        tamDoVet--;
   }
   return -1;
}