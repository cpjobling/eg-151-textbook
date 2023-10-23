---
jupytext:
  formats: md:myst,ipynb
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.2
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

(week6)=
# Interfacing to digital I/O with C

```{image} ../week3/pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

## Introduction

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

 
```{image} ../week3/pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```

### Topics Covered

In this section we will be looking at two different approaches to reading and writing to ports on a microcontroller. The first approach discussed is using library files and predefined functions to control I/O ports as is conventionally done with the Arduino IDE, the second approach will look at accessing I/O bits directly using bit masks to select the desired pins. The section begins by looking at digital inputs and outputs before moving onto to show a detailed example program implemented on the Atmel ATmega328 microcontroller.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### Contents

- How does I/O work using the Arduino IDE.

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

- Bit masking

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

- Digital I/O example using LEDs and push buttons.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk6:arduino_ide)=
## How does I/O work using the Arduino IDE
```{image} pictures/arduino_nano_wallpaper.jpg
:alt: Decorative section background - showing an Arduino nano microcontroller and an LED light strip
```
Image source: [This Photo by Unknown Author is licensed under CC BY-NC](https://www.flickr.com/photos/netlcom/36486445205/)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Digital Control
Imagine a circuit with LEDs connected to `D8` and `D9` of the Atmel ATmega328 microcontroller.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

Both LEDs will be wired to PORTD. How can the LED at `D9` be switched on without changing the state of the LED at `D8`?

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The answer is to use the *pin* functions provided by the Arduino library. These functions allow programmers to gain direct access to particular pins

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

Using the Arduino IDE, the programmer would first define the pin as an output and then use the `digitalWrite` function to write `HIGH` (integer `0x1`) or `LOW` (integer `0x0`) to the pin as required.

```c
void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
}
```

This is because for each "sketch" the Arduino IDE automatically includes a the include file  `Arduino.h` and the library file `wiring_digital.c`[^where_to_find].

[^where_to_find]: `Arduino.h` and `wiring_digital.c` are hidden away in the installation folders for the Arduino IDE. The examples versions shown here are taken from the GitHub repository [github.com/arduino/ArduinoCore-avr](https://github.com/arduino/ArduinoCore-avr)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### The include file Arduino.h

Amongst a number of other definitions[^arduino_h], the `Arduino.h` file contains the declarations for the commonly used digital I/O functions: `pinMode`, `digitalWrite` and `digitalRead` as well as the functions used for Analog I/0: `analogRead`, `analogReference` and `analogWrite` to be discussed in {ref}`week7`. 

```c
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* `pinMode` takes two *unsigned* 8-bit integers as arguments and has return type of void (returns nothing).

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* `digitalWrite` takes two unsigned 8-bit integers as arguments and has return type of void (returns nothing).

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* `digitalRead` takes one unsigned 8-bit integer as an argument and returns a *signed* integer value.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

[^arduino_h]: To see the full contents see: [Arduino.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Arduino.h) on GitHub.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

**Remember the function declaration only tells the compiler about a function's name, return type, and arguments**. 

The actual definition of these functions lies elsewhere in the Arduino core library.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### The library file wiring_digital.c

The [wiring_digital.c](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/wiring_digital.c) file contains the definitions for the pinMode, `digitalWrite` and `digitalRead` functions[^wiring_analog].

[^wiring_analog]: The analog functions are defined in [wiring_analog.c](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/wiring_analog.c).

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Extracts from wiring_digital.c

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

###### [pinMode](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/wiring_digital.c#L29) (line 29)
```c
void pinMode(uint8_t pin, uint8_t mode)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *reg, *out;

	if (port == NOT_A_PIN) return;

	// JWS: can I let the optimizer do this?
	reg = portModeRegister(port);
	out = portOutputRegister(port);

	if (mode == INPUT) { 
		uint8_t oldSREG = SREG;
                cli();
		*reg &= ~bit;
		*out &= ~bit;
		SREG = oldSREG;
	} else if (mode == INPUT_PULLUP) {
		uint8_t oldSREG = SREG;
                cli();
		*reg &= ~bit;
		*out |= bit;
		SREG = oldSREG;
	} else {
		uint8_t oldSREG = SREG;
                cli();
		*reg |= bit;
		SREG = oldSREG;
	}
}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

###### function [digitalWrite](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/wiring_digital.c#L138) (line 138)
```c
void digitalWrite(uint8_t pin, uint8_t val)
{
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *out;

	if (port == NOT_A_PIN) return;

	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	out = portOutputRegister(port);

	uint8_t oldSREG = SREG;
	cli();

	if (val == LOW) {
		*out &= ~bit;
	} else {
		*out |= bit;
	}

	SREG = oldSREG;
}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Advantages and Disadvantages of using the Arduino IDE

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Advantages

