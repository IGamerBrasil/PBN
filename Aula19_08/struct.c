#include <stdio.h>

struct{
    float p1, p2;
    float tf;
    int faltas;
} aluno1 = {.p1 = 10, .p2 = 10, .faltas = 0, .tf = 8.5}, 
  aluno2 = {.p1 = 10, .p2 = 10, 8.5, .faltas = 0};

int main(){

    printf("Aluno1: p1(%4.1f), p2(%4.1f), tf(%4.1f), faltas(%d)\n", aluno1.p1, aluno1.p2, aluno1.tf, aluno1.faltas);

    printf("Aluno2: p1(%4.1f), p2(%4.1f), tf(%4.1f), faltas(%d)\n", aluno2.p1, aluno2.p2, aluno2.tf, aluno2.faltas);

}