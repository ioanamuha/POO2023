#include "RangeRover.h"
RangeRover::RangeRover()
{
	fuelCap = 80;
	fuelComp = 1.8;
	avgSpeed = 0;
	name = new char[10];
	(*this).name = (char*)"RangeRover";
	finishTime = 0;
}
int RangeRover::fuelCapacity()
{
	return (*this).fuelCap;
}
double RangeRover::fuelConsumption()
{
	return (*this).fuelComp;
}
double RangeRover::averageSpeed(Weather weather)
{
	switch (weather)
	{
	case Weather::Rain:
		avgSpeed = 19;
		break;
	case Weather::Sunny:
		avgSpeed = 30;
		break;
	case Weather::Snow:
		avgSpeed = 10;
		break;
	}
	return (*this).avgSpeed;
}
void RangeRover::setFinishTime(int lenght, Weather weather)
{
	if (fuelCapacity() / fuelConsumption() < lenght / 4)
	{
		finishTime = 999;
	}
	else
	{
		finishTime = ((float)lenght / averageSpeed(weather));
	}

}
double RangeRover::getFinishTime()
{
	return finishTime;
}
char* RangeRover::getName()
{
	return name;
}