* Code is cross processor compatible.
* Code is easy to understand.
* Code controls a named pin on the board and is therefore easy to wire up
* Changing code to use different pins is trivial..

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Disadvantages

* Code is slower than accessing the ports directly.
* You cannot perform multiple bit reads or writes in a single action.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

## Bitmasking

```{image} pictures/arduino_nano_wallpaper.jpg
:alt: Decorative section background - showing an Arduino nano microcontroller and an LED light strip
```
Image source: [This Photo by Unknown Author is licensed under CC BY-NC](https://www.flickr.com/photos/netlcom/36486445205/)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Logical Bitwise Operators

As we saw in {ref}`wk4:bitwise_ops`, there is a group of operators within the C programming language which are referred to as **bitwise logical operators** ({numref}`bitwise-logic-operators`).

```{list-table} The bitwise logic operators
:header-rows: 1
:name: bitwise-logic-operators
* - Logical Operation
  - Operator
* - AND
  - `&`
* - OR
  - `|`
* - XOR
  - `^`
* - NOT
  - `~`
* - Shift right
  - `>>`
* - Shift left
  - `<<`
```

These are important when working with inputs and outputs as they can be used to apply masks to ports (registers) to work with only specific bits[^io_bits].

[^io_bits]: In the case of I/O specific bits refers to individual I/O pins

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Truth tables for the bitwise logical operators.

The truth tables for bitwise logical operators are given for AND (`&`) in {numref}`truth_table_AND`, OR (`|`) in {numref}`truth_table_OR`, XOR (`^`) in {numref}`truth_table_XOR`, and NOT (`^`) in {numref}`truth_table_NOT`.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{list-table} Bitwise AND
:header-rows: 1
:name: truth_table_AND
* - A
  - B
  - Out
* - 0
  - 0
  - 0
* - 0
  - 1
  - 0
* - 1
  - 0
  - 0
* - 1
  - 1
  - 1
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{list-table} Bitwise OR
:header-rows: 1
:name: truth_table_OR
* - A
  - B
  - Out
* - 0
  - 0
  - 0
* - 0
  - 1
  - 1
* - 1
  - 0
  - 1
* - 1
  - 1
  - 1
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{list-table} Bitwise XOR
:header-rows: 1
:name: truth_table_XOR
* - A
  - B
  - Out
* - 0
  - 0
  - 0
* - 0
  - 1
  - 1
* - 1
  - 0
  - 1
* - 1
  - 1
  - 0
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{list-table} Bitwise NOT
:header-rows: 1
:name: truth_table_NOT
* - A
  - Out
* - 0
  - 1
* - 1
  - 0
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Masking

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Masking Example

Consider an example where you want to know if bits 0 and 7 are both on / high / logic 1 but you don't care about any other bits. 

Programmatically, this would be done using an *if* statement with a bitwise *and* operator:

```c
input = 0b10100011;

if (input & 0b10000001 == 0b10000001 ) 
{
	// do something;
}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

If bits 0 and 7 are `HIGH`
```{math}
\begin{array}{lcrr}
\mathrm{Bit\ No.}  & & 7654 & 3210 \\\hline
\mathrm{Input}  &    & \mathbf{1}010 & 001\mathbf{1} \\
\mathrm{Mask}   & \& & 1000 & 0001 \\\hline
\mathrm{Result} &    & 1000 & 0001
\end{array}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

If bits 0 and 7 are `LOW`
```{math}
\begin{array}{lcrr}
\mathrm{Bit\ No.} & & 7654 & 3210 \\\hline
\mathrm{Input}  &    & \mathbf{0}010 & 001\mathbf{0} \\
\mathrm{Mask}   & \& & 1000 & 0001 \\\hline
\mathrm{Result} &    & 0000 & 0000
\end{array}
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

In both examples, it doesn't matter what bits 1-6 are, they don't affect the result.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Let us revisit the task

Imagine a circuit with LED’s connected to D8 and D9 of the Atmel ATmega328 microcontroller.



```{figure} pictures/pins_8_and_9.png
:alt: Schematic of Arduino nano board identifying pins D8 and D9.
:name: wk6:fig:pins_8_and_9
:width: 50%

Schematic of Arduino nano board identifying pins D8 and D9[^d8_and_d9].
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

How can the LED at `D9` be switched on without changing the state of the LED at `D8`?

[^d8_and_d9]: are bits 0 and 1 respectively of Port B.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Atmel ATmega328 I/0 Architecture Recap

```{image} pictures/io_map.png
:alt: Arduino ATmega328 Memory map for I/O
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Recall:

Three I/O memory address locations are allocated for each port, one each for the *Data Register* – `PORTx`, *Data Direction Register* – `DDRx`, and the *Port Input Pins* – `PINx`, where `x` refers to the numbering letter for the port (`B`, `C` or `D` in our case).

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Solution with bit masking

Imagine a circuit with LED’s connected to D8 and D9 of the Atmel ATmega328 microcontroller.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

How can the LED at `D9` be switched on without changing the state of the LED at `D8`?

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* `D8 = PortB0`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* `D9 = PortB1`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

Let us assume Port B currently reads $1010\,0001$ and we execute[^shortcut]:

```c
PORTB = PORTB | 0x00000010;
```

[^shortcut]: Idiomatic C often uses the shortcut `PORTB |= 0x00000010;` There are many such *assignment operators* in C. For example: `+=`, `-=`, `&=` etc. They all mean the same thing: `var = var op argument`. Internally, the C compiler treats both forms the same so their use is a matter of style. The full version is easier to read and understand. The shortcut is quicker to type, but arguably less easy to read and understand. 

```{math}
\begin{array}{lrrl}
  & 1010 & 0001 & \mathrm{Port\ B}\\
| & 0000 & 0010 & \mathrm{Bitmask\ for\ D9} \\ \hline
  & 1010 & 00\mathbf{1}1 & \mathrm{D9\ is\ on}
\end{array}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

To turn but 9 off, we use the logical AND.

```c
PORTB = PORTB & 0x11111101;
```

```{math}
\begin{array}{lrrl}
  & 1010 & 0001 & \mathrm{Port\ B}\\
\& & 1111 & 1101 & \mathrm{Bitmask\ for\ D9} \\ \hline
  & 1010 & 00\mathbf{0}1 & \mathrm{D9\ is\ off}
\end{array}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

## Digital I/O Example Program

```{image} pictures/breadboard_wallpaper.jpg
:width: 75%
:alt: Decorative background image showing the circuit discussed in the example.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example - breadboard

Consider the Ardunino nano circuit shown in {numref}`wk6_fig_example_circuit`. The left and right push buttons are connected to the digital inputs `D3` and `D2` on the Arduino nano board. These correspond with Port D Bits 3 and 2 on the Atmega328 microcontroller. 

```{figure} pictures/breadboard.jpg
:alt: A photograph of the example circuit which has two buttons and two LEDs.
:name: wk6_fig_example_circuit
:width: 50%

A photograph of the example circuit which has two buttons and two LEDs. When the left button is pressed, the red LED lights up. When the right button is pressed the green LED lights up.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

When the left push button is pressed, the red LED (Port B Bit 1) is illuminated and the green LED (Port B Bit 0) illuminated when the right push button is pressed.

The buttons are digital inputs with pull-up resistors (so *active low*) and are connected to pins 1 and 2 of port D respectively.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

What does the code for this look like without using the predefined Arduino functions – `pinMode` and `digitalRead`?

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example Code - statement 1

```c
#include <stdint.h>
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

`#include` is a **preprocessor directive** used to **include header files** which contain **definitions and declarations** of existing and frequently used functions.

The **<>** variant is used for **system header files** that are included as part of the C language compiler.

 The *stdint.h* header file provides a set of **type definitions (typedefs)** that specify exact-width integer types, together with the defined minimum and maximum allowable values for each type, using macros. The types are tabulated in {numref}`integer_types`.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```{list-table} Specific integral type limits
:header-rows: 1
:name: integer_types
* - **Specifier**
  - **Signing**
  - **Bits**
  - **Bytes**
  - **Minimum Value**
  - **Maximum Value**
* - `int8_t`
  - Signed
  - 8
  - 1
  - $-2^7$ which equals $-128$
  - $2^7 - 1$ which equals $127$
* - `uint8_t`
  - Signed
  - 8
  - 1
  - $0$
  - $2^8 - 1$ which equals $255$
* - `int16_t`
  - Signed
  - 16
  - 2
  - $-2^7$ which equals $-32,768$
  - $2^7 - 1$ which equals $32,767$
* - `uint16_t`
  - Signed
  - 16
  - 2
  - $0$
  - $2^{16} - 1$ which equals $65,535$
* - `int32_t`
  - Signed
  - 32
  - 4
  - $-2^{31}$ which equals $-2,147,483,648$
  - $2^{31} - 1$ which equals $2,147,483,647$
* - `uint32_t`
  - Signed
  - 32
  - 4
  - $0$
  - $2^{32} - 1$ which equals $4,294,967,295$
* - `int64_t`
  - Signed
  - 64
  - 8
  - $-2^{63}$ which equals $-9,223,372,036,854.775,808$
  - $2^{63} - 1$ which equals $9,223,372,036,854.775,807$
* - `uint32_t`
  - Signed
  - 32
  - 4
  - $0$
  - $2^{64} - 1$ which equals $18,446,744,073,709,551,615$
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example code - aligning port names to the I/O memory map

The I/O memory map is shown in {numref}`wk6:fig:io_mem_map`. 

```{figure} pictures/io_mem_map.png
:name: wk6:fig:io_mem_map
:align: center
:width: 100%
:alt: Memory map for the I/O ports in the Atmel ATmega328

Memory map for the I/O ports in the Atmel ATmega328
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

We need to map a port to the address used by the port. We use `#define` for this:

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

1. Preprocessor directive: `#define`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

2. Convenient name that the processor can use in code: `PORTD`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

3. The size is an 8 bit unsigned integer: `unit8_t`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

4. Memory address of the specific register from the datasheet (reproduced here as {numref}`wk6:fig:io_mem_map`): `0x2B`.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The full command is[^volatile]:

```c
#define PORTD(*(volatile unint8_t *)(0x2B))
```

[^volatile]: In this definition we use the qualifier volatile to inform the compiler that the variable value can be changed any time without any task given by the source code. Without this qualifier, depending on the optimisation level of the compiler this may result in code that doesn’t work as it doesn’t know the value can be changed by external sources. The asterisk symbol is used to denote a pointer, for now you do not need to know what this explicitly mean but in short a pointer is a variable whose value is the address of another variable, i.e., direct address of the memory location rather than a value.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

The full set up which sets up the ports, data direction registers and pins is:

```c
//I/O and ADC Register definitions taken from datasheet
#define	PORTD (*(volatile uint8_t *)(0x2B))
#define DDRD  (*(volatile uint8_t *)(0x2A))
#define PIND  (*(volatile uint8_t *)(0x29))

#define PORTB (*(volatile uint8_t *)(0x25))
#define DDRB  (*(volatile uint8_t *)(0x24))
#define PINB  (*(volatile uint8_t *)(0x23))
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example Code - the main function

This is the starting point for any program[^main].

```c
int main (void) 
{
    // code
    return 0;
}
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

The return type is declared as integer meaning the function returns some integer even ‘0’ at the end of the program execution. By convention, a return of ‘0’ represents the successful execution of a program.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example Code - Set data direction registers

```{image} pictures/dd.gif
:alt: Video illustrating the setting up of the data direction regsisters.
:width: 100%
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example Code - Set pull-ups for inputs and initialize outputs

```{image} pictures/pullup.gif
:alt: Video illustrating the setting of the port D for input and resetting port B.
:width: 100%
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example Code - The infinite for loop

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

The **infinite *for* loop** is quite a common idiom in C:
```c
for (;;;)
{
   // code that repeats forever
}
```

Any code that is placed inside the for loop will run forever.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

The Arduino IDE does the same thing behind the scenes - `void loop` is actually a function that is repeatedly called inside an infinite for loop[^main].

[^main]: The actual code is slightly different and if you are interested you can access it here: [main.cpp](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/main.cpp). Note that the sketch function `init()` is called once first, then `loop()` is called each time through the infinite loop.
:

```c
int main(void)
{
  init();
    
  for (;;) {
	loop();
  }
        
  return 0;
}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example Code - Reading the button

This *if* statement is at the heart of the program. Each time though the loop it tests the condition of bit 2 in the `PIND` register (`D3`). The pin linked to this bit has been configured as an input with the pull-up resistor enabled and it has been wired to the left button. This means the default state is 1 (`HIGH`) and pressing the button will ground the input to 0 (`LOW`).

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

 We then use a bit mask to query bit 2 only, and if the result is zero, we turn on bit 1 of `PORTB` - which illuminates the red LED.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

 ```c
if ((PIND & 0b00000100) == 0)
{
    PORTB = 0b00000001; // Sets port B, bit 0 to logic 1/high which switches the LED connected to D8 on.
}
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```{image} pictures/buttons.gif
:alt: Video showing how the state of the buttons is interogated using bit masks.
:width: 100%
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

Similar code is used to test the left button on `PORTD` pin 3 to illuminate the green LED on `PORTB` pin 0. See if you can write this code.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### The full program

The full program is available as a GitHub gist: [main.c](https://gist.github.com/cpjobling/07585093f8eafe69a4eeff1186110883). You will need a fully featured IDE, such as [Atmel (now Microchip) Studio](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio), to compile and upload the code to the Ardino nano board.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

## Summary

In this section we have:

* Begun to look at I/O operations on the Atmel Atmega 328 microcontroller including the registers and checking/setting states based on flow control statements.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* Introduced bit masking to read/write individual bits of a register without affecting the remainder of it.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* Looked at a detailed example program which uses the state of two pushbuttons to set whether an LED is illuminated or not.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### On Canvas

This week on the [canvas course page](https://canvas.swansea.ac.uk/courses/44971/pages/direct-port-manipulation-in-c), you will find the sample programs from today's lecture, look through these and ensure you are confident in how they work and how the masks are defined. There is also a short quiz to test your knowledge on these topics.
