#include <stdio.h>
#include <string.h>
void print(char* msg);

int main(){
    //char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    //char msg[] = "Hello!";
    printf("MAIN -> Greeting message: %s (%d)\n", greeting, strlen(greeting));//%s procura um \0 para parar
    print(greeting);
    return 0;
}

void print(char* msg){
    printf("PRINT -> Greeting message: %s (%d)\n", msg, strlen(msg));
    for(int i = 0; i < 6; ++i)
        printf(" %d: %c (%d)\n", i, msg[i], msg[i]);//ao chegar no \0 ele nao o printara por que nao eh visivel
}