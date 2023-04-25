#include "Volvo.h"
#include <iostream>
#include <cstring>


double Volvo::fuel_capacity() const {
    return 50.2;
}

double Volvo::fuel_consumption() const {
    return 8.4;
}

double Volvo::speed(Weather weather) const {
    switch (weather) {
    case Weather::Rain:
        return 62.7;
    case Weather::Sunny:
        return 85.4;
    case Weather::Snow:
        return 41.8;
    }
    return 0.0;
}

const char* Volvo::name()
{
    return "Volvo";
}