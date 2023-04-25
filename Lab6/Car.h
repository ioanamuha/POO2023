#ifndef CAR_H
#define CAR_H

#include "Weather.h"

class Car {
public:
    virtual double fuel_capacity() const = 0;
    virtual double fuel_consumption() const = 0;
    virtual double speed(Weather weather) const = 0;
    virtual const char* name() = 0;
};

#endif // CAR_H