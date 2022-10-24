/*
  POT Bit Value and Voltage with 5 LEDS
  Use potentiometer, set pin to A0 as input
  Analog read on pin A0 and prints the results to the Serial Monitor, bit value and voltage
  Analog write to set state of LED
  Use serial begin to start serial monitoring, and use serial.print or serial.println to print value
  Use float to convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
  Use bit value of analog read to determine amount of LEDs light up
  As you turn the potentiometer the bit value increases and so does the voltage
*/

int var = 0; // variable set to 0

// the setup function runs once when you press reset or power the board
void setup() {
  
  pinMode(A0, INPUT); // setting pin A0 as an input (Potentiometer)
  pinMode(2, OUTPUT); // setting pin 2 as output (LED 1)
  pinMode(3, OUTPUT); // setting pin 3 as output (LED 2)
  pinMode(4, OUTPUT); // setting pin 4 as output (LED 3)
  pinMode(5, OUTPUT); // setting pin 5 as output (LED 4)
  pinMode(6, OUTPUT); // setting pin 6 as output (LED 5)
  Serial.begin(9600); // initialize serial communication
  Serial.println("Reading Analog Value"); // pushbutton print value
}

// the loop routine runs over and over again forever
void loop() {

  int var = analogRead(A0); // read the input on analog pin 0
  
  Serial.print("potValue"); // print out the state of the button
  Serial.print(var); //print out the value you read
  Serial.print(" Voltage:"); // print out the state of the button
  float voltage = var * (5.0 / 1023.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
  Serial.print(voltage); //print out the value you read
  Serial.println("V"); // print out the state of the button
  
  delay(100); // delay between each read
  
  
  if(var < 200) // if bit value is less than 200 LED 1 lights up
  {
    digitalWrite(2, 1); // set to high turning on LED 1
    digitalWrite(3, 0); // set to 0 LED 2 off
    digitalWrite(4, 0); // set to 0 LED 3 off
    digitalWrite(5, 0); // set to 0 LED 4 off 
    digitalWrite(6, 0); // set to 0 LED 5 off
    
  }
  else if(var < 400) // if bit value is less than 400 LED 1 and 2 lights up
  {
    digitalWrite(2, 1); // set to high turning on LED 1
    digitalWrite(3, 1); // set to high turning on LED 2
    digitalWrite(4, 0); // set to 0 LED 3 off
    digitalWrite(5, 0); // set to 0 LED 4 off
    digitalWrite(6, 0); // set to 0 LED 5 off
    
  }
  else if(var < 600) // if bit value is less than 600 LED 1, 2, and 3 lights up
  {
    digitalWrite(2, 1); // set to high turning on LED 1
    digitalWrite(3, 1); // set to high turning on LED 2
    digitalWrite(4, 1); // set to high turning on LED 3
    digitalWrite(5, 0); // set to 0 LED 4 off
    digitalWrite(6, 0); // set to 0 LED 5 off
    
  }
  else if(var < 800) // if bit value is less than 800 LED 1, 2,3 and 4 lights up
  {
    digitalWrite(2, 1); // set to high turning on LED 1
    digitalWrite(3, 1); // set to high turning on LED 2
    digitalWrite(4, 1); // set to high turning on LED 3 
    digitalWrite(5, 1); // set to high turning on LED 4
    digitalWrite(6, 0); // set to 0 LED 5 off
  
  }
  else // bit value higher than 800 all LEDs (1-5) light up
  {
    digitalWrite(2, 1); // set to high turning on LED 1
    digitalWrite(3, 1); // set to high turning on LED 2
    digitalWrite(4, 1); // set to high turning on LED 3
    digitalWrite(5, 1); // set to high turning on LED 4
    digitalWrite(6, 1); // set to high turning on LED 5
  }
}
