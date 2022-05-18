<!---
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
--->

# File Processing (1)

> Slides version: [lecture13_slides.html](./lecture13_slides.html)
> Website version: [lecture13.html](./lecture13.html)

- What is File?
  - Temporary variable & Permanent file
  - Example: Gradebook (Text) & Image (Binary)
* File 101 in C++
  - Open & Close File
  - Read or Write or Read & Write
  - Text or Binary
  - Append or Overwrite
  - Sequantial or Random Access
---
* Example 1: Big Real Number in Text File
* Example 2: Point & Triangle in Text File (function ver.)
* Example 3: Vector & Matrix in Binary File (function ver.)
* Pratices

## What is File?

> A computer file is a computer resource for recording data in a computer storage device, primarily identified by its file name. Just as words can be written to paper, so can data be written to a computer file.

Ref: https://en.wikipedia.org/wiki/Computer_file

![bg right fit](img/nthu.jpg)

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

## File 101 in C++

Steps to process a file:

1. Open a file
2. Seek to a position
3. Read or write data
4. Close the file

---
### Open a file (Write)

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // write to a file
    // create a output file stream object
    ofstream outfile;
    // open a file
    outfile.open("test.txt");
    // check if the file is open
    if (!outfile)
    {
        cout << "Error opening file" << endl;
        return 1;
    }
    // ...
}
```

---
### Seek to a position (Write)

``` c++
int main()
{
    // ...
    // open a file
    outfile.open("test.txt");
    // ...
    // seek to the end of the file
    outfile.seekp(0, ios::end);
    // ...
}
```

`test.txt`:

``` text
|
```

---
### Read or write data (Write)

``` c++
int main()
{
    // ...
    // seek to the end of the file
    outfile.seekp(0, ios::end);
    // write to the file
    outfile << "Hello World!" << endl;
    // ...
}
```

`test.txt`:

``` text
Hello World!⏎
|
```

---
### Close the file (Write)

``` c++
int main()
{
    // ...
    // write to the file
    outfile << "Hello World!" << endl;
    // close the file
    outfile.close();
}
```

`test.txt`:

``` text
Hello World!⏎
|<EOF>
```

---

### Hello World! (Write)

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // write to a file
    // create a output file stream object
    ofstream outfile;
    // open a file
    outfile.open("test.txt");
    // check if the file is open
    if (!outfile)
    {
        cout << "Error opening file" << endl;
        return 1;
    }
    // seek to the end of the file
    outfile.seekp(0, ios::end);
    // write to the file
    outfile << "Hello World!" << endl;
    // close the file
    outfile.close();
}
```

---
### Open a file (Read)

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // read from a file
    // create a input file stream object
    ifstream infile;
    // open the file
    infile.open("test.txt");
    // or open the file with ifstream constructor
    // ifstream infile("test.txt");
    // check if the file is open
    if(!infile)
    {
        cout << "Error opening file" << endl;
        return -1;
    }
    // ...
}
```

---
### Seek to a position (Read)

``` c++
int main()
{
    // ...
    // open the file
    infile.open("test.txt");
    // ...
    // seek to the front of the file
    infile.seekg(0, ios::beg);
    // ...
}
```

`test.txt`:

``` text
|Hello World!⏎
<EOF>
```

---
### Read or write data (Read)

``` c++
int main()
{
    // ...
    // seek to the front of the file
    infile.seekg(0, ios::beg);
    // read the file until the end (.eof() is true)
    while(!infile.eof())
    {
        // read a line
        string line;
        getline(infile, line);
        // print the line
        cout << line << endl;
    }
    // ...
}
```

---
`test.txt`:

``` text
Hello World!⏎
|<EOF>
```

console:

``` console
$ ./a.out
Hello World!

