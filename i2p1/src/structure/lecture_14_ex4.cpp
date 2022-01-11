#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

typedef struct Vector_t
{
    std::vector<double> unit;
    double length;
} Vector;

typedef struct Matrix_t
{
    std::vector<Vector> row_vectors;
} Matrix;

Vector parse_vector(char input_buffer[], int &i)
{
    Vector v;
    int number = 0
    // parse normal vector
    while (input_buffer[i] != '\0')
    {
        if (input_buffer[i] == '[')
        {
            i++;
        }
        if (input_buffer[i] == '0')
        {
            v.unit.push_back(0);
            i++;
        }
        else
        {
            while (isdigit(input_buffer[i]))
            {
                number = number * 10 + input_buffer[i] - '0';
                i++;
            }
            v.unit.push_back(number);
            number = 0;
        }
        if (input_buffer[i] == ',')
        {
            i++;
        }
        if (input_buffer[i] == ' ')
        {
            i++;
        }
        if (input_buffer[i] == ']')
        {
            break;
        }
    }
    // calc vector length
    for (int j = 0; j < v.unit.size(); j++)
    {
        v.length = v.length + v.unit[j] * v.unit[j];
    }
    v.length = sqrt(v.length);
    // normalize vector
    for (int j = 0; j < v.unit.size(); j++)
    {
        v.unit[j] = v.unit[j] / v.length;
    }
    return v;
}

Matrix parse_matrix(char input_buffer[])
{
    Matrix m;
    // parse matrix
    int i = 0;
    while (input_buffer[i] != '\0')
    {
        if (input_buffer[i] == '[')
        {
            i++;
        }
        while (input_buffer[i] != ']')
        {
            m.row_vectors.push_back(parse_vector(input_buffer, i));
        }
        if (input_buffer[i] == ']')
        {
            i++;
        }
    }
    return m;
}

void print_vector(const Vector &v)
{
    cout << "[";
    for (int i = 0; i < v.unit.size(); i++)
    {
        cout << v.unit[i] * v.length;
        if (i != v.unit.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}

void print_matrix(const Matrix &m)
{
    cout << "[";
    for (int i = 0; i < m.row_vectors.size(); i++)
    {
        print_vector(m.row_vectors[i]);
        cout << endl;
    }
    cout << "]";
}

int main()
{
    char input_buffer[10000 + 1];

    cout << "Enter a vector: ";
    cin.getline(input_buffer, 10000);

    int i = 0;
    Vector v = parse_vector(input_buffer, i);

    cout << "Vector v: " << endl;
    print_vector(v);
    cout << "Length: " << v.length << endl;
    cout << endl;

    cout << "Enter a matrix: ";
    cin.getline(input_buffer, 10000);

    Matrix m = parse_matrix(input_buffer);

    cout << "Matrix m: " << endl;
    print_matrix(m);
    cout << endl;
}
