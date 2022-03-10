<!--
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
-->

# Class Data Members & Member Functions

> Slides version: [lecture3_slides.html](./lecture3_slides.html)
> Website version: [lecture3.html](./lecture3.html)

* Define Class Data Members & Member Functions
* `public`, `private`, `protected` member
  * Kickstart of getter & setter
* `this` member
* Variable scope in a class
  * `::` scope resolution operator
---
* `static` data member
  * Kickstart of constructor & destructor 
* Example 1: Triangle (again)
* Example 2: Vector (again)
* Example 3: Integer Calculator

## Define Class Data Members & Member Functions

* Why do we need data members?
  * To store data
  * Make data accessible
* Why do we need member functions?
  * To perform operations
  * Ease of access to data

---

### Design data members

Guidelines:

* each data member should be seen only by its owner
  * if you want to access it, you need to use getter & setter (discussed on next lecture)
* if you want a data member to be accessible by other classes, you should handle it carefully
* the naming convention of data members should be consistent, meaningful, and easy to understand
  * `_` is used to separate words
  * `m_` is used to indicate a data member
  * `arg_` is used to indicate an argument
  * etc.

---

Example: `Point_2D`

```c++
#include <iostream>

using namespace std;

class Point_2D // the class name
// we use first upper case letter to indicate a class
{
private: // private data members
         // we will discuss it later
    // Data members
    // we use `m_` to indicate a data member

    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;
```
---
``` c++
public: // public member functions
        // we will discuss in the next lecture
    
    // Member functions
    // we use lower case letter to indicate a member function
    // also, we just define the function declaration
    // and leave the definition to the end of the class

    // iniialize the x and y coordinate
    void init();
    // print the x and y coordinate
    void print();
    // modify the x and y coordinate
    // we use `arg_` to indicate the arguments
    void modify(const int &arg_x, const int &arg_y);
};
```
---
``` c++
// function definition

// initialize the x and y coordinate
void Point_2D::init()
{
    m_x = 0;
    m_y = 0;
}
// print the x and y coordinate
void Point_2D::print()
{
    cout << "(" << m_x << ", " << m_y << ")";
}
// modify the x and y coordinate
// we use `arg_` to indicate the arguments
void Point_2D::modify(const int &arg_x, const int &arg_y)
{
    m_x = arg_x;
    m_y = arg_y;
}
```
---
``` c++
// main function

int main()
{
    Point_2D p1, p2;
    // init 2 instances of Point
    p1.init();    p2.init();
    // print 2 instances of Point
    p1.print();   cout << endl;
    p2.print();   cout << endl;
    // modify each instance
    p1.modify(1, 2);
    p2.modify(3, 4);
    // you can see the change in p1 and p2
    p1.print();   cout << endl;
    p2.print();   cout << endl;
    return 0;
}
```

---

### Design member functions  (discuss on next lecture)

Guidelines:

* each member function should show it's accessibility explicitly
  * '_' is used to indicate a member function used internally (`private`)
  * all other functions are public
* essential member functions should be defined in the class
  * getter & setter
  * constructor & destructor
  * `operator=` (disscuss on later lecture)
* etc.

## `public`, `private`, `protected` member

To identify the accessibility of a member, we use `public`, `private`, and `protected` keywords.

* `public` data members is accessible by other classes.
* `private` data members is accessible only by its owner.
* `protected` data members is accessible by other inherited classes and its owner. (discuss in lecture 8)
---
### `public` member

Same as `struct`.

```c++
class Point // the class name
{
public: 

    // public data members
    // we can access them directly by use `.` operator
    int m_x;
    int m_y;
};

int main()
{
    Point p1;
    // init p1
    p1.m_x = 1;
    p1.m_y = 2;
    // print p1
    cout << "(" << p1.m_x << ", " << p1.m_y << ")" << endl;
    return 0;
}
```

---
### `private` member

Different from `struct`, `private` member is not accessible by other classes or functions.

