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

```
[label:]    operator    [operand]     [;comment]
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

All statements must have something in the Operator field, but the label, operand and comment fields can be empty.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assembly language labels

The label field is used to create a reference point in the program than can be used to identify/locate a collection of instructions.

Examples:
```
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

For this module we have been working  with an Atmel ATmega328 microcontroller which is based on the  AVR® enhanced (AVRe+) architecture.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assembler Directives

The **operator field** contains either an **assembly directive** or a **mnemonic/instruction**.

Assembly directives, sometimes termed pseudo-operations are **directives to the assembler** that will not be translated to machine code but provide information critical to the programs function that is **required by the assembler**.

Some common directives include;

- `.CSEG` / `.DSEG` / `.ESEG`
- `.ORG` / `.EXIT`
- `.EQU` / `.SET` / `.DEF` / `INCLUDE`
- `.DB` / `.DW `/ `.BYTE`

Directives are specific to a particular microcontroller family (different to the instruction set). A list of supported directives for the AVR based microcontrollers can be found [here](http://www.avr-asm-tutorial.net/avr_en/beginner/DIREXP.html).

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assembly Language Operands

- The operand field follows the operator and contains the **address or data** to be used by the instruction.
- A name (‘label’) can be used to represent the address of the data or a symbol to represent a data constant.
- The **field can be empty** if the instructions given by the operator do not need an address or data.
  - As an example the operator `NOP` (no-operation) requires no operand.
- **Some operators allow for multiple operands** and in these cases the operands are separated by commas (`,`).

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Examples 1

```
LDI     R16, 0b01010101
ADD     R16, R17
LDS     R2, 0xFF00
NOP
MOV     R16, R17
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assembly Language Comments

As with the C language, the comment field is there to allow the programmer to include any comments which may make the program easier to understand at a later time or by another reader.

When the **assembler is reading** the line of text, the **comment field is ignored**.

Comments also follow a set of rules and a particular format dependent on the assembler being used[^comments_in_asm]:
- If an **entire line** is a comment, it must start with a **semicolon** or an **asterisk symbol** in the first column.
- If **not starting in the first column**, the comment must start with a **semicolon**.
- The comment must be separated from the operator or operand field by at least one space. 

[^comments_in_asm]: As assembly codes are generally less readable than higher level languages, like the C language, it is good practice to be very liberal with comments in assembly code programs.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Examples 2

```
;This comment line starts with a semicolon
*This comment line starts with an asterisk

operator ;This comment follows an operator
operator
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assembler

It is important to be aware of the assembler and the structure assembly language programs follow.

The assembler takes the sequence of mnemonics (instructions) written in assembly language and translates them into machine code using the process illustrated in {numref}`wk7:fig:assembly`.

```{figure} pictures/assembler.png
:alt: The assembly process
:name: wk7:fig:assembly
:width: 50%

The assembly process
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

The assembler processes the assembly language file and generates an object file and listing file(s)
- An object file is essentially a one-to-one mapping of mnemonics against the binary (sometimes hexadecimal) instruction set
- The listing file shows each line of the assembly language input along with the memory addresses resolved by the assembler, resulting machine code or data and other diagnostic information.

The linker combines multiple object files as well as any library files and generates an executable which can be loaded onto the microcontroller (this file is often a `*.hex` file).

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk7:sect3)=
## Interfacing with Digital I/O example.

```{image} ../week05/pictures/breadboard_wallpaper.jpg
:width: 75%
:alt: Decorative background image showing the circuit discussed in the example.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Example

Recall the example from {ref}`wk5:example_program` reproduced again here as {numref}`wk7_fig_example_circuit`. The left and right push buttons connected to the digital inputs `D3` and `D2` respectively corresponding with Port D Bits 3 and 2 on the Atmega328 microcontroller. 

When the left push button is pressed the red LED (Port B Bit 1) is illuminated and the green LED (Port B Bit 0) illuminated when the right push button is pressed.

```{figure} ../week05/pictures/breadboard.jpg
:alt: A photograph of the example circuit which has two buttons and two LEDs.
:name: wk7_fig_example_circuit
:width: 50%

A photograph of the example circuit which has two buttons and two LEDs discussed in {ref}`wk5:example_program`.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### C-Language Code

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

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### I/O Addresses

```{figure} pictures/io_registers.png
:alt: The addresses of the IO registers with information on which can be used in particular contexts.
:width: 100%
:name: wk7:fig:io_addresses

The addresses of the IO registers with information on which can be used in particular contexts.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assigning a name to the I/O addresses

We use `.EQU`, `.SET` or `.DEF` to assign a name to a memory location[^assembly_names]:

```
.EQU label = 12345
.SET variable = 0x0100
.DEF my_register = R16
```

[^assembly_names]: The purpose of these assembly directives is to assign a meaningful name to a label, constant, data value (*variable*), or memory location.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} pictures/asm1.png
:alt: First assembler example - assigning names
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Assembly equivalent of `int main(void)`

In C language we put our code (or calls to external functions) within a main function, written as:
```c
int main(void) {
  // Program code
}
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

In assembly language, there isn't a main function as such but rather `.CSEG` / `.DSEG` / `.ESEG` directive along with the `.ORG` directive are used to define the start address of code, data and EEPROM segments in memory.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

In these lines we are telling the assembler that we want the code segment to start at memory location with address $200_{16}$.

```{image} pictures/asm2.png
:alt: Second assembler example - setting the start address for a program
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### I/O port access and bitmasking operations

