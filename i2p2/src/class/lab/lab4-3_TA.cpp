#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void prompt_invalid_input();

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
    Complex(const double &arg_real = 0.0, const double &arg_imag = 0.0)
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
    // add function
    Complex add(const Complex &arg_c)
    {
        Complex c;
        c.m_real = m_real + arg_c.m_real;
        c.m_imag = m_imag + arg_c.m_imag;
        return c;
    }
    // subtract function
    Complex sub(const Complex &arg_c)
    {
        Complex c;
        c.m_real = m_real - arg_c.m_real;
        c.m_imag = m_imag - arg_c.m_imag;
        return c;
    }
    // multiply function
    Complex mul(const Complex &arg_c)
    {
        Complex c;
        c.m_real = m_real * arg_c.m_real - m_imag * arg_c.m_imag;
        c.m_imag = m_real * arg_c.m_imag + m_imag * arg_c.m_real;
        return c;
    }
    // divide function
    Complex div(const Complex &arg_c)
    {
        if (arg_c.m_real == 0 && arg_c.m_imag == 0)
            prompt_invalid_input();

        Complex c;
        c.m_real = (m_real * arg_c.m_real + m_imag * arg_c.m_imag) 
                    / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        c.m_imag = (m_imag * arg_c.m_real - m_real * arg_c.m_imag) 
                    / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        return c;
    }
    // parse function
    // note: use `stringstream` and `>>` to parse the string to double
    // and use `stringstream::fail()` to check the conversion is successful
    bool parse(const string &arg_str)
    {
        // Check if the number of tokens = 2
        for (int i = 0, n = 0; i < arg_str.length(); i++)
        {
            if (arg_str[i] == ' ')
                n++;
            if (n > 1 || (n == 0 && i == arg_str.length() - 1))
                return false;
        }

        stringstream ss(arg_str);
        double input_real, input_imag;

        ss >> input_real;
        if (ss.fail())
        {
            return false;
        }

        ss >> input_imag;
        if (ss.fail())
        {
            return false;
        }
        m_real = input_real;
        m_imag = input_imag;
        return ss.eof();
    }
};
// parse op global function
char parse_op(const string &arg_str)
{
    switch (arg_str[0])
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return arg_str[0];
    default:
        return '\0'; // invalid op
    }
}
// prompt invalid input and exit
void prompt_invalid_input()
{
    cout << "Error: Invalid input" << endl;
    exit(1);
}
int main()
{
    string input;
    Complex result_complex;
    char op = ' ';                   // default op is ' '
    bool is_process_continue = true; // current process should be continued or not
    while (is_process_continue)
    {
        // get the first input
        getline(cin, input);
        // check is not end of input
        if (input.empty() || cin.eof())
        {
            prompt_invalid_input();
        }
        // check the input is a valid complex number
        Complex input_complex;
        bool is_valid_complex = input_complex.parse(input);
        if (!is_valid_complex)
        {
            prompt_invalid_input();
        }
        // calculate the result
        switch (op)
        {
        case '+':
            result_complex = result_complex.add(input_complex);
            break;
        case '-':
            result_complex = result_complex.sub(input_complex);
            break;
        case '*':
            result_complex = result_complex.mul(input_complex);
            break;
        case '/':
            result_complex = result_complex.div(input_complex);
            break;
        case ' ':
            result_complex = input_complex;
            break;
        default:
            prompt_invalid_input();
        }
        // get the second input
        getline(cin, input);
        // check is end of input or not
        if (input.empty() || cin.eof())
        {
            is_process_continue = false;
        }
        // if not end of input, check the input is a valid operator
        else
        {
            op = parse_op(input);
            if (op == '\0')
            {
                prompt_invalid_input();
            }
        }
    }
    result_complex.print();
    return 0;
}
