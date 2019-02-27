#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "Arduino.h"

class Potentiometer {
private:
    const uint8_t pin;
    const byte control, channel;
    int value = -1;

public:
    Potentiometer(int pin, byte control, byte channel);

    /* Return true only if the value changed */
    bool read();
    int get_value() const;
};

#endif