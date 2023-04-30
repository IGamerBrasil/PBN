#include <stdio.h>
#include <stdlib.h>

char** matrix(int l, int c);

int main(int argc, char** argv){

    char** matriz = matrix(5, 5);
    int count = 0;
    int j, i;

    while (count < 5) {
      i = rand() % 5; // Gera um número aleatório entre 0 e 4 para a linha
      j = rand() % 5; // Gera um número aleatório entre 0 e 4 para a coluna

      if (matriz[i][j] != '.') { // Verifica se a posição não foi preenchida antes
         matriz[i][j] = '.'; // Preenche a posição com o caractere '.'
         count++; // Incrementa o contador de posições preenchidas
      }
   }
    

    return 0;
}

char** matrix(int l, int c){
    char** matriz = malloc(l * sizeof *matriz);

    for(int i=0; i<c; i++)
        matriz[i] = malloc(c * sizeof *matriz);

    for(int i=0; i<l; i++)
        for (int j = 0; i < c; i++)
            matriz[i][j] = ' ';
        

}