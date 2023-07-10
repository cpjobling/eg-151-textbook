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


(lab_1)=
# Experiment 1: Binary Counter

## Introduction: How can the microcontroller make something happen?

The microcontroller on the Nano board has a number of *parallel ports*, which can be used to make something happen in the world outside the plastic package. Parallel ports are usually groups of eight pins, however on the Arduino Nano not all the pins are brought out to the edge of the board. So, working within this constraint, Experiment 1 will begin with the construction and programming of a six-bit binary counter, which can count from zero to $63$ ($2^6 - 1$).</p>

## Parallel ports and data direction registers

In most microcontrollers, including the Atmel ATMega32 ussed in the Arduini Nano board, we set the digital poirt to be either an input or an output by setting a value in a special register, associated with the parellel port, which is called the *Data Direction Register* (DDR). 

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
:align:center
:width: 100%
:alt: Wiring diagram for experiment 1.

Counter circuit.
```

## Our First Programme

Now you are familiar with the Arduino IDE from running &ldquo;Blink&rdquo; in {doc}`../getting_started/index.md`, the next step is to write a new programme. 

Listing 1 shows the text of a programme which will illuminate the LEDs in a binary sequence, starting from zero (all LEDs off) to 63 (all LEDs on). Then the LEDs will go back to zero. The time it takes to count is controlled by a &ldquo;time wasting&rdquo; delay, using the Arduino specific command `delay()`.</p>

Listing 1: First Program counter.ino

<p>First open the Arduino directory. Create a folder and name it &ldquo;counter&rdquo;. Next open the text editor, and either type in the programme found in Appendix 1.1, or copy/paste the text from this document. Then save the text file and name it &ldquo;counter.ino&rdquo;. It may be necessary to do this in two steps, starting by saving the programme as &ldquo;counter.txt&rdquo; and then using the file manager to change the name to &ldquo;counter.ino&rdquo;.</p>
<p>Now that the file has been entered into the computer, and given a suitable name and file extension, it must be converted into a form the Arduino board can accept. This operation is called compilation. Start the Arduino IDE and when the screen appears, click on &ldquo;tools&rdquo; and select board type to be &ldquo;Nano&rdquo;. Click on port, and make sure that the relevant COM port is ticked. We are now ready to compile the programme.</p>
<p>Click on the icon which starts the compilation. This is the blue tick near the top of the window, also called Verify. After a few seconds, the display area at the bottom of the window should say &ldquo;compilation complete&rdquo;. If it does not, and some error message appears, check carefully that the programme has been entered correctly and try again.</p>
<p>When the programme has been compiled successfully, it must be uploaded to the Arduino. Click on the blue arrow near the top of the window, called Upload. This operation should only take a few seconds. The message &ldquo;Done uploading&rdquo; tells us that the upload operation has been successful, and the LEDs should start counting.</p>
<p>If the upload fails, there are a number of things to check. Under &ldquo;tools&rdquo;, there are a number of settings, e.g.</p>
<ul>
    <li>Board type: &ldquo;Arduino Nano&rdquo;</li>
    <li>Processor: &ldquo;ATmega328P&rdquo;</li>
    <li>Port: &ldquo;/dev/ttyUSB0&rdquo; (for example only; this will differ for PC and Mac)</li>
</ul>
<p>If the above are wrong, then the upload will fail.</p>
<h2>1.4. Let&rsquo;s make a decision</h2>
<p>The example programme counts from zero to 255 and then back to zero, though we see the LEDs being illuminated from zero to 63 as there are only six LEDs. The counts from 64 to 127 look just the same as zero to 63! Supposing we need a counter that counts from zero to 59, and then back to zero. This is often required, for example in time-keeping programmes (60 seconds in a minute, 60 seconds in an hour). The number of count values (60 in this case) is called a Modulus.</p>
<p>There are several ways we can add a modulus to our counter programme. One way would be to use a &ldquo;for&rdquo; loop. Another way would be to make a decision. For example, if we add the following lines to the existing programme:</p>
<pre style="font-size: 14pt; background-color: white; padding-left: 40px;">counter1 = counter1+1;<br />if (counter1 &gt;= 60)<br />{
  counter1 = 0;
};</pre>
<p>then we have made a decision! If the value of the variable &ldquo;counter1&rdquo; is increased beyond 59, then it will be set back to zero, so the LEDs never advance beyond 59. Why bother with counts greater than 60? Well, if the programme is not properly initialised then there will be a number of false counts. If you are not familiar with &ldquo;C&rdquo; programming, then you will notice that there are two kinds of &ldquo;equals&rdquo; in the extra line. The &ldquo;greater than or equals&rdquo; is a comparison and does not change any values. In other words the value of the variable <code>counter1</code> is compared with the fixed value of 60. If the condition is true, then the contents of the &ldquo;braces&rdquo; (squiggly brackets) are executed. The single equals is an assignment and forces the value of the variable to the fixed value zero.</p>
<p>Just to make life more interesting, in &ldquo;C&rdquo; there is a &ldquo;double equals&rdquo; (<code>==</code>). This can be a source of confusion when starting to programme in the &ldquo;C&rdquo; language. It is used to compare two numbers, for example as follows:</p>
<pre style="font-size: 14pt; background-color: white; padding-left: 40px;">counter1 = counter1+1;<br />if (counter1 == 60)<br />{
  counter1 = 0;
}</pre>
<p>There are lots of &ldquo;C&rdquo; commands which reduce the amount of text, for example instead of adding 1 to the variable <code>counter1</code> then a &ldquo;double plus&rdquo; can be used to increment a variable by 1;</p>
<pre style="font-size: 14pt; background-color: white; padding-left: 40px;">counter1++;</pre>
<p>This has the same effect as adding &ldquo;1&rdquo; to the variable <code>counter1</code>.</p>
<p>&nbsp;</p>
<h2>1.5. Let&rsquo;s do it again!</h2>
<p>Now that we are masters of the modulus counter, let&rsquo;s repeat the operation by connecting another set of LEDs to port B, and adding extra lines to the programme as shown in Appendix 1.2. This will require another variable, for example &ldquo;counter2&rdquo;.</p>
<p>In addition, let us increment <code>counter1</code> when <code>counter2</code>&nbsp;overflows, (changes from 59 to zero) so that one set of LEDs is counting in seconds and the other set of LEDs is counting in minutes.</p>
<p>Add another set of six LEDs and resistors to the Breadboard as shown in Fig. 1.2:</p>
<figure><img src="https://canvas.swansea.ac.uk/courses/44971/files/4630665/preview" alt="Wiring diagram for experiment 2." data-api-endpoint="https://canvas.swansea.ac.uk/api/v1/courses/44971/files/4630665" data-api-returntype="File" />
    <figcaption><strong>Figure 1.2</strong>: Circuit board for a cascaded counter.</figcaption>
</figure>
<p>&nbsp;</p>
<p>Modify the programme to include the extra lines and compile then upload. If this is successful, then the LEDs on port B will count as far as 59 (111011) and then all go out and start counting again. At the instant the LEDs on port B go out, the LEDs on port C will advance by one. So, if we have the patience, after an hour the LEDs will reach their maximum value of 59 minutes, 59 seconds (111011 111011) and all go out. Then the counter starts counting again from all zeros.</p>
<p>&nbsp;</p>
<h2>1.6. Let&rsquo;s do it differently&hellip;</h2>
<p>So far we have used simple arithmetic operations such as addition to increment the variables, then compare with a fixed modulus. An alternative is to use a for(;;) loop. Let&rsquo;s look at the elements of a <code>for(;;)</code> loop:</p>
<pre style="font-size: 14pt; background-color: white; padding-left: 40px;">for (variable = initial value; condition to be met; operation on variable)<br />{
   code to be executed in for loop<br />}</pre>
<p>A better way of understanding the <code>for(;;)</code> loop is to look at a practical example;</p>
<pre style="font-size: 14pt; background-color: white; padding-left: 40px;">for (counter2 = 0; counter2 &lt; 60; counter2++)<br />{
  PORTB = counter2;<br />  delay(1000)<br />
}</pre>
<p>In just three lines of code, the start and end values of the loop are set up, and the increment defined, followed by the code to be executed each time around the loop. This illustrates the compact nature of the &ldquo;C&rdquo; language.</p>
<p>This <code>for(;;)</code> loop only executes once, so we still need to make it repeat, which is made possible by the &ldquo;loop&rdquo; function in the Arduino programme. Suppose we embed this <code>for(;;) </code>loop in an outer <code>for(;;) </code>loop, which increments a different variable and writes to a different port? Then we will have achieved the same result as the programme in Appendix 2, but in a more elegant fashion:</p>
<pre style="font-size: 14pt; background-color: white; padding-left: 40px;">for (counter1 = 0; counter1 &lt; 60; counter1++)<br />{<br />  PORTC = counter1;<br />  for(counter2 = 0; counter2 &lt; 60; counter2++)<br />  {<br />    PORTB = counter2; <br />    delay(1000)<br />  }<br />}</pre>
<p>&nbsp;</p>
<p>The &ldquo;heart&rdquo; of the programme is just a few lines of code!</p>
<p>Modify the programme as shown in Appendix 1.3, compile and upload, and check that it really does what we expect. You may find it convenient to reduce the delay from 1000 to speed up the operation of the counters.</p>
<p>&nbsp;</p>
<h2>1.7. Assessment of Experiment 1</h2>
<p>Open the document you are using as a laboratory diary and add a new section &ldquo;Experiment 1&rdquo;.</p>
<p>Take a photograph of the completed breadboard, with the twelve LEDs and resistors fitted. Include in your photo some means of identification, such as your student card.</p>
<p>When you have finished modifying the programme to correspond with Appendix 3, add some comments (preceded by the double oblique stroke &ldquo;//&rdquo;) and copy the text from the Arduino IDE and paste it into your laboratory diary as a code listing.</p>
<p>We shall be looking for comments which show your understanding of the way the nested for(;;) loop works. Why are comments so important? If someone else reads the programme, the comments aid understanding. Also, if you return to working on a programme after a couple of weeks, it is much easier to pick up where you left off. A programme without comments is incomplete!</p>
<h2>Appendix 1.1: Basic counter programme</h2>
<p style="padding-left: 40px;"><strong>Listing 1.1</strong>: counter.ino - Basic counter. (View and download the code from GitHub gist <a class="inline_disabled" href="https://gist.github.com/cpjobling/8803a24e00f15237057dfdbb566a461b" target="_blank" rel="noopener">counter.ino</a>.)</p>
<pre style="font-size: 14pt; padding-left: 40px; background-color: white;">// the setup function runs once when you press reset or power the board

byte counter1 = 0; // we need to define the variable &ldquo;counter1&rdquo;

void setup()
{
    // initialize Port C pins 0-5 as outputs.
    DDRC = 0b00111111; // the prefix &ldquo;0b&rdquo; qualifies the number as binary
    PORTC = 0; // so all the LEDs are off initially
}

// the loop function runs over and over again forever
void loop() {
    PORTC = counter1;
    counter1 = counter1 + 1;

    // we could replace the above line with: "counter1++;"
    // add the following for a modulus of 60: &ldquo;if(counter1 &gt; 59){counter1 = 0;}

    delay(1000); // reduce the delay if you get bored waiting!
}
</pre>
<h2>Appendix 1.2: Cascaded Counter</h2>
<p style="padding-left: 40px;"><strong>Listing 1.2</strong>: counter2.ino - Cascaded counter. (View and download the code from GitHub gist <a class="inline_disabled" href="https://gist.github.com/cpjobling/d0b1b4bfc77c28a4284b7fcff13d5d1b" target="_blank" rel="noopener">counter2.ino</a>)</p>
<pre style="font-size: 14pt; padding-left: 40px; background-color: white;">// the setup function runs once when you press reset or power the board<br /><br />byte counter1 = 0; // define variables<br />byte counter2 = 0;<br /><br />void setup()<br />{<br /><br />&nbsp; &nbsp; // initialize Ports B and C pins 0-5 as outputs.<br />&nbsp; &nbsp; DDRB = 0b00111111;<br />&nbsp; &nbsp; DDRC = 0b00111111;<br /><br />&nbsp; &nbsp; PORTB = 0; // both ports start from zero<br />&nbsp; &nbsp; PORTC = 0;<br />}<br /><br />// the loop function runs over and over again forever<br /><br />void loop()<br />{<br /><br />&nbsp; &nbsp; PORTB = counter2; // counter2 is our "seconds" counter<br />&nbsp; &nbsp; PORTC = counter1; // counter1 is our "minutes" counter<br /><br />&nbsp; &nbsp; counter2++; // using the tip we learnt earlier<br /><br />&nbsp; &nbsp; if (counter2 &gt; 59)<br />  &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; counter2 = 0;<br />  &nbsp; &nbsp; &nbsp; counter1++;<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; if (counter1 &gt; 59)<br />&nbsp; &nbsp; &nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; counter1 = 0;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; delay(1000); // again, reduce this delay if necessary to speed things up.<br />}</pre>
<h2>Appendix 1.3: Counter using &ldquo;for(;;)&rdquo; loop</h2>
<p style="padding-left: 40px;"><strong>Listing 1.3</strong>: counter3.ino - Counter using for loop. (View and download the code from GitHub gist <a class="inline_disabled" href="https://gist.github.com/cpjobling/0dcf2eeb620a1e2228502d67cc1aeb95" target="_blank" rel="noopener">counter3.ino</a>)</p>
<pre style="padding-left: 40px; background-color: white; font-size: 14pt;">// the setup function runs once when you press reset or power the board<br /><br />byte counter1 = 0; // define variables<br />byte counter2 = 0;<br /><br />void setup()<br />{<br />&nbsp; &nbsp; // initialize Ports B and C pins 0-5 as outputs.<br />&nbsp; &nbsp; DDRB = 0b00111111;<br />&nbsp; &nbsp; DDRC = 0b00111111;<br />&nbsp; &nbsp; PORTB = 0; // both ports start from zero<br />&nbsp; &nbsp; PORTC = 0;<br />}<br /><br />// the loop function runs over and over again forever<br /><br />void loop()<br />{<br /><br />&nbsp; &nbsp; for (counter1 = 0; counter1 &lt; 60; counter1++)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; PORTC = counter1;<br />&nbsp; &nbsp; &nbsp; &nbsp; for (counter2 = 0; counter2 &lt; 60; counter2++)<br />&nbsp; &nbsp; &nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; PORTB = counter2;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; delay(1000);<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br />}</pre>
<h2>Appendix 1.4: Photographs of Plug-in Breadboard</h2>
<figure><img src="https://canvas.swansea.ac.uk/courses/44971/files/4630662/preview" alt="Photograph of partially wired prototype board." data-api-endpoint="https://canvas.swansea.ac.uk/api/v1/courses/44971/files/4630662" data-api-returntype="File" />
    <figcaption><strong>Figure 1.3</strong>: Photograph of partially wired prototype board.</figcaption>
</figure>
<p>&nbsp;</p>
<figure><img src="https://canvas.swansea.ac.uk/courses/44971/files/4630663/preview" alt="Photograph of completed prototype board for experiment 1." data-api-endpoint="https://canvas.swansea.ac.uk/api/v1/courses/44971/files/4630663" data-api-returntype="File" />
    <figcaption><strong>Figure 1.4</strong>: Photograph of completed prototype board for experiment 1.</figcaption>
</figure>
