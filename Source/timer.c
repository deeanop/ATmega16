# include <stdio.h>
# include <avr/interrupt.h>
# include <avr/io.h>
# include <util/delay.h>
# include <stdint.h>
# define F_CPU 14745600UL;
int x = 0b00000001;
int main(){
    DDRB = 0xFF;
    timer_init();
    while(){
        if((TIFR & (1<<4)) ==0){
            PORTB = PORTB ^ x;
            TIFR |=(1<<4);
        }
    }
    return 0;
}