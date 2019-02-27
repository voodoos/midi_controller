#include "Potentiometer.h"

Potentiometer::Potentiometer(int p, byte co, byte ch) :
   pin { p }, control (co), channel ( ch ) {}

bool Potentiometer::read() {
    int new_value = analogRead(pin);

    if(abs(new_value - value) > 4) {
        value = new_value;
        return true;
    }

    return false;
}

int Potentiometer::get_value() const {
    return value;
}