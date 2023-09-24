---
jupytext:
  formats: ipynb,md:myst
  main_language: python
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: ''
  name: ''
---

+++ {"slideshow": {"slide_type": "slide"}}

(week1)=
# Introduction to Microcontrollers and Microcontroller Architecture

![](pictures/cover.png)

(week1:introduction)=

+++ {"slideshow": {"slide_type": "slide"}}

## Introduction

In this week's lecture, you will be given an introduction to microcontrollers focussing on what a microcontroller is, where they can be found and how they can be described using the their *architecture*. The lecture then moves on to introduce the Atmel ATmega328 microcontroller, which will be used in the practical sessions in this course, looking at its core architecture including the function of the arithmetic logic unit and registers.

+++ {"slideshow": {"slide_type": "slide"}}

(week1:toc)=
## Topics Covered in this Lecture

```{image} pictures/slide2.png
:alt: A decorative image showing code, a microntroller chip and the Arduino nano microcontroller board used in the lab component of this module.
:width: 50%
```

- {ref}`week1:what_is_a_uc`
- {ref}`week1:where_are_uc_used`
- {ref}`week1:architecture`
- {ref}`atmel_atmega328`

+++ {"slideshow": {"slide_type": "slide"}}

(week1:what_is_a_uc)=
## What is a Microcontroller?

```{image} pictures/micro_chip.jpg
:alt: A decorative image showing a microcontroller chip
:width: 25%
```

A microntroller is a compact integrated circuit designed to govern a specific operation or set of operations within an embedded system.

At a high level of abstraction, a microntroller includes three core components within a single chip:

- A central processing unit (CPU)
- Memory, and
- Input/output (I/0) peripherals

+++ {"slideshow": {"slide_type": "slide"}}

(week1:where_are_uc_used)=
## Where are Microcontrollers Used?

```{image} pictures/uses_of_micros.png
:alt: An image illustrating that micronctrollers are used in the automotive industry, cosnumer electronics, industrial and control sytems, and environmental monitoring
:width: 50%
```
Microcontrollers are used in the automotive industry, consumer electronics, industrial and control systems, and environmental monitoring and many other areas of engineering.

+++ {"slideshow": {"slide_type": "slide"}}

### Automotive applications

