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

1. **Circuit Setup on Breadboard:**

   **Components Placement:**
   - Place the Arduino Uno on one side of the breadboard, ensuring it spans the gap in the middle (if using a full-size breadboard).
   
   - **Ultrasonic Sensor (HC-SR04):**
     - Connect the VCC pin of the ultrasonic sensor to the positive rail of the breadboard.
     - Connect the GND pin of the ultrasonic sensor to the negative rail of the breadboard.
     - Connect the Trig pin of the ultrasonic sensor to digital pin 9 on the Arduino.
     - Connect the Echo pin of the ultrasonic sensor to digital pin 10 on the Arduino.

   - **Buzzer:**
     - Connect the positive terminal of the buzzer to digital pin 8 on the Arduino.
     - Connect the negative terminal of the buzzer to the negative rail of the breadboard.

   - **LEDs:**
     - Insert the LEDs into the breadboard.
     - Connect the anode (longer leg) of each LED to digital pins (e.g., 3, 4, 5) on the Arduino through current-limiting resistors (220 ohms recommended, though not strictly required for this setup).
     - Connect the cathode (shorter leg) of each LED to the negative rail of the breadboard.

   - **Power Supply:**
     - Connect the external power supply to the breadboard's power rails.
     - Ensure the positive lead (+) of the power supply is connected to the positive rail and the negative lead (-) to the negative rail.

   - **Arduino Connections:**
     - Connect Arduino's 5V pin to the positive rail of the breadboard.
     - Connect Arduino's GND pin to the negative rail of the breadboard.

2. **Code Installation:**
   - Use the Arduino IDE to write and upload the following code to the Arduino Uno:

```cpp
// Intruder Alarm System with Ultrasonic Sensor

const int trigPin = 9;  // Trig pin of the ultrasonic sensor
const int echoPin = 10;  // Echo pin of the ultrasonic sensor
const int buzzerPin = 8;  // Buzzer connected to digital pin 8
const int ledPin1 = 3;  // LED 1 connected to digital pin 3
const int ledPin2 = 4;  // LED 2 connected to digital pin 4
const int ledPin3 = 5;  // LED 3 connected to digital pin 5
const int thresholdDistance = 50;  // Threshold distance in cm

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by setting the trigPin HIGH for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin and calculate the distance:
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Calculate the distance in cm
  
  if (distance < thresholdDistance) {  // If object is within the threshold distance
    digitalWrite(buzzerPin, HIGH);  // Activate the buzzer
    digitalWrite(ledPin1, HIGH);  // Turn on LED 1
    digitalWrite(ledPin2, HIGH);  // Turn on LED 2
    digitalWrite(ledPin3, HIGH);  // Turn on LED 3
    Serial.println("Intruder detected!");
  } else {
    digitalWrite(buzzerPin, LOW);  // Deactivate the buzzer
    digitalWrite(ledPin1, LOW);  // Turn off LED 1
    digitalWrite(ledPin2, LOW);  // Turn off LED 2
    digitalWrite(ledPin3, LOW);  // Turn off LED 3
    Serial.println("No intruder.");
  }
  
  delay(1000);  // Delay for stability
}
```

#### Code Explanation:
- **Variables and Constants:**
  - `trigPin`: Defines the digital pin for the Trig pin of the ultrasonic sensor.
  - `echoPin`: Defines the digital pin for the Echo pin of the ultrasonic sensor.
  - `buzzerPin`: Defines the digital pin for the buzzer.
  - `ledPin1`, `ledPin2`, `ledPin3`: Define the digital pins for the LEDs.
  - `thresholdDistance`: Sets the distance threshold for triggering the alarm.

- **Setup Function:**
  - Sets the ultrasonic sensor's Trig pin as output and Echo pin as input.
  - Sets the buzzer and LEDs as outputs.
  - Initializes serial communication for debugging.

- **Loop Function:**
  - Clears the Trig pin, sends a 10-microsecond HIGH pulse to trigger the sensor, and reads the Echo pin to get the duration of the echo.
  - Calculates the distance based on the duration.
  - If the distance is less than the threshold, activates the buzzer and LEDs, and prints a message to the serial monitor.
  - If the distance is greater than the threshold, deactivates the buzzer and LEDs, and prints a message to the serial monitor.
  - Includes a delay for stability.

### Possible Errors:

1. **Incorrect Breadboard Connections:**
   - **Symptoms:** Buzzer or LEDs not functioning correctly.
   
2. **Unstable Sensor Readings:**
   - **Symptoms:** Buzzer or LEDs flicker or behave erratically.
   
3. **Serial Communication Issues:**
   - **Symptoms:** No serial output or incorrect sensor readings.

4. **Project not working (code issue)**
   - **Symptoms** No reading in the serial monitor or no sound by the buzzer

5. **Ultrasonic sensor giving no reading on serial monitor**
   - **Symptoms** No reading in the serial monitor or error message

### Troubleshooting Steps:

1. **Incorrect Breadboard Connections:**
   - **Troubleshooting:** Double-check all connections against the circuit diagram. Ensure components are inserted correctly into the breadboard and connected to the correct Arduino pins.

2. **Unstable Sensor Readings:**
   - **Troubleshooting:** Ensure the ultrasonic sensor is placed securely and not moving. Add a capacitor across the power rails of the breadboard to stabilize sensor readings.

3. **Serial Communication Issues:**
   - **Troubleshooting:** Verify baud rate (9600 in this case) matches in both code and serial monitor. Ensure Arduino is properly connected to the computer.

4. **Project not working (code issue)**
   - **Troubleshooting** Check the code for possible errors incase you fail to find any errors get it rechecked or restart the software
  
5. **Ultrasonic sensor giving no reading on serial monitor**
  - **Troubleshooting** Check if the trig and the echo pins of the sensor are connected to the respective digital pins of the arduino and make sure the trig and echo pins don't have their locations switched

#### Conclusion:
This documentation guides you through the process of building an intruder alarm system using Arduino Uno, ultrasonic sensor, buzzer, LEDs, and an external power supply, with all connections made on a breadboard. By following these steps and applying the troubleshooting tips, you can effectively construct and debug your intruder alarm project.
