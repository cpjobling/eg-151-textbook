---
jupytext:
  cell_metadata_filter: -all
  formats: md:myst
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.0
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

(lab_4)=
# Experiment 4: Arrays

## 4.1. Arrays

An array is just a list of items, which could be numbers, or alphabetic
characters, accessible by specifying the position in the list. Setting
up an array in "C" begins with specifying what each item is:

``` {style="padding-left: 40px;"}
 byte arrayname[6]; 
```

specifies that each item in the array is one byte, and that there are
six items.

``` {style="padding-left: 40px;"}
word anothername[10]; 
```

similarly specifies that each item is an (16-bit wide) integer, and that
there are 10 items.

Other array types are possible, which are specified using the same
notation as for variables.

The contents of an array can be specified at the same time as the array
is defined, for example:

``` {style="padding-left: 40px;"}
 byte numbers[6] = {1,2,3,4,5,6}; 
```

sets up an array called numbers, containing the positive integers 1, 2,
3...

Appendix 4.1 is a programme which sets up an array containing integers,
fetches them out of the array one at a time and displays them on one of
the sets of LEDs. A short delay allows the numbers to be read, otherwise
they would flash by too quickly to see! After displaying the individual
numbers, the sum of the numbers is displayed for a longer period, then
it starts all over again.

Create an Arduino sketch and paste in the programme from Appendix 4.1.
Change the digits in the array to correspond to the digits in your
student number; if your student number has six digits, begin with a
leading zero so that there are seven items in the array.

Look at the `for(;;) `loop in the programme. It starts at zero, because
in "C" array index numbering starts from zero.

Compile and upload the programme, then check that the digits of your
student number are displayed in order and that the sum of the digits is
correct. You do not need to make any changes to the plug-in breadboard.

## 4.2. Exercise

Now that you have the programme from Appendix 4.1 as a model, write a
programme as follows:

a.  Create two arrays, one containing your student number and the other
    containing the last 7 digits of your telephone number.
b.  Write a programme which examines the two buttons. If neither button
    is pressed, continue checking the status of the buttons (look at
    Experiment 2 for a reminder how to examine the buttons).
c.  If the left button is pressed, use the programme from Appendix 4.1
    to read and display the contents of one of the arrays, finishing
    with displaying the sum of the digits.
d.  Use the other button to read and display the contents of the second
    array.
e.  When the display operation is complete, return to examining the
    switches.

 

## 4.3. Assessment of Experiment 4

When you are satisfied with the programme, copy and paste it into you
lab diary. Don't forget to put in plenty of comments (preceded by the
double oblique stroke, "//".)

 

## Appendix 4.1: Programme using an Array

**Listing 4.1**: arrays.ino - programme using an array. (View or
download code from GitHub
Gist [arrays.ino](https://gist.github.com/cpjobling/2170231c0092f07d3aa0495f8220098d){.inline_disabled
target="_blank" rel="noopener"}.)

``` {style="font-size: 14pt;"}
// the setup function runs once when you press reset or power the board

int total = 0; // This variable will contain the running total.

int numbers[7] = {2, 9, 5, 4, 5, 6, 7}; // Create an integer array and preload.

byte index = 0;

void setup()
{

    // initialize Ports B and C pins 0-5 as outputs.

    DDRB = 0b00111111;

    DDRC = 0b00111111;

    PORTB = 0; // both ports start from zero

    PORTC = 0;
}

// the loop function runs over and over again forever

void loop()
{

    total = 0;

    for (index = 0; index < 7; index++)
    {

        PORTC = numbers[index]; // The LEDs on Port C show the current array value.

        total = total + numbers[index];

        PORTB = total; // The LEDs on Port B show the running total.

        delay(1000); // A one second delay.
    }

    PORTC = total; // Finally, the LEDs on Port C show the total of all the digits.

    delay(2000); // A two second delay,then start all over again.
}
```
