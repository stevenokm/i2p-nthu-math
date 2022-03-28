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
    // Constructor
    Vector(const double &arg_x = 0.0, const double &arg_y = 0.0,
           const double &arg_z = 0.0);

    // Copy constructor
    Vector(const Vector &arg_vector);

    // Destructor
    ~Vector()
    {
        // do nothing
    }

    // print the vector
    void print();

    // set the three factor of the basis vectors
    void set_vector(const double &arg_x, const double &arg_y,
                    const double &arg_z);
    void set_x(const double &arg_x);
    void set_y(const double &arg_y);
    void set_z(const double &arg_z);
    // get the three factor of the basis vectors
    double get_x() const;
    double get_y() const;
    double get_z() const;

    // calculate the length of the vector
    double length();
    // calculate the dot product of two vectors
    int dot(const Vector &);
    // calculate the cross product of two vectors
    Vector cross(const Vector &);
};

// Vector class implementation

// Constructor
Vector::Vector(const double &arg_x, const double &arg_y,
               const double &arg_z)
    : m_x(arg_x), m_y(arg_y), m_z(arg_z)
{
}

// Copy constructor
Vector::Vector(const Vector &arg_vector)
    : m_x(arg_vector.m_x), m_y(arg_vector.m_y), m_z(arg_vector.m_z)
{
}

// print the vector
void Vector::print()
{
    // print the three factor of the basis vectors
    cout << "Vector: " << endl;
    cout << "(" << m_x << ", " << m_y << ", " << m_z << ")" << endl;
}

// set the three factor of the basis vectors
void Vector::set_vector(const double &arg_x, const double &arg_y,
                        const double &arg_z)
{
    m_x = arg_x;
    m_y = arg_y;
    m_z = arg_z;
}
void Vector::set_x(const double &arg_x)
{
    m_x = arg_x;
}
void Vector::set_y(const double &arg_y)
{
    m_y = arg_y;
}
void Vector::set_z(const double &arg_z)
{
    m_z = arg_z;
}
// get the three factor of the basis vectors
double Vector::get_x() const
{
    return m_x;
}
double Vector::get_y() const
{
    return m_y;
}
double Vector::get_z() const
{
    return m_z;
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
    Vector v1;
    v1.print();
    cout << endl;
    cout << "Length of v1: " << v1.length() << endl;
    v1.set_vector(1.0, 2.0, 3.0);
    v1.print();
    cout << endl;
    cout << "Length of v1: " << v1.length() << endl;
    cout << endl;

    Vector v2(v1);
    v2.print();
    cout << endl;
    cout << "Length of v2: " << v2.length() << endl;
    v2.set_vector(2.0, 3.0, 4.0);
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

    v2.set_vector(1.0, 1.0, 1.0);
    Vector v3(v1.cross(v2));
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