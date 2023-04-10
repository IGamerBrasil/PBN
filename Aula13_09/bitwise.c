#include "bitwise.h"
#include <stdio.h>

unsigned int clear(unsigned int val){
    unsigned int resultado;
    //objetivo, rapido, mas que nao faz uso dos recursos vistos
    resultado = 0;

    //and?
    resultado = val & 0;
    resultado = val & 0x00000000: //0x0 -> 0b0000 , 0x00 -> 0b00000000 = 1 byte
    resultado = val & 0b000000000000000000000000; //4 bytes

    //or?
    //nao tem como puxar os bit pra 0 apenas pra 1 com uma operacao
    resultado = ~(val | 0xFFFFFFFF); //puxa pra zero porem com mais de uma op

    //xor?
    resultado = val ^ val;
    resultado = ~(val ^ ~val);

    //deslocamento a direita
    resultado = val >> 32;
    resultado = val >> sizeof(val)*8;

    //deslocamento a esquerda
    resultado = val << 32;
    resultado = val << sizeof(val)*8;
    
    return resultado;
}

//setbit
// x -> valor a ser modificado
// bit -> posicao do bit valor x a ser posto em 1
unsigned int setbit(unsigned int x, int bit){
    unsigned int resultado;
    unsigned mask = (1 << bit);

    resultado = x | mask;

    return resultado;
}

//resetbit
// x -> valor a ser modificado
// bit -> posicao do bit valor x a ser posto em 0
unsigned int resetBit(unsigned int x, int bit){
    return (x & ~(1 << bit));
}

//inverte o bit
unsigned int invertBit(unsigned int x, int bit){
    if(testBit(x, bit)==1){
        //arrasta o bit para 0
        resetBit(x, bit);
    }
    else{
        //arrasta o bit para 1
        setbit(x, bit);
    }
}

unsigned int testBit(unsigned int x, int bit){
    /*
    unsigned int mask = 0x1 << bit;
    unsigned int resultado = mask & x;

    if(resultado)
        return 1;
    else 
        return 0;
    */
   return (x & (0x1 << bit)) >> bit // poem a mascara no valor e deslocado bits pra direita, assim vendo se eh 0 ou 1
}