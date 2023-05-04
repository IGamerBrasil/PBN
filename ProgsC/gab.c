#include <stdio.h>
int ackermann(int a, int b);
int main(int argc, char const *argv[])
{
    int a, b;
    printf("Programa Ackermann\nDigite os parametros m e n para calcular A(m, n) ou -1 para abortar a execucao");
    scanf("%i %i",&a,&b);
    if(a < 0)
        return 0;
    printf("A(%d, %d) = %d", a , b , ackermann(a,b));
    return 0;
}


int ackermann(int m, int n){
    //se primeiro parâmetro for igual a 0 retorna o segundo parâmetro - 1
    if(m == 0)
        return n+1;
    //se o primeiro parâmetro for maior que 0 e o segundo igual a 0, a função é chamada novamente com m - 1 como primeiro parametro e 1 como segundo
    if(m > 0 && n == 0)
        ackermann(m - 1,1);
    //se primeiro e segundo parâmetro forem maiores que 0, é chamada a função duas vezes
    if(m > 0 && n > 0)
        ackermann(m-1 , ackermann(m,n-1));
}