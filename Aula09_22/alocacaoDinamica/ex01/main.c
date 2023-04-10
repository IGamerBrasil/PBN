#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]){

    int *nums;
    int tam = 10;

    printf("szof size_t: %d", sizeof(size_t));
    printf("szof *nums: %d", sizeof(*nums));    
    printf("szof nums: %d", sizeof(nums));
    /*
    //melhor e mais flexivel que por sizeof(int)
    nums = malloc(tam * sizeof *nums);

    for(int i = 0; i < tam, i++){
        printf("[%02d]: %d",i,nums[i]);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                       //tamanho da unidade alocado na memoria ex: char 1byte 
    nums = calloc(tam, sizeof(*nums));
    for(int i = 0; i < tam, i++){
        printf("[%02d]: %d",i,nums[i]);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    */
    int limpo=1;
    int count = 1;
    do{
        printf("Alocacao %d\n",count++);
        //cria vetor de 1 milhao de espaços
        nums = malloc(tam * sizeof *nums);
        for(int i = 0; i<tam;i++){
            if(nums[i]=0){
                limpo=0;
            }
            nums[i]^=nums[i];
        }
        if(limpo == 0){
            for(int i = 0; i < tam; i++){
                printf("[%02d]: %d\n",i,nums[i]);
            }
        }
        //limpa
        free(nums);
    }while(limpo);
    return 0;
}