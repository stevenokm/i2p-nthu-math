#include <iostream>
#include <cmath>

using namespace std;

// Vector class declaration
class Vector
{
private:
    // define the three factor of the basis vectors
    // on the x, y, z axes
    double m_x, m_y, m_z;

public:
    // initialize the vector
    void init();
    // print the vector
    void print();
    // modify the three factor of the basis vectors
    void modify(double, double, double);
    // calculate the length of the vector
    double length();
    // calculate the dot product of two vectors
    int dot(const Vector &);
    // calculate the cross product of two vectors
    Vector cross(const Vector &);
};

// initialize the vector
void Vector::init()
{
    // initialize the three factor of the basis vectors
    m_x = 0.0;
    m_y = 0.0;
    m_z = 0.0;
}

// print the vector
void Vector::print()
{
    // print the three factor of the basis vectors
    cout << "Vector: " << endl;
    cout << "(" << m_x << ", " << m_y << ", " << m_z << ")" << endl;
}

// modify the three factor of the basis vectors
void Vector::modify(double arg_x, double arg_y, double arg_z)
{
    // modify the three factor of the basis vectors
    m_x = arg_x;
    m_y = arg_y;
    m_z = arg_z;
}

// calculate the length of the vector
double Vector::length()
{
    // calculate the length of the vector
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

// calculate the dot product of two vectors
int Vector::dot(const Vector &arg_v)
{
    // calculate the dot product of two vectors
    return m_x * arg_v.m_x + m_y * arg_v.m_y + m_z * arg_v.m_z;
}

// calculate the cross product of two vectors
Vector Vector::cross(const Vector &arg_v)
{
    // calculate the cross product of two vectors
    Vector v;
    v.m_x = m_y * arg_v.m_z - m_z * arg_v.m_y;
    v.m_y = m_z * arg_v.m_x - m_x * arg_v.m_z;
    v.m_z = m_x * arg_v.m_y - m_y * arg_v.m_x;
    return v;
}

// main function

int main()
{
    Vector v1, v2;
    v1.init();
    v1.print();
    cout << endl;
    cout << "Length of v1: " << v1.length() << endl;
    v1.modify(1, 1, 1);
    v1.print();
    cout << endl;
    cout << "Length of v1: " << v1.length() << endl;
    cout << endl;

    v2.init();
    v2.print();
    cout << endl;
    cout << "Length of v2: " << v2.length() << endl;
    v2.modify(2, 3, 4);
    v2.print();
    cout << endl;
    cout << "Length of v2: " << v2.length() << endl;
    cout << endl;

    cout << "v1: ";
    v1.print();
    cout << endl;
    cout << "v2: ";
    v2.print();
    cout << endl;
    cout << "Dot: " << v1.dot(v2) << endl;
    cout << endl;

    v2.modify(5, 6, 7);
    Vector v3 = v1.cross(v2);
    cout << "v1: ";
    v1.print();
    cout << endl;
    cout << "v2: ";
    v2.print();
    cout << endl;
    cout << "Cross: ";
    v3.print();
    cout << endl;
    cout << endl;

    return 0;
}