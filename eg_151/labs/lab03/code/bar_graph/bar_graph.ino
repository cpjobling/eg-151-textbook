// the setup function runs once when you press reset or power the board

word ADCval = 0;

void setup() {

    // initialize Ports B and C pins 0-5 as outputs and set them to zero initially

    DDRB = 0b00111111;
    DDRC = 0b00111111; // may as well put them on the same line

    PORTB = 0;
    PORTC = 0; // and these statements too
}

// the loop function runs over and over again forever

void loop() {

    ADCval = analogRead(A6);

    if (ADCval >= 854) {
        PORTC = 0b00111111;
    } // all six LEDs on
    else if (ADCval >= 684) {
        PORTC = 0b00011111;
    } // five LEDs on
    else if (ADCval >= 513) {
        PORTC = 0b00001111;
    } // four LEDs on
    else if (ADCval >= 342) {
        PORTC = 0b00000111;
    } // three LEDs on
    else if (ADCval >= 171) {
        PORTC = 0b00000011;
    } // two LEDs on
    else if (ADCval >= 1) {
        PORTC = 0b00000001;
    } // one LED on
    else {
        PORTC = 0; // all LEDs off
    }
}