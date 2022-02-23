#include <iostream>

using namespace std;

class Triangle
{
public:
    double x1, y1, x2, y2, x3, y3;

    void init();
    void print();
    void modify(double, double, double, double, double, double);
    double area();
};

void Triangle::init()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    x3 = 0;
    y3 = 0;
}

void Triangle::print()
{
    cout << "Triangle: " << endl;
    cout << "(" << x1 << ", " << y1 << ")" << endl;
    cout << "(" << x2 << ", " << y2 << ")" << endl;
    cout << "(" << x3 << ", " << y3 << ")" << endl;
}

void Triangle::modify(double arg_x1, double arg_y1, double arg_x2,
                      double arg_y2, double arg_x3, double arg_y3)
{
    x1 = arg_x1;
    y1 = arg_y1;
    x2 = arg_x2;
    y2 = arg_y2;
    x3 = arg_x3;
    y3 = arg_y3;
}

double Triangle::area()
{
    return (x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2) / 2;
}

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