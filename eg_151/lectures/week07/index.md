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

(week07)=
# Introduction to Assembly Language

```{image} ../week02/pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

## Introduction

So far in this course a number of topics have been covered including {ref}`data_representation`, {ref}`week02`, {ref}`week03` and {ref}`week04`. In this section we will study assembly language which is a low level language that provides a one-to-one mapping between mnemonic instructions and the machine code that is executed on the microcontroller. This will allow you to see how complex high-level instructions and functions in C are written in assembly language and the final program that gets transferred to the microcontroller.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} ../week02/pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```
### Topics discussed

In this lecture we will present an introduction to assembly language, including program structure and syntax as well as operation classifications. We will also revisit the **Direct Port Manipulation in C** example from {ref}`wk5:example_program` and translates this into assembly language looking at some of the key instructions involved.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Contents

* {ref}`wk7:sect1`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk7:sect2`

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* {ref}`wk7:sect3`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk7:sect1)=
## Machine Code and Assembly Language

```{image} pictures/machine_code_wallpaper.jpg
:alt: a decaorative image of machine code
```
[This Photo](https://stackoverflow.com/questions/16512580/how-do-i-stop-xcode-from-showing-me-this-assembly-language-when-im-debugging-an) by Unknown Author is licensed under [CC BY-SA](https://creativecommons.org/licenses/by-sa/3.0/)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Machine code

Programs are stored on a microcontroller as a series of binary codes located within sequential memory addresses ...

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

... this is known as **machine code**[^machine_code].

[^machine_code]: Programs are stored on a microcontroller as a series of binary codes located within sequential memory addresses. These instructions are executed in order, dictated by the program counter, unless an instruction modifies the program counter and changes the program flow e.g. for a function call.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The program in our microntroller looks like this
```
1000101010110001 1000001101111111 1000101010111001 
1000010010110001 1000001101100000 1000010010111001
1000010110110001 1000110001111111 1000010110111001
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### So what is wrong with machine code?

