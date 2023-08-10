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

+++

## Arrays

An array is just a list of items, which could be numbers, or alphabetic
characters, accessible by specifying the position in the list. Setting
up an array in "C" begins with specifying what each item is:

```c
 byte arrayname[6]; 
```

specifies that each item in the array is one byte, and that there are
six items.

```c
word anothername[10]; 
```

similarly specifies that each item is an (16-bit wide) integer, and that
there are 10 items.

Other array types are possible, which are specified using the same
notation as for variables.

The contents of an array can be specified at the same time as the array
is defined, for example:

```c
 byte numbers[6] = {1,2,3,4,5,6}; 
```

sets up an array called numbers, containing the positive integers 1, 2,
3...

{ref}`listing8` is a programme which sets up an array containing integers,
fetches them out of the array one at a time and displays them on one of
the sets of LEDs. A short delay allows the numbers to be read, otherwise
they would flash by too quickly to see! After displaying the individual
numbers, the sum of the numbers is displayed for a longer period, then
it starts all over again.

Create an Arduino sketch and paste in the programme from {ref}`listing8`.
Change the digits in the array to correspond to the digits in your
student number; if your student number has six digits, begin with a
leading zero so that there are seven items in the array.

Look at the `for(;;) `loop in the programme. It starts at zero, because
in "C" array index numbering starts from zero.

Compile and upload the programme, then check that the digits of your
student number are displayed in order and that the sum of the digits is
correct. You do not need to make any changes to the plug-in breadboard.

+++

## Exercise

Now that you have the programme from {ref}`listing8` as a model, write a
programme as follows:

1.  Create two arrays, one containing your student number and the other
    containing the last 7 digits of your telephone number.
2.  Write a programme which examines the two buttons. If neither button
    is pressed, continue checking the status of the buttons (look at
    Experiment 2 for a reminder how to examine the buttons).
3.  If the left button is pressed, use the programme from {ref}`listing8`
    to read and display the contents of one of the arrays, finishing
    with displaying the sum of the digits.
4.  Use the other button to read and display the contents of the second
    array.
5.  When the display operation is complete, return to examining the
    switches.

 

+++

## Assessment of Experiment 4

When you are satisfied with the programme, copy and paste it into you
lab diary. Don't forget to put in plenty of comments (preceded by the
double oblique stroke, "//".)
