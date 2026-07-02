const int trigPin = 9;
const int echoPin = 10;

const int yellowLED = 6;
const int redLED = 7;
const int buzzer = 8;

unsigned long sensorTimer = 0;
unsigned long blinkTimer = 0;

bool blinkState = false;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  unsigned long currentMillis = millis();

  // Read sensor every 50 ms
  if (currentMillis - sensorTimer >= 50) {

    sensorTimer = currentMillis;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    float distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // SAFE
    if (distance > 50) {

      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);

      noTone(buzzer);

      Serial.println("SAFE");
    }

    // 20–50 cm
    else if (distance > 20) {

      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, HIGH);

      if (currentMillis - blinkTimer >= 500) {

        blinkTimer = currentMillis;

        blinkState = !blinkState;

        if (blinkState)
          tone(buzzer, 1000);
        else
          noTone(buzzer);
      }
    }

    // 10–20 cm
    else if (distance > 10) {

      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);

      if (currentMillis - blinkTimer >= 200) {

        blinkTimer = currentMillis;

        blinkState = !blinkState;

        if (blinkState)
          tone(buzzer, 1000);
        else
          noTone(buzzer);
      }
    }

    // Less than 10 cm
    else {

      if (currentMillis - blinkTimer >= 100) {

        blinkTimer = currentMillis;

        blinkState = !blinkState;

        digitalWrite(redLED, blinkState);
        digitalWrite(yellowLED, blinkState);

        tone(buzzer, 1000);
      }
    }
  }
}
