#include <iostream>
#include "Math.h"

int main()
{
    std::cout << Math::Add(1, 2) << std::endl;
    std::cout << Math::Add(1, 2, 3) << std::endl;
    std::cout << Math::Add(2.1, 2.2) << std::endl;
    std::cout << Math::Add(2.1, 2.2, 2.3) << std::endl;
    std::cout << Math::Add(4, 1, 2, 3, 4) << std::endl;
    std::cout << Math::Mul(2, 2) << std::endl;
    std::cout << Math::Mul(2, 2, 2) << std::endl;
    std::cout << Math::Mul(3.3, 3.3) << std::endl;
    std::cout << Math::Mul(3.3, 3.3, 3.3) << std::endl;
}
