
#include <stdint.h>

#define TCCR1A_REG (*(volatile uint8_t*)0x80)
#define TCCR1B_REG (*(volatile uint8_t*)0x81)
#define TCCR1C_REG (*(volatile uint8_t*)0x82)
#define TCNT1_REG (*(volatile uint16_t*)0x84)
#define OCR1A_REG (*(volatile uint16_t*)0x88)
#define ICR1_REG (*(volatile uint16_t*)0x86)
#define TIMSK1_REG (*(volatile uint8_t*)0x6F)
#define TIFR1_REG (*(volatile uint8_t*)0x36)

void delay_s(uint16_t seconds);
void delay_us(uint16_t us);
