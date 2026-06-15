#include "spi.h"


/*--------------------------------------------------------------------
1.function    : spi_init
2.description : initialize SPI as master with the specified clock rate
                SPE(6) = enable SPI
	            MSTR(4) = master mode
	            SPR0(0) = clock = fosc/64 = 250 kHz (on 16MHz MCU)
	            NOTE: do NOT set DORD(5) — that makes it LSB first
3.parameters  : none
 -------------------------------------------------------------------*/
void spi_init(void)
{
	SPCR_REG = (1<<6)| (1<<4) | (1<<1);
}

/*--------------------------------------------------------------------
1.function    : spi_write
2.description : write a byte of data to the SPI bus
3.parameters  : data - the byte to be written
 -------------------------------------------------------------------*/
void spi_write(uint8_t data)
{
	SPDR_REG = data;
	while (!(SPSR_REG & (1<<7)));  // wait for SPIF flag
}