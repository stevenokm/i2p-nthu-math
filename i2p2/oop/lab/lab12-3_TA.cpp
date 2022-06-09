#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

class Geometry_Comp;

class Complex
{
private:
    // data members
    // save the real and imaginary parts of the complex number
    // with `double` precision
    double m_real;
    double m_imag;

public:
    // Constructor, initializes real and imaginary parts
    Complex(const double &arg_real = 0.0, const double &arg_imag = 0.0);
    // Copy constructor
    Complex(const Complex &arg_c);
    // assignment operator
    Complex &operator=(const Complex &arg_c);
    // add assignment operator
    Complex &operator+=(const Complex &arg_c);
    // multiply assignment operator
    Complex &operator*=(const Complex &arg_c);
    // length of the complex number
    double length() const;
    // angle of the complex number in radians
    double angle() const;
    // cout `<<` operator for print complex number
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_c);
    // cin `>>` operator for input complex number
    // note: use `>>` to parse the string to double,
    // use `istream::fail()` to check the conversion is successful
    // and use `istream::eof()` to check the is parse to the end of line
    friend istream &operator>>(istream &arg_is, Complex &arg_c);
    // friend class
    friend class Geometry_Comp;
};

class Geometry_Comp
{
protected:
    // data members
    vector<Complex> m_comp_array;
    // utility function to check if the transformation is valid
    bool _check_transform(const Complex &arg_trans_c, const char &arg_op);

public:
    // Constructor, initializes the array
    Geometry_Comp(const unsigned int &arg_num_of_vertex = 0);
    // Copy constructor
    Geometry_Comp(const Geometry_Comp &arg_gc);
    // assignment operator
    Geometry_Comp &operator=(const Geometry_Comp &arg_gc);
    // print the geometry
    virtual void print_geometry();
    // parse the cin to the geometry
    virtual void parse_geometry(istream &arg_is);
    // apply transformation to the geometry
    void transform_geometry(const Complex &arg_trans_c, const char &arg_op);
    // set the geometry
    void set_geometry(const vector<Complex> &arg_comp_array);
    // get the geometry array
    vector<Complex> get_geometry_array();
};

class Triangle_Comp : public Geometry_Comp
{
public:
    // Constructor, initializes the array
    Triangle_Comp();
    // Copy constructor
    Triangle_Comp(const Triangle_Comp &arg_tc);
    // assignment operator
    Triangle_Comp &operator=(const Triangle_Comp &arg_tc);
    // print the geometry
    void print_geometry();
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is);
};
const unsigned triangle_num_of_vertex = 3;

class Quadrilateral_Comp : public Geometry_Comp
{
public:
    // Constructor, initializes the array
    Quadrilateral_Comp();
    // Copy constructor
    Quadrilateral_Comp(const Quadrilateral_Comp &arg_qc);
    // assignment operator
    Quadrilateral_Comp &operator=(const Quadrilateral_Comp &arg_qc);
    // print the geometry
    void print_geometry();
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is);
};
const unsigned quadrilateral_num_of_vertex = 4;

class Polygon_Comp : public Geometry_Comp
{
public:
    // Constructor, initializes the array
    Polygon_Comp();
    // Copy constructor
    Polygon_Comp(const Polygon_Comp &arg_pc);
    // assignment operator
    Polygon_Comp &operator=(const Polygon_Comp &arg_pc);
    // print the geometry
    void print_geometry();
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is);
};

class Circle_Comp : public Geometry_Comp
{
public:
    // Constructor, initializes the array
    Circle_Comp();
    // Copy constructor
    Circle_Comp(const Circle_Comp &arg_cc);
    // assignment operator
    Circle_Comp &operator=(const Circle_Comp &arg_cc);
    // print the geometry
    void print_geometry();
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is);
};
const unsigned circle_num_of_vertex = 2;

// error and exit
void error_and_exit()
{
    cout << "Error: Invalid input" << endl;
    exit(1);
}

// Complex class implementation

// Constructor, initializes real and imaginary parts
// hint: as like as `modify` function in examples
// but use default constructor to implement
Complex::Complex(const double &arg_real, const double &arg_imag)
    : m_real(arg_real), m_imag(arg_imag)
{
}

