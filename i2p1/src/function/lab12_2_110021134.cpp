#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(const vector<string> &tokens);
string calculate_infix_expression(const vector<string> &tokens);
void print_ops(const vector<string> &tokens);
void print_nums(const vector<string> &tokens);

int main()
{
    string input_buffer;
    vector<string> tokens;

    cout << "Please input the expression: ";
    getline(cin, input_buffer);

    parse_expression(input_buffer, tokens);

    if (!check_expression(tokens))
    {
        cout << "Invalid expression." << endl;
        return EXIT_FAILURE;
    }

    print_nums(tokens);

    print_ops(tokens);

    cout << "Result:";
    if (tokens.size() == 1)
    {
        cout << tokens[0];
    }
    calculate_infix_expression(tokens);
    cout << endl;

    return EXIT_SUCCESS;
}

void parse_expression(const string &expression, vector<string> &tokens)
{
    stringstream stream_ex(expression);
    for (string s; stream_ex >> s;)
    {
        tokens.push_back(s);
    }
}

bool check_expression(const vector<string> &tokens)
{
    unsigned long long num = 0, op = 0;
    bool bool_before = 0, bool_after = 0;
    for (int i = 0; i < tokens.size(); i++)
    {
        bool n = 0;
        for (int j = 0; j < tokens[i].size(); j++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" 
                || tokens[i] == "*" || tokens[i] == "/")
            {
                op += 1;
                bool_after = 0;
                break;
            }
            else if (tokens[i][j] == '-')
            {
                if (j != 0)
                {
                    return 0;
                }
            }
            else if (isdigit(tokens[i][j]))
            {
                n = 1;
            }
            else
            {
                return 0;
            }
        }
        if (n == 1)
        {
            num += 1;
            bool_after = 1;
        }
        if (bool_after == bool_before)
        {
            return 0;
        }
        bool_before = bool_after;
    }
    if (num - op != 1)
    {
        return 0;
    }
    return 1;
}

string calculate_infix_expression(const vector<string> &tokens)
{
    if (tokens.size() == 1)
    {
        return tokens[0];
    }
    vector<string> left(tokens.begin(), tokens.end() - 2),
        right(tokens.end() - 2, tokens.end());

    string ans;
    if (right[0] == "+")
    {
        ans = to_string(stol(calculate_infix_expression(left)) + stol(right[1]));
        cout << " " << ans;
        return ans;
    }
    else if (right[0] == "-")
    {
        ans = to_string(stol(calculate_infix_expression(left)) - stol(right[1]));
        cout << " " << ans;
        return ans;
    }
    else if (right[0] == "*")
    {
        ans = to_string(stol(calculate_infix_expression(left)) * stol(right[1]));
        cout << " " << ans;
        return ans;
    }
    else if (right[0] == "/")
    {
        ans = to_string(stol(calculate_infix_expression(left)) / stol(right[1]));
        cout << " " << ans;
        return ans;
    }
    else
    {
        return "qwertyuiop";
    }
}

void print_nums(const vector<string> &tokens)
{
    cout << "Operands:";
    for (int i = 0; i < tokens.size(); i++)
    {
        bool n = 0;
        if (tokens[i] == "+" || tokens[i] == "-" 
            || tokens[i] == "*" || tokens[i] == "/")
        {
            n = 1;
        }
        if (n == 0)
        {
            cout << " " << tokens[i];
        }
    }
    cout << endl;
}

void print_ops(const vector<string> &tokens)
{
    cout << "Operators:";
    for (int i = 0; i < tokens.size(); i++)
    {
        bool n = 0;
        if (tokens[i] == "+" || tokens[i] == "-" 
            || tokens[i] == "*" || tokens[i] == "/")
        {
            n = 1;
        }
        if (n == 1)
        {
            cout << " " << tokens[i];
        }
    }
    cout << endl;
}
