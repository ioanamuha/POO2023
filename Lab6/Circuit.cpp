#include "Circuit.h"

Circuit::Circuit()
{
	lenght = 0;
	weather = Sunny;
	cars= new Car*[10];
	carIndex = 0;
}
Circuit::~Circuit()
{
	lenght = 0;
	weather = Sunny;
	for (int i = 0; i < carIndex; i++)
	{
		delete cars[i];
	}
	delete[] cars;
	carIndex = 0;
}
void Circuit::SetLength(int lenght)
{
	(*this).lenght = lenght;
}
void Circuit::SetWeather(Weather weather)
{
	(*this).weather = weather;
}Weather Circuit::GetWeather()
{
	return weather;
}
void Circuit:: AddCar(Car *car)
{
	if (car != nullptr && (*this).carIndex < 10)
	{
		(*this).cars[(*this).carIndex++] = car;
	}

}
void Circuit::Race()
{
	for (int i = 0; i < carIndex; i++)
	{
		Car* curentCar = (*this).cars[carIndex];
		curentCar->setFinishTime(this->lenght, this->weather);
	}
}
void Circuit::ShowFinalRanks()
{
	bool sorted = false;
	for (int i = 0; i < carIndex; i++)
	{
		cars[i]->setFinishTime(this->lenght, this->weather);
	}
	while (!sorted)
	{
		sorted = true;
		for (int i = 1; i < carIndex; i++)
		{
			if (cars[i-1 ]->getFinishTime() > cars[i]->getFinishTime())
				std::swap(cars[i-1], cars[i]);
		}
	}
	for (int i = 0; i < carIndex; i++)
	{
		if (cars[i]->getFinishTime() != 999)
		{
			std::cout << i + 1 << " | " << cars[i]->getName() << " | " << cars[i]->getFinishTime() << '\n';
			//printf("%s", cars[i + 1]->getName());
		}
		else
		{
			std::cout << i + 1 << " | " << cars[i]->getName() << " | " <<"DID NOT FINISH THE RACE" << '\n';
		}
	}
}
void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < carIndex; i++)
	{
		if (cars[i]->getFinishTime() == 999)
			std::cout << i + 1 << " | " << cars[i]->getName() << " | " << "DID NOT FINISH THE RACE" << '\n';
	}
}


