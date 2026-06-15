# ATmega2560 UART Driver

A lightweight UART (USART) driver for the **ATmega2560** microcontroller developed using **bare-metal C programming**. This library provides reusable APIs for initializing UART communication, transmitting characters and strings, and receiving data through all four hardware USART peripherals available on the ATmega2560.

The driver abstracts low-level register manipulation and simplifies serial communication for embedded applications.

---

## Features

1. Support for USART0, USART1, USART2, and USART3
2. Configurable baud rate initialization
3. Single character transmission
4. String transmission support
5. Character reception support
6. Direct register access implementation
7. Bare-metal AVR programming (No Arduino framework)

---

## Supported Hardware

**Microcontroller:** ATmega2560
**Architecture:** AVR 8-bit
**Language:** C

---

## Project Structure

```text
ATMEGA_2560/
│
├── UART/
│   │
│   ├── inc/
│   │      └── uart.h
│   │
│   ├── src/
│   │      └── uart.c
│   │
│   └── README.md
```

---

# Available APIs

## UART Initialization

### USART0

```c
void serial0_begin(uint32_t baud_rate);
```

Initialize USART0 with the specified baud rate.

Example:

```c
serial0_begin(9600);
```

---

### USART1

```c
void serial1_begin(uint32_t baud_rate);
```

Initialize USART1 with the specified baud rate.

Example:

```c
serial1_begin(115200);
```

---

### USART2

```c
void serial2_begin(uint32_t baud_rate);
```

Initialize USART2 with the specified baud rate.

Example:

```c
serial2_begin(9600);
```

---

### USART3

```c
void serial3_begin(uint32_t baud_rate);
```

Initialize USART3 with the specified baud rate.

Example:

```c
serial3_begin(57600);
```

---

# Transmission Functions

## Send Single Character

### USART0

```c
void serial0_tx_char(char data);
```

Example:

```c
serial0_tx_char('A');
```

---

### USART1

```c
void serial1_tx_char(char data);
```

Example:

```c
serial1_tx_char('B');
```

---

### USART2

```c
void serial2_tx_char(char data);
```

Example:

```c
serial2_tx_char('C');
```

---

### USART3

```c
void serial3_tx_char(char data);
```

Example:

```c
serial3_tx_char('D');
```

---

# String Transmission

### USART0

```c
void serial0_write(char *data);
```

Example:

```c
serial0_write("Hello World");
```

---

### USART1

```c
void serial1_write(char *data);
```

Example:

```c
serial1_write("USART1 Active");
```

---

### USART2

```c
void serial2_write(char *data);
```

Example:

```c
serial2_write("USART2 Active");
```

---

### USART3

```c
void serial3_write(char *data);
```

Example:

```c
serial3_write("USART3 Active");
```

---

# Receive Functions

### USART0

```c
char serial0_read(void);
```

Example:

```c
char data = serial0_read();
```

---

### USART1

```c
char serial1_read(void);
```

Example:

```c
char data = serial1_read();
```

---

### USART2

```c
char serial2_read(void);
```

Example:

```c
char data = serial2_read();
```

---

### USART3

```c
char serial3_read(void);
```

Example:

```c
char data = serial3_read();
```

---

# Example Usage

Transmit a message through USART0:

```c
#include "uart.h"

int main(void)
{
    serial0_begin(9600);

    while(1)
    {
        serial0_write("Hello UART\r\n");
    }
}
```

---

# UART Configuration

The driver configures USART peripherals as:

| Parameter | Configuration |
| --------- | ------------- |
| Data Bits | 8             |
| Parity    | None          |
| Stop Bits | 1             |
| Mode      | Asynchronous  |
| TX        | Enabled       |
| RX        | Enabled       |

---

# Internal Working

This driver uses AVR USART registers:

| Register | Purpose                            |
| -------- | ---------------------------------- |
| UBRRnH   | Baud rate high byte                |
| UBRRnL   | Baud rate low byte                 |
| UCSRnA   | USART status register              |
| UCSRnB   | Enable transmitter and receiver    |
| UCSRnC   | Frame format configuration         |
| UDRn     | Transmit and receive data register |

where **n = 0, 1, 2, 3** depending on the USART peripheral used.

---

# Design Goal

The library aims to provide:

* Easier UART communication
* Cleaner application code
* Reusable embedded modules
* Reduced direct register manipulation
* Multi-UART support for ATmega2560 projects

---

# Author

**Harish S**

Embedded Systems • AVR Programming • Bare-Metal Development
