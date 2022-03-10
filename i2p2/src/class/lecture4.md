<!--
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
-->

# Class Constructor & Modifer 

> Slides version: [lecture4_slides.html](./lecture4_slides.html)
> Website version: [lecture4.html](./lecture4.html)

* Define Class Data Members & Member Functions (again)
* How to initialize and modify class members?
* Class constructor & copy constructor
* Class getter & setter
  - Access `public`, `private`, members
* Class destructor
---
* `const` function & `const` class instance
* Member function & Global function
* How to design class interface?
  - Example: Triangle (again)
  - Example: Vector (again)
  - Example: Integer Calculator (again)
* Lab 4: Complex Number

## Define Class Data Members & Member Functions

- Why do we need data members?
  - To store data
  - Make data accessible
- **Why do we need member functions?**
  * To perform operations
  * Ease of access to data

---

### Design member functions

Guidelines:

* each member function should show it's accessibility explicitly
  - '_' is used to indicate a member function used internally (`private`)
  - all other functions are public
* essential member functions should be defined in the class
  - getter & setter
  - constructor & destructor
  - `operator=` (disscuss on later lecture)
  - etc.
* utility functions are usually for in-class use
  - utility functions are used to help other member functions and make it reusable, readable, and maintainable
---
* naming of member functions should be consistent with the class name
  - `get_` for getter
  - `set_` for setter
  - `is_` for predicate
  - `has_` for predicate
  - `add_` for mutator
  - `remove_` for mutator
  - `clear_` for mutator
  - `size_` for predicate
  - `to_string_` for predicate
  - `from_string_` for mutator
  - etc.

---

Example: `Point_2D`

```c++
#include <iostream>

using namespace std;

class Point_2D // the class name
// we use first upper case letter to indicate a class
{
private: // private data members & member functions
    // Data members
    // we use `m_` to indicate a data member

    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;

    // Member functions
    // we use `_` to indicate a member function

    // check if the point is valid
    void _check_validity();
```
---
``` c++
public: // public member functions
    // Constructor

    // Constructor & Default constructor
    // initialize data members, with default values
    // accessable to const object by default
    Point_2D(const int &arg_x = 0, const int &arg_y = 0);

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
```
---
``` c++    
    // Member functions
    // we use lower case letter to indicate a member function
    // also, we just define the function declaration
    // and leave the definition to the end of the class

    // print the x and y coordinate in format (x, y)
    // accessable to const object
    void print() const;
    // modify the x and y coordinate
    // we use `arg_` to indicate the arguments
    // and re-write with setter
    void set_x(const int &arg_x);
    void set_y(const int &arg_y);
    void set(const int &arg_x, const int &arg_y);
    // get the x coordinate and y coordinate
    // accessable to const object
    int get_x() const;
    int get_y() const;
};
```
---
``` c++
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
```
---
```c++
// Constructor & Default constructor
// initialize data members, with default values
Point_2D::Point_2D(const int &arg_x, const int &arg_y)
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
```
---
``` c++
// print the x and y coordinate
// accessable to const object
void Point_2D::print() const
{
    cout << "(" << m_x << ", " << m_y << ")";
}

// modify the x and y coordinate
// we use `arg_` to indicate the arguments
// and re-write with setter
void Point_2D::set_x(const int &arg_x)
{
    m_x = arg_x;
    // check if the point is valid
    _check_validity();
}
void Point_2D::set_y(const int &arg_y)
{
    m_y = arg_y;
    // check if the point is valid
    _check_validity();
}
```
---
``` c++
void Point_2D::set(const int &arg_x, const int &arg_y)
{
    m_x = arg_x;
    m_y = arg_y;
    // check if the point is valid
    _check_validity();
}

// get the x coordinate and y coordinate
// accessable to const object
int Point_2D::get_x() const
{
    return m_x;
}
int Point_2D::get_y() const
{
    return m_y;
}
```
---
``` c++
// main function

int main()
{
    // create a Point_2D object with initial values
    Point_2D p1(1, 2);
    // or create with another Point_2D object
    Point_2D p2(p1);
    // print 2 instances of Point
    p1.print();
    cout << endl;
    // or use getter
    cout << "(" << p2.get_x() << ", "
         << p2.get_y() << ")" << endl;
```
---
``` c++
    // modify each instance with setter
    p1.set(3, 4);
    p2.set_x(5);
    p2.set_y(6);
    // you can see the change in p1 and p2
    p1.print();
    cout << endl;
    // or use getter
    cout << "(" << p2.get_x() << ", "
         << p2.get_y() << ")" << endl;
    return 0;
}
```

