# ATmega2560 UART Bit-Banging Driver

A lightweight software UART transmitter for the **ATmega2560** microcontroller developed using **bare-metal C programming**. This library implements UART transmission using GPIO pin toggling (bit-banging) without using the hardware USART peripherals.

The driver generates UART frames entirely in software and can be used when hardware UART resources are unavailable.

---

## Features

1. Software UART transmission using GPIO
2. User-selectable TX pin
3. Standard UART frame generation
4. 8-bit data transmission
5. GPIO-based implementation
6. Bare-metal AVR programming (No Arduino framework)
7. No hardware USART required

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
├── UART_BITBANGING/
│   │
│   └── uart_bitbanging.h
│   │
│   │
│   └── README.md
```

---

# Available APIs

## Initialization

### Configure TX Pin

```c
void init_tx(uint8_t tx_pin);
```

Initialize the selected GPIO pin as the UART transmit pin.

Example:

```c
init_tx(13);
```

---

# Transmission Functions

### Send Single Character

```c
void serial_write(char data);
```

Transmit a single byte using software UART.

Example:

```c
serial_write('A');
```

---

# UART Frame Format

The driver generates the following UART frame:

```text
Idle  Start  D0 D1 D2 D3 D4 D5 D6 D7  Stop
 1      0    x  x  x  x  x  x  x  x    1
```

Where:

* 1 Start Bit
* 8 Data Bits (LSB First)
* 1 Stop Bit

---

# Example Usage

Transmit characters through a GPIO pin:

```c
#include "uart_bitbanging.h"

int main(void)
{
    init_tx(13);

    while(1)
    {
        serial_write('H');
        serial_write('i');
    }
}
```

---

# Baud Rate

Current implementation is configured for:

```text
9600 Baud
```

Bit duration:

```text
104 µs per bit
```

Implemented using:

```c
delay_us(104);
```

---

# Internal Working

The driver performs UART transmission by:

1. Driving TX line LOW for the start bit
2. Sending 8 data bits (LSB first)
3. Driving TX line HIGH for the stop bit
4. Maintaining HIGH level during idle state

GPIO control is handled using:

| Function        | Purpose             |
| --------------- | ------------------- |
| pin_mode()      | Configure TX pin    |
| digital_write() | Drive TX line       |
| delay_us()      | Generate bit timing |

---

# Limitations

* Transmit only
* Fixed baud rate (9600)
* Blocking implementation
* No receive support
* Timing depends on delay accuracy

---

# Design Goal

The library aims to provide:

* UART communication without hardware USART
* Educational understanding of UART protocol
* Reusable software serial module
* Simple debugging and testing interface

---

# Author

**Harish S**

Embedded Systems • AVR Programming • Bare-Metal Development
