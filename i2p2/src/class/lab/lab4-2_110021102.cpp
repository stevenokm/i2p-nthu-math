#include <iostream>
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
    Complex(double arg_real = 0.0, double arg_imag = 0.0);
    Complex(const Complex &arg_c);
    // print function
    // note: be careful about the format of output
    // especially the ` ` and newline (endl)
    void print() const;
    double get_real() const;
    double get_imag() const;
    void set_real(double &real);
    void set_imag(double &imag);
    Complex add(const Complex &arg_c);
    Complex sub(const Complex &arg_c);
    Complex mul(const Complex &arg_c);
    Complex div(Complex &arg_c);
    Complex const_mul(double arg_x);
    Complex conj();
};
Complex::Complex(double arg_real, double arg_imag)
    : m_real(arg_real), m_imag(arg_imag)
{
}
Complex::Complex(const Complex &arg_c)
    : m_real(arg_c.get_real()), m_imag(arg_c.get_imag())
{
}
void Complex::print() const
{
    cout << m_real << " + " << this->m_imag << " i" << endl;
}
double Complex::get_real() const
{
    return m_real;
}
double Complex::get_imag() const
{
    return m_imag;
}
void Complex::set_real(double &real)
{
    m_real = real;
}
void Complex::set_imag(double &imag)
{
    m_imag = imag;
}
Complex Complex::add(const Complex &arg_c)
{
    Complex c_temp;
    c_temp.m_real = m_real + (arg_c.get_real());
    c_temp.m_imag = m_imag + (arg_c.get_imag());
    return c_temp;
}
Complex Complex::sub(const Complex &arg_c)
{
    Complex c_temp;
    c_temp.m_real = m_real - (arg_c.get_real());
    c_temp.m_imag = m_imag - (arg_c.get_imag());
    return c_temp;
}
Complex Complex::mul(const Complex &arg_c)
{
    Complex c_temp;
    c_temp.m_real = m_real * (arg_c.get_real()) - m_imag * (arg_c.get_imag());
    c_temp.m_imag = m_imag * (arg_c.get_real()) + m_real * (arg_c.get_imag());
    return c_temp;
}
Complex Complex::div(Complex &arg_c)
{
    double c = arg_c.get_real();
    double d = arg_c.get_imag();
    Complex c_this(m_real, m_imag);
    Complex c_temp;
    arg_c = arg_c.conj();
    c_temp = c_this.mul(arg_c);
    c = c * c + d * d;
    c = 1 / c;
    c_temp = c_temp.const_mul(c);
    return c_temp;
}
Complex Complex::const_mul(double arg_x)
{
    Complex c_temp;
    c_temp.m_real = m_real * arg_x;
    c_temp.m_imag = m_imag * arg_x;
    return c_temp;
}
Complex Complex::conj()
{
    Complex c_temp;
    c_temp.m_real = m_real;
    c_temp.m_imag = -m_imag;
    return c_temp;
}

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