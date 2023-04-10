#include <stdio.h>

int multiplica(int x){//passagem por valor
    x*=x;
    return x;
}

int main(){
    int t = 10; //variavel declarada localmente
    printf("%d - %d\n", multiplica(t), t);
    //saida 100 10
}