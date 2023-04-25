#ifndef VOLVO_H
#define VOLVO_H

#include "Car.h"

class Volvo : public Car {
public:
    double fuel_capacity() const override;
    double fuel_consumption() const override;
    double speed(Weather weather) const override;
    const char* name();
};

#endif // VOLVO_H