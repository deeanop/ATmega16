# include <stdio.h>
# include <avr/interrupt.h>
# include <avr/io.h>
# include <util/delay.h>
# define F_CPU 14745600UL;
int x = 0b00000001;
ISR(TIMER1_COMPA_vect){
    flag = 1;
}
int main(){
    DDRB = 0xFF;
    timer_init();
    sei();
    while(1){
        if(flag){
            PORTB |= x;
            PORTB &= ~x;
            PORTB ^= x;
            flag = 0;
            }
    }
    return 0;
}
