#include "Fiat.h"
Fiat::Fiat()
{
	fuelCap = 65;
	fuelComp = 1.3;
	avgSpeed = 0;
	name = new char[4];
	(*this).name = (char*)"Fiat";
	finishTime = 0;
}
int Fiat::fuelCapacity()
{
	return (*this).fuelCap;
}
double Fiat::fuelConsumption()
{
	return (*this).fuelComp;
}
double Fiat::averageSpeed(Weather weather)
{
	switch (weather)
	{
	case Weather::Rain:
		avgSpeed = 12;
		break;
	case Weather::Sunny:
		avgSpeed = 28;
		break;
	case Weather::Snow:
		avgSpeed = 9;
		break;
	}
	return (*this).avgSpeed;
}
void Fiat::setFinishTime(int lenght, Weather weather)
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
double Fiat::getFinishTime()
{
	return finishTime;
}
char* Fiat::getName()
{
	return name;
}