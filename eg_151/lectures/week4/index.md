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

(week4)=
# Introduction to Programming and Program Development

```{image} ../week3/pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

+++ {"slideshow": {"slide_type": "slide"}}

## Introduction

When developing an application to run on a microcontroller or other embedded system, there are five key steps which should be followed:

1. Clearly define the requirements of the system, planning the number of inputs and outputs required, speed, storage etc. to identify suitable hardware candidates.
2. Plan/design the software using flowcharts and pseudocode to describe the program and identify functions, or blocks of code, and how they link to other blocks.
3. Translate the flowchart into the required programming language.
4. Once the program is at a level where its functionality can start to be tested, testing and debugging is performed to look for errors or unexpected behaviour in software called bugs.
5. When the final software is commissioned, it is important to document the code so as a developer can come back to it at later date or pass the task to another team member.

+++ {"slideshow": {"slide_type": "slide"}}

## Lecture Topics

```{image} ../week3/pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```

- {ref}`week4:useful_terminology`
- {ref}`week4:programming_languages`
- {ref}`week4:flowcharts`
- {ref}`week4:modular_programming`

+++ {"slideshow": {"slide_type": "slide"}}

(week4:useful_terminology)=
## Useful Terminology

![](pictures/prog_wallpaper.png)

+++ {"slideshow": {"slide_type": "slide"}}

### Hello, World!

{numref}`week4:fig:hello_world` is a reproduction of "Hello, world!" written in C.

+++ {"slideshow": {"slide_type": "fragment"}}

```{figure} https://upload.wikimedia.org/wikipedia/commons/3/39/C_Hello_World_Program.png
:name: week4:fig:hello_world
:alt: Hello World programme written in C
:width: 75%

