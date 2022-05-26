<!---
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
--->

# File Processing (2)

> Slides version: [lecture14_slides.html](./lecture14_slides.html)
> Website version: [lecture14.html](./lecture14.html)

- Recap: File in C++
  - Open & Close File
  - Read or Write or Read & Write
  - Text or Binary
  - Append or Overwrite
  - Sequantial or Random Access
* Detail in `iostream` & `fstream`
  - Stream I/O & Buffer
  - Stream Operator & Manipulator
  - Stream Status & Error Handling (More details in lecture 15)
---
* File I/O & `class`
  - File I/O function in a `class`
* File I/O for Structured Data
  - Class or Function?
  - Text or Binary File?
  - Sequential or Random Access?
* Example 1: Point & Triangle in Text File (class ver.)
* Example 2: Vector & Matrix in Binary File (class ver.)
* Lab 14: File Export of Complex Number's Geometry

## Recap: File in C++

---
### Example: Gradebook (Text)

In text format (csv):

``` csv
Name,Grade
John,A
Mary,B
```

In table format:

| Name  | Grade |
| :---: | :---: |
| John  |   A   |
| Mary  |   B   |

---
### Example: Image (Binary)

In viewable format: as the image on the right

![bg right fit](img/nthu.jpg)

In binary format:

```binary
00000000: ffd8 ffe1 4812 4578 6966 0000 4d4d 002a  ....H.Exif..MM.*
00000010: 0000 0008 0007 0112 0003 0000 0001 0001  ................
00000020: 0000 011a 0005 0000 0001 0000 0062 011b  .............b..
00000030: 0005 0000 0001 0000 006a 0128 0003 0000  .........j.(....
00000040: 0001 0002 0000 0131 0002 0000 001c 0000  .......1........
00000050: 0072 0132 0002 0000 0014 0000 008e 8769  .r.2...........i
00000060: 0004 0000 0001 0000 00a4 0000 00d0 002d  ...............-
00000070: c6c0 0000 2710 002d c6c0 0000 2710 4164  ....'..-....'.Ad
00000080: 6f62 6520 5068 6f74 6f73 686f 7020 4353  obe Photoshop CS
00000090: 3520 5769 6e64 6f77 7300 3230 3133 3a30  5 Windows.2013:0
000000a0: 343a 3031 2031 353a 3033 3a30 3400 0000  4:01 15:03:04...
000000b0: 0003 a001 0003 0000 0001 0001 0000 a002  ................
```

---
### Process a File

- Open & Close File
  - constructor or `.open()`
- Read or Write or Read & Write
  - `ifstream` and `ofstream`
  - `ios::in` and `ios::out` in `mode` argument of `fstream`
- Text or Binary
  - `ios::binary` in `mode` argument
- Append or Overwrite
  - `ios::app` and `ios::trunc` in `mode` argument
- Sequantial or Random Access
  - `.seekp()` and `.tellp()` for set/get position of `<<`
  - `.seekg()` and `.tellg()` for set/get position of `>>` or `getline()`

---
### `mode` and file handeling

