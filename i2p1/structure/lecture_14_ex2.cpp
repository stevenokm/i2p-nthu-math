#include <iostream>
#include <cctype> // isdigit()
#include <vector>

using namespace std;

typedef struct Poly_t
{
    int coef;
    int exp;
} Poly;

void normalize(vector<Poly> &poly)
{
    for (int i = 0; i < poly.size(); i++)
    {
        if (poly[i].coef == 0)
        {
            poly.erase(poly.begin() + i);
            i--;
        }
    }
}

vector<Poly> parse_poly(char input_buffer[])
{
    vector<Poly> result;
    int i = 0;
    while (input_buffer[i] != '\0')
    {
        Poly p;
        int sign = 1;
        p.coef = 0;
        p.exp = 0;
        if (input_buffer[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (input_buffer[i] == '+')
        {
            i++;
        }
        if (input_buffer[i] == '0')
        {
            p.coef = 0;
            i++;
        }
        else
        {
            while (isdigit(input_buffer[i]))
            {
                p.coef = p.coef * 10 + input_buffer[i] - '0';
                i++;
            }
        }
        p.coef *= sign;
        if (input_buffer[i] == 'x')
        {
            i++;
            if (input_buffer[i] == '^')
            {
                i++;
                while (isdigit(input_buffer[i]))
                {
                    p.exp = p.exp * 10 + input_buffer[i] - '0';
                    i++;
                }
            }
        }
        result.push_back(p);
    }
    return result;
}

void print_poly(const vector<Poly> &poly)
{
    if (poly.size() == 0)
    {
        cout << "0";
        return;
    }
    for (int i = 0; i < poly.size(); i++)
    {
        if (poly[i].coef == 0)
        {
            continue;
        }
        if (poly[i].coef >= 1 && i != 0)
        {
            cout << "+" << poly[i].coef;
        }
        else if (poly[i].coef == -1)
        {
            cout << "-";
        }
        else
        {
            cout << poly[i].coef;
        }
        if (poly[i].exp == 0)
        {
            continue;
        }
        else
        {
            cout << "x^" << poly[i].exp;
        }
    }
}

vector<Poly> poly_add(const vector<Poly> &a, const vector<Poly> &b)
{
    vector<Poly> result;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i].exp == b[j].exp)
        {
            Poly p;
            p.exp = a[i].exp;
            p.coef = a[i].coef + b[j].coef;
            result.push_back(p);
            i++;
            j++;
        }
        else if (a[i].exp > b[j].exp)
        {
            result.push_back(a[i]);
            i++;
        }
        else
        {
            result.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        result.push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        result.push_back(b[j]);
        j++;
    }
    normalize(result);
    return result;
}

void clean_up_input_buffer(char input_buffer[])
{
    for (int i = 0; input_buffer[i] != '\0'; i++)
    {
        input_buffer[i] = '\0';
    }
}

int main()
{
    char input_buffer[10000 + 1];
    vector<Poly> a, b;

    cout << "Enter polynomial a: ";
    cin >> input_buffer;

    a = parse_poly(input_buffer);

    clean_up_input_buffer(input_buffer);

    cout << "Polynomial a: ";
    print_poly(a);
    cout << endl;

    cout << "Enter polynomial b: ";
    cin >> input_buffer;

    b = parse_poly(input_buffer);

    clean_up_input_buffer(input_buffer);

    cout << "Polynomial b: ";
    print_poly(b);
    cout << endl;

    vector<Poly> c = poly_add(a, b);

    cout << "Polynomial c = a + b: ";
    print_poly(c);
    cout << endl;
}