#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Integer
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
    Integer &operator=(const Integer &arg_int)
    {
        m_int_value = arg_int.m_int_value;
        return *this;
    }
    void set_int_value(int arg_int_value)
    {
        m_int_value = arg_int_value;
    }
    friend ostream &operator<<(ostream &arg_os, const Integer &arg_integer)
    {
        arg_os << arg_integer.m_int_value;
        return arg_os;
    }
    friend istream &operator>>(istream &arg_is, Integer &arg_integer)
    {
        arg_is >> arg_integer.m_int_value;
        return arg_is;
    }
    friend Integer operator+(const Integer &arg_integer1, const Integer &arg_integer2)
    {
        Integer temp_integer(arg_integer1.m_int_value + arg_integer2.m_int_value);
        return temp_integer;
    }
    friend Integer operator-(const Integer &arg_integer1, const Integer &arg_integer2)
    {
        Integer temp_integer(arg_integer1.m_int_value - arg_integer2.m_int_value);
        return temp_integer;
    }
    friend Integer operator*(const Integer &arg_integer1, const Integer &arg_integer2)
    {
        Integer temp_integer(arg_integer1.m_int_value * arg_integer2.m_int_value);
        return temp_integer;
    }
    friend Integer operator/(const Integer &arg_integer1, const Integer &arg_integer2)
    {
        Integer temp_integer(arg_integer1.m_int_value / arg_integer2.m_int_value);
        return temp_integer;
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
    Real &operator=(const Real &arg_real)
    {
        m_int_value = arg_real.m_int_value;
        m_after_decimal = arg_real.m_after_decimal;
        return *this;
    }
    void set_real_value(double arg_value)
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
        arg_real.set_real_value(temp_double);
        return arg_is;
    }
    friend Real operator+(const Real &arg_real1, const Real &arg_real2)
    {
        // call the Integer operator+ to add the Integer part
        Integer temp_integer((Integer)arg_real1 + (Integer)arg_real2);
        Real temp_real(arg_real1.m_after_decimal + arg_real2.m_after_decimal);
        temp_real.set_int_value((int)temp_integer + (int)temp_real);
        return temp_real;
    }
    friend Real operator-(const Real &arg_real1, const Real &arg_real2)
    {
        Real temp_real((double)arg_real1 - (double)arg_real2);
        return temp_real;
    }
    friend Real operator*(const Real &arg_real1, const Real &arg_real2)
    {
        Real temp_real((double)arg_real1 * (double)arg_real2);
        return temp_real;
    }
    friend Real operator/(const Real &arg_real1, const Real &arg_real2)
    {
        Real temp_real((double)arg_real1 / (double)arg_real2);
        return temp_real;
    }
};

class Imaginary
{
protected:
    double m_imaginary_value;

public:
    Imaginary(double arg_imaginary_value = 0.0) : m_imaginary_value(arg_imaginary_value)
    {
    }
    Imaginary(const Imaginary &arg_imaginary) : m_imaginary_value(arg_imaginary.m_imaginary_value)
    {
    }
    Imaginary &operator=(const Imaginary &arg_imaginary)
    {
        m_imaginary_value = arg_imaginary.m_imaginary_value;
        return *this;
    }
    double get_imaginary_value() const
    {
        return m_imaginary_value;
    }
    void set_imaginary_value(double arg_imaginary_value)
    {
        m_imaginary_value = arg_imaginary_value;
    }
    friend ostream &operator<<(ostream &arg_os, const Imaginary &arg_imaginary)
    {
        arg_os << arg_imaginary.m_imaginary_value << "i";
        return arg_os;
    }
    friend Imaginary operator+(const Imaginary &arg_imaginary1, const Imaginary &arg_imaginary2)
    {
        Imaginary temp_imaginary(arg_imaginary1.m_imaginary_value + arg_imaginary2.m_imaginary_value);
        return temp_imaginary;
    }
    friend Imaginary operator-(const Imaginary &arg_imaginary1, const Imaginary &arg_imaginary2)
    {
        Imaginary temp_imaginary(arg_imaginary1.m_imaginary_value - arg_imaginary2.m_imaginary_value);
        return temp_imaginary;
    }
};

