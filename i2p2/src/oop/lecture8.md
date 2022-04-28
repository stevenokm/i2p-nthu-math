<!---
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
--->

# OOP: Inheritance (1)

> Slides version: [lecture8_slides.html](./lecture8_slides.html)
> Website version: [lecture8.html](./lecture8.html)

- What is Inheritance? and Why do we need it?
  - Example: Bus, Car, and Truck.
* Syntax
* Inheritance Mode
  - Public, Protected, Private
    - Example
---
* Inheritance Type
  - Single
  - Multiple
  - Multi-level
  - Hierarchical (discuss in the next lecture)
  - Hybrid (Virtual) Inheritance (discuss in the next lecture)
  - Multipath inheritance (discuss in the next lecture)
* Example 1: Integer & Real
* Example 2: Complex Number
* Example 3: Integer & Real & Complex Number
* Pratices

## What is Inheritance? and Why do we need it?

Ref: [Inheritance in C++](https://www.geeksforgeeks.org/inheritance-in-c/)

> The capability of a class to derive properties and characteristics from another class is called **Inheritance**.

### Example: Bus, Car, and Truck.

![](./img/inheritance.png)

---

Because bus, car and truck are all vehicles, and they all have the same member functions, we can use inheritance to reduce the amount of code we need to write. For example, `class Vehicle`:

![](./img/inheritance2.png)

## Syntax

``` c++
class subclass_name : access_mode base_class_name
{
  // body of subclass
};
```
---
### Example: Bus, Car, and Truck.

``` c++
#include <iostream>

using namespace std;

class Vehicle
{
public:
    void run()
    {
        std::cout << "Vehicle is running" << std::endl;
    }
};
class Bus : public Vehicle
{
};
class Car : public Vehicle
{
};
```
---
``` c++
class Truck : public Vehicle
{
};
int main()
{
    Bus bus;
    Car car;
    Truck truck;
    bus.run();
    car.run();
    truck.run();
    return 0;
}
```
Output:

```console
$ ./a.out
Vehicle is running
Vehicle is running
Vehicle is running
```

---
### Example: Parent & Child

``` c++
// C++ program to demonstrate implementation
// of Inheritance

#include <bits/stdc++.h>
using namespace std;

// Base class
class Parent
{
public:
    int id_p;
};

// Sub class inheriting from Base Class(Parent)
class Child : public Parent
{
public:
    int id_c;
};
```
---
``` c++
// main function
int main()
{
    Child obj1;

    // An object of class child has all data members
    // and member functions of class parent
    obj1.id_c = 7;
    obj1.id_p = 91;
    cout << "Child id is: " << obj1.id_c << '\n';
    cout << "Parent id is: " << obj1.id_p << '\n';

    return 0;
}
```
Output:

```console
$ ./a.out
Child id is: 7
Parent id is: 91
```

## Inheritance Mode

| Class Member Type |      Type of       |    Inheritence     |                    |
| :---------------: | :----------------: | :----------------: | :----------------: |
|                   |       Public       |     Protected      |      Private       |
|      Public       |     **Public**     |   **Protected**    |    **Private**     |
|     Protected     |   **Protected**    |   **Protected**    |    **Private**     |
|      Private      | **Not accessible** | **Not accessible** | **Not accessible** |

---
### Example: Inheritance Mode

``` c++
// C++ Implementation to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object.
class A
{
public:
    int x;

protected:
    int y;

private:
    int z;
};
```
---
``` c++
class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};
```

## Inheritance Type
  - Single
  - Multiple
  - Multi-level
  - Hierarchical (discuss in the next lecture)
  - Hybrid (Virtual) Inheritance (discuss in the next lecture)
  - Multipath inheritance (discuss in the next lecture)

---
### Single Inheritance

![bg right fit](img/single-inheritance.png)

Syntax:

``` c++
class subclass_name : access_mode base_class
{
    // body of subclass
};
```

---
#### Example: Single Inheritance

![bg right fit](img/single-inheritance.png)

``` c++
// C++ program to explain
// Single inheritance
#include <iostream>
using namespace std;

// base class
class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a Vehicle\n";
    }
};

// sub class derived from a single base classes
class Car : public Vehicle
{
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base classes
    Car obj;
    return 0;
}
```

---
### Multiple Inheritance

![bg right fit](img/multiple-inheritance.png)

Syntax:

``` c++
class subclass_name : access_mode base_class1,
                      access_mode base_class2,
                      ....
{
    // body of subclass
};
```

---
#### Example: Multiple Inheritance

![bg right fit](img/multiple-inheritance.png)

``` c++
// C++ program to explain
// multiple inheritance
#include <iostream>
using namespace std;

// first base class
class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a Vehicle\n";
    }
};

// second base class
class FourWheeler
{
public:
    FourWheeler()
    {
        cout << "This is a 4 wheeler Vehicle\n";
    }
};

// sub class derived from two base classes
class Car : public Vehicle, public FourWheeler
{
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base classes.
    Car obj;
    return 0;
}
```

---
### Multi-level Inheritance

![bg right fit](img/multilevel-inheritance.png)

Syntax:

``` c++
class base_class_1 : access_mode base_class_2
{
    // body of base class 1
};
class subclass_name : access_mode base_class_1
{
    // body of subclass
};
```

---
#### Example: Multi-level Inheritance

![bg right fit](img/multilevel-inheritance.png)

``` c++
// C++ program to implement
// Multilevel Inheritance
#include <iostream>
using namespace std;

// base class
class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a Vehicle\n";
    }
};

// first sub_class derived from class vehicle
class fourWheeler : public Vehicle
{
public:
    fourWheeler()
    {
        cout << "Objects with 4 wheels are vehicles\n";
    }
};
// sub class derived from the derived base class fourWheeler
class Car : public fourWheeler
{
public:
    Car()
    {
        cout << "Car has 4 Wheels\n";
    }
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base classes.
    Car obj;
    return 0;
}
```

## Example 1: Integer & Real [[Source](./lecture8_ex1.html)]

## Example 2: Complex Number [[Source](./lecture8_ex2.html)]

## Example 3: Integer & Real & Complex Number [[Source](./lecture8_ex3.html)]

## Pratices

- Design a class hierarchy for Fruit. Contains:
  - Grape
  - Apple
  - Orange
- Design a class hierarchy for Quadrilateral. Contains:
  - Square
  - Rectangle
  - Rhombus
  - Parallelogram