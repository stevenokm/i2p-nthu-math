#include <iostream>

using namespace std;

class Integer
{
private:
    int m_int_value;

public:
    Integer(int arg_int_value)
    {
        m_int_value = arg_int_value;
    }
    int get_int_value()
    {
        return m_int_value;
    }
    void set_int_value(int arg_int_value)
    {
        m_int_value = arg_int_value;
    }
};

class Real : public Integer
{
protected:
    double m_after_decimal;

public:
    Real(double arg_value) : Integer((int)arg_value),
                             m_after_decimal(arg_value - (int)arg_value)
    {
    }
    double get_real_value()
    {
        return m_after_decimal + get_int_value();
    }
    void set_real_value(double arg_value)
    {
        set_int_value((int)arg_value);
        m_after_decimal = arg_value - (int)arg_value;
    }
};

class Imaginary
{
protected:
    double m_imaginary_value;

public:
    Imaginary(double arg_imaginary_value)
    {
        m_imaginary_value = arg_imaginary_value;
    }
    double get_imaginary_value()
    {
        return m_imaginary_value;
    }
    void set_imaginary_value(double arg_imaginary_value)
    {
        m_imaginary_value = arg_imaginary_value;
    }
};

class Complex : public Real, public Imaginary
{
public:
    Complex(double arg_real_value,
            double arg_imaginary_value)
        : Real(arg_real_value),
          Imaginary(arg_imaginary_value)
    {
    }
    void print_complex_value()
    {
        cout << get_real_value() << " + " << m_imaginary_value << "i" << endl;
    }
};

int main()
{
    Complex c(1.5, 2.5);
    c.print_complex_value();
    c.set_real_value(3.5);
    c.set_imaginary_value(4.5);
    c.print_complex_value();
    return 0;
}