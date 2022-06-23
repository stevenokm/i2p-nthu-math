# Final Project: Geometry Processing

## Final-1: Geometry Objects (50%)

* Inputs:
  1. Input the dimensions (`dim`) of the coordinate system. The dimension is an `unsigned` between 2 and 10.
  2. Input the type of geometry object, one type per line, with the following types:
     1. `l` for line
     2. `t` for triangle
     3. `p` for polygon
  3. Input the number of vertices, one number per line, for each type of geometry object as shown above.
     1. line: 2
     2. triangle: 3
     3. polygon: \\(n \in Z^+, n \ge 3\\)
  4. Input the vertices, one vertex per line, seperate by a comma (`,`), and with `dim` coordinates in `double` format.
     1. line: `<double 1>,<double 2>,...,<double dim>⏎<double 1>,<double 2>,...,<double dim>`
     2. triangle: `<double 1>,<double 2>,...,<double dim>⏎<double 1>,<double 2>,...,<double dim>⏎<double 1>,<double 2>,...,<double dim>`
     3. polygon: `<double 1>,<double 2>,...,<double dim>⏎<double 1>,<double 2>,...,<double dim>⏎...`
  5. Input <kbd>Ctrl</kbd>+<kbd>D</kbd> to finish the input.
     * Windows: <kbd>Ctrl</kbd>+<kbd>Z</kbd> (will show `^Z` on the screen) then <kbd>Enter</kbd> (`⏎` in Format) to finish the input.
* Outputs: 
  1. The dimensions of the coordinate system.
  2. All geometric objects in the input, with the following information:
     1. Display the type of the object, the number of vertices, and the vertices.
        1. The format shold follow the descriptions in [Format](#format).
        2. The order of the vertices and coordinates should be the same as the input.
        3. Each coordinate should be displayed with default `double` format.
  3. Print the dimension and all geometric objects after the input is finished, and exit the program.
* File name: `final-1_<student_id>.cpp` (e.g. `final-1_106062802.cpp`)

* The program will not have any user prompts, only print the result.
* The program does not need to handle invalid inputs.
* The program should base on the `main` function provided in the pseudo code.
* The program should be finished within 10 seconds. Any test cases will garuntee the program is finished within 10 seconds.

## Format

```text
<dim>⏎
<geometry type>⏎
n⏎
<double 1>,<double 2>,...,<double dim>⏎
<double 1>,<double 2>,...,<double dim>⏎
...
<double 1>,<double 2>,...,<double dim>⏎
<geometry type>⏎
n⏎
<double 1>,<double 2>,...,<double dim>⏎
<double 1>,<double 2>,...,<double dim>⏎
...
<double 1>,<double 2>,...,<double dim>⏎
^Z⏎
<dim>
<geometry type>
n
<double 1>,<double 2>,...,<double dim>
<double 1>,<double 2>,...,<double dim>
...
<double 1>,<double 2>,...,<double dim>
<geometry type>
n
<double 1>,<double 2>,...,<double dim>
<double 1>,<double 2>,...,<double dim>
...
<double 1>,<double 2>,...,<double dim>
```

## Example

### `dim = 2`

#### Triangle

```console
$ ./a.out
2⏎
t⏎
3⏎
1.0,2.0⏎
3.0,4.0⏎
5.0,0.0⏎
^Z⏎
2
t
3
1,2
3,4
5,0
$
```

#### Line

```console
$ ./a.out
2⏎
l⏎
2⏎
1.0,2.0⏎
3.0,4.0⏎
^Z⏎
2
l
2
1,2
3,4
$
```

#### Polygon

```console
$ ./a.out
2⏎
p⏎
5⏎
1.0,0.0⏎
2.0,1.1⏎
-3.0,-2.2⏎
4.3,2.1⏎
-1.2,3.4⏎
^Z⏎
2
p
5
1,0
2,1.1
-3,-2.2
4.3,2.1
-1.2,3.4
$
```

#### Multiple Objects

```console
$ ./a.out
2⏎
t⏎
3⏎
1.0,2.0⏎
3.0,4.0⏎
5.0,0.0⏎
l⏎
2⏎
1.0,2.0⏎
3.0,4.0⏎
p⏎
5⏎
1.0,0.0⏎
2.0,1.1⏎
-3.0,-2.2⏎
4.3,2.1⏎
-1.2,3.4⏎
^Z⏎
2
t
3
1,2
3,4
5,0
l
2
1,2
3,4
p
5
1,0
2,1.1
-3,-2.2
4.3,2.1
-1.2,3.4
$
```

### `dim = 3`

#### Triangle

```console
$ ./a.out
3⏎
t⏎
3⏎
1.0,2.0,3.0⏎
3.0,4.0,5.0⏎
5.0,0.0,1.0⏎
^Z⏎
3
t
3
1,2,3
3,4,5
5,0,1
$
```

#### Line

```console
$ ./a.out
3⏎
l⏎
2⏎
1.0,2.0,3.0⏎
3.0,4.0,5.0⏎
^Z⏎
3
l
2
1,2,3
3,4,5
$
```

#### Polygon

```console
$ ./a.out
3⏎
p⏎
5⏎
1.0,0.0,-1.0⏎
2.0,1.1,0.2⏎
-3.0,-2.2,-1.3⏎
4.3,2.1,0.1⏎
-1.2,3.4,-5.6⏎
^Z⏎
3
p
5
1,0,-1
2,1.1,0.2
-3,-2.2,-1.3
4.3,2.1,0.1
-1.2,3.4,-5.6
$
```

#### Multiple Objects

```console
$ ./a.out
3⏎
t⏎
3⏎
1.0,2.0,3.0⏎
3.0,4.0,5.0⏎
5.0,0.0,1.0⏎
l⏎
2⏎
1.0,2.0,3.0⏎
3.0,4.0,5.0⏎
p⏎
5⏎
1.0,0.0,-1.0⏎
2.0,1.1,0.2⏎
-3.0,-2.2,-1.3⏎
4.3,2.1,0.1⏎
-1.2,3.4,-5.6⏎
^Z⏎
3
t
3
1,2,3
3,4,5
5,0,1
l
2
1,2,3
3,4,5
p
5
1,0,-1
2,1.1,0.2
-3,-2.2,-1.3
4.3,2.1,0.1
-1.2,3.4,-5.6
$
```

## Pseudo Code

```c++
{{#include final-1_pseudo.cpp}}
```

## Reference Code: 

### TA

```c++
{{#include final-1_TA.cpp}}
```