$
```

---
### Close the file (Write)

``` c++
int main()
{
    // ...
    // read the file until the end (.eof() is true)
    while(!infile.eof())
    {
        // read a line
        string line;
        getline(infile, line);
        // print the line
        cout << line << endl;
    }
    // close the file
    infile.close();
}
```

---
### Hello World! (Read)

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // read from a file
    // create a input file stream object
    ifstream infile;
    // open the file
    infile.open("test.txt");
    // or open the file with ifstream constructor
    // ifstream infile("test.txt");
    // check if the file is open
    if(!infile)
    {
        cout << "Error opening file" << endl;
        return -1;
    }
```
---
``` c++
    // seek to the front of the file
    infile.seekg(0, ios::beg);
    // read the file until the end (.eof() is true)
    while(!infile.eof())
    {
        // read a line
        string line;
        getline(infile, line);
        // print the line
        cout << line << endl;
    }
    // close the file
    infile.close();
}
```

## Open & Close File

Three ways to open a file:
- Open a file with `ofstream` (Write only)
- Open a file with `ifstream` (Read only)
- Open a file with `fstream` (Read & Write)

Two functions to open a file:
- Use constructor `fstream(filename, mode)`
- Use function `open(filename, mode)`

To close a file:
- Use function `close()`
- Use destructor inplicitly
  - The destructor will be called when the function returns

---
### Open & Close a file with `ofstream` (Write only)

```c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a output file stream object
    ofstream outfile;
    // open a file with `.open(filename)`
    outfile.open("test.txt");
    // close the file
    outfile.close();

    // open a file with constructor `ofstream(filename)`
    ofstream outfile2("test.txt");
    // close the file
    outfile2.close();
}
```

---
### Open & Close a file with `ifstream` (Read only)

```c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object
    ifstream infile;
    // open a file with `.open(filename)`
    infile.open("test.txt");
    // close the file
    infile.close();

    // open a file with constructor `ifstream(filename)`
    ifstream infile2("test.txt");
    // close the file
    infile2.close();
}
```

---
### Open & Close a file with `fstream` (Read & Write)

```c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object
    fstream file;
    // open a file with `.open(filename)`
    file.open("test.txt");
    // close the file
    file.close();

    // open a file with constructor `fstream(filename)`
    fstream file2("test.txt");
    // close the file
    file2.close();
}
```

---
### Check if the file is open

```c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object
    fstream file;
    // open a file with `.open(filename)`
    file.open("test.txt");
    // check if the file is open
    if(!file)
    {
        cout << "Error opening file" << endl;
        return -1;
    }
    // or use `.is_open()`
    if(!file.is_open())
    {
        cout << "Error opening file" << endl;
        return -1;
    }
    // do something

    // close the file
    file.close();
}
```

## Read or Write or Read & Write

- To read a file only: use `ifstream` or `fstream(filename, ios::in)`
- To write a file only: use `ofstream` or `fstream(filename, ios::out)`
- To read & write a file: use `fstream(filename, ios::in | ios::out)`

Note:
- `ifstream` is used like `fstream(filename, ios::in)` but not the same
- `ofstream` is used like `fstream(filename, ios::out)` but not the same

---
### Read a file only

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object with `ifstream(filename)`
    ifstream infile("test.txt");
    // print the file
    while(!infile.eof())
    {
        // read a line
        string line;
        getline(infile, line);
        // print the line
        cout << line << endl;
    }
    infile.close();

    // or use `fstream(filename, ios::in)`
    fstream file;
    // open a file with `.open(filename)`
    file.open("test.txt", ios::in);
    // print the file
    while(!file.eof())
    {
        string line;
        getline(file, line);
        cout << line << endl;
    }
    // close the file
    file.close();
}
```

---
### Write a file only

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a output file stream object with `ofstream(filename)`
    ofstream outfile("test.txt");
    // write a line
    outfile << "Hello World!" << endl;
    // close the file
    outfile.close();

    // or use `fstream(filename, ios::out)`
    fstream file;
    // open a file with `.open(filename)`
    file.open("test2.txt", ios::out);
    // write a line
    file << "Hello World!" << endl;
    // close the file
    file.close();
}
```

