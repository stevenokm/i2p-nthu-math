<!---
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
--->

# Introduction to Object Oriented Programming & Design

> Slides version: [lecture7_slides.html](./lecture7_slides.html)
> Website version: [lecture7.html](./lecture7.html)

- What is Object Oriented Programming?
* What is Object Oriented Analysis and Design?
* Object Oriented Analysis
  - Example: Calculator
    - Use cases
    - Object models
---
* Object Oriented Design
  - Example: Calculator
    - System Design
    - Object Design
* Object Oriented Implementation
  - Example: Calculator
* Summary
* Pratices

## What is Object Oriented Programming?

Example: Calculator

|       |       |       |       |
| :---: | :---: | :---: | :---: |
|   C   |   ±   |   %   |   /   |
|   7   |   8   |   9   |   *   |
|   4   |   5   |   6   |   -   |
|   1   |   2   |   3   |   +   |
|   0   |       |   .   |   =   |

---

A calculator consists of a set of buttons, each of which has following functions:
- Numbers: `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`, `0`
- Operations: `+`, `-`, `*`, `/`
- Symbols: ±(`p`lusminus), `%`, `.`
- Function: `=`, `C`(lear)

---

So, we can model the calculator as a class. For example:

``` c++
class Button
{
    // ...
};
class Calc_Controller
{
    // ...
};
class Calculator
{
    // ...
};
```

But, how?

## What is Object Oriented Analysis and Design?

