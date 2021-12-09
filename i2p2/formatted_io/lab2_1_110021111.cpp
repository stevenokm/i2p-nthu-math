#include <iostream>
using namespace std;
int main()
{
    float a, b;
    cout << "Input real number, before decimal point: ";
    cin >> a;
    cout << "Input real number, after decimal point: ";
    cin >> b;
    cout << "The real number is: " << a + b / 1000000 << endl;
    return 0;
}