``` c++
#include <iostream>

using namespace std;

// Point_2D class
class Point_2D
{
private: // private data members
    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;

public: // public member functions
    // iniialize the x and y coordinate
    void init();
    // print the x and y coordinate
    void print();
    // modify the x and y coordinate
    void modify(const int &arg_x, const int &arg_y);
    // modify the point by another point
    void modify(const Point_2D &arg_point);
};
```
---
``` c++
// Point_2D_2 class
class Point_2D_2
{
private: // private data members
    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;

public: // public member functions
    // iniialize the x and y coordinate
    void init();
    // print the x and y coordinate
    void print();
    // modify the x and y coordinate
    void modify(const int &arg_x, const int &arg_y);
    // modify the point by another point
    // NOTE: compile error
    void modify(const Point_2D &arg_point);
};
```
---
```c++
// function definition

// Point_2D class
// initialize the x and y coordinate
void Point_2D::init()
{
    m_x = 0;
    m_y = 0;
}
// print the x and y coordinate
void Point_2D::print()
{
    cout << "(" << m_x << ", " << m_y << ")";
}
// modify the x and y coordinate
void Point_2D::modify(const int &arg_x, const int &arg_y)
{
    m_x = arg_x;
    m_y = arg_y;
}
// modify the point by another point
void Point_2D::modify(const Point_2D &arg_point)
{
    m_x = arg_point.m_x;
    m_y = arg_point.m_y;
}
```
---
``` c++
// Point_2D_2 class
// initialize the x and y coordinate
void Point_2D_2::init()
{
    m_x = 0;
    m_y = 0;
}
// print the x and y coordinate
void Point_2D_2::print()
{
    cout << "(" << m_x << ", " << m_y << ")";
}
// modify the x and y coordinate
void Point_2D_2::modify(const int &arg_x, const int &arg_y)
{
    m_x = arg_x;
    m_y = arg_y;
}
// modify the point by another point
void Point_2D_2::modify(const Point_2D &arg_point)
{
    // compile error, error: 'm_x' is a private member of 'Point_2D'
    // need to use getter (discuss on the next lecture)
    m_x = arg_point.m_x;
    m_y = arg_point.m_y;
}
```
---
``` c++
// main function

int main()
{
    Point_2D point1;
    Point_2D_2 point2;

    point1.init();
    point2.init();

    point1.print();    cout << endl;
    point2.print();    cout << endl;

    point1.modify(1, 2);
    point2.modify(point1);

    point1.print();    cout << endl;
    point2.print();    cout << endl;

    return 0;
}
```

## `this` data member

To access the data members of current class explicitly, we use `this` keyword.

Usage: (inside the class definition)
``` c++
void Point_2D::init()
{
    // access the data members of current class
    this->m_x = 0;
    this->m_y = 0;
}
```
---
Example: `Point_2D` (use `this`)

```c++
#include <iostream>

using namespace std;

class Point_2D
{
private: // private data members
    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;
public: // public member functions
    // iniialize the x and y coordinate
    void init();
    // print the x and y coordinate
    void print();
    // modify the x and y coordinate
    void modify(const int &arg_x, const int &arg_y);
};
```
---
``` c++
// function definition

// initialize the x and y coordinate
void Point_2D::init()
{
    // initialize the x coordinate
    // NOTE: this is a pointer to the current object
    //       so we can use this-> to access the private data member
    this->m_x = 0;
    // initialize the y coordinate
    // NOTE: this-> is equivalent to (*this)
    (*this).m_y = 0;
}
// print the x and y coordinate
void Point_2D::print()
{
    cout << "(" << this->m_x << ", " << this->m_y << ")";
}
// modify the x and y coordinate
void Point_2D::modify(const int &arg_x, const int &arg_y)
{
    this->m_x = arg_x;
    this->m_y = arg_y;
}
```
---
``` c++
// main function

int main()
{
    Point_2D p1, p2;
    // init 2 instances of Point
    p1.init();    p2.init();
    // print 2 instances of Point
    p1.print();   cout << endl;
    p2.print();   cout << endl;
    // modify each instance
    p1.modify(1, 2);
    p2.modify(3, 4);
    // you can see the change in p1 and p2
    p1.print();   cout << endl;
    p2.print();   cout << endl;
    return 0;
}
```

## Variable scope in a class

Reference: [Scope resolution operator in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/scope-resolution-operator-in-c/)

