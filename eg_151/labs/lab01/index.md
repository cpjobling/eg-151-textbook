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

(lab_1)=
# Experiment 1: Binary Counter

## How can the microcontroller make something happen?

The microcontroller on the Nano board has a number of *parallel ports*, which can be used to make something happen in the world outside the plastic package. Parallel ports are usually groups of eight pins, however on the Arduino Nano not all the pins are brought out to the edge of the board. So, working within this constraint, Experiment 1 will begin with the construction and programming of a six-bit binary counter, which can count from zero to $63$ ($2^6 - 1$).</p>

## Parallel ports and data direction registers

In most microcontrollers, including the Atmel ATMega32 used in the Arduini Nano board, we set the digital poirt to be either an input or an output by setting a value in a special register, associated with the parellel port, which is called the *Data Direction Register* (DDR). 

The DDR settings that provide the six outputs that we need for this experiment are shown in {numref}`table:1:ddr`.

```{list-table} DDR for setting six outputs
:name: table:1:ddr
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


There are two ways of setting the bits in the DDR. Individual bits can be set using an Arduino specific command, pinmode. For this experiment, we shall write directly to the DDR corresponding to Port C, which is designated `DDRC` in our programme. In the example shown above, the top two bits of Port C will be inputs (`DDRC7=0`, `DDRC6 = 0`) and all the remaining bits will be outputs. This is a more general way of setting a DDR in different versions of embedded &ldquo;C&rdquo;.</p>

Writing a number to the port register itself will cause a binary pattern to appear on the corresponding pins of the designated port, according to their binary weights. For example, bit 0 has a binary weight of $2^0 = 1$, bit 1 has a binary weight of $2^11 = 2$, bit 2 has a binary weight of $2^2 = 4$, all the way up to bit 7 which has a binary weight of $2^7 = 128$.</p>

## Method

Construct the circuit shown in {numref}`fig:ex1:1` using the components supplied in your laboratory kit:

```{figure} pictures/fig1.png
:name: fig:ex1:1
:align: center
:width: 100%
:alt: Wiring diagram for experiment 1.

Counter circuit.
```

## Our First Programme

Now you are familiar with the Arduino IDE from running &ldquo;Blink&rdquo; in {doc}`../get_started/index`, the next step is to write a new programme. 

[Listing 1][#listing1] shows the text of a programme which will illuminate the LEDs in a binary sequence, starting from zero (all LEDs off) to 63 (all LEDs on). Then the LEDs will go back to zero. The time it takes to count is controlled by a &ldquo;time wasting&rdquo; delay, using the Arduino specific command `delay()`.</p>

(listing1)=
**Listing 1**: Basic counter (counter.ino) (View and download the code from GitHub gist [counter.ino](https://gist.github.com/cpjobling/8803a24e00f15237057dfdbb566a461b).)
<script src="https://gist.github.com/cpjobling/8803a24e00f15237057dfdbb566a461b.js"></script>


First connect your Arduino Nano board to your PC with the cable provided. Next open Arduino IDE 2 and select the connection and board as described in {ref}`set_up_arduino`. From the file menu select &ldquo;New Sketch&rdquo;. Press the `view raw` button to view the code without line numbers, copy the whole of the code given in Listing 1 and paste it into the code window of the new sketch. Save the  sketch file as `counter1`.

Arduion IDE will close then reopen with the code for a new Sketch project called `counter1.ino` loaded in the code editor as shown in {numref}`fig:ex1:1`.

```{figure} pictures/fig2.png
:name: fig:ex1:2
:align: center
:width: 100%
:alt: Screenshot of Arduino IDE 2 with the code for counter1 loaded and saved.

