#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Complex
{
private:
    double m_real;
    double m_imag;

public:
    Complex(double arg_real = 0.0, double arg_imag = 0.0)
    {
        m_real = arg_real;
        m_imag = arg_imag;
    }
    void print()
    {
        cout << m_real << " + " << m_imag << " i\n";
    };
    Complex add(Complex &arg_c)
    {
        Complex temp;
        temp.m_real = m_real + arg_c.m_real;
        temp.m_imag = m_imag + arg_c.m_imag;
        return temp;
    };
    Complex sub(Complex &arg_c)
    {
        Complex temp;
        temp.m_real = m_real - arg_c.m_real;
        temp.m_imag = m_imag - arg_c.m_imag;
        return temp;
    };
    Complex mul(Complex &arg_c)
    {
        Complex temp;
        temp.m_real = m_real * arg_c.m_real - m_imag * arg_c.m_imag;
        temp.m_imag = m_real * arg_c.m_imag + m_imag * arg_c.m_real;
        return temp;
    };
    Complex div(Complex &arg_c)
    {
        Complex temp;
        temp.m_real = (m_real * arg_c.m_real + m_imag * arg_c.m_imag) 
                    / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        temp.m_imag = (m_imag * arg_c.m_real - m_real * arg_c.m_imag) 
                    / (arg_c.m_real * arg_c.m_real + arg_c.m_imag * arg_c.m_imag);
        return temp;
    };
};
bool check_complex(string &input)
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
bool check_op(string &input)
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
int main()
{
    string input;
    Complex result_complex;
    char op = ' ';
    int process = 0;
    while (getline(cin, input))
    {
        if ((process % 2 == 1) && (check_op(input) == true))
        {
            op = input[0];
        }
        else if ((process % 2 == 0) && (check_complex(input) == true))
        {
            double real, imag;
            stringstream ss(input);
            ss >> real >> imag;
            Complex current_complex(real, imag);
            switch (op)
            {
            case '+':
                result_complex = result_complex.add(current_complex);
                break;
            case '-':
                result_complex = result_complex.sub(current_complex);
                break;
            case '*':
                result_complex = result_complex.mul(current_complex);
                break;
            case '/':
                result_complex = result_complex.div(current_complex);
                break;
            case ' ':
                result_complex = current_complex;
                break;
            default:
                cerr << "Error: unknown operation\n";
                return 1;
            }
        }
        else
        {
            cout << "Error: Invalid input" << endl;
            return 0;
        }
        process = process + 1;
    }
    if (process = 0 || process % 2 == 1)
    {
        result_complex.print();
    }
    else
    {
        cout << "Error: Invalid input" << endl;
    }
    return 0;
}
