#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

int main()
{
    long long sign1, num1, sign2, num2;
    std::string man1, man2;
    signed int expo1, expo2;
    int comp = 0, i;

    std::cout << "Input real number (a), sign: ";
    std::cin >> sign1;

    std::cout << "Input real number (a), mantissa: ";
    std::cin >> man1;

    if (sign1 < 0)
    {
        man1.insert(0, "-");
        man1.insert(2, ".");
    }
    else
    {
        man1.insert(1, ".");
    }

    std::cout << "Input real number (a), exponent: ";
    std::cin >> expo1;

    std::cout << "Input real number (b), sign: ";
    std::cin >> sign2;

    std::cout << "Input real number (b), mantissa: ";
    std::cin >> man2;

    if (sign2 < 0)
    {
        man2.insert(0, "-");
        man2.insert(2, ".");
    }
    else
    {
        man2.insert(1, ".");
    }

    std::cout << "Input real number (b), exponent: ";
    std::cin >> expo2;

    std::cout << "The real number (a) is: " << man1 << "e" << std::showpos << expo1
              << std::noshowpos << std::endl;
    std::cout << "The real number (b) is: " << man2 << "e" << std::showpos << expo2
              << std::noshowpos << std::endl;

    if (sign1 >= 0 && sign2 < 0)
        comp = 1;
    else if (sign1 < 0 && sign2 >= 0)
        comp = -1;
    else
    {
        if (sign1 >= 0)
        {
            if (expo1 > expo2)
                comp = 1;
            else if (expo1 < expo2)
                comp = -1;
            else
            {
                for (i = 0; i < man1.length(); i++)
                {
                    if (man1[i] > man2[i])
                    {
                        comp = 1;
                        break;
                    }
                    else if (man1[i] > man2[i])
                    {
                        comp = -1;
                        break;
                    }
                }
            }
        }
        else
        {
            if (expo1 > expo2)
                comp = -1;
            else if (expo1 < expo2)
                comp = 1;
            else
            {
                for (i = 0; i < man1.length(); i++)
                {
                    if (man1[i] > man2[i])
                    {
                        comp = -1;
                        break;
                    }
                    else if (man1[i] > man2[i])
                    {
                        comp = 1;
                        break;
                    }
                }
            }
        }
    }

    std::cout << "Compare result: " << comp << std::endl;
}