## How to initialize and modify class members?

* To initialize class members, we use constructor.
  - The constructor is a function that is called when an object is created.
* To modify class members, we use setter.
  - The setter is a function that is called when we want to modify the value of a class member.

## Class constructor & copy constructor

* The constructor is a function that is called when an object is created.
* 3 types of constructor
  * constructor with no arguments
    - usally used to initialize data members with default values
  * constructor with arguments
    - usally used to initialize data members with given values
  * constructor with another same-type object (copy constructor)
    - usally used to copy data members from another object
---
Syntax:

``` c++
class class_name
{
  public:
    // default constructor
    class_name();
    // constructor with arguments
    class_name(int arg_x, int arg_y);
    // constructor with arguments that has default value
    // the usage is the same as the default constructor
    class_name(int arg_x = 0, int arg_y = 0);
    // copy constructor
    class_name(const class_name &arg_class_name);
};
```
---
Example: `Point_2D` (partial)
``` c++
public: // public member functions
    // Constructor

    // Constructor & Default constructor
    // initialize data members, with default values
    // accessable to const object by default
    Point_2D(const int &arg_x = 0, const int &arg_y = 0);

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
```
---
```c++
// Constructor & Default constructor
// initialize data members, with default values
Point_2D::Point_2D(const int &arg_x, const int &arg_y)
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
```

## Class getter & setter

* The getter is a function that is called when we want to access the value of a class member.
* The setter is a function that is called when we want to modify the value of a class member.
* Getter and setter will check if the value is valid.
---
Example: `Point_2D` (partial)

``` c++
class Point_2D
{
private: // private data members & member functions
    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;

public: // public member functions
    // Setter
    // modify the x and y coordinate
    // we use `arg_` to indicate the arguments
    // and re-write with setter
    void set_x(const int &arg_x);
    void set_y(const int &arg_y);
    void set(const int &arg_x, const int &arg_y);
    // Getter
    // get the x coordinate and y coordinate
    // accessable to const object
    int get_x() const;
    int get_y() const;
};
```

## Class destructor

* The destructor is a function that is called when an object is destroyed.
* The destructor is usually used to free the memory that is allocated by the constructor.
---
Syntax:

``` c++
class class_name
{
  public:
    // default constructor
    class_name();

    // destructor
    ~class_name();
};
```

## `const` function & `const` class instance

* How to access the member of a class that is declared as `const`?
  * add `const` to the class declaration

---

Example: `Point_2D` (partial)

``` c++
class Point_2D
{
private: // private data members & member functions
    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;

public: // public member functions
    // print the x and y coordinate in format (x, y)
    // we add `const` so that it can access the value form a const object
    void print() const;
    // Setter
    // modify the x and y coordinate
    // we don't add `const` because it will modify the value
    void set_x(const int &arg_x);
    void set_y(const int &arg_y);
    void set(const int &arg_x, const int &arg_y);
    // Getter
    // get the x coordinate and y coordinate
    // we add `const` so that it can access the value form a const object
    int get_x() const;
    int get_y() const;
};
```
---
``` c++
// main function

int main()
{
    // create a Point_2D object with initial values
    Point_2D p1(1, 2);
    // also create a `const` Point_2D object
    const Point_2D p2(3, 4);
    // create a `const` with another Point_2D object
    const Point_2D p3(p1);
    // print 3 instances of Point
    p1.print();
    cout << endl;
    // getter can be used to access the member of a `const` object
    cout << "(" << p2.get_x() << ", "
         << p2.get_y() << ")" << endl;
    // also `print()` can be used to access the member of a `const` object
    p3.print();
    cout << endl;

    // modify each instance with setter
    p1.set(3, 4);
    p2.set_x(5); // error, cannot modify the member of a `const` object
    p2.set_y(6); // error, cannot modify the member of a `const` object
    return 0;
}
```

