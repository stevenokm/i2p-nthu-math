#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <exception>
#include <iomanip>

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
    // write data members in binary format
    void write_binary_coords(ofstream &arg_ofs);
    // read data members in binary format
    void read_binary_coords(ifstream &arg_ifs);
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
    virtual void print_geometry(ofstream &arg_ofs);
    // parse the cin to the geometry
    virtual void parse_geometry(ifstream &arg_ifs);
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
    void print_geometry(ofstream &arg_ofs);
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs);
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
    void print_geometry(ofstream &arg_ofs);
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs);
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
    void print_geometry(ofstream &arg_ofs);
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs);
};
const unsigned line_num_of_vertex = 2;

// Ref: https://stackoverflow.com/q/9621893
void print_output_file(int argc, char *argv[])
{
    ifstream ans_ifs(argv[2], ios::in | ios::binary);
    if (!ans_ifs)
    {
        cout << "Error: Cannot open output file" << endl;
        exit(1);
    }
    char ans_block = 0;
    unsigned offset_count = 0;

    ans_ifs.read(&ans_block, 1);
    while (!ans_ifs.eof())
    {
        int z = ans_block & 0xff;
        cout << std::hex
             << std::setfill('0')
             << std::setw(2)
             << z
             << " ";
        offset_count++;
        if (offset_count % 16 == 0)
        {
            cout << endl;
        }
        ans_ifs.read(&ans_block, 1);
    }
    cout << endl;
    ans_ifs.close();
}

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

// write data members in binary format
void Point_ND::write_binary_coords(ofstream &arg_ofs)
{
    for (unsigned i = 0; i < m_dim; i++)
    {
        arg_ofs.write((char *)&m_coords[i], sizeof(double));
    }
}
// read data members in binary format
void Point_ND::read_binary_coords(ifstream &arg_ifs)
{
    double temp_double;
    for (unsigned i = 0; i < m_dim; i++)
    {
        arg_ifs.read((char *)&temp_double, sizeof(double));
        m_coords[i] = temp_double;
    }
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
void Geometry_ND::print_geometry(ofstream &arg_ofs)
{
    throw runtime_error("print_geometry() is not implemented");
}
// parse the cin to the geometry
void Geometry_ND::parse_geometry(ifstream &arg_ifs)
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
void Triangle_ND::print_geometry(ofstream &arg_ofs)
{
    unsigned num_of_vertex = m_point_array.size();
    arg_ofs.write("t", 1);
    arg_ofs.write((char *)&num_of_vertex, sizeof(unsigned int));
    for (int i = 0; i < num_of_vertex; i++)
    {
        m_point_array[i].write_binary_coords(arg_ofs);
    }
}
// parse the cin to the geometry
void Triangle_ND::parse_geometry(ifstream &arg_ifs)
{
    unsigned int vertex_num;
    arg_ifs.read((char *)&vertex_num, sizeof(unsigned int));
    if (vertex_num != triangle_num_of_vertex)
    {
        throw runtime_error("Triangle_ND::parse_geometry(): wrong vertex number");
    }

    for (int i = 0; i < vertex_num; i++)
    {
        Point_ND point(m_dim);
        point.read_binary_coords(arg_ifs);
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
void Polygon_ND::print_geometry(ofstream &arg_ofs)
{
    unsigned num_of_vertex = m_point_array.size();
    arg_ofs.write("p", 1);
    arg_ofs.write((char *)&num_of_vertex, sizeof(unsigned int));
    for (int i = 0; i < num_of_vertex; i++)
    {
        m_point_array[i].write_binary_coords(arg_ofs);
    }
}
// parse the cin to the geometry
void Polygon_ND::parse_geometry(ifstream &arg_ifs)
{
    unsigned int vertex_num;
    arg_ifs.read((char *)&vertex_num, sizeof(unsigned int));
    if (vertex_num < 3)
    {
        throw runtime_error("Polygon_ND::parse_geometry(): wrong vertex number");
    }
    m_point_array.resize(vertex_num);
    for (int i = 0; i < vertex_num; i++)
    {
        Point_ND point(m_dim);
        point.read_binary_coords(arg_ifs);
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
void Line_ND::print_geometry(ofstream &arg_ofs)
{
    unsigned num_of_vertex = m_point_array.size();
    arg_ofs.write("l", 1);
    arg_ofs.write((char *)&num_of_vertex, sizeof(unsigned int));
    for (int i = 0; i < num_of_vertex; i++)
    {
        m_point_array[i].write_binary_coords(arg_ofs);
    }
}
// parse the cin to the geometry
void Line_ND::parse_geometry(ifstream &arg_ifs)
{
    unsigned int vertex_num;
    arg_ifs.read((char *)&vertex_num, sizeof(unsigned int));
    if (vertex_num != line_num_of_vertex)
    {
        throw runtime_error("Line_ND::parse_geometry(): wrong vertex number");
    }

    for (int i = 0; i < vertex_num; i++)
    {
        Point_ND point(m_dim);
        point.read_binary_coords(arg_ifs);
        m_point_array[i] = point;
    }
}

int main(int argc, char *argv[])
{
    vector<Geometry_ND *> geo_ptr_array;
    string input_file_path(argv[1]);
    string output_file_path(argv[2]);

    try
    {
        char input;
        unsigned dim;
        Geometry_ND *geo_ptr;

        // open the input file
        ifstream infile(input_file_path, ios::in | ios::binary);
        infile.exceptions(ios::badbit);

        // open the output file
        ofstream outfile(output_file_path, ios::out | ios::trunc | ios::binary);
        outfile.exceptions(ios::badbit);

        // read dimension
        infile.read((char *)&dim, sizeof(unsigned));
        if (dim < 2 || dim > 10)
        {
            throw runtime_error("main(): wrong dimension");
        }

        // read geometry
        while (infile.get(input))
        {
            // check the geometry type
            switch (input)
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
            if (input == 't' || input == 'p' || input == 'l')
            {
                // change exception mask
                infile.exceptions(ios::badbit | ios::failbit | ios::eofbit);
                // parse the infile to the geometry
                geo_ptr->parse_geometry(infile);
                // push the pointer to the array
                geo_ptr_array.push_back(geo_ptr);
                // rollback the exception mask
                infile.exceptions(ios::badbit);
            }
            else
            {
                throw runtime_error("main(): wrong geometry type");
            }
        }
        // print the geometry
        // first, print the dimension
        outfile.write((char *)&dim, sizeof(unsigned));
        // second, print the geometry
        for (int i = 0; i < geo_ptr_array.size(); i++)
        {
            geo_ptr_array[i]->print_geometry(outfile);
        }
        // close the input & output file
        infile.close();
        outfile.close();
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
        // delete the geometry
        for (int i = 0; i < geo_ptr_array.size(); i++)
        {
            delete geo_ptr_array[i];
        }
        return 1;
    }

    // delete the geometry
    for (int i = 0; i < geo_ptr_array.size(); i++)
    {
        delete geo_ptr_array[i];
    }

    print_output_file(argc, argv);

    return 0;
}