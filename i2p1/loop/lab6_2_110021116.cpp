#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(int argc, char **argv)
{
	long long int a, b, gcd;
	int i = 0, j = 0, k = 0;

	while (true)
	{
		cout << "The number a (input 0 to exit): ";
		cin >> a;
		if (a >= (long long int)pow(10, 18) || a < 0)
		{
			cout << "Invalid input\n";
			continue;
		}
		if (a == 0)
			return 0;

		cout << "The number b (input 0 to exit): ";
		cin >> b;
		if (b >= (long long int)pow(10, 18) || b < 0)
		{
			cout << "Invalid input\n";
			continue;
		}
		if (b == 0)
			return 0;
		while (a != 0 && b != 0)
		{
			if (a >= b)
			{
				a = a % b;
			}
			else
			{
				b = b % a;
			}
		}
		if (a >= b)
			gcd = a;
		else
			gcd = b;
		cout << "The gcd(a, b) = " << gcd << "\n\n";
	}
}