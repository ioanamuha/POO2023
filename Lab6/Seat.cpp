#include "Seat.h"
Seat::Seat()
{
	fuelCap = 70;
	fuelComp = 2;
	avgSpeed = 0;
	name = new char[4];
	(*this).name = (char*)"Seat";
	finishTime = 0;
}
int Seat::fuelCapacity()
{
	return (*this).fuelCap;
}
double Seat::fuelConsumption()
{
	return (*this).fuelComp;
}
double Seat::averageSpeed(Weather weather)
{
	switch (weather)
	{
	case Weather::Rain:
		avgSpeed = 10;
		break;
	case Weather::Sunny:
		avgSpeed = 35;
		break;
	case Weather::Snow:
		avgSpeed = 8;
		break;
	}
	return (*this).avgSpeed;
}
void Seat::setFinishTime(int lenght, Weather weather)
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
double Seat::getFinishTime()
{
	return finishTime;
}
char* Seat::getName()
{
	return name;
}