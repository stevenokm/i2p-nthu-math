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
    // note: use `>>` to parse the string to double,
    // use `istream::fail()` to check the conversion is successful
    // and use `istream::eof()` to check the is parse to the end of line
    friend istream &operator>>(istream &arg_is, Complex &arg_c);
};

// error and exit
void error_and_exit()
{
    cerr << "Error: Invalid input" << endl;
    exit(1);
}

// Complex class implementation

// Constructor, initializes real and imaginary parts
// hint: as like as `modify` function in examples
// but use default constructor to implement
Complex::Complex(const double &arg_real, const double &arg_imag)
    : m_real(arg_real), m_imag(arg_imag)
{
}

// Copy constructor
Complex::Complex(const Complex &arg_c)
    : m_real(arg_c.m_real), m_imag(arg_c.m_imag)
{
}

// assignment operator
Complex &Complex::operator=(const Complex &arg_c)
{
    if (this == &arg_c) // self-assignment
        return *this;
    m_real = arg_c.m_real;
    m_imag = arg_c.m_imag;
    return *this;
}

// add assignment operator
Complex &Complex::operator+=(const Complex &arg_c)
{
    m_real += arg_c.m_real;
    m_imag += arg_c.m_imag;
    return *this;
}

// subtract assignment operator
Complex &Complex::operator-=(const Complex &arg_c)
{
    m_real -= arg_c.m_real;
    m_imag -= arg_c.m_imag;
    return *this;
}

// multiply assignment operator
Complex &Complex::operator*=(const Complex &arg_c)
{
    double real = m_real * arg_c.m_real - m_imag * arg_c.m_imag;
    double imag = m_real * arg_c.m_imag + m_imag * arg_c.m_real;
    m_real = real;
    m_imag = imag;
    return *this;
}

// divide assignment operator
Complex &Complex::operator/=(const Complex &arg_c)
{
    if (arg_c.m_real == 0 && arg_c.m_imag == 0)
        error_and_exit();

    double real = (m_real * arg_c.m_real + m_imag * arg_c.m_imag) 
        / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
    double imag = (m_imag * arg_c.m_real - m_real * arg_c.m_imag) 
        / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
    m_real = real;
    m_imag = imag;
    return *this;
}

// add function
Complex Complex::operator+(const Complex &arg_c) const
{
    Complex c(*this);
    c += arg_c;
    return c;
}

// subtract function
Complex Complex::operator-(const Complex &arg_c) const
{
    Complex c(*this);
    c -= arg_c;
    return c;
}

// multiply function
Complex Complex::operator*(const Complex &arg_c) const
{
    Complex c(*this);
    c *= arg_c;
    return c;
}

// divide function
Complex Complex::operator/(const Complex &arg_c) const
{
    Complex c(*this);
    c /= arg_c;
    return c;
}

// cout `<<` operator for print complex number
// note: be careful about the format of output
ostream &operator<<(ostream &arg_os, const Complex &arg_c)
{
    if (arg_c.m_imag > 0)
    {
        arg_os << arg_c.m_real << " + " << arg_c.m_imag << "i";
    }
    else if (arg_c.m_imag < 0)
    {
        arg_os << arg_c.m_real << " - " << -arg_c.m_imag << "i";
    }
    else
    {
        arg_os << arg_c.m_real;
    }
    return arg_os;
}

// cin `>>` operator for input complex number
// note: be careful about the format of input
istream &operator>>(istream &arg_is, Complex &arg_c)
{
    double input_real, input_imag;
    arg_is >> input_real;
    if (arg_is.fail())
    {
        error_and_exit();
    }
    arg_is >> input_imag;
    if (arg_is.fail() || !arg_is.eof())
    {
        error_and_exit();
    }
    arg_c.m_real = input_real;
    arg_c.m_imag = input_imag;
    return arg_is;
}

// used for process the test cases, do not modify
int main()
{
    string input;
    Complex result_complex;
    char op = ' ';

    while (getline(cin, input))
    {
        // input is a operation
        if (input == "+" || input == "-" || input == "*" || input == "/")
        {
            op = input[0];
            continue;
        }
        else if (input.empty())
        {
            continue;
        }
        // input is a complex number
        else
        {
            stringstream ss(input);
            Complex current_complex;
            ss >> current_complex;
            switch (op)
            {
            case '+':
                result_complex += current_complex;
                break;
            case '-':
                result_complex -= current_complex;
                break;
            case '*':
                result_complex *= current_complex;
                break;
            case '/':
                result_complex /= current_complex;
                break;
            case ' ':
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
