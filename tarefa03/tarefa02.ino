#include "event_driven.c"

int LED_PIN = 13;
int BUTTON_VEL_UP_PIN = 2;
int BUTTON_VEL_DOWN_PIN = 3;

int lastTimeButtonVelUpPressed, lastTimeButtonVelDownPressed;
int timeLedToggle;
bool flagStop;

void button_changed (int pin, int v) {
  int diffTimeButtonsPressed;
  
  if (pin == BUTTON_VEL_UP_PIN) {
    if(v) { // Botão foi apertado
      timeLedToggle = timeLedToggle / 2;
      lastTimeButtonVelUpPressed = millis();
    }
  }
  else if (pin == BUTTON_VEL_DOWN_PIN) {
    if(v) { // Botão foi apertado
      timeLedToggle = timeLedToggle * 2;
      lastTimeButtonVelDownPressed = millis();
    }
  }

  diffTimeButtonsPressed = lastTimeButtonVelUpPressed - lastTimeButtonVelDownPressed;
  if (diffTimeButtonsPressed >= -500 && diffTimeButtonsPressed <= 500) {
    flagStop = true;
  }
}

void timer_expired () {
  if (!flagStop) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    timer_set(timeLedToggle);
  }
}

void initialize () {
  flagStop = false;
  timeLedToggle = 1000;
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_VEL_UP_PIN, INPUT);
  pinMode(BUTTON_VEL_DOWN_PIN, INPUT);

  button_listen(BUTTON_VEL_UP_PIN);
  button_listen(BUTTON_VEL_DOWN_PIN);
  timer_set(timeLedToggle);
}
