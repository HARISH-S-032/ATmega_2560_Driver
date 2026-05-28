
#include "7segment.h"

/*----------------------------------------------------------
1.function    : segment
2.description : display a number on the 7-segment display   
3.parameters  : portx - port name
                data  - the number to be displayed (0-9)
 ----------------------------------------------------------*/

void segment(uint8_t portx, uint8_t data)
{
  uint8_t z[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  *port[portx] = z[data];   // write the corresponding value to the port to display the number
}

/*-------------------------------------------------------------------
1.function    : segment_dot
2.description : display a number on the 7-segment display with a dot   
3.parameters  : portx - port name
                data  - the number to be displayed (0-9)
 ------------------------------------------------------------------*/

void segment_dot(uint8_t portx, uint8_t data)
{
  uint8_t z[10] = {0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF};
  *port[portx] = z[data];    // write the corresponding value with dot to the port to display the number with dot
}

