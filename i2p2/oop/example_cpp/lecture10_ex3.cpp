#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Triangle_Complex; // forward declaration

class Integer
{
protected:
    int m_int_value;

public:
    Integer(int arg_int_value = 0) : m_int_value(arg_int_value)
    {
    }
    Integer(const Integer &arg_int) : m_int_value(arg_int.m_int_value)
    {
    }
    operator int() const
    {
        return m_int_value;
    }
    Integer &operator=(const Integer &arg_int)
    {
        m_int_value = arg_int.m_int_value;
        return *this;
    }
    void set_int_value(int arg_int_value)
    {
        m_int_value = arg_int_value;
    }
    friend ostream &operator<<(ostream &arg_os, const Integer &arg_integer)
    {
        arg_os << arg_integer.m_int_value;
        return arg_os;
    }
    friend istream &operator>>(istream &arg_is, Integer &arg_integer)
    {
        arg_is >> arg_integer.m_int_value;
        return arg_is;
    }
    friend Integer operator+(const Integer &arg_integer1, const Integer &arg_integer2)
    {
        Integer temp_integer(arg_integer1.m_int_value + arg_integer2.m_int_value);
        return temp_integer;
    }
    friend Integer operator-(const Integer &arg_integer1, const Integer &arg_integer2)
    {
        Integer temp_integer(arg_integer1.m_int_value - arg_integer2.m_int_value);
        return temp_integer;
    }
    friend Integer operator*(const Integer &arg_integer1, const Integer &arg_integer2)
    {
        Integer temp_integer(arg_integer1.m_int_value * arg_integer2.m_int_value);
        return temp_integer;
    }
    friend Integer operator/(const Integer &arg_integer1, const Integer &arg_integer2)
    {
        Integer temp_integer(arg_integer1.m_int_value / arg_integer2.m_int_value);
        return temp_integer;
    }
};

// Real is a Integer
class Real : public Integer
{
protected:
    double m_after_decimal;

public:
    Real(double arg_value = 0.0) : Integer((int)arg_value),
                                   m_after_decimal(arg_value - (int)arg_value)
    {
    }
    Real(const Real &arg_real) : Integer(arg_real),
                                 m_after_decimal(arg_real.m_after_decimal)
    {
    }
    operator double() const
    {
        return m_after_decimal + (double)m_int_value;
    }
    Real &operator=(const Real &arg_real)
    {
        m_int_value = arg_real.m_int_value;
        m_after_decimal = arg_real.m_after_decimal;
        return *this;
    }
    void set_real_value(double arg_value)
    {
        m_int_value = (int)arg_value;
        m_after_decimal = arg_value - m_int_value;
    }
    friend ostream &operator<<(ostream &arg_os, const Real &arg_real)
    {
        arg_os << (double)arg_real;
        return arg_os;
    }
    friend istream &operator>>(istream &arg_is, Real &arg_real)
    {
        double temp_double;
        arg_is >> temp_double;
        arg_real.set_real_value(temp_double);
        return arg_is;
    }
    friend Real operator+(const Real &arg_real1, const Real &arg_real2)
    {
        // call the Integer operator+ to add the Integer part
        Integer temp_integer((Integer)arg_real1 + (Integer)arg_real2);
        Real temp_real(arg_real1.m_after_decimal + arg_real2.m_after_decimal);
        temp_real.set_int_value((int)temp_integer + (int)temp_real);
        return temp_real;
    }
    friend Real operator-(const Real &arg_real1, const Real &arg_real2)
    {
        Real temp_real((double)arg_real1 - (double)arg_real2);
        return temp_real;
    }
    friend Real operator*(const Real &arg_real1, const Real &arg_real2)
    {
        Real temp_real((double)arg_real1 * (double)arg_real2);
        return temp_real;
    }
    friend Real operator/(const Real &arg_real1, const Real &arg_real2)
    {
        Real temp_real((double)arg_real1 / (double)arg_real2);
        return temp_real;
    }
};

class Imaginary
{
protected:
    double m_imaginary_value;

public:
    Imaginary(double arg_imaginary_value = 0.0) : m_imaginary_value(arg_imaginary_value)
    {
    }
    Imaginary(const Imaginary &arg_imaginary) : m_imaginary_value(arg_imaginary.m_imaginary_value)
    {
    }
    Imaginary &operator=(const Imaginary &arg_imaginary)
    {
        m_imaginary_value = arg_imaginary.m_imaginary_value;
        return *this;
    }
    double get_imaginary_value() const
    {
        return m_imaginary_value;
    }
    void set_imaginary_value(double arg_imaginary_value)
    {
        m_imaginary_value = arg_imaginary_value;
    }
    friend ostream &operator<<(ostream &arg_os, const Imaginary &arg_imaginary)
    {
        arg_os << arg_imaginary.m_imaginary_value << "i";
        return arg_os;
    }
    friend Imaginary operator+(const Imaginary &arg_imaginary1, const Imaginary &arg_imaginary2)
    {
        Imaginary temp_imaginary(arg_imaginary1.m_imaginary_value + arg_imaginary2.m_imaginary_value);
        return temp_imaginary;
    }
    friend Imaginary operator-(const Imaginary &arg_imaginary1, const Imaginary &arg_imaginary2)
    {
        Imaginary temp_imaginary(arg_imaginary1.m_imaginary_value - arg_imaginary2.m_imaginary_value);
        return temp_imaginary;
    }
};

