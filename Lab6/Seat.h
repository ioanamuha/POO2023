#ifndef SEAT_H
#define SEAT_H

#include "Car.h"

class Seat : public Car {
public:
    double fuel_capacity() const override;
    double fuel_consumption() const override;
    double speed(Weather weather) const override;
    const char* name();
};

#endif // SEAT_H