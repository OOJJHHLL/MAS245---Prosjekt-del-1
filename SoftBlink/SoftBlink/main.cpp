/*
 * SoftBlink.cpp
 *
 * Created: 19.10.2022 09:05:42
 * Author : LH
 */ 


#define F_CPU 1000000UL // 1MHz


#include <avr/io.h>
#include <util/delay.h>


void delay_ms(int n) {
	while(n--) {
		_delay_ms(1);
	}
}

int main(void)
{
	/*int i = 0; //Variabel som skal endre seg
	
	
	int delayValue = 1; // Hvor mye On tida skal øke
	
	
	int pulseWidthTime = 25; // Tida på en periode*/
	
	//int = 0;
	
	int onTime = 0;
	int offTime = 100;
	float plp = 0; // Percived light formula
	//int i = 0;
	
	DDRB = (1 << PB1);
	while (1) 
    {		


		for (int i = 0; i <=100; i++) // fra 0 til 100%
		{
			offTime = 100;
			onTime = 0;
			
			PORTB |= (1 << PB1);
			
			while (onTime<i) //onTIme øker så lenge den er mindre enn i
			{
				_delay_ms(0.15);
				onTime++;
			}
			
			PORTB &= ~(1 << PB1);
			
			while(offTime>i)
			{
				_delay_ms(0.20);
				offTime--;
			}
		}
		
		
		//Dimme
		for (int i = 100; i >= 0; i--) // fra 100 til 0%
		{
			offTime = 100;
			onTime = 0;
			
		
			
			PORTB |= (1 << PB1);
			
			while (onTime<i) //
			{
				_delay_ms(0.15);
				onTime++;
			}
			
				PORTB &= ~(1 << PB1);
			
			while(offTime>i)
			{
				_delay_ms(0.20);
				offTime--;
			}
			
		}
		
		
		
    }
}

