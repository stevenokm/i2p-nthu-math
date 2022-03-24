#include <iostream>
#include <cmath>

using namespace std;

class Vector_3D; // forward declaration

class Point_3D // represents a point in 3D space
{
private:
    // record the x coordinate
    double m_x;
    // record the y coordinate
    double m_y;
    // record the z coordinate
    double m_z;

public:
    Point_3D(const double &arg_x = 0, const double &arg_y = 0);
    Point_3D(const Point_3D &arg_point);

    // Destructor
    ~Point_3D() // destructor
    {
        // do nothing, because we don't
        // have any dynamic memory
    }

    // print the x and y coordinate in format (x, y, z)
    void print() const;
    // modify the x, y and z coordinate
    void set_x(const double &arg_x);
    void set_y(const double &arg_y);
    void set_z(const double &arg_z);
    void set(const double &arg_x, const double &arg_y, const double &arg_z);
    // get the x, y and z coordinate
    double get_x() const;
    double get_y() const;
    double get_z() const;

    // friend class
    friend class Vector_3D;
};

// Vector_3D class declaration
class Vector_3D
{
private:
    // define the three factor of the basis vectors
    // on the x, y, z axes
    double m_x, m_y, m_z;

public:
    // Constructor
    Vector_3D(const double &arg_x = 0.0, const double &arg_y = 0.0,
              const double &arg_z = 0.0);
    Vector_3D(const Point_3D &arg_point1, const Point_3D &arg_point2);

    // Copy constructor
    Vector_3D(const Vector_3D &arg_vector);

    // Destructor
    ~Vector_3D()
    {
        // do nothing
    }

    // print the Vector_3D
    void print();

    // set the three factor of the basis vectors
    void set_vector(const double &arg_x, const double &arg_y,
                    const double &arg_z);
    void set_vector(const Point_3D &arg_point1, const Point_3D &arg_point2);
    void set_x(const double &arg_x);
    void set_y(const double &arg_y);
    void set_z(const double &arg_z);
    // get the three factor of the basis vectors
    double get_x() const;
    double get_y() const;
    double get_z() const;

    // calculate the length of the Vector_3D
    double length();
    // calculate the dot product of two vectors
    int dot(const Vector_3D &);
    // calculate the cross product of two vectors
    Vector_3D cross(const Vector_3D &);
};

// Vector_3D class implementation

// Constructor
Vector_3D::Vector_3D(const double &arg_x, const double &arg_y,
                     const double &arg_z)
    : m_x(arg_x), m_y(arg_y), m_z(arg_z)
{
}

Vector_3D::Vector_3D(const Point_3D &arg_point1, const Point_3D &arg_point2)
    : m_x(arg_point2.m_x - arg_point1.m_x),
      m_y(arg_point2.m_y - arg_point1.m_y),
      m_z(arg_point2.m_z - arg_point1.m_z)
{
}

// Copy constructor
Vector_3D::Vector_3D(const Vector_3D &arg_vector)
    : m_x(arg_vector.m_x), m_y(arg_vector.m_y), m_z(arg_vector.m_z)
{
}

// print the Vector_3D
void Vector_3D::print()
{
    // print the three factor of the basis vectors
    cout << "Vector_3D: " << endl;
    cout << "(" << m_x << ", " << m_y << ", " << m_z << ")" << endl;
}

// set the three factor of the basis vectors
void Vector_3D::set_vector(const double &arg_x, const double &arg_y,
                           const double &arg_z)
{
    m_x = arg_x;
    m_y = arg_y;
    m_z = arg_z;
}
void Vector_3D::set_vector(const Point_3D &arg_point1,
                           const Point_3D &arg_point2)
{
    m_x = arg_point2.m_x - arg_point1.m_x;
    m_y = arg_point2.m_y - arg_point1.m_y;
    m_z = arg_point2.m_z - arg_point1.m_z;
}
void Vector_3D::set_x(const double &arg_x)
{
    m_x = arg_x;
}
void Vector_3D::set_y(const double &arg_y)
{
    m_y = arg_y;
}
void Vector_3D::set_z(const double &arg_z)
{
    m_z = arg_z;
}
// get the three factor of the basis vectors
double Vector_3D::get_x() const
{
    return m_x;
}
double Vector_3D::get_y() const
{
    return m_y;
}
double Vector_3D::get_z() const
{
    return m_z;
}

// calculate the length of the Vector_3D
double Vector_3D::length()
{
    // calculate the length of the Vector_3D
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

// calculate the dot product of two vectors
int Vector_3D::dot(const Vector_3D &arg_v)
{
    // calculate the dot product of two vectors
    return m_x * arg_v.m_x + m_y * arg_v.m_y + m_z * arg_v.m_z;
}

// calculate the cross product of two vectors
Vector_3D Vector_3D::cross(const Vector_3D &arg_v)
{
    // calculate the cross product of two vectors
    Vector_3D v;
    v.m_x = m_y * arg_v.m_z - m_z * arg_v.m_y;
    v.m_y = m_z * arg_v.m_x - m_x * arg_v.m_z;
    v.m_z = m_x * arg_v.m_y - m_y * arg_v.m_x;
    return v;
}

// main function

int main()
{
    Vector_3D v1;
    v1.print();
    cout << endl;
    cout << "Length of v1: " << v1.length() << endl;
    v1.set_vector(1.0, 2.0, 3.0);
    v1.print();
    cout << endl;
    cout << "Length of v1: " << v1.length() << endl;
    cout << endl;

    Vector_3D v2(v1);
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
    Vector_3D v3(v1.cross(v2));
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