```{image} pictures/machine_code.png
:alt: A photograph showing some machine code
```
Source: [www.shutterstock.com/image-vector/binary-code-digital-numbers-green-background-1724376772](https://www.shutterstock.com/image-vector/binary-code-digital-numbers-green-background-1724376772)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

Well nothing really ... if you are a computer!

```{image} pictures/confused_human.png
:alt: Human beings looking confused
```
[www.shutterstock.com/search/confused+person](https://www.shutterstock.com/search/confused+person)

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

Otherwise ... if you're a human, machine code is difficult to:

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

* Write

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* Read

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* Understand

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* Debug,

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

and most importantly

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* Maintain

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

Instead, instructions can be written in a mnemonic form termed **assembly language** and then translated into machine code by an **assembler**.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Assembly Language
Every CPU (or family of CPU’s) has an instruction set where each operation that can be performed is represented by a certain binary combination.

The next step up in language levels is to represent each of these binary patterns with a **short mnemonic**.

Programs written using these mnemonics are known as **assembly language programs**[^disassembly].

[^disassembly]: Because each mnemonic is associated with a single machine code, it is also easy to convert machine code to assembly language. This is sometimes useful for debugging programs. It is known as **disassembly**.

```{figure} pictures/adc_code.png
:alt: An example of an assembly code instruction
:name: wk7:fig:adc_code

An example of an assembly code instruction `ADC` - Add with carry. Extracted from the Atmel ATmega328 reference manual.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### A Short history of assembly languages

Assembly languages were first developed in the 1950s and were referred to as **2nd generation programming language**. Assembly language is a low level language that uses mnemonic codes (symbols) to represent machine code instructions, rather than using the instructions' numeric (binary) values. 

Essentially, assembly langauges are a much more readable but directly translatable representation of machine code. 

Assembly language is commonly called just assembly, ASM, or symbolic machine code.

Despite the giant leap from machine code to assembly language, by the 1980s its use had largely been overtaken by higher-level languages such as Fortran and C and more recently Python for many applications. 

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Why learn low level languages

High Level Language (HLL) programs are designed to be independent of a particular machine architecture. As a result, they rarely take into account any special features of the machine - features which are commonly available to assembly language programmers. Assembly language is therefore good for hardware-specific jobs such as device drivers.

If you understand assembly language, you’ll have an appreciation for the compiler, and you’ll know exactly what it is doing with HLL statements. Once you see how compilers translate seemingly innocuous statements into a ton of machine code, you will begin to understand how HLL code could be optimised.

Good assembly language programmers make better HLL programmers because they understand the limitations of the compiler and they know what it is doing with their code.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

As well as these points, assembly programmers will have a better understanding of
* how data is represented in memory and other external devices;
* how processors access and execute instructions and how instructions access and process data;
* how a program accesses external devices – I/O;
*how to write efficient code as it requires less memory and execution time.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Why do people use assembly language?

In short:

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* **Speed** - assembly language programs are generally the fastest programs around (up to ten times faster that optimized HLL programs (The Art of Assembly Language, 2010))[^warning].

[^warning]: Please don't get carried away! There are few tasks for the cost of not starting in a HLL is going to be paid back by writing complete programs in assembly code.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* **Space** - assembly language programs are often the smallest. 

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* **Capability** - you can do things in assembly which are difficult or impossible in HLLs. 

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* **Knowledge** - your knowledge of assembly language will help you write better programs, even when using HLLs.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* **Reverse Engineer/modify (Hack)** pre-assembled programs.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk7:sect2)=
## Introduction to Assembly Language

```{image} pictures/assembly_wallpaper.png
:alt: a decaorative image of assembly code
```
[This Photo](https://www.flickr.com/photos/132889348@N07/20607150556) by Unknown Author is licensed under [CC BY-SA](https://creativecommons.org/licenses/by-sa/3.0/)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Assembly Language 101

An assembly language program consists of a series of instructions to an assembler which will then produce the machine code program that is loaded to the microcontroller. 

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

A program is written as a sequence of statements - one statement per line:
* Lines can be empty to separate sections of code
* Statements cannot span multiple lines

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

Each statement contains up to four fields each separated by a space or tab character as shown below:

```asm
[label:]    operator    [operand]     [;comment]
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

All statements must have something in the Operator field, but the label, operand and comment fields can be empty.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assembly language labels

The label field is used to create a reference point in the program than can be used to identify/locate a collection of instructions.

Examples:
```asm
LOOP        operator

  COUNTER:  operator

MY_CODE     operator

SECTION1    operator
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Labels must follow a set of rules and a particular format:

* All labels must be **unique** and cannot use **system reserved phrases**.
* All labels **must start with a letter**.
* Labels can contain **letters, numbers, and special characters** (symbols, such as `@`, `$, `_` ).
* Labels that **don't begin at column 1** must be followed by a colon character ( `:` ).
* Labels are written in **all capitals**. 

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assembly Language Operators

The **operator field** contains either an assembly directive or a mnemonic/instruction.

**Assembly directives**, sometimes termed *pseudo-operations* are directives to the assembler that will not be translated to machine code but provide information critical to the program's function or is required by the assembler.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Assembly directives can be used to specify the starting address in memory, generate fixed tables and data, indicate the end of a program and several others.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assembly mnemonics

A **mnemonic**  is an instruction that will be directly translated into machine code and is used to manipulate data in some way.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The list of allowed mnemonics/instructions is called the **instruction set** and is specific to a particular microcontroller architecture.
However in general, the mnemonics can be classified into one of six groups:

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- **Data Transfer**: `IN`, `LD`, `LDI`, `LDS`, `MOV`, `OUT`, `ST`, `STS`;

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- **Arithmetic**: `ADD`, `ADC`, `ADIW`, `SUB`, `SUBI`, `SBC`, `INC`, `DEC`, `MUL`, `MULS`, `FMUL`;

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- **Logical**: `AND`, `ANDI`, `EOR`, `OR`, `ORI`;

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- **Program flow**: `BREQ`, `BRGE`, `BRNE`, `BRLO`, `BRMI`, `BRPL`, `CALL`, `JMP`, `RET`, `RJMP`;

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- **Bit and Bit Test**: `LSL`, `LSR`, `ROL`, `ROR`, `ASR`, `SBI`, `CBI`, `BSET`, `BCLR`;

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

- **MCU Control**: `BREAK`, `NOP`, `SLEEP`, `WDR`.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

For this module we have been working  with an Atmel ATmega328 microcontroller which is based on the  AVR® enhanced (AVRe+) architecture

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

Labels must follow a set of rules and a particular format
All labels must be unique and cannot use system reserved phrases.
All labels must start with a letter.
Labels can contain letters, numbers, and special characters (symbols, such as @, $, _ ).
Labels that don’t begin at column 1 must be followed by a colon character ( : ).
Labels are written in all capitals. 

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

### Example

Recall the example from {ref}`wk5:example_program` reproduced again here as {numref}`wk7_fig_example_circuit`. The left and right push buttons connected to the digital inputs `D3` and `D2` respectively corresponding with Port D Bits 3 and 2 on the Atmega328 microcontroller. 

When the left push button is pressed the red LED (Port B Bit 1) is illuminated and the green LED (Port B Bit 0) illuminated when the right push button is pressed.
`````{figure} ../week05/pictures/breadboard.jpg
:alt: A photograph of the example circuit which has two buttons and two LEDs.
:name: wk7_fig_example_circuit
:width: 50%

A photograph of the example circuit which has two buttons and two LEDs discussed in {ref}`wk5:example_program`.
``

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

### C-Language Code

Let us start with the C-language program we wrote for this ([main.c](https://gist.github.com/cpjobling/07585093f8eafe69a4eeff1186110883)).

```c
#include <stdint.h>

//I/O and ADC Register definitions taken from datasheet
#define	PORTD (*(volatile uint8_t *)(0x2B))
#define DDRD (*(volatile uint8_t *)(0x2A))
#define PIND (*(volatile uint8_t *)(0x29))

#define PORTB (*(volatile uint8_t *)(0x25))
#define DDRB (*(volatile uint8_t *)(0x24))
#define PINB (*(volatile uint8_t *)(0x23))

int main(void)
{
	//Set Data Direction Registers
	DDRD = DDRD & 0b11110011; //setup bits 2 and 3 of port D as inputs
	DDRB = DDRB | 0b00000011; //setup bits 0 and 1 of port B as outputs

	PORTB = PORTB & 0b11111100; //both pins B0 (D8) and B1 (D9) start low
	
	PORTD = PORTD | 0b00001100; // Enable the pull up resistor for bits 2 and 3 of port D
	
	for(;;)
	{
		if((PIND & 0b00000100) == 0)
		{
			PORTB = PORTB | 0b00000001; //sets port B, bit 0 to logic 1/high, switches the LED connected to D8 on
		}
		else if ((PIND & 0b00001000) == 0)
		{
			PORTB = PORTB | 0b00000010; //sets port B, bit 1 to logic 1/high, switches the LED connected to D9 on
		}
		else
		{
			PORTB = PORTB & 0b11111100; //sets bits 0-5 of port B to logic 0/low, switches off both the LED's
		}
	}
	
}
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

(wk7:sect4)=
## Section 4

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

## Summary

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

## On Canvas

```{code-cell} ipython3
---
editable: true
slideshow:
  slide_type: ''
---

```