We can use the `IN` and `OUT` operations for reading from and writing to ports respectively, and the `ANDI` and `ORI` operations for setting up bitmasks.

We include scans of the documentation for these operators in the following images.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} pictures/in.png
:alt: The IN operator
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} pictures/out.png
:alt: The OUT operator
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} pictures/andi.png
:alt: The ANDI operator
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} pictures/ori.png
:alt: The ORI operator
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Setting up the I/O Ports

Using the C language, we wrote:

```c
DDRD = DDRD & 0b11110011;
```

to ensure bits 2 and 3 of port D are configured as inputs. 

Similar lines were written to set up the output bits in Port B, the starting condition of these bits and then to enable the pull up resistors on Port D.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

The direct translation to Assembly language involves three lines for each action as illustrated in {numref}`wk7:fig:port_io`.

```{figure} pictures/port_io.png
:alt: Setting up and accessing I/O in assembler
:width: 100%
:name: wk7:fig:port_ios

Setting up and accessing I/O in assembler
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Infinite loop

Using the C language, we created an infinite loop as follows:
	
```c
for (;;) {
  // Program code
}
```

This essentially "*traps*" the program to ensure it continuously loops executing the program code within the code block.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

In assembly language we can produce the same result by creating a "Label" and using the operation `RJMP` (*relative jump*): 

```{image} pictures/inf_loop.png
:alt: An infinite loop using a label and rjmp.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

documented as shown here


```{image} pictures/rjmp.png
:alt: The RJMP operators
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Detecting a button press

In C language, to detect a button press we used the 'if statement' below with a bit mask corresponding to a particular bit of the port and monitoring for its state changing to 0 or Low.

```c
if ( (PIND & 0b00000100) == 0)
{
  PORTB = 0b00000001;	 // sets port B, bit 0 to logic 1 (high)
                         // which switches the LED connected to D8 on
}
```

In assembly we can use the *compare* (`CP`) and *branch if equal* (`BREQ`) instructions to achieve this same implementation.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} pictures/cp.png
:alt: Documentation for the CP (compare) operation
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{image} pictures/breq.png
:alt: Documentation for the BREQ (branch if equal) operation
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

Consider the assembly code shown below.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

- In lines 32-36 we read `PIND`, use a bit mask to select bit 2, compare the value of the selected bit with zero and branch to label `LED1` if the value is zero (`0x00`).
- In lines 38-42 we read `PIND`, use a bit mask to select bit 3, compare the value of the selected bit with zero and branch to label `LED2` if the value is zero (`0x00`).
- If we reach lines 44, then both buttons were high (not pressed) so we use the bitmask `0x11111100` to ensure that both LEDs connected to bits 0 and 1 of port B are turned off. We then jump to the label `LOOP` (lines 45-47). 

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```{image} pictures/detect_switch.png
:alt: Detecting a button press in assembly code
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

In the next few lines (49-59) we read the current value of Port B into `R16` before performing a bitwise or operation with the immediate pattern provided (mask). The new value stored in R16 is then sent to the `PORTB` register essentially changing the state of the LED to on. Finally the `RJMP` instruction ensures the program loops back to the start.

```{image} pictures/leds.png
:alt: Assembly code to switch on LEDs
```

A similar process is used for LED2.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Comparison with C

In {numref}`wk7:fig:comp_asm_with_c` we compare the C program with the equivalent assembly program. 

```{figure} pictures/comp_asm_with_c.png
:alt: Comparing an I/O program written in C with an equvalent assembly program.
:width: 100%
:name: wk7:fig:comp_asm_with_c

Comparing an I/O program written in C with an equvalent assembly program.
```

The assembly code is available for study as a GIST [main.asm](https://gist.github.com/cpjobling/e72f37ff363353b6ed10ecdbeaa970af).

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### An Advantage of Assembly Language
Using C language, it is not possible to read or write individual bits of a register or I/O port.

In assembly language, this *is possible* using bit operations such `SBI`, `CBI`, `SBIC`, `SBIS` and a handful of others:

```{image} pictures/sbi.png
:alt: The SBI operation.
```
```{image} pictures/sbic.png
:alt: The SBIC operation.
```

These can only be used on certain registers as identified in the documentation for the I/O memory map:

```{image} pictures/io_mem_map2.png
:alt: The I/O memory map showing the registers for which bitwise operations are available.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Comparisons

In {numref}`wk7:fig:comparison` we show the original C program, the first version of the assembly program, and a version that is using `SBIC` to directly branch based on the value of a single bit in Port D. These will work in the same way.

```{figure} pictures/comparison.png
:alt: Comparison of three equivalent programs
:width: 100%
:name: wk7:fig:comparison

Comparison of three equivalent programs
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

## Summary

In this section:
- We have introduced assembly language as a direct mapping of mnemonics to machine code.
- We have explored the basic structure of an assembly language program including operator classification, operands and comments.
- Finally, we have revisited out digital switch example from C and looked at how this can directly translate to Assembly language and how it can be optimized using specific features of the Atmel ATmega328 microcontroller.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

## On Canvas

This week on the canvas course pages, you will find the sample program from today's lecture, look through this and ensure you are confident in how it works and how the masks are defined and registers set. 

There is also a short quiz to test your knowledge on these topics.
