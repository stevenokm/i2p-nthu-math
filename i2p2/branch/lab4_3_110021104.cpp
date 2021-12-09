#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
    int x;
    cout << "Simple scientific calculator" << endl;
    cout << "1) plus (+)" << endl;
    cout << "2) minus (-)" << endl;
    cout << "3) multiplication (*)" << endl;
    cout << "4) division (/)" << endl;
    cout << "5) modulation (%)" << endl;
    cout << "Please select the operator: ";
    cin >> x;
    if (x == 1)
        cout << "You selected: +" << endl;
    else if (x == 2)
        cout << "You selected: -" << endl;
    else if (x == 3)
        cout << "You selected: *" << endl;
    else if (x == 4)
        cout << "You selected: /" << endl;
    else if (x == 5)
        cout << "You selected: %" << endl;
    else
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    double s1, s2, e1, e2;
    double m1, m2;
    cout << "Input real number (a), sign: ";
    cin >> s1;
    cout << "Input real number (a), mantissa: ";
    if (x == 5)
        if (s1 < 1)
        {
            cout << "Invalid input" << endl;
            return 0;
        }
    cin >> m1;
    if (m1 >= 1000000000)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    else if (m1 < 100000000)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    cout << "Input real number (a), exponent: ";
    cin >> e1;
    if (e1 < -38 || e1 > 38)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    int e11 = e1;
    if (e11 != e1)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    if (s1 >= 0)
        s1 = 1;
    else
        s1 = -1;
    while (m1 >= 10)
        m1 /= 10;
    for (int i = 0; i < e1; i++)
        m1 *= 10;
    m1 = m1 * s1;
    if (x == 5)
    {
        if (e1 < 8)
        {
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    cout << "Input real number (b), sign: ";
    cin >> s2;
    if (x == 5)
        if (s2 < 0)
        {
            cout << "Invalid input" << endl;
            return 0;
        }
    cout << "Input real number (b), mantissa: ";
    cin >> m2;
    if (m2 >= 1000000000)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    else if (m2 < 100000000)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    cout << "Input real number (b), exponent: ";
    cin >> e2;
    if (e2 < -38 || e2 > 38)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    int e22 = e2;
    if (e22 != e2)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    if (s2 >= 0)
        s2 = 1;
    else
        s2 = -1;
    while (m2 >= 10)
        m2 /= 10;
    for (int i = 0; i < e2; i++)
        m2 *= 10;
    m2 = m2 * s2;
    int m22 = m2;
    if (x == 5)
    {
        if (e2 < 8)
        {
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    cout << "The real number (a) is: " << setprecision(8) << scientific << m1 << endl;
    cout << "The real number (b) is: " << setprecision(8) << scientific << m2 << endl;
    if (x == 1)
        cout << "(a) + (b) = " << setprecision(14) << scientific << m1 + m2 << endl;
    else if (x == 2)
        cout << "(a) - (b) = " << setprecision(14) << scientific << m1 - m2 << endl;
    else if (x == 3)
        cout << "(a) * (b) = " << setprecision(14) << scientific << m1 * m2 << endl;
    else if (x == 4)
        cout << "(a) / (b) = " << setprecision(14) << scientific << m1 / m2 << endl;
    else
    {
        long long a = m1, b = m2;
        cout << "(a) % (b) = " << setprecision(14) << scientific << a % b << endl;
    }
    return 0;
}
