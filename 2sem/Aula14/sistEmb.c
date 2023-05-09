#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main (void) 
{
  DDRB |= (1 << PB5); // define GPIO PB5 como saída 

  int periodo = 1000;
  int perSec = periodo/4;

  while(1)
  {
    PORTB |= 1 << PB5;     // liga o led, pode modificar o pino apenas pondo em um reg PORT
    _delay_ms(perSec);
    PORTB &= ~(1 << PB5);  // desliga o led
    _delay_ms(perSec);
  }
}