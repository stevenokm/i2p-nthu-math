#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// parse_expression
// Parse the expression from cin and store the operator and operand in
// operator_vector and operand_vector respectively.
// Hint: there is a function like atoi but it convert char[] to double.
// Hint 2: to convert string to char[] use .c_str() function.
void parse_expression(vector<string> &operator_vector,
                      vector<double> &operand_vector);
// check_expression
// Check if the expression is valid.
// Return true if the expression is valid, otherwise return false.
bool check_expression(const vector<string> &operator_vector,
                      const vector<double> &operand_vector);
// print_operator
// Print the operator in operator_vector.
void print_operator(const vector<string> &operator_vector);
// print_operand
// Print the operand in operand_vector.
// Use the default cout format for double.
void print_operand(const vector<double> &operand_vector);

int main(int argc, char *argv[])
{
    vector<string> operator_vector;
    vector<double> operand_vector;

    parse_expression(operator_vector, operand_vector);

    if (!check_expression(operator_vector, operand_vector))
    {
        cout << "Invalid Expression" << endl;
        return EXIT_FAILURE;
    }

    print_operand(operand_vector);
    print_operator(operator_vector);

    return EXIT_SUCCESS;
}
