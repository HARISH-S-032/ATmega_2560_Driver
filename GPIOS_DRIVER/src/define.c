#include "define.h"


volatile uint8_t* ddr[11] = {  // direction register
	(volatile uint8_t *)0x21, 
	(volatile uint8_t *)0x24, 
	(volatile uint8_t *)0x27, 
	(volatile uint8_t *)0x2a, 
	(volatile uint8_t *)0x2d, 
	(volatile uint8_t *)0x30,
	(volatile uint8_t *)0x33, 
	(volatile uint8_t *)0x101, 
	(volatile uint8_t *)0x104,
	(volatile uint8_t *)0x107, 
	(volatile uint8_t *)0x10a 
};

volatile uint8_t* port[11] = {  // output register
	(volatile uint8_t *)0x22,
	(volatile uint8_t *)0x25,
	(volatile uint8_t *)0x28, 
	(volatile uint8_t *)0x2b, 
	(volatile uint8_t *)0x2e, 
	(volatile uint8_t *)0x31, 
    (volatile uint8_t *)0x34,
	(volatile uint8_t *)0x102, 
	(volatile uint8_t *)0x105,
	(volatile uint8_t *)0x108,
	(volatile uint8_t *)0x10b 
};


volatile uint8_t* pin_in[11] = {  // input register
	(volatile uint8_t *)0x20, 
	(volatile uint8_t *)0x23,
	(volatile uint8_t *)0x26,
	(volatile uint8_t *)0x29, 
	(volatile uint8_t *)0x2c, 
	(volatile uint8_t *)0x2f, 
	(volatile uint8_t *)0x32, 
	(volatile uint8_t *)0x100,
	(volatile uint8_t *)0x103, 
	(volatile uint8_t *)0x106, 
	(volatile uint8_t *)0x109 
};

uint8_t pin_port[] = {       // pin to port mapping
porte,porte,porte,porte,portg,porte,porth,porth,
porth,porth,portb,portb,portb,portb,
portj,portj,porth,porth,portd,portd,portd,portd,
porta,porta,porta,porta,porta,porta,porta,porta,
portc,portc,portc,portc,portc,portc,portc,portc,
portd,portg,portg,portg,
portl,portl,portl,portl,portl,portl,portl,portl,
portb,portb,portb,portb,
portf,portf,portf,portf,portf,portf,portf,portf,
portk,portk,portk,portk,portk,portk,portk,portk
};


uint8_t pin_bit[] = {     // pin to bit mapping
0,1,4,5,5,3,3,4,
5,6,4,5,6,7,
1,0,1,0,3,2,1,0,
0,1,2,3,4,5,6,7,
7,6,5,4,3,2,1,0,
7,2,1,0,
7,6,5,4,3,2,1,0,
3,2,1,0,
0,1,2,3,4,5,6,7,
0,1,2,3,4,5,6,7
};

/*---------Delay---------*/
void delay_h(float x)
{
  volatile long i;
  for(i=0;i<(x*75);i++);
}
