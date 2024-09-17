// the setup function runs once when you press reset or power the board

byte counter1 = 0; // define variables
byte counter2 = 0; // not used in this programme

void setup() {
    // initialize Ports B and C pins 0-5 as outputs.

    DDRB = 0b00111111;
    DDRC = 0b00111111;
    PORTB = 0; // both ports start from zero
    PORTC = 0;

    pinMode(2, INPUT_PULLUP); // Make bit 2 of Port D an input
    pinMode(3, INPUT_PULLUP); // Make bit 3 of Port D an input
}

// the loop function runs over and over again forever

void loop() {

    PORTC = counter1;

    if (digitalRead(2) != 0) {
        counter1++;
    } // same decision as previous

    if (digitalRead(3) != 0) {
        delay(1000);
    } // long delay is default
    else {
        delay(100);
    } // short delay if button is pressed
}
