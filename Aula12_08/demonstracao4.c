#include <stdio.h>

int main(){
    int c[4] = {3, 2, 1, 4};
    int* p = c;

    for(int i =0; i<4; i++){
        //printf("(%d, %p)", *p++, p);
    //}
    //printf("\n");
    //for(int i =0; i<4; i++){
        //printf("%d",*(p+i));
        printf("%d, ", (*p)++);
    }

}