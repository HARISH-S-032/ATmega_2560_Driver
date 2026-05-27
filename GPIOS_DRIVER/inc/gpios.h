
#ifndef GPIOS_H
#define GPIOS_H

#include "define.h"

// configure the whole port as INPUT or OUTPUT
void port_config(volatile char port ,uint8_t data );  

// configure the pin as input or output
void pin_mode(uint8_t pin , uint8_t data);   

// write data to the whole port
void port_write(volatile char portx ,uint8_t data );   

// write data to the pin of the port
void pin_write(volatile char portx , uint8_t pin ,  uint8_t data );   

// write data to the pin of the port using pin number
void digital_write(uint8_t pin ,  uint8_t data );  

// read the whole port
uint8_t port_read(volatile char portx);    

// read the pin of the port
uint8_t pin_read(volatile char portx , uint8_t pin);    

// read the pin of the port using pin number
uint8_t digital_read(volatile uint8_t pin); 

// enable pullup resistor for the whole port
void port_pullup(char portx);    

// enable pullup resistor for the pin of the port
void pin_pullup (char portx , uint8_t pin);    

// enable pullup resistor for the pin of the port using pin number
void digital_pullup(uint8_t pin);    


#endif
