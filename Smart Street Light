#### Materials Required
1. **Arduino Uno**: The microcontroller board.
2. **LDR Sensor**: Light Dependent Resistor to detect ambient light.
3. **LEDs**: Light Emitting Diodes to simulate street lights.
4. **Power Supply**: To power the Arduino and LEDs.
5. **Jumper Wires**: For making connections.
6. **Breadboard**: For prototyping and connecting components.

#### Assembly Instructions
1. **Connecting the LDR Sensor**:
   - Connect one terminal of the LDR to the 5V pin on the Arduino.
   - Connect the other terminal of the LDR to the A0 analog input pin on the Arduino.
   - Connect the same terminal of the LDR (connected to A0) to the GND pin on the Arduino using a jumper wire.

2. **Connecting the LEDs**:
   - Connect the anode (longer leg) of the LED to digital pin 9 on the Arduino.
   - Connect the cathode (shorter leg) of the LED to the GND pin on the Arduino.

3. **Powering the Arduino**:
   - Connect the Arduino to a power supply using the USB cable or a 9V battery.

#### Arduino Code
```cpp
const int LDRPin = A0; // Analog pin for LDR sensor
const int LEDPin = 9;  // Digital pin for LED
int LDRValue = 0;      // Variable to store LDR value

void setup() {
  pinMode(LEDPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600);      // Start serial communication for debugging
}

void loop() {
  LDRValue = analogRead(LDRPin); // Read the LDR value
  Serial.println(LDRValue);      // Print the LDR value to the serial monitor

  // If ambient light is low (i.e., it is dark), turn on the LED
  if (LDRValue < 500) {
    digitalWrite(LEDPin, HIGH);  // Turn on LED
  } else {
    digitalWrite(LEDPin, LOW);   // Turn off LED
  }

  delay(1000); // Wait for a second before repeating the loop
}
```

#### Code Explanation
- **LDRPin and LEDPin**: Variables to define the pins connected to the LDR sensor and the LED.
- **LDRValue**: Variable to store the value read from the LDR sensor.
- **setup()**: Initializes the LED pin as an output and starts serial communication for debugging.
- **loop()**: Continuously reads the value from the LDR sensor, prints it to the serial monitor, and turns the LED on or off based on the ambient light level.

#### Possible Errors and Troubleshooting
1. **LED Not Turning On**:
   - **Check Connections**: Ensure all connections are correct and secure.
   - **Check Code**: Verify that the code is uploaded correctly and the pin numbers match the connections.
   - **Check LED Orientation**: Ensure the anode and cathode of the LED are connected properly.

2. **LDR Not Reading Correctly**:
   - **Check LDR Connections**: Ensure the LDR is connected properly between the 5V, A0, and GND pins.
   - **Check Serial Monitor**: Verify that the LDR values are being printed to the serial monitor. If not, check the serial connection settings.

3. **Arduino Not Powering On**:
   - **Check Power Supply**: Ensure the Arduino is properly connected to a power source.
   - **Check USB Cable**: If using a USB cable, ensure it is functioning correctly.

By following this documentation, you should be able to successfully assemble and program a smart street light using the provided materials. If you encounter any issues, refer to the troubleshooting section for possible solutions.
