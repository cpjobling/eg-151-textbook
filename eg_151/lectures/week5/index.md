---
jupytext:
  formats: md:myst,ipynb
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

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

(week5)=
# Introduction to Programming with C

```{image} ../week3/pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true, "jp-MarkdownHeadingCollapsed": true}

C is a high-level structured programming language which is often used for writing microcontroller applications. This weeks lecture will cover good coding practices, C language operators and how they can be grouped as well as flow control structures.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

 
```{image} ../week3/pictures/contents_image.png
:alt: Decorative image used as a slide background
:width: 50%
```

## Lecture Topics
In this chapter we will be looking at how to produce clear well commented programs; data transfer, arithmetic, logic and relational operators; and flow control structures including `if`, `switch-case`, `for` and `while`.

- {ref}`wk4:c-language`
  - {ref}`wk4:code_formattting`
  - {ref}`wk4:comments`
  - {ref}`wk4:pre_processor_directives`
  - {ref}`wk4:statements`
  - {ref}`wk4:variables`
  - {ref}`wk4:operators`
- {ref}`wk4:flow_control`
  - {ref}`wk4:if`
  - {ref}`wk4:for`
  - {ref}`wk4:while`
  - {ref}`wk4:switch`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:c-language)=
## C-language

Code Formatting, comments, pre-processor directives, statements and operators

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:code_formattting)=
### Code formatting

1. Write comments that explain what the program does?

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

2. Use descriptive names for variables and functions

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

3. Use tabs to indent nested code blocks

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

4. Give each class/function one purpose

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

5. Delete unnecessary/redundant code

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

6. Readability is more important than cleverness

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

7. Adopt and maintain a consistent coding style

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

8. Write good comments

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

9. Refactor, refactor, refactor

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

10. Take regular backups and implement version control

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```c
/*
This is a demonstration program for EG-151 microcontrollers that shows a tidy well commented program.

This program asks a user to input two numbers and uses the function findmax to determine which is the largest.

Author: Ben Clifford
Date: 12/10/2019
*/

// include library files
#include <stdio.h> //Required for scanf and printf

// main function
int main(void)
{
    // Variable Declarations
    int num1, num2, maxnum;
    // Function Declarations
    int findmax(int, int);

    printf("Enter the first number: ");
    scanf("%u", &num1);
    printf("Enter the second number: ");
    scanf("%u", &num2);
    
    /* invoke the function findmax passing numl and num2 
        as arguments and storing the result in the variable maxnum 
    */
    maxnum = findmax(num1, num2);
    printf("The maximum number is %u", maxnum);
}

// Definition of the findmax function 
int findmax(int x, int y) 
{
    int maximum_number;
    if (x >= y)
    {
        maximum_number = x;
    }
    else
    {
        maximum_number = y;
    }
    return maximum_number;
}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

[Execute this code using **onlinegdb.com**](https://onlinegdb.com/nGRrGSCI4)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:comments)=
### C language comments

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* Comments are added to code in order to make the program easier to read and understand at a later time or by another reader.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* When the compiler is reading the file, the comments are ignored.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* Comments must follow a set of rules and a particular format.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* In the ‘C’ language comments are surrounded by `/* comment*/` and can span multiple lines **or start with `//` if they are on a single line**.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Examples of comments

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

Single line comment $\rightarrow$ typically found after a statement

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```c
A = 10; This line sets variable A to 10
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

Multi line comment $\rightarrow$ typically used at the start of a program or to detail a block of code or a function

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```c
/* This comment 
spans multiple lines */
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:pre_processor_directives)=
### Pre-processor directives

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* The pre-processor is **part of the compilation process** and runs *before* the code is compiled.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* The pre-processor looks for lines of **code beginning with a `#`** and evaluates them before compilation.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* There are also a number of **predefined *macros*** which can be called and these are surrounded by "`__`" characters.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

* The most commonly used pre-processor directives, and also the ones we will be using, are `#include` and `#define`.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

#### Some pre-processor directives

```c
#include
#define
#undef
#if
#elif
#endif
#ifdef
#ifndef
#error
__FILE__
__LINE__
__DATE__
__TIME__
__TIMESTAMP__
# macro operator
## macro operator
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### The `#include` directive

The **`#include` directive** is used to include **header files** which contain declarations of existing and frequently used functions that can be substituted into your program.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Header files may contain custom function definitions, common functions, secondary data type definitions, etc.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```c
/* 
  This variant is used for system header files. 
  The pre-processor searches for a file named in a 
  standard list of system directories
*/
#include <header_file.h`>
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```c
/* 
   This variant is used for header files of your own program. 
   It searches for the file name first in the current directory, 
   then in the same directories used for system header files. 
*/
#include “my_library.h”
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### The `#define` directive

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

The **`#define` directive** is used to **define a macro** – when the macro name appears in code it will be replaced with the definition stated.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

##### Example: define a value for a symbol

```c
#define pi 3.1415
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

In this example the programmer is stating that the letters `pi` represent the number 3.1415. Now, in the program they can write
```c
A = pi * r * r;
```
and after pre-processing the compiler will see
```c
A = 3.1414 * r * r;
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

