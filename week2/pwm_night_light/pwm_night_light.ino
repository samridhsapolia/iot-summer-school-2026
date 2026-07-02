const int led = 9;
const int button = 2;

int mode = 0;
bool lastButtonState = HIGH;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Mode 1: Slow Breathing");
}

void loop() {

  bool currentButton = digitalRead(button);

  if (lastButtonState == HIGH && currentButton == LOW) {

    mode++;

    if (mode > 2)
      mode = 0;

    if (mode == 0)
      Serial.println("Mode 1: Slow Breathing");

    if (mode == 1)
      Serial.println("Mode 2: Fast Pulse");

    if (mode == 2)
      Serial.println("Mode 3: SOS");

    delay(250);
  }

  lastButtonState = currentButton;

  if (mode == 0)
    slowBreathing();

  else if (mode == 1)
    fastPulse();

  else
    sosPattern();
}

void slowBreathing() {

  for (int i = 0; i <= 255; i++) {
    analogWrite(led, i);
    delay(6);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(led, i);
    delay(6);
  }
}

void fastPulse() {

  analogWrite(led, 255);
  delay(250);

  analogWrite(led, 0);
  delay(250);
}

void sosPattern() {

  for (int i = 0; i < 3; i++) {
    analogWrite(led, 255);
    delay(200);
    analogWrite(led, 0);
    delay(200);
  }

  for (int i = 0; i < 3; i++) {
    analogWrite(led, 255);
    delay(600);
    analogWrite(led, 0);
    delay(200);
  }

  for (int i = 0; i < 3; i++) {
    analogWrite(led, 255);
    delay(200);
    analogWrite(led, 0);
    delay(200);
  }

  delay(1000);
}
