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
    phaHX711();
    virtual ~phaHX711();

    bool setPin();
    long read();
    
    long calAvg();
    void tare();
    void factor(double weight);
    long scale();
};

#endif