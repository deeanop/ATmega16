# include <stdio.h>
# include <avr/interrupt.h>
# include <avr/io.h>
# include <util/delay.h>
# include "timer.h"
# define F_CPU 14745600UL
void timer_init(){
    int t = 0.5;
    int N = F_CPU * N;
    int F = F_CPU/64;
    TIMSK = TIMSK | (1<<4);
    OCR1AH = (F<<8) & 0xFF;
    OCRIAL = F & 0xFF;
    TCCR1A = 0x00;
    TCCR1B = TCCR1B | 0b00001011
}