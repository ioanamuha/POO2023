#include "Seat.h"
#include <iostream>
#include <cstring>


double Seat::fuel_capacity() const {
    return 48.0;
}

double Seat::fuel_consumption() const {
    return 8.5;
}

double Seat::speed(Weather weather) const {
    switch (weather) {
    case Weather::Rain:
        return 61.0;
    case Weather::Sunny:
        return 77.0;
    case Weather::Snow:
        return 42.5;
    }
    return 0.0;
}

const char* Seat::name()
{
    return "Seat";
}