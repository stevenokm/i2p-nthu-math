#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

class BigReal_Calc;

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

// BigReal calculator class declaration
class BigReal_Calc
{
private:
    // define current value
    BigReal m_curr_val;
    // define input value
    BigReal m_input_val;
    // define operation
    // `+`, `*`, and `=`
    char m_op;
    // define input status, truns `op` for true and turns `value` for false
    bool m_op_input;
    // calculate result
    void _calc_result();
    // operation functions
    // set activation op to add
    void _add();
    // set activation op to subtract
    void _mul();
    // set activation op to divide
    void _assign();

public:
    // Constructor
    BigReal_Calc();
    // Copy constructor
    BigReal_Calc(const BigReal_Calc &arg_int_calc);

    // Destructor
    ~BigReal_Calc(){}; // no need to do anything

    // set input value or operation
    // as the same as the user input number or operation
    // into the calculator
    void set_input(const string &arg_input);

    // cout `<<` operator for print calculator status
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const BigReal_Calc &arg_comp_calc);
};

// error and exit
void error_and_exit()
{
    cerr << "Error: Invalid input" << endl;
    exit(1);
}

// BigReal class implementation

void BigReal::_output_normalization()
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

// Constructor, initializes before_decimal and after_decimalinary parts
// hint: as like as `modify` function in examples
// but use default constructor to implement
BigReal::BigReal(const long long &arg_before_decimal,
                 const long long &arg_after_decimal)
    : m_before_decimal(arg_before_decimal), m_after_decimal(arg_after_decimal)
{
}
// Copy constructor
BigReal::BigReal(const BigReal &arg_big_real)
    : m_before_decimal(arg_big_real.m_before_decimal),
      m_after_decimal(arg_big_real.m_after_decimal)
{
}
// assignment operator
BigReal &BigReal::operator=(const BigReal &arg_big_real)
{
    if (this == &arg_big_real) // self-assignment
        return *this;
    m_before_decimal = arg_big_real.m_before_decimal;
    m_after_decimal = arg_big_real.m_after_decimal;
    return *this;
}
// add assignment operator
BigReal &BigReal::operator+=(const BigReal &arg_big_real)
{
    m_before_decimal += arg_big_real.m_before_decimal;
    m_after_decimal += arg_big_real.m_after_decimal;
    _output_normalization();
    return *this;
}
// multiply assignment operator
BigReal &BigReal::operator*=(const BigReal &arg_big_real)
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
BigReal BigReal::operator+(const BigReal &arg_big_real) const
{
    BigReal c(*this);
    c += arg_big_real;
    return c;
}
// multiply function
BigReal BigReal::operator*(const BigReal &arg_big_real) const
{
    BigReal c(*this);
    c *= arg_big_real;
    return c;
}
// cout `<<` operator for print BigReal number
// note: be careful about the format of output
ostream &operator<<(ostream &arg_os, const BigReal &arg_big_real)
{
    arg_os << arg_big_real.m_before_decimal << '.'
           << setfill('0') << setw(9) << arg_big_real.m_after_decimal;
    return arg_os;
}
// cin `>>` operator for input BigReal number
// note: be careful about the format of input
// hint: use string `+=` to append digits
istream &operator>>(istream &arg_is, BigReal &arg_big_real)
{
    string str_before_decimal, str_after_decimal;
    getline(arg_is, str_before_decimal, '.');
    if (str_before_decimal.empty() || str_before_decimal.size() > 9)
    {
        error_and_exit();
    }
    getline(arg_is, str_after_decimal);
    if (str_after_decimal.empty() || str_after_decimal.size() > 9 || !arg_is.eof())
    {
        error_and_exit();
    }
    for (int i = 0; i < 9; i++)
    {
        if (i >= str_after_decimal.size())
        {
            str_after_decimal += '0';
        }
        else if (!isdigit(str_after_decimal[i]))
        {
            error_and_exit();
        }
    }
    stringstream ss_before_decimal(str_before_decimal);
    ss_before_decimal >> arg_big_real.m_before_decimal;
    if (ss_before_decimal.fail())
    {
        error_and_exit();
    }
    stringstream ss_after_decimal(str_after_decimal);
    ss_after_decimal >> arg_big_real.m_after_decimal;
    if (ss_after_decimal.fail())
    {
        error_and_exit();
    }
    return arg_is;
}

// BigReal_Calc class implementation

// Constructor
BigReal_Calc::BigReal_Calc()
    : m_curr_val(), m_input_val(), m_op('='), m_op_input(false)
{
}

// Copy constructor
BigReal_Calc::BigReal_Calc(const BigReal_Calc &arg_int_calc)
    : m_curr_val(arg_int_calc.m_curr_val),
      m_input_val(arg_int_calc.m_input_val),
      m_op(arg_int_calc.m_op),
      m_op_input(arg_int_calc.m_op_input)
{
}

// calculate the result
void BigReal_Calc::_calc_result()
{
    switch (m_op)
    {
    case '+':
        m_curr_val += m_input_val;
        break;
    case '*':
        m_curr_val *= m_input_val;
        break;
    case '=':
        m_curr_val = m_input_val;
        break;
    default:
        error_and_exit();
    }
}

// set activation op to add
void BigReal_Calc::_add()
{
    m_op = '+';
}

// set activation op to multiply
void BigReal_Calc::_mul()
{
    m_op = '*';
}

// set activation op to assign
void BigReal_Calc::_assign()
{
    m_op = '=';
}

// cout `<<` operator for print calculator status
ostream &operator<<(ostream &arg_os, const BigReal_Calc &arg_comp_calc)
{
    arg_os << arg_comp_calc.m_curr_val;
    return arg_os;
}

void BigReal_Calc::set_input(const string &arg_input)
{
    if (arg_input.empty())
    {
        return;
    }
    // input is a operation
    else if (m_op_input && (arg_input == "+" || arg_input == "*" || arg_input == "="))
    {
        // set the activated operation
        // as the same as the user press the op button
        switch (arg_input[0])
        {
        case '+':
            _add();
            break;
        case '*':
            _mul();
            break;
        case '=':
            _assign();
            break;
        }
        // set to 'input a complex number' turn
        m_op_input = false;
    }
    // input is a complex number
    // as the same as the user type a number
    // it performs as the same as the user pressed the '=' button
    // if the input is the first input
    // thus, we initialize the m_op to '='
    else if (!m_op_input)
    {
        stringstream ss(arg_input);
        ss >> m_input_val;
        _calc_result();
        // set to 'input a op' turn
        m_op_input = true;
    }
    else
    {
        error_and_exit();
    }
}

// main function

int main()
{
    // create an instance of the class
    BigReal_Calc calc;
    string input;
    while (getline(cin, input))
    {
        calc.set_input(input);
        cout << calc << endl;
    }
}