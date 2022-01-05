#include "lab12_3_include.h"
#include "gtest/gtest.h"

TEST(ParseExpression, Operands)
{
    vector<string> tokens;
    string input_buffer = "1 2 3 4 5 6 7 8 9";
    parse_expression(input_buffer, tokens);
    ASSERT_EQ(tokens.size(), 9);
    for (int i = 0; i < tokens.size(); i++)
    {
        EXPECT_EQ(tokens[i], to_string(i + 1));
    }
}

TEST(ParseExpression, Operators)
{
    vector<string> tokens;
    string input_buffer = "+ - * /";
    parse_expression(input_buffer, tokens);
    ASSERT_EQ(tokens.size(), 4);
    EXPECT_EQ(tokens[0], "+");
    EXPECT_EQ(tokens[1], "-");
    EXPECT_EQ(tokens[2], "*");
    EXPECT_EQ(tokens[3], "/");
}

TEST(ParseExpression, Mixed1)
{
    vector<string> tokens;
    string input_buffer = "1 2 3 4 * + -";
    parse_expression(input_buffer, tokens);
    ASSERT_EQ(tokens.size(), 7);
    EXPECT_EQ(tokens[0], "1");
    EXPECT_EQ(tokens[1], "2");
    EXPECT_EQ(tokens[2], "3");
    EXPECT_EQ(tokens[3], "4");
    EXPECT_EQ(tokens[4], "*");
    EXPECT_EQ(tokens[5], "+");
    EXPECT_EQ(tokens[6], "-");
}

TEST(ParseExpression, Mixed2)
{
    vector<string> tokens;
    string input_buffer = "-1 -2 -3 -4 * + -";
    parse_expression(input_buffer, tokens);
    EXPECT_EQ(tokens.size(), 7);
    EXPECT_EQ(tokens[0], "-1");
    EXPECT_EQ(tokens[1], "-2");
    EXPECT_EQ(tokens[2], "-3");
    EXPECT_EQ(tokens[3], "-4");
    EXPECT_EQ(tokens[4], "*");
    EXPECT_EQ(tokens[5], "+");
    EXPECT_EQ(tokens[6], "-");
}

TEST(ParseExpression, Mixed3)
{
    vector<string> tokens;
    string input_buffer = "-1 -2 -3 -4 * + %";
    parse_expression(input_buffer, tokens);
    EXPECT_EQ(tokens.size(), 7);
    EXPECT_EQ(tokens[0], "-1");
    EXPECT_EQ(tokens[1], "-2");
    EXPECT_EQ(tokens[2], "-3");
    EXPECT_EQ(tokens[3], "-4");
    EXPECT_EQ(tokens[4], "*");
    EXPECT_EQ(tokens[5], "+");
    EXPECT_EQ(tokens[6], "%");
}

TEST(CheckPostfixExpression, Operand)
{
    vector<string> tokens;
    tokens.push_back("1");
    EXPECT_TRUE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, Operator)
{
    vector<string> tokens;
    tokens.push_back("+");
    EXPECT_FALSE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, Mixed)
{
    vector<string> tokens;
    tokens.push_back("1");
    tokens.push_back("+");
    EXPECT_FALSE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, SimpleExpression)
{
    vector<string> tokens;
    tokens.push_back("1");
    tokens.push_back("2");
    tokens.push_back("+");
    EXPECT_TRUE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, ComplexExpression1)
{
    vector<string> tokens;
    tokens.push_back("1");
    tokens.push_back("2");
    tokens.push_back("3");
    tokens.push_back("4");
    tokens.push_back("*");
    tokens.push_back("+");
    tokens.push_back("-");
    EXPECT_TRUE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, ComplexExpression2)
{
    vector<string> tokens;
    tokens.push_back("-1");
    tokens.push_back("-2");
    tokens.push_back("-3");
    tokens.push_back("-4");
    tokens.push_back("*");
    tokens.push_back("+");
    tokens.push_back("-");
    EXPECT_TRUE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, ComplexExpression3)
{
    vector<string> tokens;
    tokens.push_back("-1");
    tokens.push_back("-2");
    tokens.push_back("*");
    tokens.push_back("-3");
    tokens.push_back("+");
    tokens.push_back("-4");
    tokens.push_back("-");
    EXPECT_TRUE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, ComplexExpression4)
{
    vector<string> tokens;
    tokens.push_back("1");
    tokens.push_back("2");
    tokens.push_back("-");
    tokens.push_back("2");
    tokens.push_back("1");
    tokens.push_back("+");
    tokens.push_back("/");
    EXPECT_TRUE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, NotExpression1)
{
    vector<string> tokens;
    tokens.push_back("-1");
    tokens.push_back("-2");
    tokens.push_back("-3");
    tokens.push_back("-4");
    tokens.push_back("*");
    tokens.push_back("+");
    EXPECT_FALSE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, NotExpression2)
{
    vector<string> tokens;
    tokens.push_back("-1");
    tokens.push_back("-2");
    tokens.push_back("-3");
    tokens.push_back("*");
    tokens.push_back("+");
    tokens.push_back("-");
    EXPECT_FALSE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, NotExpression3)
{
    vector<string> tokens;
    tokens.push_back("-1");
    tokens.push_back("-2");
    tokens.push_back("-3");
    tokens.push_back("-4");
    tokens.push_back("*");
    tokens.push_back("+");
    tokens.push_back("%");
    EXPECT_FALSE(check_postfix_expression(tokens));
}

