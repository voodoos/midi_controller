#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "Arduino.h"

class Potentiometer {
private:
    const uint8_t pin;
    const uint8_t control, channel;
    uint8_t value = -1;

public:
    Potentiometer(uint8_t pin, uint8_t control, uint8_t channel);

    /* Return true only if the value changed */
    bool read();
    uint8_t get_value() const;
    void send() const;
};

#endif