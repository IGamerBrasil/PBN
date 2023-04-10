#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]){

    int *nums;
    int tam = 10;
    int * ponteiro;

    printf("szof size_t: %d", sizeof(size_t));
    printf("szof *nums: %d", sizeof(*nums));    
    printf("szof nums: %d", sizeof(nums));

    //melhor e mais flexivel que por sizeof(int)
    nums = malloc(tam * sizeof *nums);
                       //tamanho da unidade alocado na memoria ex: char 1byte 
    ponteiro = realloc(nums, 2*tam*sizeof(*nums));
    for(int i = 0; i < tam; i++){
        nums[i]=i;
    }
    for(int i = 0; i<tam*2; i++){
        printf("[%02d]: %02d",i,ponteiro[i]);
        if(i<10){
            printf("  [%02d]: %02d",i,nums[i]);
        }
        printf("\n");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for(int i = 0; i < tam*2; i++){
        ponteiro[i]++;
    }
    for(int i = 0; i<tam*2; i++){
        printf("[%02d]: %02d",i,ponteiro[i]);
        if(i<10){
            printf("  [%02d]: %02d",i,nums[i]);
        }
        printf("\n");
    }
    return 0;
}