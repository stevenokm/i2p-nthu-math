#include <iostream>
#include <fstream>

using namespace std;

class Triangle_2D; // forward declaration

class Point_2D // the class name
// we use first upper case letter to indicate a class
{
private: // private data members & member functions
    // Data members
    // we use `m_` to indicate a data member

    // record the x coordinate
    double m_x;
    // record the y coordinate
    double m_y;

    // Member functions
    // we use `_` to indicate a member function

    // check if the point is valid
    void _check_validity();

public: // public member functions
    // Constructor

    // Constructor & Default constructor
    // initialize data members, with default values
    // accessable to const object by default
    Point_2D(const double &arg_x = 0, const double &arg_y = 0);

    // Copy constructor
    // copy the data members from the given object
    // accessable to const object by default
    Point_2D(const Point_2D &arg_point);

    // Destructor
    ~Point_2D() // destructor
    {
        // do nothing, because we don't
        // have any dynamic memory
    }

    // Member functions
    // we use lower case letter to indicate a member function
    // also, we just define the function declaration
    // and leave the definition to the end of the class

    // modify the x and y coordinate
    // we use `arg_` to indicate the arguments
    // and re-write with setter
    void set_x(const double &arg_x);
    void set_y(const double &arg_y);
    void set(const double &arg_x, const double &arg_y);
    // get the x coordinate and y coordinate
    // accessable to const object
    double get_x() const;
    double get_y() const;
    // // compare two points
    bool operator==(const Point_2D &arg_point) const;
    bool operator!=(const Point_2D &arg_point) const;
    bool operator<(const Point_2D &arg_point) const;
    bool operator>(const Point_2D &arg_point) const;
    bool operator<=(const Point_2D &arg_point) const;
    bool operator>=(const Point_2D &arg_point) const;
    // assign the point with another point
    Point_2D &operator=(const Point_2D &arg_point);

    // friend class
    friend class Triangle_2D;
    // friend function
    // print the x and y coordinate in format (x, y)
    // accessable to const object
    friend std::ostream &operator<<(std::ostream &arg_os, const Point_2D &arg_point);
    // read the coordinate of a point from the input, format: (x, y) and ignore space
    friend std::istream &operator>>(std::istream &arg_is, Point_2D &arg_point);
};

// Triangle_2D class declaration
class Triangle_2D
{
private:
    // define three points of the Triangle_2D
    // in array of Point_2D format
    Point_2D m_point[3];

    // check & correct the Triangle_2D points to counterclockwise order
    void _check_points();

public:
    // Constructor
    Triangle_2D(const double &arg_x0 = 0.0, const double &arg_y0 = 0.0,
                const double &arg_x1 = 0.0, const double &arg_y1 = 0.0,
                const double &arg_x2 = 0.0, const double &arg_y2 = 0.0);

    // Copy constructor
    Triangle_2D(const Triangle_2D &arg_triangle);

    // Destructor
    ~Triangle_2D()
    {
        // do nothing
    }

    // modify the three points of the Triangle_2D
    void set_points(const double &arg_x0, const double &arg_y0,
                    const double &arg_x1, const double &arg_y1,
                    const double &arg_x2, const double &arg_y2);
    void set_point1(const double &arg_x0, const double &arg_y0);
    void set_point2(const double &arg_x1, const double &arg_y1);
    void set_point3(const double &arg_x2, const double &arg_y2);
    void set_x0(const double &arg_x0);
    void set_y0(const double &arg_y0);
    void set_x1(const double &arg_x1);
    void set_y1(const double &arg_y1);
    void set_x2(const double &arg_x2);
    void set_y2(const double &arg_y2);
    // get the three points of the Triangle_2D
    double get_x0() const;
    double get_y0() const;
    double get_x1() const;
    double get_y1() const;
    double get_x2() const;
    double get_y2() const;

    // calculate the area of the Triangle_2D
    double area();

    // print the Triangle_2D
    // format: ((x0, y0), (x1, y1), (x2, y2))
    friend std::ostream &operator<<(std::ostream &arg_os, const Triangle_2D &arg_tri);
    // read the coordinate of a point from the input,
    // format: ((x0, y0), (x1, y1), (x2, y2)) and ignore space
    friend std::istream &operator>>(std::istream &arg_is, Triangle_2D &arg_tri);
};

// function definition

// check if the point is valid
void Point_2D::_check_validity()
{
    // check if the x coordinate is valid
    if (m_x < 0)
    {
        // if not, set it to 0
        m_x = 0;
    }
    // check if the y coordinate is valid
    if (m_y < 0)
    {
        // if not, set it to 0
        m_y = 0;
    }
}
// Constructor & Default constructor
// initialize data members, with default values
Point_2D::Point_2D(const double &arg_x, const double &arg_y)
    // use `: var_name1(arg_var_name1), var_name2(arg_var_name2)`
    // to initialize data members
    : m_x(arg_x),
      m_y(arg_y)
{
    // check if the point is valid
    _check_validity();
}

