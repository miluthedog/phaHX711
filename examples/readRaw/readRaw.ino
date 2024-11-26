#include <phaHX711.h>

const byte doutPin = 2;
const byte sckPin = 3;

phaHX711 hx711;
long result;

void setup() {
  Serial.begin(9600);
  hx711.setup(doutPin, sckPin);
}

void loop() {
  result = hx711.read();
  Serial.println(result);
  delay(1000);
}
