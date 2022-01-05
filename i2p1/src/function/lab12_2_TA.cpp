#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(const vector<string> &tokens);
void calculate_infix_expression(const vector<string> &tokens);
// hint: use std::to_string(long) to convert long to string
// see https://en.cppreference.com/w/cpp/string/basic_string/to_string
void print_ops(const vector<string> &tokens);
void print_nums(const vector<string> &tokens);

int main(int argc, char *argv[])
{
    string input_buffer;
    vector<string> tokens;

    cout << "Please input the expression: ";
    std::getline(cin, input_buffer);

    parse_expression(input_buffer, tokens);

    if (!check_expression(tokens))
    {
        cout << "Invalid expression." << endl;
        return EXIT_FAILURE;
    }

    print_nums(tokens);

    print_ops(tokens);

    cout << "Result: ";
    calculate_infix_expression(tokens);
    cout << endl;

    return EXIT_SUCCESS;
}

bool is_number(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0 && str[i] == '-' && str.length() > 1)
            continue;
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void parse_expression(const string &expression, vector<string> &tokens)
{
    string temp;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == ' ')
        {
            tokens.push_back(temp);
            temp.clear();
        }
        else if (i == expression.size() - 1) // End of Input_Buffer
        {
            temp += expression.substr(i, 1);
            tokens.push_back(temp);
        }
        else
            temp += expression.substr(i, 1);
    }
}

bool check_expression(const vector<string> &tokens)
{
    int oper_counts = 0, num_counts = 0;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" 
            || tokens[i] == "*" || tokens[i] == "/")
            oper_counts++;
        else if (is_number(tokens[i]))
            num_counts++;
        else
            return false;

        if (num_counts != oper_counts + (i + 1) % 2)
            return false;
    }
    if (!is_number(tokens[tokens.size() - 1]))
        return false;
    return true;
}

void print_nums(const vector<string> &tokens)
{
    cout << "Operands:";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].length() != 1 || isdigit(tokens[i][0]))
            cout << ' ' << tokens[i];
    }
    cout << endl;
}

void print_ops(const vector<string> &tokens)
{
    cout << "Operators:";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].length() == 1 && !isdigit(tokens[i][0]))
            cout << ' ' << tokens[i];
    }
    cout << endl;
}

void calculate_infix_expression(const vector<string> &tokens)
{
    if (tokens.size() == 1)
    {
        cout << tokens[0];
        return;
    }

    long a, b;

    for (int i = 0; i < tokens.size() - 2; i += 2)
    {
        if (i == 0)
            a = stol(tokens[i]);
        b = stol(tokens[i + 2]);

        if (tokens[i + 1] == "+")
            a += b;
        else if (tokens[i + 1] == "-")
            a -= b;
        else if (tokens[i + 1] == "*")
            a *= b;
        else if (tokens[i + 1] == "/")
            a /= b;

        cout << a << ' ';
    }
    return;
}