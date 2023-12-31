(weather_station)=
# Weather Station

**Brief**: to produce a weather station with at least two of the following measurements:

Wind speed, wind direction, temperature.

All inputs will be converted to voltages, using a 360 degree potentiometer for wind direction, a dc generator for wind speed, and LM35 type temperature sensors. The information must be displayed in separate fields on the 16 by 2 LCD.

More information to get you started on this project is provided here: {ref}`Weather_Station_Demonstration`.

Marks will be awarded as follows:

- 0 to 40%: For a non-functional unit which has some information on the LCD.
- 40 to 50%: For display of at least one of the measurements specified.
- 50 to 60% For display of at least two of the measurements specified and suitably formatted.
- 60 to 70%: For display of all three measurements.
- 70% plus: For additional functionality such as max and min values, extra displays such as a ring of eight LEDs to show wind direction using cardinal points.

<!-- #region -->
(Weather_Station_Demonstration)=
## Weather Station Demonstration

Watch Dr. Davies explaining how to approach the Weather Station mini-project.

The video lasts 17 minutes.

<iframe src="https://swanseauniversity.cloud.panopto.eu/Panopto/Pages/Embed.aspx?id=d19625f9-e2fb-447d-b93a-af5d016bd8fa&autoplay=false&offerviewer=true&showtitle=true&showbrand=true&captions=true&interactivity=all" height="405" width="720" style="border: 1px solid #464646;" allowfullscreen allow="autoplay" aria-label="Panopto Embedded Video Player"></iframe>


Here is a sketch of the op-amp circuit.

```{image} pictures/opamp.jpg
:alt: opamp circuit for temperature sensor
```



And here are details of the LM324 op-amp and LM35 temperature sensor.

```{image} pictures/lm35.jpg
:alt: details of the LM324 op-amp and LM35 temperature sensor
```


Here are some photos of the advanced demonstration programme running.

```{image} pictures/wprototype1.jpg
:alt: Prototype weather station showing wind speed and wind direction
```

Note that the wind direction has been scaled to give a number 0 to 359 instead of 0 to 1023.




In this photo, the "raw" temperature data has been scaled to give degrees Celsius.

```{image} pictures/wprototype2.jpg
:alt: Prototype weather station temperature measurement
```



Here is a listing of the basic programme, which presents the "raw" data 0 to 1023.

<script src="https://gist.github.com/cpjobling/b7a8cc466a1b5d3292cbb9f261474a13.js"></script>
<!-- #endregion -->

```python

```
