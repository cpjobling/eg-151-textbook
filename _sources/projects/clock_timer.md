(clock_timer)=
# Clock Time

**Brief**: to produce a clock display with hours, minutes, seconds display plus day of week.

The minimum requirement will be to have a digital clock display which advances at the correct rate.

Additional marks for the degree of sophistication of the timer functions, for example multiple events; one-off and regular events; and GMT/BST switching. Additional hardware will be provided in the form of relays to drive the load.

The starting point for this project is {ref}`Getting_Started_with_the_Time_Clock_Project`. It shows you how to set the *epoch time* for a clock, adjust it to clock time and then display the time in hours minutes and seconds. The display code is similar to the code used in {ref}`lab_1`.

After that is done, you need to add inputs and outputs and additional functionality to allow for setting the time, setting alarms, creating timers and stop watches, etc.

Marks will be awarded as follows:

- 0 to 40%: If some kind of activity is seen on the LCD.

- 40 to 50%: If the display is formatted into hours, minutes etc. and advances correctly.

- 50 to 60%: If there is at least one relay driven on and off at specified time.

- 60 to 70%: For more advanced timer functions.

- 70% plus: For additional functionality such as daily, weekly events.

(Getting_Started_with_the_Time_Clock_Project)=
## Getting Started with the Time Clock Project


### Starter code
The starter code starts the clock at an arbitrary time and then uses the `millis()` function to keep the clock time synchronised to the *initial epoch time*. I have used the Serial monitor for the output and you will need to change the code to use the LCD panel.  

The Serial monitor is still useful during development and for debugging though!

Your first task will be to set the initial time in the `setup()` function before you press the button on pin 2 or Port D to set the clock time. After that, the clock time should keep reasonable time based on the epoch time stored in `epoch_time`.

<script src="https://gist.github.com/cpjobling/35399e801a4031f184f9830f992978f2.js"></script>

### Tips
Your program will benefit from the use of functions, e.g. to display current time you could write a function:

```c
void display_time(int hours, int minutes, int hours) {
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.print(seconds);
  Serial.println(" ");
}
```

When you want to display the time you will just call

```c
display_time(hours, minutes, seconds);
```

As you extend the clock, you will occasionally need to leave the main loop, e.g. to set an alarm. This means that the loop will not be updating the time while you are doing something else.

You will therefore need a function to compute the current clock time in elapsed hours, minutes and seconds from `clock_time`. How to do this is left as an exercise, but the MATLAB code *clocks.mlx* which you will find in my the shared MATLAB drive folder [eg-151](https://drive.matlab.com/sharing/8c2dab30-101e-4072-a96c-2fb9d6e6d114) may help help you to understand how you might do the computations needed.

Note that in MATLAB `mod(11,2)` is equivalent to the C code:
```c
11 % 2; // = 1: remainder of 11/2
```
and `floor(11,2)` is equivalent to to the C code:
```c
11 / 2; // = 5: integer division gives 5.5 rounded down to nearest integer
```

You will need both integer division and modulo division to convert a time defined in milliseconds elapsed into actual clock time in hours:minutes:seconds.

```python

```
