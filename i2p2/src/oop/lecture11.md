<!---
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
--->

# OOP: Polymorphism (1)

> Slides version: [lecture11_slides.html](./lecture11_slides.html)
> Website version: [lecture11.html](./lecture11.html)

- What is Polymorphism? and Why do we need it?
  - Example: Bus, Car, and Truck.
* Polymorphism Types
  - Compile time
  - Run time
* Virtual Function
  - Syntax: `virtual` member function & object pointer
  - Example:
---
* Example 1: Integer & Real
* Example 2: Complex Number
* Example 3: Integer & Real & Complex Number
* Pratices

## What is Polymorphism? and Why do we need it?

> The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. 
> A real-life example of polymorphism, a person at the same time can have different characteristics. Like a man at the same time is a father, a husband, an employee. 
> So the same person posses different behavior in different situations. This is called polymorphism.

---
### Example: Bus, Car, and Truck

- A Bus:
  - has 4 wheels
  - has 20 seats
  - has 2 doors
  - has 20 windows
- A Car:
  - has 4 wheels
  - has 4 seats
  - has 4 doors
  - has 4 windows
---
- A Truck:
  - has 6 wheels
  - has 2 seats
  - has 2 doors
  - has 2 windows

---
#### function overloading

``` c++
#include <iostream>

using namespace std;

class Vehicle
{
public:
    void wheels() {}
    void seats() {}
    void doors() {}
    void windows() {}
};
```
---
``` c++
class Bus : public Vehicle
{
public:
    void wheels()
    {
        cout << "Wheels: 4" << endl;
    }
    void seats()
    {
        cout << "Seats: 20" << endl;
    }
    void doors()
    {
        cout << "Doors: 2" << endl;
    }
    void windows()
    {
        cout << "Windows: 20" << endl;
    }
};
```
---
``` c++
class Car : public Vehicle
{
public:
    void wheels()
    {
        cout << "Wheels: 4" << endl;
    }
    void seats()
    {
        cout << "Seats: 4" << endl;
    }
    void doors()
    {
        cout << "Doors: 4" << endl;
    }
    void windows()
    {
        cout << "Windows: 4" << endl;
    }
};
```
---
``` c++
class Truck : public Vehicle
{
public:
    void wheels()
    {
        cout << "Wheels: 6" << endl;
    }
    void seats()
    {
        cout << "Seats: 2" << endl;
    }
    void doors()
    {
        cout << "Doors: 2" << endl;
    }
    void windows()
    {
        cout << "Windows: 2" << endl;
    }
};
```
---
``` c++
int main()
{
    Bus b;
    Car c;
    Truck t;

    b.wheels();
    b.seats();
    b.doors();
    b.windows();

    c.wheels();
    c.seats();
    c.doors();
    c.windows();

    t.wheels();
    t.seats();
    t.doors();
    t.windows();
}
```
---
Output:

```console
$ ./a.out
Wheels: 4
Seats: 20
Doors: 2
Windows: 20
Wheels: 4
Seats: 4
Doors: 4
Windows: 4
Wheels: 6
Seats: 2
Doors: 2
Windows: 2
```

---
#### `virtual` member function

``` c++
#include <iostream>

using namespace std;

class Vehicle
{
public:
    virtual void wheels() {}
    virtual void seats() {}
    virtual void doors() {}
    virtual void windows() {}
};
```
---
``` c++
class Bus : public Vehicle
{
public:
    void wheels()
    {
        cout << "Wheels: 4" << endl;
    }
    void seats()
    {
        cout << "Seats: 20" << endl;
    }
    void doors()
    {
        cout << "Doors: 2" << endl;
    }
    void windows()
    {
        cout << "Windows: 20" << endl;
    }
};
```
---
``` c++
class Car : public Vehicle
{
public:
    void wheels()
    {
        cout << "Wheels: 4" << endl;
    }
    void seats()
    {
        cout << "Seats: 4" << endl;
    }
    void doors()
    {
        cout << "Doors: 4" << endl;
    }
    void windows()
    {
        cout << "Windows: 4" << endl;
    }
};
```
---
``` c++
class Truck : public Vehicle
{
public:
    void wheels()
    {
        cout << "Wheels: 6" << endl;
    }
    void seats()
    {
        cout << "Seats: 2" << endl;
    }
    void doors()
    {
        cout << "Doors: 2" << endl;
    }
    void windows()
    {
        cout << "Windows: 2" << endl;
    }
};
```
---
``` c++
int main()
{
    Vehicle *v[3];    // array of pointers to Vehicle
                      // used for polymorphism
    v[0] = new Bus;   // dynamically allocate Bus
    v[1] = new Car;   // dynamically allocate Car
    v[2] = new Truck; // dynamically allocate Truck

    for (int i = 0; i < 3; i++)
    {
        v[i]->wheels();
        v[i]->seats();
        v[i]->doors();
        v[i]->windows();
    }
    
    for (int i = 0; i < 3; i++)
    {
        delete v[i];
    }
}
```
---
Output:

