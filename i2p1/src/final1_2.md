## Final Exam 1-2: Calculator (20%)

* Inputs:
  1. The expression to be evaluated.
     1. Each operand and operator is separated line by line.
     2. The operands are in `double` format.
     3. The operators are in `std::string` format.
     4. The expressiion is ended by `=`.
  2. The valid operators are `+`, `-`, `*`, `/`
     1. The `/` opeartor is only valid if the second operand is not zero.
* Outputs: 
  1. The list of operands and operators in the expression.
     1. The format is shown below.
     2. The operands are in defualt `double` format in `std::cout`.
  2. The result of the expression.
     1. The calculation is done line by line.
     2. The result is in defualt `double` format.
  3. If the expression is invalid, the output is `Invalid Expression` and exit.
     1. If the number of operands is not equal to the number of operators plus one.
     2. The invalid operator occurs.
* File name: `final1_2_<student_id>.cpp` (e.g. `final1_2_106062802.cpp`)

Notice：
* The program will not print any user prompts.
* The program should use functions to process the input and output.
* The program should be finished within 30 seconds. Any test cases will garuntee the program is finished within 30 second

## Format

```text
<operand_1>⏎
<operator_1>⏎
...
<operand_n>⏎
=⏎
Operand: <operand_1> ... <operand_n>
Operator: <operator_1> ... <operator_n-1>
Result: <result>
```

## Example

``` console
$ ./a.out⏎
0.0⏎
=⏎
Operands: 0
Operators:
Result: 0
$ ./a.out⏎
0.0⏎
/⏎
1.0⏎
=⏎
Operands: 0 1
Operators: /
Result: 0
$ ./a.out⏎
1.0⏎
*⏎
2.0⏎
+⏎
3.0⏎
-⏎
4.0⏎
=⏎
Operands: 1 2 3 4
Operators: * + -
Result: 1
$ ./a.out⏎
-1.234e-5⏎
*⏎
-5.678e-6⏎
+⏎
9.876e-7⏎
-⏎
5.432e-8⏎
=⏎
Operands: -1.234e-05 -5.678e-06 9.876e-07 5.432e-08
Operators: * + -
Result: 9.3335e-07
$ ./a.out⏎
-1.234e-5⏎
*⏎
-5.678e-6⏎
+⏎
9.876e-7⏎
5.432e-8⏎
=⏎
Invalid Expression
$ ./a.out⏎
-1.234e-5⏎
*⏎
-5.678e-6⏎
+⏎
9.876e-7⏎
-⏎
=⏎
Invalid Expression
$ ./a.out⏎
-1.234e-5⏎
*⏎
-5.678e-6⏎
+⏎
9.876e-7⏎
%⏎
5.432e-8⏎
=⏎
Invalid Expression
$ ./a.out⏎
-1.234e-5⏎
*⏎
-5.678e-6⏎
+⏎
9.876e-7⏎
/⏎
0.0⏎
=⏎
Invalid Expression
```

## Pseudo code

``` c++
{{#include final1_2_pseudo.cpp}}
```

Reference Code:

``` c++
{{#include final1_2_TA.cpp}}
```