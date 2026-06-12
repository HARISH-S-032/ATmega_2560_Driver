#ifndef SPI_H
#define SPI_H


#include <stdint.h>

#define SPRC_REG (*(volatile uint8_t*)0x4C)
#define SPSR_REG (*(volatile uint8_t*)0x4D)
#define SPDR_REG (*(volatile uint8_t*)0x4E)

void spi_init(void);

void spi_write(uint8_t data);

#endif