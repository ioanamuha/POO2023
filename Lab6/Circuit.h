#pragma once
#include "Car.h"
#include "BMW.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Seat.h"
#include "Volvo.h"

class Circuit 
{
private:
    int lenght;
    Weather weather;
    Car** cars;
    int carIndex;
public:
    Circuit();
    ~Circuit();
    void SetLength(int lenght);
    void SetWeather(Weather weather);
   Weather GetWeather();
    void AddCar(Car *car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

