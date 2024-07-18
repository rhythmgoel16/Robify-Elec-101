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
