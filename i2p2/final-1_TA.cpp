#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <exception>

using namespace std;

class Geometry_ND;

class Point_ND
{
private:
    vector<double> m_coords;
    unsigned m_dim;
    friend class Geometry_ND;

public:
    // Constructor, initializes the array
    Point_ND(const unsigned &arg_dim = 2);
    // Copy constructor
    Point_ND(const Point_ND &arg_point);
    // assignment operator
    Point_ND &operator=(const Point_ND &arg_point);
    // get coordinates
    vector<double> get_coords() const;
    // get dimension
    unsigned get_dim() const;
    // set coordinates
    void set_coords(const vector<double> &arg_coords);
    // cout `<<` operator for print Point_ND number
    friend ostream &operator<<(ostream &arg_os, const Point_ND &arg_point);
    // cin `>>` operator for input Point_ND number
    friend istream &operator>>(istream &arg_is, Point_ND &arg_point);
    // friend class
    friend class Geometry_ND;
};

class Geometry_ND
{
protected:
    // data members
    vector<Point_ND> m_point_array;
    unsigned m_dim;

public:
    // Constructor, initializes the array
    Geometry_ND(const unsigned &arg_dim = 2,
                const unsigned int &arg_num_of_vertex = 0);
    // Copy constructor
    Geometry_ND(const Geometry_ND &arg_geometry);
    // assignment operator
    Geometry_ND &operator=(const Geometry_ND &arg_geometry);
    // print the geometry
    virtual void print_geometry();
    // parse the cin to the geometry
    virtual void parse_geometry(istream &arg_is);
    // set the geometry
    void set_geometry(const vector<Point_ND> &arg_point_array);
    // get the geometry array
    vector<Point_ND> get_geometry_array();
};

class Triangle_ND : public Geometry_ND
{
public:
    // Constructor, initializes the array
    Triangle_ND(const unsigned &arg_dim = 2);
    // Copy constructor
    Triangle_ND(const Triangle_ND &arg_triangle);
    // assignment operator
    Triangle_ND &operator=(const Triangle_ND &arg_triangle);
    // print the geometry
    void print_geometry();
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is);
};
const unsigned triangle_num_of_vertex = 3;

class Polygon_ND : public Geometry_ND
{
public:
    // Constructor, initializes the array
    Polygon_ND(const unsigned &arg_dim = 2);
    // Copy constructor
    Polygon_ND(const Polygon_ND &arg_polygon);
    // assignment operator
    Polygon_ND &operator=(const Polygon_ND &arg_polygon);
    // print the geometry
    void print_geometry();
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is);
};

class Line_ND : public Geometry_ND
{
public:
    // Constructor, initializes the array
    Line_ND(const unsigned &arg_dim = 2);
    // Copy constructor
    Line_ND(const Line_ND &arg_line);
    // assignment operator
    Line_ND &operator=(const Line_ND &arg_line);
    // print the geometry
    void print_geometry();
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is);
};
const unsigned line_num_of_vertex = 2;

// Point_ND class implementation

// Constructor
Point_ND::Point_ND(const unsigned &arg_dim)
    : m_dim(arg_dim), m_coords(arg_dim)
{
}

// Copy constructor
Point_ND::Point_ND(const Point_ND &arg_point)
    : m_dim(arg_point.m_dim), m_coords(arg_point.m_coords)
{
}

// assignment operator
Point_ND &Point_ND::operator=(const Point_ND &arg_point)
{
    if (this != &arg_point)
    {
        m_dim = arg_point.m_dim;
        m_coords = arg_point.m_coords;
    }
    return *this;
}

// get dimension
unsigned Point_ND::get_dim() const
{
    return m_dim;
}

// get coordinates
vector<double> Point_ND::get_coords() const
{
    return m_coords;
}

// set coordinates
void Point_ND::set_coords(const vector<double> &arg_coords)
{
    m_coords = arg_coords;
}

