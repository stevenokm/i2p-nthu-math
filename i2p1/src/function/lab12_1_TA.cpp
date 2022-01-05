#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(const vector<string> &tokens);
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
    return EXIT_SUCCESS;
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
        if (tokens[i].length() == 1)
        {
            if (isdigit(tokens[i][0]))
            {
                num_counts++;
                continue;
            }
            else
            {
                if (tokens[i][0] == '+' 
                    || tokens[i][0] == '-' 
                    || tokens[i][0] == '*' 
                    || tokens[i][0] == '/')
                {
                    oper_counts++;
                    continue;
                }
                else
                    return false;
            }
        }
        for (int j = 0; j < tokens[i].length(); j++)
        {
            if (!isdigit(tokens[i][j]))
            {
                if (j == 0 && tokens[i][j] == '-') 
                // Check if Negative Sign
                    continue;
                return false;
            }
        }
        num_counts++;
    }

    if (num_counts != oper_counts + 1)
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