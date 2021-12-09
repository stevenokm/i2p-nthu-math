#include <iostream>
#include <iomanip>
#include <cmath>
int main()
{
    int a = 0, t = 0;
    long long i = 0, a_mod = 0, b_mod = 0, n8 = 100000000;
    double exp_a = 0, exp_b = 0, num_a = 0, num_b = 0, sign_a = 0, sign_b = 0;

    std::cout << "Simple scientific calculator"
              << "\n"
              << "1) plus (+)"
              << "\n"
              << "2) minus (-)"
              << "\n"
              << "3) multiplication (*)"
              << "\n"
              << "4) division (/)"
              << "\n"
              << "5) modulation (%)"
              << "\n"
              << "Please select the operator: ";
    std::cin >> a;
    switch (a)
    {
    case 1:
        std::cout << "You selected: +" << std::endl;
        break;
    case 2:
        std::cout << "You selected: -" << std::endl;
        break;
    case 3:
        std::cout << "You selected: *" << std::endl;
        break;
    case 4:
        std::cout << "You selected: /" << std::endl;
        break;
    case 5:
        std::cout << "You selected: %" << std::endl;
        break;
    default:
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    std::cout << "Input real number (a), sign: ";
    std::cin >> sign_a;
    if (a == 5 && sign_a < 0)
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    std::cout << "Input real number (a), mantissa: ";
    std::cin >> num_a;
    if (num_a >= 1000000000 || num_a < 100000000)
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    if (a == 5 && ((long long)num_a != num_a || num_a <= 0))
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    for (i = 1; i <= 10; i += 1)
    {
        num_a = (num_a >= 10 ? num_a / 10 : num_a);
    }
    if (sign_a < 0)
        num_a = num_a * (-1);
    std::cout << "Input real number (a), exponent: ";
    std::cin >> exp_a;
    while (((long)(num_a * n8)) % (long)(pow(10, t)) == 0)
    {
        t++;
    }
    t--;
    if (a == 5 && exp_a < (8 - t))
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    if (exp_a > 38 || exp_a < -38 || (long)exp_a != exp_a)
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    std::cout << "Input real number (b), sign: ";
    std::cin >> sign_b;
    if (a == 5 && sign_b < 0)
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    std::cout << "Input real number (b), mantissa: ";
    std::cin >> num_b;
    if (num_b >= 1000000000 || num_b < 100000000)
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    if (a == 5 && ((long long)num_b != num_b || num_b <= 0))
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    for (i = 1; i <= 10; i += 1)
    {
        num_b = (num_b >= 10 ? num_b / 10 : num_b);
    }
    if (sign_b < 0)
        num_b = num_b * (-1);
    std::cout << "Input real number (b), exponent: ";
    std::cin >> exp_b;
    t = 0;
    while (((long)(num_b * n8)) % (long)(pow(10, t)) == 0)
    {
        t++;
    }
    t--;
    if (a == 5 && exp_b < (8 - t))
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    if (exp_b > 38 || exp_b < -38 || (long)exp_b != exp_b)
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    a_mod = num_a * pow(10, exp_a);
    b_mod = num_b * pow(10, exp_b);

    std::cout << "The real number (a) is: " << std::scientific << std::setprecision(8) << num_a * pow(10, exp_a) << std::endl;
    std::cout << "The real number (b) is: " << std::scientific << std::setprecision(8) << num_b * pow(10, exp_b) << std::endl;
    if (a == 1)
        std::cout << "(a) + (b) = " << std::scientific << std::setprecision(14) << num_a * pow(10, exp_a) + num_b * pow(10, exp_b) << std::endl;
    if (a == 2)
        std::cout << "(a) - (b) = " << std::scientific << std::setprecision(14) << num_a * pow(10, exp_a) - num_b * pow(10, exp_b) << std::endl;
    if (a == 3)
        std::cout << "(a) * (b) = " << std::scientific << std::setprecision(14) << (num_a * pow(10, exp_a)) * (num_b * pow(10, exp_b)) << std::endl;
    if (a == 4)
        std::cout << "(a) / (b) = " << std::scientific << std::setprecision(14) << (num_a * pow(10, exp_a)) / (num_b * pow(10, exp_b)) << std::endl;
    if (a == 5)
        std::cout << "(a) % (b) = " << std::scientific << std::setprecision(14) << (double)(a_mod % b_mod) << std::endl;
    return 0;
}