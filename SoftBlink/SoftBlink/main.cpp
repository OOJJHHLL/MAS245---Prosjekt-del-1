/*
 * SoftBlink.cpp
 *
 * Created: 19.10.2022 09:05:42
 * Author : Simon Storaker
 */ 
//#ifndef F_CPU
#define F_CPU 1000000UL // 1MHz
//#endif

#include <avr/io.h>
#include <util/delay.h>


void blinkLED()
{
		/*DDRC = (1 << PC5); // Setter PIN som output (likt som pinMode i arduino)

		while (1)
		{
			PORTC &= ~(1 << PC5); // Setter PIN 5 portC lav
			_delay_ms(1000); // 1 sekund delay
			
			PORTC |= (1 << PC5); //Setter PIN 5 portC høy
			_delay_ms(1000); // 1 sekund delay
		}*/
	
}


void setup()
{
	//DDRB = (1 << PB1); // Setter PIN som output (likt som pinMode i arduino)
}

void pwm (int dutycycle, int periode)
{
	
}

int main(void)
{
	
	int brightness = 0;
	int fade = 5;
	
	DDRB = (1 << PB1);
	while (1) 
    {		
		PORTB &= ~(1 << PB1); // Setter PIN 5 portC lav
		_delay_ms(1000); // 1 sekund delay

		PORTB |= (1 << PB1); //Setter PIN 5 portC høy
		_delay_ms(1000); // 1 sekund delay
    }
}

