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

void BigReal_Calc::set_input(const string &arg_input)
{
    if (arg_input.empty())
    {
        return;
    }
    // input is a operation
    else if ()
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
        
    }
    // input is a complex number
    // as the same as the user type a number
    // it performs as the same as the user pressed the '=' button
    // if the input is the first input
    // thus, we initialize the m_op to '='
    else if ()
    {
        stringstream ss(arg_input);
        ss >> m_input_val;
        _calc_result();
        // set to 'input a op' turn
        
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