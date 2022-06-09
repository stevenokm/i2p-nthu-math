## Final-2: Save Geometry Objects to Binary File (35%)

* Inputs:
  1. Read geometry objects from a input file.
     1. Please use `int main(int argc, char *argv[])` to open the input file (Ref: [One and the only: main function](https://stevenokm.github.io/i2p-nthu-math/i2p1/function/lecture_10.html#one-and-the-only-main-function).
     2. The file path of the input file is given as `argv[1]`.
  2. Read the dimensions (`dim`) of the coordinate system. The dimension is an `unsigned` between 2 and 10.
  3. Read the type of geometry object in `char` format with the following types:
     1. `l` for line
     2. `t` for triangle
     3. `p` for polygon
  4. Read the number of vertices in `unsigned` format for each type of geometry object as shown above.
     1. line: 2
     2. triangle: 3
     3. polygon: \\(n \in Z^+, n \ge 3\\)
  5. Read the vertices with `dim` coordinates in `double` format.
     1. line: `<double 1><double 2>...<double dim><double 1><double 2>...<double dim>`
     2. triangle: `<double 1><double 2>...<double dim><double 1><double 2>...<double dim><double 1><double 2>...<double dim>`
     3. polygon: `<double 1><double 2>...<double dim><double 1><double 2>...<double dim>...`
* Outputs: 
  1. Write geometry objects to a output file.
     1. Please use `int main(int argc, char *argv[])` to open the input file (Ref: [One and the only: main function](https://stevenokm.github.io/i2p-nthu-math/i2p1/function/lecture_10.html#one-and-the-only-main-function).
     2. The file path of the output file is given as `argv[2]`.
  2. Write the dimensions of the coordinate system.
  3. Write all geometric objects in the input, with the following information:
     1. Write the type of the object, the number of vertices, and the vertices.
        1. The format shold follow the descriptions in [Format](#format).
        2. The order of the vertices and coordinates should be the same as the input.
        3. Each coordinate should be saved with `double` format.
  4. Write the dimension and all geometric objects after the input is finished, and exit the program.
* File name: `final-2_<student_id>.cpp` (e.g. `final-2_106062802.cpp`)

* The program will not have any user prompts, only print the result.
* The program does not need to handle invalid inputs.
* The program should base on the `main` & `print_output_file` function provided in the pseudo code.
* The program should be finished within 10 seconds. Any test cases will garuntee the program is finished within 10 seconds.

## Format

### Input/Output File

```text
<dim><geometry type><n><double 1><double 2>...<double dim><double 1><double 2>...<double dim>...<EOF>
```

## Example

**Note**: For any `#` started lines are comments for human-readability. The `.bin` files do not have comments.

### `dim = 2`

#### Triangle

Input File: [`input_triangle_2d.bin`](final_data/input_triangle_2d.bin)

``` text
{{#include final_data/input_triangle_2d.bin.dump}}
```

Output File: [`output_triangle_2d.bin`](final_data/output_triangle_2d.bin)

``` text
{{#include final_data/output_triangle_2d.bin.dump}}
```

Terminal:

```console
$ ./a.out input_triangle_2d.bin output_triangle_2d.bin
{{#include final_data/output_triangle_2d.bin.dump}}
$
```

#### Line

Input File: [`input_line_2d.bin`](final_data/input_line_2d.bin)

``` text
{{#include final_data/input_line_2d.bin.dump}}
```

Output File: [`output_line_2d.bin`](final_data/output_line_2d.bin)

``` text
{{#include final_data/output_line_2d.bin.dump}}
```

Terminal:

```console
$ ./a.out input_line_2d.bin output_line_2d.bin
{{#include final_data/output_line_2d.bin.dump}}
$
```

#### Polygon

Input File: [`input_polygon_2d.bin`](final_data/input_polygon_2d.bin)

``` text
{{#include final_data/input_polygon_2d.bin.dump}}
```

Output File: [`output_polygon_2d.bin`](final_data/output_polygon_2d.bin)

``` text
{{#include final_data/output_polygon_2d.bin.dump}}
```

Terminal:

```console
$ ./a.out input_polygon_2d.bin output_polygon_2d.bin
{{#include final_data/output_polygon_2d.bin.dump}}
$
```

#### Multiple Objects

Input File: [`input_multiple_objects_2d.bin`](final_data/input_multiple_objects_2d.bin)

``` text
{{#include final_data/input_multiple_objects_2d.bin.dump}}
```

Output File: [`output_multiple_objects_2d.bin`](final_data/output_multiple_objects_2d.bin)

``` text
{{#include final_data/output_multiple_objects_2d.bin.dump}}
```

Terminal:

```console
$ ./a.out input_multiple_2d.bin output_multiple_2d.bin
{{#include final_data/output_multiple_objects_2d.bin.dump}}
$
```

### `dim = 3`

#### Triangle

Input File: [`input_triangle_3d.bin`](final_data/input_triangle_3d.bin)

``` text
{{#include final_data/input_triangle_3d.bin.dump}}
```

Output File: [`output_triangle_3d.bin`](final_data/output_triangle_3d.bin)

``` text
{{#include final_data/output_triangle_3d.bin.dump}}
```

Terminal:

```console
$ ./a.out input_triangle_3d.bin output_triangle_3d.bin
{{#include final_data/output_triangle_3d.bin.dump}}
$
```

#### Line

Input File: [`input_line_3d.bin`](final_data/input_line_3d.bin)

``` text
{{#include final_data/input_line_3d.bin.dump}}
```

Output File: [`output_line_3d.bin`](final_data/output_line_3d.bin)

``` text
{{#include final_data/output_line_3d.bin.dump}}
```

Terminal:

```console
$ ./a.out input_line_3d.bin output_line_3d.bin
{{#include final_data/output_line_3d.bin.dump}} 
$
```

#### Polygon

Input File: [`input_polygon_3d.bin`](final_data/input_polygon_3d.bin)

``` text
{{#include final_data/input_polygon_3d.bin.dump}}
```

Output File: [`output_polygon_3d.bin`](final_data/output_polygon_3d.bin)

``` text
{{#include final_data/output_polygon_3d.bin.dump}}
```

Terminal:

```console
$ ./a.out input_polygon_3d.bin output_polygon_3d.bin
{{#include final_data/output_polygon_3d.bin.dump}}
$
```

#### Multiple Objects

Input File: [`input_multiple_objects_3d.bin`](final_data/input_multiple_objects_3d.bin)

``` text
{{#include final_data/input_multiple_objects_3d.bin.dump}}
```

Output File: [`output_multiple_objects_3d.bin`](final_data/output_multiple_objects_3d.bin)

``` text
{{#include final_data/output_multiple_objects_3d.bin.dump}}
```

Terminal:

```console
$ ./a.out input_multiple_3d.bin output_multiple_3d.bin
{{#include final_data/output_multiple_objects_3d.bin.dump}}
$
```

## Pseudo Code

```c++
{{#include final-2_pseudo.cpp}}
```