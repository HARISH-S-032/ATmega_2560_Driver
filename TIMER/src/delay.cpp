#include "delay.h"

void delay_s(uint16_t seconds)
{
  for(uint16_t i=0;i<seconds;i++)
  {
  TCCR1A_REG=0X00;
  TCNT1_REG = 0;
  OCR1A_REG = 62499;
  TIFR1_REG = (1<<1);
  TCCR1B_REG = 0x0C;;
  while(!(TIFR1_REG & (1<<1)));
  TCCR1B_REG = 0x00;
  }
}

void delay_us(uint16_t us)
{
    TCCR1A_REG = 0x00;
    TCNT1_REG = 0;
    OCR1A_REG = (us * 2) - 1;
    TIFR1_REG = (1 << 1);
    TCCR1B_REG = 0x0A;  
    while (!(TIFR1_REG & (1 << 1)));
    TCCR1B_REG = 0x00;
}
