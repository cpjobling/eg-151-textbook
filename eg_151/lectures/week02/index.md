---
jupytext:
  formats: ipynb,md:myst
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

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(week02)=
# Architecture of the Atmel ATmega 328 Microcontroller

```{image} pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

## Lecture Topics

```{image} pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```

- {ref}`week02:intro`
- {ref}`week02:status_register`
- {ref}`week02:program_counter`
- {ref}`week02:stack_pointer`
- {ref}`week02:io`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(week02:intro)=
## Introducing the Atmel ATmega 328 MCU

In {ref}`week1` we described what a microcontroller is and looked at how one can be described by considering its architecture. We finished the lecture looking at {numref}`week02:fig:atmel_arch` which provides an overview of the AVR core architecture and we introduced the general purpose registers and the ALU.


```{figure} pictures/atmel_arch.png
:name: week02:fig:atmel_arch
:align: center
:width: 50%
:alt: The architecture of the Atmel ATMega328 Microcontroller

The architecture of the Atmel ATMega328 Microcontroller
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

- This is an 8-bit CMOS microcontroller based on the AVR enhanced **RISC architecture** with 131 instructions

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- It has 2KB of Internal SRAM, 32 KB of Flash Memory and 1 KB of EEPROM

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- It has **32 General Purpose Registers**

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- It can achieve up to 20 MIPS at 20 MHz (maximum clock frequency)

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- There are **8 Analog I/O Pins** connected to 10-bit ADC

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- There are **22 Digital I/O Pins** (6 capable of PWM)

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- The AVR core uses a **Harvard memory  architecture** – with separate memories and buses for program and data.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(week02:status_register)=
## The Status Register

```{image} pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### What is The status register?

- An 8-bit register containing flags that contain information about the result of the most recently executed instruction and the current **state of the processor** ({numref}`week02:fig1:sreg`).
- The status register is updated after all ALU instructions as specified by the instruction set reference.

```{figure} pictures/sreg.png
:alt: SREG - The AVR Status Register
:name: week02:fig1:sreg
:width: 75%

SREG - The AVR Status Register
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{figure} pictures/AVR-instruction.png
:alt: Example instruction showing how the status register is affected
:name: week02:fig1:sreg-setting

Example instruction showing how the status register is affected
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Status Register Flags

```{list-table} 
* - **Bit 0 - Carry Flag (C)**: 
  - The carry flag is set when the execution of the previous arithmetic or logic instruction produced a carry out of bit-7 or required a borrow
* - **Bit 1 – Zero Flag (Z)**:
  - The zero flag is set when the result of the previous arithmetic or logic instruction resulted in a zero
* - **Bit 2 – Negative Flag (N)**:
  - The negative flag is set when the result of the previous arithmetic or logic instruction is negative
* - **Bit 3 – Two’s Complement Overflow Flag (V)**:
  - The Two’s Complement Overflow Flag V supports two’s complement arithmetic. +ve + +ve = -ve  or  -ve + -ve = +ve
* - **Bit 4 – Sign Bit (S)**:
  - The S-bit is always an exclusive or between the Negative Flag and the Two’s Complement Overflow Flag.
* - **Bit 5 – Half Carry Flag (H)**:
  - The half carry flag is set when the execution of the previous arithmetic or logic instruction produced a carry out of bit-3 or required a borrow from bit-4.
* - **Bit 6 – Bit Copy Storage (T)**:
  - A bit from a register in the Register File can be copied into T by the BST instruction, and a bit in T can be copied into a bit in a register in the Register File by the BLD instruction.
* - **Bit 7 – Global Interrupt Enable (I)**:
  - The Global Interrupt Enable bit is set to enable interrupts. The individual interrupt enable control is then performed in separate control registers.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Status Register Example
```{image} pictures/sreg-example.png
:alt: An example of how the status register works
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Status Register Demonstration

Code to be executed
```
LDI R16, Addend
LDI rR17, Augend
ADD R16, R17
```

