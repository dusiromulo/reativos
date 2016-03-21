int ledLevelOnePin = 13;
int ledLevelTwoPin = 12;
int ledLevelThreePin = 11;
int ledLevelFourPin = 10;
int ledLevelFivePin = 9;
int ledLevelSixPin = 8;
int ledLevelSevenPin = 7;
int ledLevelEightPin = 6;
int ledLevelNinePin = 5;
int ledLevelTenPin = 4;
int ledLevelElevenPin = 3;

int temperaturePin = 0;

void setup() {
  pinMode(ledLevelOnePin, OUTPUT);
  pinMode(ledLevelTwoPin, OUTPUT);
  pinMode(ledLevelThreePin, OUTPUT);
  pinMode(ledLevelFourPin, OUTPUT);
  pinMode(ledLevelFivePin, OUTPUT);
  pinMode(ledLevelSixPin, OUTPUT);
  pinMode(ledLevelSevenPin, OUTPUT);
  pinMode(ledLevelEightPin, OUTPUT);
  pinMode(ledLevelNinePin, OUTPUT);
  pinMode(ledLevelTenPin, OUTPUT);
  pinMode(ledLevelElevenPin, OUTPUT);
}

void loop() {
  int temperature = analogRead(temperaturePin);

  switch (temperature / 30) {
    case 0:
      digitalWrite(ledLevelOnePin, LOW);
      digitalWrite(ledLevelTwoPin, LOW);
      digitalWrite(ledLevelThreePin, LOW);
      digitalWrite(ledLevelFourPin, LOW);
      digitalWrite(ledLevelFivePin, LOW);
      digitalWrite(ledLevelSixPin, LOW);
      digitalWrite(ledLevelSevenPin, LOW);
      digitalWrite(ledLevelEightPin, LOW);
      digitalWrite(ledLevelNinePin, LOW);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
    case 1:
      digitalWrite(ledLevelOnePin, HIGH);
      digitalWrite(ledLevelTwoPin, LOW);
      digitalWrite(ledLevelThreePin, LOW);
      digitalWrite(ledLevelFourPin, LOW);
      digitalWrite(ledLevelFivePin, LOW);
      digitalWrite(ledLevelSixPin, LOW);
      digitalWrite(ledLevelSevenPin, LOW);
      digitalWrite(ledLevelEightPin, LOW);
      digitalWrite(ledLevelNinePin, LOW);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
    case 2:
      digitalWrite(ledLevelOnePin, HIGH);
      digitalWrite(ledLevelTwoPin, HIGH);
      digitalWrite(ledLevelThreePin, LOW);
      digitalWrite(ledLevelFourPin, LOW);
      digitalWrite(ledLevelFivePin, LOW);
      digitalWrite(ledLevelSixPin, LOW);
      digitalWrite(ledLevelSevenPin, LOW);
      digitalWrite(ledLevelEightPin, LOW);
      digitalWrite(ledLevelNinePin, LOW);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
    case 3:
      digitalWrite(ledLevelOnePin, HIGH);
      digitalWrite(ledLevelTwoPin, HIGH);
      digitalWrite(ledLevelThreePin, HIGH);
      digitalWrite(ledLevelFourPin, LOW);
      digitalWrite(ledLevelFivePin, LOW);
      digitalWrite(ledLevelSixPin, LOW);
      digitalWrite(ledLevelSevenPin, LOW);
      digitalWrite(ledLevelEightPin, LOW);
      digitalWrite(ledLevelNinePin, LOW);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
    case 4:
      digitalWrite(ledLevelOnePin, HIGH);
      digitalWrite(ledLevelTwoPin, HIGH);
      digitalWrite(ledLevelThreePin, HIGH);
      digitalWrite(ledLevelFourPin, HIGH);
      digitalWrite(ledLevelFivePin, LOW);
      digitalWrite(ledLevelSixPin, LOW);
      digitalWrite(ledLevelSevenPin, LOW);
      digitalWrite(ledLevelEightPin, LOW);
      digitalWrite(ledLevelNinePin, LOW);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
    case 5:
      digitalWrite(ledLevelOnePin, HIGH);
      digitalWrite(ledLevelTwoPin, HIGH);
      digitalWrite(ledLevelThreePin, HIGH);
      digitalWrite(ledLevelFourPin, HIGH);
      digitalWrite(ledLevelFivePin, HIGH);
      digitalWrite(ledLevelSixPin, LOW);
      digitalWrite(ledLevelSevenPin, LOW);
      digitalWrite(ledLevelEightPin, LOW);
      digitalWrite(ledLevelNinePin, LOW);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
    case 6:
      digitalWrite(ledLevelOnePin, HIGH);
      digitalWrite(ledLevelTwoPin, HIGH);
      digitalWrite(ledLevelThreePin, HIGH);
      digitalWrite(ledLevelFourPin, HIGH);
      digitalWrite(ledLevelFivePin, HIGH);
      digitalWrite(ledLevelSixPin, HIGH);
      digitalWrite(ledLevelSevenPin, LOW);
      digitalWrite(ledLevelEightPin, LOW);
      digitalWrite(ledLevelNinePin, LOW);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
    case 7:
      digitalWrite(ledLevelOnePin, HIGH);
      digitalWrite(ledLevelTwoPin, HIGH);
      digitalWrite(ledLevelThreePin, HIGH);
      digitalWrite(ledLevelFourPin, HIGH);
      digitalWrite(ledLevelFivePin, HIGH);
      digitalWrite(ledLevelSixPin, HIGH);
      digitalWrite(ledLevelSevenPin, HIGH);
      digitalWrite(ledLevelEightPin, LOW);
      digitalWrite(ledLevelNinePin, LOW);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
    case 8:
      digitalWrite(ledLevelOnePin, HIGH);
      digitalWrite(ledLevelTwoPin, HIGH);
      digitalWrite(ledLevelThreePin, HIGH);
      digitalWrite(ledLevelFourPin, HIGH);
      digitalWrite(ledLevelFivePin, HIGH);
      digitalWrite(ledLevelSixPin, HIGH);
      digitalWrite(ledLevelSevenPin, HIGH);
      digitalWrite(ledLevelEightPin, HIGH);
      digitalWrite(ledLevelNinePin, LOW);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
    case 9:
      digitalWrite(ledLevelOnePin, HIGH);
      digitalWrite(ledLevelTwoPin, HIGH);
      digitalWrite(ledLevelThreePin, HIGH);
      digitalWrite(ledLevelFourPin, HIGH);
      digitalWrite(ledLevelFivePin, HIGH);
      digitalWrite(ledLevelSixPin, HIGH);
      digitalWrite(ledLevelSevenPin, HIGH);
      digitalWrite(ledLevelEightPin, HIGH);
      digitalWrite(ledLevelNinePin, HIGH);
      digitalWrite(ledLevelTenPin, LOW);
      digitalWrite(ledLevelElevenPin, LOW);
      break;
  }
}
