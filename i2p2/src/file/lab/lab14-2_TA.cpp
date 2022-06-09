#include <iostream>
#include <iomanip>
#include <fstream>
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
    // use `atan2` to compute the angle by the formula `atan(imag/real)`
    // and use `NAN` for 0/0 case
    // `atan2` ref: https://en.cppreference.com/w/cpp/numeric/math/atan2
    // `NAN` ref: https://en.cppreference.com/w/cpp/numeric/math/NAN
    double angle() const;
    // write data members in binary format
    // note: be careful about the type used in `.write()` function
    void write_binary_record(ostream &arg_os);
    // read data members in binary format
    // note: use `.read()` to get the double in binary format,
    // use `istream::fail()` to check the conversion is successful
    // and use `istream::eof()` to check the is parse to the end of line
    void read_binary_record(istream &arg_is);
    // friend class
    friend class Geometry_Comp;
};

class Geometry_Comp
{
protected:
    // data members
    vector<Complex> m_comp_array;
    // utility function to check if the transformation is valid
    // hint: use `isnan` to check the angle is valid or not
    // ref: https://en.cppreference.com/w/cpp/numeric/math/isnan
    bool _check_transform(const Complex &arg_trans_c, const char &arg_op);

public:
    // Constructor, initializes the array
    Geometry_Comp(const unsigned int &arg_num_of_vertex = 0);
    // Copy constructor
    Geometry_Comp(const Geometry_Comp &arg_gc);
    // assignment operator
    Geometry_Comp &operator=(const Geometry_Comp &arg_gc);
    // print the geometry
    virtual void print_geometry(ofstream &arg_ofs);
    // parse the cin to the geometry
    virtual void parse_geometry(ifstream &arg_ifs);
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
    void print_geometry(ofstream &arg_ofs);
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs);
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
    void print_geometry(ofstream &arg_ofs);
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs);
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
    void print_geometry(ofstream &arg_ofs);
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs);
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
    void print_geometry(ofstream &arg_ofs);
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs);
};
const unsigned circle_num_of_vertex = 2;

// error and exit
void error_and_exit()
{
    cout << "Error: Invalid input" << endl;
    exit(1);
}

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
// write data members in binary format
// note: be careful about the type used in `.write()` function
void Complex::write_binary_record(ostream &arg_os)
{
    arg_os.write((char *)&m_real, sizeof(double));
    arg_os.write((char *)&m_imag, sizeof(double));
}

