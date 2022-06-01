<!---
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
--->

# Advanced I/O & Exception Handling

> Slides version: [lecture15_slides.html](./lecture15_slides.html)
> Website version: [lecture15.html](./lecture15.html)

- Detail in `iostream`, `fstream` & `stringstream`
  - Stream Operator & Manipulator
  - Stream Status & Error Handling
* Exception & Exception Handling
  - What is an exception?
  - How to handle exceptions?
  - How many types of exceptions?
    - `std::exception` class
  - `iostream`, `fstream` & exception handling
---
* Example: Exception Handling, `iostream` & `fstream` Error Handling
* Practices

## Stream Operator & Manipulator

### `<<` & `>>` stream operator

Discussed in [lecture14](./lecture14.html)

### Stream Manipulator 

Ref: [Manipulators in C++ with Examples](https://www.geeksforgeeks.org/manipulators-in-c-with-examples/)

There are two types of manipulators in C++:
1. Manipulators without arguments:
   - endl (output `\n` and flush), ws (consume whitespace), ends (output `\0`), flush (flush output buffer to terminal)
2. Manipulators with Arguments: Some of the manipulators are used with the argument like `setw(20)`, `setfill(*)`, and many more.

---
- In `<ios>`:
  - `(no)boolalpha`, `(no)uppercase`, `(no)showbase`, `(no)showpos`, `(no)showpoint`, `(no)skipws`, `(no)unitbuf`, `internal`, `left`, `right`, `hex`, `dec`, `oct`, `fixed`, `scientific`
- In `<iomanip>`:
  - `setw(val)`, `setfill(c)`, `setprecision(val)`, `setbase(val)`, `setiosflags(flag)`, `resetiosflags(m)`

---
#### `(no)boolalpha`

Ref: [std::boolalpha, std::noboolalpha](https://en.cppreference.com/w/cpp/io/manip/boolalpha)

```cpp
#include <sstream>
#include <iostream>
int main()
{
    // boolalpha output
    std::cout << std::boolalpha 
              << "boolalpha true: " << true << '\n'
              << "boolalpha false: " << false << '\n';
    std::cout << std::noboolalpha 
              << "noboolalpha true: " << true << '\n'
              << "noboolalpha false: " << false << '\n';
    // boolalpha parse
    bool b1, b2;
    std::istringstream is("true false");
    is >> std::boolalpha >> b1 >> b2;
    std::cout << '\"' << is.str() << "\" parsed as " << b1 << ' ' << b2 << '\n';
}
```

---
#### `(no)uppercase`, `(no)showbase`

Ref: [std::showbase, std::noshowbase](https://en.cppreference.com/w/cpp/io/manip/showbase), [std::uppercase, std::nouppercase](https://en.cppreference.com/w/cpp/io/manip/uppercase)

```cpp
#include <sstream>
#include <locale>
#include <iostream>
#include <iomanip>
int main()
{
    // showbase affects the output of octals and hexadecimals
    std::cout << std::hex
              << "showbase: " << std::showbase << 42 << '\n'
              << "noshowbase: " << std::noshowbase << 42 << '\n';
    // uppercase affects the output of hexadecimals
    std::cout << std::hex << std::showbase
              << "0x2a with uppercase: " << std::uppercase << 0x2a << '\n'
              << "0x2a with nouppercase: " << std::nouppercase << 0x2a << '\n'
              << "1e-10 with uppercase: " << std::uppercase << 1e-10 << '\n'
              << "1e-10 with nouppercase: " << std::nouppercase << 1e-10 << '\n';
}
```

---
#### `(no)showpos`, `(no)showpoint`

Ref: [std::showpos, std::noshowpos](https://en.cppreference.com/w/cpp/io/manip/showpos), [std::showpoint, std::noshowpoint](https://en.cppreference.com/w/cpp/io/manip/showpoint)

```cpp
#include <iostream>
int main()
{
    std::cout << "1.0 with showpoint: " << std::showpoint << 1.0 << '\n'
              << "1.0 with noshowpoint: " << std::noshowpoint << 1.0 << '\n';
    std::cout
        << "showpos: " << std::showpos << 42 << ' ' << 3.14 << ' ' << 0 << '\n'
        << "noshowpos: " << std::noshowpos << 42 << ' ' << 3.14 << ' ' << 0 << '\n';
}
```

---
#### `(no)skipws`

Ref: [std::skipws, std::noskipws](https://en.cppreference.com/w/cpp/io/manip/skipws)

```cpp
#include <iostream>
#include <sstream>
int main()
{
    char c1, c2, c3;
    std::istringstream("a b c") >> c1 >> c2 >> c3;
    std::cout << "Default  behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';
    std::istringstream("a b c") >> std::noskipws >> c1 >> c2 >> c3;
    std::cout << "noskipws behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';
}
```

---
#### `internal`, `left`, `right`

Ref: [std::left, std::right, std::internal](https://en.cppreference.com/w/cpp/io/manip/left)

```cpp
#include <iostream>
#include <iomanip>
#include <locale>

int main()
{
    std::cout.imbue(std::locale("en_US.utf8"));

    std::cout << "Default positioning:\n"
              << std::setfill('*')
              << std::setw(12) << -1.23 << '\n'
              << std::setw(12) << std::hex << std::showbase << 42 << '\n'
              << std::setw(12) << std::put_money(123, true) << "\n\n";

    std::cout << "Left positioning:\n"
              << std::left
              << std::setw(12) << -1.23 << '\n'
              << std::setw(12) << 42 << '\n'
              << std::setw(12) << std::put_money(123, true) << "\n\n";

    std::cout << "Internal positioning:\n"
              << std::internal
              << std::setw(12) << -1.23 << '\n'
              << std::setw(12) << 42 << '\n'
              << std::setw(12) << std::put_money(123, true) << "\n\n";

    std::cout << "Right positioning:\n"
              << std::right
              << std::setw(12) << -1.23 << '\n'
              << std::setw(12) << 42 << '\n'
              << std::setw(12) << std::put_money(123, true) << '\n';
}
```

---
#### `hex`, `dec`, `oct`

Ref: [std::dec, std::hex, std::oct](https://en.cppreference.com/w/cpp/io/manip/hex)

```cpp
#include <iostream>
#include <sstream>
#include <bitset>
int main()
{
    std::cout << "The number 42 in octal:   " << std::oct << 42 << '\n'
              << "The number 42 in decimal: " << std::dec << 42 << '\n'
              << "The number 42 in hex:     " << std::hex << 42 << '\n';
    int n;
    std::istringstream("2A") >> std::hex >> n;
    std::cout << std::dec << "Parsing \"2A\" as hex gives " << n << '\n';
    // the output base is sticky until changed
    std::cout << std::hex << "42 as hex gives " << 42
              << " and 21 as hex gives " << 21 << '\n';

    // Note: there is no I/O manipulator that sets up a stream to print out
    // numbers in binary format (e.g. bin). If binary output is necessary
    // the std::bitset trick can be used:
    std::cout << "The number 42 in binary:  " << std::bitset<8>{42} << '\n';
}
```

---
#### `fixed`, `scientific`

Ref: [std::fixed, std::scientific](https://en.cppreference.com/w/cpp/io/manip/fixed)

```cpp
#include <iostream>
#include <iomanip>
#include <sstream>
 
enum class cap { title, middle, end };
void print(const char* text, double num, cap c)
{
    if (c == cap::title) std::cout <<
    "┌──────────┬────────────┬──────────────────────────┐\n"
    "│  number  │   iomanip  │      representation      │\n"
    "├──────────┼────────────┼──────────────────────────┤\n"
    ;
    std::cout << std::left
    << "│ " << std::setw(8) << text << " │ fixed      │ "
    << std::setw(24) << std::fixed        << num << " │\n"
    << "│ " << std::setw(8) << text << " │ scientific │ "
    << std::setw(24) << std::scientific   << num << " │\n"
    << "│ " << std::setw(8) << text << " │ hexfloat   │ "
    << std::setw(24) << std::hexfloat     << num << " │\n"
    << "│ " << std::setw(8) << text << " │ default    │ "
    << std::setw(24) << std::defaultfloat << num << " │\n"
    ;
    std::cout << (c != cap::end ?
    "├──────────┼────────────┼──────────────────────────┤\n" :
    "└──────────┴────────────┴──────────────────────────┘\n" );
}
```
---
```cpp 
int main()
{
    print("0.0", 0.0, cap::title);
    print("0.01", 0.01, cap::middle);
    print("0.00001", 0.00001, cap::end);
 
    // Note; choose clang for correct output
    double f;
    std::istringstream("0x1.8p+0") >> f;
    std::cout << "Parsing 0x1.8p+0 gives " << f << '\n';
 
    std::istringstream("0x1P-1022") >> f;
    std::cout << "Parsing 0x1P-1022 gives " << f << '\n';
}
```

---
#### `setw(val)`, `setfill(c)`

Ref: [std::setw](https://en.cppreference.com/w/cpp/io/manip/setw), [std::setfill](https://en.cppreference.com/w/cpp/io/manip/setfill)

```cpp
#include <sstream>
#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "default fill: [" << std::setw(10) << 42 << "]\n"
              << "setfill('*'): [" << std::setfill('*')
              << std::setw(10) << 42 << "]\n";
    std::cout << "no setw: [" << 42 << "]\n"
              << "setw(6): [" << std::setw(6) << 42 << "]\n"
              << "setw(6), several elements: [" << 89 << std::setw(6) << 12 << 34 << "]\n";
    std::istringstream is("hello, world");
    char arr[10];
    is >> std::setw(6) >> arr;
    std::cout << "Input from \"" << is.str() << "\" with setw(6) gave \""
              << arr << "\"\n";
}
```

---
#### `setprecision(val)`

Ref: [std::setprecision](https://en.cppreference.com/w/cpp/io/manip/setprecision)

```cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
int main()
{
    const long double pi = std::acos(-1.L);
    std::cout << "default precision (6): " << pi << '\n'
              << "std::setprecision(10): " << std::setprecision(10) << pi << '\n'
              << "max precision:         "
              << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
              << pi << '\n';
}
```

---
#### `setbase(val)`, alias of `std::oct`, `std::dec`, `std::hex`

Ref: [std::setbase](https://en.cppreference.com/w/cpp/io/manip/setbase)

```cpp
#include <iostream>
#include <sstream>
#include <iomanip>
int main()
{
    std::cout << "Parsing string \"10 0x10 010\"\n";

    int n1, n2, n3;
    std::istringstream s("10 0x10 010");
    s >> std::setbase(16) >> n1 >> n2 >> n3;
    std::cout << "hexadecimal parse: " << n1 << ' ' << n2 << ' ' << n3 << '\n';

    s.clear();
    s.seekg(0);
    s >> std::setbase(0) >> n1 >> n2 >> n3;
    std::cout << "prefix-dependent parse: " << n1 << ' ' << n2 << ' ' << n3 << '\n';

    std::cout << "hex output: " << std::setbase(16)
              << std::showbase << n1 << ' ' << n2 << ' ' << n3 << '\n';
}
```

---
#### `setiosflags(flag)`, `resetiosflags(m)`

Ref: [std::setiosflags](https://en.cppreference.com/w/cpp/io/manip/setiosflags), [std::resetiosflags](https://en.cppreference.com/w/cpp/io/manip/resetiosflags)

```cpp
#include <sstream>
#include <iostream>
#include <iomanip>
int main()
{
    if (false)
    {
        std::cout << std::resetiosflags(std::ios_base::dec)
                  << std::setiosflags(std::ios_base::hex | std::ios_base::uppercase | std::ios_base::showbase) << 42 << '\n';
    }
    else
    {
        std::istringstream in("10 010 10 010 10 010");
        int n1, n2;
        in >> std::oct >> n1 >> n2;
        std::cout << "Parsing \"10 010\" with std::oct gives:  " << n1 << ' ' << n2 << '\n';
        in >> std::dec >> n1 >> n2;
        std::cout << "Parsing \"10 010\" with std::dec gives:  " << n1 << ' ' << n2 << '\n';
        in >> std::resetiosflags(std::ios_base::basefield) >> n1 >> n2;
        std::cout << "Parsing \"10 010\" with autodetect gives: " << n1 << ' ' << n2 << '\n';
    }
}
```

## Stream Status & Error Handling

Ref: [std::basic_ios](https://en.cppreference.com/w/cpp/io/basic_ios), [std::ios_base::iostate](https://en.cppreference.com/w/cpp/io/ios_base/iostate)

- 4 states: `.good()`, `.eof()`, `.fail()`, `.bad()`
  - `.good()`: checks if no error has occurred i.e. I/O operations are available.
  - `.eof()`: checks if end-of-file has been reached.
  - `.fail()`: checks if an error has occurred.
  - `.bad()`: checks if a non-recoverable error has occurred.

all of them are based on `ios_base::iostate`
  - `badbit`: `true` if the stream has an irrecoverable stream error
  - `eofbit`: `true` if the stream's associated input sequence has reached end-of-file
  - `failbit`: `true` if the stream has an input/output operation failed (formatting or extraction error)

---
### When will `badbit` be set

The badbit is set by the following situations:

- Fails to insert a character into the output stream, for any reason.
- `operator<<` encounter the end of the output stream before completing output.
- Initialize a stream with a `NULL` pointer.
- called on a stream with a `NULL` pointer buffer.
- A `NULL` pointer is passed as the argument.
- Buffer opeartions are returned with EOF value.
- Every stream I/O function if an exception is thrown by any member function of the associated stream buffer.
- Failure to allocate memory.

---
### When will `eofbit` be set

The eofbit is set by the following situations:

- Reaching the end of the stream, as opposed to reaching the specified terminating character.

---
### When will `failbit` be set

The failbit is set by the following situations:

- Initialize a stream while the stream either `eofbit` or `badbit` is set.
- Extract invalid characters/invalid format/no characters or extract a `NULL` pointer.
- Extract `basic_string::max_size` characters from the input stream.
- If the end-of-file condition occurs on the input stream before all requested characters could be extracted.
- `seekg` or `tellp` on failure
- The constructors of `fstream`, `ifstream`, and `ofstream` that takes a filename argument, if the file cannot be opened.
- `fstream::open`, `ifstream::open`, and `ofstream::open` if the file cannot be opened.
- `fstream::close`, `ifstream::close`, and `ofstream::close` if the file cannot be closed.

---
### Relation between `iostate` flags and stream status

|  `eofbit`  | `failbit`  |  `badbit`  | `.good()`  | `.fail()`  |  `.bad()`  |  `.eof()`  | `operator bool()` | `operator!()` |
| :--------: | :--------: | :--------: | :--------: | :--------: | :--------: | :--------: | :---------------: | :-----------: |
|  `false`   |  `false`   |  `false`   | **`true`** |  `false`   |  `false`   |  `false`   |    **`true`**     |    `false`    |
|  `false`   |  `false`   | **`true`** |  `false`   | **`true`** | **`true`** |  `false`   |      `false`      |  **`true`**   |
|  `false`   | **`true`** |  `false`   |  `false`   | **`true`** |  `false`   |  `false`   |      `false`      |  **`true`**   |
|  `false`   | **`true`** | **`true`** |  `false`   | **`true`** | **`true`** |  `false`   |      `false`      |  **`true`**   |
| **`true`** |  `false`   |  `false`   |  `false`   |  `false`   |  `false`   | **`true`** |    **`true`**     |    `false`    |
| **`true`** |  `false`   | **`true`** |  `false`   | **`true`** | **`true`** | **`true`** |      `false`      |  **`true`**   |
| **`true`** | **`true`** |  `false`   |  `false`   | **`true`** |  `false`   | **`true`** |      `false`      |  **`true`**   |
| **`true`** | **`true`** | **`true`** |  `false`   | **`true`** | **`true`** | **`true`** |      `false`      |  **`true`**   |

## Exception & Exception Handling

- What is an exception?
- How to handle exceptions?
- How many types of exceptions?
- `iostream`, `fstream` & exception handling

---
### What is an exception?

Ref: [Exception Handling in C++](https://www.geeksforgeeks.org/exception-handling-in-c/)

> Exceptions are run-time anomalies or abnormal conditions that a program encounters during its execution.
> There are two types of exceptions: 
>   a) Synchronous
>   b) Asynchronous (Ex: which are beyond the program's control, Disc failure etc).

---
### How to handle exceptions?

In C++, exceptions are handled by the following statements:

```cpp
try
{
    // a exception variable, could be any type
    // and could be used without declaration
    exception_type e;

    // statements to be executed

    // if exception occurs, throw the exception
    throw e;
}
catch (exception_type e)
{
    // statements to handle any exception thrown
}
```

---
#### Example:

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = -1;

    // Some code
    cout << "Before try \n";
    try
    {
        cout << "Inside try \n";
        if (x < 0)
        {
            throw x;
            cout << "After throw (Never executed) \n";
        }
    }
    catch (int x)
    {
        cout << "Exception Caught \n";
    }

    cout << "After catch (Will be executed) \n";
    return 0;
}
```

---
#### Example: multiple catch blocks & default catch block

```cpp
#include <iostream>
using namespace std;

int main()
{
    try
    {
        throw 10;
    }
    catch (char *excp)
    {
        cout << "Caught " << excp;
    }
    catch (...)
    {
        cout << "Default Exception\n";
    }
    return 0;
}
```

---
#### Example: uncaught exception

```cpp
#include <iostream>
using namespace std;

int main()
{
    try
    {
        // error, unhandled exception
        throw 'a';
    }
    catch (int x)
    {
        cout << "Caught ";
    }
    return 0;
}
```

---
#### Example: Nesting of exceptions

```cpp
#include <iostream>
using namespace std;

int main()
{
    try
    {
        try
        {
            throw 20;
        }
        catch (int n)
        {
            cout << "Handle Partially ";
            throw; // Re-throwing an exception
        }
    }
    catch (int n)
    {
        cout << "Handle remaining ";
    }
    return 0;
}
```

---
#### Example: class & exception

```cpp
#include <iostream>
using namespace std;

class Test
{
public:
    Test() { cout << "Constructor of Test " << endl; }
    ~Test() { cout << "Destructor of Test " << endl; }
};

int main()
{
    try
    {
        Test t1;
        throw 10;
    }
    catch (int i)
    {
        cout << "Caught " << i << endl;
    }
}
```

---
#### Example: class inheritance & exception

```cpp
// C++ Program to demonstrate a catching of
// Derived exception and printing it successfully
#include <iostream>
using namespace std;

class Base
{
};
class Derived : public Base
{
};
int main()
{
    Derived d;
    // Some other functionalities
    try
    {
        // Monitored code
        throw d;
    }
    catch (Derived d)
    {
        // the derived class object should be caught before the base class object
        // else the base class object will always be caught
        cout << "Caught Derived Exception";
    }
    catch (Base b)
    {
        cout << "Caught Base Exception";
    }
    getchar(); // To read the next character
    return 0;
}
```

---
### How many types of exceptions?

There are three types of exceptions:
- any preliminary types (e.g., `int`, `char`, `float`, etc.)
  - Discussed in the previous section
- user-defined types (e.g., `class`, `struct`, etc.)
  - Discussed in the previous section
- `std::exception`

---
#### `std::exception`

Ref: [Exception header in C++ with examples](https://www.geeksforgeeks.org/exception-header-in-c-with-examples/)

`std::exception` is the base class of all exceptions in C++ standard library.

|        Exception         |        Description        |
| :----------------------: | :-----------------------: |
|     `std::bad_alloc`     | Memory allocation failed  |
|     `std::bad_cast`      |  Invalid type conversion  |
|   `std::bad_exception`   | Exception handling failed |
|    `std::bad_typeid`     |      Invalid typeid       |
| `std::bad_function_call` |   Invalid function call   |
|   `std::bad_weak_ptr`    |   Invalid weak pointer    |
|    `std::logic_error`    |        Logic error        |
|   `std::runtime_error`   |       Runtime error       |

---
##### `exception::what()`

Ref: [exception::what() in C++ with Examples](https://www.geeksforgeeks.org/exceptionwhat-in-c-with-examples/)

To get the description of the exception, use the `what()` member function.
The example below shows how to use the `what()` member function and how it works.

```cpp
// C++ code for exception::what()
#include <iostream>
#include <exception>
using namespace std;
class geeksforgeeks : public exception
{
public:
    const char *what() const noexcept
    {
        return "Hey!!";
    }
};
```
---
```cpp
// main method
int main()
{
    // try block
    try
    {
        throw geeksforgeeks();
    }
    // catch block to handle the errors
    catch (exception &gfg)
    {
        cout << gfg.what();
    }
    return 0;
}
```

---
#### Example: `std::bad_alloc`

```cpp
// C++ program to illustrate bad_alloc
// using class bad_alloc
#include <exception>
#include <iostream>
using namespace std;
// Function to illustrate bad_alloc
void createArray(long long N)
{
    // Try Block
    try
    {
        // Create an array of length N
        int *array = new int[N];
        // If created successfully then
        // print the message
        cout << "Array created successfully"
             << " of length " << N << " \n";
    }
    // Check if the memory
    // was allocated or not
    // using class bad_alloc
    catch (bad_alloc &e)
    {
        // If not, print the error message
        cout << e.what()
             << " for array of length "
             << N << " \n";
    }
}
```
---
```cpp
// Driver Code
int main()
{
    // Function call to create an
    // array of 1000 size
    createArray(1000);
    // Function call to create an
    // array of 1000000000 size
    createArray(10000000000);
    return 0;
}
```

---
#### Example: `std::logic_error`

```cpp
// C++ program to illustrate logic_error
#include <exception>
#include <iostream>
using namespace std;
// Function to find factorial of N and
// throws error if occurs
void findFactorial(int N)
{
    // Initialise variable by 1
    int factorial = 1;
    // Check for errors
    try
    {
        // If N is less than zero then,
        // it shows errors as factorial
        // of negative number can't be
        // calculated
        if (N < 0)
        {
            // Exception object which
            // returns the message passed
            // to it
            throw invalid_argument(
                "negative not allowed");
        }
        // Find factorial if no error occurs
        for (int i = N; i > 0; i--)
        {
            factorial *= i;
        }
        cout << "Factorial of " << N
             << " is " << factorial << endl;
    }
    // Print the error message
    catch (exception &e)
    {
        cout << e.what();
    }
}
```
---
```cpp
// Driver Code
int main()
{
    // Function call to find factorial
    // of 0
    findFactorial(0);
    // Function call to find factorial
    // of 3
    findFactorial(3);
    // Function call to find factorial
    // of -1
    findFactorial(-1);
    return 0;
}
```

---
#### Example: Divide by zero

Ref: [Handling the Divide by Zero Exception in C++](https://www.geeksforgeeks.org/handling-the-divide-by-zero-exception-in-c)

```cpp
// Program to depict how to handle
// divide by zero exception
#include <iostream>
#include <stdexcept> // To use runtime_error
using namespace std;
// Defining function Division
float Division(float num, float den)
{
    // If denominator is Zero
    // throw runtime_error
    if (den == 0)
    {
        throw runtime_error("Math error: Attempted to divide by Zero\n");
    }
    // Otherwise return the result of division
    return (num / den);
} // end Division
```
---
```cpp
int main()
{
    float numerator, denominator, result;
    numerator = 12.5;
    denominator = 0;
    // try block calls the Division function
    try
    {
        result = Division(numerator, denominator);
        // this will not print in this example
        cout << "The quotient is "
             << result << endl;
    }
    // catch block catches exception thrown
    // by the Division function
    catch (runtime_error &e)
    {
        // prints that exception has occurred
        // calls the what function
        // using runtime_error object
        cout << "Exception occurred" << endl
             << e.what();
    }
} // end main
```

---
### `iostream`, `fstream` & exception handling

Ref: [std::basic_ios::exceptions](https://en.cppreference.com/w/cpp/io/basic_ios/exceptions)

To Handle stream `.bad()`, `.fail()` and `.eof()` flags with `try ... catch` block, use `.exceptions()` member function to set the exceptions to be thrown.
The type of exception thrown is `ios_base::failure`.

---
Example:

```cpp 
#include <iostream>
#include <fstream>

int main()
{
    int ivalue;
    try
    {
        std::ifstream in("in.txt");
        in.exceptions(std::ifstream::failbit); // may throw
        in >> ivalue;                          // may throw
    }
    catch (const std::ios_base::failure &fail)
    {
        // handle exception here
        std::cout << fail.what() << '\n';
    }
}
```

## Example: Exception Handling, `iostream` & `fstream` Error Handling [[Source](./lecture15_ex.html)]

## Practices

- Try to read/write files in serveral stream formats.
  - `std::string`, `std::hex`, `std::uppercase`, etc.
- Try to handle errors in `std::fstream` and `std::iostream`
  - fail to open file, read/write error, invalid format, etc.
- Try to throw/handle exceptions in user-defined class
  - examples in lectrue 2 to lecture 12