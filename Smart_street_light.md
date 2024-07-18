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
int LDRPin=A0; // defining the LDR sensor's pin to read analog values
int LEDPin=8; // defining the LED pin to receive an output
int threshold=200; // setting a certain value after which the LED will turn on
void setup() // setting up the required inputs , outputs and beginning the serial communication
{
Serial.begin(9600); // making serial communication with the LDR sensor at 9600 beats per second
pinMode(LEDPin,OUTPUT); // defining the LED pin to give output
}
void loop() 
{
  int data=analogRead(LDRPin); // taking the analog values given by the LDR and storing them in a variable
//printing the values received from the LDR sensor
Serial.println("");   
Serial.print("Light Sensor");
Serial.print("value=");
Serial.print(data);
delay(1000); // giving a delay of 1 second in between printing the values

if(data>=threshold) // if the reading given by the sensor is higher than a certain amount then the light will turn on
{
  digitalWrite(LEDPin,HIGH); //LED turns on 
}
else // if the reading given by the sensor is lower than a certain amount then the light will remain off
{
  digitalWrite(LEDPin,LOW); // light remains off
}
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
   - **Check if LED is fused**: Make sure to check the led for possible fuse faults.

2. **LDR Not Reading Correctly**:
   - **Check LDR Connections**: Ensure the LDR is connected properly between the 5V, A0, and GND pins.
   - **Check Serial Monitor**: Verify that the LDR values are being printed to the serial monitor. If not, check the serial connection settings.

3. **Arduino Not Powering On**:
   - **Check Power Supply**: Ensure the Arduino is properly connected to a power source.
   - **Check USB Cable**: If using a USB cable, ensure it is functioning correctly.
   - **Check the arduino board for possible faults**: While operating with the arduino board there may be possible faults so check if the board is working before creating the project.
