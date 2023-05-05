#include <stdio.h>
float operator"" _Kelvin(long double x)
{
    return (float)(x + 273.15);
}
float operator"" _Fahrenheit(long double x)
{
    return (float)(x * 1.8 + 32);
}
int main()
{
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    printf("The value of a is %f\n", a);
    printf("The value of b is %f\n", b);
    return 0;
}
