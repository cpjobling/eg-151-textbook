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

* {ref}`wk9:sect1`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk9:sect2`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk9:sect1)=
## What is an addressing mode?

An addressing mode is a way in which an operand is specified in an instruction and defines how the CPU finds it. 

There are different ways in which an operand may be specified in an instruction depending on what it is and where it is located.

Some operations require no operands and the data to be operated on is *implied*, in other cases operands can be constants, variables, arrays and memory locations – this is where addressing modes are used. 

The six addressing modes found in the AVR architecture used by the Atmel ATmega328 family of processors are summarised in {numref}`wk9:fig:addressing_modes`.


```{figure} pictures/addressing_modes.png
:name: wk9:fig:addressing_modes
:align: center
:width: 100%
:alt: The six addressing modes of an AVR processor - inherent, immediate, extended, direct, relative and indexed.

The six addressing modes of an AVR processor.
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The memory address where data is stored is called the  *effective address* of the operand and the addressing mode refers to the way in which the operand is specified and how the CPU accesses it.

**Addressing modes** are an aspect of the *instruction set architecture* in most *central processing unit* (CPU) designs. The various addressing modes that are defined in a given instruction set architecture define how the *machine language instructions* in that architecture identify the *operand*(s) of each instruction. An addressing mode specifies how to calculate the effective *memory address* of an operand by using information held in *registers* and/or constants contained within a machine instruction or elsewhere.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk9:sect2)=
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
:width: 100%
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

```{note}
Remember the operand represents the data so this addressing mode is accessing or acting on the data using only one of the general purpose registers but does not include any write back to SRAM/EEPROM.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Two Register (Rd, Rr)

For instructions that use **direct register addressing with two registers**, the operand is **contained in the source and destination registers Rr and Rd respectively. The result of this that the data in Rd is overwritten . This is illustrated in {numref}`wk9:fig:rda_with_2_regs`.


```{figure} pictures/srda2.png
:alt: Illustrating direct register addressing with two registers.
:name: wk9:fig:rda_with_2_regs
:width: 100%
:align: center

Illustrating register direct addressing with two registers: d is the source of the first operand, r is the source of the second operand. The result overwrites the data in register d.
```

**Examples**

```
ADD R16, R17  ;Add the contents of R16 and R17. Return sum to R16.
CP R16, R17   ;Compare the values of R16 and R17
MOV R16, R17  ;Copy contents of R17 into R16
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

```{note}
As with the previous addressing mode, this one is accessing or acting on the data in two of the general purpose registers and although it overwrites the data in Rd is also does not include any write back to SRAM/EEPROM.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### I/O Direct Addressing

Within the user data space there are 64 I/O registers as well as 160 Extended I/O registers. The **first 64** of these can be accessed using instructions **such as `IN` and `OUT` using I/O direct addressing mode**.  In I/O direct addressing mode the operands contain the **address A of one of the lower 64 I/O locations** and a source (Rr) or destination register (Rd). This is illustrated in {numref}`wk9:fig:io_addr`. 

```{figure} pictures/io_addr.png
:alt: Illustrating I/O direct register addressing - one of the operands comes from one of the I/O registers. 
:name: wk9:fig:io_addr
:width: 100%
:align: center

Illustrating I/O direct addressing: the source (or destination) will be from an I/O register. The destination (or source) will be one of the general purpose registers.
```

**Examples[^wk9:note1]** 

```
IN R16, PIND	 ;Load (input) the contents of PIND into R16
OUT PORTC, R17	 ;Store (output) the contents of R17 to PORTC
```

[^wk9:note1]: Note: in these examples, the labels  `PIND` and `PORTC` must have already been defined.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

```{note}
Be aware that loading and storing data to these registers using instructions such as LD and ST must address these registers differently and does not use I/O direct addressing mode. 
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Data Direct Addressing

Instructions that use **direct data addressing** are **two words** (32-bits) in length, the first operand, Rr/Rd is one of the general-purpose registers and the second is 16-bit Data Address contained in the 16 LSBs of the two-word instruction.
This is illustrated in {numref}`wk9:fig:dd_addr`. 

```{figure} pictures/dd_addr.png
:alt: Illustrating data direct addressing with a general purpose register and data stored in memory.
:name: wk9:fig:dd_addr
:width: 100%
:align: center

Illustrating data direct addressing: the source (or destination) will be in memory. The destination (or source) will be one of the general purpose registers.
```

**Examples** 

```
LDS R16, 0x0100   ;Load the contents of data space address hex 0100 into R16
STS 0x0101, R17   ;Store the contents of R17 to data space address hex 0101
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Immediate Addressing

With instructions that use **immediate addressing** the actual data to be used is included within the instruction itself as a constant value[^wk9:note2]. This is illustrated in {numref}`wk9:fig:imm_addr`. 

```{figure} pictures/imm_addr.png
:alt: Illustrating immediate addressing in which the operand is a number in the instruction.
:name: wk9:fig:imm_addr
:width: 100%
:align: center

Illustrating immediate addressing: the destination will be an one of the general purpose registers. The source will be a data value given in the instruction.
```

[^wk9:note2]: the value of the second operand of an operator with immediate addressing will be hard coded into the code and cannot be changed during the running of a program.

**Examples** 

```
LDI R16, 0x5B   ;Load the hex value 5B into R16
SUBI R17, 24    ;Subtract the decimal value 24 from the contents of R17
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

