/* Koden baserer seg på:
   "AVR Microcontroller. Toggle LED’s Using a Push Button Switch. Push Button Debouncing." av  malcomoffice
   fra https://www.instructables.com/AVR-Microcontroller-Toggle-LEDs-Using-a-Push-Butto/
*/

#define F_CPU 1000000UL // 1MHz

#include <avr/io.h>
#include <util/delay.h>
#define DEBOUNCE_TIME 5 // millisekunder
#define LOCK_INPUT_TIME 300  


void initialize_ports()
{
	DDRB=0xFFu; // Alle pins på PORTB settes som output
	DDRD &= ~(1<<PD0); // Pin0 PORTD settes som input
	PORTD = (1 << PD0);
	PORTB = 0xFF; // Alle pins på PORT B settes høy
}

bool state_of_button()
{
	if (!(PIND & (1<<PD0))) 
	{
		 _delay_ms(DEBOUNCE_TIME);
		 if (!(PIND & (1<<PD0))) 
			return true;
	}
	return false;
 }


int main(void)
{
	bool On = true; // Skrudd på
	initialize_ports();
	
	while(true){
		if (state_of_button()) // Hvis den trykkes inn, vil LED-tilstanden holdes
		{
			if(!On)
			{
				PORTB &= ~(1 << PB1);
				On = true;
				_delay_ms(500);
			}
			else if(On)
			{
				PORTB |= (1<<PB1);
				On = false;
				_delay_ms(500);
			}
		}	
	}
}
