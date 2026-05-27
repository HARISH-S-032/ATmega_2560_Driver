#ifndef DEFINE_H
#define DEFINE_H

#include <stdint.h>

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

#define high 1         // 1 for high
#define low 0          // 0 for low

#define output 1       // 1 for output
#define input 0        // 0 for input

#define OUTPUT 0XFF  // 0xFF for output
#define INPUT 0x00   // 0x00 for input

#define porta 0  // 0 for port a
#define portb 1  // 1 for port b
#define portc 2  // 2 for port c
#define portd 3  // 3 for port d
#define porte 4  // 4 for port e
#define portf 5  // 5 for port f
#define portg 6  // 6 for port g
#define porth 7  // 7 for port h
#define portj 8  // 8 for port j
#define portk 9  // 9 for port k
#define portl 10 // 10 for port l

#define A0 54   // 54 for analog pin 0
#define A1 55   // 55 for analog pin 1
#define A2 56   // 56 for analog pin 2
#define A3 57   // 57 for analog pin 3
#define A4 58   // 58 for analog pin 4
#define A5 59   // 59 for analog pin 5
#define A6 60   // 60 for analog pin 6
#define A7 61   // 61 for analog pin 7
#define A8 62   // 62 for analog pin 8
#define A9 63   // 63 for analog pin 9
#define A10 64  // 64 for analog pin 10
#define A11 65  // 65 for analog pin 11
#define A12 66  // 66 for analog pin 12
#define A13 67  // 67 for analog pin 13
#define A14 68  // 68 for analog pin 14
#define A15 69  // 69 for analog pin 15


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

#endif