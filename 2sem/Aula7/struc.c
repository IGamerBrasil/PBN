#include <stdio.h>

//Definição de tipo se declara antes de ser utilizado
typedef struct{
    float p1;
    float p2;
    float trab;
    int faltas;
}Aluno;

void print(Aluno* a);

void esculhemba(Aluno* a);

int main(){
    Aluno aluno1, aluno2;

    aluno1.p1 = 10;
    aluno1.p2 = 7.5;
    aluno1.trab = 8;
    aluno1.faltas = 0;

    aluno2.p1 = 9;
    aluno2.p2 = 8.5;
    aluno2.trab = 9;
    aluno2.faltas = 0;

    //inf. de uma struct da para transferir suas inf. para outra struct do mesmo tipo
    //aluno2 = aluno1;
    print(&aluno1);

    print(&aluno2);

    esculhemba(&aluno1);
    esculhemba(&aluno2);

    print(&aluno1);

    print(&aluno2);

}

void print(Aluno* a){
    printf("Informacoes sobre o aluno:\n\n");
    printf(" P1 = %.2f\n",a->p1);
    printf(" P2 = %.2f\n", a->p2);
    printf(" TRAB = %.2f\n", a->trab);
    printf(" FALTAS = %d\n", a->faltas);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
}

void esculhemba(Aluno* a){
    a->p1/=2;
    a->p2/=2;
    a->trab/=2;
}