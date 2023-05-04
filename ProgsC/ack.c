#include <stdio.h>
int ackermann(int m, int n) {
  		if (m == 0) {
      		return n+1;
 		}else if(m > 0 && n == 0) {
       		return ackermann(m-1, 1);
   		} else if(m > 0 && n > 0) {
       		return ackermann(m-1, ackermann(m, n-1));
   		}
}

int main(){
    int a, b;
    printf("Programa Ackermann\nDigite os parametros m e n para calcular A(m, n) ou -1 para abortar a execucao");
    scanf("%i %i",&a,&b);

    if(a < 0)
        return 0;
    printf("A(%d, %d) = %d", a , b , ackermann(a,b));

}

