#include <iostream>

using namespace std;

// Triangle class declaration
class Triangle
{
private:
    // define three points of the triangle
    // in x1, y1, x2, y2, x3, y3 format
    double m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;

public:
    // initialize the triangle
    void init();
    // print the triangle
    void print();
    // modify the three points of the triangle
    void modify(double, double, double,
                double, double, double);
    // calculate the area of the triangle
    double area();
};

// Triangle class implementation

// initialize the triangle
void Triangle::init()
{
    // initialize the three points of the triangle
    m_x1 = 0.0;
    m_y1 = 0.0;
    m_x2 = 1.0;
    m_y2 = 0.0;
    m_x3 = 0.0;
    m_y3 = 1.0;
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

// modify the three points of the triangle
void Triangle::modify(double arg_x1, double arg_y1,
                      double arg_x2, double arg_y2,
                      double arg_x3, double arg_y3)
{
    // modify the three points of the triangle
    m_x1 = arg_x1;
    m_y1 = arg_y1;
    m_x2 = arg_x2;
    m_y2 = arg_y2;
    m_x3 = arg_x3;
    m_y3 = arg_y3;
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
    Triangle t;
    t.init();
    t.print();
    t.modify(1, 1, 2, 2, 0, 3);
    t.print();
    cout << "Area: " << t.area() << endl;
    return 0;
}