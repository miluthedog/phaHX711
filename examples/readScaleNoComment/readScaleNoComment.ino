// no comment version for Python stuff
#include <phaHX711.h>

const byte doutPin = 2;
const byte sckPin = 3;
double weight = 100;

phaHX711 hx711;
long result;

void setup() {
  Serial.begin(9600);
  hx711.setPin(doutPin, sckPin);

  Serial.println("Remove weight");
  delay(1000);
  hx711.tare();
  Serial.println("Put weight");
  delay(1000);
  hx711.factor(weight);
}

void loop() {
  result = hx711.scale();
  Serial.println(result);
  delay(1000);
}
