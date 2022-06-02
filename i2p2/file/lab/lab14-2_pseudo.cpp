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

int main(int argc, char *argv[])
{
    char input;
    vector<Geometry_Comp *> geo_ptr_array;
    Geometry_Comp *geo_ptr;
    Complex trans_c;
    char trans_op;

    string input_file_path(argv[1]);
    string output_file_path(argv[2]);

    // open & check input file

    // open & check output file

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

    // close input and output file

    print_output_file(argc, argv);

    return 0;
}