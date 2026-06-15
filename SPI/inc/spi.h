#ifndef SPI_H
#define SPI_H


#include <stdint.h>

#define SPRC_REG (*(volatile uint8_t*)0x4C) // SPI Control Register
#define SPSR_REG (*(volatile uint8_t*)0x4D) // SPI Status Register
#define SPDR_REG (*(volatile uint8_t*)0x4E) // SPI Data Register

// Initialize SPI as Master with the specified clock rate
void spi_init(void);

// Write a byte of data to the SPI bus
void spi_write(uint8_t data);

#endif