```{image} pictures/status-reg.png
:alt: Status register
:width: 50%
```

Record status of SREG at line 3.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Examples

$$\begin{array}{lrr}
\mathrm{Addend} & 0\,1\,1\,0\,1\,1\,1\,0 & 110_{10}\\
\mathrm{Augend} & 1\,1\,1\,0\,0\,0\,1\,1 & 227_{10}\\
\hline
\mathrm{Sum} & &
\end{array}$$

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

$$\begin{array}{lrr}
\mathrm{Addend} & 0\,0\,1\,1\,0\,1\,1\,1 & 55_{10}\\
\mathrm{Augend} & 0\,1\,0\,1\,0\,0\,0\,0 & 80_{10}\\
\hline
\mathrm{Sum} & &
\end{array}$$

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

$$\begin{array}{lrr}
\mathrm{Addend} & 1\,0\,0\,0\,0\,0\,0\,0 & 128_{10}\\
\mathrm{Augend} & 1\,0\,0\,0\,0\,0\,0\,0 & 128_{10}\\
\hline
\mathrm{Sum} & &
\end{array}$$

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(week02:program_counter)=
## The program counter

```{image} pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### What is The Program Counter?

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* A program is a sequence of instructions written in a particular order to perform a specific task

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* The instructions of the program are stored sequentially in non-volatile memory.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* The program counter is a register which holds the address of the next instruction to be executed

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example of a program
{numref}`week02:fig:a_program` illustrates a simple program to add two numbers. 

```{figure} pictures/pc_example.png
:name: week02:fig:a_program
:alt: An example programme showing three instructions located at memory locations 0 through 2.
:width: 30%

An example programme showing three instructions located at memory locations 0 through 2.
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

It is written in assembly code for the Atmel ATmega328 MCU. Each instruction is a programmer-friendly rendition of an 16- or 32-bit binary code that is stored at the memory locations shown.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Organisation of program memory

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* The ATmega328 microcontroller has a 32 Kbyte flash memory which is organised into 256 pages each containing 64 Words of program.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* The program counter is 14-bits and can access each of these memory locations `0x0000` – `0x3FFE`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* The remaining addresses `0x3FFF` – `0x7FA5` (the boot flash section) are reserved for the bootloader

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

{numref}`week02:fig:prog_mem` illustrates the organisation of the program memory for the ATmega328.

```{figure} pictures/prog_mem.png
:name: week02:fig:prog_mem
:alt: The program memory of the ATmega328 microcontroller
:width: 30%

The program memory of the ATmega328 microcontroller
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Remember a word is 16 bits

64 (words) = 128 bytes

256 (pages) each of 128 bytes = 32 KB (or decimal 32768 / binary 32678)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

{numref}`week02:fig:prog_counter` shows how the program counter is used to access the next instruction.

```{figure} pictures/prog_counter.png
:alt: How the program counter is used to access instructions within the available pages of program memory.
:width: 60%
:name: week02:fig:prog_counter

How the program counter is used to access instructions within the available pages of program memory.
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

The Least significant six bits address the instruction words within a given page. Note: $2^6 = 64$ words which is $128$ bytes.

The 8 most significant bits address the *page* in programme memory in which the instruction word is to be found. Note: $2^8 = 256$ and that $256 \times 64 \times 2 = 32,768$ bytes.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

### The Bootloader
In short, microcontrollers are usually programmed through a programmer (specialist piece of hardware) unless you have a piece of firmware in your microcontroller that allows installing new firmware without the need of an external programmer. This small piece of firmware is called a bootloader and can allow the program to be rewritten by the microcontroller itself e.g. via an over-the-air (OTA) updates.

The bootloader also contains the reset routine (power-on-reset)

During reset, all I/O Registers are set to their initial values, and the program starts execution from the Reset Vector. For the ATmega168A/168PA/328/328P family of microcontrollers, the instruction placed at the Reset Vector must be a JMP – Absolute Jump – instruction to the reset handling routine.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Program Counter Demonstration

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(week02:stack_pointer)=
## The Stack Pointer

