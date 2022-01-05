#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(const vector<string> &tokens);
string calculate_postfix_expression(
    vector<string> &tokens, vector<string> &vector_ans);
void print_ops(const vector<string> &tokens);
void print_nums(const vector<string> &tokens);
void expand(vector<string> &vector_ans, int len);
void prinf_ans(vector<string> &vector_ans);

int main()
{
    int len = 0;
    string input_buffer;
    vector<string> tokens, vector_ans;

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

    cout << "Result:";

    if (tokens.size() == 1)
    {
        cout << " " << tokens[0];
    }
    len = tokens.size();
    expand(vector_ans, len);
    calculate_postfix_expression(tokens, vector_ans);
    prinf_ans(vector_ans);

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
    for (int i = 0; i < tokens.size(); i++)
    {
        bool n = 0;
        for (int j = 0; j < tokens[i].size(); j++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" 
                || tokens[i] == "*" || tokens[i] == "/")
            {
                op += 1;
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
        }
        if (num - op < 1)
        {
            return 0;
        }
    }
    if (num - op != 1)
    {
        return 0;
    }
    return 1;
}

void expand(vector<string> &vector_ans, int len)
{
    for (int i = 0; i < len; i++)
    {
        vector_ans.push_back("\0");
    }
}

string calculate_postfix_expression(
    vector<string> &tokens, vector<string> &vector_ans)
{
    string ans, num_1, num_2, op;
    int location = tokens.size() - 1;
    op = tokens[tokens.size() - 1];
    tokens.pop_back();
    if (op == "+")
    {
        num_2 = calculate_postfix_expression(tokens, vector_ans);
        num_1 = calculate_postfix_expression(tokens, vector_ans);
        ans = to_string(stol(num_1) + stol(num_2));
        vector_ans[location] = ans;
        return ans;
    }
    else if (op == "-")
    {
        num_2 = calculate_postfix_expression(tokens, vector_ans);
        num_1 = calculate_postfix_expression(tokens, vector_ans);
        ans = to_string(stol(num_1) - stol(num_2));
        vector_ans[location] = ans;
        return ans;
    }
    else if (op == "*")
    {
        num_2 = calculate_postfix_expression(tokens, vector_ans);
        num_1 = calculate_postfix_expression(tokens, vector_ans);
        ans = to_string(stol(num_1) * stol(num_2));
        vector_ans[location] = ans;
        return ans;
    }
    else if (op == "/")
    {
        num_2 = calculate_postfix_expression(tokens, vector_ans);
        num_1 = calculate_postfix_expression(tokens, vector_ans);
        ans = to_string(stol(num_1) / stol(num_2));
        vector_ans[location] = ans;
        return ans;
    }
    else
    {
        return op;
    }
}

void prinf_ans(vector<string> &vector_ans)
{
    for (int i = 0; i < vector_ans.size(); i++)
    {
        if (vector_ans[i] != "\0")
        {
            cout << " " << vector_ans[i];
        }
    }
    cout << endl;
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
