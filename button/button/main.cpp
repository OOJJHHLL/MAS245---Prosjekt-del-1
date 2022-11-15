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
   
	DDRB = DDRB | (1 << PB1) ; //Make pin 4 of port B as a output -> PinMode
	DDRD = DDRD & ~(1 << PD0) ; // Make pin 5 of port C as a input -> PinMode .... 
	PORTD = (1 << PD0); // Enable internal pull-up resistor
	
   	PORTB = PORTB & ~( 1 << PB1) ;
   
    while (1) 
    {
		
		int pinValue = (PIND & (1 << PD0) >> PD0); // DigitalRead
	
		
		if(pinValue == 0) // Hvis du leser 0
		{
			PORTB = PORTB | ( 1 << PB1) ; //PIN1 of port B is high
		}
		
		else if(pinValue == 1)
		{
			PORTB = PORTB & ~( 1 << PB1) ; //PIN1 of port B will remain low
		}
		
    }
	
}

