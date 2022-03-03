<!--
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
-->

# Sturcture and Class
> Slides version: [lecture1_slides.html](./lecture1_slides.html)
> Website version: [lecture1.html](./lecture1.html)

* Recap: Structure
* What is a *Class*?
* Difference between Class and Structure
* VSCode Tutorial
* Lab 1: Hello Class

## Recap: Structure

Example: [Structures in C - GeeksforGeeks](https://www.geeksforgeeks.org/structures-c/)

``` c++
// A variable declaration with structure declaration.
struct Point
{
    int x, y;
} p1; // The variable p1 is declared with 'Point'

// A variable declaration like basic data types
struct Point
{
    int x, y;
};

int main()
{
    struct Point p1; // The variable p1 is declared like a normal variable
}
```

## How to Initialize/Modify a Structure

``` c++
#include <iostream>

using namespace std;

// A variable declaration like basic data types
struct Point
{
    int x, y;
};

void init_point(struct Point &p);
void print_point(const struct Point &p);
void modify_point(struct Point &p);
```

---

``` c++
int main()
{
    struct Point p1; // The variable p1 is declared like a normal variable

    init_point(p1);

    print_point(p1);

    modify_point(p1);

    print_point(p1);

    return 0;
}
```

---

``` c++
void init_point(struct Point &p)
{
    p.x = 10;
    p.y = 20;
}

void print_point(const struct Point &p)
{
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
}

void modify_point(struct Point &p)
{
    p.x = 100;
    p.y = 200;
}
```

Output (in console):

``` console
$ ./a.out
(10, 20)
(100, 200)
```

## What is a *Class*?

> A user-defined datatype which groups together related pieces of information. 

-- [Introduction to C++ | Electrical Engineering and Computer Science | MIT OpenCourseWare](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-096-introduction-to-c-january-iap-2011/)

### Example

* Point on a 2D plane
  * x-coordinate
  * y-coordinate

## Definition of Class

``` c++
class Point
{
public:
    // Data members
    int x;
    int y;

    // Member functions
    void init();
    void print();
    void modify();
};
```

## Difference between Class and Structure

### Definition

``` c++
class Point                         struct Point
{                                   {
public:
    // Data members                 // Data members
    int x;                              int x;
    int y;                              int y;

    // Member functions                 // No Member functions
    void init();
    void print();
    void modify();
};                                  };
// Class usuallay don't use         // Structure usuallay use
// functions to manipulate          // functions to manipulate
// the data members                 // the data members
                                    void init_point(struct Point &p);
                                    void print_point(const struct Point &p);
                                    void modify_point(struct Point &p);
```

---

### Usage

``` c++
int main()                          int main()  
{                                   {
    Point p1;                           struct Point p1;

    p1.init();                          init_point(p1);

    p1.print();                         print_point(p1);

    p1.modify();                        modify_point(p1);

    p1.print();                         print_point(p1);

    return 0;                           return 0;
}                                   }
```

# [VSCode Tutorial](../vscode_tutorial/lab_1_vscode_315.html)

# Lab 1: [Hello Class](./lab1.html)
