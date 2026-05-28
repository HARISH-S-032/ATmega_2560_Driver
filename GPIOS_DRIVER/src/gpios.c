#include "gpios.h"


/*-------------------------------------------------------------------------------
1.function    : port_config
2.description : configure the whole port as INPUT or OUTPUT
3.parameters  : port - the port to be configured
                data - INPUT,OUTPUT or value directly
-------------------------------------------------------------------------------*/

void port_config( char port ,uint8_t data )   
{
  *ddr[port]=data;   // set the whole port as input or output
}


/*-----------------------------------------------------------------
1.function    : pin_mode
2.description : configure the pin as input or output
3.parameters  : pin  - the pin to be configured (Ardiuno pin number)
                data - INPUT or OUTPUT
------------------------------------------------------------------*/

void pin_mode(uint8_t pin , uint8_t data)
{
    uint8_t a= pin_port[pin];   // get the port of the pin
    uint8_t b= pin_bit[pin];    // get the bit of the pin
  if(data==output)
  {
    *ddr[a]|= (1<<b);  //set a pin as output
  }
  else
    *ddr[a]&= ~(1<<b);  //set a pin as input
}
                          

/*---------------------------------------------
1.function    : port_write
2.description : write data to the whole port
3.parameters  : portx - port name
                data - the data to be written
---------------------------------------------*/

void port_write( char portx ,uint8_t data )  
{
  *port[portx]=data;  // write data to the whole port
}


/*-------------------------------------------------
1.function    : pin_write
2.description : write data to a specific pin
3.parameters  : portx - port name
                pin   - pin number of the port (0-7)
                data  - high or low
-------------------------------------------------*/

void pin_write( char portx , uint8_t pin ,  uint8_t data )
{
  if(data==high)
  {
    *port[portx]|= (1<<pin);  // set the pin high
  }
  else
  {
    *port[portx]&= ~(1<<pin); // set the pin low
  }
}


/*-----------------------------------------------------------
1.function    : digital_write
2.description : write data to a specific pin using pin number   
3.parameters  : pin  -  pin number (Arduino pin number)
                data - high or low
*/------------------------------------------------------------

void digital_write(uint8_t pin ,  uint8_t data )
{
    uint8_t a= pin_port[pin];     // get the port of the pin
    uint8_t b= pin_bit[pin];      // get the bit of the pin
  if(data==high)
  {
    *port[a]|= (1<<b);    // set the pin high
  }
  else
    *port[a]&= ~(1<<b);   // set the pin low
}


/*-------------------------------------------------
1.function    : port_read
2.description : read data from the whole port
3.parameters  : portx - port name
4.return      : the data read from the port
-------------------------------------------------*/

uint8_t port_read( char portx)
{
  return *pin_in[portx];  // read the whole port
}


/*-------------------------------------------------
1.function    : pin_read
2.description : read data from a specific pin
3.parameters  : portx - port name
                pin   - pin number of the port (0-7)
4.return      : the data read from the pin
-------------------------------------------------*/

uint8_t pin_read( char portx , uint8_t pin)
{
  if(*pin_in[portx]&(1<<pin))return 1;  // if the pin is high, return 1
	return 0;                           // if the pin is low, return 0
}


/*------------------------------------------------------------
1.function    : digital_read
2.description : read data from a specific pin using pin number
3.parameters  : pin  -  pin number (Arduino pin number)
4.return      : the data read from the pin
------------------------------------------------------------*/

uint8_t digital_read( uint8_t pin)
{
    uint8_t a= pin_port[pin];        // get the port of the pin
    uint8_t b= pin_bit[pin];         // get the bit of the pin
    if(*pin_in[a]&(1<<b))return 1;   // if the pin is high, return 1
    return 0;                        // if the pin is low, return 0
}


/*---------------------------------------------------------
1.function    : port_pullup
2.description : enable pull-up resistor for the whole port
3.parameters  : portx - port name
---------------------------------------------------------*/

void port_pullup(char portx)
{
  *port[portx]=0xff;   // enable pull-up resistor for the whole port by writing 1 to the output register
}


/*---------------------------------------------------------
1.function    : pin_pullup
2.description : enable pull-up resistor for a specific pin
3.parameters  : portx - port name
                pin   - pin number of the port (0-7)
---------------------------------------------------------*/

void pin_pullup (char portx , uint8_t pin)
{
  *port[portx]|=(1<<pin);   // enable pull-up resistor for the pin by writing 1 to the output register
}


/*--------------------------------------------------------------------------
1.function    : digital_pullup
2.description : enable pull-up resistor for a specific pin using pin number
3.parameters  : pin  -  pin number (Arduino pin number)
---------------------------------------------------------------------------*/

void digital_pullup(uint8_t pin)
{
  uint8_t a= pin_port[pin];   // get the port of the pin
  uint8_t b= pin_bit[pin];    // get the bit of the pin
  *port[a]|=(1<<b);           // enable pull-up resistor for the pin by writing 1 to the output register
}
