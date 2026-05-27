# ATmega2560 Seven Segment Driver

A reusable **7-Segment Display Middleware Driver** developed for the **ATmega2560** using bare-metal C. The driver simplifies displaying numeric values on a seven-segment display by abstracting segment control logic into easy-to-use APIs.

This module depends on lower-level GPIO operations and acts as a middleware layer between application code and hardware.

---

## Features

✔ Display numbers (0–9) on 7-segment display  
✔ Support for decimal point (DOT) control  
✔ Lightweight implementation  
✔ Compatible with common cathode/anode configurations (depending on implementation)  
✔ Middleware architecture for embedded projects  

---

## Target Platform

**Microcontroller:** ATmega2560  
**Architecture:** AVR 8-bit  
**Language:** C  

---

## Project Structure

```text
MIDDLEWARE/
│
└── SEVEN_SEGMENT/
      │
      ├── EXAMPLE/
      │
      ├── inc/
      │      └── 7segment.h
      │
      ├── src/
      │      └── 7segment.c
      │
      └── README.md
```

---

# Available APIs

## Display Number

```c
void segment(uint8_t portx, uint8_t data);
```

Displays a numeric value on the connected 7-segment display.

### Example

```c
segment(portb , 7);
```

Output:

```txt
Displays → 7
```

---

## Display Number with Decimal Point

```c
void segment_dot(uint8_t portx, uint8_t data);
```

Displays a value while enabling the decimal point.

### Example

```c
segment_dot(portb , 3);
```

Output:

```txt
Displays → 3.
```

---

# Example Usage

Display numbers continuously:

```c
#include "7segment.h"

int main()
{
    while(1)
    {
        segment(PORTB , 1);
        _delay_ms(1000);
        segment(PORTB , 2);
        _delay_ms(1000);
        segment(PORTB , 3);
    }
}
```

---

# Hardware Connection Example

Typical segment pin mapping:

```txt
Segment    → GPIO Pin
a          → PB0
b          → PB1
c          → PB2
d          → PB3
e          → PB4
f          → PB5
g          → PB6
dp         → PB7
```

Modify according to your circuit design.

---

# Internal Working

The driver converts input numbers into corresponding segment bit patterns and writes them to the configured GPIO port.

Example:

```txt
Input: 2

Segments ON:
a b d e g
```

---

# Dependencies

This middleware relies on:

- GPIO Driver
- AVR register definitions

Ensure GPIO configuration is completed before using the segment driver.



# Design Goal

The objective of this module is to separate display logic from application code, making embedded projects easier to maintain and extend.

---


# Author

**Harish S**

Embedded Systems • AVR Development • Bare-Metal Programming