Ref: [std::basic_filebuf<CharT,Traits>::open - cppreference.com](https://en.cppreference.com/w/cpp/io/basic_filebuf/open)

|                  `mode`                   | Action if file exists | Action if file does not exist |
| :---------------------------------------: | :-------------------: | :---------------------------: |
|                   `in`                    |    Read from start    |             Error             |
|            `out`, `out\|trunc`            |   Destory contents    |          Create new           |
|             `app`, `out\|app`             |     Write to end      |          Create new           |
|                 `out\|in`                 |    Read from start    |             Error             |
|             `out\|in\|trunc`              |   Destory contents    |          Create new           |
|         `out\|in\|app`, `in\|app`         |     Write to end      |          Create new           |
|               `binray\|in`                |    Read from start    |             Error             |
|    `binray\|out`, `binray\|out\|trunc`    |   Destory contents    |          Create new           |
|     `binray\|app`, `binray\|out\|app`     |     Write to end      |          Create new           |
|             `binray\|out\|in`             |    Read from start    |             Error             |
|         `binray\|out\|in\|trunc`          |   Destory contents    |          Create new           |
| `binray\|out\|in\|app`, `binray\|in\|app` |     Write to end      |          Create new           |

## Detail in `iostream` & `fstream`

Inheritance diagram: (Ref: [File Handling through C++ Classes](https://www.geeksforgeeks.org/file-handling-c-classes/))

![](img/CPP-File-Handling.png)

---

Some `istream` and `ostream` functions can be used in thier derived classes:
- `<<` from `ostream` and `>>` from `istream` can be used in `fstream` and `stringstream`
- `put()` from `ostream`, `get()` and `getline()` from `istream` can be used in `fstream` and `stringstream`
- Manupulators, such as `std::fixed`, `std::setprecision()` can be used in `fstream` and `stringstream`

Details will be discussed in lecture 15.

---
### Stream I/O & Buffer

Ref: [Basic Input / Output in C++](https://www.geeksforgeeks.org/basic-input-output-c/)

C++ comes with libraries that provide for performing input and output.
> - Input Stream: The information is from the device (for example, Keyboard) to the main memory
> - Output Stream: The information is from main memory to device (display screen)

![bg right fit](img/C-basic-input-output.png)

---

#### What is a buffer? 

Ref: [Clearing The Input Buffer In C/C++](https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/)

> A temporary storage area is called a buffer.
> All standard input and output devices contain an input and output buffer.
> In standard C/C++, streams are buffered, for example in the case of standard input, when we press the key on the keyboard, it isn’t sent to your program, rather it is buffered by the operating system till the time is allotted to that program.

---

Example:

``` cpp
// C++ Code to explain why
// not clearing the input
// buffer causes undesired
// outputs
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    char ch[80];

    // Enter input from user
    // - 4 for example
    cin >> a;

    // Get input from user -
    // "GeeksforGeeks" for example
    cin.getline(ch, 80);

    // Prints 4
    cout << a << endl;

    // Printing string : This does
    // not print string
    cout << ch << endl;

    return 0;
}
```

---

Console:

``` console
$ ./a.out
4
GeeksforGeeks
4

$
```

Why? because the '\n' character is typed into the buffer and is not removed.
- When the user presses the <kbd>Enter</kbd> key, the '\n' character sends to the buffer.

---
#### How to clear the buffer?

1. Using `cin.ignore(numeric_limits::max(),’\n’);`

``` cpp
// C++ Code to explain how
// "cin.ignore(numeric_limits
// <streamsize>::max(),'\n');"
// discards the input buffer
#include <iostream>
// for <streamsize>
#include <ios>
// for numeric_limits
#include <limits>
using namespace std;
int main()
{
    int a;
    char str[80];
    // Enter input from user
    // - 4 for example
    cin >> a;
    // discards the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Get input from user -
    // GeeksforGeeks for example
    cin.getline(str, 80);
    // Prints 4
    cout << a << endl;
    // Printing string : This
    // will print string now
    cout << str << endl;
    return 0;
}
```

---
2. Using `cin.sync()`

``` cpp
// C++ Code to explain how " cin.sync();"
// discards the input buffer
#include <iostream>
#include <ios>
#include <limits>
using namespace std;
int main()
{
    int a;
    char str[80];
    // Enter input from user
    // - 4 for example
    cin >> a;
    // Discards the input buffer
    cin.sync();
    // Get input from user -
    // GeeksforGeeks for example
    cin.getline(str, 80);
    // Prints 4
    cout << a << endl;
    // Printing string - this
    // will print string now
    cout << str << endl;
    return 0;
}
```

---
3. Using `cin >> ws`

``` cpp
// C++ Code to explain how "cin >> ws"
// discards the input buffer along with
// initial white spaces of string
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a;
    string s;
    // Enter input from user -
    // 4 for example
    cin >> a;
    // Discards the input buffer and
    // initial white spaces of string
    cin >> ws;
    // Get input from user -
    // GeeksforGeeks for example
    getline(cin, s);
    // Prints 4 and GeeksforGeeks :
    // will execute print a and s
    cout << a << endl;
    cout << s << endl;
    return 0;
}
```

---
### Stream Operator & Manipulator

#### `<<` & `>>` stream operator

[Overloading stream insertion (<>) operators in C++](https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/)

> - Why these operators must be overloaded as global?
> In operator overloading, if an operator is overloaded as a member, then it must be a member of the object on the *left side* of the operator.
> For example, `ob1 + ob2`. To make this statement compile, we must overload `+` in a class of `ob1` or make `+` a global function.
> The operators `<<` and `>>` are called like `cout << ob1` and `cin >> ob1`.
> So if we want to make them a member method, then they must be made members of ostream and istream classes, which is not a good option most of the time.
> Therefore, these operators are overloaded as global functions with two parameters, cout and object of user-defined class.

---
#### Stream Manipulator (More detailed in lecture 15)

Ref: [Manipulators in C++ with Examples](https://www.geeksforgeeks.org/manipulators-in-c-with-examples/)

There are two types of manipulators in C++:
1. Manipulators without arguments:
   - endl: Defined in ostream. It is used to enter a new line and after entering a new line it flushes the output stream.
   - ws: It is defined in istream and is used to ignore the whitespaces in the string sequence.
   - ends: It is also defined in ostream and it inserts a null character into the output stream.
   - flush: It is also defined in ostream and it flushes the output stream.

---
Example:

``` cpp
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    istringstream str("		 Programmer");
    string line;
    // Ignore all the whitespace in string
    // str before the first word.
    getline(str >> std::ws, line);
    // you can also write str>>ws
    // After printing the output it will automatically
    // write a new line in the output stream.
    cout << line << endl;
    // without flush, the output will be the same.
    cout << "only a test" << flush;
    // Use of ends Manipulator
    cout << "\na";
    // NULL character will be added in the Output
    cout << "b" << ends;
    cout << "c" << endl;
    return 0;
}
```

---
2. Manipulators with Arguments: Some of the manipulators are used with the argument like `setw(20)`, `setfill(*)`, and many more.

- In `<iomanip>`:
  - `setw(val)`, `setfill(c)`, `setprecision(val)`, `setbase(val)`, `setiosflags(flag)`, `resetiosflags(m)`
- In `<ios>`:
  - `showpos`, `noshowpos`, `showbase`, `uppercase`, `nouppercase`, `fixed`, `scientific`, `hex`, `dec`, `oct`, `left`, `right`

We will discuss the manipulators in the lecture 15.

---
### Stream Status & Error Handling (More details in lecture 15)

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
#### Example

Ref: [`std::basic_ios<CharT,Traits>::good`](https://en.cppreference.com/w/cpp/io/basic_ios/good)

```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
int main()
{
    const char *fname = "test.txt";
    std::ofstream ofile{fname};
    ofile << "10 "
          << "11 "
          << "12 "
          << "non-int";
    ofile.close();

    std::ifstream file{fname};
    if (!file.good())
    {
        std::cout << "#1. Opening file test.txt failed - "
                     "one of the error flags is true\n";
        return EXIT_FAILURE;
    }
```
---
``` cpp
    // typical C++ I/O loop uses the return value of the I/O function
    // as the loop controlling condition, operator bool() is used here
    for (int n; file >> n;)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    if (file.bad())
    {
        std::cout << "#2. I/O error while reading - badbit is true\n";
        return EXIT_FAILURE;
    }
    else if (file.eof())
    {
        std::cout << "#3. End of file reached successfully - eofbit is true\n"
                     "This is fine even though file.good() is false\n";
    }
    else if (file.fail())
    {
        std::cout << "#4. Non-integer data encountered - failbit is true\n";
    }
}
```

---
Output:

```
$ ./a.out
10 11 12
#4. Non-integer data encountered - failbit is true
$
```

## File I/O & `class`

### File I/O function in a `class`

If we want to store the data of a class into a file, we can use 2 methods:
- Text File: `<<` and `>>` operators
- Binary File: new member functions

---
### Text File

As we know, we can use `<<` and `>>` operators to store and retrieve data from a file.
Just like we can use `cout` and `cin` to store and retrieve data from the console, we can use `ofstream` and `ifstream` to store and retrieve data from a file.

---
### Binary File: new member functions

We can add new member functions to the class to store and retrieve binary data from a file.
Two data styles:
- Read/Write each data member into a file
  - Disscuss in example 2
- Read/Write the entire class variable into a file

---
#### Read/Write the entire class variable into a file

Ref: [Read/Write Class Objects from/to File in C++](https://www.geeksforgeeks.org/readwrite-class-objects-fromto-file-c/)

**Theory**:
The data transfer is usually done using `>>` and `<<` operators.
But if you have a class with 4 data members and want to write all 4 data members from its object directly to a file or vice-versa, we can do that using following syntax:

To write object's data members in a file:
``` cpp
// Here file_obj is an object of ofstream
file_obj.write((char *) & class_obj, sizeof(class_obj));
```

To read file's data members into an object:
``` cpp
// Here file_obj is an object of ifstream
file_obj.read((char *) & class_obj, sizeof(class_obj));
```

---
Example:

``` cpp
// C++ program to demonstrate read/write of class
// objects in C++.
#include <iostream>
#include <fstream>
using namespace std;

// Class to define the properties
class Contestant
{
public:
    // Instance variables
    string Name;
    int Age, Ratings;

    // Function declaration of input() to input info
    int input();

    // Function declaration of output_highest_rated() to
    // extract info from file Data Base
    int output_highest_rated();
};
```
---
``` cpp
// Function definition of input() to input info
int Contestant::input()
{
    // Object to write in file
    ofstream file_obj;

    // Opening file in append mode
    file_obj.open("Input.txt", ios::app);

    // Object of class contestant to input data in file
    Contestant obj;

    // Feeding appropriate data in variables
    string str = "Michael";
    int age = 18, ratings = 2500;

    // Assigning data into object
    obj.Name = str;
    obj.Age = age;
    obj.Ratings = ratings;

    // Writing the object's data in file
    file_obj.write((char *)&obj, sizeof(obj));

    // Feeding appropriate data in variables
    str = "Terry";
    age = 21;
    ratings = 3200;

    // Assigning data into object
    obj.Name = str;
    obj.Age = age;
    obj.Ratings = ratings;

    // Writing the object's data in file
    file_obj.write((char *)&obj, sizeof(obj));

    return 0;
}
```
---
``` cpp
// Function definition of output_highest_rated() to
// extract info from file Data Base
int Contestant::output_highest_rated()
{
    // Object to read from file
    ifstream file_obj;

    // Opening file in input mode
    file_obj.open("Input.txt", ios::in);

    // Object of class contestant to input data in file
    Contestant obj;

    // Reading from file into object "obj"
    file_obj.read((char *)&obj, sizeof(obj));

    // max to store maximum ratings
    int max = 0;

    // Highest_rated stores the name of highest rated contestant
    string Highest_rated;

    // Checking till we have the feed
    while (!file_obj.eof())
    {
        // Assigning max ratings
        if (obj.Ratings > max)
        {
            max = obj.Ratings;
            Highest_rated = obj.Name;
        }

        // Checking further
        file_obj.read((char *)&obj, sizeof(obj));
    }

    // Output is the highest rated contestant
    cout << Highest_rated;
    return 0;
}
```
---
``` cpp
// Driver code
int main()
{
    // Creating object of the class
    Contestant object;

    // Inputting the data
    object.input();

    // Extracting the max rated contestant
    object.output_highest_rated();

    return 0;
}
```

## File I/O for Structured Data

Guideline for Structured Data's File I/O:
  - Class or Function?
    - Depending on the data structure, we can either use a class or a function to read/write the data.
    - If the data structure is a class, we can use the class's member functions to read/write the data.
    - Otherwise, we can use a function to read/write the data.
  - Text or Binary File?
    - Binary file is used for efficient data transfer, but it is not human readable/editable.
    - Text file is human readable/editable, but it is not efficient for large data transfer.
---
  - Sequential or Random Access?
    - Sequential access does not require large memory to store the data. Usually used for data parsing and processing.
    - Random access requires large memory to store the data. Usually used for data storage, data retrieval, and data editing.
    - Random access is faster than sequential access, especially for binary file.

## Example 1: Point & Triangle in Text File (class ver.) [[Source](./lecture14_ex1.html)]

## Example 2: Vector & Matrix in Binary File (class ver.) [[Source](./lecture14_ex2.html)]

## Lab 14: [File Export of Complex Number's Geometry](./lab/lab14-1.html)