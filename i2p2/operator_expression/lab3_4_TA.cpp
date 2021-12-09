#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
     int a_sign, a_exp, b_sign, b_exp;
     unsigned long long a_mantissa, b_mantissa;

     cout << "Input real number (a), sign: ";
     cin >> a_sign;
     a_sign = (a_sign >= 0 ? 1 : -1);
     cout << "Input real number (a), mantissa: ";
     cin >> a_mantissa;
     cout << "Input real number (a), exponent: ";
     cin >> a_exp;

     cout << "Input real number (b), sign: ";
     cin >> b_sign;
     b_sign = (b_sign >= 0 ? 1 : -1);
     cout << "Input real number (b), mantissa: ";
     cin >> b_mantissa;
     cout << "Input real number (b), exponent: ";
     cin >> b_exp;
     // initialize

     cout << "The real number (a) is: "
          << a_sign * (int)(a_mantissa / (long long)1e+18)
          << "."
          << setw(18) << setfill('0')
          << a_mantissa % (long long)1e+18
          << "e"
          << (a_exp >= 0 ? "+" : "-")
          << setw(2) << setfill('0')
          << (a_exp >= 0 ? a_exp : -a_exp)
          << endl;

     cout << "The real number (b) is: "
          << b_sign * (int)(b_mantissa / (long long)1e+18)
          << "."
          << setw(18) << setfill('0')
          << b_mantissa % (long long)1e+18
          << "e"
          << (b_exp >= 0 ? "+" : "-")
          << setw(2) << setfill('0')
          << (b_exp >= 0 ? b_exp : -b_exp)
          << endl;

     int result = (a_sign * b_sign == -1 ? (a_sign > b_sign ? 1 : -1) : 
               (a_exp > b_exp ? a_sign : 
                    (a_exp < b_exp ? -a_sign : 
                         (a_mantissa > b_mantissa ? a_sign : 
                              (a_mantissa < b_mantissa ? -a_sign : 0)
                         )
                    )
               )
          );

     cout << "Compare result: "
          << result
          << endl;

     return 0;
}