// read data members in binary format
// note: use `.read()` to get the double in binary format,
// use `istream::fail()` to check the conversion is successful
// and use `istream::eof()` to check the is parse to the end of line
void Complex::read_binary_record(istream &arg_is)
{
    double input_real, input_imag;
    arg_is.read((char *)&input_real, sizeof(double));
    if (arg_is.fail())
    {
        error_and_exit();
    }
    arg_is.read((char *)&input_imag, sizeof(double));
    if (arg_is.fail())
    {
        error_and_exit();
    }
    m_real = input_real;
    m_imag = input_imag;
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
void Geometry_Comp::print_geometry(ofstream &arg_ofs)
{
    cout << "not implemented" << endl;
}
// parse the cin to the geometry
void Geometry_Comp::parse_geometry(ifstream &arg_ifs)
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
void Triangle_Comp::print_geometry(ofstream &arg_ofs)
{
    unsigned int num_of_vertex = m_comp_array.size();
    arg_ofs.write("t", 1);
    arg_ofs.write((char *)&num_of_vertex, sizeof(unsigned int));
    for (unsigned int i = 0; i < num_of_vertex; i++)
    {
        m_comp_array[i].write_binary_record(arg_ofs);
    }
}
// parse the cin to the geometry
void Triangle_Comp::parse_geometry(ifstream &arg_ifs)
{
    unsigned int vertex_num;
    arg_ifs.read((char *)&vertex_num, sizeof(unsigned int));
    if (vertex_num != triangle_num_of_vertex)
    {
        error_and_exit();
    }

    for (int i = 0; i < vertex_num; i++)
    {
        Complex c;
        c.read_binary_record(arg_ifs);
        if (arg_ifs.fail())
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
void Quadrilateral_Comp::print_geometry(ofstream &arg_ofs)
{
    arg_ofs.write("q", 1);
    unsigned int num_of_vertex = m_comp_array.size();
    arg_ofs.write((char *)&num_of_vertex, sizeof(unsigned int));
    for (int i = 0; i < quadrilateral_num_of_vertex; i++)
    {
        m_comp_array[i].write_binary_record(arg_ofs);
    }
}
// parse the cin to the geometry
void Quadrilateral_Comp::parse_geometry(ifstream &arg_ifs)
{
    unsigned int vertex_num;
    arg_ifs.read((char *)&vertex_num, sizeof(unsigned int));
    if (vertex_num != quadrilateral_num_of_vertex)
    {
        error_and_exit();
    }

    for (int i = 0; i < vertex_num; i++)
    {
        Complex c;
        c.read_binary_record(arg_ifs);
        if (arg_ifs.fail())
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
void Polygon_Comp::print_geometry(ofstream &arg_ofs)
{
    arg_ofs.write("p", 1);
    unsigned int num_of_vertex = m_comp_array.size();
    arg_ofs.write((char *)&num_of_vertex, sizeof(unsigned int));
    for (int i = 0; i < m_comp_array.size(); i++)
    {
        m_comp_array[i].write_binary_record(arg_ofs);
    }
}
// parse the cin to the geometry
void Polygon_Comp::parse_geometry(ifstream &arg_ifs)
{
    unsigned int vertex_num;
    arg_ifs.read((char *)&vertex_num, sizeof(unsigned int));
    if (vertex_num < triangle_num_of_vertex)
    {
        error_and_exit();
    }
    m_comp_array.resize(vertex_num);
    for (int i = 0; i < vertex_num; i++)
    {
        Complex c;
        c.read_binary_record(arg_ifs);
        if (arg_ifs.fail())
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
void Circle_Comp::print_geometry(ofstream &arg_ofs)
{
    arg_ofs.write("c", 1);
    unsigned int num_of_vertex = m_comp_array.size();
    arg_ofs.write((char *)&num_of_vertex, sizeof(unsigned int));
    for (int i = 0; i < circle_num_of_vertex; i++)
    {
        m_comp_array[i].write_binary_record(arg_ofs);
    }
}
// parse the cin to the geometry
void Circle_Comp::parse_geometry(ifstream &arg_ifs)
{
    unsigned int vertex_num;
    arg_ifs.read((char *)&vertex_num, sizeof(unsigned int));
    if (vertex_num != circle_num_of_vertex)
    {
        error_and_exit();
    }

    for (int i = 0; i < vertex_num; i++)
    {
        Complex c;
        c.read_binary_record(arg_ifs);
        if (arg_ifs.fail())
        {
            error_and_exit();
        }
        m_comp_array[i] = c;
    }
}

int main(int argc, char *argv[])
{
    char input;
    vector<Geometry_Comp *> geo_ptr_array;
    Geometry_Comp *geo_ptr;
    Complex trans_c;
    char trans_op;

    string input_file_path(argv[1]);
    string output_file_path(argv[2]);

    ifstream infile(input_file_path, ios::in | ios::binary);
    if (!infile)
    {
        cout << "Input file cannot open." << endl;
        return -1;
    }

    ofstream outfile(output_file_path, ios::out | ios::trunc | ios::binary);
    if (!outfile)
    {
        cout << "Output file cannot open." << endl;
        return -1;
    }

    while (infile.get(input))
    {
        // check the geometry type
        switch (input)
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
            break;
        default:
            for (int i = 0; i < geo_ptr_array.size(); i++)
            {
                delete geo_ptr_array[i];
            }
            error_and_exit();
        }
        if (input == 't' || input == 'q' || input == 'p' || input == 'c')
        {
            // parse the cin to the geometry
            geo_ptr->parse_geometry(infile);
            // print the geometry
            geo_ptr->print_geometry(outfile);
            // push the pointer to the array
            geo_ptr_array.push_back(geo_ptr);
        }
        else if (input == 'r' || input == 'z' || input == 'm')
        {
            trans_c.read_binary_record(infile);
            // transform the geometry using operator and complex
            for (int i = 0; i < geo_ptr_array.size(); i++)
            {
                geo_ptr_array[i]->transform_geometry(trans_c, input);
                // print transformed geometry
                geo_ptr_array[i]->print_geometry(outfile);
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

    for (int i = 0; i < geo_ptr_array.size(); i++)
    {
        delete geo_ptr_array[i];
    }

    infile.close();
    outfile.close();

    print_output_file(argc, argv);

    return 0;
}