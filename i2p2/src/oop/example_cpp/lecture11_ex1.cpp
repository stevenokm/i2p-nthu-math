#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Number
{
public:
    Number()
    {
    }
    virtual double get_value() const
    {
        return 0.0;
    }
    virtual string get_string() const
    {
        return "";
    }
    virtual void set_value(double value)
    {
    }
};

class Integer : public Number
{
protected:
    int m_int_value;

public:
    Integer(int arg_int_value = 0) : m_int_value(arg_int_value)
    {
    }
    Integer(const Integer &arg_int) : m_int_value(arg_int.m_int_value)
    {
    }
    operator int() const
    {
        return m_int_value;
    }
    operator double() const
    {
        return (double)m_int_value;
    }
    double get_value() const
    {
        return (double)m_int_value;
    }
    string get_string() const
    {
        return to_string(m_int_value);
    }
    Integer &operator=(const Integer &arg_int)
    {
        m_int_value = arg_int.m_int_value;
        return *this;
    }
    void set_value(int arg_int_value) // int version
    {
        m_int_value = arg_int_value;
    }
    friend ostream &operator<<(ostream &arg_os, const Integer &arg_integer)
    {
        arg_os << arg_integer.get_string();
        return arg_os;
    }
    friend istream &operator>>(istream &arg_is, Integer &arg_integer)
    {
        arg_is >> arg_integer.m_int_value;
        return arg_is;
    }
};

// Real is a Integer
class Real : public Integer
{
protected:
    double m_after_decimal;

public:
    Real(double arg_value = 0.0) : Integer((int)arg_value),
                                   m_after_decimal(arg_value - (int)arg_value)
    {
    }
    Real(const Real &arg_real) : Integer(arg_real),
                                 m_after_decimal(arg_real.m_after_decimal)
    {
    }
    operator double() const
    {
        return m_after_decimal + (double)m_int_value;
    }
    double get_value() const
    {
        return m_after_decimal + (double)m_int_value;
    }
    string get_string() const
    {
        return to_string(Real::get_value());
    }
    Real &operator=(const Real &arg_real)
    {
        m_int_value = arg_real.m_int_value;
        m_after_decimal = arg_real.m_after_decimal;
        return *this;
    }
    void set_value(double arg_value) // double version
    {
        m_int_value = (int)arg_value;
        m_after_decimal = arg_value - m_int_value;
    }
    friend ostream &operator<<(ostream &arg_os, const Real &arg_real)
    {
        arg_os << (double)arg_real;
        return arg_os;
    }
    friend istream &operator>>(istream &arg_is, Real &arg_real)
    {
        double temp_double;
        arg_is >> temp_double;
        arg_real.set_value(temp_double);
        return arg_is;
    }
};

int main()
{
    Number *p[2];

    p[0] = new Integer(10);
    p[1] = new Real(10.5);

    cout << "virtual function call" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "p[" << i << "] = " << p[i]->get_string() << endl;
    }

    cout << "address of object" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "p[" << i << "] = " << p[i] << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete p[i];
    }
}