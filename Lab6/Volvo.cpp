#include "Volvo.h"
Volvo::Volvo()
{
	fuelCap = 60;
	fuelComp = 1.9;
	avgSpeed = 0;
	name = new char[5];
	(*this).name = (char*)"Volvo";
	finishTime = 0;
}
int Volvo::fuelCapacity()
{
	return (*this).fuelCap;
}
double Volvo::fuelConsumption()
{
	return (*this).fuelComp;
}
double Volvo::averageSpeed(Weather weather)
{
	switch (weather)
	{
	case Weather::Rain:
		avgSpeed = 13;
		break;
	case Weather::Sunny:
		avgSpeed = 34;
		break;
	case Weather::Snow:
		avgSpeed = 9;
		break;
	}
	return (*this).avgSpeed;
}
void Volvo::setFinishTime(int lenght, Weather weather)
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
double Volvo::getFinishTime()
{
	return finishTime;
}
char* Volvo::getName()
{
	return name;
}