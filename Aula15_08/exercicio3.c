#include <stdio.h>

typedef struct
{
    double p1, p2, media;
} Aluno;

double media(Aluno);

int main(){

    int nro = 5;

    Aluno alunos[nro];
    

    Aluno aluno1;
    aluno1.p1 = 7.5;
    aluno1.p2 = 8.9;
    media(aluno1);
    

    Aluno aluno2;
    aluno2.p1 = 7.5;
    aluno2.p2 = 8.9;
    media(aluno2);

    Aluno aluno3;
    aluno1.p1 = 7.5;
    aluno1.p2 = 8.9;
    media(aluno3);

    Aluno aluno4;
    aluno1.p1 = 7.5;
    aluno1.p2 = 8.9;
    media(aluno4);

    Aluno aluno5;

    aluno1.p1 = 7.5;
    aluno1.p2 = 8.9;
    media(aluno5);

    

}

double media(Aluno a){
    a.media = (a.p1+a.p2)/2; 
    return a.media;
}