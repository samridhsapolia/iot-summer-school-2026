#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int buttonPin = 2;

bool lastButtonState = HIGH;

void setup() {

  myServo.attach(9);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  // Read potentiometer
  int potValue = analogRead(potPin);

  // Convert to angle
  int angle = map(potValue, 0, 1023, 0, 180);

  // Move servo
  myServo.write(angle);

  // Print angle
  Serial.print("Servo Angle: ");
  Serial.print(angle);
  Serial.println("°");

  bool currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {

    Serial.println("Automatic Sweep Started");

    // 0 → 180
    for (int i = 0; i <= 180; i++) {

      myServo.write(i);
      delay(10);
    }

    // 180 → 0
    for (int i = 180; i >= 0; i--) {

      myServo.write(i);
      delay(10);
    }

    Serial.println("Sweep Completed");
  }

  lastButtonState = currentButtonState;

  delay(100);
}
