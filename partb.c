/*
 * GccApplication3.cpp
 *
 * Created: 2/3/2023 11:13:50 AM
 * Author : sindu
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL

void Initialize()
{
	cli(); //disables global interrupt
	DDRB &= ~(1<<DDB0); //set as input 
	DDRB |= (1<<DDB5); //LED as output
	TIMSK1 |= (1<<ICIE1); //enable input capture event
	TCCR1B |= (1<<ICES1); //look for rising edge
	TIFR1 |= (1<<ICF1); //clear input capture flag
	sei(); // Enable Global Interrupts
	//setup interrupts here
}
ISR(TIMER1_CAPT_vect) //capture event
{
	PORTB ^= (1<<PORTB5); //toggles the on-board LED
}
int main(void)
{
	Initialize();
    while (1); 
}


