#include <iostream>

using namespace std;

class Complex
{
private:
    // data members
    // save the real and imaginary parts of the complex number
    // with `double` precision

public:
    // Constructor, initializes real and imaginary parts
    // hint: as like as `modify` function in examples
    // but use default constructor to implement

    // print function
    // note: be careful about the format of output
    // especially the ` ` and newline (endl)
    void print();
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