#include "spi.h"

void spi_init(void)
{
	// SPE(6) = enable SPI
	// MSTR(4) = master mode
	// SPR0(0) = clock = fosc/64 = 250 kHz (on 16MHz MCU)
	// NOTE: do NOT set DORD(5) — that makes it LSB first
	SPCR_REG = (1<<6)| (1<<4) | (1<<1);
}

void spi_write(uint8_t data)
{
	SPDR_REG = data;
	while (!(SPSR_REG & (1<<7)));  // wait for SPIF flag
}