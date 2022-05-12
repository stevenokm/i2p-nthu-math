#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
    virtual void add_assign(string arg_s)
    {
    }
    virtual void sub_assign(string arg_s)
    {
    }
    virtual void mul_assign(string arg_s)
    {
    }
    virtual void div_assign(string arg_s)
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
    Integer &operator=(const Integer &arg_int)
    {
        m_int_value = arg_int.m_int_value;
        return *this;
    }
    double get_value() const
    {
        return (double)m_int_value;
    }
    string get_string() const
    {
        return to_string(m_int_value);
    }
    void set_value(string arg_int_value) // int version
    {
        stringstream ss(arg_int_value); // use operator>> to convert string to Integer
        ss >> m_int_value;
    }
    void add_assign(string arg_int_value) // int version
    {
        Integer num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 + num2;
    }
    void sub_assign(string arg_int_value) // int version
    {
        Integer num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 - num2;
    }
    void mul_assign(string arg_int_value) // int version
    {
        Integer num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 * num2;
    }
    void div_assign(string arg_int_value) // int version
    {
        Integer num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 / num2;
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
    double get_value() const
    {
        return m_after_decimal + (double)m_int_value;
    }
    string get_string() const
    {
        return to_string(Real::get_value());
    }
    void set_value(string arg_value) // double version
    {
        double temp_double;
        temp_double = stod(arg_value);
        m_int_value = (int)temp_double;
        m_after_decimal = temp_double - (double)m_int_value;
    }
    void add_assign(string arg_int_value) // int version
    {
        Real num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 + num2;
    }
    void sub_assign(string arg_int_value) // int version
    {
        Real num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 - num2;
    }
    void mul_assign(string arg_int_value) // int version
    {
        Real num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 * num2;
    }
    void div_assign(string arg_int_value) // int version
    {
        Real num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 / num2;
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
    friend Real operator+(const Real &arg_real1, const Real &arg_real2)
    {
        // call the Integer operator+ to add the Integer part
        Integer temp_integer((Integer)arg_real1 + (Integer)arg_real2);
        Real temp_real(arg_real1.m_after_decimal + arg_real2.m_after_decimal);
        temp_real.set_value(to_string(temp_integer.get_value() + temp_real.get_value()));
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
    double get_value() const // use the same function as Number to
                             // maintain the same interface
    {
        return m_imaginary_value;
    }
    string get_string() const
    {
        return to_string(m_imaginary_value) + "i";
    }
    void set_value(string arg_imaginary_value)
    {
        m_imaginary_value = stod(arg_imaginary_value);
    }
    friend ostream &operator<<(ostream &arg_os, const Imaginary &arg_imaginary)
    {
        arg_os << arg_imaginary.get_string();
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
    double get_value() const
    {
        cout << "not implemented" << endl;
        return 0.0;
    }
    string get_string() const
    {
        return Real::get_string() + " + " + Imaginary::get_string();
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
            Imaginary::set_value(arg_value.substr(plus_pos + 1, i_pos - plus_pos - 1));
        }
    }
    Complex reciprocal() const
    {
        double temp_real_value = Real::get_value();
        double temp_imaginary_value = Imaginary::get_value();
        double temp_denominator = temp_real_value * temp_real_value + temp_imaginary_value * temp_imaginary_value;
        Complex temp_complex(temp_real_value / temp_denominator, -temp_imaginary_value / temp_denominator);
        return temp_complex;
    }
    void add_assign(string arg_int_value) // int version
    {
        Complex num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 + num2;
    }
    void sub_assign(string arg_int_value) // int version
    {
        Complex num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 - num2;
    }
    void mul_assign(string arg_int_value) // int version
    {
        Complex num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 * num2;
    }
    void div_assign(string arg_int_value) // int version
    {
        Complex num1(*this), num2;
        num2.set_value(arg_int_value);
        *this = num1 / num2;
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
    friend Complex operator+(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex(arg_complex1.Real::get_value() + arg_complex2.Real::get_value(),
                             arg_complex1.Imaginary::get_value() + arg_complex2.Imaginary::get_value());
        return temp_complex;
    }
    friend Complex operator-(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex(arg_complex1.Real::get_value() - arg_complex2.Real::get_value(),
                             arg_complex1.Imaginary::get_value() - arg_complex2.Imaginary::get_value());
        return temp_complex;
    }
    friend Complex operator*(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex(arg_complex1.Real::get_value() * arg_complex2.Real::get_value() -
                                 arg_complex1.Imaginary::get_value() * arg_complex2.Imaginary::get_value(),
                             arg_complex1.Real::get_value() * arg_complex2.Imaginary::get_value() +
                                 arg_complex1.Imaginary::get_value() * arg_complex2.Real::get_value());
        return temp_complex;
    }
    friend Complex operator/(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex(arg_complex1 * arg_complex2.reciprocal());
        return temp_complex;
    }
};

// Number calculator class declaration
class Number_Calc
{
private:
    // define current value
    Number *m_curr_val_ptr;
    // define input value
    Number *m_input_val_ptr;
    // define operation
    // `+`, `-`, `*`, `/`, and `=`
    char m_op;
    // define value type
    // `(R)eal`, `(I)nterger`, `(C)omplex`
    char m_val_type;
    // define input status, turns `op` for true and turns `value` for false
    bool m_op_input;
    // calculate result
    void _calc_result()
    {
        switch (m_op)
        {
        case '+':
            m_curr_val_ptr->add_assign(m_input_val_ptr->get_string());
            break;
        case '-':
            m_curr_val_ptr->sub_assign(m_input_val_ptr->get_string());
            break;
        case '*':
            m_curr_val_ptr->mul_assign(m_input_val_ptr->get_string());
            break;
        case '/':
            m_curr_val_ptr->div_assign(m_input_val_ptr->get_string());
            break;
        case '=':
            m_curr_val_ptr->set_value(m_input_val_ptr->get_string());
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
    Number_Calc(const char &arg_type = 'C')
        : m_curr_val_ptr(NULL), m_input_val_ptr(NULL), m_op('='), m_op_input(false), m_val_type(arg_type)
    {
        switch (m_val_type)
        {
        case 'R':
            m_curr_val_ptr = new Real();
            m_input_val_ptr = new Real();
            break;
        case 'C':
            m_curr_val_ptr = new Complex();
            m_input_val_ptr = new Complex();
            break;
        case 'I':
            m_curr_val_ptr = new Integer();
            m_input_val_ptr = new Integer();
            break;
        default:
            cout << "Error: Invalid value type" << endl;
            break;
        }
    }

    // Copy constructor
    Number_Calc(const Number_Calc &arg_comp_calc)
        : m_op(arg_comp_calc.m_op), m_op_input(arg_comp_calc.m_op_input), m_val_type(arg_comp_calc.m_val_type)
    {
        switch (m_val_type)
        {
        case 'R':
            m_curr_val_ptr = new Real(*(Real *)arg_comp_calc.m_curr_val_ptr);
            m_input_val_ptr = new Real(*(Real *)arg_comp_calc.m_input_val_ptr);
            break;
        case 'C':
            m_curr_val_ptr = new Complex(*(Complex *)arg_comp_calc.m_curr_val_ptr);
            m_input_val_ptr = new Complex(*(Complex *)arg_comp_calc.m_input_val_ptr);
            break;
        case 'I':
            m_curr_val_ptr = new Integer(*(Integer *)arg_comp_calc.m_curr_val_ptr);
            m_input_val_ptr = new Integer(*(Integer *)arg_comp_calc.m_input_val_ptr);
            break;
        default:
            cout << "Error: Invalid value type" << endl;
            break;
        }
    }

    // Destructor
    ~Number_Calc()
    {
        delete m_curr_val_ptr;
        delete m_input_val_ptr;
    }

    // cin `>>` operator for set input value or operation
    friend istream &operator>>(istream &arg_is, Number_Calc &arg_comp_calc)
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
            arg_comp_calc.m_input_val_ptr->set_value(temp_string);
            arg_comp_calc.m_op_input = true;
            arg_comp_calc._calc_result();
        }
        return arg_is;
    }

    // cout `<<` operator for print calculator status
    // note: be careful about the format of output
    // cout `<<` operator for print calculator status
    friend ostream &operator<<(ostream &arg_os, const Number_Calc &arg_comp_calc)
    {
        arg_os << arg_comp_calc.m_curr_val_ptr->get_string();
        return arg_os;
    }
};

int main()
{
    // create an instance of the class for Integer
    Number_Calc calc_i('I');
    for (int i = 0; i < 3; i++)
    {
        cin >> calc_i;
        cout << calc_i << endl;
    }
    // create an instance of the class for Real
    Number_Calc calc_r('R');
    for (int i = 0; i < 3; i++)
    {
        cin >> calc_r;
        cout << calc_r << endl;
    }
    // create an instance of the class for Complex
    Number_Calc calc_c('C');
    for (int i = 0; i < 3; i++)
    {
        cin >> calc_c;
        cout << calc_c << endl;
    }
}