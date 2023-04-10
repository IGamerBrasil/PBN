#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "Aluno.h"

int main(int argc, char const *argv[]){
    if(argc != 2){
        printf("Falta informar o numero de alunos");
        printf("Exemplo 0: O comando abaixo cria uma lista de 10 alunos");
        printf("    %s  10\n", argv[0]);
        return 0;
    }

    //rotina principal
    int nAlunos = atoi(argv[1]);
    Aluno listaDeAlunos[nAlunos];
    srand(time(NULL));

    for (int i = 0; i < nAlunos; i++)
    {
        listaDeAlunos[i].p1 = (rand()%10)+1;
        listaDeAlunos[i].p2 = (rand()%10)+1;
        listaDeAlunos[i].tf = (rand()%10)+1;
        listaDeAlunos[i].media = (rand()%10)+1;
    }
    
    listaAlunos(listaDeAlunos, nAlunos);
}

void listaAlunos(Aluno* lista, int qtde){
    for (int pos = 0; pos < qtde; pos++)
    {
        printf("Aluno%02d: P1(%04.1f), P2(%04.1f), TF(%04.1f), MEDIA(%04.1f)\n", pos, lista[pos].p1, lista[pos].p2,
                                                                                 lista[pos].tf, lista[pos].media);
    }
}

void calculaMedia(Aluno* lista, int qtde){
    while(qtde--){
        lista->media=(lista->p1+lista->p2+lista->tf)/3; //*lista.p1 mesma coisa que lista->p1
        lista++;                                     //soma 1 no endereco que lista referencia Ex: lista = 1000 -> 1256 porque o struct ocupa 256 bits
    }
}