#ifndef DEFINE_H
#define DEFINE_H

#include <stdint.h>

extern volatile uint8_t* ddr[11];
extern volatile uint8_t* port[11];
extern volatile uint8_t* pin_in[11];

extern uint8_t pin_port[];
extern uint8_t pin_bit[];

void delay_h(float x);


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




  


#endif