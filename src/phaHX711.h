#ifndef phaHX711_h
#define phaHX711_h
#include "Arduino.h"

class phaHX711
{
  private:
    static const byte loopTimes = 100;

    byte serialClock;
    byte dataOut;
    long manualTare = 0;
    double manualFactor = 1;

  public:
    phaHX711(byte doutPin, byte sckPin);
    virtual ~phaHX711();

    bool setPin();
    long read();
    
    long calAvg();
    void tare();
    double factor(double weight);
    double autoScale(double factor);
    double manualScale();
};

#endif