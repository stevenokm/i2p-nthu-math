<!--
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
-->

# Class Design 101

> Slides version: [lecture2_slides.html](./lecture2_slides.html)
> Website version: [lecture2.html](./lecture2.html)

* Recap: Hello Class
* Class Definition
* Class Instance
* Class Usage/Method
* Example: Triangle
* Example: Vector

## Recap: Hello Class

``` c++
class Point
{
public:
    // Member variables
    int x;
    int y;

    // Member functions
    void init();
    void print();
    void modify();
};

int main()                          
{                                   
    Point p1;                       
    p1.init();                      
    p1.print();                     
    p1.modify();                    
    p1.print();                     

    return 0;                       
}
```

## Class Definition

Syntax:

```c++
class Point // the class name
{
public: // public member variables and functions
        // Note: there is also private: and protected: sections.
        // we will discuss them in following lectures

    // Member variables
    // as like as the data in a 'struct', you can have multiple 
    // variables in different types
    int x;
    int y;
};
```

## Class Instance

``` c++
int main()      
{               
    Point p1, p2;   
    // init 2 instances of Point
    p1.x = 0; p1.y = 0;
    p2.x = 0; p2.y = 0;

    // print 2 instances of Point
    cout << "p1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "p2: (" << p2.x << ", " << p2.y << ")" << endl;

    // modify each instance
    // p1 and p2 are the same class, but they are different instances
    // so they can have different values
    p1.x = 1; p1.y = 2;
    p2.x = 3; p2.y = 4;
    
    // you can see the change in p1 and p2
    cout << "p1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "p2: (" << p2.x << ", " << p2.y << ")" << endl;

    return 0;   
}               
```

---

``` console
$ ./a.out
p1: (0, 0)
p2: (0, 0)
p1: (1, 2)
p2: (3, 4)
```

## Class Method/Usage

### Class as a argument

As like as struct, you can use a class instance as a argument to a function.

``` c++
void init_point(Point &p)
{
    p.x = 0;
    p.y = 0;
}
void print_point(const Point &p)
{
    cout << "(" << p.x << ", " << p.y << ")";
}
void modify_point(Point &p, const int& arg_x, const int& arg_y)
{
    p.x = arg_x;
    p.y = arg_y;
}
```

---

``` c++
int main()      
{               
    Point p1, p2;   
    // init 2 instances of Point
    init_point(p1);
    init_point(p2);

    // print 2 instances of Point
    cout << "p1: "; print_point(p1); cout << endl;
    cout << "p2: "; print_point(p2); cout << endl;

    // modify each instance
    modify_point(p1, 1, 2);
    modify_point(p2, 3, 4);
    
    // you can see the change in p1 and p2
    cout << "p1: "; print_point(p1); cout << endl;
    cout << "p2: "; print_point(p2); cout << endl;

    return 0;   
}   
```

---

### Use class method

Instead of using extra functions, you can use the member functions to manipulate the data.

---

```c++
class Point // the class name
{
public: // public member variables and functions
        // Note: there is also private: and protected: sections.
        // we will discuss them in following lectures

    // Member variables
    // as like as the data in a 'struct', you can have multiple 
    // variables in different types
    int x;
    int y;

    // Member functions
    // different from a 'struct', you can have multiple functions
    // in a class that related to the class
    void init() { x = 0; y = 0; }
    void print() { cout << "(" << x << ", " << y << ")"; }
    void modify(const int& arg_x, const int& arg_y) { x = arg_x; y = arg_y; }
};
```

---

``` c++
int main()      
{               
    Point p1, p2;   
    // init 2 instances of Point
    p1.init(); p2.init();

    // print 2 instances of Point
    p1.print(); p2.print();

    // modify each instance
    p1.modify(1, 2); p2.modify(3, 4); 

    // you can see the change in p1 and p2
    p1.print(); p2.print();

    return 0;   
}  
```

## Example: Triangle [[Source](./lecture2_ex1.html)]

