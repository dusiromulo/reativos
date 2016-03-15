int LED_PIN = 13;
int BUTTON_VEL_UP_PIN = 2;
int BUTTON_VEL_DOWN_PIN = 3;

int timeOld;
int timeLedWait;
int lastTimeButtonUpPressed, lastTimeButtonDownPressed;
bool ledLocked, buttonUpPressed, buttonDownPressed;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_VEL_UP_PIN, INPUT);
  pinMode(BUTTON_VEL_DOWN_PIN, INPUT);

  timeOld = millis();
  timeLedWait = 1000;
  buttonUpPressed = false;
  buttonDownPressed = false;
  ledLocked = false;
  lastTimeButtonUpPressed = -1;
  lastTimeButtonDownPressed = -1;
}

void loop() {
  int diffButtonsTime;
  int timeNow = millis();

  if (!ledLocked) {
    if (timeNow - timeOld >= timeLedWait){
      timeOld = timeNow;
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    }
  
    if (digitalRead(BUTTON_VEL_UP_PIN)) {
      if (!buttonUpPressed) {
        timeLedWait = timeLedWait / 2;
        buttonUpPressed = true;
      }
      lastTimeButtonUpPressed = millis();
    }
    else {
      buttonUpPressed = false;
    }
    
    if (digitalRead(BUTTON_VEL_DOWN_PIN)) {
      if (!buttonDownPressed) {
        timeLedWait = timeLedWait * 2;
        buttonDownPressed = true;
      }
      lastTimeButtonDownPressed = millis();
    }
    else {
      buttonDownPressed = false;
    }
  
    if (lastTimeButtonUpPressed > 0 && lastTimeButtonDownPressed > 0) {
      diffButtonsTime = lastTimeButtonUpPressed - lastTimeButtonDownPressed;
      if (diffButtonsTime >= -500 && diffButtonsTime <= 500) {
        ledLocked = true;
      }
    }  
  }  
}