TEST(CheckPostfixExpression, NotExpression4)
{
    vector<string> tokens;
    tokens.push_back("-1");
    tokens.push_back("*");
    tokens.push_back("-2");
    tokens.push_back("+");
    tokens.push_back("-3");
    tokens.push_back("-");
    tokens.push_back("-4");
    EXPECT_FALSE(check_postfix_expression(tokens));
}

TEST(CalculateExpression, Operand)
{
    vector<string> tokens;
    vector<long> num_stack;
    tokens.push_back("1");
    calculate_expression(tokens, num_stack);
    ASSERT_EQ(num_stack.size(), 1);
    EXPECT_EQ(num_stack[0], 1);
}

TEST(CalculateExpression, SimpleExpression)
{
    vector<string> tokens;
    vector<long> num_stack;
    tokens.push_back("1");
    tokens.push_back("2");
    tokens.push_back("+");
    calculate_expression(tokens, num_stack);
    ASSERT_EQ(num_stack.size(), 1);
    EXPECT_EQ(num_stack[0], 3);
}

TEST(CalculateExpression, ComplexExpression1)
{
    vector<string> tokens;
    vector<long> num_stack;
    //1 2 3 4 * + -
    tokens.push_back("1");
    tokens.push_back("2");
    tokens.push_back("3");
    tokens.push_back("4");
    tokens.push_back("*");
    tokens.push_back("+");
    tokens.push_back("-");
    calculate_expression(tokens, num_stack);
    ASSERT_EQ(num_stack.size(), 1);
    EXPECT_EQ(num_stack[0], -13);
}

TEST(CalculateExpression, ComplexExpression2)
{
    vector<string> tokens;
    vector<long> num_stack;
    //-1 -2 -3 -4 * + -
    tokens.push_back("-1");
    tokens.push_back("-2");
    tokens.push_back("-3");
    tokens.push_back("-4");
    tokens.push_back("*");
    tokens.push_back("+");
    tokens.push_back("-");
    calculate_expression(tokens, num_stack);
    ASSERT_EQ(num_stack.size(), 1);
    EXPECT_EQ(num_stack[0], -11);
}

TEST(CalculateExpression, ComplexExpression3)
{
    vector<string> tokens;
    vector<long> num_stack;
    //-1 -2 * -3 + -4 -
    tokens.push_back("-1");
    tokens.push_back("-2");
    tokens.push_back("*");
    tokens.push_back("-3");
    tokens.push_back("+");
    tokens.push_back("-4");
    tokens.push_back("-");
    calculate_expression(tokens, num_stack);
    ASSERT_EQ(num_stack.size(), 1);
    EXPECT_EQ(num_stack[0], 3);
}

TEST(CalculateExpression, ComplexExpression4)
{
    vector<string> tokens;
    vector<long> num_stack;
    //1 2 - 2 1 + /
    tokens.push_back("1");
    tokens.push_back("2");
    tokens.push_back("-");
    tokens.push_back("2");
    tokens.push_back("1");
    tokens.push_back("+");
    tokens.push_back("/");
    calculate_expression(tokens, num_stack);
    ASSERT_EQ(num_stack.size(), 1);
    EXPECT_EQ(num_stack[0], 0);
}