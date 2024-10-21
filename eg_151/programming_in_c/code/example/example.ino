// Declare variables to be used as counters.
byte counter1, counter2;

// the setup function runs once when you press reset or power the board
void setup() {
    // define counters
    counter1 = counter2 = 0; // initialize counters

    // initialize Ports B and C pins 0-5 as outputs.
    DDRB = 0b00111111;
    DDRC = 0b00111111;

    PORTB = PORTC = 0; // both ports start from zero
}

// the loop function runs repeatedly forever
void loop() {
    PORTB = counter2; // counter2 is our "seconds" counter
    PORTC = counter1; // counter1 is our "minutes" counter

    if (counter2 > 59) {
        counter2 = 0;
        if (counter1 > 59) {
            counter1 = 0;
        }
        counter1++;
    }
    counter2++; // using the tip we learnt earlier

    delay(1000); // again, reduce this delay if necessary to speed things up.
}