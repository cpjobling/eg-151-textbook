(programming_in_c_3)=
# Wiring up the Circuit


Referencing the pinout of the Arduino nano in {numref}`

` below, the programmer must first identify where each of the three hardware elements will be connected, ensuring that the pins/ports meet the requirements.

- For the push button switch, this will be a digital signal (on/off) so can be connected to any GPIO pin.
  - Looking at the other hardware requirements, this should avoid the pins connected to the ADC and leave a full port of input pins for the LEDs. For this example, connection `D8` of the nano board is a convenient pin to use, this is connected to `PB0`, i.e. Port B bit 0[^note].
- For the analogue input, this can be connected to any of the GPIO pins which is also connected to the ADC.
  - Looking at {numref}`fig:ccode:1`, these connections are labelled `A0` &ndash; `A7` on the nano board. Connection `A0` is connected to `PC0`, i.e. Port C bit 0 which is also connected to ADC[0] &ndash; ADC channel 0.
- The LEDs can be connected to any digital GPIO pin, but ideally will be 8 pins on the same port.
  - Looking at {numref}`fig:ccode:1` and the two pins we have used above, connections `D0` &ndash; `D7` can be used which corresponds to Port D bits 0-7[^note3].
 
A possible assembly is illustrated in {numref}`fig:ccode:2`[^note4]
 


## Figures

```{figure} pictures/ArduinoNanoPinout.png
:name: fig:ccode:1
:align: center
:width: 100%
:alt: Arduino Nano Pinout.

Arduino Nano Pinout - [Arduino Nano links](https://docs.arduino.cc/hardware/nanoLinks).
```

```{figure} pictures/AssembledCircuit.png
:name: fig:ccode:2
:align: center
:width: 100%
:alt: A photograph of circuit assembled on breadboard.

The circuit assembled on breadboard
```


## Notes

[^note1]: the programmer could also use `D9`, `D10`, `D11`, `D12` etc.

[^note2]: the programmer could also use `A1`, `A2`, `A3`, `A4`, etc.)

[^note3]: pins across multiple ports *can* be used but this will make the programming more complicated.

[^note4]: When building this circuit, it is advised that the red wire from the 5V output of the Arduino nano board to the bottom rail of the breadboard is replaced with a 220 Ohm resistor, this will protect the USB circuitry within the PC in the event of any wiring faults/short circuits between the rails.  


```python

```
