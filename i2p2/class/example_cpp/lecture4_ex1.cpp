#include <iostream>

using namespace std;

// Triangle class declaration
class Triangle
{
private:
    // define three points of the triangle
    // in x1, y1, x2, y2, x3, y3 format
    double m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;

    // check & correct the triangle points to counterclockwise order
    void _check_points();

public:
    // Constructor
    Triangle(const double &arg_x1 = 0.0, const double &arg_y1 = 0.0,
             const double &arg_x2 = 0.0, const double &arg_y2 = 0.0,
             const double &arg_x3 = 0.0, const double &arg_y3 = 0.0);

    // Copy constructor
    Triangle(const Triangle &arg_triangle);

    // Destructor
    ~Triangle()
    {
        // do nothing
    }

    // print the triangle
    void print();
    // modify the three points of the triangle
    void set_points(const double &arg_x1, const double &arg_y1,
                    const double &arg_x2, const double &arg_y2,
                    const double &arg_x3, const double &arg_y3);
    void set_point1(const double &arg_x1, const double &arg_y1);
    void set_point2(const double &arg_x2, const double &arg_y2);
    void set_point3(const double &arg_x3, const double &arg_y3);
    void set_x1(const double &arg_x1);
    void set_y1(const double &arg_y1);
    void set_x2(const double &arg_x2);
    void set_y2(const double &arg_y2);
    void set_x3(const double &arg_x3);
    void set_y3(const double &arg_y3);
    // get the three points of the triangle
    double get_x1() const;
    double get_y1() const;
    double get_x2() const;
    double get_y2() const;
    double get_x3() const;
    double get_y3() const;

    // calculate the area of the triangle
    double area();
};

// Triangle class implementation

// check & correct the triangle points to counterclockwise order
void Triangle::_check_points()
{
    // calculate the area of the triangle
    double area = (m_x1 * (m_y2 - m_y3) + m_x2 * (m_y3 - m_y1) 
                + m_x3 * (m_y1 - m_y2)) / 2.0;

    // if the area is negative, swap the points
    if (area < 0.0)
    {
        double temp_x = m_x1;
        double temp_y = m_y1;
        m_x1 = m_x2;
        m_y1 = m_y2;
        m_x2 = temp_x;
        m_y2 = temp_y;
    }
}

// Constructor
Triangle::Triangle(const double &arg_x1, const double &arg_y1,
                   const double &arg_x2, const double &arg_y2,
                   const double &arg_x3, const double &arg_y3)
    : m_x1(arg_x1), m_y1(arg_y1), m_x2(arg_x2), m_y2(arg_y2),
      m_x3(arg_x3), m_y3(arg_y3)
{
    // check & correct the triangle points to counterclockwise order
    _check_points();
}

// Copy constructor
Triangle::Triangle(const Triangle &arg_triangle)
    : m_x1(arg_triangle.m_x1), m_y1(arg_triangle.m_y1),
      m_x2(arg_triangle.m_x2), m_y2(arg_triangle.m_y2),
      m_x3(arg_triangle.m_x3), m_y3(arg_triangle.m_y3)
{
}

// print the triangle
void Triangle::print()
{
    // print the three points of the triangle
    cout << "Triangle: " << endl;
    cout << "(" << m_x1 << ", " << m_y1 << ")" << endl;
    cout << "(" << m_x2 << ", " << m_y2 << ")" << endl;
    cout << "(" << m_x3 << ", " << m_y3 << ")" << endl;
}

// set the three points of the triangle
void Triangle::set_points(const double &arg_x1, const double &arg_y1,
                          const double &arg_x2, const double &arg_y2,
                          const double &arg_x3, const double &arg_y3)
{
    m_x1 = arg_x1;
    m_y1 = arg_y1;
    m_x2 = arg_x2;
    m_y2 = arg_y2;
    m_x3 = arg_x3;
    m_y3 = arg_y3;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}
void Triangle::set_point1(const double &arg_x1, const double &arg_y1)
{
    m_x1 = arg_x1;
    m_y1 = arg_y1;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}
void Triangle::set_point2(const double &arg_x2, const double &arg_y2)
{
    m_x2 = arg_x2;
    m_y2 = arg_y2;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}
void Triangle::set_point3(const double &arg_x3, const double &arg_y3)
{
    m_x3 = arg_x3;
    m_y3 = arg_y3;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}
void Triangle::set_x1(const double &arg_x1)
{
    m_x1 = arg_x1;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}
void Triangle::set_y1(const double &arg_y1)
{
    m_y1 = arg_y1;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}
void Triangle::set_x2(const double &arg_x2)
{
    m_x2 = arg_x2;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}
void Triangle::set_y2(const double &arg_y2)
{
    m_y2 = arg_y2;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}
void Triangle::set_x3(const double &arg_x3)
{
    m_x3 = arg_x3;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}
void Triangle::set_y3(const double &arg_y3)
{
    m_y3 = arg_y3;

    // check & correct the triangle points to counterclockwise order
    _check_points();
}

// get the three points of the triangle
double Triangle::get_x1() const
{
    return m_x1;
}
double Triangle::get_y1() const
{
    return m_y1;
}
double Triangle::get_x2() const
{
    return m_x2;
}
double Triangle::get_y2() const
{
    return m_y2;
}
double Triangle::get_x3() const
{
    return m_x3;
}
double Triangle::get_y3() const
{
    return m_y3;
}

// calculate the area of the triangle
double Triangle::area()
{
    // calculate the area of the triangle
    return (m_x1 * (m_y2 - m_y3) + m_x2 * (m_y3 - m_y1) + m_x3 * (m_y1 - m_y2)) / 2.0;
}

// main function

int main()
{
    Triangle t(1, 1, 2, 2, 0, 3);
    t.print();
    cout << "Area: " << t.area() << endl;

    // change the points of the triangle
    t.set_points(1, 2, 2, 3, 3, 1);
    t.print();
    cout << "Area: " << t.area() << endl;

    return 0;
}