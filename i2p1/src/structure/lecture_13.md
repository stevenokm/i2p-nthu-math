# Lecture 13: Structure (1)

## Why Structure?

寫 structure 好處
1. 可以讓多個型態的資料放在一起，視為一個單一的型態，並且用一個變數來存取。
2. 可以讓變數賦予更多的意義，以下內容會介紹。
3. 讓 function 回傳多個值，因為 structure 可以包涵多個不同型態的資料，並視為一個單一的型態。

## Structure Definition

``` c++
struct <name>
{
    <type> <member>;
    <type> <member>;
    ...
};
```

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

## Structure Usage

如何使用 structure？

初始化的時候可以使用 `{}` 來初始化。若有 structure 內有陣列的話，則需要透過多層的 `{}` 來初始化。

要使用的時候可以透過 `.` 運算子來存取 structure 裡頭的資料，如下所示：

Example: [Structures in C - GeeksforGeeks](https://www.geeksforgeeks.org/structures-c/)

``` c++
#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    struct Point p1 = {0, 1};

    // Accessing members of point p1
    p1.x = 20;
    std::cout << "x = " << p1.x << ", y = " << p1.y << std::endl;

    return 0;
}
```

Array example:

``` c++
#include <iostream>

struct Triangle
{
    int x[3];
    int y[3];
};

struct Point
{
    int x, y;
};

int main()
{
    struct Point p1 = {0, 1};
    struct Triangle t1 = {{0, 1, 2}, {0, 1, 2}};

    // Accessing members of point p1
    p1.x = 20;
    std::cout << "x = " << p1.x << ", y = " << p1.y << std::endl;

    // Accessing members of triangle t1
    t1.x[0] = 20;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "x[" << i << "] = " << t1.x[i]
                  << ", y[" << i << "] = " << t1.y[i] << std::endl;
    }
    return 0;
}
```

同時 structure 也可以作為 array 的元素，如下所示：

Reference: [Structures in C - GeeksforGeeks](https://www.geeksforgeeks.org/structures-c/)

``` c++
#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    // Create an array of structures
    struct Point arr[10];

    // Access array members
    arr[0].x = 10;
    arr[0].y = 20;

    std::cout << arr[0].x << " " << arr[0].y << std::endl;
    return 0;
}
```

若為了程式碼可讀性，可以寫 function 使各個 structure 內的 member 各自分開初始化。
並可以使用 `memset()` 來初始化 array 宣告的 member 的值。

``` c++
#include <iostream>
#include <cstring> // For memset()

struct Point
{
    int x, y;
    int metadata[10];
};

void init(struct Point p[], int size)
{
    for (int i = 0; i < size; i++)
    {
        p[i].x = 1;
        p[i].y = 2;
        memset(p[i].metadata, 0, sizeof(int) * 10); // Initialize metadata to 0
        // Note: memset() can only initialize with 0 or '\0'
    }
}

int main()
{
    // Create an array of structures
    struct Point arr[10];

    // Initialize the array
    init(arr, 10);

    // Access array members
    arr[0].x = 10;
    arr[0].y = 20;

    std::cout << arr[0].x << " " << arr[0].y << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i].metadata[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## Structure as a Type

在使用 structure 除了用 `struct <name>` 之外，也可以將 structure 宣告為 type 來使用。

``` c++
typedef struct <struct_name>
{
    <type> <member>;
    <type> <member>;
    ...
} <type_name>;
```

Example:

``` c++
#include <iostream>

typedef struct Triangle_struct
{
    int x[3];
    int y[3];
} Triangle;

typedef struct Point_struct
{
    int x, y;
} Point;

int main()
{
    Point p1 = {0, 1};
    Triangle t1 = {{0, 1, 2}, {0, 1, 2}};

    // Accessing members of point p1
    p1.x = 20;
    std::cout << "x = " << p1.x << ", y = " << p1.y << std::endl;

    // Accessing members of triangle t1
    t1.x[0] = 20;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "x[" << i << "] = " << t1.x[i]
                  << ", y[" << i << "] = " << t1.y[i] << std::endl;
    }
    return 0;
}
```

## Structure example: Complex Numbers

``` c++
#include <iostream>
#include <cctype> // isdigit()

using namespace std;

typedef struct Complex
{
    int real;
    int imag;
} Complex;

Complex parse_complex_number(const char input_buffer[])
{
    Complex complex_number;

    complex_number.real = 0;
    complex_number.imag = 0;

    // Parse real part
    int i = 0, real_sign = 1;
    if (input_buffer[i] == '-')
    {
        real_sign = -1;
        i++;
    }
    else if (input_buffer[i] == '+')
    {
        i++;
    }
    else
    {
        complex_number.real = input_buffer[i] - '0';
        i++;
    }
    while (isdigit(input_buffer[i]))
    {
        complex_number.real = 10 * complex_number.real + (input_buffer[i] - '0');
        i++;
    }
    complex_number.real *= real_sign;

    // Skip the '+'
    if (input_buffer[i] == '+')
    {
        i++;
    }

    // Parse imaginary part
    int imag_sign = 1;
    if (input_buffer[i] == '-')
    {
        imag_sign = -1;
        i++;
    }
    else if (input_buffer[i] == '+')
    {
        i++;
    }
    else
    {
        complex_number.imag = input_buffer[i] - '0';
        i++;
    }
    while (isdigit(input_buffer[i]))
    {
        complex_number.imag = 10 * complex_number.imag + (input_buffer[i] - '0');
        i++;
    }
    if (input_buffer[i] == 'i')
    {
        i++;
    }
    complex_number.imag *= imag_sign;

    // check if there is any extra characters
    if (input_buffer[i] != '\0')
    {
        cout << "Error: Invalid input" << endl;
        exit(1);
    }

    // Return the complex number
    return complex_number;
}

void print_complex_number(Complex &complex_number)
{
    cout << complex_number.real << " + " << complex_number.imag << "i" << endl;
}

void clean_up_input_buffer(char input_buffer[])
{
    for (int i = 0; input_buffer[i] != '\0'; i++)
    {
        input_buffer[i] = '\0';
    }
}

int main()
{
    char input_buffer[10000 + 1]; // + 1 for the last '\0'
    Complex a, b;

    cout << "Input a complex number (a) in (+|-)[0-9]+(+|-)[0-9]i : ";
    cin >> input_buffer;

    a = parse_complex_number(input_buffer);

    clean_up_input_buffer(input_buffer);

    cout << "(a) = ";
    print_complex_number(a);

    cout << "Input a complex number (b) in (+|-)[0-9]+(+|-)[0-9]i : ";
    cin >> input_buffer;

    b = parse_complex_number(input_buffer);

    clean_up_input_buffer(input_buffer);

    cout << "(b) = ";
    print_complex_number(b);

    return 0;
}
```
