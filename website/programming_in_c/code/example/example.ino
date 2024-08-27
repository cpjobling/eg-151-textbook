//Pin Defintions
const int pushButton = 8;
const int inputSignal = A0;
const int ledPin0 = 0;
const int ledPin1 = 1;
const int ledPin2 = 2;
const int ledPin3 = 3;
const int ledPin4 = 4;
const int ledPin5 = 5;
const int ledPin6 = 6;
const int ledPin7 = 7;

//Variable declarations
int sensorValue = 0;

void setup() {

  // put your setup code here, to run once:
  pinMode(pushButton, INPUT_PULLUP);  // Default value is high, pressed value is low
  pinMode(inputSignal, INPUT);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);

  //Set the initial state of the LEDs to be off
  digitalWrite(ledPin0, LOW);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
  digitalWrite(ledPin7, LOW);
}


void loop() {
  //if statement to test if pushButton has been pressed
  //Default pushButton state is high as the pull-up resitor is enabled
  if (digitalRead(pushButton) == LOW) {
    // read the value from the sensor ans store the result in sensorValue variable
    sensorValue = analogRead(inputSignal);

    // Write to the LEDS
    if (sensorValue <= 127) {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      digitalWrite(ledPin6, LOW);
      digitalWrite(ledPin7, LOW);
    } else if (sensorValue <= 255) {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      digitalWrite(ledPin6, LOW);
      digitalWrite(ledPin7, LOW);
    } else if (sensorValue <= 383) {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      digitalWrite(ledPin6, LOW);
      digitalWrite(ledPin7, LOW);
    } else if (sensorValue <= 511) {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      digitalWrite(ledPin6, LOW);
      digitalWrite(ledPin7, LOW);
    } else if (sensorValue <= 639) {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      digitalWrite(ledPin5, LOW);
      digitalWrite(ledPin6, LOW);
      digitalWrite(ledPin7, LOW);
    } else if (sensorValue <= 767) {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      digitalWrite(ledPin5, HIGH);
      digitalWrite(ledPin6, LOW);
      digitalWrite(ledPin7, LOW);
    } else if (sensorValue <= 895) {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      digitalWrite(ledPin5, HIGH);
      digitalWrite(ledPin6, HIGH);
      digitalWrite(ledPin7, LOW);
    } else if (sensorValue <= 1023) {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      digitalWrite(ledPin5, HIGH);
      digitalWrite(ledPin6, HIGH);
      digitalWrite(ledPin7, HIGH);
    }
  }
}