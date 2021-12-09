#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(void)
{
    double z;
    long long a = 4, b = 3, c = 0, d, x;
    cout << "The number of terms: ";
    cin >> z;
    x = z;
    if (z >= 93 or z <= 0 or x != z)
    {
        cout << "Invalid input";
        return 0;
    }
    cout << "The series: ";
    while (c < z)
    {
        d = a - b;
        a = b;
        b = d;
        if (c == 0)
        {
            cout << b;
            c += 1;
        }
        else
        {
            cout << ", " << b;
            c += 1;
        }
    }
    return 0;
}