---
jupytext:
  formats: ipynb,md:myst
  main_language: python
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

(week08)=
# Microcontroller Architecture – Program Operation

```{image} ../week02/pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} ../week02/pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```

## Introduction
In {ref}`week02`, we discussed  some of the core components of a microcontrollers architecture including the general purpose registers, status register, program counter and stack pointers. Aside from the program counter these are registers which the programmer can directly access and manipulate. In this section, we will look at some of the other components in the microcontroller CPU including the control unit, clock, memory address register, memory data register, instruction register and decoder. After introducing these components an example program will be demonstrated that is written in C language, showing the translation to assembly language using the listing file followed by an explanation of how the program is executed through the fetch-decode-execute cycle.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Contents

* {ref}`wk8:sect1`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk8:sect2`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk8:sect3`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk8:sect4`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk8:sect1)=
## Architecture recap

```{image} ../week02/pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Arithmetic Logic Unit (ALU)

The Arithmetic Logic Unit (ALU) ({numref}`wk8:fig:alu`), is the part of the processor that performs arithmetic and logic operations on data from the storage area. 

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Memory is used to store data and information but the real goal of the MCU is computation or manipulating data in a structured and purposeful way, like adding two numbers together. These operations are handled by the ALU which is the numerical and logical brain of the MCU. The Atmel ATmega328 has an 8-bit ALU which takes two 8-bit inputs, an opcode describing the operation to perform and outputs an 8-bit result along with a series of 1-bit flags which we can access through the status register.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```{figure} pictures/ALU.png
:name: wk8:fig:alu
:align: center
:width: 50%
:alt: The arithmetic logic unit

The arithmetic logic unit (ALU)
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}, "jp-MarkdownHeadingCollapsed": true}

First, data are read from storage into the ALU’s data input ports. Once inside the ALU, they’re modified by means of an arithmetic or logic operation (`ADD`, `SUB`, `AND`, `OR` ...), and then they’re written back to storage via the ALU’s output port.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}, "jp-MarkdownHeadingCollapsed": true}

Depending on the result of the computation, certain flags in the status register will be set or unset.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}, "jp-MarkdownHeadingCollapsed": true}

To illustrate this, here is the reference manual entry for the **add without carry** operator (`ADD`)

```{image} pictures/add_op.png
:alt: Add without carry operator
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### The CPU Core

The CPU core of the Atmel ATmega328 microcontroller is illustrated in {numref}`wk8:fig:cpu_core`.

```{figure} pictures/cpu_core.png
:name: wk8:fig:cpu_core
:align: center
:width: 100%
:alt: The CPU core with programme counter, status and control register, general registers, and ALU highlighted.

The CPU core of the Atmel ATmega328 microcontroller with *program counter*, *status and control register*, *32 general registers*, and *ALU* highlighted.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}, "jp-MarkdownHeadingCollapsed": true}

The highlighted components are:

**General Purpose Registers** – 32 8-bit wide registers which are used by the CPU to hold operands and immediate results of arithmetic and logic operations.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}, "jp-MarkdownHeadingCollapsed": true}

**Program Counter** – a 14-bit wide register that stores the address of the next instruction or operand to be fetched.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}, "jp-MarkdownHeadingCollapsed": true}

**Stack Pointer** – 2 8-bit wide registers that stores the address of the last item in the stack. 

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}, "jp-MarkdownHeadingCollapsed": true}

**Status and Control Register** – an 8-bit wide register that contains information about the state of the processor based on the execution of the last instruction[^sr_control_bits].

[^sr_control_bits]: The status and control register also contains bits that can change the operation of the microcontroller. For example the *global interrupt enable* bit is set if interrupts have been enabled. Interrupts will be discussed in EG-252 next year.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}, "jp-MarkdownHeadingCollapsed": true}

**Notes**

* The stack is an area in SRAM where data/information/MCU state can be temporarily pushed on and popped off - the stack pointer holds the memory address of the top of the stack.

* The program counter holds the address of the next address to be executed.

* The general purpose registers are located at the bottom of the data space so can be accessed directly by the ALU. Lower spec microcontrollers/CPUs may only have a single register which is referred to as an accumulator..

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

(wk8:sect2)=
## Additional components

```{image} ../week02/pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

(wk8:sect3)=
## Fetch-Decode-Execute cycle

```{image} ../week02/pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

(wk8:sect4)=
## Example

```{image} ../week02/pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

## Summary

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

## On Canvas
