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
	char sL[100], sR[100];
	USART_Init();
	adc_init();
	
	while (1)
	{
		uint16_t adc_value_L = conversion_start(0);
		double voltageL = (double)(((double)(adc_value_L * 5)) / 1023);
		uint16_t intregL =floor(voltageL) ;
		double auxL = voltageL - intregL ;
		int percentL = ((uint32_t)adc_value_L * 100)/1023;
		auxL= auxL *100000;
		uint16_t zecimalL = floor(auxL);
		char xL = '%';
		sprintf(sL, "ADC = %u %u.%u %d%c\r\n", adc_value_L,intregL,zecimalL,percentL,xL);
		uint16_t adc_value_R = conversion_start(1);
		double voltageR = (double)(((double)(adc_value_R * 5)) / 1023);
		uint16_t intregR =floor(voltageR) ;
		double auxR = voltageR - intregR ;
		int percentR = ((uint32_t)adc_value_R * 100)/1023;
		auxR= auxR *100000;
		uint16_t zecimalR = floor(auxR);
		char xR = '%';
		sprintf(sR, "ADC = %u %u.%u %d%c | %s\r\n", adc_value_R,intregR,zecimalR,percentR,xR,sL);
		USART_Transmit_String(sR);
		_delay_ms(1000);
	}
}
