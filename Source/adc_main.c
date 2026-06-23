#include <avr/io.h>
#define F_CPU 14745600UL
#include <util/delay.h>
#include "USART.h"
#include "ADC.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
int main(void)
{
	char s[100];
	USART_Init();
	adc_init();
	
	while (1)
	{
		uint16_t adc_value = conversion_start();
		double voltage = (double)(((double)(adc_value * 5)) / 1023);
		uint16_t intreg =floor(voltage) ;
		double aux = voltage - intreg ;
		aux= aux *100000;
		uint16_t zecimal = floor(aux);
		
		sprintf(s, "ADC = %u %u.%u\r\n", adc_value,intreg,zecimal);
		USART_Transmit_String(s);
		_delay_ms(1000);
	}
}