// Copy constructor
Complex::Complex(const Complex &arg_c)
    : m_real(arg_c.m_real), m_imag(arg_c.m_imag)
{
}

// assignment operator
Complex &Complex::operator=(const Complex &arg_c)
{
    if (this == &arg_c) // self-assignment
        return *this;
    m_real = arg_c.m_real;
    m_imag = arg_c.m_imag;
    return *this;
}

// add assignment operator
Complex &Complex::operator+=(const Complex &arg_c)
{
    m_real += arg_c.m_real;
    m_imag += arg_c.m_imag;
    return *this;
}

// multiply assignment operator
Complex &Complex::operator*=(const Complex &arg_c)
{
    double real = m_real * arg_c.m_real - m_imag * arg_c.m_imag;
    double imag = m_real * arg_c.m_imag + m_imag * arg_c.m_real;
    m_real = real;
    m_imag = imag;
    return *this;
}

// length of the complex number
double Complex::length() const
{
    return sqrt(m_real * m_real + m_imag * m_imag);
}

// angle of the complex number in radians
double Complex::angle() const
{
    if (m_real == 0 && m_imag == 0)
    {
        return NAN;
    }
    return atan2(m_imag, m_real);
}

// cout `<<` operator for print complex number
// note: be careful about the format of output
ostream &operator<<(ostream &arg_os, const Complex &arg_c)
{
    if (arg_c.m_imag > 0)
    {
        arg_os << arg_c.m_real << " + " << arg_c.m_imag << "i";
    }
    else if (arg_c.m_imag < 0)
    {
        arg_os << arg_c.m_real << " - " << -arg_c.m_imag << "i";
    }
    else
    {
        arg_os << arg_c.m_real;
    }
    return arg_os;
}

// cin `>>` operator for input complex number
// note: be careful about the format of input
istream &operator>>(istream &arg_is, Complex &arg_c)
{
    double input_real, input_imag;
    arg_is >> input_real;
    if (arg_is.fail())
    {
        error_and_exit();
    }
    arg_is >> input_imag;
    if (arg_is.fail() || !arg_is.eof())
    {
        error_and_exit();
    }
    arg_c.m_real = input_real;
    arg_c.m_imag = input_imag;
    return arg_is;
}

// Geometry_Comp class implementation

// check if the transformation is valid
bool Geometry_Comp::_check_transform(const Complex &arg_c, const char &arg_op)
{
    // check if the operation is valid
    if (arg_op == 'r' && (arg_c.length() != 1 || isnan(arg_c.angle())))
    {
        return false;
    }
    else if (arg_op == 'z' && (arg_c.m_real == 0 || arg_c.m_imag != 0))
    {
        return false;
    }
    else
    {
        return true;
    }
}
// Constructor, initializes the array
Geometry_Comp::Geometry_Comp(const unsigned int &arg_num_of_vertex)
    : m_comp_array(arg_num_of_vertex)
{
}
// Copy constructor
Geometry_Comp::Geometry_Comp(const Geometry_Comp &arg_gc)
    : m_comp_array(arg_gc.m_comp_array)
{
}
// assignment operator
Geometry_Comp &Geometry_Comp::operator=(const Geometry_Comp &arg_gc)
{
    if (this == &arg_gc) // self-assignment
        return *this;
    m_comp_array = arg_gc.m_comp_array;
    return *this;
}
// print the geometry
void Geometry_Comp::print_geometry()
{
    cout << "not implemented" << endl;
}
// parse the cin to the geometry
void Geometry_Comp::parse_geometry(istream &arg_is)
{
    cout << "not implemented" << endl;
}
// apply transformation to the geometry
void Geometry_Comp::transform_geometry(const Complex &arg_c, const char &arg_op)
{
    if (!(_check_transform(arg_c, arg_op)))
    {
        error_and_exit();
    }
    if (arg_op == 'm')
    {
        for (unsigned int i = 0; i < m_comp_array.size(); i++)
        {
            m_comp_array[i] += arg_c;
        }
    }
    else if (arg_op == 'r' || arg_op == 'z')
    {
        for (unsigned int i = 0; i < m_comp_array.size(); i++)
        {
            m_comp_array[i] *= arg_c;
        }
    }
}
// set the geometry
void Geometry_Comp::set_geometry(const vector<Complex> &arg_comp_array)
{
    m_comp_array = arg_comp_array;
}
// get the geometry array
vector<Complex> Geometry_Comp::get_geometry_array()
{
    return m_comp_array;
}

