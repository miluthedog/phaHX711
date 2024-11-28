#ifndef phaHX711_h
#define phaHX711_h
#include "Arduino.h"

class phaHX711
{
  private:
    static const byte loopTimes = 100;

    byte serialClock;
    byte dataOut;
    long tareValue = 0;
    double factorValue = 1;

  public:
    phaHX711(byte doutPin, byte sckPin);
    virtual ~phaHX711();

    bool setPin();
    long read();
    
    long calAvg();
    void tare();
    double factor(double weight);
    double scale();
};

#endif