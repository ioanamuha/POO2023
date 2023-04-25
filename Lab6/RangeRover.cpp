#include "RangeRover.h"
#include <iostream>
#include <cstring>


double RangeRover::fuel_capacity() const {
    return 52.4;
}

double RangeRover::fuel_consumption() const {
    return 10.7;
}

double RangeRover::speed(Weather weather) const {
    switch (weather) {
    case Weather::Rain:
        return 71.5;
    case Weather::Sunny:
        return 84.7;
    case Weather::Snow:
        return 43.8;
    }
    return 0.0;
}

const char* RangeRover::name()
{
    return "RangeRover";
}