// Triangle_Comp class implementation

// Constructor, initializes the array
Triangle_Comp::Triangle_Comp()
    : Geometry_Comp(triangle_num_of_vertex)
{
}
// Copy constructor
Triangle_Comp::Triangle_Comp(const Triangle_Comp &arg_tc)
    : Geometry_Comp(arg_tc)
{
}
// assignment operator
Triangle_Comp &Triangle_Comp::operator=(const Triangle_Comp &arg_tc)
{
    if (this == &arg_tc) // self-assignment
        return *this;
    Geometry_Comp::operator=(arg_tc);
    return *this;
}
// print the geometry
void Triangle_Comp::print_geometry()
{
    cout << "t" << endl;
    cout << m_comp_array.size() << endl;
    for (int i = 0; i < triangle_num_of_vertex; i++)
    {
        cout << m_comp_array[i] << endl;
    }
}
// parse the cin to the geometry
void Triangle_Comp::parse_geometry(istream &arg_is)
{
    string temp;
    getline(arg_is, temp); // get the vertex number
    stringstream ss(temp);
    unsigned int vertex_num;
    ss >> vertex_num;
    if (vertex_num != triangle_num_of_vertex)
    {
        error_and_exit();
    }

    for (int i = 0; i < vertex_num; i++)
    {
        getline(arg_is, temp);
        stringstream ss(temp);
        Complex c;
        ss >> c;
        if (ss.fail())
        {
            error_and_exit();
        }
        m_comp_array[i] = c;
    }
}

// Quadrilateral_Comp class implementation

// Constructor, initializes the array
Quadrilateral_Comp::Quadrilateral_Comp()
    : Geometry_Comp(quadrilateral_num_of_vertex)
{
}
// Copy constructor
Quadrilateral_Comp::Quadrilateral_Comp(const Quadrilateral_Comp &arg_qc)
    : Geometry_Comp(arg_qc)
{
}
// assignment operator
Quadrilateral_Comp &Quadrilateral_Comp::operator=(const Quadrilateral_Comp &arg_qc)
{
    if (this == &arg_qc) // self-assignment
        return *this;
    Geometry_Comp::operator=(arg_qc);
    return *this;
}
// print the geometry
void Quadrilateral_Comp::print_geometry()
{
    cout << "q" << endl;
    cout << m_comp_array.size() << endl;
    for (int i = 0; i < quadrilateral_num_of_vertex; i++)
    {
        cout << m_comp_array[i] << endl;
    }
}
// parse the cin to the geometry
void Quadrilateral_Comp::parse_geometry(istream &arg_is)
{
    string temp;
    getline(arg_is, temp); // get the vertex number
    int vertex_num = stoi(temp);
    if (vertex_num != quadrilateral_num_of_vertex)
    {
        error_and_exit();
    }

    for (int i = 0; i < vertex_num; i++)
    {
        getline(arg_is, temp);
        stringstream ss(temp);
        Complex c;
        ss >> c;
        if (ss.fail())
        {
            error_and_exit();
        }
        m_comp_array[i] = c;
    }
}

// Polygon_Comp class implementation

