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
    // hint: as like as `modify` function in examples
    // but use default constructor to implement
    Complex(const double &arg_real = 0.0, const double &arg_imag = 0.0)
    {
        m_real = arg_real;
        m_imag = arg_imag;
    }
    // print function
    // note: be careful about the format of output
    // especially the ` ` and newline (endl)
    void print()
    {
        cout << m_real << " + " << m_imag << " i" << endl;
    }
    // add function
    Complex add(const Complex &arg_c)
    {
        Complex c;
        c.m_real = m_real + arg_c.m_real;
        c.m_imag = m_imag + arg_c.m_imag;
        return c;
    }
    // subtract function
    Complex sub(const Complex &arg_c)
    {
        Complex c;
        c.m_real = m_real - arg_c.m_real;
        c.m_imag = m_imag - arg_c.m_imag;
        return c;
    }
    // multiply function
    Complex mul(const Complex &arg_c)
    {
        Complex c;
        c.m_real = m_real * arg_c.m_real - m_imag * arg_c.m_imag;
        c.m_imag = m_real * arg_c.m_imag + m_imag * arg_c.m_real;
        return c;
    }
    // divide function
    Complex div(const Complex &arg_c)
    {
        Complex c;
        c.m_real = (m_real * arg_c.m_real + m_imag * arg_c.m_imag) / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        c.m_imag = (m_imag * arg_c.m_real - m_real * arg_c.m_imag) / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        return c;
    }
};

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
        // input is a complex number
        else
        {
            stringstream ss(input);
            double real, imag;
            ss >> real >> imag;
            Complex current_complex(real, imag);
            switch (op)
            {
            case '+':
                result_complex = result_complex.add(current_complex);
                break;
            case '-':
                result_complex = result_complex.sub(current_complex);
                break;
            case '*':
                result_complex = result_complex.mul(current_complex);
                break;
            case '/':
                result_complex = result_complex.div(current_complex);
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
    result_complex.print();
    return 0;
}