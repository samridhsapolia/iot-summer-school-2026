#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------- Keypad --------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// -------- LEDs & Buzzer --------
const int greenLED = 10;
const int redLED   = 11;
const int buzzer   = 12;

// -------- Password --------
String password = "1234";
String entered = "";

int wrongAttempts = 0;
bool locked = false;
unsigned long lockStart = 0;

void setup() {

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("ENTER PIN:");
}

void loop() {

  // ----- Lock Mode -----
  if (locked) {

    if (millis() - lockStart >= 10000) {

      locked = false;
      wrongAttempts = 0;

      lcd.clear();
      lcd.print("ENTER PIN:");
    }

    return;
  }

  char key = keypad.getKey();

  if (key) {

    if (entered.length() < 4) {

      entered += key;

      lcd.setCursor(0,1);

      for (int i = 0; i < entered.length(); i++)
        lcd.print("*");

    }

    if (entered.length() == 4) {

      if (entered == password) {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("GRANTED");

        digitalWrite(greenLED, HIGH);

        tone(buzzer, 1000, 300);

        delay(2000);

        digitalWrite(greenLED, LOW);

        wrongAttempts = 0;

      }

      else {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("DENIED");

        digitalWrite(redLED, HIGH);

        tone(buzzer, 500, 1000);

        delay(2000);

        digitalWrite(redLED, LOW);

        wrongAttempts++;

        if (wrongAttempts >= 3) {

          lcd.clear();
          lcd.print("LOCKED");
          lcd.setCursor(0,1);
          lcd.print("10 Seconds");

          locked = true;
          lockStart = millis();

        }

      }

      entered = "";

      if (!locked) {

        lcd.clear();
        lcd.print("ENTER PIN:");

      }

    }

  }

}
