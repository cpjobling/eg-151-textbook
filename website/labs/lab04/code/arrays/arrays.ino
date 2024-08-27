// the setup function runs once when you press reset or power the board

int total = 0; // This variable will contain the running total.

int numbers[7] = {2, 9, 5, 4, 5, 6, 7}; // Create an integer array and preload.

byte index = 0;

void setup() {

    // initialize Ports B and C pins 0-5 as outputs.

    DDRB = 0b00111111;

    DDRC = 0b00111111;

    PORTB = 0; // both ports start from zero

    PORTC = 0;
}

// the loop function runs over and over again forever

void loop() {

    total = 0;

    for (index = 0; index < 7; index++) {

        PORTC = numbers[index]; // The LEDs on Port C show the current array value.

        total = total + numbers[index];

        PORTB = total; // The LEDs on Port B show the running total.

        delay(1000); // A one second delay.
    }

    PORTC = total; // Finally, the LEDs on Port C show the total of all the digits.

    delay(2000); // A two second delay,then start all over again.
}