// Copy constructor
// copy the data members from the given object
Point_2D::Point_2D(const Point_2D &arg_point)
    : m_x(arg_point.m_x),
      m_y(arg_point.m_y)
{
    // check if the point is valid
    _check_validity();
}

// modify the x and y coordinate
// we use `arg_` to indicate the arguments
// and re-write with setter
void Point_2D::set_x(const double &arg_x)
{
    m_x = arg_x;
    // check if the point is valid
    _check_validity();
}
void Point_2D::set_y(const double &arg_y)
{
    m_y = arg_y;
    // check if the point is valid
    _check_validity();
}
void Point_2D::set(const double &arg_x, const double &arg_y)
{
    m_x = arg_x;
    m_y = arg_y;
    // check if the point is valid
    _check_validity();
}

// get the x coordinate and y coordinate
// accessable to const object
double Point_2D::get_x() const
{
    return m_x;
}
double Point_2D::get_y() const
{
    return m_y;
}

// // compare two points
bool Point_2D::operator==(const Point_2D &arg_point) const
{
    // if the x and y coordinates are equal,
    // return true
    return (m_x == arg_point.m_x && m_y == arg_point.m_y);
}
bool Point_2D::operator!=(const Point_2D &arg_point) const
{
    return !(*this == arg_point);
}
bool Point_2D::operator<(const Point_2D &arg_point) const
{
    // if the x coordinate is smaller than the other point,
    // return true
    if (m_x < arg_point.m_x)
    {
        return true;
    }
    // if the x coordinate is equal to the other point,
    // check if the y coordinate is smaller than the other point
    else if (m_x == arg_point.m_x)
    {
        // if the y coordinate is smaller, return true
        if (m_y < arg_point.m_y)
        {
            return true;
        }
        // if the y coordinate is equal to the other point,
        // return false
        else if (m_y == arg_point.m_y)
        {
            return false;
        }
        // if the y coordinate is larger, return false
        else
        {
            return false;
        }
    }
    // if the x coordinate is larger, return false
    else
    {
        return false;
    }
}
bool Point_2D::operator>(const Point_2D &arg_point) const
{
    return !(*this < arg_point || *this == arg_point);
}
bool Point_2D::operator<=(const Point_2D &arg_point) const
{
    return (*this < arg_point || *this == arg_point);
}
bool Point_2D::operator>=(const Point_2D &arg_point) const
{
    return !(*this < arg_point);
}
// assign the point with another point
Point_2D &Point_2D::operator=(const Point_2D &arg_point)
{
    // check if the point is valid
    _check_validity();
    // assign the x and y coordinate
    m_x = arg_point.m_x;
    m_y = arg_point.m_y;
    // check if the point is valid
    _check_validity();
    return *this;
}

// print the point in the format (x, y)
std::ostream &operator<<(std::ostream &arg_os, const Point_2D &arg_point)
{
    arg_os << "(" << arg_point.m_x << ", " << arg_point.m_y << ")";
    return arg_os;
}

// read the coordinate of a point from the input, format: (x, y) and ignore space
std::istream &operator>>(std::istream &arg_is, Point_2D &arg_point)
{
    string str_x, str_y, temp;

    if (getline(arg_is, temp, '(')) // ignore the first '('
    {
        if (getline(arg_is, str_x, ','))
        {
            if (getline(arg_is, str_y, ')'))
            {
                arg_point.m_x = stod(str_x);
                arg_point.m_y = stod(str_y);
            }
        }
    }

    // check if the point is valid
    arg_point._check_validity();

    return arg_is;
}

// Triangle_2D class implementation

// check & correct the Triangle_2D points to counterclockwise order
void Triangle_2D::_check_points()
{
    // sort the points in ascending order
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (m_point[i] > m_point[j])
            {
                // swap the points
                Point_2D temp = m_point[i];
                m_point[i] = m_point[j];
                m_point[j] = temp;
            }
        }
    }

    // if the area is negative, swap the points
    if (area() < 0.0)
    {
        Point_2D temp = m_point[0];
        m_point[0] = m_point[1];
        m_point[1] = temp;
    }
}

// Constructor
Triangle_2D::Triangle_2D(const double &arg_x0, const double &arg_y0,
                         const double &arg_x1, const double &arg_y1,
                         const double &arg_x2, const double &arg_y2)
    : m_point{Point_2D(arg_x0, arg_y0),
              Point_2D(arg_x1, arg_y1),
              Point_2D(arg_x2, arg_y2)} // init the array with {}
{
    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}

