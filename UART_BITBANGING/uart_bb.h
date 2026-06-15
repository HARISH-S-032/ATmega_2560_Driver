#include "gpios.h"
#include "delay.h"

static uint8_t txpin;

/*-------------------------------------------------------------------
1.function    : init_tx
2.description : initialize the TX pin for UART communication
3.parameters  : tx_pin - the pin number for the TX line
 ------------------------------------------------------------------*/
void init_tx(uint8_t tx_pin)
{
  txpin=tx_pin;
  pin_mode(tx_pin,output);
  digital_write(tx_pin,high);
}

/*-------------------------------------------------------------------
1.function    : serial_write
2.description : send a byte of data by bit-banging the UART protocol
3.parameters  : data - the byte to be sent
 ------------------------------------------------------------------*/
void serial_write(char data)
{
   digital_write(txpin,low);
   // 9600 baud rate corresponds to a bit duration of approximately 104 microseconds
   delay_us(104);

   for(int i=0;i<8;i++)
   {
     if(data & (1 << i))
     {
      digital_write(txpin,high);
     }

     else
     {
      digital_write(txpin,low);
     }
     delay_us(104);
   }

   digital_write(txpin,high);
   delay_us(104);
}