// cout `<<` operator for print Point_ND number
ostream &operator<<(ostream &arg_os, const Point_ND &arg_point)
{
    for (unsigned i = 0; i < arg_point.m_dim; i++)
    {
        if (i != 0)
        {
            arg_os << ",";
        }
        arg_os << arg_point.m_coords[i];
    }
    arg_os << flush;
    return arg_os;
}

// cin `>>` operator for input Point_ND number
istream &operator>>(istream &arg_is, Point_ND &arg_point)
{
    string line;
    getline(arg_is, line);
    istringstream iss(line);
    for (unsigned i = 0; i < arg_point.m_dim; i++)
    {
        string buf;
        double input_num;
        getline(iss, buf, ',');
        input_num = stod(buf);
        arg_point.m_coords[i] = input_num;
    }
    return arg_is;
}

// Geometry_ND class implementation

// Constructor, initializes the array
Geometry_ND::Geometry_ND(const unsigned &arg_dim, const unsigned int &arg_num_of_vertex)
    : m_dim(arg_dim), m_point_array(arg_num_of_vertex)
{
}
// Copy constructor
Geometry_ND::Geometry_ND(const Geometry_ND &arg_geometry)
    : m_dim(arg_geometry.m_dim), m_point_array(arg_geometry.m_point_array)
{
}
// assignment operator
Geometry_ND &Geometry_ND::operator=(const Geometry_ND &arg_geometry)
{
    if (this == &arg_geometry) // self-assignment
        return *this;
    m_point_array = arg_geometry.m_point_array;
    return *this;
}
// print the geometry
void Geometry_ND::print_geometry()
{
    throw runtime_error("print_geometry() is not implemented");
}
// parse the cin to the geometry
void Geometry_ND::parse_geometry(istream &arg_is)
{
    throw runtime_error("parse_geometry() is not implemented");
}
// set the geometry
void Geometry_ND::set_geometry(const vector<Point_ND> &arg_point_array)
{
    // check the dimension
    for (unsigned i = 0; i < arg_point_array.size(); i++)
    {
        if (arg_point_array[i].get_dim() != m_dim)
        {
            throw runtime_error("The dimension of the geometry is not consistent");
        }
    }
    m_point_array = arg_point_array;
}
// get the geometry array
vector<Point_ND> Geometry_ND::get_geometry_array()
{
    return m_point_array;
}

// Triangle_ND class implementation

// Constructor, initializes the array
Triangle_ND::Triangle_ND(const unsigned &arg_dim)
    : Geometry_ND(arg_dim, triangle_num_of_vertex)
{
}
// Copy constructor
Triangle_ND::Triangle_ND(const Triangle_ND &arg_triangle)
    : Geometry_ND(arg_triangle)
{
}
// assignment operator
Triangle_ND &Triangle_ND::operator=(const Triangle_ND &arg_triangle)
{
    if (this == &arg_triangle) // self-assignment
        return *this;
    Geometry_ND::operator=(arg_triangle);
    return *this;
}
// print the geometry
void Triangle_ND::print_geometry()
{
    cout << "t" << endl;
    cout << m_point_array.size() << endl;
    for (int i = 0; i < triangle_num_of_vertex; i++)
    {
        cout << m_point_array[i] << endl;
    }
}
// parse the cin to the geometry
void Triangle_ND::parse_geometry(istream &arg_is)
{
    string temp;
    getline(arg_is, temp); // get the vertex number
    stringstream ss(temp);
    unsigned int vertex_num;
    ss >> vertex_num;
    if (vertex_num != triangle_num_of_vertex)
    {
        throw runtime_error("Triangle_ND::parse_geometry(): wrong vertex number");
    }

    for (int i = 0; i < vertex_num; i++)
    {
        getline(arg_is, temp);
        stringstream ss(temp);
        Point_ND point(m_dim);
        ss >> point;
        m_point_array[i] = point;
    }
}

// Polygon_ND class implementation

