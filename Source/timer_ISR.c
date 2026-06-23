# include <stdio.h>
# include <avr/interrupt.h>
# include <avr/io.h>
# include <util/delay.h>
# define F_CPU 14745600UL;
int x = 0b00000001;
int main(){
    DDRB = 0xFF;
    timer_init();
    sei();
    while(1){
    }
    return 0;
}
ISR(TIMER1_COMPA_vect){
    PORTB = PORTB | x;
    PORTB = PORTB & ~x;
    PORTB = PORTB ^ x;
}