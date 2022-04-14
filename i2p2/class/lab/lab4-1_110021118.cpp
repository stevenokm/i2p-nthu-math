#include <iostream>

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
    Complex(const double &arg_real = 0.0, const double &arg_imag = 0.0);
    // Copy Constructor
    Complex(const Complex &arg_complex);
    // Destructor
    ~Complex(){
        // do nothing
    };
    // print function
    // note: be careful about the format of output
    // especially the ` ` and newline (endl)
    void print();
};

Complex::Complex(const double &arg_real, const double &arg_imag)
    : m_real(arg_real), m_imag(arg_imag)
{
}

Complex::Complex(const Complex &arg_complex)
    : m_real(arg_complex.m_real), m_imag(arg_complex.m_imag)
{
}

void Complex::print()
{
    cout << m_real << " + " << m_imag << " i" << endl;
    return;
}

int main()
{
    double real = 0.0, imag = 0.0;
    while (cin >> real >> imag)
    {
        Complex c(real, imag);
        c.print();
    }
    return 0;
}
