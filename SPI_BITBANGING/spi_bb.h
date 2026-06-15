#include "gpios.h"
#include "delay.h"

#define MOSI 7 
#define SCK  6
#define SS   5
#define MISO 4

/*--------------------------------------------------------------------
1.function    : spi_bb_init
2.description : initialize bit-banged SPI
3.parameters  : none
 -------------------------------------------------------------------*/
void spi_bb_init(void)
{
    pin_mode(MOSI, output);
    pin_mode(SCK, output);
    pin_mode(SS, output);
    pin_mode(MISO,input);
    digital_write(SS, 1);
    digital_write(SCK, 0);
}


/*
1.function    : spi_bb_write
2.description : write a byte of data to the bit-banged SPI bus
3.parameters  : data - the byte to be written
 -------------------------------------------------------------------*/
void spi_bb_write(unsigned char data)
{
    digital_write(SS, 0);
    for(int i = 7; i >= 0; i--)
    {
        if(data & (1 << i))
            digital_write(MOSI, 1);
        else
            digital_write(MOSI, 0);
        digital_write(SCK, 1);
        delay_us(5);
        digital_write(SCK, 0);
        delay_us(5);
    }
    digital_write(SS, 1);
}