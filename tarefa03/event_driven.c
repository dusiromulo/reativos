#include <Arduino.h>

#define MAX_BUTTONS 14


/* Variáveis Globais: */
int buttonsPinRegistred[MAX_BUTTONS];
int buttonsRegistredStates[MAX_BUTTONS];
int counterButtonsRegistred;

int timerMs;
int timeActivatedMs;

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

/* Callbacks: */
void button_changed (int pin, int v);
void timer_expired (void);

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