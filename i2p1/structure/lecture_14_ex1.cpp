#include <iostream>
#include <cctype>  // isdigit()
#include <cmath>   // pow()
#include <climits> // INT_MAX

using namespace std;

typedef struct Float_t
{
    int sign;
    int exp;
    long mantissa;
} Float;

void normalize_float(Float &f)
{
    while (f.mantissa > 0 && f.mantissa % 10 == 0)
    {
        f.mantissa /= 10;
        f.exp++;
    }
    while (f.mantissa > INT_MAX)
    {
        f.mantissa /= 10;
        f.exp++;
    }
    if (f.mantissa == 0)
    {
        f.exp = 0;
        f.sign = 1;
    }
}

Float parse_float_number(char input_buffer[])
{
    Float result;
    result.sign = 1;
    result.exp = 0;
    result.mantissa = 0;

    int i = 0;
    if (input_buffer[i] == '-')
    {
        result.sign = -1;
        i++;
    }

    if (input_buffer[i] == '0')
    {
        i++;
    }
    else
    {
        while (isdigit(input_buffer[i]))
        {
            result.mantissa = result.mantissa * 10 + input_buffer[i] - '0';
            i++;
        }
    }

    if (input_buffer[i] == '.')
    {
        i++;
        int factor = 1;
        while (isdigit(input_buffer[i]))
        {
            result.mantissa = result.mantissa * 10 + input_buffer[i] - '0';
            factor *= 10;
            i++;
        }
        result.exp = -1 * (int)log10(factor);
    }

    if (input_buffer[i] == 'e' || input_buffer[i] == 'E')
    {
        i++;
        int exp = 0;
        if (input_buffer[i] == '-')
        {
            i++;
            while (isdigit(input_buffer[i]))
            {
                exp = exp * 10 + input_buffer[i] - '0';
                i++;
            }
            result.exp += -1 * exp;
        }
        else
        {
            while (isdigit(input_buffer[i]))
            {
                exp = exp * 10 + input_buffer[i] - '0';
                i++;
            }
            result.exp += exp;
        }
    }
    // normalize the result float
    normalize_float(result);
    return result;
}

void print_float_number(Float number)
{
    if (number.sign == -1)
    {
        cout << "-";
    }
    cout << number.mantissa;
    if (number.exp != 0)
    {
        cout << "e" << number.exp;
    }
}

void clean_up_input_buffer(char input_buffer[])
{
    for (int i = 0; input_buffer[i] != '\0'; i++)
    {
        input_buffer[i] = '\0';
    }
}

Float add(Float a, Float b)
{
    Float result;
    int same_sign = a.sign * b.sign;
    if (a.exp == b.exp)
    {
        result.sign = a.sign;
        result.exp = a.exp;
        result.mantissa = a.mantissa + same_sign * b.mantissa;
    }
    else if (a.exp > b.exp)
    {
        result.sign = a.sign;
        result.exp = a.exp;
        long exp_factor = (long)pow(10, a.exp - b.exp);
        result.mantissa = a.mantissa + same_sign * b.mantissa / exp_factor;
    }
    else
    {
        result.sign = b.sign;
        result.exp = b.exp;
        long exp_factor = (long)pow(10, b.exp - a.exp);
        result.mantissa = b.mantissa + same_sign * a.mantissa / exp_factor;
    }
    if (result.mantissa < 0)
    {
        result.sign *= -1;
        result.mantissa *= -1;
    } else if (result.mantissa == 0) {
        result.sign = 1;
    }
    normalize_float(result);
    return result;
}

Float sub(Float a, Float b)
{
    Float result;
    int same_sign = a.sign * b.sign;
    if (a.exp == b.exp)
    {
        result.sign = a.sign;
        result.exp = a.exp;
        result.mantissa = a.mantissa - same_sign * b.mantissa;
    }
    else if (a.exp > b.exp)
    {
        result.sign = a.sign;
        result.exp = a.exp;
        long exp_factor = (long)pow(10, a.exp - b.exp);
        result.mantissa = a.mantissa - same_sign * b.mantissa / exp_factor;
    }
    else
    {
        result.sign = b.sign;
        result.exp = b.exp;
        long exp_factor = (long)pow(10, b.exp - a.exp);
        result.mantissa = b.mantissa - same_sign * a.mantissa / exp_factor;
    }
    if (result.mantissa < 0)
    {
        result.sign *= -1;
        result.mantissa *= -1;
    } else if (result.mantissa == 0) {
        result.sign = 1;
    }
    normalize_float(result);
    return result;
}

Float mul(Float a, Float b)
{
    Float result;
    result.sign = a.sign * b.sign;
    result.exp = a.exp + b.exp;
    result.mantissa = a.mantissa * b.mantissa;
    normalize_float(result);
    return result;
}

Float div(Float a, Float b)
{
    Float result;
    result.sign = a.sign * b.sign;
    result.exp = a.exp - b.exp;
    result.mantissa = a.mantissa / b.mantissa;
    normalize_float(result);
    return result;
}

int main()
{
    char input_buffer[10000 + 1]; // + 1 for the last '\0'
    Float a, b;

    cout << "Input a float number (a) in (-)xxx.xxx(e|E)(-)(xxx): ";
    cin >> input_buffer;

    a = parse_float_number(input_buffer);

    clean_up_input_buffer(input_buffer);

    cout << "(a) = ";
    print_float_number(a);
    cout << endl;

    cout << "Input a float number (b) in (-)xxx.xxx(e|E)(-)(xxx): ";
    cin >> input_buffer;

    b = parse_float_number(input_buffer);

    clean_up_input_buffer(input_buffer);

    cout << "(b) = ";
    print_float_number(b);
    cout << endl;

    cout << "(a) + (b) = ";
    print_float_number(add(a, b));
    cout << endl;

    cout << "(a) - (b) = ";
    print_float_number(sub(a, b));
    cout << endl;

    cout << "(a) * (b) = ";
    print_float_number(mul(a, b));
    cout << endl;

    cout << "(a) / (b) = ";
    print_float_number(div(a, b));
    cout << endl;

    return 0;
}