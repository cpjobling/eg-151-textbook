---
jupytext:
  cell_metadata_filter: -all
  formats: md:myst
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.14.7
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---


(lab_2)=
# Experiment 2: Digital Input

All the programme examples in {ref}`lab_1` dealt with Digital Output,
and we learned how to set the bits in the Data Direction Register (DDR) to
make designated ports work as outputs. In Experiment 2 we shall look at
digital inputs.

```{list-table} DDR for setting six outputs
:name: table:1:ddr_inputs
:header-rows: 1
* - DDRC7 
  - DDRC6 
  - DDRC5 
  - DDRC4 
  - DDRC3 
  - DDRC2
  - DDRC1
  - DDRC0
* - 0
  - 0
  - 1
  - 1
  - 1
  - 1
  - 1
  - 1
```

Referring to {numref}`table:1:ddr_inputs`, the bits set to logic "1" in `DDRC` correspond to physical ports set as outputs. 

**Question**: *What about the bits set to logic "0"?*

***Answer***: The physical ports are inputs, and can be connected to devices outside
the microcontroller, for example switches and sensors.

**Question**: *How is the logic state of a port accessed by the microcontroller?

***Answer***: By reading from the corresponding port number. The ports on our Nano board are a maximum of 8 bits wide, so a read from the port returns a value
between 0 and 255 ($2^8 - 1$).

**Question**: *Supposing there are several digital inputs on a particular port. How can
we distinguish between one input and another?*

***Answer:*** *There are several ways of
doing this, but they are all based on the idea of masking.*

In the
following example, imagine that there is a physical switch connected to
Port C, bit 7. A read from Port C returns the state of all the bits from
0 to 7. In order to isolate just bit 7, we use a mask and a decision.

 
```{list-table} Applying a mask to a register to access a particular value
:name: table:2:mask
* - **Value read from Port**
  - 0 or 1 
  - 1
  - 0
  - 0 
  - 1
  - 0
  - 1
  - 1
* - **Mask**
  - 1
  - 0
  - 0
  - 0
  - 0
  - 0
  - 0
  - 0
* - **Value AND Mask**
  - 0 or 1
  - 0
  - 0
  - 0
  - 0
  - 0
  - 0
  - 0
```

The last row of {numref}`table:2:mask` shows the result of an AND operation on the
value read and the mask. So, a decision zero/non-zero will be exclusive
to the bit that was masked.

The Arduino version of "C" includes some commands which allow individual
bits to be interrogated. The mask operation is still there but it is
"behind the scenes".

## 2.2. Connecting a switch to a port

How do we connect a switch to a port pin? There are various
possibilities as shown in Fig. 2.1.

<figure>
<img
src="https://canvas.swansea.ac.uk/courses/44971/files/4630674/preview"
data-api-endpoint="https://canvas.swansea.ac.uk/api/v1/courses/44971/files/4630674"
data-api-returntype="File" alt="Connecting a switch to a port" />
<figcaption><strong>Figure 2.1</strong>: Three ways to connect a switch
to a port.</figcaption>
</figure>

Option "A" looks good, but there are several problems. It requires a
"change over" switch, with connections to both contacts. In addition,
when the switch is in motion from "0" to "1" there is a brief period
when the port voltage is undefined, which can result in unpredictable
operation. For example, it could be seen as multiple operations of the
switch.

Option "B" is much better. It only requires a "single pole" switch,
which is the usual configuration for a keyboard. In addition, the
voltage on the port is always defined; logic "0" when the switch is
open, logic "1" when it is closed.

Option "C" has the same advantages as option "B", though of course the
switch action is reversed -- logic "1" when the switch is open, logic
"0" when the switch is closed. Historically, switch inputs on digital
circuits tend to be of this type, which is known as "active low"
switching. In fact, this option is supported by the internal hardware of
the microcontroller, which has built-in resistors so all that is
required is an external switch connected between the port and logic "0".

<figure>
<img
src="https://canvas.swansea.ac.uk/courses/44971/files/4630669/preview"
data-api-endpoint="https://canvas.swansea.ac.uk/api/v1/courses/44971/files/4630669"
data-api-returntype="File"
alt="Connecting a switch to a microcontroller" />
<figcaption><strong>Figure 2.2</strong>: Active low switching for a
microcontroller.</figcaption>
</figure>

Each port has an associated pull-up register, which allows individual
bits of the port to be "tied" to logic "1" through a high-value
resistor. Different families of microcontrollers have different
mechanisms for achieving this. In the demonstration programme that
follows, the input pull-up resistors are enabled by a Arduino specific
instruction, `pinmode().` Another microcontroller used in our
undergraduate labs, the "AW60", has special registers called "pull-up
enable" registers to perform the same task.

 

## 2.3. Using a switch in a programme

The demonstration programme in Appendix 1 is, in fact, the very first
programme we tried in Experiment 1. There is one refinement; a switch is
tested and if the logic input is "0", the counter does not advance.
Notice the `pinmode()` instruction in setup, which turns on the internal
pull-up resistor. This is a one-off instruction at the start of
programme execution.

Create an Arduino sketch, and copy/paste the code from Appendix 2.1 into
it.

The testing of the switch input could be done using an Arduino-specific
instruction, `digitalRead()`, but for the sake of completeness here is
how it can be done using a port read and a logical "and" operation. The
designated port is port D, bit 2. Note the use of the exclamation mark
("!"); "!=" means "does not equal".

```c
if ((PIND & 0b00000100) != 0) { 
  counter2++; 
}
```

This will work with a wide range of different microcontrollers and "C"
compilers. Note the use of the ampersand ("&") which is the logical
"and" operation. The equivalent using an Arduino specific command is as
follows:

