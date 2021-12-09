#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    cout << "Input real number (a), before decimal point: ";
    cin >> a1;
    cout << "Input real number (a), after decimal point: ";
    cin >> a2;
    cout << "The real number (a) is: " << a1 << "."
         << setfill('0') << setw(9) << a2 << "000000000" << endl;
    cout << "Input real number (b), before decimal point: ";
    cin >> b1;
    cout << "Input real number (b), after decimal point: ";
    cin >> b2;
    cout << "The real number (b) is: " << b1 << "."
         << setfill('0') << setw(9) << b2 << "000000000" << endl;
    long long int N = 1000000000;
    long long int c1 = a1 * b1 + a1 * b2 / N + a2 * b1 / N;
    long long int c2 = a2 * b2 + ((a1 * b2) % N) * N + ((a2 * b1) % N) * N;
    c1 += c2 / (N * N);
    c2 = c2 % (N * N);
    cout << "(a) * (b) = " << c1 << '.'
         << setfill('0') << setw(18) << c2 << endl;
    return 0;
}