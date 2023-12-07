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

(week04)=
# Introduction to Programming with C

```{image} ../week02/pictures/chapter_heading.png
:alt: Decorative image for slide show
:width: 50%
```

+++ {"slideshow": {"slide_type": "fragment"}, "editable": true, "jp-MarkdownHeadingCollapsed": true}

C is a high-level structured programming language which is often used for writing microcontroller applications. This weeks lecture will cover good coding practices, C language operators and how they can be grouped as well as flow control structures.

+++ {"slideshow": {"slide_type": "slide"}, "editable": true}

 
```{image} ../week02/pictures/contents_image.png
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
  - {ref}`wk4:switch`
  - {ref}`wk4:while`
  - {ref}`wk4:for`

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

{numref}`week04:fig:function_bd` is a schematic diagram of the C function. You can think of it as something that takes some inputs (arguments) and returns some output.

```{figure} pictures/function_bd.png
:alt: A schematic diagram of a function in C
:width: 100%
:name: week04:fig:function_bd

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

In the C language, the data transfer operations are mostly covered by assignment without ever having to deal directly with the registers.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

For example:

```c
a = 10;
b = 20;
sum = a + b;
PTFD = sum; // output total to PORT F
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

This is because C ia highs -level language and the compiler takes care of he details.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:arithmetic_ops)=
#### **Arithmetic** operators in C

The order of arithmetic operations follow the [BODMAS (BIDMAS)](https://en.wikipedia.org/wiki/Order_of_operations#Mnemonics) rules[^bodmas_rules].

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

| **Operator**  | **Used for**   |
|---------------|----------------|
| `+`           | Addition       |
| `-`           | Subtraction    |
| `*`           | Multiplication |
| `/`           | Division       |
| `%`           | Modulus        |
| `++`          | Increment      |
| `--`          | Decrement      |


[^bodmas_rules]: BODMAS is a *mnemonic* which stands for **B**ackets, **O**perations, **D**ivision/**M**ultiplication, **A**ddition/**S**ubtraction. It describes the order of calculation in an expression that involves operators. Brackets, which are considered first, are used to disambiguate expressions that would otherwise produce wrong results. For example `a + b/c` is intrepreted as $a + (b/c)$ not $(a + b)/c$.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Examples

Aassume `a`, `b` and `c` are defined as variable of type integer (`int`)[^integer_type].

```c
a = r * 5 + 6 / 3;    // -> a = 12;
```
[^integer_type]: An integer type means the value is a whole number (not a fractional number) that can be positive, negative, or zero.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

Brackets can be used to improve readability[^rounding]
```c
b = (3.14 * r * r);   // -> b = 12 not 12.56!   
```
[^rounding]: The execution of expression `3.14 * r * r` would most likely result in a decimal (*floating point*) number. This would be truncated to an integer before it is assigned to `b`. This is a common cause of mathematical error in programming.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

There are also special operators like *increment* and *decrement*
```c
c = c++;  // -> c = c + 1
d = d--;  // -> d = d - 1;
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

Assume `d` to `h` are defined as type integer variables (`int`) and `i` as a floating point number (`float`):
```c
d =  5 / 3;     // -> d = 1:  gives the whole part of the fraction
e =   5 % 3;    // -> e = 2: gives thremainder of the fraction
f  =  6 % 3;    // -> f = 0: gives 0 as there is no remainder
g =   5.5 / 2;  // -> g = 2: float is converted to int
h  =  5.5 % 2;  // -> invalid – will not compile
i   =  5.5 / 2; // -> i = 1.75	- evaluates correctly if i is defined as a float 
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

The same  rules apply to multiplication operation.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:logical_ops)=
#### **Logical** operators in C

Logical operators are used in expressions which return *true* (`1`) or *false* (`0`).

| **Operator** | **Meaning**   |
|--------------|---------------|
| `&&`         | Logical *and* |
| `\|\|`       | Logical *or*  |
| `!` .        | Logical *not* |

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Example of the *and* operator (`&&`)
```c
/* 
   If the voltage is greater than 10 and the
   current is less than 20 the condition is true
   and the value of the expression will be 1, 
   otherwise it is false and the value of the 
   expression will be 0.
*/
if ((voltage > 10) && (current < 20)) {...}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Example of the *or* operator (`&&`)
```c
/*
    If the voltage is greater than 10 or the
    current is greater than 20 the condition is
    true and the value of the expression will be
    1, otherwise it is false and the expression 
    will be 0.
*/
if((voltage > 10) || (current > 20)) {...}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

##### Example of the *not* operator (`!`)
```c
/* 
    The unary operator (!) is usually used to
    turn true into false and vice versa.
*/
c = 0;	// -> c = 0 which is "false"
d = !c; // -> d = 1 which is "true".
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:bitwise_ops)=
##### **Bitwise logical** operators in C

