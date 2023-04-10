#include <stdio.h>

void printChar(char* msg);
int strlen(char* msg);

int main(){
    //char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    //char msg[] = "Hello!";
    printf("MAIN -> Greeting message: %s (%d)\n", greeting, strlen(greeting));//%s procura um \0 para parar
    printChar(greeting);
    return 0;
}
        //recebe o conteudo de greeting
void printChar(char* msg){
    int i = 0;
    printf("PRINT -> Greeting message: %s (%d)\n", msg, strlen(msg));
    while(*msg!='\0')
        printf("%c\n", *msg++);//ao chegar no \0 ele nao o printara por que nao eh visivel
}

int strlen(char* msg){
    int i = 0;
    while(*msg++!='\0')
        ++i;
    return i;    
}