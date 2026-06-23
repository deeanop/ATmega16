//polling method
# define F_CPU 14745600UL
# include <avr/interrupt.h>
# include <avr/io.h>
void timer_init(){
	unsigned int value = 0x5A00;
	OCR1AH = (value>>8) & 0xFF;
	OCR1AL = (value & 0xFF);
}
int main(){
	DDRB = 0xff;
	int x = 0b00000001;
	timer_init();
	while(1){
		if((TIFR & (1<<4))==0){
				PORTB = PORTB | x;
				PORTB = PORTB & ~x;
				PORTB = PORTB ^ x;
		}
	}
	return 0;
}

