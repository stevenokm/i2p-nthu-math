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
    virtual void set_value(string arg_s)
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
    void set_value(string arg_int_value) // int version
    {
        stringstream ss(arg_int_value); // use operator>> to convert string to Integer
        ss >> m_int_value;
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
    void set_value(string arg_value) // double version
    {
        double temp_double;
        temp_double = stod(arg_value);
        m_int_value = (int)temp_double;
        m_after_decimal = temp_double - (double)m_int_value;
    }
    friend ostream &operator<<(ostream &arg_os, const Real &arg_real)
    {
        arg_os << (double)arg_real;
        return arg_os;
    }
    friend istream &operator>>(istream &arg_is, Real &arg_real)
    {
        string temp_string;
        arg_is >> temp_string;
        arg_real.set_value(temp_string);
        return arg_is;
    }
};

class Complex : public Real
{
private:
    Real m_imaginary;

public:
    Complex(double arg_real_value = 0.0,
            double arg_imaginary_value = 0.0)
        : Real(arg_real_value),
          m_imaginary(arg_imaginary_value)
    {
    }
    Complex(const Complex &arg_complex)
        : Real(arg_complex),
          m_imaginary(arg_complex.m_imaginary)
    {
    }
    double get_value() const
    {
        cout << "not implemented" << endl;
        return 0.0;
    }
    string get_string() const
    {
        return to_string((double)*this) + " + " + m_imaginary.get_string() + "i";
    }
    Complex &operator=(const Complex &arg_complex)
    {
        Real::operator=(arg_complex);
        m_imaginary = arg_complex.m_imaginary;
        return *this;
    }
    void set_value(string arg_value) // complex version
    {
        size_t plus_pos = arg_value.find("+");
        if (plus_pos != string::npos)
        {
            Real::set_value(arg_value.substr(0, plus_pos));
        }
        size_t i_pos = arg_value.find("i");
        if (i_pos != string::npos)
        {
            m_imaginary.set_value(arg_value.substr(plus_pos + 1, i_pos - plus_pos - 1));
        }
    }
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_complex)
    {
        arg_os << arg_complex.get_string();
        return arg_os;
    }
    friend istream &operator>>(istream &arg_is, Complex &arg_complex)
    {
        string temp_string;
        getline(arg_is, temp_string);
        arg_complex.set_value(temp_string);
        return arg_is;
    }
};

int main()
{
    Number *p[3];

    p[0] = new Integer(10);
    p[1] = new Real(10.5);
    p[2] = new Complex(10.5, 3.5);

    cout << "virtual function call" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "p[" << i << "] = " << p[i]->get_string() << endl;
    }

    cout << "address of object" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "p[" << i << "] = " << p[i] << endl;
    }

    p[0]->set_value("20");
    p[1]->set_value("20.5");
    p[2]->set_value("20.5 + 3.5i");

    cout << "set value by virtual function" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "p[" << i << "] = " << p[i]->get_string() << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete p[i];
    }
}