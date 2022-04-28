#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Complex_Calc;

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
    Complex(const double &arg_real = 0.0, const double &arg_imag = 0.0)
    {
        m_real = arg_real;
        m_imag = arg_imag;
    }
    // Copy constructor
    Complex(const Complex &arg_c)
    {
        m_real = arg_c.m_real;
        m_imag = arg_c.m_imag;
    }
    // assignment operator
    Complex &operator=(const Complex &arg_c)
    {
        m_imag = arg_c.m_imag;
        m_real = arg_c.m_real;
        return *this;
    }
    // add assignment operator
    Complex &operator+=(const Complex &arg_c)
    {
        m_imag = m_imag + arg_c.m_imag;
        m_real = m_real + arg_c.m_real;
        return *this;
    }
    // subtract assignment operator
    Complex &operator-=(const Complex &arg_c)
    {
        m_imag = m_imag - arg_c.m_imag;
        m_real = m_real - arg_c.m_real;
        return *this;
    }
    // multiply assignment operator
    Complex &operator*=(const Complex &arg_c)
    {
        Complex p;
        p.m_real = (m_real * arg_c.m_real) - (m_imag * arg_c.m_imag);
        p.m_imag = (m_real * arg_c.m_imag) + (m_imag * arg_c.m_real);
        m_imag = p.m_imag;
        m_real = p.m_real;
        return *this;
    }
    // divide assignment operator
    Complex &operator/=(const Complex &arg_c)
    {
        Complex p;
        p.m_real = (arg_c.m_real * m_real + m_imag * arg_c.m_imag) 
            / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        p.m_imag = (arg_c.m_real * m_imag - m_real * arg_c.m_imag) 
            / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        m_imag = p.m_imag;
        m_real = p.m_real;
        return *this;
    }
    // add function
    Complex operator+(const Complex &arg_c) const
    {
        Complex p;
        p.m_imag = m_imag + arg_c.m_imag;
        p.m_real = m_real + arg_c.m_real;
        return p;
    }
    // subtract function
    Complex operator-(const Complex &arg_c) const
    {
        Complex p;
        p.m_imag = m_imag - arg_c.m_imag;
        p.m_real = m_real - arg_c.m_real;
        return p;
    }
    // multiply function
    Complex operator*(const Complex &arg_c) const
    {
        Complex p;
        p.m_real = (m_real * arg_c.m_real) - (m_imag * arg_c.m_imag);
        p.m_imag = (m_real * arg_c.m_imag) + (m_imag * arg_c.m_real);
        return p;
    }
    // divide function
    Complex operator/(const Complex &arg_c) const
    {
        Complex p;
        p.m_real = (arg_c.m_real * m_real + m_imag * arg_c.m_imag) 
            / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        p.m_imag = (arg_c.m_real * m_imag - m_real * arg_c.m_imag) 
            / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        return p;
    }

    friend ostream &operator<<(ostream &arg_os, const Complex &arg_c)
    {
        if (arg_c.m_imag == 0)
            arg_os << arg_c.m_real;
        else if (arg_c.m_imag > 0)
            arg_os << arg_c.m_real << " + " << arg_c.m_imag << 'i';
        else
            arg_os << arg_c.m_real << " - " << (-1) * (arg_c.m_imag) << 'i';
        return arg_os;
    }

    friend istream &operator>>(istream &arg_is, Complex &arg_c)
    {
        string str_x, str_y, temp;

        if (getline(arg_is, str_x, ' '))
        {
            if (getline(arg_is, str_y, '\n'))
            {
                arg_c.m_real = stod(str_x);
                arg_c.m_imag = stod(str_y);
            }
        }

        return arg_is;
    }
    friend class Complex_Calc;
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
    string m_op;
    // calculate result
    void _calc_result()
    {
        switch (m_op[0])
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
        return;
    }
    // operation functions
    // add the input value to the current value
    void _add()
    {
        m_curr_val += m_input_val;
        return;
    }
    // subtract the input value from the current value
    void _sub()
    {
        m_curr_val -= m_input_val;
        return;
    }
    // multiply the input value with the current value
    void _mul()
    {
        m_curr_val *= m_input_val;
        return;
    }
    // divide the current value by the input value
    void _div()
    {
        m_curr_val /= m_input_val;
        return;
    }
    // assign the input value to the current value
    void _assign()
    {
        m_curr_val = m_input_val;
        return;
    }

public:
    // Constructor
    Complex_Calc(const Complex &arg_curr_val = Complex(0, 0),
                 const Complex &arg_input_val = Complex(0, 0),
                 const string op = "=")
    {
        m_curr_val = arg_curr_val;
        m_input_val = arg_input_val;
        m_op = op;
    }
    //(const Complex &arg_curr_val = (0, 0),
    // const Complex &arg_input_val = (0,0),
    // const char op = '=')
    // Copy constructor
    Complex_Calc(const Complex_Calc &arg_int_calc)
    {
        m_curr_val = arg_int_calc.m_curr_val;
        m_input_val = arg_int_calc.m_input_val;
        m_op = arg_int_calc.m_op;
    }

    // Destructor
    ~Complex_Calc(){}; // no need to do anything

    // set input value or operation
    void set_input(const string &arg_input);

    // cout `<<` operator for print calculator status
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const Complex_Calc &arg_comp_calc)
    {
        arg_os << arg_comp_calc.m_curr_val;
        return arg_os;
    }
};

// parse the test cases, do not modify belows
void error_and_exit()
{
    cout << "Error: Invalid input" << endl;
    exit(1);
}
void Complex_Calc::set_input(const string &arg_input)
{
    // input is empty, read again
    if (arg_input.empty())
    {
        error_and_exit();
        return;
    }
    // input is a operation
    else if (arg_input == "+" || arg_input == "-" 
        || arg_input == "*" || arg_input == "/" || arg_input == "=")
    {
        m_op = arg_input;
    }
    // input is a complex number
    // as the same as the user type a number
    // it performs as the same as the user pressed the '=' button
    // if the input is the first input
    // thus, we initialize the m_op to '='
    else
    {
        stringstream ss(arg_input);
        ss >> m_input_val;
        if (m_input_val.m_imag == 0 && m_input_val.m_real == 0 && m_op == "/")
        {
            error_and_exit();
        }
        _calc_result();
    }
}

// main function
bool test(string input, int n)
{
    if (n % 2 == 0)
    {
        int t = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == ' ')
            {
                t++;
            }
        }
        if (t != 1)
        {
            return false;
        }

        double real, imag;
        stringstream ss(input);
        ss >> real;

        if (ss.fail()) // if fail return false
        {
            return false;
        }

        ss >> imag;
        if (ss.fail())
        {
            return false;
        }

        if (!ss.eof()) // if it is not the end of file return false
        {
            return false;
        }
    }
    else
    {
        if (input.size() != 1)
        {
            return false;
        }
        else if (input[0] != '+' && input[0] != '-' 
            && input[0] != '*' && input[0] != '/')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n = 0;
    // create an instance of the class
    Complex_Calc calc;
    string input;
    while (getline(cin, input))
    {
        if (!(test(input, n)))
        {
            error_and_exit();
        }
        calc.set_input(input);
        cout << calc << endl;
        n++;
    }
}
