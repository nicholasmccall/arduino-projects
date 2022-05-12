#include <Arduino.h>

int waitTime = 5000;
int onePin = 2;
int twoPin = 3;
int fourPin = 4;
int eightPin = 5;

void light_four_bit_led_array(int number, int onePin, int twoPin, int fourPin, int eightPin, int onTime){
  Serial.println(number);
  // If we are fed a number higher than our maximum number, ignore it.
  if (number > 15){
    Serial.println("Number was too high to write, ignoring...");
    return;
  }

  // If the number is less than the max, progressively work through each bit
  // lighting up each one and then recalculating the remaining number.

  int remainder = number;

  if(remainder >= 8){
    digitalWrite(eightPin, HIGH);
    remainder = number - 8;
  }

  if(remainder >= 4){
    digitalWrite(fourPin, HIGH);
    remainder = remainder - 4;
  }

  if(remainder >= 2){
    digitalWrite(twoPin, HIGH);
    remainder = remainder - 2;
  }

  if(remainder >= 1){
    digitalWrite(onePin, HIGH);
  }

  // Clean up all our LEDs after the wait time
  delay(onTime);
  digitalWrite(eightPin, LOW);
  digitalWrite(fourPin, LOW);
  digitalWrite(twoPin, LOW);
  digitalWrite(onePin, LOW);

  Serial.println("--------");
  return;
}

void setup() {
  pinMode(onePin, OUTPUT);
  pinMode(twoPin, OUTPUT);
  pinMode(fourPin, OUTPUT);
  pinMode(eightPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i=0; i <= 15; i++){
    light_four_bit_led_array(i, onePin, twoPin, fourPin, eightPin, waitTime);
  }
}