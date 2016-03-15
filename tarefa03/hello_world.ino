#include "event_driven.c"

int BUTTON_PIN = 2;
int LED_PIN = 13;

void button_changed (int pin, int v) {
  digitalWrite(ledPin, v);
}

void timer_expired () {}

void initialize () {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  button_listen(buttonPin);
}
