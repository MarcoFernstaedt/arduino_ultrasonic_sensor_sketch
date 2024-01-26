// Define the Trig and Echo pin:
#define TRIG_PIN 12
#define ECHO_PIN 11

// Define the LED pin:
#define LED_PIN 13

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
    // Set the LED pin as an output:
    pinMode(LED_PIN, OUTPUT);
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
    // Calculating the distance in centimeters
    // distance = duration * 0.034 / 2;

    // Print the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    // Check if the distance is less than or equal to 61 cm
    if (distance <= 61) {
        // Turn the LED ON
        digitalWrite(LED_PIN, HIGH);
    } else {
        // Turn the LED OFF
        digitalWrite(LED_PIN, LOW);
    }

    // Delay 50ms before the next measurement:
    delay(50);
}
