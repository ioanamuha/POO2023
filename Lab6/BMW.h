#ifndef BMW_H
#define BMW_H

#include "Car.h"

class BMW : public Car {
public:
    double fuel_capacity() const override;
    double fuel_consumption() const override;
    double speed(Weather weather) const override;
    const char* name();
};

#endif // BMW