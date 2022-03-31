#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Complex_Calc;

class Complex
{
private:
    // data members
    // save the real and imaginary parts of the complex number
    // with `double` precision
    double m_real;
    double m_imag;

public:
    // Constructor, initializes real and imaginary parts
    Complex(const double &arg_real = 0.0, const double &arg_imag = 0.0);
    // Copy constructor
    Complex(const Complex &arg_c);
    // assignment operator
    Complex &operator=(const Complex &arg_c);
    // add assignment operator
    Complex &operator+=(const Complex &arg_c);
    // subtract assignment operator
    Complex &operator-=(const Complex &arg_c);
    // multiply assignment operator
    Complex &operator*=(const Complex &arg_c);
    // divide assignment operator
    Complex &operator/=(const Complex &arg_c);
    // add function
    Complex operator+(const Complex &arg_c) const;
    // subtract function
    Complex operator-(const Complex &arg_c) const;
    // multiply function
    Complex operator*(const Complex &arg_c) const;
    // divide function
    Complex operator/(const Complex &arg_c) const;
    // cout `<<` operator for print complex number
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_c);
    // cin `>>` operator for input complex number
    // note: be careful about the format of input
    // hint: use `stod` to convert string to double
    friend istream &operator>>(istream &arg_is, Complex &arg_c);

    friend class Complex_Calc;
};

// Complex calculator class declaration
class Complex_Calc
{
private:
    // define current value
    Complex m_curr_val;
    // define input value
    Complex m_input_val;
    // define operation
    // `+`, `-`, `*`, `/`, and `=` for first assign
    char m_op;
    // calculate result
    void _calc_result();
    // operation functions
    // add the input value to the current value
    void _add();
    // subtract the input value from the current value
    void _sub();
    // multiply the input value with the current value
    void _mul();
    // divide the current value by the input value
    void _div();
    // assign the input value to the current value
    void _assign();

public:
    // Constructor
    Complex_Calc();
    // Copy constructor
    Complex_Calc(const Complex_Calc &arg_int_calc);

    // Destructor
    ~Complex_Calc(){}; // no need to do anything

    // set input value or operation
    void set_input(const string &arg_input);

    // cout `<<` operator for print calculator status
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const Complex_Calc &arg_comp_calc);
};

// parse the test cases, do not modify belows

void Complex_Calc::set_input(const string &arg_input)
{
    // input is a operation
    if (arg_input.empty())
    {
        return;
    }
    else if (arg_input == "+" || arg_input == "-" 
            || arg_input == "*" || arg_input == "/")
    {
        m_op = arg_input[0];
    }
    // input is a complex number
    else
    {
        stringstream ss(arg_input);
        ss >> m_input_val;
        switch (m_op)
        {
        case '+':
            m_curr_val += m_input_val;
            break;
        case '-':
            m_curr_val -= m_input_val;
            break;
        case '*':
            m_curr_val *= m_input_val;
            break;
        case '/':
            m_curr_val /= m_input_val;
            break;
        case '=':
            m_curr_val = m_input_val;
            break;
        default:
            cerr << "Error: unknown operation" << endl;
            exit(1);
        }
    }
}

// main function

int main()
{
    // create an instance of the class
    Complex_Calc calc;
    string input;
    while (getline(cin, input))
    {
        calc.set_input(input);
        cout << calc << endl;
    }
}