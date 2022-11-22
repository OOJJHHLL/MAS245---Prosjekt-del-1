/*
 * button.cpp
 *
 * Created: 21.10.2022 12:47:42
 * Author : Herman Jonsaas
 */ 

#define F_CPU 1000000UL // 1MHz
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   
	DDRB = DDRB | (1 << PB1); 
	DDRD = DDRD & ~(1 << PD0); 
	PORTD = (1 << PD0);
	
   	PORTB = PORTB & ~( 1 << PB1) ;
   
    while (1) 
    {
		
		int pinValue = (PIND & (1 << PD0) >> PD0); 
	
		
		if(pinValue == 0) // Hvis du leser 0
		{
			PORTB = PORTB | ( 1 << PB1) ; 
		}
		
		else if(pinValue == 1)
		{
			PORTB = PORTB & ~( 1 << PB1) ; 
		}
		
    }
	
}