```{image} pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### The Stack

In a microcontroller, the ‘stack’ is a space in memory with a fixed origin and a variable size that can be used for temporary storage purposes, such as storing local variables and saving return address for subroutine calls and interrupts.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The stack supports two types of operations:

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

1. Push – a data item is placed at the location pointed to by the stack pointer

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

2. Pop or Pull – a data item at the current location pointed to by the stack pointer is removed.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The stack typically operates as a “Last In First Out” (LIFO) buffer

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### What is the stack pointer?

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The *stack pointer register* keeps track of the top of the stack.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* A stack `PUSH` command will decrement the stack pointer.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* A stack `POP` command will increment the stack pointer.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

The AVR stack pointer is implemented as two 8-bit registers in the I/O space.

The are called `SPH` (stack pointer high byte) and `SPL` (stack pointer low byte) as illustrated in {numref}`week02:fig:sp_register`.


```{figure} pictures/sp_register.png
:name: week02:fig:sp_register
:align: center
:width: 75%
:alt: The AVR stack pointer implemented as two bytes SPH and SPL.

The AVR stack pointer implemented as two bytes SPH and SPL.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

{numref}`week02:fig:sp_operation` illustrates the operation of the stack pointer as it appears to the user of the stack.

```{figure} pictures/sp_operation.png
:name: week02:fig:sp_operation
:align: center
:width: 50%
:alt: Illustration of the operation of a stack.

Illustration of the operation of a stack.
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Like a box of Pringles, when you pop an item of the stack, it comes from the top. The pringle below the one you have just taken off becomes the new top. If you were to put the Pringle back, it becomes the new top. When the pringles box is empty, there is nothing on the stack and the stack pointer will be pointing at the memory address of the bottom of the stack.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(week02:io)=
## Introduction to Microcontroller I/O

```{image} pictures/mc_io_wallpaper.png
:alt: Image of a microcontroller used as chapter heading heading for MC I/O Sectiom
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers))

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### I/O on the ATmega328

{numref}`week02:fig:arduino_nano` illustrates the layout of the input-output (I/O) pins of the Atmel ATmega328 packaged as an Arduino Nano that you will be using in the lab and project.


```{figure} pictures/arduino_nano.png
:name: week02:fig:arduino_nano
:align: center
:width: 50%
:alt: Input/output pins for the Arduino nano

Input/output pins for the Arduino nano
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

{numref}`week02:fig:atmega325_schematic` is the schematic diagram of the Atmel ATmega328 reproduced from the reference manual.


```{figure} pictures/atmega325_schematic.png
:name: week02:fig:atmega325_schematic
:alt: Schematic diagram showing the I/O provided by the Atmel ATmega328 microcontroller
:width: 50%

Schematic diagram showing the I/O provided by the Atmel ATmega328 microcontroller
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### MCU Inputs

Consider a switch which on one side is connected to a 5V power source and on the other side to a microntroller input.

![](pictures/switch.png)

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

What voltage is read at the I/O port when the switch is closed and when it is open?

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Pull Ups

To get around this issue, microcontrollers use pull-up (or pull-down) circuitry to hold the port high (or low) (see {numref}`week02:fig:pullup`).

```{figure} pictures/pullup.png
:name: week02:fig:pullup
:alt: Schematic of the pullup circuitry for the ATmega328 (from the manual).
:width: 50%

Schematic of the pullup circuitry for the ATmega328 (from the manual).
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

What voltage is read at the I/O port when the switch 'S1' is closed and when it is open now?

```{image} pictures/pu_enabled.png
:alt: port with pull-up enabled
:width: 50%
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Ports as General Digital I/O