class Complex : public Real, public Imaginary
{
public:
    Complex(double arg_real_value = 0.0,
            double arg_imaginary_value = 0.0)
        : Real(arg_real_value),
          Imaginary(arg_imaginary_value)
    {
    }
    Complex(const Complex &arg_complex)
        : Real(arg_complex),
          Imaginary(arg_complex)
    {
    }
    Complex &operator=(const Complex &arg_complex)
    {
        Real::operator=(arg_complex);
        Imaginary::operator=(arg_complex);
        return *this;
    }
    Complex reciprocal() const
    {
        Complex temp_complex(*this);
        double temp_real_value = temp_complex;
        double temp_imaginary_value = temp_complex.get_imaginary_value();
        double temp_denominator = temp_real_value * temp_real_value + temp_imaginary_value * temp_imaginary_value;
        temp_complex.set_real_value(temp_real_value / temp_denominator);
        temp_complex.set_imaginary_value(-temp_imaginary_value / temp_denominator);
        return temp_complex;
    }
    double get_magnitude() const
    {
        Real temp_real(*this);
        return sqrt((double)(temp_real * temp_real) + get_imaginary_value() * get_imaginary_value());
    }
    Complex get_argument() const
    {
        double magnitude = get_magnitude();
        Complex temp_complex((double)(*this) / magnitude, get_imaginary_value() / magnitude);
        return temp_complex;
    }
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_complex)
    {
        arg_os << (Real)arg_complex << " + " << (Imaginary)arg_complex;
        return arg_os;
    }
    friend istream &operator>>(istream &arg_is, Complex &arg_complex)
    {
        string temp_string;
        getline(arg_is, temp_string, '+');
        arg_complex.set_real_value(stod(temp_string));
        getline(arg_is, temp_string, 'i');
        arg_complex.set_imaginary_value(stod(temp_string));
        return arg_is;
    }
    friend Complex operator+(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex((double)arg_complex1 + (double)arg_complex2,
                             arg_complex1.get_imaginary_value() + arg_complex2.get_imaginary_value());
        return temp_complex;
    }
    friend Complex operator-(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex((double)arg_complex1 - (double)arg_complex2,
                             arg_complex1.get_imaginary_value() - arg_complex2.get_imaginary_value());
        return temp_complex;
    }
    friend Complex operator*(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex((double)arg_complex1 * (double)arg_complex2 -
                                 arg_complex1.get_imaginary_value() * arg_complex2.get_imaginary_value(),
                             (double)arg_complex1 * arg_complex2.get_imaginary_value() +
                                 arg_complex1.get_imaginary_value() * (double)arg_complex2);
        return temp_complex;
    }
    friend Complex operator/(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        Complex temp_complex(arg_complex1 * arg_complex2.reciprocal());
        return temp_complex;
    }
    friend bool operator==(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        return ((double)arg_complex1 == (double)arg_complex2) &&
               (arg_complex1.get_imaginary_value() == arg_complex2.get_imaginary_value());
    }
    friend bool operator!=(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        return !(arg_complex1 == arg_complex2);
    }
    friend bool operator<(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        return ((double)arg_complex1 < (double)arg_complex2) ||
               ((double)arg_complex1 == (double)arg_complex2 &&
                arg_complex1.get_imaginary_value() < arg_complex2.get_imaginary_value());
    }
    friend bool operator>(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        return arg_complex2 < arg_complex1;
    }
    friend bool operator<=(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        return !(arg_complex1 > arg_complex2);
    }
    friend bool operator>=(const Complex &arg_complex1, const Complex &arg_complex2)
    {
        return !(arg_complex1 < arg_complex2);
    }
    friend class Triangle_Complex;
};

// Triangle_Complex class declaration
class Triangle_Complex
{
protected:
    // define three points of the Triangle_Complex
    // Triangle 'has-a' Complex, so it use composition
    Complex m_point[3];

