#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Complex
{
private:
    // data members
    // save the real and imaginary parts of the complex number
    // with double precision
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
    // hint: use stod to convert string to double
    friend istream &operator>>(istream &arg_is, Complex &arg_c);
};

Complex::Complex(const double &arg_real, const double &arg_image)
    : m_real(arg_real), m_imag(arg_image)
{
}

Complex::Complex(const Complex &arg_c)
    : m_real(arg_c.m_real), m_imag(arg_c.m_imag)
{
}

Complex &Complex::operator=(const Complex &arg_c)
{
    m_real = arg_c.m_real;
    m_imag = arg_c.m_imag;
    return *this;
}

Complex &Complex::operator+=(const Complex &arg_c)
{
    m_real += arg_c.m_real;
    m_imag += arg_c.m_imag;
    return *this;
}

Complex &Complex::operator-=(const Complex &arg_c)
{
    m_real -= arg_c.m_real;
    m_imag -= arg_c.m_imag;
    return *this;
}

Complex &Complex::operator*=(const Complex &arg_c)
{
    Complex a;
    a.m_real = m_real;
    a.m_imag = m_imag;
    m_real = a.m_real * arg_c.m_real - a.m_imag * arg_c.m_imag;
    m_imag = a.m_real * arg_c.m_imag + arg_c.m_real * a.m_imag;
    return *this;
}

Complex &Complex::operator/=(const Complex &arg_c)
{
    Complex a;
    a.m_real = m_real;
    a.m_imag = m_imag;
    m_real = (a.m_real * arg_c.m_real + a.m_imag * arg_c.m_imag) 
        / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
    m_imag = (arg_c.m_real * a.m_imag - a.m_real * arg_c.m_imag) 
        / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
    return *this;
}

ostream &operator<<(ostream &arg_os, const Complex &arg_c)
{
    if (arg_c.m_imag == 0)
    {
        arg_os << arg_c.m_real;
    }
    else if (arg_c.m_imag < 0)
    {
        arg_os << arg_c.m_real << " - " << 0.0 - arg_c.m_imag << "i";
    }
    else
    {
        arg_os << arg_c.m_real << " + " << arg_c.m_imag << "i";
    }
    return arg_os;
}

istream &operator>>(istream &arg_is, Complex &arg_c)
{
    string strs;
    size_t sz;
    arg_c = {0, 0};
    arg_is >> strs;
    try
    {
        arg_c.m_real = stod(strs);
    }
    catch (const invalid_argument &ia)
    {
    }
    strs = "";
    arg_is >> strs;
    try
    {
        arg_c.m_imag = stod(strs);
    }
    catch (const invalid_argument &ia)
    {
    }
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