![Automotive applications of microcontrollers](https://media.licdn.com/dms/image/C5612AQFlXXRGbDj1iQ/article-cover_image-shrink_423_752/0/1548696054359?e=1697068800&v=beta&t=jQnmQP2oTqRSY17lAliHfiSlMdcckGRRhzzpcrfLA7s)

Image source: [www.linkedin.com/pulse/microcontrollers-used-automotive-applications-field-amin-agina](https://www.linkedin.com/pulse/microcontrollers-used-automotive-applications-field-amin-agina).

+++ {"slideshow": {"slide_type": "fragment"}}

<table>
<tr>
<td>
<ul>
    <li>Engine Control</li>
<li>Heating/Cooling</li>
<li>Central Locking</li>
<li>Navigation</li>
<li>Cruise Control</li>
<li>Lighting</li>
<li>Radio</li>
<li>Charging System</li>
</li>
</ul>
</td><td>
<ul>
    <li>Exhaust Control</li>
    <li>Parking Assistance</li>
    <li>Wipers</li>
    <li>Occupancy / Airbags</li>
    <li>ADAS</li>
    <li>Collison Warning</li>
    <li>Speed limiter</li>
    <li>Battery Monitoring</li>
</ul>
</td>
</tr>
</table>

+++ {"slideshow": {"slide_type": "slide"}}

### Consumer electronics

![Photograph showing the microcontroller inside a smart watch](https://static.electronicsweekly.com/wp-content/uploads/2015/10/14194030/6a238902a5a6bcc5a0e42f2133959272_original.jpg)

Image source: [www.electronicsweekly.com/blogs/distribution-world/communities/innovative-smartwatch-challenges-apples-watch-design-2015-10](https://www.electronicsweekly.com/blogs/distribution-world/communities/innovative-smartwatch-challenges-apples-watch-design-2015-10)

+++ {"slideshow": {"slide_type": "fragment"}}

<table>
<tr>
<td>
<ul>
    <li>Smart watch</li>
<li>Mobile phone</li>
<li>Air conditioner</li>
<li>Printer</li>
<li>Calculator</li>
<li>Hair dryer</li>
</li>
</ul>
</td><td>
<ul>
    <li>Alarm clock</li>
    <li>Microwave</li>
    <li>Wipers</li>
    <li>Fridge freezer</li>
    <li>Power tool</li>
    <li>Remote control</li>
</ul>
</td>
</tr>
</table>

+++ {"slideshow": {"slide_type": "slide"}}

### Industrial applications

```{image} https://investinfrance.fr/wp-content/uploads/2020/07/Usine_robot_bleu_1500px.jpg
:alt: Photograph showing robots working on an automated assembly line]()
:width: 50%
```

Image source: [investinfrance.fr/high-technology-industry/robotic-arm-catch-for-electronic-assembly-line-the-robot-for-sm/](https://investinfrance.fr/high-technology-industry/robotic-arm-catch-for-electronic-assembly-line-the-robot-for-sm/)

+++ {"slideshow": {"slide_type": "fragment"}}

<table>
<tr>
<td>
<ul>
    <li>Manufacturing systems</li>
<li>Quality control</li>
<li>Process monitoring</li>
<li>Robotics</li>
<li>Tracking systems</li>
<li>Fire control</li>
</li>
</ul>
</td><td>
<ul>
    <li>Materials processing</li>
    <li>Laboratory equipment</li>
    <li>Machine-to-machine communications</li>
    <li>Networking</li>
    <li>Smart buildings / BMS</li>
    <li>Environmental control/li>
</ul>
</td>
</tr>
</table>

+++ {"slideshow": {"slide_type": "slide"}}

### Envoronmental monitoring

```{image} https://cdn.openpr.com/S/7/S709502617_g.jpg
:alt: Image that illustrated article "Hawa Dawa Installs the Largest Air Quality Measurement Network in Germany"
:width: 50%
```

Image source: [www.openpr.com/news/1799966/hawa-dawa-installs-the-largest-air-quality-measurement-network](http://www.openpr.com/news/1799966/hawa-dawa-installs-the-largest-air-quality-measurement-network)

+++ {"slideshow": {"slide_type": "fragment"}}

<table>
<tr>
<td>
<ul>
    <li>Air quality monitoring</li>
<li>Weather monitoring</li>
<li>Gas sensors</li>
<li>Water quality sensors</li>
<li>Farming</li>
</ul>
</td><td>
<ul>
    <li>Temperature monitoring</li>
<li>Light level monitoring</li>
    <li>Climate change</li>
    <li>Air flow</li>
    <li>Animal/wildlife tracking</li>
</ul>
</td>
</tr>
</table>

+++ {"slideshow": {"slide_type": "slide"}}

### Microcontroller Market Forecast

```{image} https://www.precedenceresearch.com/insightimg/Microcontroller-Market-Share-By-Application-2021.jpg
:alt: Microntroller (MCU) market size, 2021 to 2030 (USD Billion)
:width: 50%
```
Source: [www.precedenceresearch.com/microcontroller-mcu-market](http://www.precedenceresearch.com/microcontroller-mcu-market)

+++ {"slideshow": {"slide_type": "slide"}}

(week1:architecture)=
## How do we Describe Microcontrollers?

+++ {"slideshow": {"slide_type": "slide"}}

### Architecture

Definition from the Oxford English Dictionary [architecture](https://www.oed.com/dictionary/architecture_n?tab=meaning_and_use&tl=true#40006241)

> **Computing**. The conceptual structure and overall logical organization of a computer or computer-based system from the point of view of its use or design; a particular realization of this[^defn].

[^defn]: “architecture, n., sense 6”. Oxford English Dictionary, Oxford University Press, July 2023, <https://doi.org/10.1093/OED/5575991854>

+++ {"slideshow": {"slide_type": "slide"}}

#### Number of Bits

```{image} pictures/nbits.png
:alt: Architecture diagram showing number of bits used in a microcontroller
:width: 50%
```

+++ {"slideshow": {"slide_type": "slide"}}

Categorizing Microcontroller Units (MCUs) as 8-, 16-, or 32-bit designs is one way of classifying their performance capabilities.

The number of bits identifies the size of the registers, the number of available memory addresses and the largest number that can be processed/represented.

As an example, in an 8-bit MC

- Each register is 8-bits (or one byte) wide. 
- There are $2^8$ (or 256) possible memory addresses
- There are $2^8$ integers that can be represented (0 o 255).

Microcontrollers with more bits, for example 16- and 32-bit MCUs have correspondingly more bits per register, more available memory addresses, and can handle larger numbers compared with their 8-bit counterparts.

An introduction to data representation follows in {ref}`week2`.

+++ {"slideshow": {"slide_type": "slide"}}

{numref}`memmap` shows the data memory map of the Atmel Atmega328 which is an 8- bit MCU.

It has $2^8$ or 256 available memory addresses
from 0x0000 – 0x00FF which covers:

- 32 general purpose registers,
- 64 I/O registers, and
- 160 Extended I/O registers

```{figure} pictures/memmap.jpg
:name: memmap
:alt: Memory map for the Atmel Atmega328 MCU
:width: 50%

Memory map for the Atmel Atmega328 MCU
```

+++ {"slideshow": {"slide_type": "slide"}}

##### Applications of 8-bit and 32-bit MCUs

```{image} http://lreese.dotsenkoweb.com/wp-content/uploads/2019/04/Fig-1-VennDiagraml-1024x713.jpg
:alt: Venn diagram of the 8-bit MCU vs. 32-bit MCU benefits from a general perspective, as direct comparisons of all features combined are relative to tradeoffs. In general, the 8-bit MCU has been lower cost and smaller in size than the 32-bit MCU, but 32-bit MCUs are close to competing on cost and both have at least one “specimen” of a similarly minute physical size. In overall power consumption, the slower 8-bit MCUs will always trump the faster 32-bit MCUs as long as manufacturers stay on their game.
:width: 50%
```
Source: [http://lreese.dotsenkoweb.com/2017/07/31/iot-choosing-8-bit-vs-32-bit-mcus](http://lreese.dotsenkoweb.com/2017/07/31/iot-choosing-8-bit-vs-32-bit-mcus)

+++ {"slideshow": {"slide_type": "slide"}}

##### Market share of 8-bit, 18-bit and 32-bit MCUs in 2021

```{image} https://www.precedenceresearch.com/insightimg/Product-Market-Share-By-Product-2021.jpg
:alt:
:width: 50%
```

Source: [www.precedenceresearch.com/microcontroller-mcu-market](http://www.precedenceresearch.com/microcontroller-mcu-market)

+++ {"slideshow": {"slide_type": "slide"}}

#### Memory

```{image} pictures/memory.png
:alt: Architecture diagram showing memory types used in microcontrollers
:width: 50%
```

+++ {"slideshow": {"slide_type": "slide"}}

##### Embedded vs external memory

Memory in modern microcontrollers can be classified as embedded or external dependent on whether this is physically located within the MCU itself or is connected separately.

For most microcontroller-based applications, the internal memory is enough, however applications which gather or buffer large amounts of data may also need external memory in the form of SD cards, M.2 drives and similar.

+++ {"slideshow": {"slide_type": "slide"}}

A Raspberry Pi 4 Model B is illustrated in {numref}`raspberrypi4b`. It has both internal and external memory.


```{figure} https://www.hackatronic.com/wp-content/uploads/2021/11/raspberry-pi-4-specifications-.jpg
:name: raspberrypi4b
:align: center
:width: 60%
:alt: Raspberry Pi 4 Model B

Raspberry Pi 4 Model B
```
Source: [www.hackatronic.com/raspberry-pi-4-specifications-pin-diagram-and-description](http://www.hackatronic.com/raspberry-pi-4-specifications-pin-diagram-and-description/).

+++ {"slideshow": {"slide_type": "slide"}}

##### Volatile vs non-volatile embedded memory

Broadly speaking embedded memory that is found in a microcontroller can be classified into two categories: 

- *Volatile*: data is lost when power is removed &ndash; this is *temporary storage*.
- *Non-volatile*: data is retained when power is removed &ndash; this is *permanent storage*.

+++ {"slideshow": {"slide_type": "slide"}}

Volatile and non-volatile memory can be further classified as illustrated in {numref}`vol-non-vol-memory`.

```{figure} pictures/memory_types.png
:name: vol-non-vol-memory
:align: center
:width: 60%
:alt: Classification of volatile and non-volatile memmory.

Classification of volatile and non-volatile memmory.
```

+++ {"slideshow": {"slide_type": "slide"}}

#### Instruction Set Architectures

```{image} pictures/instruction_set.png
:alt: Architecture diagram showing instruction sets used in microcontrollers
:width: 50%
```

+++ {"slideshow": {"slide_type": "slide"}}

The instruction set architecture (ISA) describes the format and operation of instructions the microcontroller can perform and a microcontroller will often be categorized as having a RISC based or CISC based architecture.

+++ {"slideshow": {"slide_type": "slide"}}

##### Reduced instruction Set Computer (RISC)

A RISC is a device with a small, highly optimized set of instructions which utilizes registers and a highly regular instruction pipeline, allowing instructions to be completed in a low number of clock cycles. In short, several instructions may need to be run to perform a task and this may complicate the coding.

+++ {"slideshow": {"slide_type": "slide"}}

##### Complex Instruction Computer (CISC)

A CISC is a device in which single instructions can execute several low-level operations or are capable of multi-step operations or addressing modes within single instructions. In this instance a program may be easier to read by a human, but the timing will be irregular and difficult to debug or be monitored by a machine.

+++ {"slideshow": {"slide_type": "slide"}}

##### Example

As an example, consider the case where you want to multiply two numbers stored at addresses 0x0010 and 0x0011 respectively.

+++ {"slideshow": {"slide_type": "fragment"}}

On a RISC based architecture microcontroller the code would look something like:

```
LDS r18, 0x0010
LDS r19, 0x0011
MUL r18, r19
```

+++ {"slideshow": {"slide_type": "fragment"}}

However, on a CISC based architecture machine the multiply instruction may be able to perform the memory access instructions within its execution, meaning the code would look like this:

```asm
MUL 0x0010, 0x0011
```

+++ {"slideshow": {"slide_type": "slide"}}

#### Memory Architectures

```{image} pictures/mem_arch.png
:alt: Architecture diagram showing the memory architectures used in microcontrollers
:width: 75%
```

+++ {"slideshow": {"slide_type": "slide"}}

Memory architecture is a different concept from embedded and external and volatile and non-volatile memory. Memory architecture classifications describe where program instructions and data are stored and how they are accessed. 

There are two categories, *Von-Neumann* and *Harvard*.

+++ {"slideshow": {"slide_type": "slide"}}

##### Von-Neumann (Princeton) architecture

In a Von-Neumann architecture, the same memory and bus are used for both data and instructions used by the CPU and peripherals as illustrated in {numref}`fig:week1:vonneuman`.

```{figure} pictures/von_neuman_arch.png
:name: fig:week1:vonneuman
:align: center
:width: 20%
:alt: The Von Neumann architecture - data memory and programme code use the same memory storage area and data busses.

The Von Neumann architecture
```

+++ {"slideshow": {"slide_type": "slide"}}

##### Harvard architecture

The Harvard architecture stores machine instructions and data in separate memory units that are connected to the CPU and peripherals by different busses as illustrated in {numref}`fig:week1:harvard`.

```{figure} pictures/harvard_arch.jpg
:name: fig:week1:harvard
:align: center
:width: 30%
:alt: The Harvard architecture - data memory and programme code use different memory storage areas and busses.

The Harvard architecture
```

+++ {"slideshow": {"slide_type": "slide"}}

##### Modified Harvard architecture

Most modern microcontrollers don't have a physical separation between the memory spaces used by data and instructions, and therefore could be described as Von Neumann for this reason. However, since these microcontrollers often use separate busses for data and instructions, a better way to represent these is as a *modified* Harvard architecture[^note1].

[^note1]: This gets around the bottleneck that can occur using a Von-Neumann memory architecture with lower costs than having two separate memories.

+++ {"slideshow": {"slide_type": "slide"}}

### How is a Microcontroller Described?

In summary, the final MCU classification shown in {numref}`mcu_architecture` represents some of categories under microcontroller architecture which are focussed around the system itself.

There are further classifications as you move towards either the circuit design or the embedded system application.

```{figure} pictures/mem_arch.png
:name: mcu_architecture
:align: center
:width: 75%
:alt: Classification of microcontrollers systems

Classification of microcontroller systems
```

+++ {"slideshow": {"slide_type": "slide"}}

#### System or Core Architecure

In general, most microcontroller manufacturers will present a system wide, or *core architecture* in the form of a diagram which will appear early on in the data sheet for the device.

+++ {"slideshow": {"slide_type": "slide"}}

##### Atmel ATMega328P AVR

For example, {numref}`fig:week1:avr` is taken from Atmel ATMega328 data sheet[^atmega328_data_sheet] and shows a block diagram of the Advanced Virtual RISC (AVR) architecture.

```{figure} pictures/avr_architecture.png
:name: fig:week1:avr
:align: center
:width: 50%
:alt: Block Diagram of the AVR Architecture

Block Diagram of the AVR Architecture (Source: Figure 6.1, Page 9 of the Atmel ATMega328P data sheet)
```

[^atmega328_data_sheet]: Atmel ATMega328 Datasheet. 2015. Microchip. URL: [ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf). Accessed: 11 August 2022. **TODO** Put this into the references and cite it.

+++ {"slideshow": {"slide_type": "slide"}}

##### NXP HCS08 MCU

As another example, the block diagram shown in {numref}`fig:week1:hcs08` represents the architecture of the NXP (formally Motorola) HCS08 MCU.

This MCU, which was used on this module before the Arduino was adopted, does not have a bank of general purpose registers. Instead it has a single working register, known as the *accumulator*, which is involved in most computations that the MCU performs.

```{figure} pictures/hcs08.png
:name: fig:week1:hcs08
:align: center
:width: 50%
:alt: Block Diagram of the HCS08 MCU

Block Diagram of the NXP HCS08 Architecture
```

+++ {"slideshow": {"slide_type": "slide"}}

(atmel_atmega328)=
## The Atmel ATmega 328 Microcontroller

<a title="BregesT65421354, CC BY-SA 4.0 &lt;https://creativecommons.org/licenses/by-sa/4.0&gt;, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:ATMEL_MEGA328P_AU_1328.jpg"><img width="512" alt="ATMEL MEGA328P AU 1328" src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/ATMEL_MEGA328P_AU_1328.jpg/512px-ATMEL_MEGA328P_AU_1328.jpg"></a>

The Atmel&reg; ATMega328/P is a low-power CMOS 8-bit microcontroller based on the AVR&reg; enhanced RISC architecture.

+++ {"slideshow": {"slide_type": "slide"}}

### Introducing the Atmel ATMega328 MCU

- This is an 8-bit CMOS microcontroller based on the AVR&reg; enhanced **RISC architecture** with 131 instructions.

- It has 2KB of Internal SRAM, 32 KB of Flash Memory and 1 KB of EEPROM.

- It has **32 General Purpose Registers**.

- It can achieve up to 20 MIPS at 20 MHz (maximum clock frequency).

- There are **8 Analog I/O** pins connected to **10-bit analogue to digital converter (ADC)**.

- There are **22 Digital I/O pins** (6 capable of *pulse-width modulation* (PWM)).

- The AVR core uses a **Harvard memory architecture** &ndash; with separate memories and busses for program and data.

+++ {"slideshow": {"slide_type": "slide"}}

#### Arithmetic Logic Unit

The **Arithmetic Logic Unit** (ALU) ({numref}`fig:week1:alu`), is the part of the processor that performs arithmetic and logic operations on numbers from the storage area &ndash; it is essentially the &ldquo;brain&rdquo; of the microcontroller.

```{figure} pictures/alu.png
:name: fig:week1:alu
:align: center
:width: 30%
:alt: General purpose arithmetic logic unit (ALU)

General purpose arithmetic logic unit (ALU)
```

+++ {"slideshow": {"slide_type": "slide"}}

- First, numbers are read from storage into the ALU's data input ports.

- Once inside the ALU, they're modified by means of an arithmetic or logic operation (`ADD`, `SUB`, `AND`, `OR`...), and

- Finally, the data is written back to storage via the ALU's output port.

+++ {"slideshow": {"slide_type": "slide"}}

##### Example instruction

![Add without carry instruction for the ATMega328](pictures/add_instruction.png)

+++ {"slideshow": {"slide_type": "slide"}}

##### Example of the ALU from the 74LS181

The 74LS181 is a 4-bit microcontroller that supports 16 logical and 16 arithmetic operations.

You do not need to understand {numref}`74LS181`, it is just and example to show that an ALU isn't just a black box. Rather it contains complex logic circuitry by means of which it performs its operations.

```{figure} pictures/74LS181_ALU.png
:name: 74LS181
:alt: The ALU for the 74LS181 MCU

The ALU for the 74LS181 MCU
```

+++ {"slideshow": {"slide_type": "slide"}}

### Registers

A register is a group of memory bits with special addressing characteristics which is often used for a particular purpose.

- In most modern processors, regardless of architecture, data is loaded from a larger memory space into special registers where it is used for arithmetic operations, manipulation or testing by various machine instructions.
- Data is then temporarily held in a register until it is overwritten, or the immediate instruction stores it back to main memory.

![Use of registers in ATMega328 programms](pictures/registers.png)

+++ {"slideshow": {"slide_type": "slide"}}

#### Registers in the ATMega328 MCU

The Atmel ATmega328 is an 8-bit microcontroller and has 256
addressable registers within the user data space.The first 32
locations address the Register File, the next 64 location the standard
I/O memory and then the remaining 160 locations for Extended I/O
memory.

{numref}`memmap` summarizes the memory map of the ATMega328 MCU. {numref}`mem_map2` shows part of the full memory map that is given in pages 275-280 of the Atmel ATMega280/P data sheet.

```{figure} pictures/mem_map_atmel.png
:name: mem_map2
:align: center
:width: 100%
:alt: Part of the memory map of the Atmel ATMega328/P MCU

Part of the memory map of the Atmel ATMega328/P MCU
```

+++ {"slideshow": {"slide_type": "slide"}}

#### The Register File

The Register file (see {numref}`reg_file`) contains 32 x 8-bit wide registers that are often referred to as general purpose or working registers in the CPU.

```{figure} pictures/reg_file.jpg
:name: reg_file
:align: center
:width: 50%
:alt: The register file for the Atmel ATMega328/P MCU

The register file for the Atmel ATMega328/P MCU
```

+++ {"slideshow": {"slide_type": "slide"}}

Each register is also assigned a data memory address, mapping them directly into the first 32 locations of the **user data space**.

Most of the instructions operating on the Register File have direct access to all registers, and most of them are single cycle instructions, however:

- `R0` &ndash; `R15` are not available for all instructions, and

- `R26` &ndash; `R31` have some added functions as pointer registers.

+++ {"slideshow": {"slide_type": "slide"}}

#### Using the Register File

![Using the registers for an ADD without carry operation.](pictures/reg_file1.png)

+++ {"slideshow": {"slide_type": "slide"}}

![Using the registers for an Load immediate (LDI) operation.](pictures/reg_file2.png)

+++ {"slideshow": {"slide_type": "slide"}}

#### X- Y- Z-Pointer Registers

![The x-, y- and z- registers](pictures/x-y-z-reg.png)

In addition to acting as general purpose
registers, `R26` - `R31` can be used as 16-bit address pointers and
referred to as the X-,Y-, Z-registers. These pointers can be used to
indirectly address the SRAM portion of the data space.

The start address of SRAM is 0x0100, this cannot be accessed with 8-bits (maximum is 0x00FF).

Note: We will look at this in more detail at the end of the module but this approach can be useful to access sets of data where we don't necessarily know the address.

+++ {"slideshow": {"slide_type": "slide"}}

## Summary

In this lecture we have:

-   Familiarized ourselves with what a microcontroller is and where they are used.

-   Introduced describing a microcontroller by considering parts of its
    architecture and

-   Began to look at the Atmel ATmega328 microcontroller focusing on
    its register file and the general-purpose registers.

+++ {"slideshow": {"slide_type": "slide"}}

## On Canvas

There is a quiz which tests your recall of the topics covered in this lecture

+++ {"slideshow": {"slide_type": "slide"}}

## Next week

Next week we will look at {ref}`week2`.
