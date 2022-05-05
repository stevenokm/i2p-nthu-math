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
    void _output_normalization()
    {
        if (m_after_decimal < 0)
        {
            m_before_decimal -= 1;
            m_after_decimal += m_dec_upperbound;
        }
        if (m_after_decimal > m_dec_upperbound)
        {
            m_before_decimal += m_after_decimal / m_dec_upperbound;
            m_after_decimal = m_after_decimal % m_dec_upperbound;
        }
    }

public:
    // Constructor, initializes before_decimal and after_decimalinary parts
    // hint: as like as `modify` function in examples
    // but use default constructor to implement
    BigReal(const long long &arg_before_decimal = 0.0,
            const long long &arg_after_decimal = 0.0)
        : m_before_decimal(arg_before_decimal), m_after_decimal(arg_after_decimal)
    {
    }
    // Copy constructor
    BigReal(const BigReal &arg_big_real)
        : m_before_decimal(arg_big_real.m_before_decimal),
          m_after_decimal(arg_big_real.m_after_decimal)
    {
    }
    // assignment operator
    BigReal &operator=(const BigReal &arg_big_real)
    {
        if (this == &arg_big_real) // self-assignment
            return *this;
        m_before_decimal = arg_big_real.m_before_decimal;
        m_after_decimal = arg_big_real.m_after_decimal;
        return *this;
    }
    // add assignment operator
    BigReal &operator+=(const BigReal &arg_big_real)
    {
        m_before_decimal += arg_big_real.m_before_decimal;
        m_after_decimal += arg_big_real.m_after_decimal;
        _output_normalization();
        return *this;
    }
    // multiply assignment operator
    BigReal &operator*=(const BigReal &arg_big_real)
    {
        long long before_decimal = m_before_decimal * arg_big_real.m_before_decimal;
        long long after_decimal = m_after_decimal * arg_big_real.m_after_decimal / m_dec_upperbound;
        after_decimal += m_before_decimal * arg_big_real.m_after_decimal;
        after_decimal += m_after_decimal * arg_big_real.m_before_decimal;
        m_before_decimal = before_decimal;
        m_after_decimal = after_decimal;
        _output_normalization();
        return *this;
    }
    // add function
    BigReal operator+(const BigReal &arg_big_real) const
    {
        BigReal c(*this);
        c += arg_big_real;
        return c;
    }
    // multiply function
    BigReal operator*(const BigReal &arg_big_real) const
    {
        BigReal c(*this);
        c *= arg_big_real;
        return c;
    }
    // cout `<<` operator for print BigReal number
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const BigReal &arg_big_real)
    {
        arg_os << arg_big_real.m_before_decimal << '.'
               << setfill('0') << setw(9) << arg_big_real.m_after_decimal;
        return arg_os;
    }
    // cin `>>` operator for input BigReal number
    // note: be careful about the format of input
    // hint: use string `+=` to append digits
    friend istream &operator>>(istream &arg_is, BigReal &arg_big_real)
    {
        string str_before_decimal, str_after_decimal;
        getline(arg_is, str_before_decimal, '.');
        getline(arg_is, str_after_decimal);
        str_after_decimal = str_after_decimal.substr(0, 9);
        for (int i = 0; i < 9; i++)
            if (i >= str_after_decimal.size())
                str_after_decimal += '0';
        arg_big_real.m_before_decimal = stoll(str_before_decimal);
        arg_big_real.m_after_decimal = stoll(str_after_decimal);
        return arg_is;
    }
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