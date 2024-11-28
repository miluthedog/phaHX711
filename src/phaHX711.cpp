#include <Arduino.h>
#include "phaHX711.h"

// constructor - destructor
phaHX711::phaHX711(byte doutPin, byte sckPin) {
  serialClock  = sckPin;
  dataOut  = doutPin;
}

phaHX711::~phaHX711() {
}

// set up
bool phaHX711::setPin() {
  pinMode(serialClock, OUTPUT);
  pinMode(dataOut, INPUT);

  return digitalRead(dataOut) == LOW;
}

// read data
long phaHX711::read() {
  while (!setPin());

  byte data[3];

  for (byte j = 3; j--;) {
      data[j] = shiftIn(dataOut,serialClock, MSBFIRST); // MostSignificantBit
  }

  digitalWrite(serialClock, HIGH);
  digitalWrite(serialClock, LOW);

  data[2] ^= 0x80;
  return ((uint32_t) data[2] << 16) | ((uint32_t) data[1] << 8) | (uint32_t) data[0];
}

// calculate values
long phaHX711::calAvg() {
  long sum = 0;

	for (byte i = 0; i < loopTimes; i++) {
		sum += read();
	}
  return sum/loopTimes;
}

void phaHX711::tare() {
  tareValue = calAvg();
}

double phaHX711::factor(double weight) {
  factorValue = (calAvg() - tareValue) / weight;
  return factorValue;
}

// output
double phaHX711::scale() {
  return (read() - tareValue) / factorValue;
}

