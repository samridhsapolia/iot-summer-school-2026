const int enablePin = 9;   // PWM
const int in1 = 8;
const int in2 = 7;

const int potPin = A0;

const int dirButton = 2;
const int startButton = 3;

bool direction = true;      // true = Forward
bool motorRunning = true;

bool lastDirState = HIGH;
bool lastStartState = HIGH;

void setup() {

  pinMode(enablePin, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(dirButton, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  // Read potentiometer
  int potValue = analogRead(potPin);

  int pwmValue = map(potValue, 0, 1023, 0, 255);

  int speedPercent = map(potValue, 0, 1023, 0, 100);

  // Direction Button
  bool dirState = digitalRead(dirButton);

  if (lastDirState == HIGH && dirState == LOW) {

    direction = !direction;

    delay(200);
  }

  lastDirState = dirState;

  // Start/Stop Button
  bool startState = digitalRead(startButton);

  if (lastStartState == HIGH && startState == LOW) {

    motorRunning = !motorRunning;

    delay(200);
  }

  lastStartState = startState;

  if (motorRunning) {

    analogWrite(enablePin, pwmValue);

    if (direction) {

      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

    } else {

      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

    }

  } else {

    analogWrite(enablePin, 0);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

  }

  Serial.print("Direction: ");

  if (direction)
    Serial.print("Forward");
  else
    Serial.print("Reverse");

  Serial.print(" | Speed: ");

  Serial.print(speedPercent);

  Serial.print("% | State: ");

  if (motorRunning)
    Serial.println("Running");
  else
    Serial.println("Stopped");

  delay(500);
}
