#include <stdio.h>
void quadrado(); //prototipo diz que ela exite para a main

int main(){
    printf("ola mundo\n");
    

    printf("Informe dois valores: ");
    int v1, v2;
    scanf("%d %d", &v1, &v2);//igual ao Scanner do java
    printf("Os seguintes valores foram digitados: \n"); 

    //%d eh uma marcacao para inteiros

    printf("valor1: %d\n", v1);
    printf("valor2: %d\n", v2);

    quadrado();

    return 0;
}

void quadrado()//sem valor de retorno/parametros de entrada
{//corpo da funcao

    int k;
    for(k=1; k<=10; k++){
        printf("%d\n",k*k);
    }

}

