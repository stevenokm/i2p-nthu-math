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
    Complex(double arg_real = 0.0, double arg_imag = 0.0)
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
};
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
