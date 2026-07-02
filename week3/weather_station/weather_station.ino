#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define RED_LED 8
#define GREEN_LED 9

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);

  dht.begin();

  Serial.println("timestamp,temp_C,temp_F,humidity");
}

void loop() {

  float tempC = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(tempC) || isnan(humidity)) {
    Serial.println("Sensor Error");
    delay(2000);
    return;
  }

  float tempF = tempC * 9.0 / 5.0 + 32.0;

  // CSV Output
  Serial.print(millis());
  Serial.print(",");

  Serial.print(tempC);
  Serial.print(",");

  Serial.print(tempF);
  Serial.print(",");

  Serial.println(humidity);

  // LED Conditions
  if (tempC > 35 || humidity > 80) {

    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

  }
  else {

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

  }

  delay(2000);

}
