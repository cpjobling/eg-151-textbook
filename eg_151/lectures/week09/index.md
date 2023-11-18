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

(week09)=
# Addressing Modes

```{image} ../week02/pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

## Introduction
In this week's lecture, you will learn more about assembly language and the diverse ways to access data dependent on what it is and where it is stored. This is based around what is known as addressing modes. There are different ways in which an operand may be specified in an instruction depending on what it is and where it is located. Some operations require no operands and the data to be operated on is implied, in other cases operands can be constants, variables, arrays and memory locations all of which are accessed differently.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} ../week02/pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```
### Topics discussed

In this section we will review a number of different addressing modes relevant to the Atmel ATMega328 Microcontroller including, inherent, immediate, direct, indirect and relative.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Contents

* {ref}`wk8:sect1`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk8:sect2`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk8:sect1)=
## What is an addressing mode?

An addressing mode is a way in which an operand is specified in an instruction and defines how the CPU finds it. 

There are different ways in which an operand may be specified in an instruction depending on what it is and where it is located.

Some operations require no operands and the data to be operated on is *implied*, in other cases operands can be constants, variables, arrays and memory locations – this is where addressing modes are used. 

The six addressing modes found in the AVR architecture used by the Atmel ATmega328 family of processors are summarised in {numref}`wk9:fig:addressing_modes`.


```{figure} pictures/addressing_modes.png
:name: wk9:fig:addressing_modes
:align: center
:width: 30%
:alt: The six addressing modes of an AVR processor: inherent, immediate, extended, direct, relative and indexed.

The six addressing modes of an AVR processor.
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The memory address where data is stored is called the  *effective address* of the operand and the addressing mode refers to the way in which the operand is specified and how the CPU accesses it.

**Addressing modes** are an aspect of the *instruction set architecture* in most *central processing unit* (CPU) designs. The various addressing modes that are defined in a given instruction set architecture define how the *machine language instructions* in that architecture identify the *operand*(s) of each instruction. An addressing mode specifies how to calculate the effective *memory address* of an operand by using information held in *registers* and/or constants contained within a machine instruction or elsewhere.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk8:sect2)=
## Addressing modes on the Atmel ATmega328
The AVR<sup>&reg;</sup> Enhanced RISC microcontroller supports powerful and efficient addressing modes for access to the program memory (Flash) and Data memory (SRAM, Register file, I/O Memory, and Extended I/O Memory).

The Atmel ATmega328 microcontroller makes use of the following addressing modes:
- Inherent/Implied Addressing
- Register Direct (single and two-register) Addressing
- I/O Direct Addressing
- Data Direct Addressing
- Immediate Addressing
- Data Indirect Addressing
- Relative Addressing
- Program Addressing (Not covered)

Apart from program addressing, we will discuss each of these addressing modes in the followin.g

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Inherent Addressing Mode

For instructions that use **inherent addressing**, sometimes called *implicit* or *implied* addressing,  the operands are not explicitly specified but are implied by the instruction[^inherent_addressing].

[^inherent_addressing]: In inherent addressing the effective address that the operation acts on is the register itself.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

**Examples**

```
SEN    ; Set Negative Flag in Status Register (SREG)
CLN    ; Clear Nagative Flag in Status Register (SREG)
NOP    ; No Operation (do nothing for one clock cycle)
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

Since no additional clock cycles are required to fetch and move data around, this is the **simplest and fastest addressing mode**.

Some of the AVR instructions that use inherent addressing are listed in {numref}`wk9:table1`.

```{list-table} AVR instructions that use inherent addressing
:name: wk9:table1
:header-rows: 1
* - Mnemonic
  - Operands
  - Decription
* - `CLZ`
  - 
  - Clear Zero Flag
* - `SEI`
  - 
  - Global Interrupt Enable
* - `CLI`
  - 
  - Global Interrupy Disable
* - `SES`
  - 
  - Set Sign Bit
* - `CLS`
  - 
  - Clear Sign Biy
* - `SEV`
  - 
  - Set Two's Complement Overflow
* - `CLV`
  - 
  - Clear Two's Complement Overflow
* - `SET`
  - 
  - SET T in SREG
* - `CLT`
  - 
  - Clear T in SREG
* - `SEH`
  - 
  - Set Half Carry Flag in SREG
* - `CLH`
  - 
  - Clear Half Carry Flag in SREG
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Microcontrollers that have single accumulators in place of a bank of general-purpose registers often have more instructions that use inherent addressing such as `CLRA`, `DECA`, `INCA`.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Register Direct Addressing

For these operators, the operands are contained in registers in the *register file*. There are single register operators which operates on and returns the result to the destination register, known as Rd[^rd].

Because the microcontroller can access the register file faster than memory, they are also fast instructions.

[^Rd]: The d in Rd is a number in the range 0-31.
[^Rr]: The r in Rr is also a number in the range 0-31.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Single Register (Rd)

For instructions that use **single direct register addressing**, the operand is contained in the destination register Rd as illustrated in {numref}`wk9:fig:srda`.


```{figure} pictures/srda.png
:alt: Illustrating single register direct addressing.
:name: wk9:fig:srda
:width: 60%
:align: center

Illustrating single register direct addressing: d is the register number and register d is source of the operand and the destination of the result.
```

**Examples**

```
DEC R16		;Decrement R16
INC R17		;Increment R17
CLR R16		;Clear R16
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Remember the operand represents the data so this addressing mode is accessing or acting on the data using only one of the general purpose registers but does not include any write back to SRAM/EEPROM.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Two Register (Rd, Rr)

For instructions that use **direct register addressing with two registers**, the operand is **contained in the source and destination registers Rr and Rd respectively. The result of this that the data in Rd is overwritten . This is illustrated in {numref}`wk9:fig:rda_with_2_regs`.


```{figure} pictures/srda2.png
:alt: Illustrating direct register addressing with two registers.
:name: wk9:fig:rda_with_2_regs
:width: 60%
:align: center

Illustrating register direct addressing with two registers: d is the source of the first operand, r is the source of the second operand. The result overwrites the data in register d.
```

**Examples**

```
ADD R16, R17  ;Add the contents of R16 and R17. Return sum to R16.
CP R16, R17   ;Compare the values of R16 and R17
MOV R16, R17  ;Copy contents of R17 into R16
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

As with the previous addressing mode, this one is accessing or acting on the data in two of the general purpose registers and although it overwrites the data in Rd is also does not include any write back to SRAM/EEPROM.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### I/O Direct Addressing

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Data Direct Addressing

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Immediate Addressing

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Immediate vs Data Direct Addressing

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Indirect Data Addressing

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Indirect Data Addressing with Displacement

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Indirect Data Addressing with Increment/Decrement

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Relative Addressing

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Relative Addressing Example

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

## Summary

In this section have reviewed different addressing modes supported by the AVR instruction set commenting on use cases and speed (in clock cycles) of their operation.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

## On Canvas

This week in your own time, you should review all the content covered in these lecture notes, self-directed study material and the lab classes in preparation for the class test next week. 

You should also review Section 3 of the AVR instructions set manual {cite}`avr_instruction_set`) on program and data addressing modes.
