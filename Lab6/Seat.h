#pragma once
#include "Car.h"
class Seat :
    public Car
{
private:
    int fuelCap;
    double fuelComp;
    double avgSpeed;
    char* name;
    double finishTime;
public:
    Seat();
    ~Seat();
    int fuelCapacity();
    double fuelConsumption();
    double averageSpeed(Weather weather);
    void setFinishTime(int lenght, Weather weather);
    double getFinishTime();
    char* getName();
};

