# define F_CPU 14745600UL
# include <avr/interrupt.h>
# include <avr/io.h>
# include <util/delay.h>

int main(){
	DDRB = 0xff;
	DDRD = 0x00;
	
	unsigned prev;
	unsigned curr;
	
	unsigned stable = 0;
	unsigned curr_stable;
	unsigned prev_stable;

	while(1){
		prev = curr;
		prev_stable = curr_stable;
		curr = (PIND & (1<<PD6)) ? 0 : 1;
		
		if(prev != curr) {
			stable = 0;
		}
		if(stable >= 1000) {
			curr_stable = curr;
		}
		if(curr_stable && !prev_stable) {
			PORTB ^= (1 << PB0);
		}
		if(stable < 1000) {
			stable ++;
		}
		_delay_us(10);
	}
	return 0;
}