In addition to the logical operators designed to evaluate multiple conditions there are **bitwise logical operators** which operate on the binary digits (bits) of their operands.

| **Operator** | **Used for** |
|--------------|--------------|
| `&`          | bitwise AND  |
| `\|`         | bitwise OR   |
| `^`          | bitwise XOR  |
| `~`          | bitwise NOT  |
| `>>`         | shift right  |
| `<<`         | shift left   |

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

###### Example of the bitwise and operator

```c
b = 0xA3 & 0xD5; // -> b = 0x81
```

```{math}
\begin{array}{lrr}
   & 1010 & 0111 \\
\& & 1101 & 0101 \\\hline
   & 1000 & 0001
\end{array}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

###### Example of the bitwise or operator

```c
c = 0xA3 | 0xD5; // -> b = 0xF7
```

```{math}
\begin{array}{lrr}
   & 1010 & 0111 \\
|  & 1101 & 0101 \\\hline
   & 1111 & 0111
\end{array}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

###### Example of the bitwise not operator

```c
c = ~0xA3; // -> c = 0x5C
```


```{math}
\begin{array}{lrr}
\sim & 1010 & 0111 \\\hline
     & 0101 & 1100
\end{array}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

###### Bitwise operators used for I/O ports

The use of these operators are important when working with microcontrollers, in particular in the case of I/O, as they can be used to mask bits of a port. This is useful in C as we have limited data transfer options, i.e. we have to read/write to an entire port (memory location) rather than an individual bit.

```c
PTAPE = 0x0F;       // bit pattern: 0000 1111
PTAD = 0xF0;        // bit pattern: 1111 0000
PTAD = PTAD | 0x0C;	// bit pattern: 1111 1100
```

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

Since XORing any bit with a 1 forces it to return the opposite value, it can be used to toggle the state of a port:

```c
portA = portA ^ 0xFF; // e.g. 0101 0110 -> 1010 1001
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:relational_ops)=
##### **Relational** operators in C

The final group of operators are the **relational operators** which are used to test a relationship between two variables or a variable and data. 

| **Relational operator** | **Meaning**                 |
|-------------------------|-----------------------------|
| `==`                    | is equal to                 |
| `!=`                    | is *not* equal to           |
| `<`                     | is less than                |
| `<=`                    | is less than or equal to    |
| `>`                     | is greater than |
| `>=`                    | is greater than or equal to |

Example: "is x equal to 2?" would be written as `x == 2`[^equality].

[^equality]: **Important**: don’t confuse the double equals sign (`==`) with `=`. The latter used for assignment operations. **That is `(x = 2)` is different from `(x == 2)`**.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Relational operators are most often used in the *expressions* used in the *conditions* of the flow control structures discussed in {ref}`wk4:flow_control`.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:program_ctrl_ops)=
#### **Program control** operators in C

These are discussed in the next section {ref}`wk4:flow_control`.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:flow_control)=
## Flow control
```{image} ../week03/pictures/prog_lang_wallpaper.jpg
:alt: Decorative section background - showing code
```
Flow control statements `if`, `for`, `while`, and `switch`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

### Flow control structures in C

{numref}`wk4:fig:flow_control_structures` illustrates the flow control structures that are provided in the C language. We will illustrate the most commonly used[^rarely_used] in the following sections.

```{figure} pictures/stuctures.png
:name: wk4:fig:flow_control_structures
:alt: An organogram showing a classification of the flow control strucures provided by the C language.
:width: 100%

Classification of the flow control strucures provided by the C language.
```

[^rarely_used]: Most of the unconditional branching statements such as `goto` (for an unconditional branch to a label) and `continue` (to ignore a condition without breaking out of a loop) are rarely used in modern programs. The `break` statement is often used in *switch statements* and occasionally for breaking out of a loop when some exit condition is met.

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

### Flow control structures to be considered

1. {ref}`wk4:if`
   - {ref}`wk4:if-else`
   - {ref}`wk4:if-elseif-else`
3. {ref}`wk4:switch`
4. {ref}`wk4:while`
   - {ref}`wk4:do-while`
5. {ref}`wk4:for`
   - {ref}`wk4:nested-for`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:if)=
