# Midterm: Simpilified Big Number Calculator (extra homework, 15% grade)

* Inputs:
  1. The function to be calculated, listed below:
     1. Display two nubmers only (`display only`) (50%, with exceptions handled)
     2. Plus (`+`) (30%)
     3. Greatest Common Divider (`gcd`) (20%)
  2. Two non-negative integers \\( a, b \\). Two numbers will not more than 50 digits.
  3. If the calculated function is greatest common divider, \\( a, b \\) should be natural numbers (自然數), otherwise, the two numbers should be integer.
* Outputs: 
  1. The calculated function. (i.e. `display only`, `+`, `gcd`)
  2. Two nubmers. \\( a, b \\)
  3. The corrsponding calculation result.
* File name: `midterm_1_<student_id>.cpp` (e.g. `midterm_1_106062802.cpp`)

* The program should inform the user to select the function and type the numbers, \\( a, b \\) to be calculated. Output the typed numbers and the calculation result of the selected function.
* The program supports the calculation repeatly. User can select the function `0` to exit the program.
* The program should check user's input, output the error message and inform the user to input again if the input is invalid. If the input is invalid, the program should inform the user with `Invalid input: <the wrong input>` right after the input and inform the user to type the same input again.
* The format of the error message is shown in the [Exception](./midterm.html#exceptions) section.
* The program should assume the user's input is any non-space character (i.e. not <kbd>space</kbd>, <kbd>tab</kbd>) string.
* The program should be finished within 30 seconds. Any test cases will garuntee the program is finished within 30 seconds.

## Format

```text
Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: <1-3>⏎
You selected: <display only,+,gcd>
Input integer number (a): <a>⏎
Input integer number (b): <b>⏎
(a) = <a>
(b) = <b>
(a) <+, gcd> (b) = <result>
```

## Example

### Display

```console
$ ./a.out
Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 1⏎
You selected: display only
Input integer number (a): 0000000000000⏎
Input integer number (b): 00000001⏎
(a) = 0
(b) = 1

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 1⏎
You selected: display only
Input integer number (a): 123456789012345678901234567890⏎
Input integer number (b): 987654321098765432109876543210⏎
(a) = 123456789012345678901234567890
(b) = 987654321098765432109876543210

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 1⏎
You selected: display only
Input integer number (a): 12345678901234567890123456789012345678901234567890⏎
Input integer number (b): 98765432109876543210987654321098765432109876543210⏎
(a) = 12345678901234567890123456789012345678901234567890
(b) = 98765432109876543210987654321098765432109876543210

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 0⏎

$
```

### Plus 

```console
$ ./a.out
Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 2⏎
You selected: +
Input integer number (a): 111⏎
Input integer number (b): 222⏎
(a) = 111
(b) = 222
(a) + (b) = 333

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 2⏎
You selected: +
Input integer number (a): 123⏎
Input integer number (b): 987⏎
(a) = 123
(b) = 987
(a) + (b) = 1110

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 2⏎
You selected: +
Input integer number (a): 123456789012345678901234567890⏎
Input integer number (b): 987654321098765432109876543210⏎
(a) = 123456789012345678901234567890
(b) = 987654321098765432109876543210
(a) + (b) = 1111111110111111111011111111100

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 2⏎
You selected: +
Input integer number (a): 12345678901234567890123456789012345678901234567890⏎
Input integer number (b): 98765432109876543210987654321098765432109876543210⏎
(a) = 12345678901234567890123456789012345678901234567890
(b) = 98765432109876543210987654321098765432109876543210
(a) + (b) = 111111111011111111101111111110111111111011111111100

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 0⏎

$
```

### Greatest Common Divider

```console
$ ./a.out
Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 3⏎
You selected: gcd
Input integer number (a): 3⏎
Input integer number (b): 27⏎
(a) = 3
(b) = 27
(a) gcd (b) = 3

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 3⏎
You selected: gcd
Input integer number (a): 47⏎
Input integer number (b): 7⏎
(a) = 47
(b) = 7
(a) gcd (b) = 1

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 3⏎
You selected: gcd
Input integer number (a): 123492001107001353123492001107001353⏎
Input integer number (b): 99396000891001089099396000891001089⏎
(a) = 123492001107001353123492001107001353
(b) = 99396000891001089099396000891001089
(a) gcd (b) = 3012000027000033003012000027000033

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 3⏎
You selected: gcd
Input integer number (a): 7369130657357778596659⏎
Input integer number (b): 2305843009213693951⏎
(a) = 7369130657357778596659
(b) = 2305843009213693951
(a) gcd (b) = 1

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 3⏎
You selected: gcd
Input integer number (a): 2305843009213693951⏎
Input integer number (b): 7369130657357778596659⏎
(a) = 2305843009213693951
(b) = 7369130657357778596659
(a) gcd (b) = 1

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 3⏎
You selected: gcd
Input integer number (a): 12345678901234567890123456789012345678901234567890⏎
Input integer number (b): 1234567890123456789012345678901234567890123456789⏎
(a) = 12345678901234567890123456789012345678901234567890
(b) = 1234567890123456789012345678901234567890123456789
(a) gcd (b) = 1234567890123456789012345678901234567890123456789

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 3⏎
You selected: gcd
Input integer number (a): 987654321098765432109876543210⏎
Input integer number (b): 123456789012345678901234567890⏎
(a) = 987654321098765432109876543210
(b) = 123456789012345678901234567890
(a) gcd (b) = 9000000000900000000090

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 0⏎

$
```

### Exceptions

```console
$ ./a.out
Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: +⏎
Invalid input: +

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 00000001⏎
Invalid input: 00000001

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: -2⏎
Invalid input: -2

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 4⏎
Invalid input: 4

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 1⏎
You selected: display only
Input integer number (a): +_)(*(&#$)(*@()*@!⏎
Invalid input: +_)(*(&#$)(*@()*@!

Input integer number (a): -0.0⏎
Invalid input: -0.0

Input integer number (a): 123⏎
Input integer number (b): 0.1⏎
Invalid input: 0.1

Input integer number (b): 0⏎
(a) = 123
(b) = 0

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 3⏎
You selected: gcd
Input integer number (a): 0⏎
Invalid input: 0

Input integer number (a): 987654321098765432109876543210⏎
Input integer number (b): 0⏎
Invalid input: 0

Input integer number (b): 987654321098765432109876543210⏎
(a) = 987654321098765432109876543210
(b) = 987654321098765432109876543210
(a) gcd (b) = 987654321098765432109876543210

Big number calculator
1) display only
2) plus (+)
3) greatest common divider (gcd)
0) exit
Please select the operator: 0⏎

$
```

## Pseudo code

``` c++
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    vector<int> num_a, num_b;
    string input_buffer;
    int select_function;

    while (true)
    {
        // select function
        cout << "Big number calculator" << endl
             << "1) display only" << endl
             << "2) plus (+)" << endl
             << "3) greatest common divider (gcd)" << endl
             << "0) exit" << endl
             << "Please select the operator: ";
        cin >> input_buffer;

        // start of check selected function is valid

        // end of check selected function is valid
        
        // start of inform selected function

        // end of inform selected function

        // clear buffer
        input_buffer.clear();

        // input number (a)
  
            // check if input is valid
            // if not valid, inform user and continue to input

            // convert string to int

            // remove leading zeros

            // check if input is valid for gcd

        // clear buffer
        input_buffer.clear();

        // input number (b)

            // check if input is valid
            // if not valid, inform user and continue to input

            // convert string to int

            // remove leading zeros

            // check if input is valid for gcd


        // clear buffer
        input_buffer.clear();

        // print number (a) (b)

        // calculation

            // plus

            // gcd

                // compaire a and b

                // if a == b, break

                // if a > b

                    // a = a - b

                // if a < b

                    // b = b - a


                // remove leading zeros


                // if a == 0, b is the result

                // else if b == 0, a is the result



        // clean up (a) and (b)

    }
}
```

## C++ References

1. unzip `html-book-20201016.zip`.
2. open `html-book-20201016/reference/en/index.html`.
3. Find what you want.

Reference Code:

``` c++
{{#include midterm.cpp}}
```
