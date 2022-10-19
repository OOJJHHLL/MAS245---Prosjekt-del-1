/*
 * SoftBlink.cpp
 *
 * Created: 19.10.2022 09:05:42
 * Author : Simon Storaker
 */ 
//#ifndef F_CPU
#define F_CPU 1000000UL
//#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
	DDRC = 0xFF;
    
	while (1) 
    {
		 PORTC=0xFF;
		 _delay_ms(1000); //so that LED would remain in ON state for 1 sec and then  turns off  for  1 sec.
		 PORTC=0b00;
		 _delay_ms(1000);
    }
}

