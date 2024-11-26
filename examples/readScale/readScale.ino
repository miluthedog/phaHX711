#include <phaHX711.h>

const byte doutPin = 2;
const byte sckPin = 3;

phaHX711 hx711;
double weight = ; // input
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
  Serial.print("Result: ");
  Serial.println(result);
  delay(1000);
}
