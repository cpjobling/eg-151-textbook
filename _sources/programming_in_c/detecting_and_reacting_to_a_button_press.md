(programming_in_c_6)=
# Detecting and reacting to a button press


(step5)=
## Step 5 - Detecting the Button Press

Now the direction/mode for each pin and the initial state of the output pins has been set, the main program code can be written within the loop function. Looking back at the {ref}`programming_in_c_3`
> The program written needs to detect when a push button is pressed...",

the first section of code within the loop function needs to check if the button has been pressed. This is achieved by reading the state of the pin and comparing against 0 or `LOW`, 0 is used since the pull-resistor for this pin has been enabled meaning the default value (no button press) seen at the input is 1 or `HIGH`.

To achieve this functionality in code, an if statement is used - The if statement allows branching within code and can be used to check if a particular condition has been met. If the condition has been met, the set of statements within the code block (parentheses) is executed, if the condition is not met then the statements within the code block are not executed and the program will branch over to the
next statement outside of the if statement. The syntax of an if statement is 

```c
if (condition is met) {
  //statements to be run
}
```

To read the current state of the pin, the pre-defined Arduino function “`digitalRead`” can be used. This function takes the connection label as an argument. The syntax of this function is:

```c
digitalRead(pin)
```

More information on this function can be found in the [digitalRead](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/) section of the Arduino reference library.

To check if the push button has been pressed, the [equal to (`==`)](https://www.arduino.cc/reference/en/language/structure/comparison-operators/equalto/) comparison operator is used. This operator compares the value on the left with the value on the right and returns `true` when the two operands are equal. 

By putting these three components together, and using the value LOW (or 0) on the right hand side of the "equal to" comparison operator, the following code checks whether the push button connected to `D8` has been pressed:

```c
if (digitalRead(pushButton) == LOW) {
    
}
```


## Step 6 - Reading the Analog Input

The next step in this program is to write the code that can read the analogue signal and store the converted value into a variable. There are 2 parts to this step, the first is to declare a variable that the result will be stored in, and second, to read the analogue signal and assign the result to the declared variable. A variable must be declared before it is used and there are three different ways to achieve this:

1. Declare the variable at the start of the program before void setup (this is the best option)
2. Declare the variable at the start of the function (in this case, at the top of void loop)
3. Declare the variable inline.

As a minimum, the variable declaration must specify the data type and a name to be used, however this can also set the initial value of the variable. In code, we can declare a variable with the name sensorValue as follows:

```c
//Variable declarations
int sensorValue = 0;
```

Now the variable has been declared, the programmer/code can assign values to it and/or change its value. In this example, the programmer needs to read the value of the analogue input signal every time the push button is pressed. This means the next bit of code that is added needs to be within the code block of the button press detection. 

To read the current value at an analogue pin, the pre-defined Arduino function “`analogRead`” can be used. This function takes the connection label as an argument. The syntax of this function is:

```c
analogRead(pin)
```

More information on this function can be found in the [analogRead section](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/) of the Arduino reference library.

 Adding this component to our existing code which checks whether the push button connected to `D8` has been pressed, the code becomes:

```c
if (digitalRead(pushButton) == LOW) {
    // read the value from the sensor and store the result in sensorValue variable
    sensorValue = analogRead(inputSignal);
}
``` 

In simple terms, each time the push button connected to D8 is pressed, the value of the input signal at `A0` is read and stored in the variable sensorValue.



<!-- #region -->
(step7)=
## Step 7 - Outputting the value of sensorValue to the LEDs

The initial task asked for a program that outputs the value of the analogue input signal as a proportion of the maximum value on a series of LEDs. In this application, 8 LEDs are connected to PORT D and variable names `ledPin0` &ndash; `ledPin7` have been declared. At this stage, the programmer needs to work out the relationship between the analogue input signal and each LED. The analogue input signal is being processed by the built in Analog to Digital Converter or ADC of the ATmega 328 microcontroller which has a 10 bit resolution meaning the digital output will be an integer value in the range of 0:1023 ($2^{10}-1$). Dividing the maximum digital value by the number of LEDs:

$$\mathrm{EachLED} = \frac{1023}{8} = 127.875$$

Now that the relationship between the output of the ADC and the LEDs is known the programmer can create the flow control statements to implement the output. This can be achieved by using an if, else-if statement with 8 test conditions as follows[^note1]:

```c
if (sensorValue <= 127) {

} else if (sensorValue <= 255) {

} else if (sensorValue <= 383) {

} else if (sensorValue <= 511) {

} else if (sensorValue <= 639) {

} else if (sensorValue <= 767) {

} else if (sensorValue <= 895) {

} else if (sensorValue <= 1023) {

}
``` 

Finally, the programmer must populate each of these if statement blocks with the code to turn the correct LEDs on/off. Using the Arduino pre-defined functions there isn't an elegant way to manipulate the state of the whole port meaning each of the above test cases will need 8 digitalWrite statements. The first test condition, should only switch the first LED on and as such is written as:

```c
if (sensorValue <= 127) {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      digitalWrite(ledPin6, LOW);
      digitalWrite(ledPin7, LOW);
}
```
 

Once each of the test conditions has been populated with `digitalWrite` statements the code is complete and can uploaded to the Arduino Nano board.
<!-- #endregion -->

[^note1]: To avoid using floating point aritmetic, we have rounded $127.875$ to $127$. If you wanted to be really accurate, you could add the full value and round afterwards. For example $2\times 127.875 = 256$; $3\times 127.875 = 384$. Indeed it is arguable that $127.875$ is closer to $128$ than $127$!

## Appendix: Code Listing

(listing10)=
### Listing 10: An Example C Program
The complete code listing can be downloaded as a GitHub gist [example.ino](https://gist.github.com/cpjobling/27269c14e211e7d19657f0a147a3986d)
<script src="https://gist.github.com/cpjobling/27269c14e211e7d19657f0a147a3986d.js"></script>

```python
    
```
