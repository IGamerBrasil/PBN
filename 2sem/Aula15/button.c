#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void){

    DDRB |= (1<<PB5);       // SETA PB5 COMO SAIDA
    DDRB &= ~(1<<PB0);      // SETA PB0 COMO ENTRADA

    while(1){
        //ACAO
        if(PINB & (1 << PB0)){// LE PB0
            PORTB ^= (1 << PB5); //TOGGLE EM PB5 1 OU 0
            //CONTROLE
            while (PINB & (1 << PB0))
                _delay_ms(1);//debounce             
        }
        /*
        BLOQUEANTE
        while(1)
            while(!alguem)
                wait(1)

        PULLING
        while(1)
            trata relogio()
            trata humidade()
            if(alguem)
             trata pesagem()
        */
    }

}