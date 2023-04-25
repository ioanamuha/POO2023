#ifndef RANGEROVER_H
#define RANGEROVER_H

#include "Car.h"

class RangeRover : public Car {
public:
    double fuel_capacity() const override;
    double fuel_consumption() const override;
    double speed(Weather weather) const override;
    const char* name();
};

#endif // RANGEROVER_H