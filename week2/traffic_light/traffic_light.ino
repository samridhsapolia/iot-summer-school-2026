/*
  Traffic Light Controller with Pedestrian Button
  Uses INPUT_PULLUP (No external resistor)
*/

const int RED = 13;
const int YELLOW = 12;
const int GREEN = 11;
const int BUTTON = 7;

void printState(String state)
{
  Serial.print("[");
  Serial.print(millis());
  Serial.print(" ms] ");
  Serial.println(state);
}

void pedestrianCrossing()
{
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  printState("PEDESTRIAN CROSSING");

  delay(8000);
}

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);   // <-- Internal pull-up

  Serial.begin(9600);
}

void loop()
{
  // RED
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  printState("RED");

  for (int i = 0; i < 50; i++)
  {
    if (digitalRead(BUTTON) == LOW)
    {
      pedestrianCrossing();
      return;
    }
    delay(100);
  }

  // YELLOW
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);

  printState("YELLOW");

  for (int i = 0; i < 20; i++)
  {
    if (digitalRead(BUTTON) == LOW)
    {
      pedestrianCrossing();
      return;
    }
    delay(100);
  }

  // GREEN
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);

  printState("GREEN");

  for (int i = 0; i < 40; i++)
  {
    if (digitalRead(BUTTON) == LOW)
    {
      pedestrianCrossing();
      return;
    }
    delay(100);
  }
}