// Copy constructor
Triangle_2D::Triangle_2D(const Triangle_2D &arg_triangle)
    : m_point{Point_2D(arg_triangle.m_point[0]),
              Point_2D(arg_triangle.m_point[1]),
              Point_2D(arg_triangle.m_point[2])} // init the array with {}
{
}

// set the three points of the Triangle_2D
void Triangle_2D::set_points(const double &arg_x0, const double &arg_y0,
                             const double &arg_x1, const double &arg_y1,
                             const double &arg_x2, const double &arg_y2)
{
    m_point[0].set(arg_x0, arg_y0);
    m_point[1].set(arg_x1, arg_y1);
    m_point[2].set(arg_x2, arg_y2);

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}
void Triangle_2D::set_point1(const double &arg_x0, const double &arg_y0)
{
    m_point[0].set(arg_x0, arg_y0);

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}
void Triangle_2D::set_point2(const double &arg_x1, const double &arg_y1)
{
    m_point[1].set(arg_x1, arg_y1);

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}
void Triangle_2D::set_point3(const double &arg_x2, const double &arg_y2)
{
    m_point[2].set(arg_x2, arg_y2);

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}
void Triangle_2D::set_x0(const double &arg_x0)
{
    m_point[0].m_x = arg_x0;

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}
void Triangle_2D::set_y0(const double &arg_y0)
{
    m_point[0].m_y = arg_y0;

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}
void Triangle_2D::set_x1(const double &arg_x1)
{
    m_point[1].m_x = arg_x1;

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}
void Triangle_2D::set_y1(const double &arg_y1)
{
    m_point[1].m_y = arg_y1;

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}
void Triangle_2D::set_x2(const double &arg_x2)
{
    m_point[2].m_x = arg_x2;

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}
void Triangle_2D::set_y2(const double &arg_y2)
{
    m_point[2].m_y = arg_y2;

    // check & correct the Triangle_2D points to counterclockwise order
    _check_points();
}

// get the three points of the Triangle_2D
double Triangle_2D::get_x0() const
{
    return m_point[0].m_x;
}
double Triangle_2D::get_y0() const
{
    return m_point[0].m_y;
}
double Triangle_2D::get_x1() const
{
    return m_point[1].m_x;
}
double Triangle_2D::get_y1() const
{
    return m_point[1].m_y;
}
double Triangle_2D::get_x2() const
{
    return m_point[2].m_x;
}
double Triangle_2D::get_y2() const
{
    return m_point[2].m_y;
}

// calculate the area of the Triangle_2D
double Triangle_2D::area()
{
    // calculate the area of the Triangle_2D
    return (m_point[0].m_x * m_point[1].m_y +
            m_point[1].m_x * m_point[2].m_y +
            m_point[2].m_x * m_point[0].m_y -
            m_point[0].m_x * m_point[2].m_y -
            m_point[1].m_x * m_point[0].m_y -
            m_point[2].m_x * m_point[1].m_y) /
           2.0;
}

// print the Triangle_2D
// format: ((x0, y0), (x1, y1), (x2, y2))
std::ostream &operator<<(std::ostream &arg_os, const Triangle_2D &arg_tri)
{
    arg_os << "(";
    for (int i = 0; i < 3; i++)
    {
        arg_os << arg_tri.m_point[i];
        if (i < 2)
            arg_os << ", ";
    }
    arg_os << ")";
    return arg_os;
}
// read the coordinate of a point from the input,
// format: ((x0, y0), (x1, y1), (x2, y2)) and ignore space
std::istream &operator>>(std::istream &arg_is, Triangle_2D &arg_tri)
{
    string temp;
    if (getline(arg_is, temp, '(')) // ignore the first '('
    {
        for (int i = 0; i < 3; i++)
        {
            arg_is >> arg_tri.m_point[i];
            if (i < 2)
            {
                getline(arg_is, temp, ','); // ignore the ','
            }
        }
        getline(arg_is, temp, ')'); // ignore the last ')'
    }

    // check & correct the Triangle_2D points to counterclockwise order
    arg_tri._check_points();

    return arg_is;
}

// main function

int main()
{
    Triangle_2D t(1, 1, 2, 2, 0, 3);
    cout << t << endl;
    cout << "Area: " << t.area() << endl;

    ofstream t_file("triangle.txt", ios::out | ios::trunc);
    // reuse the `<<` operator to write the Triangle_2D to the file
    t_file << t << endl;
    t_file.close();

    // read the Triangle_2D from the file
    ifstream t_file_in("triangle.txt", ios::in);
    Triangle_2D t_in;
    t_file_in >> t_in;
    cout << t_in << endl;
    cout << "Area: " << t_in.area() << endl;
    t_file_in.close();

    return 0;
}