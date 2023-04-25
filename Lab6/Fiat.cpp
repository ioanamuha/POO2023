#include "Fiat.h"
#include <iostream>
#include <cstring>


double Fiat::fuel_capacity() const {
    return 40.0;
}

double Fiat::fuel_consumption() const {
    return 50.0;
}

double Fiat::speed(Weather weather) const {
    switch (weather) {
    case Weather::Rain:
        return 54.0;
    case Weather::Sunny:
        return 55.0;
    case Weather::Snow:
        return 50.0;
    }
    return 0.0;
}

const char* Fiat::name()
{
    return "Fiat";
}