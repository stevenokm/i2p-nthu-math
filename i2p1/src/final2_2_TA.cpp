#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef struct Point_t
{
    double x;
    double y;
} Point;

typedef struct Triangle_t
{
    Point p[3];
} Triangle;

typedef struct Circle_t
{
    Point p[2];
} Circle;

typedef struct Rectangle_t
{
    Point p[2];
} Rectangle;

const double PI = 3.14159265358979323846;

// parse_header
// Parses the first line of the input.
void parse_header(string &type, int &number_of_points);
// parse_geometry
// Parses the list of points based on the type of geometry.
// Hint: check the number of points and the coordinates.
void parse_geometry(Point &p, const int &number_of_points);
void parse_geometry(Triangle &t, const int &number_of_points);
void parse_geometry(Circle &c, const int &number_of_points);
void parse_geometry(Rectangle &r, const int &number_of_points);
// check_geometry
// Checks if the geometry is valid.
bool check_geometry(const Point &p);
bool check_geometry(const Triangle &t);
bool check_geometry(const Circle &c);
bool check_geometry(const Rectangle &r);
// print_geometry
// Prints the geometry.
void print_geometry(const Point &p);
void print_geometry(const Triangle &t);
void print_geometry(const Circle &c);
void print_geometry(const Rectangle &r);
// print_point
// Prints the coordinates of a point.
void print_point(const Point &p);
// area_geometry
// Calculates the area of the geometry.
double area_geometry(const Point &p);
double area_geometry(const Triangle &t);
double area_geometry(const Circle &c);
double area_geometry(const Rectangle &r);

int main()
{
    string type;
    int number_of_points;

    parse_header(type, number_of_points);

    if (type == "point")
    {
        Point p;
        parse_geometry(p, number_of_points);
        print_geometry(p);
    }
    else if (type == "triangle")
    {
        Triangle t;
        parse_geometry(t, number_of_points);
        print_geometry(t);
    }
    else if (type == "circle")
    {
        Circle c;
        parse_geometry(c, number_of_points);
        print_geometry(c);
    }
    else if (type == "rectangle")
    {
        Rectangle r;
        parse_geometry(r, number_of_points);
        print_geometry(r);
    }
    else
    {
        cout << "Invalid Object" << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void parse_header(string &type, int &number_of_points)
{
    cin >> type >> number_of_points;
}
void parse_geometry(Point &p, const int &number_of_points)
{
    if (number_of_points != 1)
    {
        cout << "Invalid Object" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < number_of_points; i++)
    {
        cin >> p.x >> p.y;
    }
    if (!check_geometry(p))
    {
        cout << "Invalid Object" << endl;
        exit(EXIT_FAILURE);
    }
}
void parse_geometry(Triangle &t, const int &number_of_points)
{
    if (number_of_points != 3)
    {
        cout << "Invalid Object" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < number_of_points; i++)
    {
        cin >> t.p[i].x >> t.p[i].y;
    }
    if (!check_geometry(t))
    {
        cout << "Invalid Object" << endl;
        exit(EXIT_FAILURE);
    }
}
void parse_geometry(Circle &c, const int &number_of_points)
{
    if (number_of_points != 2)
    {
        cout << "Invalid Object" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < number_of_points; i++)
    {
        cin >> c.p[i].x >> c.p[i].y;
    }
    if (!check_geometry(c))
    {
        cout << "Invalid Object" << endl;
        exit(EXIT_FAILURE);
    }
}
void parse_geometry(Rectangle &r, const int &number_of_points)
{
    if (number_of_points != 2)
    {
        cout << "Invalid Object" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < number_of_points; i++)
    {
        cin >> r.p[i].x >> r.p[i].y;
    }
    if (!check_geometry(r))
    {
        cout << "Invalid Object" << endl;
        exit(EXIT_FAILURE);
    }
}
bool check_geometry(const Point &p)
{
    if (p.x < -100.0 || p.y < -100.0 || p.x > 100.0 || p.y > 100.0)
    {
        return false;
    }
    return true;
}
bool check_geometry(const Triangle &t)
{
    for (int i = 0; i < 3; i++)
    {
        if (!check_geometry(t.p[i]))
        {
            return false;
        }
    }
    double ccw = (t.p[1].x - t.p[0].x) * (t.p[2].y - t.p[0].y) 
                - (t.p[2].x - t.p[0].x) * (t.p[1].y - t.p[0].y);
    return (ccw > 0);
}
bool check_geometry(const Circle &c)
{
    if (!check_geometry(c.p[0]) || !check_geometry(c.p[1]))
    {
        return false;
    };
    return (c.p[1].y > c.p[0].y);
}
bool check_geometry(const Rectangle &r)
{
    if (!check_geometry(r.p[0]) || !check_geometry(r.p[1]))
    {
        return false;
    }
    return (r.p[1].y > r.p[0].y);
}
void print_geometry(const Point &p)
{
    cout << "Object Type: point" << endl;
    cout << "Number of Points: 1" << endl;
    cout << "Point: ";
    print_point(p);
    cout << endl;
    cout << "Area: " << area_geometry(p) << endl;
}
void print_geometry(const Triangle &t)
{
    cout << "Object Type: triangle" << endl;
    cout << "Number of Points: 3" << endl;
    cout << "Point: ";
    for (int i = 0; i < 3; i++)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        print_point(t.p[i]);
    }
    cout << endl;
    cout << "Area: " << area_geometry(t) << endl;
}
void print_geometry(const Circle &c)
{
    cout << "Object Type: circle" << endl;
    cout << "Number of Points: 2" << endl;
    cout << "Point: ";
    for (int i = 0; i < 2; i++)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        print_point(c.p[i]);
    }
    cout << endl;
    cout << "Area: " << area_geometry(c) << endl;
}
void print_geometry(const Rectangle &r)
{
    cout << "Object Type: rectangle" << endl;
    cout << "Number of Points: 2" << endl;
    cout << "Point: ";
    for (int i = 0; i < 2; i++)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        print_point(r.p[i]);
    }
    cout << endl;
    cout << "Area: " << area_geometry(r) << endl;
}
void print_point(const Point &p)
{
    cout << "(" << p.x << ", " << p.y << ")";
}
double area_geometry(const Point &p)
{
    return 0.0;
}
double area_geometry(const Triangle &t)
{
    double area = 0.0;
    for (int i = 0; i < 3; i++)
    {
        area += t.p[i].x * t.p[(i + 1) % 3].y - t.p[i].y * t.p[(i + 1) % 3].x;
    }
    return abs(area / 2.0);
}
double area_geometry(const Circle &c)
{
    double x_diff = c.p[1].x - c.p[0].x;
    double y_diff = c.p[1].y - c.p[0].y;
    double radius = sqrt(x_diff * x_diff + y_diff * y_diff);
    return PI * radius * radius;
}
double area_geometry(const Rectangle &r)
{
    return abs(r.p[0].x - r.p[1].x) * abs(r.p[0].y - r.p[1].y);
}