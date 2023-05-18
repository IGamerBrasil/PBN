#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//define setas indicadoras de umidade

#define N1 PB1
#define N2 PB2
#define N3 PB3
#define N4 PB4
#define ON 1
#define OFF 0
#define tempPisca 500
#define paraIrriga 5000

void irrigaGramado(int Tirriga, int umidade);
void picarLeds(int umidade);
void campoSemIrrigacao(int Tirriga, int umidade);

int main(void)  {


    DDRB |= (1<<N1);
    DDRB |= (1<<N2);
    DDRB |= (1<<N3);
    DDRB |= (1<<N4);

    int nivUmidade = 0;
    int valorIrriga;
    int valorBotao;
    int Tirriga = 0;

    // enquanto botao ativo

    while(1)    {
        _delay_ms(1);
        if(!valorBotao){
            if (PINB & (1<<PB0))    { //se botao ativo
                valorBotao = ON;
                valorIrriga = ON;
                while (PINB & (1 << PB0)); 
            }
        }
    
        switch (valorIrriga){
                    case ON: //umidade 0
                        Tirriga++;
                        if(PINB & (1<<PB0)){
                            valorIrriga = OFF;
                            Tirriga = 0; 
                        }
                        else{
                            if(umidade >= 4)
                                valorIrriga = OFF;
                                Tirriga = 0;
                            else
                                irrigaGramado(Tirriga, nivUmidade);
                        }
                        
                        break;
                    default:
                        Tirriga++;
                        if(PINB & (1<<PB0)){
                            valorIrriga = ON;
                            Tirriga = 0; 
                        } 
                        else{
                            campoSemIrrigacao(Tirriga, nivUmidade);
                        }
                        break; 
        }
    }   

}

void irrigaGramado(int Tirriga, int umidade){
    int inverteLed = Tirriga%tempPisca;
    if(inverteLed == 0)
        picarLeds(umidade);
    int Tumidade = Tirriga%3000;
    if((Tumidade==0)&&(umidade<4))
        umidade++;
    switch (umidade)
    {
    case 1:
        PORTB = (1 << N1);
        break;
    
    default:
        break;
    }
}

void campoSemIrrigacao(int Tirriga, int umidade){
    //contabilizar tempo
    int tempo=Tirriga%paraIrriga;
    //atualizar nivel
    if(tempo==0)&&(umidade >= 1){ // chegou o momento de atualizar o nivel
        //atuar nos leds
        switch (umidade)
        {
           case 1:
               PORTB &= ~(1 << N1);
               break;
           case 2:
               PORTB &= ~(1 << N2);
               break;
           case 3:
               PORTB &= ~(1 << N3);
               break;
           default:
               PORTB &= ~(1 << N3);
               break;
        }
        //diminui o nivel de umidade
        umidade--;
        
    }
}

void picarLeds(int nivUmidade){
    switch(nivUmidade){
        case 0:
            PORTB ^= (1 << N1);
            PORTB ^= (1 << N2);
            PORTB ^= (1 << N3);
            PORTB ^= (1 << N4);
            break;
        case 1:
            PORTB ^= (1 << N2);
            PORTB ^= (1 << N3);
            PORTB ^= (1 << N4);
            break;
        case 2:
            PORTB ^= (1 << N3);
            PORTB ^= (1 << N4);
            break;
        case 3:
            PORTB ^= (1 << N4);
            break;
        default:
            break;   
    }
}

