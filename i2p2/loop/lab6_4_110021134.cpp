#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    unsigned long long long_a_a = 0, long_a_b = 0, long_b_a = 0, long_b_b = 0, t_a = 0, t_b = 0;
    while (1)
    {
        while (cout << "The number a, first part (input -1 to exit): ")
        {
            cin >> long_a_a;
            if (long_a_a == -1)
            {
                return 0;
            }
            if (long_a_a < 0 || long_a_a >= (long long)pow(10, 18))
            {
                cout << "Invalid input" << endl;
                continue;
            }
            cout << "The number a, second part (input -1 to exit): ";
            cin >> long_a_b;
            if (long_a_b == -1)
            {
                return 0;
            }
            if (long_a_b < 0 || long_a_b >= (long long)pow(10, 18))
            {
                cout << "Invalid input" << endl;
                continue;
            }
            if (long_a_a == 0 && long_a_b == 0)
            {
                cout << "Invalid input" << endl;
                continue;
            }
            if (long_a_a == 0)
            {
                cout << "The number a = " << long_a_b << endl;
            }
            else
            {
                cout << "The number a = " << long_a_a << setfill('0') << setw(18) << long_a_b << endl;
            }
            break;
        }
        while (cout << "The number b, first part (input -1 to exit): ")
        {
            cin >> long_b_a;
            if (long_b_a == -1)
            {
                return 0;
            }
            if (long_b_a < 0 || long_b_a >= (long long)pow(10, 18))
            {
                cout << "Invalid input" << endl;
                continue;
            }
            cout << "The number b, second part (input -1 to exit): ";
            cin >> long_b_b;
            if (long_b_b == -1)
            {
                return 0;
            }
            if (long_b_b < 0 || long_b_b >= (long long)pow(10, 18))
            {
                cout << "Invalid input" << endl;
                continue;
            }
            if (long_b_a == 0 && long_b_b == 0)
            {
                cout << "Invalid input" << endl;
                continue;
            }
            if (long_b_a == 0)
            {
                cout << "The number b = " << long_b_b << endl;
            }
            else
            {
                cout << "The number b = " << long_b_a << setfill('0') << setw(18) << long_b_b << endl;
            }
            break;
        }
        while (long_b_a != 0 || long_b_b != 0)
        {
            t_a = long_b_a;
            t_b = long_b_b;
            while (long_a_a >= long_b_a)
            {
                if (long_b_a == 0 && long_b_b != 0)
                {
                    long_a_b %= long_b_b;
                    long_a_a--;
                    if (long_a_a > (long long)pow(10, 18))
                    {
                        long_a_a++;
                        break;
                    }
                    long_a_b += (long long)pow(10, 18);
                }
                else
                {
                    long_a_a -= long_b_a;
                    if (long_a_b < long_b_b)
                    {
                        long_a_a--;
                        if (long_a_a > (long long)pow(10, 18))
                        {
                            long_a_a++;
                            long_a_a += long_b_a;
                            break;
                        }
                        long_a_b += (long long)pow(10, 18);
                        long_a_b -= long_b_b;
                    }
                    else
                    {
                        long_a_b -= long_b_b;
                    }
                }
            }
            long_b_a = long_a_a;
            long_b_b = long_a_b;
            long_a_a = t_a;
            long_a_b = t_b;
        }

        if (long_a_a == 0)
        {
            cout << "The gcd(a, b) = " << long_a_b << endl;
        }
        else
        {
            cout << "The gcd(a, b) = " << long_a_a << setfill('0') << setw(18) << long_a_b << endl;
        }

        cout << endl;
    }
    return 0;
}
