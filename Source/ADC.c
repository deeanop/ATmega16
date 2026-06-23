#include <avr/io.h>
#define F_CPU 14745600UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
void adc_init(){
	DDRA &= ~(1 << PA0);
	DDRA &= ~(1 << PA1);
	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0);
}
uint16_t conversion_start(uint8_t channel){
	ADMUX=ADMUX | channel;
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));
	uint16_t result = ADCL;
	result |= (ADCH << 8);
	return result;
}