#include <phaHX711.h>

const byte doutPin = 2;
const byte sckPin = 3;

phaHX711 hx711(doutPin, sckPin);
double result;

void setup() {
  Serial.begin(9600);
  hx711.setPin();
}

void loop() {
  result = hx711.read();
  Serial.println(result);
  delay(1000);
}
