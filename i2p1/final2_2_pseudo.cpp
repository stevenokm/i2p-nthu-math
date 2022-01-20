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
