#include <iostream>
#include <vector>

using namespace std;

typedef struct Point_t
{
    int x;
    int y;
} Point;

typedef struct Triangle_t
{
    Point p[3];
} Triangle;

typedef struct Quadrilateral_t
{
    Point p[4];
} Quadrilateral;

typedef struct Polygon_t
{
    vector<Point> p;
} Polygon;

Point parse_point(char input_buffer[], int i)
{
    Point p;
    while (input_buffer[i] != '\0')
    {
        if (input_buffer[i] == '(')
        {
            i++;
        }
        if (input_buffer[i] == '0')
        {
            p.x = 0;
            i++;
        }
        else
        {
            while (isdigit(input_buffer[i]))
            {
                p.x = p.x * 10 + input_buffer[i] - '0';
                i++;
            }
        }
        if (input_buffer[i] == ',')
        {
            i++;
        }
        if (input_buffer[i] == '0')
        {
            p.y = 0;
            i++;
        }
        else
        {
            while (isdigit(input_buffer[i]))
            {
                p.y = p.y * 10 + input_buffer[i] - '0';
                i++;
            }
        }
        if (input_buffer[i] == ')')
        {
            i++;
        }
    }
    return p;
}

Triangle parse_triangle(char input_buffer[])
{
    Triangle t;
    int i = 0;
    while (input_buffer[i] != '\0')
    {
        for (int j = 0; j < 3; j++)
        {
            if (input_buffer[i] == '(')
            {
                i++;
            }
            t.p[j] = parse_point(input_buffer, i);
            i += 2;
        }
    }
    return t;
}

Quadrilateral parse_quadrilateral(char input_buffer[])
{
    Quadrilateral q;
    int i = 0;
    while (input_buffer[i] != '\0')
    {
        for (int j = 0; j < 4; j++)
        {
            if (input_buffer[i] == '(')
            {
                i++;
            }
            q.p[j] = parse_point(input_buffer, i);
            i += 2;
        }
    }
    return q;
}

Polygon parse_polygon(char input_buffer[])
{
    Polygon poly;
    int i = 0;
    while (input_buffer[i] != '\0')
    {
        if (input_buffer[i] == '(')
        {
            i++;
        }
        poly.p.push_back(parse_point(input_buffer, i));
        i += 2;
    }
    return poly;
}

void print_geometry(const Point &p)
{
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

void print_geometry(const Triangle &t)
{
    cout << "Triangle: " << endl;
    for (int i = 0; i < 3; i++)
    {
        print_geometry(t.p[i]);
    }
}

void print_geometry(const Quadrilateral &q)
{
    cout << "Quadrilateral: " << endl;
    for (int i = 0; i < 4; i++)
    {
        print_geometry(q.p[i]);
    }
}

void print_geometry(const Polygon &poly)
{
    cout << "Polygon: " << endl;
    for (int i = 0; i < poly.p.size(); i++)
    {
        print_geometry(poly.p[i]);
    }
}

unsigned long int area(const Triangle &t)
{
    unsigned long int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += t.p[i].x * t.p[(i + 1) % 3].y;
        sum -= t.p[i].y * t.p[(i + 1) % 3].x;
    }
    return sum / 2;
}

unsigned long int area(const Quadrilateral &q)
{
    unsigned long int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += q.p[i].x * q.p[(i + 1) % 4].y;
        sum -= q.p[i].y * q.p[(i + 1) % 4].x;
    }
    return sum / 2;
}

unsigned long int area(const Polygon &poly)
{
    unsigned long int sum = 0;
    for (int i = 0; i < poly.p.size(); i++)
    {
        sum += poly.p[i].x * poly.p[(i + 1) % poly.p.size()].y;
        sum -= poly.p[i].y * poly.p[(i + 1) % poly.p.size()].x;
    }
    return sum / 2;
}

int main()
{
    char input_buffer[10000 + 1];

    cout << "Enter the type of geometry (t|q|p) with points (x,y): ";
    cin.getline(input_buffer, 10000);

    if (input_buffer[0] == 't')
    {
        Triangle t = parse_triangle(input_buffer);
        print_geometry(t);
        cout << "Area: " << area(t) << endl;
    }
    else if (input_buffer[0] == 'q')
    {
        Quadrilateral q = parse_quadrilateral(input_buffer);
        print_geometry(q);
        cout << "Area: " << area(q) << endl;
    }
    else if (input_buffer[0] == 'p')
    {
        Polygon poly = parse_polygon(input_buffer);
        print_geometry(poly);
        cout << "Area: " << area(poly) << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}