``` c++
#include <iostream>

using namespace std;

class Triangle
{
public:
    double x1, y1, x2, y2, x3, y3;

    void init();
    void print();
    void modify(double, double, double, double, double, double);
    double area();
};
```
---
``` c++
void Triangle::init()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    x3 = 0;
    y3 = 0;
}

void Triangle::print()
{
    cout << "Triangle: " << endl;
    cout << "(" << x1 << ", " << y1 << ")" << endl;
    cout << "(" << x2 << ", " << y2 << ")" << endl;
    cout << "(" << x3 << ", " << y3 << ")" << endl;
}
```
---
```c++
void Triangle::modify(double arg_x1, double arg_y1, double arg_x2,
                      double arg_y2, double arg_x3, double arg_y3)
{
    x1 = arg_x1;
    y1 = arg_y1;
    x2 = arg_x2;
    y2 = arg_y2;
    x3 = arg_x3;
    y3 = arg_y3;
}

double Triangle::area()
{
    return (x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2) / 2;
}
```
---
```c++
int main()
{
    Triangle t;
    t.init();
    t.print();
    t.modify(1, 1, 2, 2, 0, 3);
    t.print();
    cout << "Area: " << t.area() << endl;
    return 0;
}
```
---

Output:

```console
$ ./a.out
Triangle: 
(0, 0)
(0, 0)
(0, 0)
Triangle: 
(1, 1)
(2, 2)
(0, 3)
Area: 1.5
```

## Example: Vector [[Source](./lecture2_ex2.html)]

``` c++
#include <iostream>

using namespace std;

class Vector
{
public:
    int x, y, z;

    void init();
    void print();
    void modify(int, int, int);
    int dot(const Vector &);
    Vector cross(const Vector &);
};
```
---
``` c++
void Vector::init()
{
    x = 0;
    y = 0;
    z = 0;
}

void Vector::print()
{
    cout << "Vector: "
         << "(" << x << ", " << y << ", " << z << ")";
}

void Vector::modify(int arg_x, int arg_y, int arg_z)
{
    x = arg_x;
    y = arg_y;
    z = arg_z;
}
```
---
``` c++
int Vector::dot(const Vector &arg_v)
{
    return x * arg_v.x + y * arg_v.y + z * arg_v.z;
}

Vector Vector::cross(const Vector &arg_v)
{
    Vector v;
    v.x = y * arg_v.z - z * arg_v.y;
    v.y = z * arg_v.x - x * arg_v.z;
    v.z = x * arg_v.y - y * arg_v.x;
    return v;
}
```
---
``` c++
int main()
{
    Vector v1, v2;
    v1.init();
    v1.print();
    cout << endl;
    v1.modify(1, 1, 1);
    v1.print();
    cout << endl;
    cout << endl;

    v2.init();
    v2.print();
    cout << endl;
    cout << endl;
```
---
``` c++
    v2.modify(2, 3, 4);
    cout << "v1: ";
    v1.print();
    cout << endl;
    cout << "v2: ";
    v2.print();
    cout << endl;
    cout << "Dot: " << v1.dot(v2) << endl;
    cout << endl;
```
---
``` c++
    v2.modify(5, 6, 7);
    Vector v3 = v1.cross(v2);
    cout << "v1: ";
    v1.print();
    cout << endl;
    cout << "v2: ";
    v2.print();
    cout << endl;
    cout << "Cross: ";
    v3.print();
    cout << endl;
    cout << endl;

    return 0;
}
```
---

Output:

``` console
Vector: (0, 0, 0)
Vector: (1, 1, 1)

Vector: (0, 0, 0)

v1: Vector: (1, 1, 1)
v2: Vector: (2, 3, 4)
Dot: 9

v1: Vector: (1, 1, 1)
v2: Vector: (5, 6, 7)
Cross: Vector: (1, -2, 1)
```

## Pratices

* Pratice 1: 參考 `Triangle` class, 如果四邊形、多邊形要如何設計？
* Pratice 2: 參考 `Vector` class, 如果需要紀錄多維度的座標系上、或是轉換 eigen vector 為其他 vector 要如何設計？
