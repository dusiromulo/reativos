#define MAX_BUTTONS 14

/* Variáveis Globais: */
int buttonsPinRegistred[MAX_BUTTONS];
int buttonsRegistredStates[MAX_BUTTONS];
int counterButtonsRegistred;

int timerMs;
int timeActivatedMs;

int BUTTON_PIN = 2;
int LED_PIN = 13;

void button_changed(int pin, int v) {
  digitalWrite(LED_PIN, v);
}

void timer_expired() {}

void initialize() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
  button_listen(BUTTON_PIN);
}

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
  int i, currButtonPin, currButtonState;
  for (i = 0; i < counterButtonsRegistred; i++) {
    currButtonPin = buttonsPinRegistred[i];
    currButtonState = digitalRead(currButtonPin);
    if (currButtonState != buttonsRegistredStates[i]) {
      button_changed(currButtonPin, currButtonState);
      buttonsRegistredStates[i] = currButtonState;
    }
  }

  if (timeActivatedMs > 0) {
    if (millis() - timeActivatedMs >= timerMs) {
      timer_expired();
      timerMs = 0;
      timeActivatedMs = -1;
    }
  }
}

