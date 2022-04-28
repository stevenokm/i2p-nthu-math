#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

class Complex_Calc;

class Complex
{
private:
    double m_real;
    double m_imag;

public:
    Complex(const double &arg_real = 0.0, const double &arg_imag = 0.0);
    Complex(const Complex &arg_c);
    Complex &operator=(const Complex &arg_c);
    Complex &operator+=(const Complex &arg_c);
    Complex &operator-=(const Complex &arg_c);
    Complex &operator*=(const Complex &arg_c);
    Complex &operator/=(const Complex &arg_c);
    Complex operator+(const Complex &arg_c) const
    {
        Complex res(*this);
        res += arg_c;
        return res;
    }
    Complex operator-(const Complex &arg_c) const
    {
        Complex res(*this);
        res -= arg_c;
        return res;
    }
    Complex operator*(const Complex &arg_c) const
    {
        Complex res(*this);
        res *= arg_c;
        return res;
    }
    Complex operator/(const Complex &arg_c) const
    {
        Complex res(*this);
        res /= arg_c;
        return res;
    }
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_c);
    friend istream &operator>>(istream &arg_is, Complex &arg_c);
    friend class Complex_Calc;
};

Complex::Complex(const double &arg_real, const double &arg_imag)
    : m_real(arg_real), m_imag(arg_imag) {}

Complex::Complex(const Complex &arg_point)
    : m_real(arg_point.m_real), m_imag(arg_point.m_imag) {}

Complex &Complex::operator=(const Complex &arg_c)
{
    this->m_real = arg_c.m_real;
    this->m_imag = arg_c.m_imag;
    return *this;
}

Complex &Complex::operator+=(const Complex &arg_c)
{
    this->m_real += arg_c.m_real;
    this->m_imag += arg_c.m_imag;
    return *this;
}
Complex &Complex::operator-=(const Complex &arg_c)
{
    this->m_real -= arg_c.m_real;
    this->m_imag -= arg_c.m_imag;
    return *this;
}
Complex &Complex::operator*=(const Complex &arg_c)
{
    double _real = this->m_real, _imag = this->m_imag;
    this->m_real = (_real * arg_c.m_real) - (_imag * arg_c.m_imag);
    this->m_imag = (_real * arg_c.m_imag) + (_imag * arg_c.m_real);
    return *this;
}
Complex &Complex::operator/=(const Complex &arg_c)
{
    double _real = this->m_real, _imag = this->m_imag;
    this->m_real = ((_real * arg_c.m_real) + (_imag * arg_c.m_imag)) 
        / ((arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag));
    this->m_imag = ((-_real * arg_c.m_imag) + (_imag * arg_c.m_real)) 
        / ((arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag));
    return *this;
}

std::ostream &operator<<(std::ostream &arg_os, const Complex &arg_point)
{
    if (arg_point.m_imag == 0)
    {
        arg_os << arg_point.m_real;
        return arg_os;
    }
    else if (arg_point.m_imag < 0)
    {
        arg_os << arg_point.m_real << " - " << -arg_point.m_imag << "i ";
        return arg_os;
    }
    else
    {
        arg_os << arg_point.m_real << " + " << arg_point.m_imag << "i ";
        return arg_os;
    }
}

std::istream &operator>>(std::istream &arg_is, Complex &arg_point)
{
    string str_x, str_y, temp;

    if (getline(arg_is, str_x, ' '))
    {
        if (getline(arg_is, str_y, ' '))
        {
            arg_point.m_real = stod(str_x);
            arg_point.m_imag = stod(str_y);
        }
    }

    return arg_is;
}

class Complex_Calc
{
private:
    Complex m_curr_val;
    Complex m_input_val;
    char m_op, op;
    int process = 0;

    void _calc_result()
    {
        switch (m_op)
        {
        case '+':
            m_curr_val += m_input_val;
            break;
        case '-':
            m_curr_val -= m_input_val;
            break;
        case '*':
            m_curr_val *= m_input_val;
            break;
        case '/':
            if (m_input_val.m_real == 0 && m_input_val.m_imag == 0)
            {
                error_and_exit();
            }
            else
            {
                m_curr_val /= m_input_val;
                break;
            }
        case '=':
            m_curr_val = m_input_val;
            break;
        }
    }
    void _add()
    {
        m_op = '+';
    }
    void _sub()
    {
        m_op = '-';
    }
    void _mul()
    {
        m_op = '*';
    }
    void _div()
    {
        m_op = '/';
    }
    void _assign()
    {
        m_op = '=';
    }

public:
    Complex_Calc();
    Complex_Calc(const Complex_Calc &arg_int_calc);
    ~Complex_Calc(){};

    void error_and_exit();

    void set_input(const string &arg_input);

    friend ostream &operator<<(ostream &arg_os, const Complex_Calc &arg_comp_calc);
};

Complex_Calc::Complex_Calc() : m_curr_val(), m_input_val(), m_op('=')
{
}

Complex_Calc::Complex_Calc(const Complex_Calc &arg_int_calc)
    : m_curr_val(arg_int_calc.m_curr_val),
      m_input_val(arg_int_calc.m_input_val),
      m_op(arg_int_calc.m_op)
{
}

bool check_complex(const string &input)
{
    string temp_str;
    vector<string> vec;
    stringstream terms_extractor(input);
    while (terms_extractor >> temp_str)
    {
        vec.push_back(temp_str);
    }
    if (vec.size() == 2)
    {
        if ((!isdigit(vec[0][0]) && vec[0][0] != '-') 
            || (!isdigit(vec[1][0]) && vec[1][0] != '-'))
        {
            return false;
        }

        for (int i = 1; i < vec[0].size(); i++)
        {
            if (isdigit(vec[0][i]) || vec[0][i] == '.')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        for (int i = 1; i < vec[1].size(); i++)
        {
            if (isdigit(vec[1][i]) || vec[1][i] == '.')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

bool check_op(const string &input)
{
    if (input == "+" || input == "-" || input == "*" || input == "/")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Complex_Calc::set_input(const string &arg_input)
{

    if ((process % 2 == 1) && (check_op(arg_input) == true))
    {
        op = arg_input[0];
    }
    else if ((process % 2 == 0) && (check_complex(arg_input) == true))
    {
        switch (op)
        {
        case '+':
            _add();
            break;
        case '-':
            _sub();
            break;
        case '*':
            _mul();
            break;
        case '/':
            _div();
            break;
        case '=':
            _assign();
            break;
        }
        stringstream ss(arg_input);
        ss >> m_input_val;
        _calc_result();
    }

    else
    {
        error_and_exit();
    }
    process = process + 1;
}

void Complex_Calc::error_and_exit()
{
    cout << "Error: Invalid input" << endl;
    exit(1);
}

std::ostream &operator<<(ostream &arg_os, const Complex_Calc &arg_comp_calc)
{
    arg_os << arg_comp_calc.m_curr_val;
    return arg_os;
}
// main function

int main()
{
    // create an instance of the class
    Complex_Calc calc;
    string input;
    while (getline(cin, input))
    {
        calc.set_input(input);
        cout << calc << endl;
    }
}
