// Q15 - Digital Piano using Buzzer
// Arduino UNO

const int BUZZER = 8;

const int BTN_DO   = 2;
const int BTN_RE   = 3;
const int BTN_MI   = 4;
const int BTN_FA   = 5;
const int BTN_MODE = 6;

// Major scale
int majorNotes[4] = {262, 294, 330, 349};

// Minor scale
int minorNotes[4] = {262, 294, 311, 349};

bool majorMode = true;
bool lastModeState = HIGH;

void setup() {
  pinMode(BTN_DO, INPUT_PULLUP);
  pinMode(BTN_RE, INPUT_PULLUP);
  pinMode(BTN_MI, INPUT_PULLUP);
  pinMode(BTN_FA, INPUT_PULLUP);
  pinMode(BTN_MODE, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);

  Serial.println("Digital Piano Started");
  Serial.println("Current Mode: Major");
}

void loop() {

  // ---------- Mode Toggle ----------
  bool modeState = digitalRead(BTN_MODE);

  if (lastModeState == HIGH && modeState == LOW) {
    majorMode = !majorMode;

    if (majorMode)
      Serial.println("Mode Changed: Major");
    else
      Serial.println("Mode Changed: Minor");

    delay(250);   // debounce
  }

  lastModeState = modeState;

  // ---------- Count Pressed Buttons ----------
  int pressed = 0;

  if (digitalRead(BTN_DO) == LOW) pressed++;
  if (digitalRead(BTN_RE) == LOW) pressed++;
  if (digitalRead(BTN_MI) == LOW) pressed++;
  if (digitalRead(BTN_FA) == LOW) pressed++;

// Play Sol note when two buttons are pressed together
  if (pressed >= 2) {
    tone(BUZZER, 392);
  }

  // ---------- Single Notes ----------
  else if (digitalRead(BTN_DO) == LOW) {

    if (majorMode)
      tone(BUZZER, majorNotes[0]);
    else
      tone(BUZZER, minorNotes[0]);

  }

  else if (digitalRead(BTN_RE) == LOW) {

    if (majorMode)
      tone(BUZZER, majorNotes[1]);
    else
      tone(BUZZER, minorNotes[1]);

  }

  else if (digitalRead(BTN_MI) == LOW) {

    if (majorMode)
      tone(BUZZER, majorNotes[2]);
    else
      tone(BUZZER, minorNotes[2]);

  }

  else if (digitalRead(BTN_FA) == LOW) {

    if (majorMode)
      tone(BUZZER, majorNotes[3]);
    else
      tone(BUZZER, minorNotes[3]);

  }

  // ---------- No Button ----------
  else {
    noTone(BUZZER);
  }
}
