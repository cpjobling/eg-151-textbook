// the setup function runs once when you press reset or power the board

byte counter1 = 0; // define variables
byte counter2 = 0;

void setup() {
    // initialize Ports B and C pins 0-5 as outputs.
    DDRB = 0b00111111;
    DDRC = 0b00111111;
    PORTB = 0; // both ports start from zero
    PORTC = 0;
}

// the loop function runs over and over again forever

void loop() {

    for (counter1 = 0; counter1 < 60; counter1++) {
        PORTC = counter1;
        for (counter2 = 0; counter2 < 60; counter2++) {
            PORTB = counter2;
            delay(1000);
        }
    }
}
