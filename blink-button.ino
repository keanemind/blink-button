/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +3.3V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 modified Apr 27 2012
 by Robert Wessels
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = PUSH2;     // the number of the pushbutton pin
//const int ledPin =  GREEN_LED;      // the number of the LED pin
const int ledPin = P1_0;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int counter = 0;
bool flipped = true;
long previousMillis = 0;
int ledState = LOW;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  unsigned long currentMillis = millis();

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW && flipped) {     
    // flip the variable:    
    counter += 1;  
    if (counter == 8) {
      counter = 0;
    }
    flipped = false;
  } 
  if (buttonState == HIGH) {
    flipped = true;
  }

  switch (counter) {
    case 0: 
      digitalWrite(ledPin, LOW);
      break;
    case 1: 
      try_to_switch_led(currentMillis, 1024);
      break;
    case 2: 
      try_to_switch_led(currentMillis, 512);
      break;
    case 3: 
      try_to_switch_led(currentMillis, 256);
      break;
    case 4: 
      try_to_switch_led(currentMillis, 128);
      break;
    case 5: 
      try_to_switch_led(currentMillis, 64);
      break;
    case 6: 
      try_to_switch_led(currentMillis, 32);
      break;
    case 7: 
      try_to_switch_led(currentMillis, 16);
      break;
  }

  delay(1);
}

void try_to_switch_led(unsigned long currentMillis, long interval){
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}

