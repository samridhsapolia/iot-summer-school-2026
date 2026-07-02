const int trigPin = 9;
const int echoPin = 10;

const int yellowLED = 6;
const int redLED = 7;
const int buzzer = 8;

unsigned long previousMillis = 0;
bool state = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

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

  unsigned long currentMillis = millis();

  if (distance > 50) {

    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    noTone(buzzer);

    Serial.println("SAFE");
  }

  else if (distance > 20) {

    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);

    if (currentMillis - previousMillis >= 500) {

      previousMillis = currentMillis;

      state = !state;

      if (state)
        tone(buzzer, 1000);
      else
        noTone(buzzer);
    }
  }

  else if (distance > 10) {

    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);

    if (currentMillis - previousMillis >= 200) {

      previousMillis = currentMillis;

      state = !state;

      if (state)
        tone(buzzer, 1000);
      else
        noTone(buzzer);
    }
  }

  else {

    if (currentMillis - previousMillis >= 100) {

      previousMillis = currentMillis;

      state = !state;

      digitalWrite(redLED, state);
      digitalWrite(yellowLED, state);

      tone(buzzer, 1000);
    }
  }

  delay(50);
}