##### Example: define a block of reusable code

```c
#define cube(x) (x) * (x) * (x)
```

If the programmer writes:
```c
v = cube(2) // = 8
```

The compiler sees:
```
v = (2) * (2) * (2)  // = 8
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:statements)=
### Statements in C

C functions are made up from **statements**, each of which is **terminated with a semicolon `;`**.[^semicolon]

**A statement is made up of at least one *operator* and some *operands***.

*Operands* can be variables or data.

[^semicolon]: Missing the semicolon is one of the most common causes of compilation errors in C programming.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### C functions

{numref}`week5:fig:function_bd` is a schematic diagram of the C function. You can think of it as something that takes some inputs (arguments) and returns some output.

```{figure} pictures/function_bd.png
:alt: A schematic diagram of a function in C
:width: 100%
:name: week5:fig:function_bd

A schematic diagram of a function in C
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### C code for a function

A simple function is presented below.
```c
/* 
  This function is called a_function. 
  It takes no aguments (inputs).
  It returns no output.  
*/
void a_function(void)
{
    statement1;
    statement2;
}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:variables)=
### Variables in C

The term *variable* is used for a name which describes a memory address. These names follow the same naming convention as used for functions[^variable_names].
[^variable_names]: Similarly to a function these variable names need to be declared before their use indicating their data type. More on this can be found in the self-directed study material for on [Canvas for this week](https://canvas.swansea.ac.uk/courses/44971/pages/week-4-history-of-the-c-language-functions-and-data-types).

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

For example, a variable named `num1` describes a particular memory address at which the first number is found and a second variable `num2` describes a second memory address while a third variable, `total`, is a third memory address.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

In a function we may then have the following statements:

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

```c
num1 = 10;
num2 = 20;
total = num1 + num2; // 30!
`````

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Each of the statements in the example above tells the computer system to **assign/store a value into the memory address** described by the variable. This is called *assignment*.

Assignment statements use the **equals (`=`) sign** to assign the value on the right of `=` to the variable on the left of `=`[^assignment]

[^assignment]: Please do not confuse `=` in C with equality in mathematics. After assignment, the value in the variable can change. In mathematics $a = b$ means that $a$ is always equal to $b$. If we change the value of $b$,
the value of $a$ changes too. In C, `a = b` *copies* the current value of `b` into the storage assigned to `a`. If we change the value of `b` later, `a` will not change.  To confuse matters still further, there is another use
of the equals symbol: `==` means *is equal to* and is used in decision statements such as *is `num1` equal to `num2`*?

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:operators)=
### Operators in C

Each statement or instruction is made up of operators and operands, where the *operator* represents an action and the *operands* represents the data.

In C, the operators can be split into four categories based on the type of actions that they perform[^similar_in_assembler].

[^similar_in_assembler]: We will see similar categories of operators when we come to look at assembly language. For example, for *data transfer* we have the register instructions `LDI` (load register immediate), `LDS` (load register from store), and `STS` (store register to store).e)

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

They are:

1. {ref}`wk4:data_transfer_ops`
2. {ref}`wk4:arithmetic_ops`
3. {ref}`wk4:logical_ops`
   - {ref}`wk4:bitwise_ops`
   - {ref}`wk4:relational_ops`
6. {ref}`wk4:program_ctrl_ops`

We will consider each of these in the following sections.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:data_transfer_ops)=
#### **Data transfer** operators in C

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:arithmetic_ops)=
#### **Arithmetic** operators in C

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:logical_ops)=
#### **Logical** operators in C

(wk4:bitwise_ops)=
##### **Bitwise logical** operators in C

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:relational_ops)=
##### **Relational** operators in C

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:program_ctrl_ops)=
#### **Program control** operators in C

These are discussed in the next section {ref}`wk4:flow_control`.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:flow_control)=
## Flow control
```{image} ../week4/pictures/prog_lang_wallpaper.jpg
:alt: Decorative section background - showing code
```
Flow control statements `if`, `for`, `while`, and `switch`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:if)=
### The *if*-statement in C

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:if-else)=
#### The *if-else*-statement

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:if-elseif-else)=
#### The *if-elseif-else*-statement

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:for)=
### The *for*-statement in C

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:nested)=
#### Nested *for*-statements

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:while)=
### The *while*-statement in C

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:do-while)=
#### The *do-while*-statement

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:switch)=
### The *switch*-statement in C

+++ {"editable": true, "slideshow": {"slide_type": ""}}

## Summary
In this lecture we have:
- Covered basic concepts in coding to create clear and concise code as well as how to add comments to key lines of a program.
- Introduced and discussed the different operators available to the C language programmer including how they are categorized.
- Looked at the flow control statements available in the C language as well as how they are represented using flowchart diagrams and examples of the required syntax.

## On Canvas

This week on the canvas course page, there is a series of short videos providing a history of the C language and a brief overview of programming paradigms as well as videos on functions and data type with a quiz to test your knowledge

```{code-cell} ipython3
---
editable: true
slideshow:
  slide_type: ''
---

```
