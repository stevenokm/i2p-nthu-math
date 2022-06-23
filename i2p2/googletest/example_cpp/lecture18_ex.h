#include <iostream>
#include <fstream>
#include <cmath>

#ifndef LECTURE18_EX_H

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
    Point_3D(const double &arg_x = 0, const double &arg_y = 0,
             const double &arg_z = 0);
    Point_3D(const Point_3D &arg_point);

    // Destructor
    ~Point_3D() // destructor
    {
        // do nothing, because we don't
        // have any dynamic memory
    }

    // modify the x, y and z coordinate
    void set_x(const double &arg_x);
    void set_y(const double &arg_y);
    void set_z(const double &arg_z);
    void set(const double &arg_x, const double &arg_y, const double &arg_z);
    // get the x, y and z coordinate
    double get_x() const;
    double get_y() const;
    double get_z() const;

    // calculate the distance between two points
    // in form of a vector
    Vector_3D operator-(const Point_3D &arg_point) const;

    // friend class
    friend class Vector_3D;
    // print the x and y coordinate in format (x, y, z)
    // accessable to const object
    friend std::ostream &operator<<(std::ostream &arg_os, const Point_3D &arg_point);
    // read the coordinate of a point from the input,
    // format: (x, y, z) and ignore space
    friend std::istream &operator>>(std::istream &arg_is, Point_3D &arg_point);
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

    // assign operator
    Vector_3D &operator=(const Vector_3D &arg_vector);

    // calculate the length of the Vector_3D
    double length();
    // calculate the dot product of two vectors
    int dot(const Vector_3D &);
    // calculate the cross product of two vectors
    Vector_3D cross(const Vector_3D &);

    // write the Vector_3D in binary format
    void write_binary(std::ofstream &arg_ofs);
    // read the Vector_3D in binary format
    void read_binary(std::ifstream &arg_ifs);
    // print the Vector_3D in format (x, y, z)
    // accessable to const object
    friend std::ostream &operator<<(std::ostream &arg_os,
                                    const Vector_3D &arg_point);
    // read the factors of a vector from the input,
    // format: (x, y, z) and ignore space
    friend std::istream &operator>>(std::istream &arg_is,
                                    Vector_3D &arg_point);
};

// Point_3D class implementation

// Constructor & Default constructor
// initialize data members, with default values
Point_3D::Point_3D(const double &arg_x, const double &arg_y,
                   const double &arg_z)
    : m_x(arg_x),
      m_y(arg_y),
      m_z(arg_z)
{
}

// Copy constructor
// copy the data members from the given object
Point_3D::Point_3D(const Point_3D &arg_point)
    : m_x(arg_point.m_x),
      m_y(arg_point.m_y),
      m_z(arg_point.m_z)
{
}

// modify the x and y coordinate
// we use `arg_` to indicate the arguments
// and re-write with setter
void Point_3D::set_x(const double &arg_x)
{
    m_x = arg_x;
}
void Point_3D::set_y(const double &arg_y)
{
    m_y = arg_y;
}
void Point_3D::set(const double &arg_x, const double &arg_y,
                   const double &arg_z)
{
    m_x = arg_x;
    m_y = arg_y;
    m_z = arg_z;
}

// get the x coordinate and y coordinate
// accessable to const object
double Point_3D::get_x() const
{
    return m_x;
}
double Point_3D::get_y() const
{
    return m_y;
}
double Point_3D::get_z() const
{
    return m_z;
}

// calculate the distance between two points
// in form of a vector
Vector_3D Point_3D::operator-(const Point_3D &arg_point) const
{
    return Vector_3D(*this, arg_point);
}

// print the point in the format (x, y, z)
std::ostream &operator<<(std::ostream &arg_os, const Point_3D &arg_point)
{
    arg_os << "(" << arg_point.m_x << ", " << arg_point.m_y
           << ", " << arg_point.m_z << ")";
    return arg_os;
}

// read the coordinate of a point from the input,
// format: (x, y, z) and ignore space
std::istream &operator>>(std::istream &arg_is, Point_3D &arg_point)
{
    string str_x, str_y, str_z, temp;

    if (getline(arg_is, temp, '(')) // ignore the first '('
    {
        if (getline(arg_is, str_x, ','))
        {
            if (getline(arg_is, str_y, ','))
            {
                if (getline(arg_is, str_z, ')'))
                {
                    arg_point.m_x = stod(str_x);
                    arg_point.m_y = stod(str_y);
                    arg_point.m_z = stod(str_z);
                }
            }
        }
    }
    return arg_is;
}

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

// assign operator
Vector_3D &Vector_3D::operator=(const Vector_3D &arg_vector)
{
    m_x = arg_vector.m_x;
    m_y = arg_vector.m_y;
    m_z = arg_vector.m_z;
    return *this;
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

// write the vector to the file in binary format
void Vector_3D::write_binary(std::ofstream &arg_ofs)
{
    arg_ofs.write((char *)&m_x, sizeof(double));
    arg_ofs.write((char *)&m_y, sizeof(double));
    arg_ofs.write((char *)&m_z, sizeof(double));
}

// read the vector from the file in binary format
void Vector_3D::read_binary(std::ifstream &arg_ifs)
{
    arg_ifs.read((char *)&m_x, sizeof(double));
    arg_ifs.read((char *)&m_y, sizeof(double));
    arg_ifs.read((char *)&m_z, sizeof(double));
}

// print the point in the format (x, y, z)
std::ostream &operator<<(std::ostream &arg_os, const Vector_3D &arg_vector)
{
    arg_os << "(" << arg_vector.m_x << ", " << arg_vector.m_y
           << ", " << arg_vector.m_z << ")";
    return arg_os;
}

// read the factors of a vector from the input,
// format: (x, y, z) and ignore space
std::istream &operator>>(std::istream &arg_is, Vector_3D &arg_vector)
{
    string str_x, str_y, str_z, temp;

    if (getline(arg_is, temp, '(')) // ignore the first '('
    {
        if (getline(arg_is, str_x, ','))
        {
            if (getline(arg_is, str_y, ','))
            {
                if (getline(arg_is, str_z, ')'))
                {
                    arg_vector.m_x = stod(str_x);
                    arg_vector.m_y = stod(str_y);
                    arg_vector.m_z = stod(str_z);
                }
            }
        }
    }
    return arg_is;
}

#endif // LECTURE18_EX_H