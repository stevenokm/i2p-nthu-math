<!--
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
-->

# Operator & Operator Overloading 

> Slides version: [lecture6_slides.html](./lecture6_slides.html)
> Website version: [lecture6.html](./lecture6.html)

* What is Operator?
* How to write/use your own operator? (Operator Overloading)
  - Syntax
    - Unary, Binary, Ternary
  - Example
* Overloading other class's/global operator
  - Example: cout `<<` & cin `>>` operator  
---
* How to design your own operator?
  - Guidelines
* Example
  - Example: Triangle (again)
  - Example: Vector (again)
  - Example: Fixed Point Number & Fixed Point Number Calculator (again)
* Lab 6: Complex Number Calculator

## What is Operator?

Ref: [C++ Operator Precedence - cppreference.com](https://en.cppreference.com/w/cpp/language/operator_precedence)

| precedence (partial) |                           operator                            |
| :------------------: | :-----------------------------------------------------------: |
|          1           |                         `a++`, `a--`                          |
|          2           |                         `++a`, `--a`                          |
|          3           |                          `+a`, `-a`                           |
|                      |                          `!a`, `~a`                           |
|                      |                           `(type)`                            |
|          5           |                   `a * b`, `a / b`, `a % b`                   |
|          6           |                       `a + b`, `a - b`                        |
|          7           |                      `a << b`, `a >> b`                       |
|          9           |             `a < b`, `a <= b`, `a > b`, `a >= b`              |
|          10          |                      `a == b`, `a != b`                       |
|          11          |                            `a & b`                            |
|          12          |                            `a ^ b`                            |
|          13          |                           `a \| b`                            |
|          14          |                           `a && b`                            |
|          15          |                          `a \|\| b`                           |
|          16          | `a ? b : c`, `a = b`, `a += b`, `a -= b`, `a *= b`, `a /= b`  |
|                      | `a %= b`, `a <<= b`, `a >>= b`, `a &= b`, `a ^= b`, `a \|= b` |


## How to write/use your own operator? (Operator Overloading)

### Example: `Point_2D` (partial)

- we want to compare two `Point_2D`
- we want to assign a `Point_2D` to another `Point_2D`
- we want to print/output a `Point_2D`
- we want to read/input a `Point_2D`

---

naive implementation:

``` c++
class Point_2D
{
private:
/// ...

public:
/// ...
    // print the point in the format (x, y)
    void print() const;
    // read the point from input
    void read();
    // modify the x and y coordinate
    void set_x(const double &arg_x);
    void set_y(const double &arg_y);
    void set(const double &arg_x, const double &arg_y);
    // get the x coordinate and y coordinate
    double get_x() const;
    double get_y() const;
    // compare two points
    bool equal(const Point_2D &arg_point) const;
    bool not_equal(const Point_2D &arg_point) const;
    bool less(const Point_2D &arg_point) const;
    bool greater(const Point_2D &arg_point) const;
    bool less_equal(const Point_2D &arg_point) const;
    bool greater_equal(const Point_2D &arg_point) const;
    // assign the point with another point
    Point_2D assign(const Point_2D &arg_point);
};
```
---

Can we use `operator` like `>`, `!=` to implement the above? Yes!

``` c++
class Point_2D
{
private:
/// ...

public:
/// ...
    // print the point in the format (x, y)
    friend std::ostream &operator<<(std::ostream &os, const Point_2D &arg_point);
    // read the point from input
    friend std::istream &operator>>(std::istream &is, Point_2D &arg_point);
    // modify the x and y coordinate
    void set_x(const double &arg_x);
    void set_y(const double &arg_y);
    void set(const double &arg_x, const double &arg_y);
    // get the x coordinate and y coordinate
    double get_x() const;
    double get_y() const;
    // compare two points
    bool operator==(const Point_2D &arg_point) const;
    bool operator!=(const Point_2D &arg_point) const;
    bool operator<(const Point_2D &arg_point) const;
    bool operator>(const Point_2D &arg_point) const;
    bool operator<=(const Point_2D &arg_point) const;
    bool operator>=(const Point_2D &arg_point) const;
    // assign the point with another point
    Point_2D operator=(const Point_2D &arg_point);
};
```
---

Usage:

``` c++
int main()
{
    Point_2D point1, point2;
    cin >> point1 >> point2;
    cout << point1 << point2 << endl;
    if (point1 == point2)
    {
        std::cout << "point1 == point2" << std::endl;
    }
    else
    {
        std::cout << "point1 != point2" << std::endl;
    }
    point1 = point2;
    if (point1 == point2)
    {
        std::cout << "point1 == point2" << std::endl;
    }
    else
    {
        std::cout << "point1 != point2" << std::endl;
    }
    return 0;
}
```

---
### Syntax

Ref: [Operator Overloading in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/operator-overloading-c/), [operator overloading - cppreference.com](https://en.cppreference.com/w/cpp/language/operators)

- `operator<op>`, where `<op>` is one of the following:
  - `+`, `-`, `*`, `/`, `%`, `^`, `&`, `|`, `~`, `!`, `=`, `<`, `>`, `+=`, `-=`, `*=`, `/=`, `%=`, `^=`, `&=`, `|=`, `<<`, `>>`, `>>=`, `<<=`, `==`, `!=`, `<=`, `>=`, `&&`, `||`, `++`, `--`, `,`, `->*`, `->`, `( )`, `[ ]`
- `operator <type>`, where `<type>` is one of the following: (type conversion)
  - `int`, `long`, `long long`, `unsigned`, `unsigned long`, `unsigned long long`, `float`, `double`, `long double`, `char`, `bool`, or user-defined type defined by `typedef`

---
### Syntax (cont.)
- 2 types of operator:
  - unary operator: `(a).operator@()`, `operator@()`, `(a).operator@(0)`, `operator@(a, 0)`
  - binary operator: `(a).operator@(b)`, `operator@(a, b)`, `(a).operator=(b)`

---
### Example (member function)

```c++
#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
```
---
```c++
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
}
```

---
### Example (friend function)

```c++
#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
```
---
```c++
    // The global operator function is made friend of this class so
    // that it can access private members
    friend Complex operator+(Complex const &, Complex const &);
};

Complex operator+(Complex const &c1, Complex const &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}
```

---
### Example (type conversion)

```c++
#include <iostream>
using namespace std;
class Fraction
{
private:
	int num, den;
public:
	Fraction(int n, int d) { num = n; den = d; }

	// Conversion operator: return float value of fraction
	operator float() const {
		return float(num) / float(den);
	}
};

int main() {
	Fraction f(2, 5);
	float val = f;
	cout << val << '\n';
	return 0;
}
```

## Overloading other class's/global operator

Ref: [operator overloading - cppreference.com](https://en.cppreference.com/w/cpp/language/operators)

- Global operator: To overload a global operator, you can define a function with the same name as the operator.
- Other class's operator: To overload a member operator, you need to inherit from the class and define a function with the same name as the operator. (disscuss in Lecture 9)

---
### Example: cout `<<` & cin `>>` operator  

``` c++
#include <iostream>
#include <string>

using namespace std;

class Point_2D
{
private:
    // record the x coordinate
    double m_x;
    // record the y coordinate
    double m_y;

public:
    // print the point in the format (x, y)
    friend std::ostream &operator<<(std::ostream &arg_os, const Point_2D &arg_point)
    {
        arg_os << "(" << arg_point.m_x << ", " << arg_point.m_y << ")";
        return arg_os;
    }
```
---
```c++
    // read the coordinate of a point from the input, format: (x, y) and ignore space
    friend std::istream &operator>>(std::istream &arg_is, Point_2D &arg_point)
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
        return arg_is;
    }
};
```
---
```c++
int main()
{
    Point_2D point;
    cin >> point;
    cout << point << endl;
    return 0;
}
```

Output:
```console
$ ./a.out
(1.0, 2.0)⏎
(1, 2)
$
```

## How to design your own operator?

Ref: [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#Operator_Overloading), This section is licensed under the Apache License 2.0

> Define overloaded operators only if their meaning is obvious, unsurprising, and consistent with the corresponding built-in operators.
> For example, use `|` as a bitwise- or logical-or, not as a shell-style pipe.
---
> Define operators only on your own types. More precisely, define them in the same headers, .cc files, and namespaces as the types they operate on. That way, the operators are available wherever the type is, minimizing the risk of multiple definitions. 
> If possible, avoid defining operators as templates, because they must satisfy this rule for any possible template arguments. 
> If you define an operator, also define any related operators that make sense, and make sure they are defined consistently. For example, if you overload `<`, overload all the comparison operators, and make sure `<` and `>` never return true for the same arguments.
---
> Prefer to define non-modifying binary operators as non-member functions. 
> If a binary operator is defined as a class member, implicit conversions will apply to the right-hand argument, but not the left-hand one. It will confuse your users if `a < b` compiles but `b < a` doesn't.
---
> Don't go out of your way to avoid defining operator overloads. 
> For example, prefer to define `==`, `=`, and `<<`, rather than `Equals()`, `CopyFrom()`, and `PrintTo()`. 
> Conversely, don't define operator overloads just because other libraries expect them. 
> For example, if your type doesn't have a natural ordering, but you want to store it in a `std::set`, use a custom comparator rather than overloading `<`.
---
> Do not overload `&&`, `||`, `,` (comma), or unary `&`. Do not overload `operator""`, i.e., do not introduce user-defined literals. Do not use any such literals provided by others (including the standard library).
---
> Type conversion operators are covered in the section on [implicit conversions](https://google.github.io/styleguide/cppguide.html#Implicit_Conversions).
> The `=` operator is covered in the section on [copy constructors](https://google.github.io/styleguide/cppguide.html#Copyable_Movable_Types).
> Overloading `<<` for use with streams is covered in the section on [streams](https://google.github.io/styleguide/cppguide.html#Streams).
> See also the rules on [function overloading](https://google.github.io/styleguide/cppguide.html#Function_Overloading), which apply to operator overloading as well.

## Example 1: Triangle (again) [[Source](./lecture6_ex1.html)]

A Triangle:
- contains 3 points
- on the 2D plane
- need to be able to calculate the area
- need to be initialized, printed, and modified

## Example 2: Vector (again) [[Source](./lecture6_ex2.html)]

A Vector:
- contains 3 factors of the 3 basis $\bold{i}$, $\bold{j}$, $\bold{k}$
- need to be able to calculate the length
- need to be able to calculate the dot, cross product
- need to be initialized, printed, and modified

## Example 3: Fixed Point Number & Fixed Point Number Calculator (again) [[Source](./lecture6_ex3.html)]

A Fixed Point Number:
- contains a integer part, a fractional part, and a precision
- need to be able to calculate the sum, difference
- need to be able to convert to/from string, `float`, and `double`
- need to be initialized, printed, and modified
---
A Fixed Point Number Calculator:
- contains current value, input value, and operation
- need to be able to set the input value
- need to be able to set the operation
- need to be able to calculate the result
- need to be able to clear the input value
- need to be initialized
- need to be able to get all information

## Lab 6: [Complex Number Calculator](./lab/lab6-1.html)