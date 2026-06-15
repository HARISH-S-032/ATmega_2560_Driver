# ATmega2560 SPI Driver

A lightweight SPI (Serial Peripheral Interface) driver for the **ATmega2560** microcontroller developed using **bare-metal C programming**. This library provides reusable APIs for initializing the SPI peripheral and transmitting data using the ATmega2560 hardware SPI module.

The driver abstracts low-level register manipulation and simplifies SPI communication for embedded applications.

---

## Features

1. Hardware SPI support
2. Master mode operation
3. Configurable SPI clock generation
4. Byte-wise data transmission
5. Direct register access implementation
6. Bare-metal AVR programming (No Arduino framework)

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
├── SPI/
│   │
│   ├── inc/
│   │      └── spi.h
│   │
│   ├── src/
│   │      └── spi.c
│   │
│   └── README.md
```

---

# Available APIs

## SPI Initialization

### Initialize SPI

```c
void spi_init(void);
```

Configure the SPI peripheral as Master.

Configuration:

* SPI Enabled
* Master Mode Enabled
* Clock Frequency = FOSC / 64
* MSB First
* SPI Mode 0

Example:

```c
spi_init();
```

---

# Data Transmission

### Send Single Byte

```c
void spi_write(uint8_t data);
```

Transmit a single byte over the SPI bus.

Example:

```c
spi_write(0x55);
```

---

# Example Usage

Transmit a byte continuously:

```c
#include "spi.h"

int main(void)
{
    spi_init();

    while(1)
    {
        spi_write(0xAA);
    }
}
```

---

# SPI Configuration

The driver configures SPI using the following settings:

| Parameter             | Configuration |
| --------------------- | ------------- |
| Mode                  | Master        |
| Data Order            | MSB First     |
| Clock Polarity (CPOL) | 0             |
| Clock Phase (CPHA)    | 0             |
| SPI Enable            | Enabled       |
| Clock Speed           | FOSC / 64     |

For a 16 MHz system clock:

```text
SPI Clock = 250 kHz
```

---

# Internal Working

This driver uses AVR SPI registers:

| Register | Purpose              |
| -------- | -------------------- |
| SPCR     | SPI Control Register |
| SPSR     | SPI Status Register  |
| SPDR     | SPI Data Register    |

Transmission process:

1. Load data into SPDR register.
2. SPI hardware shifts data serially on MOSI.
3. Clock pulses are generated automatically by the SPI peripheral.
4. Wait for SPIF flag to indicate transmission complete.

---

# Limitations

* Master mode only
* Transmit API only
* No SPI read API
* No interrupt support
* Fixed clock configuration

---

# Design Goal

The library aims to provide:

* Easier SPI programming
* Cleaner application code
* Reusable embedded modules
* Reduced direct register manipulation
* Hardware SPI communication support

---

# Author

**Harish S**

Embedded Systems • AVR Programming • Bare-Metal Development
