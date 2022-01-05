#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(const vector<string> &tokens);
string calculate_postfix_expression(vector<string> &tokens, int &last_pos);
// hint: use std::to_string(long) to convert long to string
// see https://en.cppreference.com/w/cpp/string/basic_string/to_string
// hint: use recursion to find the subexpressions of two operands
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

	cout << "Result:";
	int last_pos = tokens.size() - 1;
	calculate_postfix_expression(tokens, last_pos);
	cout << endl;

	return EXIT_SUCCESS;
}

void parse_expression(string const &expression, vector<string> &tokens)
{
	stringstream tokens_extractor(expression);

	for (string new_token; (tokens_extractor >> new_token);)
	{
		tokens.push_back(new_token);
	}
}

bool check_expression(const vector<string> &tokens)
{
	int op_cnt = 0, num_cnt = 0;
	int number_in_stack_cnt = 0;

	for (int i = 0; i < tokens.size(); ++i)
	{
		if (tokens[i] == "+" || tokens[i] == "-" 
			|| tokens[i] == "*" || tokens[i] == "/")
		{
			++op_cnt;
			if (--number_in_stack_cnt < 1)
				return false;
		}
		else
		{
			try
			{
				stol(tokens[i]);
				++num_cnt;
				++number_in_stack_cnt;
			}
			catch (const std::exception &e)
			{
				return false;
			}
		}
	}

	return num_cnt == op_cnt + 1 && number_in_stack_cnt == 1;
}

string calculate_postfix_expression(vector<string> &tokens, int &last_pos)
{
	if (tokens.size() == 1)
	{
		cout << " " << tokens[0];
		return tokens[0];
	}
	vector<long> numbers;

	for (int i = 0; i < tokens.size(); ++i)
	{
		if (tokens[i] == "+" || tokens[i] == "-" 
			|| tokens[i] == "*" || tokens[i] == "/")
		{
			long b = numbers.back();
			numbers.pop_back();
			long a = numbers.back();
			numbers.pop_back();
			if (tokens[i] == "+")
				numbers.push_back(a + b);
			else if (tokens[i] == "-")
				numbers.push_back(a - b);
			else if (tokens[i] == "*")
				numbers.push_back(a * b);
			else if (b != 0)
				numbers.push_back(a / b);
			else
			{
				numbers.push_back(a);
				cerr << endl
					 << "ERROR: divided by zero" << endl;
			}
			cout << " " << numbers.back();
		}
		else
		{
			numbers.push_back(stol(tokens[i]));
		}
	}
	return to_string(numbers.back());
}

void print_ops(const vector<string> &tokens)
{
	cout << "Operators:";
	for (int i = 0; i < tokens.size(); ++i)
	{
		if (tokens[i] == "+" || tokens[i] == "-" 
			|| tokens[i] == "*" || tokens[i] == "/")
		{
			cout << " " << tokens[i];
		}
	}
	cout << endl;
}

void print_nums(const vector<string> &tokens)
{
	cout << "Operands:";
	for (int i = 0; i < tokens.size(); ++i)
	{
		try
		{
			long number = stol(tokens[i]);
			cout << " " << number;
		}
		catch (const std::exception &e)
		{
		}
	}
	cout << endl;
}