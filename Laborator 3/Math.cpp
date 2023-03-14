#include "Math.h"
#include <cstdarg>

using namespace std;

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return a + b;
}

int Math::Add(double a, double b, double c)
{
    return a + b + c;
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return a * b;
}

int Math::Mul(double a, double b, double c)
{
    return a * b * c;
}

int Math::Add(int count, ...)
{
    int sum = 0;
    va_list parameters;
    va_start(parameters, count);
    for (int i = 0; i < count; ++i) {
        sum += va_arg(parameters, int);
    }
    va_end(parameters);

    return sum;
}

char* Math::Add(const char* str1, const char* str2)
{
    if (str1 == nullptr || str2 == nullptr)
        return nullptr;

    char* result = new char[strlen(str1) + strlen(str2) + 1];
    memcpy(result, str1, strlen(str1));
    memcpy(result + strlen(str1), str2, strlen(str2) + 1);

    return result;
}
