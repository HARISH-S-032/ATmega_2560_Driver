# ATmega2560 SPI Bit-Banging Driver

A lightweight SPI Bit-Banging driver for the **ATmega2560** microcontroller developed using **bare-metal C programming**. This library implements SPI communication using GPIO pin toggling instead of the hardware SPI peripheral.

The driver manually generates SPI clock signals and transmits data through software, making it useful when the hardware SPI module is unavailable or when custom SPI implementations are required.

---

## Features

1. Software SPI implementation using GPIO
2. Master mode operation
3. Manual clock generation
4. Byte-wise data transmission
5. Configurable through GPIO APIs
6. Bare-metal AVR programming (No Arduino framework)
7. No hardware SPI peripheral required

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
├── SPI_BITBANGING/
│   │
|   └── spi_bitbanging.h
│   │
│   └── README.md
```

---

# Available APIs

## SPI Initialization

### Initialize Software SPI

```c
void spi_bb_init(void);
```

Configure MOSI, MISO, SCK and SS pins for software SPI communication.

Example:

```c
spi_bb_init();
```

---

# Data Transmission

### Send Single Byte

```c
void spi_bb_write(unsigned char data);
```

Transmit a single byte over the software SPI bus.

Example:

```c
spi_bb_write(0x55);
```

---

# Pin Configuration

The driver uses the following GPIO pins:

| Signal | Pin |
| ------ | --- |
| MOSI   | 7   |
| SCK    | 6   |
| SS     | 5   |
| MISO   | 4   |

---

# Example Usage

Transmit data continuously:

```c
#include "spi_bitbanging.h"

int main(void)
{
    spi_bb_init();

    while(1)
    {
        spi_bb_write(0xAA);
        spi_bb_write(0x55);
    }
}
```

---

# SPI Frame Transmission

Data is transmitted:

```text
Bit7 → Bit6 → Bit5 → Bit4 → Bit3 → Bit2 → Bit1 → Bit0
```

The driver sends:

* MSB First
* 8-bit Data
* Software Generated Clock

---

# Internal Working

The transmission process is:

1. Pull SS LOW to select the slave.
2. Send each data bit on MOSI.
3. Generate a clock pulse on SCK.
4. Repeat for all 8 bits.
5. Pull SS HIGH to deselect the slave.

Clock generation:

```c
digital_write(SCK,1);
delay_us(5);

digital_write(SCK,0);
delay_us(5);
```

Data transmission:

```c
if(data & (1 << i))
    digital_write(MOSI,1);
else
    digital_write(MOSI,0);
```

---

# SPI Configuration

| Parameter        | Configuration       |
| ---------------- | ------------------- |
| Mode             | Master              |
| Data Order       | MSB First           |
| Clock Generation | Software            |
| Data Length      | 8-bit               |
| Slave Select     | Software Controlled |

---

# Limitations

* Master mode only
* Transmit API only
* No read functionality
* No interrupt support
* Fixed GPIO pin assignment
* Blocking implementation

---

# Design Goal

The library aims to provide:

* SPI communication without hardware SPI
* Educational understanding of SPI protocol
* Reusable software communication module
* Reduced dependency on dedicated peripherals

---

# Author

**Harish S**

Embedded Systems • AVR Programming • Bare-Metal Development
