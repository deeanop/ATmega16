/*****************************************************************************
 * lab4_1.c
 *****************************************************************************/

#include <sys/platform.h>
#include "adi_initialize.h"
#include "lab2.h"
#include <cdefbf537.h> // register definitions for BF537
#include <sys/exception.h> // definitions for the interrupt system
#define F_CPU 50000000

/** 
 * If you want to use command program arguments, then place them in the following string. 
 */
char __argv_string[] = "";

void led_init(){
	*pPORTFIO_DIR|=(1<<6)|(1<<7)|(1<<8)|(1<<9)|(1<<10)|(1<<11);
}
void timer_init(){
	*pTIMER7_CONFIG|= 1|(1<<3)|(1<<4);
	*pTIMER7_PERIOD = 25000000;
	*pTIMER_ENABLE|=(1<<7);

}
void led_toggle(){
	*pPORTFIO_TOGGLE|=(1<<6);
}
int main(int argc, char *argv[])
{
	adi_initComponents();
	led_init();
	timer_init();
	while(1){
		if((*pTIMER_STATUS & (1<<19))!=0){
			led_toggle();
			*pTIMER_STATUS |=(1<<19);
		}
	}
	return 0;
}

