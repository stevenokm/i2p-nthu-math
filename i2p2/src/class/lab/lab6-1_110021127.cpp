#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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
    Complex(const double &arg_real = 0, const double &arg_imag = 0);
    // Copy constructor
    Complex(const Complex &arg_c);
    // assignment operator
    ~Complex() {}
    Complex &operator=(const Complex &arg_c);
    // add assignment operator
    Complex &operator+=(const Complex &arg_c);
    // subtract assignment operator
    Complex &operator-=(const Complex &arg_c);
    // multiply assignment operator
    Complex &operator*=(const Complex &arg_c);
    // divide assignment operator
    Complex &operator/=(const Complex &arg_c);

    // cout `<<` operator for print complex number
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_c);
    // cin `>>` operator for input complex number
    // note: be careful about the format of input
    // hint: use `stod` to convert string to double
    friend istream &operator>>(istream &arg_is, Complex &arg_c);
};
Complex::Complex(const double &arg_real, const double &arg_imag)
    : m_real(arg_real), m_imag(arg_imag) {}

Complex::Complex(const Complex &arg_point)
    : m_real(arg_point.m_real), m_imag(arg_point.m_imag) {}

Complex &Complex::operator=(const Complex &arg_c)
{
    this->m_real = arg_c.m_real;
    this->m_imag = arg_c.m_imag;
    return *this;
}
Complex &Complex::operator+=(const Complex &arg_c)
{
    this->m_real += arg_c.m_real;
    this->m_imag += arg_c.m_imag;
    return *this;
}
Complex &Complex::operator-=(const Complex &arg_c)
{
    this->m_real -= arg_c.m_real;
    this->m_imag -= arg_c.m_imag;
    return *this;
}
Complex &Complex::operator*=(const Complex &arg_c)
{
    double _real = this->m_real, _imag = this->m_imag;
    this->m_real = (_real * arg_c.m_real) - (_imag * arg_c.m_imag);
    this->m_imag = (_real * arg_c.m_imag) + (_imag * arg_c.m_real);
    return *this;
}
Complex &Complex::operator/=(const Complex &arg_c)
{
    double _real = this->m_real, _imag = this->m_imag;
    this->m_real = ((_real * arg_c.m_real) + (_imag * arg_c.m_imag)) 
        / ((arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag));
    this->m_imag = ((-_real * arg_c.m_imag) + (_imag * arg_c.m_real)) 
        / ((arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag));
    return *this;
}
std::ostream &operator<<(std::ostream &arg_os, const Complex &arg_point)
{
    if (arg_point.m_imag == 0)
    {
        arg_os << arg_point.m_real;
        return arg_os;
    }
    else if (arg_point.m_imag < 0)
    {
        arg_os << arg_point.m_real << " - " << -arg_point.m_imag << "i ";
        return arg_os;
    }
    else
    {
        arg_os << arg_point.m_real << " + " << arg_point.m_imag << "i ";
        return arg_os;
    }
}

// read the coordinate of a point from the input, format: (x, y) and ignore space
std::istream &operator>>(std::istream &arg_is, Complex &arg_point)
{
    string str_x, str_y, temp;

    if (getline(arg_is, str_x, ' '))
    {
        if (getline(arg_is, str_y, ' '))
        {
            arg_point.m_real = stod(str_x);
            arg_point.m_imag = stod(str_y);
        }
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
