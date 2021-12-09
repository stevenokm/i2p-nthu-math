#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    cout << "Input real number (a), before decimal point: ";
    cin >> a1;
    cout << "Input real number (a), after decimal point: ";
    cin >> a2;
    cout << "The real number (a) is: " << a1 << "."
         << setfill('0') << setw(18) << a2 << endl;
    cout << "Input real number (b), before decimal point: ";
    cin >> b1;
    cout << "Input real number (b), after decimal point: ";
    cin >> b2;
    cout << "The real number (b) is: " << b1 << "."
         << setfill('0') << setw(18) << b2 << endl;
    long long int c2 = a2 + b2, c1 = a1 + b1;
    long long int N = 1000000000000000000;
    if (c2 >= N)
    {
        c2 = c2 - N;
        c1++;
    }
    cout << "(a) + (b) = " << c1 << '.'
         << setfill('0') << setw(18) << c2 << endl;
    return 0;
}