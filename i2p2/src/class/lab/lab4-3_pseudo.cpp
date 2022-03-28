#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Complex
{
private:
    // data members
    // save the real and imaginary parts of the complex number
    // with `double` precision

public:
    // Constructor, initializes real and imaginary parts
    // hint: as like as `modify` function in examples
    // but use default constructor to implement

    // print function
    // note: be careful about the format of output
    // especially the ` ` and newline (endl)
    void print();

    // add function

    // subtract function

    // multiply function

    // divide function

    // parse function
    // note: use `stringstream` and `>>` to parse the string to double
    // and use `stringstream::fail()` to check the conversion is successful

};

// parse op global function
char parse_op(const string &arg_str);

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
        
        // check is not end of input
        if (input.empty() || cin.eof())
        {
            prompt_invalid_input();
        }
        // check the input is a valid complex number
        
        // calculate the result
        
        // get the second input
        
        // check is end of input or not
        if (input.empty() || cin.eof())
        {
            is_process_continue = false;
        }
        // if not end of input, check the input is a valid operator
        
    }
    result_complex.print();
    return 0;
}