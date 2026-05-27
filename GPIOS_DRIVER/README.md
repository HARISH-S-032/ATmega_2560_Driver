# ATmega2560 GPIO Driver

A lightweight GPIO driver for the **ATmega2560** microcontroller developed using **bare-metal C programming**. This library provides reusable APIs for configuring, reading, and controlling GPIO pins and ports through AVR registers.

The driver abstracts low-level register manipulation and simplifies GPIO operations for embedded applications.

---

## Features

✔ Port-level configuration and control  
✔ Pin-level GPIO operations  
✔ Arduino-style digital APIs (`digital_write`, `digital_read`)  
✔ Internal pull-up resistor support  
✔ Direct register access implementation  
✔ Bare-metal AVR programming (No Arduino framework)

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
├── GPIOS_DRIVER/
│   │
│   ├── EXAMPLE/
│   │
│   ├── inc/
│   │      ├── define.h 
│   │      └── gpios.h
│   │
│   ├── src/
│   │      └── gpios.c
│   │
│   └── README.md
```

---

# Available APIs

## GPIO Configuration

### Configure entire port

```c
void port_config(volatile char port , uint8_t data);
```

Configure all pins in a port as INPUT or OUTPUT.

Example:

```c
port_config(porta , OUTPUT);
```

---

### Configure single pin

```c
void pin_mode(uint8_t pin , uint8_t data);
```

Set an individual pin as INPUT or OUTPUT.

Example:

```c
pin_mode(13 , OUTPUT);
```

---

# Write Operations

### Write data to entire port

```c
void port_write(volatile char portx , uint8_t data);
```

Example:

```c
port_write(porta , high);
```

---

### Write data to specific pin

```c
void pin_write(volatile char portx,uint8_t pin,uint8_t data);
```

Example:

```c
pin_write(portf,2,high);
```

---

### Arduino-style write

```c
void digital_write(uint8_t pin , uint8_t data);
```

Example:

```c
digital_write(13 , high);
```

---

# Read Operations

### Read entire port

```c
uint8_t port_read(volatile char portx);
```

Example:

```c
uint8_t value =port_read(portb);
```

---

### Read specific pin

```c
uint8_t pin_read(volatile char portx,uint8_t pin);
```

Example:

```c
uint8_t state =pin_read(portf, 7);
```

---

### Arduino-style read

```c
uint8_t digital_read(uint8_t pin);
```

Example:

```c
uint8_t state =
digital_read(13);
```

---

# Pull-up Resistor Functions

Enable AVR internal pull-up resistors.

---

### Entire Port

```c
void port_pullup(char portx);
```

Example:

```c
port_pullup(portb);
```

---

### Single Pin

```c
void pin_pullup(char portx,uint8_t pin);
```

Example:

```c
pin_pullup(portk, 7);
```

---

### Arduino-style Pull-up

```c
void digital_pullup(uint8_t pin);
```

Example:

```c
digital_pullup(13);
```

---

# Example Usage

Configure pin 13 as output and turn ON LED:

```c
#include "gpios.h"

int main()
{
    pin_mode(13 , OUTPUT);

    while(1)
    {
        digital_write(13 ,high);
    }
}
```

---

# Internal Working

This driver uses AVR GPIO registers:

| Register | Purpose |
|----------|----------|
| DDRx | Configure input/output |
| PORTx | Write output / enable pull-up |
| PINx | Read input |

---

# Design Goal

The library aims to provide:

- Easier GPIO programming
- Cleaner application code
- Reusable embedded modules
- Reduced direct register manipulation

# Author

**Harish S**

Embedded Systems • AVR Programming • Bare-Metal Development
