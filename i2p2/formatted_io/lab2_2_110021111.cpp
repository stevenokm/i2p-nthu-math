#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a1, a2, b1, b2;
    cout << "Input real number (a), before decimal point: ";
    cin >> a1;
    cout << "Input real number (a), after decimal point: ";
    cin >> a2;
    cout << "The real number (a) is: " << fixed << a1 + a2 / 1000000 << endl;
    cout << "Input real number (b), before decimal point: ";
    cin >> b1;
    cout << "Input real number (b), after decimal point: ";
    cin >> b2;
    cout << "The real number (b) is: " << fixed << b1 + b2 / 1000000 << endl;
    cout << "(a) + (b) = " << fixed << a1 + b1 + (a2 + b2) / 1000000 << endl;
    return 0;
}