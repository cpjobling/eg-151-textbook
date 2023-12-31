(voltmeter)=
# Voltmeter

**Brief**: Build a Voltmeter using the Arduino Nano processor and the 16 by 2 LCD.

The Voltmeter must, as a minimum, display voltage in at least one range, with units, decimal points, included on the display. This will require additional circuitry in the form of potential dividers and protection diodes to prevent over voltages from damaging the Arduino Nano.

Marks will be awarded as follows:

- 0 to 40%: For a non-functional unit which shows signs of working.

- 40 to 50%: For a minimal implementation of the specification, displaying a number which is at least proportional to the applied voltage.

- 50 to 60%: For a correctly calibrated voltmeter with decimal points and units displayed.

- 60 to 70%: For a voltmeter displaying plus and minus voltages.

- 70% plus: This mark will only be given to a voltmeter with some additional functionality, such as multiple ranges, auto ranging, zero offset, memory and so on.

## Technical Information

Here is a video of Dr. Davies explaining how to begin the Voltmeter Mini-Project

<iframe src="https://swanseauniversity.cloud.panopto.eu/Panopto/Pages/Embed.aspx?id=6854ee6c-cad9-43aa-bc64-b0c2010754b1&autoplay=false&offerviewer=true&showtitle=true&showbrand=true&captions=true&interactivity=all" height="405" width="720" style="border: 1px solid #464646;" allowfullscreen allow="autoplay" aria-label="Panopto Embedded Video Player"></iframe>

Initial calibration of voltmeter:

Assume $V_\mathrm{ref} = 5$V.

Let us have a resistive network which divides $V_\mathrm{in}$ by four, so 20 V in becomes 5 V after the network.

In order to display the voltage as a meaningful number, and remembering that the maximum input to a 10 bit ADC
produces a digital number of 1023, let us divide by 1024 and multiply by 20, using floating point numbers.

$$\frac{V_\mathrm{in}}{1024}\times 20$$

This resulted in reading of $7.388$ for an input of $7.06$ which was about 6% in error.

The value of $V_\mathrm{ref}$ was measured using a voltmeter, and found to be $4.73$V, not 5V.
So the programme was modified to multiply by $18.92$ and divide by $1023$.
This resulted in an error of about 1%, which is much better!

The demo code which accounts for these adjustments follows:

<script src="https://gist.github.com/cpjobling/1326229ed9e42f174d541fb8a1d64824.js"></script>

## Bipolar Voltage Measurement

Extra information is provided in {ref}`bipolar_voltage_measurement`.
