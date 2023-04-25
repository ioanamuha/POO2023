#include "Circuit.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

Circuit::Circuit()
{
    allocated = 200;
    cars = new Car * [allocated];

    times = new double[200];
}
void Circuit::SetLength(double length) {
    length_ = length;
}

void Circuit::SetWeather(Weather weather) {
    weather_ = weather;
}

void Circuit::AddCar(Car* car) {
    if (nrCars == allocated)
    {
        allocated += grow;
        Car** aux = new Car*[allocated];
        for (int i = 0; i < nrCars; i++)
            aux[i] = cars[i];
        delete[] cars;
        cars = aux;
    }
    cars[nrCars] = car;
    nrCars++;
}

void Circuit::Race() {
    int i;
    for(i=0;i<nrCars;i++)
    {
        double fuel = cars[i]->fuel_capacity();
        double consumption = cars[i]->fuel_consumption();
        double speed = cars[i]->speed(weather_);
        double time = length_ / speed;
        double remaining;
        remaining = length_ - ((consumption / fuel) * 100);
        if (remaining >= 0) {
            times[i] = time;
        }
        else {
            times[i] = -1;
        }
    }
}

void Circuit::ShowFinalRanks() /*const*/ {

    Car* aux;
    Car** copie = new Car * [allocated];
    for (int i = 0; i < nrCars; i++) copie[i] = cars[i];
    int i, j;
    for (i = 0;i < nrCars-1;i++)
    {
        for (j = i + 1;j < nrCars;j++)
        {
            if (times[i] > times[j] || times[i] == -1)
            {
                aux = copie[i];
                copie[i] = copie[j];
                copie[j] = aux;

                swap(times[i], times[j]);
            }
        }
    }
    delete[] cars;
    cars = new Car * [allocated];
    cars = copie;
    for (i = 0;i<nrCars;i++) 
    {
        if (times[i] >= 0)
        { 
            cout << cars[i]->name() << " " << "a terminat cursa in " << times[i] << endl;
        }
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    int i = 0;
    for (i = 0;i < nrCars;i++)
    {
        if (times[i] < 0)
        {
            cout << cars[i]->name() << " " << "nu a terminat cursa" << endl;
        }
    }
}

Circuit::~Circuit()
{
    delete [](times);
    delete[]cars;
}