/*
State Transition Diagram

IDLE
 |
 | Insert Coin
 v
COIN_INSERTED
 |
 | Select Item
 v
ITEM_SELECTED
 |
 | Dispense
 v
DISPENSING
 |
 | Complete
 v
IDLE

Cancel button:
COIN_INSERTED -> IDLE
ITEM_SELECTED -> IDLE
*/

const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;

const int coinBtn = 2;
const int selectBtn = 3;
const int cancelBtn = 4;

enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

void setup() {

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  Serial.begin(9600);

  showState();
}

void loop() {

  if (digitalRead(cancelBtn) == LOW &&
      currentState != IDLE) {

    currentState = IDLE;
    Serial.println("Cancelled -> IDLE");
    showState();
    delay(300);
  }

  switch(currentState){

    case IDLE:

      if(digitalRead(coinBtn)==LOW){

        currentState=COIN_INSERTED;
        Serial.println("IDLE -> COIN_INSERTED");
        showState();
        delay(300);
      }

    break;

    case COIN_INSERTED:

      if(digitalRead(selectBtn)==LOW){

        currentState=ITEM_SELECTED;
        Serial.println("COIN_INSERTED -> ITEM_SELECTED");
        showState();
        delay(300);
      }

    break;

    case ITEM_SELECTED:

      currentState=DISPENSING;
      Serial.println("ITEM_SELECTED -> DISPENSING");
      showState();

      delay(2000);

      currentState=IDLE;
      Serial.println("DISPENSING -> IDLE");
      showState();

    break;

    case DISPENSING:

    break;
  }

}

void showState(){

  digitalWrite(redLED,LOW);
  digitalWrite(yellowLED,LOW);
  digitalWrite(greenLED,LOW);

  switch(currentState){

    case IDLE:
      digitalWrite(redLED,HIGH);
      break;

    case COIN_INSERTED:
      digitalWrite(yellowLED,HIGH);
      break;

    case ITEM_SELECTED:
      digitalWrite(greenLED,HIGH);
      break;

    case DISPENSING:
      digitalWrite(redLED,HIGH);
      digitalWrite(yellowLED,HIGH);
      digitalWrite(greenLED,HIGH);
      break;
  }

}
