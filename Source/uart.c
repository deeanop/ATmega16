/*
 * GccApplication16.c
 *
 * Created: 5/22/2025 11:10:35 AM
 * Author : dspuser
 */ 

#include <avr/io.h>
#define F_CPU 14745600UL
#include <util/delay.h>
#include <stdio.h>

int main(void)
{
    DDRD |= (1<<PD1);
	DDRD &= ~(1<<PD0);
	UCSRC &= ~(1<<URSEL);
	UBRRH = (51>>8) & 0xFF;
	UBRRL = (51 & 0xFF);
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	UCSRC |= (1<<URSEL);
	UCSRC |= (1<<UCSZ1) | (1<<UCSZ0);
    while (1) 
    {
		if((UCSRA & (1<<5))==1){
			UDR = 'A';
			_delay_ms(1000);
		}
    }
}