---
### Read & Write a file

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object with `fstream(filename, ios::in | ios::out)`
    // Note: create "test.txt" first
    fstream file("test.txt", ios::in | ios::out);
    // write lines
    for( int i = 0; i < 10; i++ )
    {
        file << "Line " << i << endl;
    }
    // seek to the beginning of the file
    file.seekg(0, ios::beg);
    // print the file
    for( int i = 0; i < 10; i++ )
    {
        // read a line
        string line;
        getline(file, line);
        // print the line
        cout << line << endl;
    }
    // close the file
    file.close();
}
```


---
### If file not exist

`fstream`, `ifstream` and `ofstream` will handle the file if it not exist.

- Create new file: `ofstream`, `fstream(filename, ios::out)`, `fstream(filename, ios::in | ios::out | ios::trunc)`, `fstream(filename, ios::out | ios::app)`
  - `ios::trunc` & `ios::app` will be disscussed later
- Error opening file: `ifstream`, `fstream(filename, ios::in)`, `fstream(filename, ios::in | ios::out)`

---
Example:

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // open a non-existing file
    ifstream infile("test.txt");
    // check if the file is open
    if(!infile)
    {
        cout << "Error opening file" << endl;
    }
    // create a new file and open it
    ofstream outfile("test.txt");
    // write some text to the file
    outfile << "Hello World!" << endl;
    outfile.close();
```
---
``` c++
    // read the file again
    fstream file("test.txt");
    // check if the file is open
    if(!file)
    {
        cout << "Error opening file" << endl;
    }
    // read the file
    while (!file.eof())
    {
        string line;
        getline(file, line);
        cout << line << endl;
    }
    // close the file
    file.close();
}
```

## Text or Binary

- Text file: save the data in character format

``` text
Name,Grade
John,A
Mary,B
```

- Binary file: save the data with the same format as the computer

``` binary
00000000: ffd8 ffe1 4812 4578 6966 0000 4d4d 002a  ....H.Exif..MM.*
```

The file saved JPEG header `ffd8`, `ffe1`, and has 18,450 (`0x4812`) bytes of metadata.
The metadata store EXIF information `Exif..MM.*` (`4578 6966 0000 4d4d 002a`).

---
### Read & Write a text file

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object with `fstream(filename, ios::in | ios::out)`
    // Note: create "test.txt" first
    fstream file("test.txt", ios::in | ios::out);
    // write lines
    for( int i = 0; i < 10; i++ )
    {
        file << "Line " << i << endl;
    }
    // seek to the beginning of the file
    file.seekg(0, ios::beg);
    // print the file
    for( int i = 0; i < 10; i++ )
    {
        // read a line
        string line;
        getline(file, line);
        // print the line
        cout << line << endl;
    }
    // close the file
    file.close();
}
```

---
Result: `test.txt`

``` text
Line 0⏎
Line 1⏎
Line 2⏎
Line 3⏎
Line 4⏎
Line 5⏎
Line 6⏎
Line 7⏎
Line 8⏎
Line 9⏎
<EOF>
```

---
### Read & Write a binary file

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object with `fstream(filename, ios::in | ios::out)`
    // Note: create "test.bin" first
    fstream file("test.bin", ios::in | ios::out | ios::binary);
    // write lines
    for (int i = 0; i < 10; i++)
    {
        string temp("Line");
        // write string to file, we need to use `.c_str()` to convert string to char*
        file.write(temp.c_str(), temp.size());
        // for other data type like int, float, double, etc.
        // we need to convert the data type to char* first
        // use `&` to get the address of the data,
        // use `(char *)` to convert the address to char*,
        // and use `sizeof(type)` to get the size (number of bytes) of the data type
        // then use `.write(data, size)` to write the data to file
        file.write((char *)&i, sizeof(int)); // write int value to file
    }
    file.flush(); // flush the buffer
```
---
``` c++
    // seek to the beginning of the file
    file.seekg(0, ios::beg);
    // print the file
    for (int i = 0; i < 10; i++)
    {
        // read string from file
        char temp[5];
        // because we store "Line" in the file, so we only need to read 4 bytes
        file.read(temp, 4);
        // add '\0' to the end of the string
        temp[4] = '\0';
        // read int from file
        int temp_int;
        // same as write, we need to convert the data type to char* first
        // then use `.read(data, size)` to read the data from file
        file.read((char *)&temp_int, sizeof(int));
        cout << temp << " " << temp_int << endl;
    }
    // close the file
    file.close();
}
```

