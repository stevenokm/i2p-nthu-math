# Midterm Project: Big Positive Real Number Calculator

## Midterm-1: Big Positive Real Number in Decimal Point Format (40%)

* Inputs:
  1. Input a big positive real number in decimal point format, one line for one number.
     1. digits before and after the decimal point are at most 9 digits, separated by a point character `.`.
  2. Input a operator, one line for one operator:
     1. `+`: add
     2. `*`: multiply
  3. The input is interleaved, one line for one number and one line for one operator after the number.
  4. Input <kbd>Ctrl</kbd>+<kbd>D</kbd> to finish the input.
     * Windows: <kbd>Ctrl</kbd>+<kbd>Z</kbd> (will show `^Z` on the screen) then <kbd>Enter</kbd> (`⏎` in Format) to finish the input.
* Outputs: 
  1. The calculation result
     1. The result is shown in decimal point format, with at most 18 digits before the decimal point, and 9 digits after the decimal point ([rounding toward zero, truncate](https://en.wikipedia.org/wiki/Rounding#Round_half_toward_zero)).
     2. The format please refer to the [Format](#format) section.
* File name: `midterm-1_<student_id>.cpp` (e.g. `midterm-1_106062802.cpp`)

* The program will not have any user prompts, only print the result.
* The program does not need to handle invalid inputs.
* The program should be finished within 10 seconds. Any test cases will garuntee the program is finished within 10 seconds.

## Format

```text
<before dec 1>.<after dec 1>⏎
<op 1>⏎
<before dec 2>.<after dec 2>⏎
<op 2>⏎
...
<before dec n-1>.<after dec n-1>⏎
<op n-1>⏎
<before dec n>.<after dec n>⏎
^Z⏎
<before dec result>.<after dec result>
```

## Example

```console
$ ./a.out
1.0⏎
^Z⏎
1.000000000
$ ./a.out
0.2⏎
^Z⏎
0.200000000
$ ./a.out
1.0⏎
+⏎
2.0⏎
+
3.0⏎
*⏎
4.3⏎
^Z⏎
25.800000000
$ ./a.out
1.000000001⏎
+⏎
2.000000002⏎
^Z⏎
3.000000003
$ ./a.out
123456789.123456789⏎
+⏎
987654321.987654321⏎
^Z⏎
1111111111.111111110
$ ./a.out
1.000000001⏎
*⏎
2.000000002⏎
^Z⏎
2.000000004
$ ./a.out
123456789.123456789⏎
*⏎
987654321.987654321⏎
^Z⏎
121932631356500531.347203169
```

## Reference
* [Big Number Calculator](https://www.calculator.net/big-number-calculator.html)

## Pseudo Code

```c++
{{#include midterm-1_pseudo.cpp}}
```

## TA Version Code

``` c++
{{#include midterm-1_TA.cpp}}
```