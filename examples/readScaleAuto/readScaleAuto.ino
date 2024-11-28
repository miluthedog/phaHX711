#include <phaHX711.h>

const byte doutPin = 2;
const byte sckPin = 3;
double factor = 100; // factor number

phaHX711 hx711(doutPin, sckPin);
double result;

void setup() {
  Serial.begin(9600);
  hx711.setPin();

  Serial.println("Remove weight");
  delay(2000);
  hx711.tare();
}

void loop() {
  result = hx711.autoScale(factor);
  Serial.print("Result: ");
  Serial.print(result);
  Serial.println(" g");
  delay(1000);
}
