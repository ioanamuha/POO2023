#pragma once
#include "Weather.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Car
{
protected:
	int fuelCap;
	double fuelComp;
	double avgSpeed;
	char* name;
	double finishTime;

public: 
	virtual int fuelCapacity() = 0;
	virtual double fuelConsumption() = 0;
	virtual double averageSpeed(Weather weather) = 0;
	virtual void setFinishTime(int lenght, Weather weather) = 0;
	virtual  double getFinishTime() = 0;
	virtual char* getName() = 0;
};

