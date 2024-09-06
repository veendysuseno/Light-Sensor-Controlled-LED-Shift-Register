# Light Sensor Controlled LED Shift Register

This project demonstrates how to control an 8-segment LED display using a shift register (e.g., 74HC595) based on the brightness detected by a photoresistor. The brightness level adjusts how many LEDs are lit up.

## Components Used

- Arduino Uno
- 74HC595 Shift Register
- 8 LEDs
- 8 Resistors (220Ω recommended for each LED)
- Photoresistor (LDR)
- 10kΩ Resistor (for LDR)
- Jumper wires
- Breadboard

## Pin Configuration

- **PHOTORESISTOR_PIN**: connected to the photoresistor (Pin A5).
- **DATA_PIN**: connected to the data input of the shift register (Pin A2).
- **LATCH_PIN**: connected to the latch pin of the shift register (Pin A3).
- **CLOCK_PIN**: connected to the clock pin of the shift register (Pin A4).

## How It Works

- The Arduino reads the brightness level from the photoresistor.
- The brightness level is mapped to a value that determines how many LEDs will be lit up.
- The shift register is used to control the LEDs based on this mapped value.

## Code

```cpp
const int PHOTORESISTOR_PIN = A5;
const int CLOCK_PIN = A4;
const int LATCH_PIN = A3;
const int DATA_PIN = A2;

void setup() {
    pinMode( PHOTORESISTOR_PIN, INPUT );
    pinMode( CLOCK_PIN, OUTPUT );
    pinMode( LATCH_PIN, OUTPUT );
    pinMode( DATA_PIN, OUTPUT );
    Serial.begin( 9600 );
}

void loop() {

    int brightness = analogRead( PHOTORESISTOR_PIN );
    Serial.println( brightness );

    int val = map( brightness, 0, 880, 0, 8 );

    update( val );
}

void update( int val ) {

    digitalWrite( LATCH_PIN, LOW );

    for( int i = 0; i < 8; i++ ) {
        digitalWrite( DATA_PIN, (i < val) );
        digitalWrite( CLOCK_PIN, LOW );
        digitalWrite( CLOCK_PIN, HIGH );
    }

    digitalWrite( LATCH_PIN, HIGH );
}
```

## How to Use

1. Connect the shift register and LEDs to the Arduino as described in the pin configuration.
2. Connect the photoresistor to the analog pin A5 and a 10kΩ resistor in series.
3. Open the Serial Monitor in the Arduino IDE.
4. Set the baud rate to 9600 bps.
5. Observe the number of lit LEDs changing with the light intensity falling on the photoresistor.

## Features

- Uses a photoresistor to control an 8-segment LED display.
- The number of lit LEDs varies with light intensity.
- Demonstrates the use of shift registers and analog sensors with Arduino.

## License

This project is open-source and can be modified or distributed freely.