class Complex : public Real, public Imaginary
{
public:
    Complex(double arg_real_value = 0.0,
            double arg_imaginary_value = 0.0)
        : Real(arg_real_value),
          Imaginary(arg_imaginary_value)
    {
    }
    Complex(const Complex &arg_complex)
        : Real(arg_complex),
          Imaginary(arg_complex)
    {
    }
    Complex &operator=(const Complex &arg_complex)
    {
        Real::operator=(arg_complex);
        Imaginary::operator=(arg_complex);
        return *this;
    }
    Complex reciprocal() const
    {
        Complex temp_complex(*this);
        double temp_real_value = temp_complex;
        double temp_imaginary_value = temp_complex.get_imaginary_value();
        double temp_denominator = temp_real_value * temp_real_value + temp_imaginary_value * temp_imaginary_value;
        temp_complex.set_real_value(temp_real_value / temp_denominator);
        temp_complex.set_imaginary_value(-temp_imaginary_value / temp_denominator);
        return temp_complex;
    }
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_complex)
    {
        arg_os << (Real)arg_complex << " + " << (Imaginary)arg_complex;
        return arg_os;
    }
    friend istream &operator>>(istream &arg_is, Complex &arg_complex)
    {
        string temp_string;
        getline(arg_is, temp_string);
        size_t plus_pos = temp_string.find("+");
        if (plus_pos != string::npos)
        {
            arg_complex.set_real_value(atof(temp_string.substr(0, plus_pos).c_str()));
        }
        size_t i_pos = temp_string.find("i");
        if (i_pos != string::npos)
        {
            arg_complex.set_imaginary_value(
                atof(temp_string.substr(plus_pos + 1, i_pos - plus_pos - 1)
                         .c_str()));
        }
        return arg_is;
    }
    friend Complex operator+(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex((double)arg_complex1 + (double)arg_complex2,
                             arg_complex1.get_imaginary_value() + arg_complex2.get_imaginary_value());
        return temp_complex;
    }
    friend Complex operator-(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex((double)arg_complex1 - (double)arg_complex2,
                             arg_complex1.get_imaginary_value() - arg_complex2.get_imaginary_value());
        return temp_complex;
    }
    friend Complex operator*(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex((double)arg_complex1 * (double)arg_complex2 -
                                 arg_complex1.get_imaginary_value() * arg_complex2.get_imaginary_value(),
                             (double)arg_complex1 * arg_complex2.get_imaginary_value() +
                                 arg_complex1.get_imaginary_value() * (double)arg_complex2);
        return temp_complex;
    }
    friend Complex operator/(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex(arg_complex1 * arg_complex2.reciprocal());
        return temp_complex;
    }
};

// Complex calculator class declaration
class Complex_Calc
{
private:
    // define current value
    Complex m_curr_val;
    // define input value
    Complex m_input_val;
    // define operation
    // `+`, `-`, `*`, `/`, and `=`
    char m_op;
    // define input status, turns `op` for true and turns `value` for false
    bool m_op_input;
    // calculate result
    void _calc_result()
    {
        switch (m_op)
        {
        case '+':
            m_curr_val = m_curr_val + m_input_val;
            break;
        case '-':
            m_curr_val = m_curr_val - m_input_val;
            break;
        case '*':
            m_curr_val = m_curr_val * m_input_val;
            break;
        case '/':
            m_curr_val = m_curr_val / m_input_val;
            break;
        case '=':
            m_curr_val = m_input_val;
            break;
        default:
            break;
        }
    }
    // operation functions
    // set activation op to add
    void _add()
    {
        m_op = '+';
        m_op_input = false;
    }
    // set activation op to subtract
    void _sub()
    {
        m_op = '-';
        m_op_input = false;
    }
    // set activation op to multiply
    void _mul()
    {
        m_op = '*';
        m_op_input = false;
    }
    // set activation op to divide
    void _div()
    {
        m_op = '/';
        m_op_input = false;
    }
    // set activation op to assign
    void _assign()
    {
        m_op = '=';
        m_op_input = false;
    }

public:
    // Constructor
    Complex_Calc()
        : m_curr_val(), m_input_val(), m_op('='), m_op_input(false)
    {
    }

    // Copy constructor
    Complex_Calc(const Complex_Calc &arg_comp_calc)
        : m_curr_val(arg_comp_calc.m_curr_val), m_input_val(arg_comp_calc.m_input_val),
          m_op(arg_comp_calc.m_op), m_op_input(arg_comp_calc.m_op_input)
    {
    }

    // Destructor
    ~Complex_Calc(){}; // no need to do anything

    // cin `>>` operator for set input value or operation
    friend istream &operator>>(istream &arg_is, Complex_Calc &arg_comp_calc)
    {
        string temp_string;
        getline(arg_is, temp_string);
        if (temp_string == "+")
        {
            arg_comp_calc._add();
        }
        else if (temp_string == "-")
        {
            arg_comp_calc._sub();
        }
        else if (temp_string == "*")
        {
            arg_comp_calc._mul();
        }
        else if (temp_string == "/")
        {
            arg_comp_calc._div();
        }
        else if (temp_string == "=")
        {
            arg_comp_calc._assign();
        }
        else
        {
            stringstream temp_string_stream(temp_string);
            temp_string_stream >> arg_comp_calc.m_input_val;
            arg_comp_calc.m_op_input = true;
            arg_comp_calc._calc_result();
        }
        return arg_is;
    }

    // cout `<<` operator for print calculator status
    // note: be careful about the format of output
    // cout `<<` operator for print calculator status
    friend ostream &operator<<(ostream &arg_os, const Complex_Calc &arg_comp_calc)
    {
        arg_os << arg_comp_calc.m_curr_val;
        return arg_os;
    }
};

int main()
{
    // create an instance of the class
    Complex_Calc calc;
    while (cin >> calc)
    {
        cout << calc << endl;
    }
}