```{figure} pictures/general_io.png
:name: week02:fig:general_io
:alt: The PORTC register
:width: 75%

The `PORTC` register
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

The ports are bi-directional I/O ports with optional internal pull-ups meaning they can be configured to read an input such as a switch or a sensor or to write to an output such as an LED or control an actuator. {numref}`week02:fig:general_io` shows a functional description of one I/O-port pin, which we give the notation `Pxn`.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Configuring a pin

```{figure} pictures/iomap.png
:name: week02:fig:iomap
:alt: A portion of the memory map of the Atmel ATmega328 showing the location of the I/O registers.
:width: 750%

A portion of the memory map of the Atmel ATmega328 showing the location of the I/O registers.
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Recall the 64 I/O registers early on in the user data space (see {numref}`week02:fig:iomap`):

* General purpose registers – `0x0000` – `0x001F`
* Three I/O memory address locations are allocated for each port, one each for:
    *  the *Data Registers* – `PORTx`,
    *  the *Data Direction Register* – `DDRx`, and
    *  the *Port Input Pins* – `PINx`

Note: `x` refers to the numbering letter for the port (`B`, `C`, or `D` in our case).e)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Configuring a Pin - Data Direction

The `DDxn` bit in the `DDRx` Register (illustrated for `DDRB` in {numref}`week02:fig:ddrb`) selects the data direction (input or output) of this pin.

```{figure} pictures/ddrb.png
:name: week02:fig:ddrb
:alt: DDRB - The port B data direction register.
:width: 75%

`DDRB` - The port B data direction register.
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

* Writing **logic one** to `DDxn`, `PORTxn` is configured as an **output pin**.
* Writing **logic zero** to `DDxn`, `PORTxn` is configured as an **input pin**. .

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Writing to a Pin - Output

The `Pxn` bit in the `PORTx` Register (illustrated for `PORTC` in {numref}`week02:fig:portc`) has two purposes dependent on the condition of the corresponding bit in the `DDRx` register. 


```{figure} pictures/portc.png
:name: week02:fig:portc
:alt: PORTC - the port C data register
:width: 75%

`PORTC` - the port C data register
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

If the `DDRx` bit is configured as an output:

* Writing logic one to `PORTxn` drives the pin high (on-state).
* Writing logic zero to `PORTxn` to logic zero drives the pin low (off-state).

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Reading from a Pin - Input

The port pin can be read through the **`PINxn` Register bit** (illustrated for `PINB` in {numref}`week02:fig:pinb`. 

```{figure} pictures/pinb.png
:name: week02:fig:pinb
:alt: PINB - the port B input pins address
:width: 75%

`PINB` - the port B input pins address
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

This is independent of the setting of Data Direction bit `DDxn`, however is good practice to have it set.

**Writing** a logic one to `PINxn` toggles the value of `PORTxn`, independent on the value of `DDRxn`.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Configuring a Pin - Pull Up Enable

Providing a port is configured as an input.

* If `PORTxn` is written **logic one** when the pin is configured as an input pin, the **pull-up resistor** is activated.

* To switch the **pull-up resistor** off, `PORTxn` has to be written logic zero or the pin has to be configured as an output pin.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Basic I/O Demonstration

```{image} pictures/ide_for_demo.png
:alt: Screen shot of the Atmel IDE taken during the rehersal for the demo of I/O.
:width: 50%
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

## Summary

In this chapter we have:

* Introduced a few more parts of the AVR core, namely, the status register, program counter and stack pointer and how these are used under normal operation

* Started  to look at I/O on a microcontroller including the concept of pull up resistors as well as some of the specific registers used in the AVR core to enable the use of both input and output device

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### On Canvas

Canvas module [Week 2: Microcontroller Architecture and I/O](https://canvas.swansea.ac.uk/courses/44971/modules/305537?wrap=1), along with these notes, there is some additional self study material on canvas on page [Week 2: Atmel ATmega328 Architecture Overview](https://canvas.swansea.ac.uk/courses/44971/pages/week-3-atmel-atmega328-architecture-overview?module_item_id=2258072). This includes a video demonstration, from my former colleague Ben Clifford, of the various topics discussed in this session. 

There is also a quiz on Microcontroller Architecture.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Any Questions?

### Next time

* {ref}`week03`
