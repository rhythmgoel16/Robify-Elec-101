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
