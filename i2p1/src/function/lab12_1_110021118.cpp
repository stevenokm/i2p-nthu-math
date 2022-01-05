#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void parse_expression(const string &expression, vector<string> &check);
void parse_expression(
    const vector<string> &check,
    vector<long> &operands,
    vector<string> &operators);
bool check_expression(const vector<string> &check);
void print_ops(const vector<long> &operands);
void print_nums(const vector<string> &operators);

int main(int argc, char *argv[])
{
    string input_buffer;
    vector<string> check;
    vector<long> operands;
    vector<string> operators;

    cout << "Please input the expression: ";
    getline(cin, input_buffer);

    parse_expression(input_buffer, check);

    if (!check_expression(check))
    {
        cout << "Invalid expression." << endl;
        return EXIT_FAILURE;
    }

    parse_expression(check, operands, operators);
    if ((operands.size() - 1) != operators.size())
    {
        cout << "Invalid expression." << endl;
        return EXIT_FAILURE;
    }

    print_ops(operands);

    print_nums(operators);

    return EXIT_SUCCESS;
}

void parse_expression(const string &expression, vector<string> &check)
{
    stringstream terms_extractor(expression);

    for (string term; (terms_extractor >> term);)
    {
        check.push_back(term);
    }
}
void parse_expression(
    const vector<string> &check,
    vector<long> &operands,
    vector<string> &operators)
{
    for (int i = 0; i < check.size(); i++)
    {
        if (check[i] == "+" 
            || check[i] == "-" 
            || check[i] == "*" 
            || check[i] == "/")
        {
            operators.push_back(check[i]);
        }
        else
        {
            long operand = stol(check[i]);
            operands.push_back(operand);
        }
    }
}
bool check_expression(const vector<string> &check)
{
    if ((check.size() % 2) == 0)
    {
        return false;
    }
    for (int i = 0; i < check.size(); i++)
    {
        string s = check[i];
        if (s.size() == 1)
        {
            if (s[0] != '+' 
                && s[0] != '-' 
                && s[0] != '*' 
                && s[0] != '/')
            {
                if (!isdigit(s[0]))
                {
                    return false;
                }
            }
        }
        else
        {
            if (s[0] != '-')
            {
                if (!isdigit(s[0]))
                {
                    return false;
                }
            }
            for (int i = 1; i < check[i].size(); i++)
            {
                if (!isdigit(s[i]))
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void print_ops(const vector<long> &operands)
{
    cout << "Operands: ";
    for (int i = 0; i < operands.size(); i++)
    {
        cout << operands[i] << " ";
    }
    cout << endl;
}
void print_nums(const vector<string> &operators)
{
    cout << "Operators: ";
    for (int i = 0; i < operators.size(); i++)
    {
        cout << operators[i] << " ";
    }
    cout << endl;
}