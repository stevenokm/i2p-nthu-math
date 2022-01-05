#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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
	getline(cin, input_buffer);

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

	for (int i = 0; i < tokens.size(); ++i)
	{
		if (tokens[i] == "+" 
			|| tokens[i] == "-" 
			|| tokens[i] == "*" 
			|| tokens[i] == "/")
		{
			++op_cnt;
		}
		else
		{
			try
			{
				stol(tokens[i]);
				++num_cnt;
			}
			catch (const std::exception &e)
			{
				return false;
			}
		}
	}
	return num_cnt == op_cnt + 1;
}

void print_ops(const vector<string> &tokens)
{
	cout << "Operators:";
	for (int i = 0; i < tokens.size(); ++i)
	{
		if (tokens[i] == "+" 
			|| tokens[i] == "-" 
			|| tokens[i] == "*" 
			|| tokens[i] == "/")
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