---
Result: `test.bin`

``` binary
00000000: 4c69 6e65 0000 0000 4c69 6e65 0100 0000  Line....Line....
00000010: 4c69 6e65 0200 0000 4c69 6e65 0300 0000  Line....Line....
00000020: 4c69 6e65 0400 0000 4c69 6e65 0500 0000  Line....Line....
00000030: 4c69 6e65 0600 0000 4c69 6e65 0700 0000  Line....Line....
00000040: 4c69 6e65 0800 0000 4c69 6e65 0900 0000  Line....Line....
```

## Append or Overwrite

Two ways to handle a existing file:
- Append (`ios::app`): append the data to the end of the file
- Overwrite (`ios::trunc`): overwrite the file

---
### Append (`ios::app`)

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object with `fstream(filename, ios::in | ios::out)`
    // Note: create "test.txt" first
    fstream file("test.txt", ios::in | ios::out);
    // write lines
    for (int i = 0; i < 10; i++)
    {
        file << "Line " << i << endl;
    }
    // seek to the beginning of the file
    file.seekg(0, ios::beg);
    // print the file
    for (int i = 0; i < 10; i++)
    {
        // read a line
        string line;
        getline(file, line);
        // print the line
        cout << line << endl;
    }
    // close the file
    file.close();
```
---
``` c++
    // open again with `ios::app`
    fstream file2("test.txt", ios::in | ios::out | ios::app);
    // write a line
    for (int i = 10; i < 20; i++)
    {
        file2 << "Line " << i << endl;
    }
    // seek to the beginning of the file
    file2.seekg(0, ios::beg);
    // print the file
    for (int i = 0; i < 20; i++)
    {
        // read a line
        string line;
        getline(file2, line);
        // print the line
        cout << line << endl;
    }
    // close the file
    file2.close();
}
```

---
Result: `test.txt`

``` text
Line 0⏎
Line 1⏎
Line 2⏎
Line 3⏎
Line 4⏎
Line 5⏎
Line 6⏎
Line 7⏎
Line 8⏎
Line 9⏎
Line 10⏎
Line 11⏎
Line 12⏎
Line 13⏎
Line 14⏎
Line 15⏎
Line 16⏎
Line 17⏎
Line 18⏎
Line 19⏎
<EOF>
```

---
### Overwrite (`ios::trunc`)

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object with `fstream(filename, ios::in | ios::out)`
    // Note: create "test.txt" first
    fstream file("test.txt", ios::in | ios::out);
    // write lines
    for (int i = 0; i < 10; i++)
    {
        file << "Line " << i << endl;
    }
    // seek to the beginning of the file
    file.seekg(0, ios::beg);
    // print the file
    for (int i = 0; i < 10; i++)
    {
        // read a line
        string line;
        getline(file, line);
        // print the line
        cout << line << endl;
    }
    // close the file
    file.close();
```
---
``` c++
    // open again with `ios::app`
    fstream file2("test.txt", ios::in | ios::out | ios::trunc);
    // write a line
    for (int i = 10; i < 20; i++)
    {
        file2 << "Line " << i << endl;
    }
    // seek to the beginning of the file
    file2.seekg(0, ios::beg);
    // print the file
    for (int i = 0; i < 20; i++)
    {
        // read a line
        string line;
        getline(file2, line);
        // print the line
        cout << line << endl;
    }
    // close the file
    file2.close();
}
```

---
Result: `test.txt`

