# Final Exam 2: Geometry Object Computer

## Final Exam 2-1: Display Geometry Objects (30%)

* Inputs: The gemoetry object.
  1. The first line of the input contains the type of the object and the number of points.
     1. The type of the object is one of the following:
        1. `point`: a point.
        2. `circle`: a circle, which is defined by two points, center of the circle and a point on the circle.
        3. `triangle`: a triangle, which is defined by three points.
        4. `rectangle`: a rectangle, which is defined by two points.
     2. The number of points is an `int` between \(1\) and \(100\).
  2. The remaining lines of the input contain the coordinates of the points.
     1. The coordinates of the points are `double` between \(-100\) and \(100\).
* Outputs: 
  1. The type of the object, the number of points, and the coordinates of the points.
     1. The format is shown below.
     2. The coordinates of the points are in defualt `double` format in `std::cout`.
  2. If the object is invalid, the output is `Invalid Object` and exit.
     1. If the coordinates of the points are out of the range.
     2. If the number of points is not equal to the defined number.
     3. If the type of the object is not one of the defined types.
* File name: `final2_1_<student_id>.cpp` (e.g. `final2_1_106062802.cpp`)

Notice：
* The program will not print any user prompts.
* The program should use functions to process the input and output.
* The program should define structures to store the data of the objects.
* The program should be finished within 30 seconds. Any test cases will garuntee the program is finished within 30 second

## Format

```text
<type> <number_of_points>⏎
<x_1> <y_1>⏎
...
<x_n> <y_n>⏎
Object Type: <type>
Number of Points: <number_of_points>
Points: (<x_1>, <y_1>), ..., (<x_n>, <y_n>)
```

## Example

``` console
$ ./a.out⏎
point 1⏎
0.0 0.0⏎
Object Type: point
Number of Points: 1
Points: (0, 0)
$ ./a.out⏎
circle 2⏎
0.0 0.0⏎
1.0 1.0⏎
Object Type: circle
Number of Points: 2
Point: (0, 0), (1, 1)
$ ./a.out⏎
triangle 3⏎
0.0 0.0⏎
2.0 0.0⏎
1.0 1.0⏎
Object Type: triangle
Number of Points: 3
Point: (0, 0), (2, 0), (1, 1)
$ ./a.out⏎
rectangle 2⏎
0.0 0.0⏎
1.0 2.0⏎
Object Type: rectangle
Number of Points: 2
Point: (0, 0), (1, 2)
$ ./a.out⏎
rectangle 3⏎
Invalid Object
$ ./a.out⏎
circle -1⏎
Invalid Object
$ ./a.out⏎
circle 2⏎
-100.1 -100.1⏎
1.0 1.0⏎
Invalid Object
$ ./a.out⏎
point 101⏎
Invalid Object
$ ./a.out⏎
square 2⏎
Invalid Object
```

## Pseudo code

``` c++
{{#include final2_1_pseudo.cpp}}
```

Reference Code:

``` c++
{{#include final2_1_TA.cpp}}
```