# ATmega2560 Bare-Metal Driver Library

A collection of reusable embedded drivers developed for the **ATmega2560** microcontroller using **bare-metal C programming**.

This project provides lightweight hardware abstraction libraries for GPIO, UART, SPI, software communication protocols, timers, and middleware utilities without relying on the Arduino framework.

The primary goal of this project is to build a modular embedded software stack while gaining a deeper understanding of AVR peripherals through direct register-level programming.

---

## Features

* GPIO Driver
* Hardware UART Driver
* Software UART (Bit-Banging)
* Hardware SPI Driver
* Software SPI (Bit-Banging)
* Timer Utilities
* Middleware Support Modules
* Bare-Metal AVR Development
* Direct Register Access
* Reusable Embedded Components

---

## Supported Hardware

**Microcontroller:** ATmega2560

**Architecture:** AVR 8-bit

**Programming Language:** C

**Development Style:** Bare-Metal Programming

---

## Project Structure

```text
ATMEGA_2560/
│
├── GPIOS_DRIVER/
│   ├── inc/
│   ├── src/
│   └── README.md
│
├── SPI/
│   ├── inc/
│   ├── src/
│   └── README.md
│
├── SPI_BITBANGING/
│   ├── inc/
│   ├── src/
│   └── README.md
│
├── UART/
│   ├── inc/
│   ├── src/
│   └── README.md
│
├── UART_BITBANGING/
│   ├── inc/
│   ├── src/
│   └── README.md
│
├── TIMER/
│   ├── inc/
│   ├── src/
│   └── README.md
│
├── MIDDLEWARE/
│
├── DATASHEET.pdf
│
└── README.md
```

---

# Available Modules

## GPIO Driver

Provides APIs for:

* Port configuration
* Pin configuration
* Digital read/write operations
* Internal pull-up support

### Features

* Port-level control
* Pin-level control
* Arduino-style APIs
* Direct AVR register access

---

## UART Driver

Hardware USART driver supporting:

* USART0
* USART1
* USART2
* USART3

### Features

* Baud rate configuration
* Character transmission
* String transmission
* Character reception

---

## UART Bit-Banging Driver

Software UART implementation using GPIO.

### Features

* User-defined TX pin
* UART frame generation
* Software serial transmission
* No hardware USART required

---

## SPI Driver

Hardware SPI implementation using AVR SPI peripheral.

### Features

* Master mode support
* Byte-wise transmission
* Hardware clock generation

---

## SPI Bit-Banging Driver

Software SPI implementation using GPIO.

### Features

* Software clock generation
* Master mode operation
* Byte-wise transmission
* No hardware SPI required

---

## Timer Module

Provides timer-based utilities for embedded applications.

### Features

* Delay generation
* Time-based operations
* AVR timer utilization

---

## Middleware

Common reusable software utilities used across multiple drivers.

### Features

* Driver support functions
* Shared utilities
* Platform abstraction helpers

---

# Design Goals

This project was created to:

* Learn low-level AVR programming
* Understand peripheral register architecture
* Build reusable embedded software modules
* Reduce repetitive code across projects
* Develop production-style driver architecture
* Strengthen embedded systems fundamentals

---

# Development Approach

All drivers are implemented using:

* Direct register manipulation
* AVR datasheet references
* Bare-metal programming techniques
* Modular software design

No Arduino libraries or frameworks are used.

---

# Future Enhancements

Planned additions:

* I2C (TWI) Driver
* ADC Driver
* PWM Driver
* Interrupt Management Library
* External Interrupt Driver
* Watchdog Timer Support
* RTOS Integration Examples

---

# Author

**Harish S**

Embedded Systems Engineer

Areas of Interest:

* Embedded Systems
* Bare-Metal Firmware Development
* Device Driver Development
* AVR Microcontrollers
* ARM Cortex-M Microcontrollers
* RTOS
* Embedded Linux

---

## License

This project is open-source and intended for educational and learning purposes.