```{note}
Since the instruction already contains the data, this is a fast addressing mode and only takes one clock cycle to complete.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Immediate vs Data Direct Addressing

Instructions that use immediate addressing, take one clock-cycle to complete. For example `LDI` - load immediate:

```{image} pictures/wk9_ldi.png
:alt: Manual page for the LDI command
```

Instructions that use register or data direct addressing, take two clock-cycles to complete. For example `LDS` - load from store 
 needs to load the operator and decode the register address, then load data from the data space into the register.

```{image} pictures/wk9_lds.png
:alt: Manual page for the LDS command
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Indirect Data Addressing

With instructions that use **indirect data addressing** the operand address is the contents of one of the X- Y- Z-pointer registers. This is illustrated in {numref}`wk9:fig:id_addr`. 

```{figure} pictures/id_addr.png
:alt: Illustrating indirect direct addressing in which the registers provide the address of the operand.
:name: wk9:fig:id_addr
:width: 100%
:align: center

Illustrating indirect direct addressing in which two registers provide the address in memory of the operand.
```

**Examples**

```
LDS R26, 0x00
LDS R27, 0x10 

LD R18, X	   ;Load R18 with data stored at the address in the X- pointer register
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

```{note}
This mode allows the address to be a run time computed value, whereas the direct address must be computed at compile time/assembly time/load time.

This has several important use cases including setting up storage for arrays or other structures in memory.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Indirect Data Addressing with Displacement

As with indirect data addressing, the microcontroller makes use of the Y and/or Z pointers with an additional displacement to access data stored in the data space.

This is the best way to access an array of data and is illustrated in {numref}`wk9:fig:id_addr_2`. 

```{figure} pictures/id_addr_2.png
:alt: Illustrating indirect direct addressing with displacement.
:name: wk9:fig:id_addr_2
:width: 100%
:align: center

Illustrating indirect direct addressing with displacement.
```

**Examples**

```
LDS R28, 0x00
LDS R29, 0x10 

LD R18, Y + 1	   ;Load R18 with data stored at the address in the Y- pointer register with a displacement of 1
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

```{note}
This mode allows the address to be a run time computed value, whereas the direct address must be computed at compile time/assembly time/load time.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Indirect Data Addressing with Increment/Decrement

Indirect Data Addressing mode also supports Post-increment and Pre-decrement addressing.
W
ith Data Indirect Addressing with Post-increment, the X-, Y-, or the Z-pointer is incremented after the operation. The operand address is the content of the X-, Y-, or the Z-pointer before incrementing.

With Data Indirect Addressing with Pre-decrement, the X,- Y-, or the Z-pointer is decremented before the operation. The operand address is the decremented contents of the X-, Y-, or the Z-pointer.

**Examples**

```
LD R16, Z+ ;Load R16 with data stored at the current address in the Z pointer register then increment the Z register
LD R16, -Z ;Load R16 with data stored at the current address in the Z pointer register - 1
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

```{note}
This mode is useful for iterating through arrays of or sequentially stored linked data.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Relative Addressing
With relative program memory addressing the operand contains a signed 12-bit offset value which during execution is added to the program counter to change the flow of the program.

The destination of the branch (effective address) instruction is calculated by adding the signed byte following the opcode (-2048 to +2047) to the PC content. This is illustrated in {numref}`wk9:fig:rel_addr`. 

```{figure} pictures/rel_addr.png
:alt: Illustrating relative addressing which adjusts the program counter and is typically used for branching.
:name: wk9:fig:rel_addr
:width: 100%
:align: center

Illustrating relative addressing which adjusts the program counter and is typically used for branching.
```

**Examples**

```
RJMP Label	;Jump to the address specified by label
RCALL Label	;relative call to an address (subroutine)
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{note}
This addressing mode is used by instructions such as RJMP to modify the flow of a program, this typically is used in conjunction with test conditions or at the end of the code to make it loop back to the start.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Relative Addressing Example

```{figure} pictures/rad_example.png
:alt: Example of relative addressing
:name: wk9:fig:rel_addr_2
:width: 100%
:align: center

An example to illustrate relative addressing
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} pictures/rel_addr_2.png
:alt: RJMP LED1
:width: 50%
```

```
RJMP LED1
1100 kkkk kkkk kkkk
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

is

```
C006 = 1100 0000 0000 0110
RJMP +6
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```{image} pictures/rel_addr_3.png
:alt: The program counter jumps 6 memory locations forward.
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

## Summary

In this section have reviewed different addressing modes supported by the AVR instruction set commenting on use cases and speed (in clock cycles) of their operation.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

## On Canvas

You should review Section 3 of the AVR instructions set manual ({cite}`avr_instruction_set`) on program and data addressing modes. There is a short quiz covering the content of this chapter. 

In preparation for the class test next week, you should review all the content covered in these lecture notes, self-directed study material and the lab classes. 

Note that the class test is closed-book but you have will access to the reference manuals mentioned in these notes.

```{code-cell} ipython3
---
editable: true
slideshow:
  slide_type: ''
---

```
