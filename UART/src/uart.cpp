#include "uart.h"

/*---------------------------------------------------------------------------
1.function   : serial0_begin, serial1_begin, serial2_begin, serial3_begin
2.description: Initializes the USART0 with the specified baud rate.
3.parameters:  baud_rate - The desired baud rate for communication.
---------------------------------------------------------------------------*/
void serial0_begin(uint32_t baud_rate)
{
      uint16_t a;
      a=(16000000/(16*baud_rate))-1;    // Calculate the baud rate register value based on the formula
      UBRR0H_REG = (a >> 8);            // Set the high byte of the baud rate register
      UBRR0L_REG = a;                   // Set the low byte of the baud rate register
      UCSR0C_REG|=0x03;  //set bit 0 and bit 1 of UCSR0C to configure the USART for 8 data bits, no parity, and 1 stop bit
      UCSR0B_REG|=0X18;  //enable RX and TX by setting bit 3 (RXEN0) and bit 4 (TXEN0) of UCSR0B
}


/*---------------------------------------------------------------------------
1.function   : serial0_tx_char, serial1_tx_char, serial2_tx_char, serial3_tx_char
2.description: Transmits a single character over the specified USART.
3.parameters:  data - The character to be transmitted.
---------------------------------------------------------------------------*/
void serial0_tx_char(char data)  
{
    while (!(UCSR0A_REG & (1 << 5)));   // Wait until the transmit buffer is empty by checking the UDRE0 bit (bit 5) in UCSR0A
    UDR0_REG = data;  // Load the character into the USART Data Register (UDR0) to start transmission
}


/*---------------------------------------------------------------------------
1.function   : serial0_write, serial1_write, serial2_write, serial3_write
2.description: Writes a string over the specified USART by transmitting each character until the null terminator is reached.
3.parameters:  data - A pointer to the null-terminated string to be transmitted.
---------------------------------------------------------------------------*/
void serial0_write(char *data)
{
    while(*data)        // Loop through each character in the string until the null terminator is reached
    {
        serial0_tx_char(*data);   // Transmit the current character using the serial0_tx_char function
        data++;
    }
}

/*---------------------------------------------------------------------------
1.function   : serial0_read, serial1_read, serial2_read, serial3_read
2.description: Reads a single character from the specified USART.
3.returns:     The character received from the USART.
---------------------------------------------------------------------------*/
char serial0_read(void)
{
    while (!(UCSR0A_REG & (1 << 7)));  // Wait until a character is received by checking the RXC0 bit (bit 7) in UCSR0A
    return UDR0_REG;  // Return the received character from the USART Data Register (UDR0)
}

/* ================= USART1 ================= */

void serial1_begin(uint32_t baud_rate)
{
      uint16_t a;
      a=(16000000/(16*baud_rate))-1;
      UBRR1H_REG = (a >> 8);
      UBRR1L_REG = a;
      UCSR1C_REG|=0x03;  //set bit 
      UCSR1B_REG|=0X18;  //enable RX and TX
}

void serial1_tx_char(char data)
{
    while (!(UCSR1A_REG & (1 << 5)));
    UDR1_REG = data;
}

void serial1_write(char *data)
{
    while(*data)
    {
        serial1_tx_char(*data);
        data++;
    }
}

char serial1_read(void)
{
    while (!(UCSR1A_REG & (1 << 7)));
    return UDR1_REG;
}

/* ================= USART2 ================= */

void serial2_begin(uint32_t baud_rate)
{
      uint16_t a;
      a=(16000000/(16*baud_rate))-1;
      UBRR2H_REG = (a >> 8);
      UBRR2L_REG = a;
      UCSR2C_REG|=0x03;  //set bit 
      UCSR2B_REG|=0X18;  //enable RX and TX
}

void serial2_tx_char(char data)
{
    while (!(UCSR2A_REG & (1 << 5)));
    UDR2_REG = data;
}

void serial2_write(char *data)
{
    while(*data)
    {
        serial2_tx_char(*data);
        data++;
    }
}

char serial2_read(void)
{
    while (!(UCSR2A_REG & (1 << 7)));
    return UDR2_REG;
}

/* ================= USART3 ================= */

void serial3_begin(uint32_t baud_rate)
{
      uint16_t a;
      a=(16000000/(16*baud_rate))-1;
      UBRR3H_REG = (a >> 8);
      UBRR3L_REG = a;
      UCSR3C_REG|=0x03;  //set bit 
      UCSR3B_REG|=0X18;  //enable RX and TX
}

void serial3_tx_char(char data)
{
    while (!(UCSR3A_REG & (1 << 5)));
    UDR3_REG = data;
}

void serial3_write(char *data)
{
    while(*data)
    {
        serial3_tx_char(*data);
        data++;
    }
}

char serial3_read(void)
{
    while (!(UCSR3A_REG & (1 << 7)));
    return UDR3_REG;
}

