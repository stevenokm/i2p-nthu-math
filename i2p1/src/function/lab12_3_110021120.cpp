#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void parse_expression(string &expression, vector<string> &tokens)
{
    stringstream str(expression);
    for (string term; (str >> term);)
    {
        tokens.push_back(term);
    }
}
bool check_expression(const vector<string> &tokens, int &n)
{
    int o = 0;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" 
            || tokens[i] == "*" || tokens[i] == "/")
        {
            n++;
        }
        else
        {
            for (int j = 0; j < tokens[i].size(); j++)
            {
                if (j == 0 && (!isdigit(tokens[i][j]) && tokens[i][j] != '-'))
                    return false;
                else if (!isdigit(tokens[i][j]) && j != 0)
                    return false;
            }
            o++;
        }
    }
    return (o == n + 1);
}
void print_ops(const vector<string> &tokens)
{
    cout << "Operators: ";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" 
            || tokens[i] == "*" || tokens[i] == "/")
        {
            cout << tokens[i] << ' ';
        }
    }
    cout << endl;
}
void print_nums(const vector<string> &tokens)
{
    cout << "Operands: ";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (!(tokens[i] == "+" || tokens[i] == "-" 
            || tokens[i] == "*" || tokens[i] == "/"))
        {
            cout << stol(tokens[i]) << ' ';
        }
    }
    cout << endl;
}
string calculate_postfix_expression(
    vector<string> &tokens, 
    int &last_pos, 
    vector<string> &final_ans)
{
    if (tokens.size() == 1)
    {
        return tokens[0];
    }
    int n = last_pos, o = last_pos;
    long b, a;
    string ans, re;
    last_pos--;
    n = last_pos;
    if (last_pos < 0)
        return "error";
    if (tokens[last_pos] == "+" || tokens[last_pos] == "-" 
        || tokens[last_pos] == "*" || tokens[last_pos] == "/")
    {
        re = calculate_postfix_expression(tokens, last_pos, final_ans);
        if (re == "error")
            return "error";
        else
        {
            b = stol(re);
            final_ans[n] = re;
        }
    }
    else
        b = stol(tokens[last_pos]);
    last_pos--;
    n = last_pos;
    if (last_pos < 0)
        return "error";
    if (tokens[last_pos] == "+" || tokens[last_pos] == "-" 
        || tokens[last_pos] == "*" || tokens[last_pos] == "/")
    {
        re = calculate_postfix_expression(tokens, last_pos, final_ans);
        if (re == "error")
            return "error";
        else
        {
            a = stol(re);
            final_ans[n] = re;
        }
    }
    else
        a = stol(tokens[last_pos]);

    if (tokens[o] == "+")
        a = a + b;
    else if (tokens[o] == "-")
        a = a - b;
    else if (tokens[o] == "*")
        a = a * b;
    else if (tokens[o] == "/")
        a = a / b;

    ans = to_string(a);
    return ans;
}
int main(int argc, char *argv[])
{
    string input_buffer, str;
    vector<string> tokens;

    cout << "Please input the expression: ";
    std::getline(cin, input_buffer);

    parse_expression(input_buffer, tokens);
    int n = 0;
    if (!check_expression(tokens, n))
    {
        cout << "Invalid expression." << endl;
        return EXIT_FAILURE;
    }

    int last_pos = tokens.size() - 1;
    vector<string> final_ans;
    final_ans.assign(n * 2 + 2, "error");
    str = calculate_postfix_expression(tokens, last_pos, final_ans);
    if (str == "error")
    {
        cout << "Invalid expression." << endl;
        return EXIT_FAILURE;
    }

    print_nums(tokens);
    print_ops(tokens);

    cout << "Result: ";
    for (int i = 0; i < final_ans.size(); i++)
    {
        if (final_ans[i] != "error")
            cout << final_ans[i] << ' ';
    }
    cout << str;
    cout << endl;
    return EXIT_SUCCESS;
}