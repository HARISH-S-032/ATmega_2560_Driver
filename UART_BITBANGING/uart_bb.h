#include "gpios.h"
#include "delay.h"

static uint8_t txpin;

void init_tx(uint8_t tx_pin)
{
  txpin=tx_pin;
  pin_mode(tx_pin,output);
  digital_write(tx_pin,high);
}

void init_rx(uint8_t rx_pin)
{
  pin_mode(rx_pin,input);
}

void serial_write(char data)
{
   digital_write(txpin,low);
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
