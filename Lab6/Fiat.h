#ifndef FIAT_H
#define FIAT_H

#include "Car.h"

class Fiat : public Car {
public:
    double fuel_capacity() const override;
    double fuel_consumption() const override;
    double speed(Weather weather) const override;
    const char* name();
};

#endif // FIAT_H