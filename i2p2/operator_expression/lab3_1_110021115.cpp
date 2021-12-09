#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    int s = 0, exp = 0;
    double sign = 0, man = 0, num = 0;

    std::cout << "Input real number, sign: ";
    std::cin >> s;
    if (s >= 0)
    {
        sign = 1;
    }
    else //s<0
    {
        sign = -1;
    }
    std::cout << "Input real number, mantissa: ";
    std::cin >> man;
    std::cout << "Input real number, exponent: ";
    std::cin >> exp;

    num = sign * (man * (std::pow(10, exp - 8)));

    std::cout << "The real number is: "
              << std::scientific << std::setprecision(8)
              << num << "\n";

    return 0;
}