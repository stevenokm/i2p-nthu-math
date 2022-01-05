#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(const vector<string> &tokens);
void print_ops(const vector<string> &tokens);
void print_nums(const vector<string> &tokens);
bool is_number(string num);
bool is_oper(string token);

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

    return EXIT_SUCCESS;
}

void print_ops(const vector<string> &tokens)
{
    cout << "Operators: ";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (is_oper(tokens[i]))
            cout << tokens[i] << " ";
    }
    cout << endl;
}
void print_nums(const vector<string> &tokens)
{
    cout << "Operands: ";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (is_number(tokens[i]))
            cout << tokens[i] << " ";
    }
    cout << endl;
}

void parse_expression(const string &expression, vector<string> &tokens)
{
    stringstream buffer(expression);
    for (string tmp; (buffer >> tmp);)
    {
        tokens.push_back(tmp);
    }
}

bool is_number(string num)
{
    int suc_case = 0;
    if (num[0] == '-' && num.size() != 1)
        suc_case = 1;
    for (int i = 0; i < num.size(); i++)
    {
        for (int tmp = 0; tmp < 10; tmp++)
        {
            if (num[i] - '0' == tmp)
            {
                suc_case += 1;
            }
        }
    }
    return suc_case == num.size();
}

bool is_oper(string token)
{
    if (token.size() != 1)
        return false;
    string valid = "+-*/";
    for (int i = 0; i < valid.size(); i++)
    {
        if (token[0] == valid[i])
            return true;
    }
    return false;
}

bool check_expression(const vector<string> &tokens)
{
    int numC = 0, operC = 0;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (is_number(tokens[i]))
            numC += 1;
        else if (is_oper(tokens[i]))
            operC += 1;
        else
            return false;
    }
    return (numC - operC == 1);
}
