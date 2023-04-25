#ifndef CIRCUIT_H
#define CIRCUIT_H

//#include <vector>
#include <iostream>
#include "Car.h"
#include "Weather.h"

class Circuit {
public:
    Circuit();
    ~Circuit();
    void SetLength(double length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks() /*const*/;
    void ShowWhoDidNotFinish() const;

private:
    double length_;
    int nrCars = 0;
    int allocated=50;
    int grow = 50;
    Weather weather_;
    Car** cars;
    double *times;
};

#endif // CIRCUIT_H