Our first program ready for testing.
```

Now that the file has been entered into the computer and an Arduino sketch project it must be converted into a form the Arduino board can accept. This operation is called compilation. 

Click on the icon which starts the compilation. This is the blue tick near the top of the window, also called Verify. After a few seconds, the display area at the bottom of the window should say &ldquo;compilation complete&rdquo;. If it does not, and some error message appears, check carefully that the programme has been entered correctly and try again.

When the programme has been compiled successfully, it must be uploaded to the Arduino. Click on the blue arrow near the top of the window, called Upload. This operation should only take a few seconds. The message &ldquo;Done uploading&rdquo; tells us that the upload operation has been successful, and the LEDs should start counting.

If the upload fails, there are a number of things to check. Under &ldquo;tools&rdquo;, there are a number of settings, e.g.</p>

* Board type: `Arduino Nano`
* Processor: `ATmega328P`
* Port: `/dev/ttyUSB0` (for example only; this will differ for PC and Mac)

If the above are wrong, then the upload will fail. Ask a demonstrator for help!

## Let&rsquo;s make a decision

The example programme counts from zero to 255 and then back to zero, though we see the LEDs being illuminated from zero to 63 as there are only six LEDs. The counts from 64 to 127 look just the same as zero to 63! Supposing we need a counter that counts from zero to 59, and then back to zero. This is often required, for example in time-keeping programmes (60 seconds in a minute, 60 seconds in an hour). The number of count values (60 in this case) is called a Modulus.

There are several ways we can add a modulus to our counter programme. One way would be to use a &ldquo;for&rdquo; loop. Another way would be to make a decision. For example, if we add the following lines to the existing programme:

```c
counter1 = counter1 + 1;
if (counter1 >= 60) {
  counter1 = 0;
}
```

In this code, we have made a decision! If the value of the variable `counter1` is increased beyond 59, then it will be set back to zero, so the LEDs never advance beyond 59. 

Why bother with counts greater than 60? Well, if the programme is not properly initialised then there will be a number of false counts. 

If you are not familiar with &ldquo;C&rdquo; programming, then you will notice that there are two kinds of &ldquo;equals&rdquo; in the extra line. The &ldquo;greater than or equals&rdquo; (`>=`) is a comparison and does not change any values. In other words the value of the variable `counter1` is compared with the fixed value of 60. If the condition is true, then the contents of the &ldquo;braces&rdquo; (squiggly brackets) are executed. The single equals (`=`) is an *assignment* and forces the value of the variable to the fixed value zero.

Just to make life more interesting, in &ldquo;C&rdquo; there is a &ldquo;double equals&rdquo; `==`). This can be a source of confusion when starting to program in the &ldquo;C&rdquo; language. It is used to compare two numbers, for example as follows:

```c
counter1 = counter1 + 1;
if (counter1 == 60) {
  counter1 = 0;
}
```
<p>There are lots of &ldquo;C&rdquo; commands which reduce the amount of text that you have to write. For example, instead of adding 1 to the variable `counter1` we can use the *increment operator* (`++`) to increment a variable by 1:
    
```c
counter1++;
```

This has the same effect as adding &ldquo;1&rdquo; to the variable `counter1` and reassigning the new value to `counter1` which is what:
```c
counter1 = counter1 + 1;
```
does.

## Let&rsquo;s do it again!

Now that we are masters of the modulus counter, let&rsquo;s repeat the operation by connecting another set of LEDs to port B, and adding extra lines to the programme as shown in Listing 2.

**Listing 2**: Canscaded counter (counter2.ino) (View and download the code from GitHub gist [counter2.ino](https://gist.github.com/cpjobling/d0b1b4bfc77c28a4284b7fcff13d5d1b).)
<script src="https://gist.github.com/cpjobling/d0b1b4bfc77c28a4284b7fcff13d5d1b.js"></script>

This will require another variable, for example &ldquo;counter2&rdquo;.

In addition, let us increment `counter1` when `counter2` *overflows*, (changes from 59 to zero) so that one set of LEDs is counting in seconds and the other set of LEDs is counting in minutes.

Add another set of six LEDs and resistors to the Breadboard as shown in {numref}`fig:ex1:3`

```{figure} pictures/fig3.png
:name: fig:ex1:3
:align: center
:alt: Wiring diagram for cascaded counter.
:width: 100%

