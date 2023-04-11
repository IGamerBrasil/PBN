#include <stdio.h>

int main() {
  printf("sizeof(int)    = %d\n", sizeof (int));
  printf("sizeof(char)   = %d\n", sizeof(char));
  printf("sizeof(float)  = %d\n", sizeof(float));
  printf("sizeof(double) = %d\n", sizeof(double));

  //Em Hexa

  printf("sizeof(int)    = 0x%02X\n", sizeof (int));
  printf("sizeof(char)   = 0x%02X\n", sizeof(char));
  printf("sizeof(float)  = 0x%02X\n", sizeof(float));
  printf("sizeof(double) = 0x%02X\n", sizeof(double));

  int varS = -1;
  unsigned int var = -1;

  printf("Valor var com sinal = %d\n",varS);
  printf("Valor var sem sinal = %d\n",var);
}
