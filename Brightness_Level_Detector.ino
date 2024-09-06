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
