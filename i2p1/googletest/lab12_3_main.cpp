#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "lab12_3_include.h"

using namespace std;

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

    print_ops(tokens);

    print_nums(tokens);

    cout << "Result: ";
    int last_pos = tokens.size() - 1;
    vector<long> num_stack;
    calculate_expression(tokens, num_stack);
    cout << num_stack[0] << endl;

    return EXIT_SUCCESS;
}