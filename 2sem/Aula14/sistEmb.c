#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define ON 1
#define OFF 0

void ledLight(int valor, int pos){
  if(valor == OFF){
    PORTB &= ~(1 << pos);  // desliga o led
  }
  else
    PORTB |= 1 << pos;     // liga o led, pode modificar o pino apenas pondo em um reg PORT
}

int main (void) 
{
  DDRB |= (1 << PB5); // define GPIO PB5 como saída 

  int periodo = 1000;
  int perSec = periodo/4;
  int status = OFF;
  ledLight(OFF, PB5); //comeca em 0

  int estado = 0; //no estado

  int countTime = 0;

  

  while(1)
  {

    _delay_ms(1);
    ++countTime;
    if(estado == 0){
      //acao
      ledLight(OFF, PB5);
      /*
       if(countTime >= perSec){ //momento de mudar o status do led
        status = (status==OFF?ON:OFF);
        ledLight(status, PB5);
        countTime = 0;
      */

      //mudanca de estado

      if(countTime >= periodo*2){//a cada 2 seg muda o estado
        estado = 1;
        countTime = 0;
      }

    }else{
      ledLight(ON,PB5);
      if(countTime >= periodo){
        estado = 0;
        countTime = 0;
      }
    }
  }
}
  
  
