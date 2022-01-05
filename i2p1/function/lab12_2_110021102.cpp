#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(const vector<string> &tokens);
void print_ops(const vector<string> &tokens);
void print_nums(const vector<string> &tokens);
bool string_isdigit(string s);
vector<string> calculate_infix_expression(vector<string> tokens);
void answer(const vector<string> &tokens);
long string_to_long(string s);

int main()
{
    string input_buffer;
    vector<string> tokens;

    cout << "Please input the expression: ";
    std::getline(cin, input_buffer);

    parse_expression(input_buffer, tokens);

    if (!check_expression(tokens))
    {
        cout << "Invalid expression." << endl;
        return 0;
    }
    print_nums(tokens);
    print_ops(tokens);

    cout << "Result:";
    if (tokens.size() == 1)
    {
        cout << " " << tokens[0];
    }
    else
    {
        tokens = calculate_infix_expression(tokens);
    }

    return 0;
}
void parse_expression(const string &expression, vector<string> &tokens)
{
    stringstream terms_extractor(expression);
    for (string term; (terms_extractor >> term);)
    {
        tokens.push_back(term);
    }
}
bool string_isdigit(string s)
{
    if (s[0] == '-')
    {
        if (s.size() == 1)
        {
            return false;
        }
        for (int i = 1; i < s.size(); i++)
        {
            if (!isdigit(s[i]))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (!isdigit(s[i]))
            {
                return false;
            }
        }
        return true;
    }
}
bool check_expression(const vector<string> &tokens)
{
    int opcount = 0;
    int numcount = 0;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" or tokens[i] == "-" 
            or tokens[i] == "*" or tokens[i] == "/")
        {
            opcount += 1;
        }
        else if (string_isdigit(tokens[i]))
        {
            numcount += 1;
        }
        else
        {
            return 0;
        }
    }
    if (numcount == opcount + 1)
    {
        for (int i = 1; i < tokens.size() - 1; i += 2)
        {
            if (!(tokens[i] == "+" or tokens[i] == "-" 
                or tokens[i] == "*" or tokens[i] == "/"))
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
void print_ops(const vector<string> &tokens)
{
    cout << "Operators:";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" or tokens[i] == "-" 
            or tokens[i] == "*" or tokens[i] == "/")
        {
            cout << " " << tokens[i];
        }
    }
    cout << endl;
}
void print_nums(const vector<string> &tokens)
{
    cout << "Operands:";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (string_isdigit(tokens[i]))
        {
            cout << " " << tokens[i];
        }
    }
    cout << endl;
}
vector<string> calculate_infix_expression(vector<string> tokens)
{
    long a = 0;
    vector<string> vs;
    if (tokens.size() == 3)
    {

        if (tokens[1] == "+")
        {
            a = string_to_long(tokens[0]) + string_to_long(tokens[2]);
            cout << " " << a;
            string str = to_string(a);
            vs.push_back(str);
            return vs;
        }
        else if (tokens[1] == "-")
        {
            a = string_to_long(tokens[0]) - string_to_long(tokens[2]);
            cout << " " << a;
            string str = to_string(a);
            vs.push_back(str);
            return vs;
        }
        else if (tokens[1] == "*")
        {
            a = string_to_long(tokens[0]) * string_to_long(tokens[2]);
            cout << " " << a;
            string str = to_string(a);
            vs.push_back(str);
            return vs;
        }
        else if (tokens[1] == "/")
        {
            a = string_to_long(tokens[0]) / string_to_long(tokens[2]);
            cout << " " << a;
            string s = to_string(a);
            vs.push_back(s);
            return vs;
        }
    }
    else
    {
        if (tokens[tokens.size() - 2] == "+")
        {
            long temp = 0;
            temp = string_to_long(tokens[tokens.size() - 1]);
            tokens.pop_back();
            tokens.pop_back();
            a = string_to_long((calculate_infix_expression(tokens))[0]) + temp;
            cout << " " << a;
            string str = to_string(a);
            vs.push_back(str);
            return vs;
        }
        else if (tokens[tokens.size() - 2] == "-")
        {
            long temp = 0;
            temp = string_to_long(tokens[tokens.size() - 1]);
            tokens.pop_back();
            tokens.pop_back();
            a = string_to_long((calculate_infix_expression(tokens))[0]) - temp;
            cout << " " << a;
            string str = to_string(a);
            vs.push_back(str);
            return vs;
        }
        else if (tokens[tokens.size() - 2] == "*")
        {
            long temp = 0;
            temp = string_to_long(tokens[tokens.size() - 1]);
            tokens.pop_back();
            tokens.pop_back();
            a = string_to_long((calculate_infix_expression(tokens))[0]) * temp;
            cout << " " << a;
            string str = to_string(a);
            vs.push_back(str);
            return vs;
        }
        else if (tokens[tokens.size() - 2] == "/")
        {
            long temp = 0;
            temp = string_to_long(tokens[tokens.size() - 1]);
            tokens.pop_back();
            tokens.pop_back();
            a = string_to_long((calculate_infix_expression(tokens))[0]) / temp;
            cout << " " << a;
            string str = to_string(a);
            vs.push_back(str);
            return vs;
        }
    }
}
long string_to_long(string s)
{
    long a = 0;
    if (s[0] == '-')
    {
        for (int i = 1; i < s.size(); i++)
        {
            a *= 10;
            a += (s[i] - '0');
        }
        a *= -1;
        return a;
    }
    else
    {
        for (int i = s.size() - 1; i >= 0; i--)
        {
            a += (s[i] - '0') * pow(10, s.size() - 1 - i);
        }
        return a;
    }
}
