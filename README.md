# C++ Calculator

A command-line calculator that I am building in C++ while learning the language.

I started this project with basic arithmetic operations and gradually expanded it
into an expression-based calculator. The main goal of this project is not just to
make a calculator, but to understand how things like parsing, vectors, functions,
and operator precedence actually work.

## Features

- Addition
- Subtraction
- Multiplication
- Division
- Decimal numbers
- Expression parsing
- Support for spaces in expressions
- Operator precedence
- Parentheses
- Nested parentheses
- Division by zero handling
- Invalid parenthesis detection

## How It Works

The calculator takes an expression as input and separates it into two parts:

- Numbers
- Operators

For example:

10 + 5 * 2 - 4 / 2

is separated into:
Numbers:
10  5  2  4  2

Operators:
+  *  -  /

The calculator then follows operator precedence.
First it calculates:
* and /

and then:
+ and -

So:
10 + 5 * 2 - 4 / 2

becomes:
10 + 10 - 2

and finally:
18

The calculator also supports parentheses.

Parentheses are evaluated before the rest of the expression.

For example:

10 + (5 * 2) - 3

The expression inside the parentheses is calculated first:

10 + 10 - 3

Result:

17

Nested parentheses are handled using a stack to find matching pairs.

## Technologies Used

- C++
- STL Vectors
- STL Stack
- Strings
- Functions
- References
- Basic expression parsing

## How To Run

Compile the program using:
g++ calculator.cpp -o calculator

Then run:
./calculator

Example
Welcome to the Calculator
1. Arithmetic Operations
0. Exit
Enter your Choice: 1

Enter the expression: 10 + 5 * 2 - 4 / 2

18

## What I Learned

While building this project, I have learned and used:
- Functions and function prototypes
- Strings and character traversal
- Vectors
- Parsing user input
- stoi() and stod()
- References
- Pointers
- vector.erase()
- Iterators and vector.begin()
- Operator precedence
- Parentheses handling
- Nested parentheses
- STL stack
- Git and GitHub

## Current Status

The calculator currently supports basic arithmetic, decimal numbers,
operator precedence, parentheses, and nested parentheses.

Nested parentheses are handled using a stack to find matching pairs.

The next step is improving input validation so that malformed
expressions are handled properly.

## Future Plans

I am planning to keep expanding this project step by step.
- Handle malformed expressions
- Add scientific operations
- Add better input validation
- Add a quadratic equation solver
- Add graphing
- Improve the expression parser

## About This Project

This is one of my first proper C++ projects and I am building it while learning
C++ from the basics.
Instead of trying to build everything at once, I am adding features one by one
and understanding how each part works.
