#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens)
{
    int n = 0;
    string stringtokens;
    while (n <= expression.size() - 1)
    {
        if (expression[n] != ' ')
        {
            do
            {
                stringtokens.push_back(expression[n]);
                n = n + 1;
            } while (expression[n] != ' ' && n <= expression.size() - 1);
            tokens.push_back(stringtokens);
            stringtokens.clear();
        }
        else
        {
            n = n + 1;
        }
    }
}
bool check_expression(const vector<string> &tokens)
{
    int operandsnum = 0;
    int operatorsnum = 0;
    for (int i = 0; i <= tokens.size() - 1; i++)
    {
        int j = 0;

        if (tokens[i][j] == '-' && tokens[i].size() != 1)
        {
            for (int j = 1; j <= tokens[i].size() - 1; j++)
            {
                if (!isdigit(tokens[i][j]))
                {
                    return false;
                }
            }
            operandsnum = operandsnum + 1;
        }
        else if (tokens[i][j] == '+' 
            || tokens[i][j] == '-' 
            || tokens[i][j] == '*' 
            || tokens[i][j] == '/')
        {
            if (tokens[i].size() != 1)
            {
                return false;
            }
            else
            {
                operatorsnum = operatorsnum + 1;
            }
        }
        else
        {
            for (int j = 0; j <= tokens[i].size() - 1; j++)
            {
                if (!isdigit(tokens[i][j]))
                {
                    return false;
                }
            }
            operandsnum = operandsnum + 1;
        }
    }
    if (operandsnum != operatorsnum + 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void print_ops(const vector<string> &tokens)
{
    std::cout << "Operators: ";
    for (int i = 0; i <= tokens.size() - 1; i++)
    {
        if (tokens[i] == "+" 
            || tokens[i] == "-" 
            || tokens[i] == "*" 
            || tokens[i] == "/")
        {
            std::cout << tokens[i];
            if (i != tokens.size() - 1)
            {
                std::cout << " ";
            }
        }
    }
}
void print_nums(const vector<string> &tokens)
{
    std::cout << "Operands: ";
    for (int i = 0; i <= tokens.size() - 1; i++)
    {
        if (tokens[i] != "+" 
            && tokens[i] != "-" 
            && tokens[i] != "*" 
            && tokens[i] != "/")
        {
            std::cout << tokens[i];
            if (i != tokens.size() - 1)
            {
                std::cout << " ";
            }
        }
    }
    std::cout << "\n";
}
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