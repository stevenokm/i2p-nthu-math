#include <iostream>

using namespace std;

// Triangle class declaration
class Int_Calc
{
private:
    // define current value
    long m_curr_val;
    // define input value
    long m_input_val;
    // define operation
    // `+`, `-`, `*`, `/`, and ` ` for none
    char m_op;
    // calculate result
    void _calc_result(); // private function, discuss in the next lecture

public:
    // clear the input value
    void clear();
    // clear the entire class
    void init();
    // set the input value
    void set_input(long arg_input);
    // add the input value to the current value
    void add();
    // subtract the input value from the current value
    void sub();
    // multiply the input value with the current value
    void mul();
    // divide the current value by the input value
    void div();
    // assign the input value to the current value
    void assign();
    // get the current value
    long get_curr_val();
    // get the current operation
    char get_op();
    // get the input value
    long get_input_val();
};

// Int_Calc class implementation

// calculate the result
void Int_Calc::_calc_result()
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
        m_curr_val /= m_input_val;
        break;
    case ' ':
        m_curr_val = m_input_val;
        break;
    default:
        break;
    }
}

// clear the input value
void Int_Calc::clear()
{
    m_input_val = 0;
}

// clear the entire class
void Int_Calc::init()
{
    m_curr_val = 0;
    m_input_val = 0;
    m_op = ' ';
}

// set the input value
void Int_Calc::set_input(long arg_input)
{
    m_input_val = arg_input;
}

// add the input value to the current value
void Int_Calc::add()
{
    _calc_result();
    m_op = '+';
}

// subtract the input value from the current value
void Int_Calc::sub()
{
    _calc_result();
    m_op = '-';
}

// multiply the input value with the current value
void Int_Calc::mul()
{
    _calc_result();
    m_op = '*';
}

// divide the current value by the input value
void Int_Calc::div()
{
    _calc_result();
    m_op = '/';
}

// assign the input value to the current value
void Int_Calc::assign()
{
    _calc_result();
    m_op = ' ';
}

// get the current value
long Int_Calc::get_curr_val()
{
    return m_curr_val;
}

// get the current operation
char Int_Calc::get_op()
{
    return m_op;
}

// get the input value
long Int_Calc::get_input_val()
{
    return m_input_val;
}

// main function

int main()
{
    // create an instance of the class
    Int_Calc calc;
    // initialize the class
    calc.init();
    // set the input value
    calc.set_input(10);
    // get the input value
    cout << calc.get_input_val() << endl;
    // add the input value to the current value
    calc.add();
    // get current op
    cout << '\'' << calc.get_op() << '\'' << endl;
    // set another input value
    calc.set_input(20);
    // get the input value
    cout << calc.get_input_val() << endl;
    // clear the input value
    calc.clear();
    // set the input value
    calc.set_input(30);
    // get the input value
    cout << calc.get_input_val() << endl;
    // compute the result
    calc.assign();
    // print the result
    cout << calc.get_curr_val() << endl;
}