// Constructor, initializes the array
Polygon_Comp::Polygon_Comp()
    : Geometry_Comp()
{
}
// Copy constructor
Polygon_Comp::Polygon_Comp(const Polygon_Comp &arg_pc)
    : Geometry_Comp(arg_pc)
{
}
// assignment operator
Polygon_Comp &Polygon_Comp::operator=(const Polygon_Comp &arg_pc)
{
    if (this == &arg_pc) // self-assignment
        return *this;
    Geometry_Comp::operator=(arg_pc);
    return *this;
}
// print the geometry
void Polygon_Comp::print_geometry()
{
    cout << "p" << endl;
    cout << m_comp_array.size() << endl;
    for (int i = 0; i < m_comp_array.size(); i++)
    {
        cout << m_comp_array[i] << endl;
    }
}
// parse the cin to the geometry
void Polygon_Comp::parse_geometry(istream &arg_is)
{
    string temp;
    getline(arg_is, temp); // get the vertex number
    int vertex_num = stoi(temp);
    if (vertex_num < triangle_num_of_vertex)
    {
        error_and_exit();
    }
    m_comp_array.resize(vertex_num);
    for (int i = 0; i < vertex_num; i++)
    {
        getline(arg_is, temp);
        stringstream ss(temp);
        Complex c;
        ss >> c;
        if (ss.fail())
        {
            error_and_exit();
        }
        m_comp_array[i] = c;
    }
}

// Circle_Comp class implementation

// Constructor, initializes the array
Circle_Comp::Circle_Comp()
    : Geometry_Comp(circle_num_of_vertex)
{
}
// Copy constructor
Circle_Comp::Circle_Comp(const Circle_Comp &arg_cc)
    : Geometry_Comp(arg_cc)
{
}
// assignment operator
Circle_Comp &Circle_Comp::operator=(const Circle_Comp &arg_cc)
{
    if (this == &arg_cc) // self-assignment
        return *this;
    Geometry_Comp::operator=(arg_cc);
    return *this;
}
// print the geometry
void Circle_Comp::print_geometry()
{
    cout << "c" << endl;
    cout << m_comp_array.size() << endl;
    for (int i = 0; i < circle_num_of_vertex; i++)
    {
        cout << m_comp_array[i] << endl;
    }
}
// parse the cin to the geometry
void Circle_Comp::parse_geometry(istream &arg_is)
{
    string temp;
    getline(arg_is, temp); // get the vertex number
    int vertex_num = stoi(temp);
    if (vertex_num != circle_num_of_vertex)
    {
        error_and_exit();
    }

    for (int i = 0; i < vertex_num; i++)
    {
        getline(arg_is, temp);
        stringstream ss(temp);
        Complex c;
        ss >> c;
        if (ss.fail())
        {
            error_and_exit();
        }
        m_comp_array[i] = c;
    }
}

int main()
{
    string input, temp;
    vector<Geometry_Comp *> geo_ptr_array;
    Geometry_Comp *geo_ptr;
    Complex trans_c;
    char trans_op;

    while (getline(cin, input))
    {
        // check the geometry type
        switch (input[0])
        {
        case 't':
            geo_ptr = new Triangle_Comp();
            break;
        case 'q':
            geo_ptr = new Quadrilateral_Comp();
            break;
        case 'p':
            geo_ptr = new Polygon_Comp();
            break;
        case 'c':
            geo_ptr = new Circle_Comp();
            break;
        case 'r':
        case 'z':
        case 'm':
            getline(cin, temp);
            break;
        default:
            for (int i = 0; i < geo_ptr_array.size(); i++)
            {
                delete geo_ptr_array[i];
            }
            error_and_exit();
        }
        if (input[0] == 't' || input[0] == 'q' || input[0] == 'p' || input[0] == 'c')
        {
            // parse the cin to the geometry
            geo_ptr->parse_geometry(cin);
            // print the geometry
            geo_ptr->print_geometry();
            // push the pointer to the array
            geo_ptr_array.push_back(geo_ptr);
        }
        else if (input[0] == 'r' || input[0] == 'z' || input[0] == 'm')
        {
            stringstream ss(temp);
            ss >> trans_c;
            // transform the geometry using operator and complex
            for (int i = 0; i < geo_ptr_array.size(); i++)
            {
                geo_ptr_array[i]->transform_geometry(trans_c, input[0]);
                // print transformed geometry
                geo_ptr_array[i]->print_geometry();
            }
        }
        else
        {
            for (int i = 0; i < geo_ptr_array.size(); i++)
            {
                delete geo_ptr_array[i];
            }
            error_and_exit();
        }
    }
    return 0;
}