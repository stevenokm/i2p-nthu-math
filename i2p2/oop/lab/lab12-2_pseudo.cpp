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
    // use `atan2` to compute the angle by the formula `atan(imag/real)`
    // and use `NAN` for 0/0 case
    // `atan2` ref: https://en.cppreference.com/w/cpp/numeric/math/atan2
    // `NAN` ref: https://en.cppreference.com/w/cpp/numeric/math/NAN
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

// used for process the test cases, do not modify
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
    }
    return 0;
}