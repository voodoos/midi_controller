#include "src/Potentiometer.h"

// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.x / Teensy LC have the LED on pin 13
const int ledPin = 11;

// the setup() method runs once, when the sketch starts

void setup() {
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop() methor runs over and over again,
// as long as the board has power

int prop(int val) {
 return (127.0 * analogRead(0)) / 1023.0;
}

int last_val = 0;

void loop() {
  int val = prop(analogRead(0));
  Serial.println(val);
  if(val != last_val) {
    usbMIDI.sendControlChange(7, val, 0);
    val = last_val;
  }
  
  // MIDI Controllers should discard incoming MIDI messages.
  while (usbMIDI.read()) {
  }
  //digitalWrite(ledPin, HIGH);   // set the LED on
  //delay(50);                  // wait for a second
  //digitalWrite(ledPin, LOW);    // set the LED off
  //delay(50);                  // wait for a second
}