### The *if* statement in C

The ***if* statement** allows branching within code and can be used to check if a particular condition has been met.

If the condition has been met, the set of statement in the following blocks is executed, if the condition is not met then the statement is not executed, and the program will branch over to the next statement outside of the flow control statement

The equivalent of the *if* statement illustrated in the {numref}`wk4:fig:if-statement` is:

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```c
Statement_1;
if (expression != 0) // in C anything that is not 0 is true
{
    Statement_2;
}
Statement_3;
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{figure} pictures/if.png
:alt: A flow chart illustrating the structure of the if-statement
:width: 20%
:name: wk4:fig:if-statement

A flow chart illustrating the structure of the *if* statement
````

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:if-else)=
#### The *if-else* statement

The ***if*-else statement** allows one set of statements to be executed if the condition is met and another set of statements if the condition hasn’t been met.

The equivalent of the *if-else* statement illustrated in the {numref}`wk4:fig:if-else-statement` is:

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```c
Statement_1;
if (expression != 0) // in C anything that is not 0 is true
{
    Statement_2;
}
else // expression is false == 0
{
    Statement_3;
}
Statement_4;
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{figure} pictures/if-else.png
:alt: A flow chart illustrating the structure of the if-else statement
:width: 25%
:name: wk4:fig:if-else-statement

A flow chart illustrating the structure of the *if-else* statement
````

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:if-elseif-else)=
#### The *if-elseif-else* statement

The third example of the if statement is the ***if-elseif-else* statement** which allows multiple conditions to be tested and blocks of statements to be executed for each decision.

The equivalent of the *if-elseif-else* statement illustrated in the {numref}`wk4:fig:if-elseif-else-statement` is:

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```c
Statement_1;
if (expression1) // expression1 is true
{
    Statement_2;
}
elseif (expression2)  // expression2 is true
{
    Statement_3;
}
else // neither expression1 nor expression2 is true
{
    Statement_4;
}
Statement_5;
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{figure} pictures/if-elseif-else.png
:alt: A flow chart illustrating the structure of the if-elseif-else statement
:width: 50%
:name: wk4:fig:if-elseif-else-statement

A flow chart illustrating the structure of the *if-elseif-else* statement
````

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:switch)=
### The *switch* statement in C

- The *switch* statement allows selection between several possible defined options. 
- The **test condition** is referred to as the *expression* and the choices are referred to as the *cases*[^cases].
- Each switch expression will have a **default choice** for when no choices match the expression.
- The switch statement represents an easier and more readable way of managing multiple if statements[^switch]

[^cases]: Each case must be a *constant expression*: i.e. a number or a character.
[^switch]: i.e. avoids `if` – `elseif` – `elseif` – `elseif` – `elseif` – … – `else`

The equivalent of the *switch* statement illustrated in the {numref}`wk4:fig:switch-statement` is:

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```c
Statement;
switch (expression1) // branch according to the value of the expression
{
    case case_1 :
        code_block_1;

    case case_2 :
        code_block_2;
        
    case case_3 :
        code_block_3;

    // you can have any number of case statements
    
    default : // optional
        default_code_block;
}
Statement_2;
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{figure} pictures/switch.png
:alt: A flow chart illustrating the structure of the switch statement
:width: 50%
:name: wk4:fig:switch-statement

A flow chart illustrating the structure of the *switch* statement
````

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Example switch statement

```c
char student_grade = 'B';
printf("Your grade was %c: ",student_grade);
switch (student_grade)
{
   case 'A':
     printf ("excellent!\n");
     break; // prevents fall-through to default
   case 'B' :
     printf("very good!\n");
     break;
   case 'C' :
     printf("good!\n");
     break;
   case 'D' :
     printf("satisfactory!\n");
     break;
   case 'E' :
     printf("needs work!\n");
     break;
   case 'F' : 
     printf("sorry you failed!\n");
     break;
   default: 
     printf("Error! The grade %c is invalid\n",student_grade);
}
```

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

If the `break` was not present, the program would drop down to the next case which is not usually what you want. Instead, you usually break out to the case statement as soon as a valid match is made.