```c
if ( digitalRead(2) != 0 ) {
    counter2++;
}
```

 

The argument of the `digitalRead() `operation, 2, is part of the
"shorthand" used by Arduino programmers to designate a particular port
pin. It has the advantage of being consistent over a wide range of
boards in the Arduino family.

Add the two push button switches to the plug-in breadboard, using
pin-to-pin leads. Take great care when mounting the switches on the
breadboard, to orient them correctly, and to avoid bending the little
tabs!

When the programme runs, the LEDs on Port C will count up as before.
When the left-hand button is pressed, the counter stops and resumes when
the button is released. We are "in control" of the counter!

## 2.4. Let's go faster

The next programme, in Appendix 2.2, uses both buttons. The left-hand
button, as before, stops the counter. The right-hand button is a "turbo"
button, and makes the counter speed up by a factor of 10! A new
programme structure, if...else is used to decide on a delay of 1000 ms
or a delay of 100 ms, depending on the condition of the button.

The `if…else` structure is as follows:

```c
if (condition 1) {
    operation 1
} else {
   operation 2
}
```

 

An additional programme structure, `else if`, can replace else if there
are multiple decisions.

<figure>
<img
src="https://canvas.swansea.ac.uk/courses/44971/files/4630677/preview"
data-api-endpoint="https://canvas.swansea.ac.uk/api/v1/courses/44971/files/4630677"
data-api-returntype="File" alt="Wiring diagram for prototype board" />
<figcaption><strong>Figure 2.3</strong>: Wiring diagram for Experiment
2.</figcaption>
</figure>

## 2.5. An exercise for the reader...

The last part of Experiment 2 is an exercise for the reader. Do not
despair, all the programme elements needed gave been covered in this
Experiment and Experiment 1.

Modify the programme in Appendix 2 so that the two buttons have this
effect:

1.  If no buttons are pressed, a counter on Port C and a counter on Port
    B increment at the same rate, with a delay of 1000 ms so that the
    LEDs seem to be counting identically.
2.  If the left button is pressed, the LEDs on Port C stop counting but
    the LEDs on Port B continue as before.
3.  If the right button is pressed, the LEDs on Port B stop counting but
    the LEDs on Port C continue as before.
4.  If both buttons are pressed, both sets of LEDs stop counting but
    resume when the buttons are released.

A hint: there are four distinct parts inside` loop()`; first of all,
update both sets of LEDs. Then test one button and make a decision to
increment counter 1 or not. Then test the other button and do the same
for counter 2. Finally, the delay.

 

## 2.6. Assessment of Experiment 2

This follows the pattern set in Experiment 1.

-   A photograph of the modified breadboard, with some form of
    identification.
-   A listing of your final programme (as specified in Section 5 above)
    with suitable comments.

 

## Appendix 2.1: Binary counter with stop/start control

**Listing 2.1**: digi_input1.ino - binary counter with stop/start
control. (View and download code as a GitHub gist:
[digi_input1.ino).](https://gist.github.com/cpjobling/c3ad4ae874ad7b77605aa7929468d04f){.inline_disabled
target="_blank" rel="noopener"}

```c
// the setup function runs once when you press reset or power the board

byte counter1 = 0; // define variables
byte counter2 = 0; // not used in this programme

void setup() {

    // initialize Ports B and C pins 0-5 as outputs.

    DDRB = 0b00111111;
    DDRC = 0b00111111;
    PORTB = 0; // both ports start from zero
    PORTC = 0;
    pinMode(2, INPUT_PULLUP); // Make bit 2 of Port D an input
}

// the loop function runs over and over again forever

void loop() {
    PORTC = counter1;
    // if (digitalRead(2) != 0){counter1++;}

    if ((PIND & 0b00000100) != 0) {
        counter1++;
    }

    // either of the two lines above can be used

    delay(1000); // reduce this delay for faster counting
}
```


## Appendix 2.2: Binary counter with stop/start and "turbo" button

**Listing 2.2**: digi_input2.ino - binary counter with stop/start and
turbo button. (View and download code as a GitHub gist:
[digi_input2.ino](https://gist.github.com/cpjobling/2aea9097a906424b0b2ba1eab2bcf3b2){.inline_disabled
target="_blank" rel="noopener"}).

```c
// the setup function runs once when you press reset or power the board

byte counter1 = 0; // define variables
byte counter2 = 0; // not used in this programme

void setup() {
    // initialize Ports B and C pins 0-5 as outputs.

    DDRB = 0b00111111;
    DDRC = 0b00111111;
    PORTB = 0; // both ports start from zero
    PORTC = 0;

    pinMode(2, INPUT_PULLUP); // Make bit 2 of Port D an input
    pinMode(3, INPUT_PULLUP); // Make bit 3 of Port D an input
}

// the loop function runs over and over again forever

void loop() {

    PORTC = counter1;

    if (digitalRead(2) != 0) {
        counter1++;
    } // same decision as previous

    if (digitalRead(3) != 0) {
        delay(1000);
    } // long delay is default
    else {
        delay(100);
    } // short delay if button is pressed
}

```

## Appendix 2.3: Photograph of Experiment 2

<figure>
<img
src="https://canvas.swansea.ac.uk/courses/44971/files/4630666/preview"
data-api-endpoint="https://canvas.swansea.ac.uk/api/v1/courses/44971/files/4630666"
data-api-returntype="File"
alt="Photograph of the prototype board after completing experiment 2." />
<figcaption><strong>Figure 2.4</strong>: Photograph of the completed
prototype board for Experiment 2.</figcaption>
</figure>

 
