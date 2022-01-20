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
// calculate_expression
// Calculate the expression store in operator_vector and operand_vector
// and return the result in double.
// User should check the expression is valid before calling this function.
double calculate_expression(const vector<string> &operator_vector,
                            const vector<double> &operand_vector);

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

    cout << "Result: " << calculate_expression(operator_vector, operand_vector)
         << endl;

    return EXIT_SUCCESS;
}

void parse_expression(vector<string> &operator_vector,
                      vector<double> &operand_vector)
{
    for (string temp; cin >> temp;)
    {
        if (temp == "=")
        {
            break;
        }
        else if(isnumber(temp[0]))
        {
            operand_vector.push_back(atof(temp.c_str()));
        }
        else
        {
            operator_vector.push_back(temp);
        }
    }
}

bool check_expression(const vector<string> &operator_vector,
                      const vector<double> &operand_vector)
{
    for (unsigned i = 0; i < operator_vector.size(); i++)
    {
        if (operator_vector[i] == "/" && operand_vector[i + 1] == 0)
        {
            return false;
        }
        else if (operator_vector[i] != "+" && operator_vector[i] != "-" &&
                 operator_vector[i] != "*" && operator_vector[i] != "/")
        {
            return false;
        }
    }
    return (operator_vector.size() == operand_vector.size() - 1);
}

void print_operator(const vector<string> &operator_vector)
{
    cout << "Operators:";
    for (int i = 0; i < operator_vector.size(); i++)
        cout << ' ' << operator_vector[i];
    cout << endl;
}

void print_operand(const vector<double> &operand_vector)
{
    cout << "Operands:";
    for (int i = 0; i < operand_vector.size(); i++)
        cout << ' ' << operand_vector[i];
    cout << endl;
}

double calculate_expression(const vector<string> &operator_vector,
                            const vector<double> &operand_vector)
{
    double result = operand_vector[0];
    for (unsigned i = 0; i < operator_vector.size(); i++)
    {
        if (operator_vector[i] == "+")
        {
            result += operand_vector[i + 1];
        }
        else if (operator_vector[i] == "-")
        {
            result -= operand_vector[i + 1];
        }
        else if (operator_vector[i] == "*")
        {
            result *= operand_vector[i + 1];
        }
        else if (operator_vector[i] == "/")
        {
            result /= operand_vector[i + 1];
        }
    }
    return result;
}
