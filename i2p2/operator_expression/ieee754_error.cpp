#include <iostream>
#include <iomanip>
#include <cmath>
int main(void)
{
    long int a = -100, b = 123456789, c = 7;

    float c_exp = std::pow(10.0, (double)c);
    double b_mantissa = (float)b * 1e-8;
    double b_mantissa_double = (double)b * 1e-8;

    a = (a >= 0 ? 1 : -1);
    float d = a * b_mantissa * c_exp;
    double d_real = a * b_mantissa_double * c_exp;
    double mantissa_diff = d - d_real;
    mantissa_diff = (mantissa_diff >= 0 ? mantissa_diff : mantissa_diff * -1); // abs()
    // round mantissa difference
    double mantissa_diff_round_unit = std::pow(10.0, (double)c - 8);
    double mantissa_diff_quotient = std::round(mantissa_diff / mantissa_diff_round_unit);
    // unit is 10^(c-8), because the significant digits are 9 digits
    // and with a leading digit, the least significant digit is
    // 10^-8 smaller than the leading digit. Thus, the mantissa difference
    // must round to 10^(c-8).
    mantissa_diff = mantissa_diff_round_unit * mantissa_diff_quotient;

    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl
              << "c: " << c << std::endl
              << std::scientific << std::setprecision(8)
              << d << std::endl
              << d_real << std::endl
              << mantissa_diff << std::endl;
    return 0;
}