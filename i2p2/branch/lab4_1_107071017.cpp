#include <iostream>
#include <iomanip>

int main(void)
{
    int a = 0;
    std::cout << "Simple scientific calculator\n"
              << "1) plus (+)\n"
              << "2) minus (-)\n"
              << "3) multiplication (*)\n"
              << "4) division (/)\n"
              << "Please select the operator: "
              << std::endl;
    std::cin >> a;
    if (a == 1)
    {
        std::cout << "You selected: "
                  << "+"
                  << std::endl;
    }
    else if (a == 2)
    {
        std::cout << "You selected: "
                  << "-"
                  << std::endl;
    }
    else if (a == 3)
    {
        std::cout << "You selected: "
                  << "*"
                  << std::endl;
    }
    else if (a == 4)
    {
        std::cout << "You selected: "
                  << "/"
                  << std::endl;
    }
    else
    {
        std::cout << "Your operator is not in here!!!!!!!"
                  << std::endl;
    }
}