```console
$ ./a.out
Wheels: 4
Seats: 20
Doors: 2
Windows: 20
Wheels: 4
Seats: 4
Doors: 4
Windows: 4
Wheels: 6
Seats: 2
Doors: 2
Windows: 2
```

## Polymorphism Types

Ref: https://www.geeksforgeeks.org/polymorphism-in-c/

- In C++ polymorphism is mainly divided into two types:
  - Compile time Polymorphism
  - Runtime Polymorphism

![bg right fit](img/Polymorphism-in-CPP.png)

---
### Compile time Polymorphism (Function/Operator Overloading)

``` c++
// C++ program for function overloading
#include <iostream>

using namespace std;
class Geeks
{
public:
    // function with 1 int parameter
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    }

    // function with same name but 1 double parameter
    void func(double x)
    {
        cout << "value of x is " << x << endl;
    }

    // function with same name and 2 int parameters
    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};
```
---
``` c++
int main()
{

    Geeks obj1;

    // Which function is called will depend on the parameters passed
    // The first 'func' is called
    obj1.func(7);

    // The second 'func' is called
    obj1.func(9.132);

    // The third 'func' is called
    obj1.func(85, 64);
    return 0;
}
```

---
### Runtime Polymorphism (Virtual Function with object pointer)

``` c++
// C++ program for function overriding

#include <iostream>
using namespace std;

class base
{
public:
    virtual void print()
    {
        cout << "print base class" << endl;
    }

    void show()
    {
        cout << "show base class" << endl;
    }
};
```
---
``` c++
class derived : public base
{
public:
    void print() // print () is already virtual function in derived class,
                 // we could also declared as virtual void print () explicitly
    {
        cout << "print derived class" << endl;
    }

    void show()
    {
        cout << "show derived class" << endl;
    }
};
```
---
``` c++
// main function
int main()
{
    base *bptr;
    derived d;
    bptr = &d;

    // virtual function, binded at runtime (Runtime polymorphism)
    bptr->print();

    // Non-virtual function, binded at compile time
    bptr->show();

    return 0;
}
```

## Virtual Function

Ref: https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-c-set-1-introduction/

> A **virtual** function is a *member* function which is declared in the *base* class using the keyword `virtual` and is re-defined (Overriden) by the *derived* class.

---
### Syntax: `virtual` member function & object pointer

``` c++
class base
{
public:
    virtual void a() {} // virtual function
};
class derived : public base
{
public:
    void a() {} // non-virtual function, overridden by derived class
};
```
---
``` c++
int main()
{
    base *b_ptr;
    derived d;
    b_ptr = &d; // object pointer of derived class

    // virtual function, binded at runtime (Runtime polymorphism)
    b_ptr->a();

    return 0;
}
```

---
### Example 1:

``` c++
// C++ program for function overriding

#include <iostream>
using namespace std;

class base
{
public:
    virtual void print()
    {
        cout << "print base class" << endl;
    }

    void show()
    {
        cout << "show base class" << endl;
    }
};
```
---
``` c++
class derived : public base
{
public:
    void print() // print () is already virtual function in derived class,
                 // we could also declared as virtual void print () explicitly
    {
        cout << "print derived class" << endl;
    }

    void show()
    {
        cout << "show derived class" << endl;
    }
};
```
---
``` c++
// main function
int main()
{
    base *bptr;
    derived d;
    bptr = &d;

    // virtual function, binded at runtime (Runtime polymorphism)
    bptr->print();

    // Non-virtual function, binded at compile time
    bptr->show();

    return 0;
}
```

---
### Example 2:

``` c++
class Employee
{
public:
    virtual void raiseSalary()
    {
        /* common raise salary code */
    }

    virtual void promote()
    { 
        /* common promote code */
    }
};
```
---
``` c++
class Manager : public Employee
{
    virtual void raiseSalary()
    {
        /* Manager specific raise salary code, may contain
        increment of manager specific incentives */
    }

    virtual void promote()
    {
        /* Manager specific promote */
    }
};

// Similarly, there may be other types of employees
```
---
``` c++
// We need a very simple function
// to increment the salary of all employees
// Note that emp[] is an array of pointers
// and actual pointed objects can
// be any type of employees.
// This function should ideally
// be in a class like Organization,
// we have made it global to keep things simple
void globalRaiseSalary(Employee *emp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // Polymorphic Call: Calls raiseSalary()
        // according to the actual object, not
        // according to the type of pointer
        emp[i]->raiseSalary();
    }
}
```

## Example 1: Integer & Real [[Source](./lecture11_ex1.html)]

## Example 2: Complex Number [[Source](./lecture11_ex2.html)]

## Example 3: Integer & Real & Complex Number [[Source](./lecture11_ex3.html)]

## Pratices

- Design a class hierarchy for Fruit.
  - Contains: Grape, Apple, Orange
  - Implement with based class `Fruit`
  - Use `virtual` function to provide universal `print()`, `color()` functions

- Design a class hierarchy for Quadrilateral. 
  - Contains: Square, Rectangle, Rhombus, Parallelogram
  - Implement with based class `Quadrilateral`
  - Use `virtual` function to provide universal `print()`, `area()` functions