* Which variables are accessible in a member function?
  * data members
  * local variables
  * global variables (Ref: [Lecture 11: Function & Reference (2)](https://stevenokm.github.io/i2p-nthu-math/i2p1/function/lecture_11.html#variable-scope--lifetime))
  * function arguments
---
Example:

``` c++
#include <iostream>
using namespace std;

int a = 1;

class A
{
public:
    int a;
    void f()
    {
        a = a; // how to access global variable a?
    }
};

int main()
{
    A a;
    a.f();
    return 0;
}
```
---
### `::` scope resolution operator

Usage: Global variable

``` c++
// C++ program to show that we can access a global variable
// using scope resolution operator :: when there is a local
// variable with same name
#include <iostream>
using namespace std;

int x; // Global x

int main()
{
    int x = 10; // Local x
    cout << "Value of global x is " << ::x;
    cout << "\nValue of local x is " << x;
    return 0;
}
```
---
Usage: Function name
``` c++
// C++ program to show that scope resolution operator :: is used
// to define a function outside a class
#include <iostream>
using namespace std;

class A
{
public:
    // Only declaration
    void fun();
};

// Definition outside class using ::
void A::fun()
{
    cout << "fun() called";
}

int main()
{
    A a;
    a.fun();
    return 0;
}
```
---
Example: 
``` c++
#include <iostream>
using namespace std;

int global_a = 1;
// a = 1;

class A
{
public:
    int local_a;
    // int a;
    void f()
    {
        local_a = ::global_a;
        // a = ::a;
    }
};

int main()
{
    A a;
    a.f();
    return 0;
}
```
---
### Case: a class in a class
``` c++
// Use of scope resolution class inside another class.
#include <iostream>
using namespace std;

class outside
{
public:
    int x;
    class inside
    {
    public:
        int x;
        static int y; // we talk it later
        int foo();
    };
};
int outside::inside::y = 5;

int main()
{
    outside A;
    outside::inside B;
}
```

## `static` data member

Reference: [Static Keyword in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/static-keyword-cpp/)

To maintain the status of a class or save memory usage, we use `static` data member.

Note: the value of a `static` variable is shared during the entire execution of the program and will initialize only once.

---
``` c++
// C++ program to demonstrate
// the use of static Static
// variables in a Function
#include <iostream>
#include <string>
using namespace std;

void demo()
{
    // static variable
    static int count = 0;
    cout << count << " ";

    // value is updated and
    // will be carried to next
    // function calls
    count++;
}

int main()
{
    for (int i = 0; i < 5; i++)
        demo();
    return 0;
}
```

---
### Example: static data member

Note: `static` data member will share the same value for all instances of the class.

``` c++
// C++ program to demonstrate static
// variables inside a class

#include <iostream>
using namespace std;

class GfG
{
public:
    static int i;

    GfG(){
        // Default constructor
        // we will discuss this in the next lecture
    };
};

// static data member should be initialized in global scope
int GfG::i = 1;
  
int main()
{
    GfG obj;
    // prints value of i
    cout << obj.i; 
}
```
---
### Initialize `static` data member is important

Without initializing `static` data member, the compiler will not know the value of `static` data member.

``` c++
// C++ program to demonstrate static
// variables inside a class

#include <iostream>
using namespace std;

class GfG
{
public:
    static int i;
};

int main()
{
    GfG obj;
    // prints value of i
    cout << obj.i << endl;
}
```

## Example 1: Triangle (again) [[Source](./lecture3_ex1.html)]

A Triangle:
* contains 3 points
* on the 2D plane
* need to be able to calculate the area
* need to be initialized, printed, and modified

## Example 2: Vector (again) [[Source](./lecture3_ex2.html)]

A Vector:
* contains 3 factors of the 3 basis $\bold{i}$, $\bold{j}$, $\bold{k}$
* need to be able to calculate the length
* need to be able to calculate the dot, cross product
* need to be initialized, printed, and modified

## Example 3: Integer Calculator [[Source](./lecture3_ex3.html)]

A Integer Calculator:
* contains current value, input value, and operation
* neet to be able to set the input value
* neet to be able to set the operation
* neet to be able to calculate the result
* neet to be able to clear the input value
* need to be initialized
* need to be able to get all information

## Pratices

* Pratice 1: 參考 `Triangle` class, 如果四邊形、多邊形要如何設計要儲存的變數？
* Pratice 2: 參考 `Vector` class, 如果需要支援多維度的座標系上、或是轉換 basis 為其他 vector 要如何設計儲存的變數？
* Pratice 3: 參考 `Integer Calculator` class, 如果需要支援 `M+` 運算要如何設計相關變數？