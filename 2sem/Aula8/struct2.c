#include <stdio.h>
//simple struct, without typedef part1 is a variable, used for little things
struct{
    int number;
    char name[101];
    int on_hand;
} part1 = {514, "Disk Drive", 10},
  part2 = {142, "Printer Cable", 5};

//you can create more then one struct in C
struct {
    char name[101];
    int number;
    char sex;
} employee1, employee2;

//other types of struct
typedef struct{
    char apelido[10];
    float peso;
    char sexo;
    int idade;
}Formulario;

struct formula{
    char comp[100];
    int id;
};

void printFormulario(Formulario f);

int main(){
    Formulario f1 = {"Xovem", .sexo = 'M'};
    struct formula f2;
    printf("O struct Formulario tem tamanho de %d\n", sizeof(f1));
    printFormulario(f1);

    char * ch = (char*) &f1;
    for (int i = 0; i < sizeof(f1); i++){
                        // char/ASCII
        printf("%p: [%d] -> %c/%d\n", ch,i,*ch,*ch);
        ++ch;
    }
    
}

void printFormulario(Formulario f){
    printf("O conteudo do formulario eh:\n");
    printf("apelido: %s\n", f.apelido);
    printf("Sexo: %c\n", f.sexo);
    printf("Peso: %.2f\n", f.peso);
    printf("Idade: %d\n\n", f.idade);
}