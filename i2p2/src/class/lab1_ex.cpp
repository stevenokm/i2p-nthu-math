#include <iostream>

using namespace std;

class Complex
{
public:
    int real;
    int imag;
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real << " + " << c.imag << " i";
        return os;
    }
    void print() const
    {
        // TODO: implement this function
        // Hint: use cout to print the complex number
    }
    Complex &operator+(const Complex &c)
    {
        real += c.real;
        imag += c.imag;
        return *this;
    }
};

int main()
{
    Complex a, b, c;

    a.real = 1;
    a.imag = 2;
    cout << "(a) = " << a << endl;

    b.real = 3;
    b.imag = -4;
    cout << "(b) = ";
    b.print();
    cout << endl;

    c = a + b;
    cout << "(c) = (a) + (b) = " << c << endl;

    return 0;
}