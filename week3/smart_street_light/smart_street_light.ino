const int ldrPin = A0;
const int pirPin = 2;
const int ledPin = 9;

const int threshold = 500;

bool isNight = false;
bool motionActive = false;

unsigned long motionStart = 0;

bool lastDayState = false;
bool lastMotionState = false;

void printTime() {
  unsigned long totalSeconds = millis() / 1000;

  int hh = totalSeconds / 3600;
  int mm = (totalSeconds % 3600) / 60;
  int ss = totalSeconds % 60;

  if (hh < 10) Serial.print("0");
  Serial.print(hh);
  Serial.print(":");

  if (mm < 10) Serial.print("0");
  Serial.print(mm);
  Serial.print(":");

  if (ss < 10) Serial.print("0");
  Serial.print(ss);
}

void logEvent(String msg) {
  Serial.print("[");
  printTime();
  Serial.print("] EVENT: ");
  Serial.println(msg);
}

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

  Serial.begin(9600);
}

void loop() {

  int light = analogRead(ldrPin);

  isNight = (light < threshold);

  // DAY MODE
  if (!isNight) {

    analogWrite(ledPin, 0);

    if (!lastDayState) {
      logEvent("Daylight detected - Street Light OFF");
      lastDayState = true;
    }

    motionActive = false;
    lastMotionState = false;

    return;
  }

  lastDayState = false;

  bool motion = digitalRead(pirPin);

  // Motion detected only once
  if (motion && !lastMotionState) {

    motionStart = millis();
    motionActive = true;

    logEvent("Motion Detected - LED FULL BRIGHTNESS");
  }

  lastMotionState = motion;

  if (motionActive) {

    if (millis() - motionStart < 30000) {

      analogWrite(ledPin, 255);

    } else {

      analogWrite(ledPin, 51);

      logEvent("No Motion - LED DIM (20%)");

      motionActive = false;
    }

  } else {

    analogWrite(ledPin, 51);

  }

}
