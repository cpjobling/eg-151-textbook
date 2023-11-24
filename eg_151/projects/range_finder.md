(ultrasound_range_finder)=
# Ultrasonic Range Finder

**Brief**: to connect an SR04 ultrasonic module to the Arduino Nano and the 16 by 2 LCD.

More information to get you started on this project is provided below.

The minimum requirement will be for the display to show a number which is proportional to the distance to the target. Additional marks will be given if the display is properly calibrated, can be switched from mm to feet and inches, and uses averaging to give a steady reading.

Marks will be awarded as follows:

- 0 to 40%: For a non-functional unit which nevertheless has some meaningful reading.

- 40 to 50%: For a minimal implementation of the specification, with a reading which goes up and down as the target is moved away from and towards the sensor.

- 50 to 60%: For a range finder with accurate calibration and averaging.

- 60 to 70%: For additional functionality such as a button to zero the reading for difference.

- 70% plus: A range finder with advanced functionality such as area measurement.

## Technical Information

Here are some thoughts about the ultrasonic range finder, and a brief piece of code which is FAR from ideal!

Here is a picture of the Experiment 5 breadboard with the ultrasonic module connected, and showing a time interval of about 500&mu;s for the echo. That corresponds to about 160 mm, divided by two for out and back, which is 80 mm. Look at the ruler; the distance from the cardboard box and the back of the sensor is about 80 mm, so we are not far off the correct measurement.

```{image} pictures/ultra_son_prototype.jpg
:alt: A prototype of an ultrasonic range finder built with an Arduino nano and ultrasonic module.
```

Now look at the waveforms on the oscilloscope.

```{image} pictures/SCR19.png
:alt: Oscilloscope trace showing the triggering pulse and the return echo.
```

You will see that the "trig" pulse is very narrow, about 5 &mu;s, which is plenty. The echo pulse is about 500 &mu;s, corresponding to the number on the LCD. 

The code to produce the above waveform follows. It is for GUIDANCE ONLY, as it has no averaging or scaling, and it "locks up" if no echo is received.

Trig is on A0/digital pin 14, and Echo is on A1/digital pin 15.

<script src="https://gist.github.com/cpjobling/7639b8e8e2cafdd653d25f720a93d20b.js"></script>

```python

```