    // check & correct the Triangle_Complex points to counterclockwise order
    void _check_points()
    {
        // if the area is negative, swap the points
        if (area() < 0.0)
        {
            Complex temp = m_point[0];
            m_point[0] = m_point[1];
            m_point[1] = temp;
        }
    }

public:
    // Constructor
    Triangle_Complex(const Complex &arg_point1,
                     const Complex &arg_point2,
                     const Complex &arg_point3)
        : m_point{arg_point1, arg_point2, arg_point3}
    {
        _check_points();
    }

    // Copy constructor
    Triangle_Complex(const Triangle_Complex &arg_triangle)
        : m_point{arg_triangle.m_point[0], arg_triangle.m_point[1], arg_triangle.m_point[2]}
    {
    }

    // Destructor
    ~Triangle_Complex() {} // do nothing

    // modify the three points of the Triangle_Complex
    void set_points(const Complex &arg_point1,
                    const Complex &arg_point2,
                    const Complex &arg_point3)
    {
        m_point[0] = arg_point1;
        m_point[1] = arg_point2;
        m_point[2] = arg_point3;
        _check_points();
    }
    void set_point1(const Complex &arg_point1)
    {
        m_point[0] = arg_point1;
        _check_points();
    }
    void set_point2(const Complex &arg_point2)
    {
        m_point[1] = arg_point2;
        _check_points();
    }
    void set_point3(const Complex &arg_point3)
    {
        m_point[2] = arg_point3;
        _check_points();
    }
    // get the three points of the Triangle_Complex
    Complex get_point1() const
    {
        return m_point[0];
    }
    Complex get_point2() const
    {
        return m_point[1];
    }
    Complex get_point3() const
    {
        return m_point[2];
    }

    // calculate the area of the Triangle_Complex
    double area()
    {
        double area = 0.0;
        for (int i = 0; i < 3; i++)
        {
            area += (double)m_point[i] * m_point[(i + 1) % 3].get_imaginary_value();
            area -= m_point[i].get_imaginary_value() * (double)m_point[(i + 1) % 3];
        }
        return area / 2.0;
    }

    // print the Triangle_Complex
    // format: (c1, c2, c3)
    friend std::ostream &operator<<(std::ostream &arg_os, const Triangle_Complex &arg_tri)
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
    // format: (c1, c2, c3) and ignore space
    friend std::istream &operator>>(std::istream &arg_is, Triangle_Complex &arg_tri)
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

        // check & correct the Triangle_Complex points to counterclockwise order
        arg_tri._check_points();

        return arg_is;
    }
};

class Equilateral_Triangle_Complex : public Triangle_Complex
// Equilateral Triangle `is-a' Triangle_Complex, so it use inheritance
// use function overloading to implement the different function
// of Equilateral_Triangle_Complex
// details will be discussed in polymorphism (next chapter)
{
public:
    Equilateral_Triangle_Complex(const Complex &arg_point1,
                                 const Complex &arg_point2)
        : Triangle_Complex(arg_point1, arg_point2, arg_point1)
    {
        Complex temp = arg_point2 - arg_point1;
        temp = temp * Complex(0.5, sqrt(3.0) / 2.0); // rotate 60 degree
        m_point[2] = arg_point1 + temp;              // calculate the third point
        _check_points();
    }

    void set_points(const Complex &arg_point1,
                    const Complex &arg_point2)
    {
        m_point[0] = arg_point1;
        m_point[1] = arg_point2;
        Complex temp = arg_point2 - arg_point1;
        temp = temp * Complex(0.5, sqrt(3.0) / 2.0); // rotate 60 degree
        m_point[2] = arg_point1 + temp;              // calculate the third point
        _check_points();
    }

    void set_point1(const Complex &arg_point1)
    {
        // invalid operation
    }
    void set_point2(const Complex &arg_point2)
    {
        // invalid operation
    }
    void set_point3(const Complex &arg_point3)
    {
        // invalid operation
    }
    // read the coordinate of a point from the input,
    // format: (c1, c2, c3) and ignore c3 and spaces
    friend std::istream &operator>>(std::istream &arg_is,
                                    Equilateral_Triangle_Complex &arg_tri)
    {
        string temp;
        if (getline(arg_is, temp, '(')) // ignore the first '('
        {
            for (int i = 0; i < 3; i++)
            {
                if (i < 2)
                {
                    arg_is >> arg_tri.m_point[i];
                    getline(arg_is, temp, ','); // ignore the ','
                }
            }
            getline(arg_is, temp, ')'); // ignore the c3 and last ')'
        }

        // check & correct the Triangle_Complex points to counterclockwise order
        arg_tri._check_points();

        return arg_is;
    }
};

// main function

int main()
{
    Equilateral_Triangle_Complex t(Complex(1, 1), Complex(2, 2));
    cout << t << endl;
    cout << "Area: " << t.area() << endl;

    // change the points of the Triangle_Complex
    cin >> t;
    cout << t << endl;
    cout << "Area: " << t.area() << endl;

    return 0;
}