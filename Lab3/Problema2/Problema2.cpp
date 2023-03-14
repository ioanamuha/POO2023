#include <iostream>
#include "Canvas.h"
int main()
{
    Canvas ca(30,30);

    ca.DrawLine(15, 15, 2, 2, '-');

    int latime = 5;
    int lungime = 10;

    ca.FillRect(latime, lungime, latime, lungime, '@');
    ca.DrawCircle(15, 15, 5, '@');
    ca.Print();
}