Hello World programme written in C (Image source: [en.wikipedia.org/wiki/File:C_Hello_World_Program.png](https://en.wikipedia.org/wiki/File:C_Hello_World_Program.png))
```

+++ {"slideshow": {"slide_type": "notes"}}

The first version of **Hello, World!** was published in the classic book Kerningham and Ritchie, The C Programming Language, 1st Ed. Prentice Hall, 1978. 

Since then, it has become common to introduce each new programming language with a version of this program.

Unfortunately, there is a lot of hidden complexity in this simple program, and it is not easy to run "Hello, World!" on a microcontroller!

+++ {"slideshow": {"slide_type": "slide"}}

### What is a program?

A program or algorithm is a **recorded sequence of instructions** that **performs a task** or set of tasks when executed **to produce a specific result**.

+++ {"slideshow": {"slide_type": "slide"}}

### What is software?

Software is the term used to describe **collections of programs, libraries, and related data**.

+++ {"slideshow": {"slide_type": "slide"}}

### What is a programming language?

A programming language is a **formal notation comprising a set of instructions and rules** for writing programs.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### Development of programming

+++ {"slideshow": {"slide_type": "notes"}, "editable": true}

The next few slides provide some historical context to the development of computer programming. For example {numref}`week4:fig:ibm704` is a photograph, taken in 1957, of an early mainframe computer based at NASA Langley Research Centre. This may have well been used in the research that led to the moon landing in 1969.

In the early days of programming, programs were typed on teletypes and encoded as ASCII characters onto paper tape ({numref}`week4:fig:punch_tape`). These paper tapes where used to load programs and data into mainframes like that shown in {numref}`week4:fig:ibm704`. Later, programs were stored on magnetic tape, then magnetic disks and these days are stored servers to be downloaded over networks and loaded into powerful PCs or mobile devices using flash memory and SSD drives.

{numref}`week4:fig:modern_programming` shows an image of a modern laptop and the programming tools and languages (in this case Python) that are used to develop programs these days.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

```{figure} pictures/ibm704.png
:alt: Man and woman shown working with IBM type 704 electronic data processing machine used for making computations for aeronautical research at Langley Research Center.
:name: week4:fig:ibm704

IBM type 704 electronic data processing machine used for making computations for aeronautical research at NASA Langley Research Center – 21st March 1957. (Image source: [www.flickr.com/photos/nasacommons/9467782802](https://www.flickr.com/photos/nasacommons/9467782802))
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

```{figure} pictures/punch_tape.png
:alt: a picture of some punched paper tape
:name: week4:fig:punch_tape

Early program source code! Input into a computer with punched paper tape. Image Source: [How it was: Paper tapes and punched cards | EETimes](https://www.eetimes.com/how-it-was-paper-tapes-and-punched-cards/)
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

```{figure} pictures/modern_programming.png
:alt: A computer screen with a bunch of code on it
:name: week4:fig:modern_programming

Writing programs on a modern high resolution display screen. (Image source: [unsplash.com/photos/ieic5Tq8YMk](https://unsplash.com/photos/ieic5Tq8YMk) by Chris Reid) 

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

(week4:programming_languages)=
## Programming Languages

```{image} pictures/prog_lang_wallpaper.jpg
:alt: Decorative section background - showing code
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### Programming Language Level Vs Complexity

{numref}`week4:fig:pl_complexity` shows how code complexity that must be handled by the programmer is related to language level.

```{figure} pictures/prog_lang_complexity.png
:name: week4:fig:pl_complexity
:alt: A pyramid comparing code complexity with language level.
:width: 100%

Programming language level versus complexity.
```

+++ {"slideshow": {"slide_type": "notes"}, "editable": true}

There is more code complexity at the top because the languages there are "low level" - you need to tell the computer what to do at a very granular level. Languages at the bottom of the pyramid are "high-level" because they provide a simpler way for the programmer to define complex operations without needing to be explicit about how the processor will perform the tasks. Tools are needed to convert that code into the low-level instructions that the computer needs to execute. High-level codes are converted into machine code by compilers, interpreters and web browsers.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### Programming levels

```{figure} pictures/wc_programming_languages.png
:alt: Word cloud of common programming languages.
:width: 50%
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### High-level languages

- High level languages are written in a form that is close to human language, enabling the programmer to just focus on the problem being solved without any knowledge of the hardware it is running on.

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

- Examples include: C++, Java, Pascal, Python, Visual Basic.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### Low-level languages

- Low level languages are used to write programs that relate to the specific architecture and hardware of a particular type of computer and are much closer to the native language of a computer (binary).

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

- Examples include:  Assembly Language, Machine Code

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### The C Programming language

> C is a general-purpose computer programming language. It was created in the 1970s by Dennis Ritchie, and remains very widely used and influential. [Wikipedia - C (programming language)](https://en.wikipedia.org/wiki/C_(programming_language))

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

- C might be described as a "mid-level language". It is a compiled language and it has features that allow code to be written at a fair distance from the machine instructions. At the same time it provides structures that allow the detailed manipulation of data, memory and I/O at a level that is quite close to the machine.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

- In this course, we will be using a dialect of C that has been specifically designed for the programming of Arduino devices such as the 8-bit Atmel ATmega328 which is used in the Arduino Nano.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

- C is a very influential language. It is still used widely for writing operating system kernels, command-line tools, hardware drivers, and microcontroller applications.  The syntax of C is the basis of many of the compiled and interpreted high-level languages that are in use today.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

(week4:flowcharts)=
## Flowcharts

```{image} https://upload.wikimedia.org/wikipedia/commons/a/a6/Flowchart_structured_programming.svg
:width: 50%
:alt: A flowchart
```

This [Image](https://commons.wikimedia.org/wiki/File:Flowchart_structured_programming.svg) by Unknown Author is licensed under [CC BY-SA](https://creativecommons.org/licenses/by-sa/3.0/)

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### What is a Flowchart?

A flowchart is a **pictorial representation** of the **logic flow** through a program.

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

Flowcharts are a useful tool for planning, visualizing and documenting a program without having to write any code.

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

Basic flowcharts are convenient because they

- Don't require the viewer to have an in-depth knowledge of programming

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

- Don't require the viewer to have knowledge of a specific programming language

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

- Useful for visualizing how blocks of code interact with one another

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

- Can be a useful tool in identifying flaws and bottlenecks in large and complex algorithms

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### Flowcharts Vs Code

Consider the simple flowchart shown in {numref}`week4:fig:flowchart:hello_world` representing the printing of the text string "Hello, World!"[^string].

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

```{figure} pictures/flowchart_hello_world.png
:name: week4:fig:flowchart:hello_world
:alt: A flowchart representing the hellow world program.
:width: 20%

A flowchart representing the "Hello, World!" program.
```

+++ {"slideshow": {"slide_type": "notes"}, "editable": true}

[^string]: In most programming languages, text is stored in memory as a sequence of binary codes which each represent the individual characters as in `'H'`, `'e'`, `'l'`, `'l'`, `'o'`, `','`, `' '`, `'W'`, `'o'`, `'r'`, `'l'`, `'d'`, `'!'`. Such a sequence is usually called a *string*.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

#### Bash (a command-line *shell* used in Unix and MacOS)

```c
echo "Hello, World!"
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

#### BASIC 

```basic
PRINT "Hello, World!"
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

#### MATLAB 

```matlab
disp('Hello, World!')
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

#### Python


```bash
print("Hello, World!")
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

#### C (for Arduino) 
(a *shell* used in Unix and MacOS)

```c
puts("Hello, World!");
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

#### C++
(a *shell* used in Unix and MacOS)

```c
std::cout << "Hello, World!" << std:endl;
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

#### HTML

```html
<p>Hello, World!</p>
```

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

#### JavaScript

```javascript
document.write('Hello, World!');
```

+++

### Flowchart building blocks

+++

#### Terminal: start/end block
```{image} pictures/fc_terminal.png
:alt: Flowchart start/end block
:width: 20%
```

+++

#### Terminal: program flow
```{image} pictures/fc_flow.png
:alt: Flowchart program flow
:width: 20%
```

+++

#### Process block
```{image} pictures/fc_process.png
:alt: Flowchart process block
:width: 20%
```

+++

#### Suprocess block
```{image} pictures/fc_subprocess.png
:alt: Flowchart suprocess block
:width: 20%
```

+++

#### Decision block
```{image} pictures/fc_decision.png
:alt: Flowchart decision block
:width: 20%
```

+++

#### I/O block
```{image} pictures/fc_io.png
:alt: Flowchart I/O block
:width: 20%
```

+++

### Rules for drawing flowcharts

+++ {"slideshow": {"slide_type": "fragment"}}

- Flowcharts are usually drawn top to bottom but can be also be drawn left to right.

+++ {"slideshow": {"slide_type": "fragment"}}

- Flowcharts must begin with a "start" symbol and finish with an "end" symbol.

+++ {"slideshow": {"slide_type": "fragment"}}

- The spacing between all items should be consistent

+++ {"slideshow": {"slide_type": "fragment"}}

- The direction of flow between each block should be indicated with an arrow.

+++ {"slideshow": {"slide_type": "fragment"}}

- Connecting lines should never overlap.

+++ {"slideshow": {"slide_type": "fragment"}}

In short flow charts should look visually tidy and the program flow should be obvious to the viewer.

+++ {"slideshow": {"slide_type": "slide"}}

### Flowchart Drawing Packages

+++ {"slideshow": {"slide_type": "slide"}}

#### Microsoft Visio (Windows and web only)

```{image} pictures/visio.png
:alt: A screenshot of the Microsoft Vision program being used to draw a flowchart.
:width: 100%
```

+++ {"slideshow": {"slide_type": "slide"}}

#### Microsoft 365

```{image} pictures/ms265_flowchart_symbols.png
:alt: Screenshot of the flowchart symbols available in Microsoft 365 - Word, PowerPoint, Excel, etc.
:width: 100%
```

Get [Swansea University Office 365 (now Microsoft 365)](https://myuni.swansea.ac.uk/it-services/software-enquiry/office-365/) from myuni.swan.ac.uk.

+++ {"slideshow": {"slide_type": "slide"}}

### Other flowchart drawing tools

#### SmartDraw 

For MacOS

```{image} pictures/smartdraw.png
:alt: Screenshot from the smartdraw flowchart editor
:width: 75%
```
[www.smartdraw.com](https://www.smartdraw.com/)

+++ {"slideshow": {"slide_type": "slide"}}

#### Creately

Web-based drawing tool

```{image} pictures/creately.png
:alt: Screenshot from the creately flowchart editor
:width: 50%
```

[creately.com/diagram-type/flowchart/](https://creately.com/diagram-type/flowchart/)

+++ {"slideshow": {"slide_type": "slide"}}

### Using flowcharts to capturing the most common program constructs

From a software designer's point of view, any program function can be described using only three program constructs:

- **Sequence**: this construct performs one task after another in a sequence. It is a group of instructions to be performed one after another in the order shown in the program. 
- **Decision**: this construct performs a task or a sequence of tasks based on the result of a test condition.
- **Repetition**: this construct is for a process that repeats until a condition which will stop the process is satisfied[^repetition]. Repetition is used to repeat a a sequence over and over again. 

+++ {"slideshow": {"slide_type": "notes"}}

[^repetition]: Repetition is used a lot in microcontroller programming.

+++

## Program Constructs

From a software designer’s point of view, any program function can be described using only three program constructs:

- **Sequence**: this construct performs one task after another in a sequence. It is a group of instructions to be performed one after another in the order shown in the program. 
- **Decision**: this construct performs one of several tasks based on the result of a test condition.
- **Repetition**: This construct is for a process that repeats until a condition is satisfied to stop the process. It is used to repeat a program segment over and over until a condition is satisfied[^repetition]. 

[^repetition]: Repetition is used a lot in microcontroller programming.

+++ {"slideshow": {"slide_type": "slide"}}

#### Sequence

A sequence ({numref}`week4:fig:fc_sequence`) is represented as a set of process blocks (tasks) connected by program flows. The tasks are executed in the order shown by the arrows from top to bottom.


```{figure} pictures/fc_sequence.png
:name: week4:fig:fc_sequence
:alt: Flowchart for a sequence of instructions computed in the order shown, one after the other.
:width: 20%

Flowchart for a sequence of tasks
```

+++ {"slideshow": {"slide_type": "notes"}}

The program shown in {numref}`week4:fig:fc_sequence` might be represented in *psuedocode*[^psuedocode] as

```
START;
 Task 1;
 Task 2;
 Task 3;
END;
```

[^psuedocode]: is a formal text which is used to represent the operation of a section of code in a way that can be understood without needing to resort to formal rules of a programming language.

+++ {"slideshow": {"slide_type": "slide"}}

#### Decision

A decision ({numref}`week4:fig:fc_decision`) is represented as a decision block followed by flows which depend on the outcome of the decision.


```{figure} pictures/decision.png
:name: week4:fig:fc_decision
:alt: Flowchart for a decision.
:width: 30%

Flowchart for a decision
```

+++ {"slideshow": {"slide_type": "notes"}}

The program shown in {numref}`week4:fig:fc_decision` might be represented in psuedocode as

```
START;
 IF condition one is true
   DO
       Task 1;
       :
   END_DO
 IF condition two is true
   DO
       Task 2;
       :
   END_DO
END;
```

+++ {"slideshow": {"slide_type": "slide"}}

#### Repetition

Repetition ({numref}`week4:fig:fc_repetition`) is represented as a decision block, then a sequence of tasks and a flow that returns to the original decision. The tasks are repeated until the condition for ending the repeated sequence is met.


```{figure} pictures/repetition.png
:name: week4:fig:fc_repetition
:alt: Flowchart for a sequence of instructions computed in the order shown, one after the other,
:width: 30%

Flowchart for a sequence of tasks
```

+++ {"slideshow": {"slide_type": "notes"}}

The program shown in {numref}`week4:fig:fc_repetition` might be represented in psuedocode as

```
START;
 UNTIL condition is true
   Task 1;
   :
   Task n;
 THEN
   Task 2;
   :
END;
```

+++ {"slideshow": {"slide_type": "slide"}}

### Example 1: A sequence

+++ {"slideshow": {"slide_type": "fragment"}}

Task: *Find the sum of numbers 1 to 10*

+++ {"slideshow": {"slide_type": "fragment"}}

Program design method 1: 

- Brute force method using the Sequence construct,
- Add number 1 to sum, then add, number 2, then add number 3 ...
- Continue the process until all numbers are added!

+++ {"slideshow": {"slide_type": "slide"}}

#### Solution to task as a sequence

{numref}`week4:fig:task1_sequence` shows the flow chart of this program.

```{figure} pictures/task1_sequence.png
:name: week4:fig:task1_sequence
:alt: Flowchart of a program to sum the first 10 numbers written as a sequence.
:width: 20%

Flowchart of a program to sum the first 10 numbers written as a sequence.
```

+++ {"slideshow": {"slide_type": "slide"}}

#### Program shown in {numref}`week4:fig:task1_sequence` written in pseudo code

```
START
  sum = 0
  sum = sum + 1
  sum = sum + 2
  sum = sum + 3
  :
  sum = sum + 10
END
```

+++ {"slideshow": {"slide_type": "slide"}}

### Example 2: Decision and a Loop

Task: *Find the sum of numbers 1 to 10*

+++ {"slideshow": {"slide_type": "fragment"}}

Program design method 2: 

- Use the decision and repetition constructs:

+++ {"slideshow": {"slide_type": "slide"}}

#### Solution to task 1 using a decision and repetition

{numref}`week4:fig:task1_loop` shows the solution of task 1 using a decision and repetition.

```{figure} pictures/task1_loop.png
:name: week4:fig:task1_loop
:alt: Flowchart of the solution to task 1 using a decision and repetition
:width: 30%

Flowchart of the solution to task 1 using a decision and repetition.
```

+++ {"slideshow": {"slide_type": "slide"}}

#### Program shown in {numref}`week4:fig:task1_loop` written in pseudo code

```
START
  sum = 0
  counter = 1
  WHILE counter < 11
  DO 
    sum = sum + counter
    counter = counter + 1
  END_DO
END
```

+++ {"slideshow": {"slide_type": "slide"}}

### Another Example Program

Consider a program that asks a user for a 'limit' value and sums the numbers up to that limit before outputting the sum?

I.e. $\mathrm{sum} = 1 + 2 + 3 + \dots n$

+++ {"slideshow": {"slide_type": "notes"}}

The program that solves this project is illustrated by the flowchart shown in {numref}`week4:fig:example2`. This program has a sequence, a decision and repetition. It also has an input where the limit ($n$) is entered and an output where the sum is displayed. 

+++ {"slideshow": {"slide_type": "slide"}}

```{figure} pictures/example2.png
:name: week4:fig:example2
:align: center
:width: 30%
:alt: A program that asks for a limit value and sums numbers up to that limit before outputting the sum.

A program that asks for a limit value and sums numbers up to that limit before outputting the sum.
```

+++ {"slideshow": {"slide_type": "slide"}}

Let us tabulate the results of this program assuming that $n=4$.

+++ {"slideshow": {"slide_type": "fragment"}}

We will complete the table in class:

| **`sum`** | **`counter`** | **`counter > limit`** |
|----------:|--------------:|:----------------------|
| $0$       | $1$           | `No`                  |
|           | $2$           |                       |
|           | $3$           |                       |
|           | $4$           |                       |
|           | $5$           |                       |

+++ {"slideshow": {"slide_type": "slide"}}

### How many ways can we write the same program?

For our program summing the numbers up to a limit, there are three key parts.

- Sum (**S**): `sum = sum + counter` 
- Increment (**I**): `counter = counter + 1`
- Check (**C**): Has condition been met?

These can be theoretically be combined in 8 different ways, the first six of which as shown in {numref}`week4:table:1`. Three implementations three are illustrated in {numref}`

` (variation 6), {numref}`week4:fig:isc` (variation 4), {numref}`week4:fig:isc` (row 2). 

+++ {"slideshow": {"slide_type": "slide"}}

```{list-table} How many ways can a program be written?
:header-rows: 1
:name: week4:table:1
* - Variation
  - Part 1
  - Part 2
  - Part 3
* - 1
  - C
  - S
  - I
* - 2
  - C
  - I
  - S
* - 3
  - I
  - C
  - S
* - 4
  - I
  - S
  - C
* - 5
  - S
  - C
  - I
* - 6
  - S
  - I
  - C
```

+++ {"slideshow": {"slide_type": "slide"}}

```{figure} pictures/sic.png
:name: week4:fig:sic
:align: center
:width: 30%
:alt: Variation 6 - Sum - Increment - Check

Variation 6: Sum - Increment - Check
```

+++ {"slideshow": {"slide_type": "slide"}}

```{figure} pictures/isc.png
:name: week4:fig:isc
:align: center
:width: 30%
:alt: Variation 4 - Increment - Sum - Check

Variation 4: Increment - Sum - Check
```

+++ {"slideshow": {"slide_type": "slide"}}

```{figure} pictures/cis.png
:name: week4:fig:cis
:align: center
:width: 30%
:alt: Variation 2 - Check - Increment - Sum

Variation 2: Check - Increment - Sum
```

+++ {"slideshow": {"slide_type": "slide"}}

#### Any more?

+++ {"slideshow": {"slide_type": "fragment"}}

$$\mathrm{sum} = 1 + 2 + 3 + \cdots + \left(n - 1\right) + n$$

+++ {"slideshow": {"slide_type": "fragment"}}

$$\equiv$$

+++ {"slideshow": {"slide_type": "fragment"}}

$$\mathrm{sum} = n + \left(n-1\right) + \cdots 3 + 2 + 1$$

+++ {"slideshow": {"slide_type": "slide"}}

Let us tabulate the results of this program assuming that $n=4$.

+++ {"slideshow": {"slide_type": "fragment"}}

| **`sum`** | **`counter`** | **`counter > limit`** |
|----------:|--------------:|:----------------------|
| $0$       | $4$           |                  |
|           | $3$           |                       |
|           | $2$           |                       |
|           | $1$           |                       |
|           | $0$           |                       |

+++ {"slideshow": {"slide_type": "fragment"}}

A flow chart that implements this variation is given in {numref}`week4:fig:var4`.

+++ {"slideshow": {"slide_type": "slide"}}

```{figure} pictures/var4.png
:name: week4:fig:var4
:align: center
:width: 30%
:alt: Another variation - Check - Decrement - Sum

Another variation: Check - Decrement - Sum
```

+++ {"slideshow": {"slide_type": "slide"}}

(flow_chart_task)=
#### Self-directed learning


1. See if you can write the other eight flowcharts for a program that sums the numbers 1 to n.

2. To get you thinking from a programmer's point of view, consider the steps required to perform a task we usually take for granted, such as making a cup of tea, and what a flowchart for this might look like.

3. After you’ve had a go at these, drop a message on the [discussion forum for this week](https://canvas.swansea.ac.uk/courses/44971/discussion_topics/366215?module_item_id=2258078) to let us know how you got on and which drawing package you found the best. Feel free to include any tips you find useful.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

(week4:modular_programming)=
## Modular Programming

```{image} pictures/modular_prog_wallpaper.png
:alt:
:width: 50%
```
This [Image](https://commons.wikimedia.org/wiki/File:Flowchart_structured_programming.svg) by Unknown Author is licensed under [CC BY-SA](https://creativecommons.org/licenses/by-sa/3.0/)

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

### What is a module?

The basic approach to modularization is to consider a top-down design where the top level defines the main function, and a separate module represents each smaller function in the program (see {numref}`week4:fig:a_modular_program`.

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true}

```{figure} pictures/modules.png
:name: week4:fig:a_modular_program
:alt: A program built from modules
:width: 50%

A program built from modules
```

+++ {"slideshow": {"slide_type": "notes"}, "editable": true}

Each module is treated as a box which can have an input and output.

As long as the input and output requirements remain the same, the module code can be changed without affecting the rest of the program.

+++

#### Example Task

Write a program to perform n different tasks with a ten second delay between each task.

+++

The program we have been discussing that sums the numbers 1-10 can be used to simulate a delay.

+++ {"slideshow": {"slide_type": "slide"}}

##### Example program - Non-Modular Approach

```
DO 
  Task 1
END

/* Delay between task 1 and task 2 */
DO
  number = 0
  WHILE number < 11
    DO
      number = number + 1
    END_DO
  END_WHILE
END

DO 
  Task 2
END

/* Delay between task 2 and task 3 */
DO
  number = 0
  WHILE number < 11
    DO
      number = number + 1
    END_DO
  END_WHILE
END

DO 
  Task 3
END

:
```

+++ {"slideshow": {"slide_type": "slide"}}

##### Change the specification

Now suppose that we want to change the delay between tasks to 20 seconds.

Using a non-modular approach the developer/programmer now needs to change the line

```
WHILE number < 11
```

to 

```
WHILE number < 21
```

For each of the n-1 times it is used.

+++ {"slideshow": {"slide_type": "slide"}}

##### Example program - Modular Approach

The code that implements the delay is made into a module which is called when needed

```
MODULE delay
  DO
    number = 0
    WHILE number < 21
      DO
        number = number + 1
      END_DO
    END_WHILE
  END
END_MODULE
```

+++ {"slideshow": {"slide_type": "slide"}}

The modular program becomes:

```
DO 
  Task 1
END

/* Delay between task 1 and task 2 */
DO
  delay
END

DO 
  Task 2
END

/* Delay between task 2 and task 3 */
DO 
  delay
END

DO 
  Task 3
END

:
```

+++ {"slideshow": {"slide_type": "notes"}}

By using a modular approach to program this task, the developer/programmer need only change one value to adjust the delay, independent of how many times the delay is called between tasks in the program.

+++ {"slideshow": {"slide_type": "notes"}}

We can take this idea further by parameterising the delay value itself. To code might now look like:

```
MODULE delay(delay)
  DO
    number = 0
    WHILE number < delay
      DO
        number = number + 1
      END_DO
    END_WHILE
  END
END_MODULE
```

We can now have variable length delays between tasks:
```
DO 
  Task 1
END

/* Ten second delay between task 1 and task 2 */
DO
  delay(10)
END

DO 
  Task 2
END

/* Twenty second delay between task 2 and task 3 */
DO 
  delay(20)
END

DO 
  Task 3
END

:
```


We will return to this idea when we look at functions in C.

+++ {"slideshow": {"slide_type": "slide"}}

#### Activity

With the time remaining can you represent this program as a flow chart?

Feel free to work individually or in small groups

+++ {"slideshow": {"slide_type": "slide"}}

##### Solution

See {numref}`week4:fig:exercise_solution` in the notes online.


+++ {"slideshow": {"slide_type": "notes"}}

```{figure} pictures/exercise_soln.png
:name: week4:fig:exercise_solution
:alt: Implementing a delay sub-program 
:width: 50%

Implementing a delay sub-program using a modular approach
```

+++ {"slideshow": {"slide_type": "slide"}}

## Summary

In this chapter we have:
- Defined terminology relating to programming and looked at how languages can be classified as high or low based on the level of abstraction from the architecture it is to be run on. 
- Looked at flowcharts defining the standard symbols and looking at how they are used to represent a program.
- Introduced the use of sub-processes to allow modular programming for splitting up a program or repeating common elements.

+++ {"slideshow": {"slide_type": "slide"}}

## Any Questions?

+++ {"slideshow": {"slide_type": "slide"}}

## On Canvas

This week on the canvas course page, there is:
- a [short video by Ben Clifford providing more of an introduction to programming languages and the compilation process](https://canvas.swansea.ac.uk/courses/44971/pages/introduction-to-programming-languages?module_item_id=2258077); 

+++ {"slideshow": {"slide_type": "fragment"}}

- a [discussion forum](https://canvas.swansea.ac.uk/courses/44971/discussion_topics/366215?module_item_id=2258078) to talk about the {ref}`flow_chart_task`; 

+++ {"slideshow": {"slide_type": "fragment"}}

- some [supplementary resources](https://canvas.swansea.ac.uk/courses/44971/pages/week-4-supplementary-resources?module_item_id=2258079); and 

+++ {"slideshow": {"slide_type": "fragment"}}

- a [quiz to test your knowledge](https://canvas.swansea.ac.uk/courses/44971/assignments/321260/edit?module_item_id=2415567&quiz_lti=true).