// Constructor, initializes the array
Polygon_ND::Polygon_ND(const unsigned &arg_dim)
    : Geometry_ND(arg_dim)
{
}
// Copy constructor
Polygon_ND::Polygon_ND(const Polygon_ND &arg_polygon)
    : Geometry_ND(arg_polygon)
{
}
// assignment operator
Polygon_ND &Polygon_ND::operator=(const Polygon_ND &arg_polygon)
{
    if (this == &arg_polygon) // self-assignment
        return *this;
    Geometry_ND::operator=(arg_polygon);
    return *this;
}
// print the geometry
void Polygon_ND::print_geometry()
{
    cout << "p" << endl;
    cout << m_point_array.size() << endl;
    for (int i = 0; i < m_point_array.size(); i++)
    {
        cout << m_point_array[i] << endl;
    }
}
// parse the cin to the geometry
void Polygon_ND::parse_geometry(istream &arg_is)
{
    string temp;
    getline(arg_is, temp); // get the vertex number
    int vertex_num = stoi(temp);
    if (vertex_num < triangle_num_of_vertex)
    {
        throw runtime_error("Polygon_ND::parse_geometry(): the number of vertex is less than 3");
    }
    m_point_array.resize(vertex_num);
    for (int i = 0; i < vertex_num; i++)
    {
        getline(arg_is, temp);
        stringstream ss(temp);
        Point_ND point(m_dim);
        ss >> point;
        m_point_array[i] = point;
    }
}

// Line_ND class implementation

// Constructor, initializes the array
Line_ND::Line_ND(const unsigned &arg_dim)
    : Geometry_ND(arg_dim, line_num_of_vertex)
{
}
// Copy constructor
Line_ND::Line_ND(const Line_ND &arg_line)
    : Geometry_ND(arg_line)
{
}
// assignment operator
Line_ND &Line_ND::operator=(const Line_ND &arg_line)
{
    if (this == &arg_line) // self-assignment
        return *this;
    Geometry_ND::operator=(arg_line);
    return *this;
}
// print the geometry
void Line_ND::print_geometry()
{
    cout << "l" << endl;
    cout << m_point_array.size() << endl;
    for (int i = 0; i < line_num_of_vertex; i++)
    {
        cout << m_point_array[i] << endl;
    }
}
// parse the cin to the geometry
void Line_ND::parse_geometry(istream &arg_is)
{
    string temp;
    getline(arg_is, temp); // get the vertex number
    int vertex_num = stoi(temp);
    if (vertex_num != line_num_of_vertex)
    {
        throw runtime_error("Line_ND::parse_geometry(): wrong vertex number");
    }

    for (int i = 0; i < vertex_num; i++)
    {
        getline(arg_is, temp);
        stringstream ss(temp);
        Point_ND point(m_dim);
        ss >> point;
        m_point_array[i] = point;
    }
}

int main()
{
    vector<Geometry_ND *> geo_ptr_array;
    try
    {
        string input;
        unsigned dim;
        Geometry_ND *geo_ptr;
        // read dimension
        getline(cin, input);
        dim = stoi(input);

        // read geometry
        while (getline(cin, input))
        {
            // check the geometry type
            switch (input[0])
            {
            case 't':
                geo_ptr = new Triangle_ND(dim);
                break;
            case 'p':
                geo_ptr = new Polygon_ND(dim);
                break;
            case 'l':
                geo_ptr = new Line_ND(dim);
                break;
            default:
                throw runtime_error("main(): wrong geometry type");
            }
            if (input == "t" || input == "p" || input == "l")
            {
                // parse the cin to the geometry
                geo_ptr->parse_geometry(cin);
                // push the pointer to the array
                geo_ptr_array.push_back(geo_ptr);
            }
            else
            {
                throw runtime_error("main(): wrong geometry type");
            }
        }
        // print the geometry
        // first, print the dimension
        cout << geo_ptr_array[0]->get_geometry_array().at(0).get_dim() << endl;
        // second, print the geometry
        for (int i = 0; i < geo_ptr_array.size(); i++)
        {
            geo_ptr_array[i]->print_geometry();
        }
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    // delete the geometry
    for (int i = 0; i < geo_ptr_array.size(); i++)
    {
        delete geo_ptr_array[i];
    }
    return 0;
}