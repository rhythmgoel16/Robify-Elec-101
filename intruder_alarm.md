### Documentation: Intruder Alarm System

#### Materials Required:
- Arduino Uno
- Ultrasonic sensor (HC-SR04)
- Buzzer
- LEDs (for visual indication)
- External power supply (battery or suitable adapter)
- Jumper wires (male-to-male and male-to-female)
- Breadboard

#### Construction Steps:

1. *Circuit Setup on Breadboard:*

   *Components Placement:*
   - Place the Arduino Uno on one side of the breadboard, ensuring it spans the gap in the middle (if using a full-size breadboard).
   
   - *Ultrasonic Sensor (HC-SR04):*
     - Connect the VCC pin of the ultrasonic sensor to the positive rail of the breadboard.
     - Connect the GND pin of the ultrasonic sensor to the negative rail of the breadboard.
     - Connect the Trig pin of the ultrasonic sensor to digital pin 9 on the Arduino.
     - Connect the Echo pin of the ultrasonic sensor to digital pin 10 on the Arduino.

   - *Buzzer:*
     - Connect the positive terminal of the buzzer to digital pin 8 on the Arduino.
     - Connect the negative terminal of the buzzer to the negative rail of the breadboard.

   - *LEDs:*
     - Insert the LEDs into the breadboard.
     - Connect the anode (longer leg) of each LED to digital pins (e.g., 3, 4, 5) on the Arduino.
     - Connect the cathode (shorter leg) of each LED to the negative rail of the breadboard.

   - *Arduino Connections:*
     - Connect Arduino's 5V pin to the positive rail of the breadboard.
     - Connect Arduino's GND pin to the negative rail of the breadboard.

2. *Code Installation:*
   - Use the Arduino IDE to write and upload the following code to the Arduino Uno:

cpp
// Intruder Alarm System with Ultrasonic Sensor

const int trigPin = 9;  // Trig pin of the ultrasonic sensor
const int echoPin = 10;  // Echo pin of the ultrasonic sensor
const int buzzerPin = 8;  // Buzzer connected to digital pin 8
const int ledPin1 = 3;  // LED 1 connected to digital pin 3
const int ledPin2 = 4;  // LED 2 connected to digital pin 4
const int ledPin3 = 5;  // LED 3 connected to digital pin 5
const int thresholdDistance = 50;  // Threshold distance in cm

long duration;  // Variable to store the duration of pulse
int distance;  // Variable to store the distance calculated

void setup() {
  pinMode(trigPin, OUTPUT);  // Set the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);  // Set the echoPin as an INPUT
  pinMode(buzzerPin, OUTPUT);  // Set the buzzerPin as an OUTPUT
  pinMode(ledPin1, OUTPUT);  // Set LED 1 as an OUTPUT
  pinMode(ledPin2, OUTPUT);  // Set LED 2 as an OUTPUT
  pinMode(ledPin3, OUTPUT);  // Set LED 3 as an OUTPUT
  Serial.begin(9600);  // Initialize serial communication at 9600 bits per second
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by setting the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin and calculate the distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convert duration to distance
  
  if (distance < thresholdDistance) {  // If the distance is less than the threshold
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
    digitalWrite(ledPin1, HIGH);  // Turn on LED 1
    digitalWrite(ledPin2, HIGH);  // Turn on LED 2
    digitalWrite(ledPin3, HIGH);  // Turn on LED 3
    Serial.println("Intruder detected!");  // Print a message to the serial monitor
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
    digitalWrite(ledPin1, LOW);  // Turn off LED 1
    digitalWrite(ledPin2, LOW);  // Turn off LED 2
    digitalWrite(ledPin3, LOW);  // Turn off LED 3
    Serial.println("No intruder.");  // Print a message to the serial monitor
  }
  
  delay(1000);  // Wait for a second before repeating the loop
}

#### Code Explanation:
- *Variables and Constants:*
  - trigPin: Defines the digital pin for the Trig pin of the ultrasonic sensor.
  - echoPin: Defines the digital pin for the Echo pin of the ultrasonic sensor.
  - buzzerPin: Defines the digital pin for the buzzer.
  - ledPin1, ledPin2, ledPin3: Define the digital pins for the LEDs.
  - thresholdDistance: Sets the distance threshold for triggering the alarm.

- *Setup Function:*
  - Sets the ultrasonic sensor's Trig pin as output and Echo pin as input.
  - Sets the buzzer and LEDs as outputs.
  - Initializes serial communication for debugging.

- *Loop Function:*
  - Clears the Trig pin, sends a 10-microsecond HIGH pulse to trigger the sensor, and reads the Echo pin to get the duration of the echo.
  - Calculates the distance based on the duration.
  - If the distance is less than the threshold, activates the buzzer and LEDs, and prints a message to the serial monitor.
  - If the distance is greater than the threshold, deactivates the buzzer and LEDs, and prints a message to the serial monitor.
  - Includes a delay for stability.

### Possible Errors:

1. *Incorrect Breadboard Connections:*
   - *Symptoms:* Buzzer or LEDs not functioning correctly.
   
2. *Unstable Sensor Readings:*
   - *Symptoms:* Buzzer or LEDs flicker or behave erratically.
   
3. *Serial Communication Issues:*
   - *Symptoms:* No serial output or incorrect sensor readings.

### Troubleshooting Steps:

1. *Incorrect Breadboard Connections:*
   - *Troubleshooting:* Double-check all connections against the circuit diagram. Ensure components are inserted correctly into the breadboard and connected to the correct Arduino pins.

2. *Unstable Sensor Readings:*
   - *Troubleshooting:* Ensure the ultrasonic sensor is placed securely and not moving. Add a capacitor across the power rails of the breadboard to stabilize sensor readings.

3. *Serial Communication Issues:*
   - *Troubleshooting:* Verify baud rate (9600 in this case) matches in both code and serial monitor. Ensure Arduino is properly connected to the computer.

#### Conclusion:
This documentation guides you through the process of building an intruder alarm system using Arduino Uno, ultrasonic sensor, buzzer, LEDs, and an external power supply, with all connections made on a breadboard. By following these steps and applying the troubleshooting tips, you can effectively construct and debug your intruder alarm project.
