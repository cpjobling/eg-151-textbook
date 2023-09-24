---
jupytext:
  formats: ipynb,md:myst
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

+++ {"slideshow": {"slide_type": "slide"}}

(week3)=
# Architecture of the Atmel ATmega 328 Microcontroller

```{image} pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

+++ {"slideshow": {"slide_type": "slide"}}

## Lecture Topics

```{image} pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```

- {ref}`week3:intro`
- {ref}`week3:status_register`
- {ref}`week3:program_counter`
- {ref}`week3:stack_pointer`
- {ref}`week3:io`

+++ {"slideshow": {"slide_type": "slide"}}

(week3:intro)=
## Introducing the Atmel ATmega 328 MCU

In {ref}`week1` we described what a microcontroller is and looked at how one can be described by considering its architecture. We finished the lecture looking at {numref}`week3:fig:atmel_arch` which provides an overview of the AVR core architecture and we introduced the general purpose registers and the ALU.


```{figure} pictures/atmel_arch.png
:name: week3:fig:atmel_arch
:align: center
:width: 50%
:alt: The architecture of the Atmel ATMega328 Microcontroller

The architecture of the Atmel ATMega328 Microcontroller
```

+++ {"slideshow": {"slide_type": "slide"}}

- This is an 8-bit CMOS microcontroller based on the AVR enhanced **RISC architecture** with 131 instructions

+++ {"slideshow": {"slide_type": "fragment"}}

- It has 2KB of Internal SRAM, 32 KB of Flash Memory and 1 KB of EEPROM

+++ {"slideshow": {"slide_type": "fragment"}}

- It has **32 General Purpose Registers**

+++ {"slideshow": {"slide_type": "fragment"}}

- It can achieve up to 20 MIPS at 20 MHz (maximum clock frequency)

+++ {"slideshow": {"slide_type": "fragment"}}

- There are **8 Analog I/O Pins** connected to 10-bit ADC

+++ {"slideshow": {"slide_type": "fragment"}}

- There are **22 Digital I/O Pins** (6 capable of PWM)

+++ {"slideshow": {"slide_type": "fragment"}}

- The AVR core uses a **Harvard memory  architecture** – with separate memories and buses for program and data.

+++ {"slideshow": {"slide_type": "slide"}}

(week3:status_register)=
## The Status Register

```{image} pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"slideshow": {"slide_type": "slide"}}

### What is The status register?

- An 8-bit register containing flags that contain information about the result of the most recently executed instruction and the current **state of the processor** ({numref}`week3:fig1:sreg`).
- The status register is updated after all ALU instructions as specified by the instruction set reference.

+++ {"slideshow": {"slide_type": "slide"}}

```{figure} pictures/sreg.png
:alt: SREG - The AVR Status Register
:name: week3:fig1:sreg

SREG - The AVR Status Register
```

+++ {"slideshow": {"slide_type": "slide"}}

```{figure} pictures/AVR-instruction.png
:alt: Example instruction showing how the status register is affected
:name: week3:fig1:sreg-setting

Example instruction showing how the status register is affected
```

+++ {"slideshow": {"slide_type": "slide"}}

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

+++ {"slideshow": {"slide_type": "slide"}}

### Status Register Example
```{image} pictures/sreg-example.png
:alt: An example of how the status register works
```

+++ {"slideshow": {"slide_type": "slide"}}

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

+++ {"slideshow": {"slide_type": "slide"}}

#### Examples

$$\begin{array}{lrr}
\mathrm{Addend} & 0\,1\,1\,0\,1\,1\,1\,0 & 110_{10}\\
\mathrm{Augend} & 1\,1\,1\,0\,0\,0\,1\,1 & 227_{10}\\
\hline
\mathrm{Sum} & &
\end{array}$$

+++ {"slideshow": {"slide_type": "slide"}, "jupyterlab-deck": {"layer": "fragment"}}

$$\begin{array}{lrr}
\mathrm{Addend} & 0\,0\,1\,1\,0\,1\,1\,1 & 55_{10}\\
\mathrm{Augend} & 0\,1\,0\,1\,0\,0\,0\,0 & 80_{10}\\
\hline
\mathrm{Sum} & &
\end{array}$$

+++ {"slideshow": {"slide_type": "fragment"}}

$$\begin{array}{lrr}
\mathrm{Addend} & 1\,0\,0\,0\,0\,0\,0\,0 & 128_{10}\\
\mathrm{Augend} & 1\,0\,0\,0\,0\,0\,0\,0 & 128_{10}\\
\hline
\mathrm{Sum} & &
\end{array}$$

+++ {"slideshow": {"slide_type": "slide"}}

(week3:program_counter)=
## The program counter

```{image} pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"slideshow": {"slide_type": "slide"}}

(week3:stack_pointer)=
## The Stack Pointer

```{image} pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"slideshow": {"slide_type": "slide"}}

(week3:io)=
## Introduction to Microcontroller I/O

```{image} pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

```{code-cell} ipython3

```