You can play with this program here: [grader](https://onlinegdb.com/16BcOgMJD). See what happens when you remove `break`.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:while)=
### The *while* statement in C

In order to write a function that loops, i.e. execution of a sequence of statements until a particular condition is met, a *while* statement can be used.

The while statement allows for a block of statements to be repeatedly executed as long as a *condition* is true. 


The equivalent of the *while* statement illustrated in the {numref}`wk4:fig:while-statement` is:

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```c
while (condition)
{
    statements;
}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{figure} pictures/while.png
:alt: A flow chart illustrating the structure of the while statement
:width: 30%
:name: wk4:fig:while-statement

A flow chart illustrating the structure of the *while* statement
````

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:do-while)=
#### The *do-while* statement

The *do-while* statement is almost identical to the while statement however the condition is checked after the statements have run.

The equivalent of the *do-while* statement illustrated in the {numref}`wk4:fig:do-while-statement` is:

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```c
do
{
    statements;
}
while (condition);
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{figure} pictures/do-while.png
:alt: A flow chart illustrating the structure of the do-while statement
:width: 25%
:name: wk4:fig:do-while-statement

A flow chart illustrating the structure of the *do-while* statement
````

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

Be careful: it is very easy to get stuck in an infinite *while* loop if your test condition is always true.

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:for)=
### The *for* statement in C

Another way of writing a while statement is to use a ***for* loop**.

The term *loop* is used for the execution of a sequence of statements until a particular condition is met.

The equivalent of the *for* statement illustrated in the {numref}`wk4:fig:for-statement` is:

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```c
for (initialize counter; counter < final value; increment counter)
{
    statements;
}
statement
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{figure} pictures/for.png
:alt: A flow chart illustrating the structure of the for statement
:width: 30%
:name: wk4:fig:for-statement

A flow chart illustrating the structure of the *for* statement
````

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

#### Example for loop

Here is an actual *for* loop which solves the problem given in {ref}`wk4:sum_example` it better illustrates how it might be written in a real program:

```c
int sum, x;
/* Add the numbers from 1 to 10 and print the sum */
for (x = 0; x < 11; x++)
{
    sum = sum + x;
}
printf("sum = %d", sum);
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

The sequence performed by the for loop is:
1. The variable `x` is *initialized* to 0;

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

2. The statements in the *block*[^block] are executed in sequence;

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

3. `x` is incremented by 1 (`x++` $\rightarrow$ `x = x + 1`);

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

4. The value of the *logical expression* `x < 11` is evaluated: if it is *true* we return to step 2.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

5. If `x < 11` is false (i.e. `x == 10`) the loop ends the result is printed to the screen.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

To execute this program see [sum.c](https://onlinegdb.com/w3YDJCZcm).

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

#### Equivalence of *for* and *while*

You can *always* write a *for* loop using *while*[^for-while]. The previous example could be written:
```c
int sum, x;
// initialize x
x = 0; 
while (x < 11) 
{
    sum = sum + x;
    x++; // increment x
}
printf("Sum = %d",sum);
```

See [sum with while](https://onlinegdb.com/ME6B9jbo8).

It is arguable that the *for* loop is easier to read and understand.

[for-while]: Indeed most c-compilers produce equivalent code for *for* and *while*.

+++ {"editable": true, "slideshow": {"slide_type": "fragment"}}

[^block]: in the C language a *block* is any sequence of statements surrounded by curly brackets `{ ... }`

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

(wk4:nested-for)=
#### Nested *for* statements

The equivalent of the nested *for* statement illustrated in the {numref}`wk4:fig:nested-for-statement` is:_

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```c
for (counter1 = 0; counter1 < 60; counter1++)
{
    for (counter2 = 0; counter2 < 60; counter2++)
    {
        statements;
    }
}
```

+++ {"editable": true, "slideshow": {"slide_type": "slide"}}

```{figure} pictures/nested-for.png
:alt: A flow chart illustrating the structure of the nested-for statement
:width: 35%
:name: wk4:fig:nested-for-statement

A flow chart illustrating the structure of the nested *for* statement
````

+++ {"editable": true, "slideshow": {"slide_type": "notes"}}

See [nested-counter](https://onlinegdb.com/Dhku-m1As) for an executable example of this program. 

What could you use it for?

+++ {"editable": true, "slideshow": {"slide_type": ""}}

## Summary
In this section we have:
- Covered basic concepts in coding to create clear and concise code as well as how to add comments to key lines of a program.
- Introduced and discussed the different operators available to the C language programmer including how they are categorized.
- Looked at the flow control statements available in the C language as well as how they are represented using flowchart diagrams and examples of the required syntax.

## On Canvas

On the canvas course page, there is a series of short videos providing a history of the C language and a brief overview of programming paradigms as well as videos on functions and data type with a quiz to test your knowledge
