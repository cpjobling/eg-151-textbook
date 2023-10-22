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
# Interfacing with digital I/O in C

```{image} ../week3/pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

 
```{image} ../week3/pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```

## Lecture Topics

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
}```

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

```{image} pictures/mem_map.png
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

+++ {"editable": true, "slideshow": {"slide_type": ""}}

### Example

## Summary


## On Canvas

```{code-cell} ipython3
---
editable: true
slideshow:
  slide_type: ''
---

```
