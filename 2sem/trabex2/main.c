#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "nokia5110.h"
#include <stdlib.h>
#include <stdio.h>

#define CREDIT_50 PD0
#define CREDIT_25 PD1
#define CREDIT_100 PD2
#define CONT_INIT PB0
#define VAL_MAX 1.50


void credit25(double *m, char s[]);
void credit50(double *m, char s[]);
void credit100(double *m, char s[]);

void timer_park(double *m, char stringTemp[]);

int t = 0;


void setRelogio() {
    TCCR1B |= (1 << WGM12);                 // Modo CTC
    OCR1A = 15624;                          // Valor 10 segundos (prescaler de 256)
    TIMSK1 |= (1 << OCIE1A);                // Ativa interrupção do Timer1 comparando com OCR1A
    TCCR1B |= (1 << CS12) | (1 << CS10);    // Prescaler de 1024
}

ISR(TIMER1_COMPA_vect) {
    if (t > 0) {
        t--;//diminuiu o tempo do timer
    }
}

uint8_t glyph[] = { 0b00010000, 0b00100100, 0b11100000, 0b00100100, 0b00010000 };

int main(void)
{

    DDRD &= ~(1<< CREDIT_50);
    DDRD &= ~(1<< CREDIT_25);
    DDRD &= ~(1<< CREDIT_100);
    DDRB &= ~(1<< CONT_INIT);

    double moeda = 0.0;
    char valorString[16];
    char stringTemp[16];
    nokia_lcd_init();
    nokia_lcd_clear();
    nokia_lcd_custom(1,glyph);
    nokia_lcd_write_string("0 REAIS",1);
    nokia_lcd_set_cursor(0, 12);
    nokia_lcd_write_string("INSIRA MOEDA\001", 1);
    nokia_lcd_render();
    while(1){
            if(PIND & (1 << CREDIT_100)){// LE PD0
                    //PORTC ^= (1 << PC2); //TOGGLE EM PB5 1 OU 0
                    //CONTROLE
                    credit100(&moeda, valorString);
                    while (PIND & (1 << CREDIT_100))
                        _delay_ms(1);//debounce  
                    _delay_ms(1);             
            }
            if(PIND & (1 << CREDIT_50)){// LE PD0
                    //PORTC ^= (1 << PC2); //TOGGLE EM PB5 1 OU 0
                    //CONTROLE
                    credit50(&moeda, valorString);
                    while (PIND & (1 << CREDIT_50))
                        _delay_ms(1);//debounce 
                    _delay_ms(1);             
            }
            if(PIND & (1 << CREDIT_25)){// LE PD0
                    //PORTC ^= (1 << PC2); //TOGGLE EM PB5 1 OU 0
                    //CONTROLE
                    credit25(&moeda, valorString);
                    while (PIND & (1 << CREDIT_25))
                        _delay_ms(1);//debounce  
                    _delay_ms(1);             
            }
            if(PINB & (1 << CONT_INIT)){// LE PD0
                    //PORTC ^= (1 << PC2); //TOGGLE EM PB5 1 OU 0
                    //CONTROLE
                    if(moeda == VAL_MAX){
                        nokia_lcd_clear();
                        timer_park(&moeda, stringTemp);
                    }
                    while (PINB & (1 << CONT_INIT))
                        _delay_ms(1);//debounce  
                    _delay_ms(1);             
            }
    }
}

void credit100(double *m, char s[]){
         nokia_lcd_init();
         nokia_lcd_clear();
         nokia_lcd_custom(1,glyph);
         if((*m+1) <= VAL_MAX || *m == VAL_MAX){
             *m+=1;
             dtostrf(*m,4,2, s);
             nokia_lcd_write_string("Quantia: ",1);
             nokia_lcd_write_string(s,1);
             nokia_lcd_set_cursor(0, 12);
             if(*m == VAL_MAX){
                nokia_lcd_write_string("QUANTIA MAXIMA!\001", 1);
             }else{
                 nokia_lcd_write_string("INSIRA MOEDA\001", 1);
             }  
         }else{
                dtostrf(*m,4,2, s);
                nokia_lcd_write_string("Quantia: ",1);
                nokia_lcd_write_string(s,1);
                nokia_lcd_set_cursor(0, 12);
                nokia_lcd_write_string("INSIRA MOEDA\001", 1);
         }
         nokia_lcd_render();  
}

void credit50(double *m, char s[]){
        nokia_lcd_init();
        nokia_lcd_clear();
        nokia_lcd_custom(1,glyph);
        if((*m+0.50) <= VAL_MAX || *m == VAL_MAX){
            *m+=0.50;
            dtostrf(*m,4,2, s);
            nokia_lcd_write_string("Quantia: ",1);
            nokia_lcd_write_string(s,1);
            nokia_lcd_set_cursor(0, 12);
            if(*m == VAL_MAX){
                nokia_lcd_write_string("QUANTIA MAXIMA!\001", 1);
            }else{
                nokia_lcd_write_string("INSIRA MOEDA\001", 1);
            }
        }else{
                dtostrf(*m,4,2, s);
                nokia_lcd_write_string("Quantia: ",1);
                nokia_lcd_write_string(s,1);
                nokia_lcd_set_cursor(0, 12);
                nokia_lcd_write_string("INSIRA MOEDA\001", 1);
        }
        nokia_lcd_render();  
}

void credit25(double *m, char s[]){
         
         nokia_lcd_init();
         nokia_lcd_clear();
         nokia_lcd_custom(1,glyph);
         if((*m+0.25) <= VAL_MAX || *m == VAL_MAX){
            *m+=0.25;
            dtostrf(*m,4,2, s);
            nokia_lcd_write_string("Quantia: ",1);
            nokia_lcd_write_string(s,1);
            nokia_lcd_set_cursor(0, 12);
            if(*m == VAL_MAX){
                nokia_lcd_write_string("QUANTIA MAXIMA!\001", 1);
            }else{
                nokia_lcd_write_string("INSIRA MOEDA\001", 1);
            }   
         }else{
            dtostrf(*m,4,2, s);
            nokia_lcd_write_string("Quantia: ",1);
            nokia_lcd_write_string(s,1);
            nokia_lcd_set_cursor(0, 12);
            nokia_lcd_write_string("INSIRA MOEDA\001", 1);
         }
         nokia_lcd_render();  
}

void timer_park(double *m, char stringTemp[]){
    nokia_lcd_init();
    nokia_lcd_clear();
    nokia_lcd_custom(1,glyph);
    
    setRelogio();
    sei();

    t = 10;

    while(t > 0){
        nokia_lcd_clear();
        sprintf(stringTemp, "Tempo: %d", t);
        nokia_lcd_write_string(stringTemp,1);
        nokia_lcd_set_cursor(0, 10);
        nokia_lcd_render();
    }

    cli();
    *m = 0.0;
    nokia_lcd_clear();
    nokia_lcd_write_string("0 REAIS",1);
    nokia_lcd_set_cursor(0, 12);
    nokia_lcd_write_string("INSIRA MOEDA\001", 1);
    nokia_lcd_render();
    
}