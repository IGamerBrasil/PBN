#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void){
    DDRB |= (1 << PB5); //seta PB0 como saida
    DDRB &= ~(1<<PB0); //zera o pino PB0 do DDRB, definido como entrada
    while(1){
        if(PB0 != 0){
            if(((PINB)&(1<<PB0))!=0){
                PORTB |= (1 << PB5); //liga LED
            }
            else{
                PORTB &= ~(1 << PB5); //desliga LED
            }
        }
        _delay_ms(10);
    }
}