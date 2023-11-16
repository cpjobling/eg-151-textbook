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

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk8:sect2)=
## Additional components

```{image} ../week02/pictures/wallpaper.png
:alt: Image of a microcontroller used as chapter headings in slide show
:width: 50%
```
[wallpaper.dog/microcontroller-wallpapers](https://wallpaper.dog/microcontroller-wallpapers)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

For this section we will used the simplified block diagram shown in {numref}`wk8:fig:simplified_bd` to represent the microcontroller core. This shows the parts that we have already seen as well as the new ones, highlighted, that we will discuss in the following.

```{figure} pictures/simple_bd.png
:name: wk8:fig:simplified_bd
:align: center
:width: 100%
:alt: Simplified block diagram showing the major components of a microcontroller

Simplified block diagram showing the major components of a microcontroller
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Block 1: Clock

The clock generates a signal that oscillates between a high and a low state and acts like a metronome which coordinates/synchronizes the actions of the different microcontroller elements.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The clock signal typically takes the form of a square wave with a 50% duty cycle[^duty_cycle] and a fixed frequency see {numref}`wk8:fig:clk`.
[^duty_cycle]: The duty cycle is $\mu=T_\mathrm{on}/\left(T_\mathrm{on}+T_\mathrm{off}\right)$ and $\mu = 0.5$ (50%) if $T_\mathrm{on}=T_\mathrm{off}$. That is for half of a cycle (i.e. for $T_\mathrm{on}$s) it is in a high state and for the other half of the cycle (for $T_\mathrm{off}$s) it is in a low state. 

```{figure} pictures/clock.png
:name: Wk8:fig:clk
:align: center
:width: 100%
:alt: A typiocal clock signal. The frequency is 1/T.

A typical clock signal. The frequency is $f=0.5/T_\mathrm{on}$ if $\mu = 0.5$.
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

In older microcontrollers the clock signal was generated by an external circuit, but modern microcontrollers typically come with an external crystal as well as an internal oscillator.

At every cycle of the clock a step of the Fetch-decode-execute cycle is performed.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

The ATmega328 is shipped with an internal RC oscillator with a frequency of 8MHz and the Arduino nano board includes a 16MHz *external* crystal which is typically set to be the default clock[^execution_speed].

[^execution_speed]: If the frequency is $x$MHz, then the microcontroller can execute $x$ million instructions a second and each instruction takes 1/x microseconds to execute. Therefore, for the ATmega328 with internal clock the execution speed is 0.125$\mu$s per instruction. For the ATmega328 on the Arduino nano it is half this. 

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Internal Clock

Internal clocks are made from RC oscillators.

Limited manufacturing abilities mean that there are large differences between individual microcontrollers. These differences are typically $\pm 10\%$, but clocks can usually be tuned to $\pm 0.5\%$.
 
**Advantages**
- Cheaper
- Leaves pins that are used for the external clock source, e.g. see {numref}`wk8:fig:atmel_clk_pins`, available for other functions such as I/O
- Simplifies PCB design and routing for high frequency traces.

```{figure} pictures/atmel_clk.png
:name: wk8:fig:atmel_clk_pins
:align: center
:width: 100%
:alt: Pins reserved for an external clock signal on the Atmel ATmega328 microcontroller.

Pins reserved for an external clock signal on the Atmel ATmega328 microcontroller.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### External clock

Many components inside the microcontroller will use a scaled version of the clock signal (recall the ADC) and so high clock accuracy is not needed. However, for other applications, such as communication based applications like the CAN bus, USB and Ethernet, high frequency and accurate clock signals are required. 

For these applications, external ceramic resonators or crystals have a much higher accuracy when it comes to frequency as well as stability. 

```{figure} pictures/crystal_clk.png
:alt: Images of the crystal oscillators used with microcontrollers
:name: wk8:fig:crystal_clk
:width: 100%
:align: center

Examples of the crystal oscillators used with microcontrollers. a) The circuit symbol for a crystal; b) A 16Mhz crystal packaged as a component; c) the external crystal provided with the ATmega328 chip on the Arduino nano board.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### The Atmel ATmega328 clock

A block diagram of the clock circuity is given in {numref}`wk8:fig:atmel328_clk`. This is a complex diagram and the details are not too important. What is important is to note is how the clock signal is distributed to all the major subsystems. This is to ensure that all the internal operations that the microcontrollers are carried out in lock-step with the clock signal and in synchronization with each other. The clock sources are shown at the bottom of the diagram and the major blocks which use the clock are at the top. The blocks in the centre of the diagram are concerned with the functions needed to monitor the status of the microcontroller. 

```{figure} pictures/atmel328_clk.png
:alt: Clock distribution of the ATmega328
:name: wk8:fig:atmel328_clk
:width: 100%
:align: center

Clock distribution of the ATmega328. (Reproduced from Figure 8.1 of the Atmel ATmega328 data sheet {cite.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

The **CKSEL3..0** are special memory locations in flash memory ("fuses") that are used to set the clock sources as shown in Table 9.1 of the data sheet reproduced below.

```{image} pictures/clksel.png
:alt: reproduction of table 9.1 of the Atmel ATmega328 data sheet.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

