#include <phaHX711.h>

const byte doutPin = 2;
const byte sckPin = 3;
double weight = 100; // gram

phaHX711 hx711(doutPin, sckPin);
double factor;
double result;

void setup() {
  Serial.begin(9600);
  hx711.setPin();

  Serial.println("Remove weight");
  delay(1000);
  hx711.tare();
  Serial.println("Put weight");
  delay(1000);
  factor = hx711.factor(weight);
  Serial.println(factor);
}

void loop() {
  result = hx711.scale();
  Serial.print("Result: ");
  Serial.print(result);
  Serial.println(" g");
  delay(1000);
}
