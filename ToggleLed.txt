#define F_CPU 1000000UL // 1MHz
#include <avr/io.h>
#include <util/delay.h>
#define DEBOUNCE_TIME 5 // ms
#define LOCK_INPUT_TIME 300 // 



void init_ports_mcu()
{
	DDRB=0xFFu; // Set all pins of the PORTB as output.
	DDRD &= ~(1<<PD0); // Makes first pin of PORTB as Input
	PORTD = (1 << PD0);
	PORTB = 0xFF; // Set all pins of the PORTB as HIGH. Led is turn on,
	// also the internal Pull Up resistor of first pin PORTB is enable.
}

bool button_state()
{
	/* the button is pressed when PD0 bit is clear */
	if (!(PIND & (1<<PD0)))
	{
		 _delay_ms(DEBOUNCE_TIME);
		 if (!(PIND & (1<<PD0))) return true;
	}
	return false;
 }






int main(void)
{
	bool turnedOn = true;
	init_ports_mcu();
	
	
	
	while(true){
	
		// Initialize I/O pins
		
	
		if (button_state()) // If the button is pressed, toggle the LED's state and delay for 300ms (#define LOCK_INPUT_TIME)
		{
			
			if(!turnedOn)
			{
				PORTB &= ~(1 << PB1);
				turnedOn = true;
				_delay_ms(500);
			}
			else if(turnedOn)
			{
				PORTB |= (1<<PB1);
				turnedOn = false;
				_delay_ms(500);
			}
			//PORTB ^= PORTB; // Invertere porten
			//PORTB ^= 0xFF;
			/*
			//PORTB & ~( 1 << PB1)
			These statements uses C bitwise operators. 
			This time it's using the exclusive OR operator. 
			When you XOR the PORT with the bit value of the bit you want to toggle, 
			that one bit is changed without effecting the other bits.
			*/
		
		}
		
		
	}
	
		
}

