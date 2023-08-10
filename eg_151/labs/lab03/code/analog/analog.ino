// the setup function runs once when you press reset or power the board

word ADCval = 0;

void setup() {

    // initialize Ports B and C pins 0-5 as outputs.

    DDRB = 0b00111111;
    DDRC = 0b00111111;

    PORTB = 0; // both ports start from zero
    PORTC = 0;
}

// the loop function runs over and over again forever

void loop() {

    PORTC = (analogRead(A6)) / 16; // and that’s the active bit of the programme!
}