## Member function & Global function

Rather than design a member function in a class, we can design a global function to process a class instance.

* Member function usually process the data members of a class.
  * public: getter, setter, constructor, destructor, etc.
  * private: utility functions, debug functions, etc.
* Global function usually process class instances with member functions.
  * like normal function.
  * but friend function can access the member of a class. (discuss in the next lecture)

---

Example: `Point_2D`

```c++
#include <iostream>

using namespace std;

class Point_2D // the class name
// we use first upper case letter to indicate a class
{
private: // private data members & member functions
    // Data members
    // we use `m_` to indicate a data member

    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;

    // Private member functions
    // we use `_` to indicate a private member function

    // utility: check if the point is valid
    void _check_validity();
```
---
``` c++
public: // public member functions
    // Constructor

    // Constructor & Default constructor
    // initialize data members, with default values
    // accessable to const object by default
    Point_2D(const int &arg_x = 0, const int &arg_y = 0);

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
```
---
``` c++    
    // Member functions
    // we use lower case letter to indicate a member function
    // also, we just define the function declaration
    // and leave the definition to the end of the class

    // print the x and y coordinate in format (x, y)
    // accessable to const object
    void print() const;
    // modify the x and y coordinate
    // we use `arg_` to indicate the arguments
    // and re-write with setter
    void set_x(const int &arg_x);
    void set_y(const int &arg_y);
    void set(const int &arg_x, const int &arg_y);
    // get the x coordinate and y coordinate
    // accessable to const object
    int get_x() const;
    int get_y() const;
};
```

## How to design class interface?

* To design a class interface, we need to know the following:
  * What is the interface of the class?
    - What is the input?
    - What is the output?
    - What is the return value?
  * How to implement the interface?
    - How to use the interface?
    - How to call the interface?
* Usually have guidelines in a team to design the interface.
  * To simplify it, we can use the following guidelines for the course.
---
Guidelines: (again)

- each member function should show it's accessibility explicitly
  - '_' is used to indicate a member function used internally (`private`)
  - all other functions are public
- essential member functions should be defined in the class
  - getter & setter
  - constructor & destructor
  - `operator=` (disscuss on later lecture)
  - etc.
- utility functions are usually for in-class use
  - utility functions are used to help other member functions and make it reusable, readable, and maintainable
---
- naming of member functions should be consistent with the class name
  - `get_` for getter
  - `set_` for setter
  - `is_` for predicate
  - `has_` for predicate
  - `add_` for mutator
  - `remove_` for mutator
  - `clear_` for mutator
  - `size_` for predicate
  - `to_string_` for predicate
  - `from_string_` for mutator
  - etc.

## Example 1: Triangle (again) [[Source](./lecture4_ex1.html)]

A Triangle:
- contains 3 points
- on the 2D plane
- need to be able to calculate the area
- need to be initialized, printed, and modified

## Example 2: Vector (again) [[Source](./lecture4_ex2.html)]

A Vector:
- contains 3 factors of the 3 basis $\bold{i}$, $\bold{j}$, $\bold{k}$
- need to be able to calculate the length
- need to be able to calculate the dot, cross product
- need to be initialized, printed, and modified

## Example 3: Integer Calculator (again) [[Source](./lecture4_ex3.html)]

A Integer Calculator:
- contains current value, input value, and operation
- neet to be able to set the input value
- neet to be able to set the operation
- neet to be able to calculate the result
- neet to be able to clear the input value
- need to be initialized
- need to be able to get all information

## Lab 4: [Complex Number](./lab4-1.html)