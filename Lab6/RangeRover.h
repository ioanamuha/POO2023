#pragma once
#include "Car.h"
class RangeRover :
    public Car
{
private:
    int fuelCap;
    double fuelComp;
    double avgSpeed;
    char* name;
    double finishTime;
public:
    RangeRover();
    ~RangeRover();
    int fuelCapacity();
    double fuelConsumption();
    double averageSpeed(Weather weather);
    void setFinishTime(int lenght, Weather weather);
    double getFinishTime();
    char* getName();
};

