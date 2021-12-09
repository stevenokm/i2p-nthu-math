#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int selection;
    cout << "Simple scientific calculator \n"
         << "1) plus (+) \n"
         << "2) minus (-) \n"
         << "3) multiplication (*) \n"
         << "4) division (/) \n";
    cout << "Please select the operator: ";
    cin >> selection;
    switch (selection)
    {
    case 1:
        cout << "You selected: +" << endl;
        break;
    case 2:
        cout << "You selected: -" << endl;
        break;
    case 3:
        cout << "You selected: *" << endl;
        break;
    case 4:
        cout << "You selected: /" << endl;
        break;
    }

    int sign_a, exponent_a, sign_b, exponent_b;
    double mantissa_a, mantissa_b;

    cout << "Input real number (a), sign: ";
    cin >> sign_a;
    cout << "Input real number (a), mantissa: ";
    cin >> mantissa_a;
    cout << "Input real number (a), exponent: ";
    cin >> exponent_a;

    cout << "Input real number (b), sign: ";
    cin >> sign_b;
    cout << "Input real number (b), mantissa: ";
    cin >> mantissa_b;
    cout << "Input real number (b), exponent: ";
    cin >> exponent_b;

    mantissa_a = mantissa_a / 100000000;
    mantissa_b = mantissa_b / 100000000;

    double num_a = pow(10, exponent_a);
    double number_a = mantissa_a * num_a;
    if (sign_a >= 0)
    {
        cout << "The real number (a) is: " << setprecision(8) << scientific << number_a << endl;
    }
    else
    {
        number_a = -number_a;
        cout << "The real number (a) is: " << setprecision(8) << scientific << number_a << endl;
    }

    double num_b = pow(10, exponent_b);
    double number_b = mantissa_b * num_b;
    if (sign_b >= 0)
    {
        cout << "The real number (b) is: " << setprecision(8) << scientific << number_b << endl;
    }
    else
    {
        number_b = -number_b;
        cout << "The real number (b) is: " << setprecision(8) << scientific << number_b << endl;
    }

    switch (selection)
    {
    case 1:
        cout << "(a) + (b) = " << setprecision(14) << number_a + number_b << endl;
        break;
    case 2:
        cout << "(a) - (b) = " << setprecision(14) << number_a - number_b << endl;
        break;
    case 3:
        cout << "(a) * (b) = " << setprecision(14) << number_a * number_b << endl;
        break;
    case 4:
        cout << "(a) / (b) = " << setprecision(14) << number_a / number_b << endl;
        break;
    }

    return 0;
}