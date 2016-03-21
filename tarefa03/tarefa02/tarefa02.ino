#define MAX_BUTTONS 14

int LED_PIN = 13;
int BUTTON_VEL_UP_PIN = 2;
int BUTTON_VEL_DOWN_PIN = 3;

/* Variáveis Globais: */
int buttonsPinRegistred[MAX_BUTTONS];
int buttonsRegistredStates[MAX_BUTTONS];
int counterButtonsRegistred;

int timerMs;
int timeActivatedMs;

int lastTimeButtonVelUpPressed, lastTimeButtonVelDownPressed;
int timeLedToggle;
bool flagStop;

/* Funções de registro: */
void button_listen (int pin) {
  buttonsPinRegistred[counterButtonsRegistred] = pin;
  buttonsRegistredStates[counterButtonsRegistred] = digitalRead(pin);
  counterButtonsRegistred++;
}

void timer_set (int ms) { 
  timeActivatedMs = millis();
  timerMs = ms;
}

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
  Serial.println("TIMER EXPIRED");
  if (!flagStop) {
    Serial.println("LED " + !digitalRead(LED_PIN));
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    timer_set(timeLedToggle);
  }
}

void initialize () {
  Serial.begin(9600);
  flagStop = false;
  timerMs = 0;
  timeLedToggle = 1000;
  lastTimeButtonVelUpPressed = -1500;
  lastTimeButtonVelDownPressed = -500;
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_VEL_UP_PIN, INPUT);
  pinMode(BUTTON_VEL_DOWN_PIN, INPUT);

  button_listen(BUTTON_VEL_UP_PIN);
  button_listen(BUTTON_VEL_DOWN_PIN);
  timer_set(timeLedToggle);
}

/* Programa principal: */
void setup() {
  int i;
  for (i = 0; i < MAX_BUTTONS; i++) {
    buttonsPinRegistred[i] = -1;
    buttonsRegistredStates[i] = -1;
  }
  counterButtonsRegistred = 0;

  timeActivatedMs = -1;

  initialize(); // Função que está no módulo que inclui esta API
}

void loop() {
  int i, currButtonPin, currButtonState, currTime;
  for (i = 0; i < counterButtonsRegistred; i++) {
    currButtonPin = buttonsPinRegistred[i];
    currButtonState = digitalRead(currButtonPin);
    if (currButtonState != buttonsRegistredStates[i]) {
      button_changed(currButtonPin, currButtonState);
      buttonsRegistredStates[i] = currButtonState;
    }
  }

  if (timeActivatedMs >= 0) {
    currTime = millis();
    if (currTime - timeActivatedMs >= timerMs) {
      timerMs = 0;
      timeActivatedMs = -1;
      timer_expired();
    }
  }
}


