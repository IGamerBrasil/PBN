#include <stdio.h>
            //armazena o endereco para o valor
void multiplica(int* x){//passagem por referencia
    *x *= *x;
}

int main(){
    int t = 10; //variavel declarada localmente
    multiplica(&t);//pega o endereço de t, se nao por & ele vai pegar um valor no endereco 10
    printf("%d - %d\n", t);
    //saida 100 10
}