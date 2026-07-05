#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define RELAY_PIN 8
#define BUTTON_PIN 3

DHT dht(DHTPIN, DHTTYPE);

bool manualOverride = false;
bool relayState = false;
bool lastButtonState = HIGH;

void setup() {

  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  dht.begin();

  // Relay OFF (Active LOW relay)
  digitalWrite(RELAY_PIN, HIGH);

  Serial.println("Relay Controlled AC Simulation");
}

void loop() {

  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Sensor Error");
    delay(1000);
    return;
  }

  // Manual Override Button
  bool buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {

    manualOverride = !manualOverride;

    Serial.print("Manual Override: ");
    Serial.println(manualOverride ? "ON" : "OFF");

    delay(200);
  }

  lastButtonState = buttonState;

  // Automatic Control
  if (!manualOverride) {

    if (temp > 32.0)
      relayState = true;

    if (temp < 28.0)
      relayState = false;
  }

  // Active LOW Relay
  if (relayState)
    digitalWrite(RELAY_PIN, LOW);    // Relay ON
  else
    digitalWrite(RELAY_PIN, HIGH);   // Relay OFF

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C | Relay: ");

  if (relayState)
    Serial.print("ON");
  else
    Serial.print("OFF");

  Serial.print(" | Mode: ");

  if (manualOverride)
    Serial.println("Manual");
  else
    Serial.println("Auto");

  delay(1000);
}