``` text
Line 10⏎
Line 11⏎
Line 12⏎
Line 13⏎
Line 14⏎
Line 15⏎
Line 16⏎
Line 17⏎
Line 18⏎
Line 19⏎
<EOF>
```

## Sequantial or Random Access

By default, the file is sequantial access.

`.tellp()` and `.tellg()` can tell the current position of the file.

``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object with `fstream(filename, ios::in | ios::out)`
    // Note: create "test.txt" first
    fstream file("test.txt", ios::in | ios::out);
    // write lines
    cout << file.tellp() << endl; // print the current position for `<<`
    for (int i = 0; i < 10; i++)
    {
        file << "Line " << i << endl;
        cout << file.tellp() << endl;
    }
```
---
``` c++
    // seek to the beginning of the file
    file.seekg(0, ios::beg);
    // print the file
    cout << file.tellg() << endl; // print the current position for `>>` and getline()
    for (int i = 0; i < 10; i++)
    {
        // read a line
        string line;
        getline(file, line);
        // print the line
        cout << file.tellg() << " " << line << endl;
    }
    // close the file
    file.close();
}
```

---
Result: terminal

``` console
0
7
14
21
28
35
42
49
56
63
70
0
7 Line 0
14 Line 1
21 Line 2
28 Line 3
35 Line 4
42 Line 5
49 Line 6
56 Line 7
63 Line 8
70 Line 9
```

---
### Random Access

`.seekp(pos)` and `.seekg(pos)` can seek to the position of the file.

Three reference position:
- `ios::beg`: the beginning of the file
- `ios::cur`: the current position of the file
- `ios::end`: the end of the file

---
``` c++
// include iostream & fstream for handle the file object
#include <iostream>
#include <fstream>
// short-cut of std::
using namespace std;

int main()
{
    // create a input file stream object with `fstream(filename, ios::in | ios::out)`
    // Note: create "test.txt" first
    fstream file("test.txt", ios::in | ios::out);
    // write lines
    cout << file.tellp() << endl; // print the current position for `<<`
    for (int i = 0; i < 10; i++)
    {
        file << "Line " << i << endl;
        cout << file.tellp() << endl;
    }
    // seek to the 5th line from the beginning
    file.seekp(5 * 7, ios::beg);
    cout << file.tellp() << endl; // print the current position for `<<`
    for (int i = 15; i < 20; i++)
    {
        file << "Line " << i << endl;
        cout << file.tellp() << endl;
    }
```
---
``` c++
    // seek to the beginning of the file
    file.seekg(0, ios::beg);
    // or use `file.seekg(0);`
    // print the file
    cout << file.tellg() << endl; // print the current position for `>>` and getline()
    for (int i = 0; i < 10; i++)
    {
        // seek to the 3th-previous line if read th 5th line
        if (i == 5)
        {
            file.seekg(-3 * 7, ios::cur);
        }
        // read a line
        string line;
        getline(file, line);
        // print the line
        cout << file.tellg() << " " << line << endl;
    }
    // close the file
    file.close();
}
```

---
Result: terminal

``` console
0
7
14
21
28
35
42
49
56
63
70
35
43
51
59
67
75
0
7 Line 0
14 Line 1
21 Line 2
28 Line 3
35 Line 4
21 Line 2
28 Line 3
35 Line 4
43 Line 15
51 Line 16
```

## Summary of File I/O 101

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

## Example 1: Big Real Number in Text File [[Source](./lecture13_ex1.html)]

Ref: [Lab 7: 真・大數四則運算 - Introduction to Programming (I)](https://stevenokm.github.io/i2p-nthu-math/i2p1/array_vector/lab_7_1.html)

## Example 2: Point & Triangle in Text File (function ver.) [[Source](./lecture13_ex2.html)]

## Example 3: Vector & Matrix in Binary File (function ver.) [[Source](./lecture13_ex3.html)]

## Pratices

- Read & Write Point & Triangle in Binary File
- Read & Write Vector & Matrix in CSV format
  - Seprator column by `,`
  - Seprator row by `\n`
