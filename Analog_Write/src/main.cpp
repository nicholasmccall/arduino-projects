#include <Arduino.h>

int ledPin = 3;
int minBrightness = 0;
int maxBrightness = 255;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Make the LED ping pong between lit and off

  // Glow
  for(int i=minBrightness; i <= maxBrightness; i++){
    Serial.println(i);
    analogWrite(ledPin, i);
    delay(10);
  }

  // Dim
  for(int i=maxBrightness; i >= minBrightness; i--){
    Serial.println(i);
    analogWrite(ledPin, i);
    delay(10);
  }

}