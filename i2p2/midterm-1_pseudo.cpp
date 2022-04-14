#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class BigReal
{
private:
    // data members
    // save the digits before and after the decimal point of a before_decimal number
    // with `long long` precision
    const long long m_dec_upperbound = 1000000000;
    long long m_before_decimal;
    long long m_after_decimal; // times 10^-9
    void _output_normalization();

public:
    // Constructor, initializes before_decimal and after_decimalinary parts
    // hint: as like as `modify` function in examples
    // but use default constructor to implement
    BigReal(const long long &arg_before_decimal = 0.0,
            const long long &arg_after_decimal = 0.0);
    // Copy constructor
    BigReal(const BigReal &arg_big_real);
    // assignment operator
    BigReal &operator=(const BigReal &arg_big_real);
    // add assignment operator
    BigReal &operator+=(const BigReal &arg_big_real);
    // multiply assignment operator
    BigReal &operator*=(const BigReal &arg_big_real);
    // add function
    BigReal operator+(const BigReal &arg_big_real) const;
    // multiply function
    BigReal operator*(const BigReal &arg_big_real) const;
    // cout `<<` operator for print BigReal number
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const BigReal &arg_big_real);
    // cin `>>` operator for input BigReal number
    // note: be careful about the format of input
    // hint: use string `+=` to append digits
    friend istream &operator>>(istream &arg_is, BigReal &arg_big_real);
};

int main()
{
    string input;
    BigReal result_complex;
    char op = '=';

    while (getline(cin, input))
    {
        // input is a operation
        if (input == "+" || input == "*")
        {
            op = input[0];
            continue;
        }
        else if (input.empty())
        {
            continue;
        }
        // input is a BigReal number
        else
        {
            stringstream ss(input);
            BigReal current_complex;
            ss >> current_complex;
            switch (op)
            {
            case '+':
                result_complex += current_complex;
                break;
            case '*':
                result_complex *= current_complex;
                break;
            case '=':
                result_complex = current_complex;
                break;
            default:
                cerr << "Error: unknown operation" << endl;
                return 1;
            }
        }
    }
    cout << endl;
    cout << result_complex << endl;
    return 0;
}