Circuit board for a cascaded counter.
```

Modify the programme to include the extra lines and compile then upload. If this is successful, then the LEDs on port B will count as far as 59 (`0b0111011`) and then all go out and start counting again. At the instant the LEDs on port B go out, the LEDs on port C will advance by one. So, if we have the patience, after an hour the LEDs will reach their maximum value of 59 minutes, 59 seconds (`0b0111011` `0b0111011`) and all go out. Then the counter starts counting again from all zeros.

## Let&rsquo;s do it differently&hellip;

So far we have used simple arithmetic operations such as addition to increment the variables, then compare with a fixed modulus. An alternative is to use a `for(;;)` loop. 

Let&rsquo;s look at the elements of a `for(;;)` loop:</p>

```
for (variable = initial value; condition to be met; operation on variable) {
   code to be executed in for loop;
}
```

A better way of understanding the `for(;;)` loop is to look at a practical example;

```c
for (counter2 = 0; counter2 < 60; counter2++) {
  PORTB = counter2;
  delay(1000);
}
```

In just three lines of code, the start and end values of the loop are set up, and the increment defined, followed by the code to be executed each time around the loop. This illustrates the compact nature of the &ldquo;C&rdquo; language.

This `for(;;)` loop only executes once, so we still need to make it repeat, which is made possible by the `loop` function in the Arduino programme. Suppose we embed this `for(;;)` loop in an outer `for(;;)` loop, which increments a different variable and writes to a different port? Then we will have achieved the same result as the programme in Listing 2, but in a more elegant fashion:

```c
for (counter1 = 0; counter1 < 60; counter1++) {
    PORTC = counter1;
    for (counter2 = 0; counter2 < 60; counter2++) {
        PORTB = counter2; 
        delay(1000)
    }
}
```

The &ldquo;heart&rdquo; of the programme is just a few lines of code!

Modify the programme as shown in Listing 3, compile and upload, and check that it really does what we expect. You may find it convenient to reduce the delay from 1000 to speed up the operation of the counters.

**Listing 3**: Counter using for loop. (counter3.ino) (View and download the code from GitHub gist [counter3.ino](https://gist.github.com/cpjobling/0dcf2eeb620a1e2228502d67cc1aeb95).)
<script src="https://gist.github.com/cpjobling/0dcf2eeb620a1e2228502d67cc1aeb95.js"></script>


## Assessment of Experiment 1

Open the document you are using as a laboratory diary and add a new section &ldquo;Experiment 1&rdquo;.

Take a photograph of the completed breadboard, with the twelve LEDs and resistors fitted. Include in your photo some means of identification, such as your student card.

When you have finished modifying the programme to correspond with Listing 3, add some comments (preceded by the double oblique stroke &ldquo;//&rdquo;) and copy the text from the Arduino IDE and paste it into your laboratory diary as a code listing.

We shall be looking for comments which show your understanding of the way the nested `for(;;)` loop works. Why are comments so important? If someone else reads the programme, the comments aid understanding. Also, if you return to working on a programme after a couple of weeks, it is much easier to pick up where you left off. A programme without comments is incomplete!

## Appendix: Photographs of Plug-in Breadboard

The following photographs ({numref}`photo:ex1:1` and {numref}`photo:ex1:2`) were provided by Dr Davies who created this experiment.

```{figure} pictures/photo1.jpg
:name: photo:ex1:1
:alt: Photograph of partially wired prototype board.
:width: 100%
:align: center

Photograph of partially wired prototype board.
```

```{figure} pictures/photo2.jpg
:name: photo:ex1:2
:alt: Photograph of completed prototype board for experiment 1.
:width: 100%
:align: center

Photograph of completed prototype board for experiment 1.
```
