// the setup function runs once when you press reset or power the board

byte counter1 = 0; // we need to define the variable counter1

void setup() {
    // initialize Port C pins 0-5 as outputs.
    DDRC = 0b00111111; // the prefix &ldquo;0b&rdquo; qualifies the number as binary
    PORTC = 0; // so all the LEDs are off initially
}

// the loop function runs over and over again forever
void loop() {
    PORTC = counter1;
    // we could replace the next line with: counter1++;
    counter1 = counter1 + 1;

    // Uncomment the following 3 lines for a modulus of 60: 
    // if(counter1 < 59) {
    //     counter1 = 0;
    // }

    delay(1000); // reduce the delay if you get bored waiting!
}

