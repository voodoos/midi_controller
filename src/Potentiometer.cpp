#include "Potentiometer.h"

Potentiometer::Potentiometer(uint8_t p, uint8_t co, uint8_t ch) :
   pin { p }, control (co), channel ( ch ) {}

bool Potentiometer::read() {
    int new_value = analogRead(pin);

    if(abs(new_value - value) > 4) {
        value = new_value;
        return true;
    }

    return false;
}

uint8_t Potentiometer::get_value() const {
    return value;
}

void Potentiometer::send() const {
    usbMIDI.sendControlChange(control, value, channel);
}