#include "BMW.h"
#include <iostream>
#include <cstring>


double BMW::fuel_capacity() const {
    return 45.7;
}

double BMW::fuel_consumption() const {
    return 9.2;
}

double BMW::speed(Weather weather) const {
    switch (weather) {
    case Weather::Rain:
        return 64.0;
    case Weather::Sunny:
        return 82.4;
    case Weather::Snow:
        return 42.8;
    }
    return 0.0;
}

const char* BMW::name()
{
    return "BMW";
}