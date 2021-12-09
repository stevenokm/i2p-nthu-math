#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(const vector<string> &tokens);
string calculate_infix_expression(const vector<string> &tokens);
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

    print_ops(tokens);

    print_nums(tokens);

    cout << "Result: ";
    calculate_infix_expression(tokens);
    cout << endl;

    return EXIT_SUCCESS;
}