[Object-oriented analysis and design - Wikipedia](https://en.wikipedia.org/wiki/Object-oriented_analysis_and_design)

> Object-oriented analysis and design (OOAD) is a technical approach for analyzing and designing an application, system, or business by applying object-oriented programming, as well as using visual modeling throughout the software development process to guide stakeholder communication and product quality.

## Object Oriented Analysis

First, we need to review the use cases and list the object models.

### Use case: Calculator
- A calculator consists of a set of buttons, each of which has following functions:
   - Numbers: `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`, `0`
   - Operations: `+`, `-`, `*`, `/`
   - Symbols: ±(`p`lusminus), `%`, `.`
   - Function: `=`, `C`(lear)

---
1. User want to type in a number, user need to press number buttons or `.`, from left to right
   1. If the number is a percentage, press `%` after finish typing a number
   2. If the number is a negative number, press `±` after finish typing a number
   3. If the typed number is wrong, press `C` to clear the number
2. After finish typing a number, user need to press an operation button
3. perform the previous operation with the current result and the typed number
   1. If the typed number is the first number, set the result with the typed number, as the same as the user press `=` in 2.
4. Do 1. to 3. until user press `=`

---
### Object models: Calculator

Next, we need to list the objects and their attributes.

Calculator:
- result: number
- buttons:
  - Numbers: `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`, `0`
  - Operations: `+`, `-`, `*`, `/`
  - Symbols: ±(`p`lusminus), `%`, `.`
  - Function: `=`, `C`(lear)
---
- controller
  - a button is pressed
  - a number is typed
    - `C`lear is pressed
    - `±` is pressed
    - `%` is pressed
    - `.` is pressed
  - an operation is pressed
  - `=` is pressed

## Object Oriented Design

After we have the object models, we can design the system and the objects.

### System Design

Calculator:
- input: buttons
- output: result
- status: result, controller, buttons

---
Use cases:
- send which button is pressed to controller
- send result to controller as the input of previous operation
- contoller will update the result of the calculator with the input number, operation, and the previous result


---
### Object Design

Botton:
- identify which button is pressed
- send which button is pressed

---
Controller 
- translate the pressed buttons to the corresponding actions:
  - a number is typed
    - `C`lear is pressed
    - `±` is pressed
    - `%` is pressed
  - an operation is pressed
  - `=` is pressed
- get the previous result
- send the result to the calculator

## Object Oriented Implementation

Finally, we can implement the system and the objects.

### Botton

``` c++
class Button
{
protected:
    char symbol;

public:
    Button(char arg_btn_char)
        : symbol(arg_btn_char)
    {
    }
    virtual char press() const // polymorphism, will discuss in lecture 11
    {
        return '\0';
    }
};
```
---
``` c++
class Num_Button : public Button // inherits from Button, will discuss in next lecture
{
public:
    Num_Button(char arg_btn_char = '\0') : Button(arg_btn_char)
    {
        // ...
    }
    char press() const
    {
        return symbol;
    }
};
class Op_Button : public Button
{
public:
    Op_Button(char arg_btn_char = '\0') : Button(arg_btn_char)
    {
        // ...
    }
    char press() const
    {
        return symbol;
    }
};
```
---
``` c++
class Sym_Button : public Button
{
public:
    Sym_Button(char arg_btn_char = '\0') : Button(arg_btn_char)
    {
        // ...
    }
    char press() const
    {
        return symbol;
    }
};
class Func_button : public Button
{
public:
    Func_button(char arg_btn_char = '\0') : Button(arg_btn_char)
    {
        // ...
    }
    char press() const
    {
        return symbol;
    }
};
```
---
### Controller

``` c++
class Calc_Controller
{
private:
    int status; // 0 = init, 1 = type num, 2 = press op or assign
    char next_op;
    char curr_op;
    bool decimal_pressed;
    double type_num;
    bool minus_pressed;
    int decimal_offset;
```
---
``` c++
public:
    Calc_Controller()
        : status(0), next_op('='), curr_op('='), decimal_pressed(false),
          type_num(0), minus_pressed(false), decimal_offset(1)
    {
    }
    void button_pressed(Button &arg_btn)
    {
        switch (status)
        {
        case 0:
            if (typeid(arg_btn) == typeid(Num_Button))
            {
                status = 1;
                type_num = arg_btn.press() - '0';
            }
            else if (typeid(arg_btn) == typeid(Op_Button))
            {
                status = 2;
                next_op = arg_btn.press();
            }
```
---
``` c++
            else if (typeid(arg_btn) == typeid(Sym_Button))
            {
                status = 1;
                switch (arg_btn.press())
                {
                case '.':
                    decimal_pressed = true;
                    break;
                case 'p':
                    minus_pressed = true;
                    break;
                default:
                    break;
                }
            }
            else if (typeid(arg_btn) == typeid(Func_button))
            {
                status = 0;
                next_op = '=';
                arg_btn.press();
            }
            break;
```
---
``` c++
        case 1:
            if (typeid(arg_btn) == typeid(Num_Button))
            {
                if (decimal_pressed)
                {
                    decimal_offset *= 10;
                }
                type_num *= 10;
                type_num += arg_btn.press() - '0';
            }
            else if (typeid(arg_btn) == typeid(Op_Button))
            {
                status = 2;
                curr_op = next_op;
                next_op = arg_btn.press();
                type_num = type_num * (minus_pressed ? -1 : 1) / decimal_offset;
            }
```
---
``` c++
            else if (typeid(arg_btn) == typeid(Sym_Button))
            {
                switch (arg_btn.press())
                {
                case '.':
                    decimal_pressed = true;
                    break;
                case 'p':
                    minus_pressed = !minus_pressed;
                    break;
                case '%':
                    type_num = type_num * 0.01;
                    break;
                default:
                    break;
                }
            }
            else if (typeid(arg_btn) == typeid(Func_button))
            {
                switch (arg_btn.press())
                {
                case 'c':
                    type_num = 0;
                    break;
                case '=':
                    curr_op = next_op;
                    next_op = arg_btn.press();
                    status = 2;
                    type_num = type_num * (minus_pressed ? -1 : 1) / decimal_offset;
                }
            }
            break;
```
---
``` c++
        case 2:
            if (typeid(arg_btn) == typeid(Num_Button))
            {
                status = 1;
                type_num = arg_btn.press() - '0';
            }
            else if (typeid(arg_btn) == typeid(Op_Button))
            {
                next_op = arg_btn.press();
            }
            else if (typeid(arg_btn) == typeid(Sym_Button))
            {
                status = 1;
                switch (arg_btn.press())
                {
                case '.':
                    decimal_pressed = true;
                    break;
                case 'p':
                    minus_pressed = !minus_pressed;
                    break;
                case '%':
                    type_num = type_num * 0.01;
                    break;
                default:
                    break;
                }
            }
```
---
``` c++
            else if (typeid(arg_btn) == typeid(Func_button))
            {
                switch (arg_btn.press())
                {
                case 'c':
                    type_num = 0;
                    status = 0;
                    curr_op = '=';
                    next_op = '=';
                    break;
                case '=':
                    curr_op = '=';
                    next_op = '=';
                    break;
                }
            }
            break;
        }
    }
```
---
``` c++
    double update_result(const double &arg_result)
    {
        switch (status)
        {
        case 0:
            return arg_result;
        case 1:
            return arg_result;
        case 2:
            switch (curr_op)
            {
            case '+':
                return arg_result + type_num;
            case '-':
                return arg_result - type_num;
            case '*':
                return arg_result * type_num;
            case '/':
                return arg_result / type_num;
            case '=':
                return type_num;
            default:
                return arg_result;
            }
        }
        return arg_result;
    }
};
```

---
### Calculator

``` c++
class Calculator
{
private:
    double result;
    Calc_Controller controller;
    Num_Button num_buttons[10];
    Op_Button op_buttons[4];
    Sym_Button sym_buttons[3];
    Func_button func_buttons[2];
    void _run()
    {
        controller.button_pressed(num_buttons[1]); // 1
        result = controller.update_result(result);
        controller.button_pressed(op_buttons[0]); // +
        result = controller.update_result(result);
        controller.button_pressed(num_buttons[2]); // 2
        result = controller.update_result(result);
        controller.button_pressed(func_buttons[1]); // =
        result = controller.update_result(result);
    }
```
---
``` c++
public:
    Calculator() // like we turn on a calculator
        : result(0.0), controller()
    {
        // init num_buttons
        for (int i = 0; i < 10; i++)
        {
            num_buttons[i] = Num_Button(i + '0');
        }
        // init op_buttons
        op_buttons[0] = Op_Button('+');
        op_buttons[1] = Op_Button('-');
        op_buttons[2] = Op_Button('*');
        op_buttons[3] = Op_Button('/');
        // init sym_buttons
        sym_buttons[0] = Sym_Button('.');
        sym_buttons[1] = Sym_Button('p');
        sym_buttons[2] = Sym_Button('%');
        // init func_buttons
        func_buttons[0] = Func_button('C');
        func_buttons[1] = Func_button('=');
        _run();
    }
    ~Calculator() // like we turn off a calculator
    {
    }
};

int main()
{
    Calculator calc;
    return 0;
}
```

## Summary

4 steps to perform object-oriented programming:

0. Define use cases
1. Define objects by use cases
2. Define whole system by objects
3. Detail define objects and their properties 
4. Implement objects and system

## Pratices

Use the workflow above to implement the following problems:

1. Elevator system
2. Basketball game
3. Closet