/* Nokia 5110 LCD AVR Library example
 *
 * Copyright (C) 2015 Sergey Denisov.
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence
 * as published by the Free Software Foundation; either version 3
 * of the Licence, or (at your option) any later version.
 *
 * Original library written by SkewPL, http://skew.tk
 * Custom char code by Marcelo Cohen - 2021
 */

#include <avr/io.h>
#include <util/delay.h>

#include "nokia5110.h"

uint8_t glyph[] = { 0b00010000, 0b00100100, 0b11100000, 0b00100100, 0b00010000 };

int main(void)
{
    nokia_lcd_init();
    nokia_lcd_clear();
    nokia_lcd_custom(1,glyph);
    nokia_lcd_write_string("IT'S WORKING!",1);
    nokia_lcd_set_cursor(0, 12);
    nokia_lcd_write_string("Nice!\001", 2);
    nokia_lcd_render();

    for (;;) {
        _delay_ms(1000);
    }
}
