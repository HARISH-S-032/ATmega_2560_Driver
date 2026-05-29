#ifndef UART_H
#define UART_H

#include <stdint.h>


#include <stdint.h>

/* ================= USART0 ================= */

#define UCSR0A_REG (*(volatile uint8_t*)0xC0) //USART Control and Status Register A
#define UCSR0B_REG (*(volatile uint8_t*)0xC1) // USART Control and Status Register B
#define UCSR0C_REG (*(volatile uint8_t*)0xC2) // USART Control and Status Register C
#define UBRR0L_REG (*(volatile uint8_t*)0xC4) // USART Baud Rate Register Low
#define UBRR0H_REG (*(volatile uint8_t*)0xC5) // USART Baud Rate Register High
#define UDR0_REG   (*(volatile uint8_t*)0xC6) // USART Data Register


/* ================= USART1 ================= */

#define UCSR1A_REG (*(volatile uint8_t*)0xC8)
#define UCSR1B_REG (*(volatile uint8_t*)0xC9)
#define UCSR1C_REG (*(volatile uint8_t*)0xCA)
#define UBRR1L_REG (*(volatile uint8_t*)0xCC)
#define UBRR1H_REG (*(volatile uint8_t*)0xCD)
#define UDR1_REG   (*(volatile uint8_t*)0xCE)


/* ================= USART2 ================= */

#define UCSR2A_REG (*(volatile uint8_t*)0xD0)
#define UCSR2B_REG (*(volatile uint8_t*)0xD1)
#define UCSR2C_REG (*(volatile uint8_t*)0xD2)
#define UBRR2L_REG (*(volatile uint8_t*)0xD4)
#define UBRR2H_REG (*(volatile uint8_t*)0xD5)
#define UDR2_REG   (*(volatile uint8_t*)0xD6)


/* ================= USART3 ================= */

#define UCSR3A_REG (*(volatile uint8_t*)0x130)
#define UCSR3B_REG (*(volatile uint8_t*)0x131)
#define UCSR3C_REG (*(volatile uint8_t*)0x132)
#define UBRR3L_REG (*(volatile uint8_t*)0x134)
#define UBRR3H_REG (*(volatile uint8_t*)0x135)
#define UDR3_REG   (*(volatile uint8_t*)0x136)

// Initialize USARTn with the specified baud rate
void serial0_begin(uint32_t baud_rate);  
void serial1_begin(uint32_t baud_rate);  
void serial2_begin(uint32_t baud_rate);  
void serial3_begin(uint32_t baud_rate);  

// Transmit a single character over USARTn
void serial0_tx_char(char data);    
void serial1_tx_char(char data);    
void serial2_tx_char(char data);    
void serial3_tx_char(char data); 

// Write a string over USARTn
void serial0_write(char *data);    
void serial1_write(char *data);    
void serial2_write(char *data);    
void serial3_write(char *data);   

// Read a single character from USARTn
char serial0_read(void);           
char serial1_read(void);           
char serial2_read(void);          
char serial3_read(void);          


#endif

