#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(vector<string> &tokens, int &pos);
bool check_postfix_expression(const vector<string> &tokens);
string calculate_postfix_expression(vector<string> &tokens, int &last_pos);
// hint: use std::to_string(long) to convert long to string
// see https://en.cppreference.com/w/cpp/string/basic_string/to_string
// hint: use recursion to find the subexpressions of two operands
void print_ops(const vector<string> &tokens);
void print_nums(const vector<string> &tokens);
void calculate_expression(const vector<string> tokens);

int main(int argc, char *argv[])
{
    string input_buffer;
    vector<string> tokens;

    cout << "Please input the expression: ";
    std::getline(cin, input_buffer);

    parse_expression(input_buffer, tokens);

    if (!check_postfix_expression(tokens))
    {
        cout << "Invalid expression." << endl;
        return EXIT_FAILURE;
    }

    print_nums(tokens);

    print_ops(tokens);

    cout << "Result:";
    int last_pos = tokens.size() - 1;
    calculate_expression(tokens);
    cout << endl;

    return EXIT_SUCCESS;
}

bool is_number(string str) // Check if a string is a number
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

void calculate_expression(const vector<string> tokens)
{
    if (tokens.size() == 1)
    {
        cout << tokens[0];
        return;
    }

    vector<long> num_stack;
    int now = 0;
    while (now < tokens.size())
    {
        while (is_number(tokens[now]))
        {
            num_stack.push_back(stol(tokens[now]));
            now++;
        }
        long a = num_stack[num_stack.size() - 2],
             b = num_stack[num_stack.size() - 1];
        num_stack.pop_back();
        num_stack.pop_back();

        if (tokens[now] == "+")
            num_stack.push_back(a + b);
        else if (tokens[now] == "-")
            num_stack.push_back(a - b);
        else if (tokens[now] == "*")
            num_stack.push_back(a * b);
        else if (tokens[now] == "/")
            num_stack.push_back(a / b);

        cout << ' ' << num_stack[num_stack.size() - 1];

        now++;
    }
}

bool check_postfix_expression(const vector<string> &tokens)
{
    int stack_count = 0;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (i > 0 && stack_count < 1)
            return false;
        if (is_number(tokens[i]))
            stack_count++;
        else if (tokens[i] == "+" || tokens[i] == "-" 
                    || tokens[i] == "*" || tokens[i] == "/")
            stack_count--;
        else
            return false;
    }
    return stack_count == 1;
}