There are two registers accessible to the programmer with respect to the clock. These are

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

**OSCCAL - Oscillation Calibration Register** used to trim the calibrated internal RC oscillator to remove process
variations from the oscillator frequency.y

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

**CLKPR – Clock Prescale Register** whose bits define the division factor between the selected clock source and the internal system clock. These bits can be set at run-time to vary the clock frequency to suit the application requirements.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Block 2: Control Unit

The **control unit** coordinates all activities and sends signals through the control bus to all elements of the microcontroller, including the ALU, memory, and input/output, instructing them how to respond to the instructions from the program code it has just read and interpreted from the memory unit. 

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The control unit is responsible for
- Coordinating and controlling activities of the CPU;
- Managing data flow between other components and the CPU;
- Acknowledging and accepting the next instruction; and
- Storing the resulting data back into a memory unit.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Block 3: Memory Address Register (MAR)

During operation the address in the program counter is loaded into the **Memory Address Register** and a request is sent onto the address bus to retrieve the data stored at that memory location.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Block 4: Memory Data Register (MDR)

The data at a particular memory location is loaded from the data bus into the **Memory Data Register** before being passed to the **instruction register** or being operated on.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Block 5: Instruction Register (IR)

After fetching an instruction from program memory, the microcontroller stores it in the **instruction register**.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Block 6: Instruction Decoder (ID)

The **instruction decoder** decodes the instruction opcode from the **instruction register** and generates appropriate control signals to execute the instruction.

It contains a lookup table featuring a mapping of all binary instructions in the microcontroller's instruction set architecture.

Once an instruction arrives at the instruction register it is passed to the decoder. Once decoded the output is passed to the control unit to select the correct hardware for the operation or to get the next word of data from memory.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

A summary of some example operations taken from section 5 of the AVR Instruction Set Manual {cite}`avr_instruction_set` are given in {numref}`wk8:table1`. The interested reader will find full details at the manual reference quoted in the table.

```{list-table} Some examples of instruction decoding
:header-rows: 1
:name: wk8:table1
* - 16 Bit Opcode
  - Operation
  - Usage
  - Syntax
  - Program Counter (PC)
  - Manual reference
* - 0001 11rd dddd rrrr
  - Add with carry (`ADC`)
  - Rd <- Rd + Rr + C[^carry_flag]
  - `ADD Rd, Rr`
  - PC <- PC + 1
  - 5.1
* - 0000 11rd dddd rrrr
  - Add without carry (`ADD`)
  - Rd <- Rd + Rr
  - `ADD Rd, Rr`
  - PC <- PC + 1
  - 5.2
* - 1001 0110 KKdd KKKK
  - Add Immedidate to Word (`ADIW`)
  - R[d+1]:Rd <- R[d+1]:Rd + K
  - `ADIW Rd+1:Rd,K`
  - PC <- PC + 1
  - 5.3
* - 0010 00rd dddd rrrr
  - Logical AND (`AND`)
  - Rd <- Rd & Rr
  - `AND Rd, Rr`
  - PC <- PC + 1
  - 5.4
* - 0111 KKKK dddd KKKK
  - Logical AND with Immediate (`ANDI`)
  - Rd <- Rd & K
  - `ANDI Rd, K`
  - PC <- PC + 1
  - 5.5
* - 1001 010d dddd 0101
  - Arithmetic Shift Right (`ASR`)
  - ![ASR Operation](pictures/asr.png)
  - `ASR Rd`
  - PC <- PC + 1
  - 5.6
* - 1001 0100 1sss 1000
  - Bit Clear in SREG (`BCLR`)
  - SREG(s) <- 0
  - `BCLR s`
  - PC <- PC + 1
  - 5.7
```

[^carry_flag]: The carry flag C comes from the status register.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Busses

Inside the microcontroller, components communicate with each other using sets of parallel connectors known as buses. The processor is connected to the main memory by three separate buses as illustrated in {numref}`wk8:fig:busses`. 

```{figure} pictures/mc_busses.png
:alt: The three busses in the ATmega328 microntroller
:name: wk8:fig:busses
:width: 100%
:align: center

The three busses in the ATmega328 microntroller.
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

The three buses are:
- **Address bus**: a unidirectional bus from the processor to the memory or an I/O controller that carries the location of the data to be read from or written to. 
- **Data bus**: a bi-directional pathway that carries data or instructions between processor components. The width of data bus is key in determining the overall computer performance. The AVR CPU data bus is 8-bits wide but the word size is 16-bits meaning the data bus has to use two cloxk cycles to fetch each byte of a word from the main memory.
- **Control bus**: is a bi-directional pathway that carries command, timing and specific status information among components. Examples of control information include:
  - Read/write from/to memory
  - Read/write from/to I/O port
  - Request access to the data bus
  - Grant access to the data bus
  - Sync clock
  - Reset

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
