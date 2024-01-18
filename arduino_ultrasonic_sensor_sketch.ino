// Define the Trig and Echo pin:
#define TRIG_PIN 13
#define ECHO_PIN 12

// Variables for the duration and the distance:
long duration;
int distance;

void setup()
{
    // Begin serial communication at a baud rate of 9600:
    Serial.begin(9600);
    // Define the pins as Output and Input
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop()
{
    // Clear the TRIG_PIN by setting it LOW:
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Trigger the sensor by setting the TRIG_PIN high for 10 microseconds:
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read the Echo, returns the sound wave travel time in microseconds
    duration = pulseIn(ECHO_PIN, HIGH);

    // Calculating the distance in inches
    distance = duration * 0.0135 / 2;
    // Calculating the distance in centameters
    // distance = duration * 0.034 / 2;

    // Print the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    // Delay 50ms before the next measurement:
    delay(50);
}
