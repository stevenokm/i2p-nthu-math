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
    cout << "The real number (a) is: " << setprecision(15)
         << a1 + a2 / 10000000000 << endl;
    cout << "Input real number (b), before decimal point: ";
    cin >> b1;
    cout << "Input real number (b), after decimal point: ";
    cin >> b2;
    cout << "The real number (b) is: " << setprecision(15)
         << b1 + b2 / 10000000000 << endl;
    long double c = (a1 + a2 / 10000000000) * (b1 + b2 / 10000000000);
    cout << "(a) * (b) = " << setprecision(15) << c << endl;
    return 0;
}