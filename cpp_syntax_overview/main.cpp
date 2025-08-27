// https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58549s
//
// INDEX
// - Function: 35
// - Stream: 74
// - Initialization types: 91
// - Operators: 117
// - Flow control: 328
// - Loops: 393
// - Arrays: 438
// - Pointers: 456
// - References: 857
// - Character manipulation and strings: 920
// - Functions in Cpp: 1,000
// - Lambda funcrions: 1,055
//
#include <cmath> // For math functions
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
// fortran

/*
Statements: end in ";" -- statements are executed in order form top to bottom.
Functions: return value
Parameters: inside function

STREAM
std::cout -- printing data to the console
std::cin -- reading data from the terminal
std::cerr -- printing errors to the console
std::clog -- printing log messages to the console
std::getline -- read full line of strings (not single word)

C++ COMPONENTS
core features: built in c++ model
standard library: standar library add ons built in c++
stl: specialized standard library

C++ TYPES
- int(32 bit): represents integer numbers (whole numbers, both positive and
negative).
- double(64 bit): represents double-precision floating-point numbers,
used for high-precision real numbers.
- float(32 bit): represents single-precision
floating-point numbers, used for real numbers with less precision than double.
- char(8 bit): represents a single character (e.g., 'a', 'b', or symbols).
stored as an integer corresponding to the ascii or unicode value.
- bool(8 bit):represents a boolean value, which can either be true or false. but
only 1 bit is used logically.
- void: represents "no type" or "nothing." commonly used as a
return type for functions that do not return a value. not applicable (conceptual
type).
- auto: automatically deduces the type of a variable based on the
initializer value. depends on the deduced type.
- signed/unsigned [int/float/etc]: explicitly declare if variable is
signed/unsigned.
- const [int/float/array/etc]: declare a constant variable (cannot be changed).
- [int/float/etc] arr[n]: declare an n sized array.
- [int/float/etc] arr[n] {x,y,z}: declare an n sized array with x,y,z in first
three indices.
- [int/float/etc]* {}: declares empty pointer

STACK // HEAP
Stack
- Finite memory
- Developer is not in full control of moemory lifetime
- Lifetime is controlled by the scope meahcnism
Heap
- Memory is finite
- Developer is in full control of memory allocation and release
- Lifetime is controlled explicitly with new and delete operators

*/

// FUNCTIONS
int sum_values(int y0, int y1) {
  int res = y0 + y1;
  return res;
}

// STREAM
int stream() {
  std::cout << "This is output message" << std::endl;
  std::cerr << "This is an error message" << std::endl;
  std::clog << "This is a log message" << std::endl;
  std::string a;
  std::string b;
  // std::cout << "a: ";
  // std::cin >> a;
  // std::cout << "a is: " << a << std::endl;
  std::cout << "b: ";
  std::getline(std::cin, b);
  std::cout << "b is " << b;
  return 0;
}

// VALUE INICIALIZATION
int initialization_types() {
  // Brace initialization `{}`:
  int a{10}; // Uniform initialization (brace initialization), prevents
  // narrowing conversion

  // Parentheses initialization `()`:
  int b(20.1); // Direct initialization (parentheses), can also prevent
  // narrowing in some cases

  // Copy initialization `=`:
  int c = 30.5; // Copy initialization (equals sign), may allow narrowing
  // depending on the context

  // Print the size of each variable
  std::cout << "Size of a: " << sizeof(a) << " bytes, Value of a: " << a
            << std::endl;
  std::cout << "Size of b: " << sizeof(b) << " bytes, Value of b: " << b
            << std::endl;
  std::cout << "Size of c: " << sizeof(c) << " bytes, Value of c: " << c
            << std::endl;

  return 0;
}

// OPERATORS
int operators() {
  // ARITHMETIC OPERATORS:

  // These operators are used to perform basic mathematical operations on
  // variables.

  int a = 10, b = 5;

  // Addition: Adds the two values.
  int sum = a + b; // sum = 10 + 5 = 15
  std::cout << "Addition: " << a << " + " << b << " = " << sum << std::endl;

  // Subtraction: Subtracts the second value from the first.
  int diff = a - b; // diff = 10 - 5 = 5
  std::cout << "Subtraction: " << a << " - " << b << " = " << diff << std::endl;

  // Multiplication: Multiplies the two values.
  int prod = a * b; // prod = 10 * 5 = 50
  std::cout << "Multiplication: " << a << " * " << b << " = " << prod
            << std::endl;

  // Division: Divides the first value by the second.
  // Important note: Division of integers will result in an integer (decimal
  // portion is discarded).
  int div = a / b; // div = 10 / 5 = 2 (remainder discarded)
  std::cout << "Division: " << a << " / " << b << " = " << div << std::endl;

  // Modulo: Returns the remainder after division.
  int mod =
      a % b; // mod = 10 % 5 = 0 (since 10 is divisible by 5 with no remainder)
  std::cout << "Modulo: " << a << " % " << b << " = " << mod << std::endl;

  // COMPARISON OPERATORS:

  // These operators are used to compare values and return a boolean result
  // (true or false).

  bool equal = (a == b);         // Checks if a is equal to b.
  bool not_equal = (a != b);     // Checks if a is not equal to b.
  bool greater = (a > b);        // Checks if a is greater than b.
  bool less = (a < b);           // Checks if a is less than b.
  bool greater_equal = (a >= b); // Checks if a is greater than or equal to b.
  bool less_equal = (a <= b);    // Checks if a is less than or equal to b.

  std::cout << "Comparison (a == b): " << equal
            << std::endl; // False, since 10 is not equal to 5
  std::cout << "Comparison (a != b): " << not_equal
            << std::endl; // True, since 10 is not equal to 5
  std::cout << "Comparison (a > b): " << greater
            << std::endl; // True, since 10 is greater than 5
  std::cout << "Comparison (a < b): " << less
            << std::endl; // False, since 10 is not less than 5
  std::cout << "Comparison (a >= b): " << greater_equal
            << std::endl; // True, since 10 is greater than 5
  std::cout << "Comparison (a <= b): " << less_equal
            << std::endl; // False, since 10 is not less than or equal to 5

  // LOGICAL OPERATORS:

  // These operators are used to combine multiple boolean expressions and return
  // a boolean result.

  bool and_op =
      (a > b) &&
      (b >
       0); // Logical AND: True if both conditions are true (10 > 5 and 5 > 0).
  bool or_op = (a > b) || (b < 0); // Logical OR: True if at least one condition
  // is true (10 > 5 or 5 < 0).
  bool not_op =
      !(a > b); // Logical NOT: Inverts the boolean value (not true is false).

  std::cout << "Logical AND (a > b && b > 0): " << and_op
            << std::endl; // True, since both conditions are true
  std::cout << "Logical OR (a > b || b < 0): " << or_op
            << std::endl; // True, since the first condition is true
  std::cout << "Logical NOT (!(a > b)): " << not_op
            << std::endl; // False, since a > b is true, so NOT of true is false

  // ASSIGNMENT OPERATORS:

  // These operators are used to assign values to variables. They can also be
  // combined with arithmetic operations.

  int x = 5; // Simple assignment: Assigns the value 5 to x
  x += 3;    // Addition assignment: Adds 3 to x (x = x + 3)
  std::cout << "Assignment (x += 3): " << x << std::endl; // x = 8

  x -= 2; // Subtraction assignment: Subtracts 2 from x (x = x - 2)
  std::cout << "Assignment (x -= 2): " << x << std::endl; // x = 6

  x *= 4; // Multiplication assignment: Multiplies x by 4 (x = x * 4)
  std::cout << "Assignment (x *= 4): " << x << std::endl; // x = 24

  x /= 2; // Division assignment: Divides x by 2 (x = x / 2)
  std::cout << "Assignment (x /= 2): " << x << std::endl; // x = 12

  x %=
      3; // Modulo assignment: Takes the remainder of x divided by 3 (x = x % 3)
  std::cout << "Assignment (x %= 3): " << x << std::endl; // x = 0

  // INCREMENT AND DECREMENT OPERATORS:

  // These operators are used to increase or decrease the value of a variable
  // by 1.

  int inc = 10;
  std::cout << "Increment (inc++): " << inc++
            << " (post-increment), inc = " << inc
            << std::endl; // inc++ returns 10, then increments to 11

  int dec = 10;
  std::cout << "Decrement (dec--): " << dec--
            << " (post-decrement), dec = " << dec
            << std::endl; // dec-- returns 10, then decrements to 9

  // MATH FUNCTIONS (from <cmath>):

  // Math functions provide powerful operations for mathematical calculations.
  // Here are some examples.

  // Floor Function: Rounds the value down to the nearest integer.
  double floor_val = std::floor(9.8); // floor(9.8) = 9.0 (rounds down)
  std::cout << "Floor of 9.8 is: " << floor_val << std::endl;

  // Ceiling Function: Rounds the value up to the nearest integer.
  double ceil_val = std::ceil(9.8); // ceil(9.8) = 10.0 (rounds up)
  std::cout << "Ceiling of 9.8 is: " << ceil_val << std::endl;

  // Round Function: Rounds the value to the nearest integer.
  double round_val = std::round(9.8); // round(9.8) = 10.0
  std::cout << "Round of 9.8 is: " << round_val << std::endl;

  // Truncation: Removes the fractional part of the number.
  double trunc_val = std::trunc(9.8); // trunc(9.8) = 9.0
  std::cout << "Truncation of 9.8 is: " << trunc_val << std::endl;

  // Absolute Value: Returns the absolute value of a number (ignoring sign).
  double abs_val = std::abs(-2.3); // abs(-2.3) = 2.3
  std::cout << "Absolute value of -2.3 is: " << abs_val << std::endl;

  // Exponential Function: Returns the result of e raised to the power of the
  // argument.
  double exp_val = std::exp(2.3); // exp(2.3) ≈ 9.974
  std::cout << "Exponential of 2.3 is: " << exp_val << std::endl;

  // Power Function: Raises a number to a specified power.
  double pow_val = std::pow(9.8, 2.3); // 9.8^2.3 ≈ 108.97
  std::cout << "9.8 raised to the power of 2.3 is: " << pow_val << std::endl;

  // Square Root Function: Returns the square root of a number.
  double sqrt_val = std::sqrt(9.8); // sqrt(9.8) ≈ 3.130
  std::cout << "Square root of 9.8 is: " << sqrt_val << std::endl;

  // Logarithmic Functions: Calculate logarithms of numbers.
  double log_val = std::log(9.8); // ln(9.8) ≈ 2.281
  std::cout << "Natural log of 9.8 is: " << log_val << std::endl;

  double log10_val = std::log10(9.8); // log10(9.8) ≈ 0.991
  std::cout << "Logarithm base 10 of 9.8 is: " << log10_val << std::endl;

  // Trigonometric Functions: Calculate the trigonometric values for angles in
  // radians.

  double angle = 1.0; // 1 radian ≈ 57.2958 degrees

  // Sine, Cosine, and Tangent functions
  double sine_val = std::sin(angle); // sin(1 radian) ≈ 0.841
  std::cout << "Sine of 1 radian is: " << sine_val << std::endl;

  double cosine_val = std::cos(angle); // cos(1 radian) ≈ 0.540
  std::cout << "Cosine of 1 radian is: " << cosine_val << std::endl;

  double tan_val = std::tan(angle); // tan(1 radian) ≈ 1.557
  std::cout << "Tangent of 1 radian is: " << tan_val << std::endl;

  // Inverse Trigonometric Functions: Calculate angles based on trigonometric
  // values.

  double asin_val = std::asin(0.5); // arcsin(0.5) ≈ 0.5236 radians
  std::cout << "Arcsine of 0.5 is: " << asin_val << " radians" << std::endl;

  double acos_val = std::acos(0.5); // arccos(0.5) ≈ 1.047 radians
  std::cout << "Arccosine of 0.5 is: " << acos_val << " radians" << std::endl;

  double atan_val = std::atan(1.0); // arctan(1) ≈ 0.785 radians
  std::cout << "Arctangent of 1 is: " << atan_val << " radians" << std::endl;

  // Hyperbolic Functions: These functions are similar to trigonometric
  // functions but for hyperbolic angles.

  double sinh_val = std::sinh(angle); // sinh(1) ≈ 1.175
  std::cout << "Hyperbolic sine of 1 is: " << sinh_val << std::endl;

  double cosh_val = std::cosh(angle); // cosh(1) ≈ 1.543
  std::cout << "Hyperbolic cosine of 1 is: " << cosh_val << std::endl;

  double tanh_val = std::tanh(angle); // tanh(1) ≈ 0.762
  std::cout << "Hyperbolic tangent of 1 is: " << tanh_val << std::endl;

  // Maximum and Minimum Functions: Return the largest and smallest values,
  // respectively.
  double max_val = std::fmax(9.8, 2.3); // Maximum of 9.8 and 2.3
  double min_val = std::fmin(9.8, 2.3); // Minimum of 9.8 and 2.3

  std::cout << "Maximum of 9.8 and 2.3 is: " << max_val << std::endl;
  std::cout << "Minimum of 9.8 and 2.3 is: " << min_val << std::endl;

  return 0;
}

// FLOW CONTROL
int flow_control() {
  // IF STATEMENT:
  // The 'if' statement executes a block of code if the condition is true.
  int a = 5, b = 10;

  if (a < b) { // Condition: a is less than b
    std::cout << "a is less than b" << std::endl;
  }

  // ELSE IF:
  // The 'else if' statement allows you to check multiple conditions.
  if (a > b) {
    std::cout << "a is greater than b" << std::endl;
  } else if (a == b) {
    std::cout << "a is equal to b" << std::endl;
  } else {
    std::cout << "a is less than b" << std::endl;
  }

  // ELSE:
  // The 'else' statement executes when all the previous conditions are false.
  if (b < 5) {
    std::cout << "b is less than 5" << std::endl;
  } else {
    std::cout << "b is greater than or equal to 5" << std::endl;
  }

  // SWITCH STATEMENT:
  // The 'switch' statement is used when you have multiple possible values to
  // check for a variable.
  int number = 2;

  switch (number) {
  case 1:
    std::cout << "The number is 1" << std::endl;
    break; // Exits the switch statement after the block is executed
  case 2:
    std::cout << "The number is 2" << std::endl;
    break;
  case 3:
    std::cout << "The number is 3" << std::endl;
    break;
  default:
    std::cout << "The number is not 1, 2, or 3" << std::endl;
    break; // Optional, but good practice to include
  }

  // TERNARY OPERATOR:
  // The ternary operator is a shorthand way of writing an 'if-else' statement.
  // Format: condition ? value_if_true : value_if_false;
  int max = (a > b) ? a : b; // If a > b, max = a; otherwise, max = b
  std::cout << "The larger value is: " << max << std::endl;

  // CONDITIONAL OPERATOR SUMMARY:
  // - Use 'if' to check a single condition.
  // - Use 'else if' to check additional conditions if the first one is false.
  // - Use 'else' to define what to do when all conditions are false.
  // - Use 'switch' for multiple specific possible values of a variable.
  // - Use the ternary operator for concise conditional expressions.

  return 0;
}

// LOOPS
int loops() {
  // FOR LOOP:
  // A for loop is useful when you know the number of iterations in advance.

  std::cout << "For Loop Example:" << std::endl;
  for (int i = 1; i <= 5; ++i) {
    std::cout << "Iteration " << i << std::endl; // Will print numbers 1 to 5
  }

  // Explanation: The for loop starts with i = 1, checks if i <= 5,
  // and increments i by 1 until it reaches 5.

  // WHILE LOOP:
  // A while loop is used when the number of iterations is unknown, but you
  // know the stopping condition.

  std::cout << "\nWhile Loop Example:" << std::endl;
  int j = 1;
  while (j <= 5) {
    std::cout << "Iteration " << j << std::endl; // Will print numbers 1 to 5
    ++j;                                         // Increment j by 1
  }

  // Explanation: The while loop continues as long as j <= 5.
  // It prints the iteration number and increments j in each cycle.

  // DO-WHILE LOOP:
  // A do-while loop guarantees that the loop body is executed at least once,
  // even if the condition is false initially.

  std::cout << "\nDo-While Loop Example:" << std::endl;
  int k = 1;
  do {
    std::cout << "Iteration " << k << std::endl; // Will print numbers 1 to 5
    ++k;                                         // Increment k by 1
  } while (k <= 5);

  // Explanation: The do-while loop executes the body at least once,
  // regardless of the initial condition. The condition is checked after
  // the body runs.

  return 0;
}

int arrays() {
  // Introduction to Arrays
  // An array in C++ is a collection of variables of the same data type, stored
  // contiguously in memory. Arrays allow us to store multiple values under a
  // single variable name, and we can access individual elements using an index
  // (starting from 0). The size of the array must be known at compile time, and
  // all elements of an array must be of the same type.

  // Declaring And Using Arrays
  // In this example, we declare an array of integers and initialize it with
  // values.
  int numbers[5] = {
      1, 2, 3, 4,
      5}; // Declare an integer array with 5 elements initialized with values

  // Accessing array elements using an index.
  // In C++, arrays are indexed starting from 0. The first element is
  // numbers[0], the second is numbers[1], and so on until numbers[4] (the last
  // element in the array).
  std::cout << "Array elements: ";
  for (int i = 0; i < 5; i++) {
    std::cout << numbers[i] << " "; // Print each element of the array
  }
  std::cout << std::endl; // Output the array elements separated by space

  // Size Of An Array
  // The size of an array in memory can be determined using the `sizeof`
  // operator. However, it is important to note that `sizeof` applied to an
  // array returns the total number of bytes used by the array, not the number
  // of elements.
  std::cout << "Size of array in bytes: " << sizeof(numbers) << std::endl;

  // To find the number of elements in an array, we divide the total size of the
  // array by the size of one element.
  int num_elements = sizeof(numbers) / sizeof(numbers[0]);
  std::cout << "Number of elements in array: " << num_elements
            << std::endl; // Output the calculated number of elements

  // Arrays of Characters (C-strings)
  // Arrays can also be used to store characters, such as strings. In C++, a
  // string is often represented as a C-string, which is an array of characters
  // terminated by a null character ('\0'). (Relevando when using
  // std::cout<<name; Here, we declare and initialize an array of characters
  // that represent the string "John".
  char name[6] = {'J', 'o', 'h', 'n',
                  '\0'}; // Declare a character array (C-string) to store "John"

  // Output the string stored in the array.
  // We can print the entire string using the array name, which automatically
  // accesses the elements until the null character.
  std::cout << "Name: " << name << std::endl; // Print the C-string, which is
  // automatically null-terminated

  // Bounds of an Array
  // C++ does not provide bounds checking for arrays, meaning that accessing an
  // index outside the valid range may result in undefined behavior. For
  // example, if we try to access an element beyond the array's size, we may get
  // garbage values or a crash.
  std::cout << "Out of bounds access (undefined behavior): " << numbers[10]
            << std::endl;
  // In this case, `numbers[10]` is out of bounds because the array only has
  // indices 0-4. This could lead to unpredictable behavior, such as printing
  // garbage data or crashing the program.

  // Working with Multi-dimensional Arrays
  // Arrays in C++ can also have more than one dimension. A common example is a
  // 2D array, which is often used to represent matrices or grids.
  int matrix[2][3] = {
      {1, 2, 3},
      {4, 5, 6}}; // Declare and initialize a 2x3 matrix (2 rows, 3 columns)

  // Accessing elements of a multi-dimensional array
  std::cout << "Matrix elements:" << std::endl;
  for (int i = 0; i < 2; i++) {         // Iterate through rows
    for (int j = 0; j < 3; j++) {       // Iterate through columns
      std::cout << matrix[i][j] << " "; // Print each element in the matrix
    }
    std::cout << std::endl; // Move to the next row
  }

  // Dynamically Allocated Arrays
  // In addition to statically allocated arrays (like those declared with a
  // fixed size), C++ also allows for dynamically allocated arrays using
  // pointers and the `new` keyword. For example, we can create an array of
  // integers at runtime and assign values to it.
  int *dynamicArray = new int[5]; // Dynamically allocate an array of 5 integers

  // Initializing and accessing a dynamically allocated array
  for (int i = 0; i < 5; i++) {
    dynamicArray[i] =
        i + 1; // Assign values to the dynamic array (1, 2, 3, 4, 5)
  }

  std::cout << "Dynamic array elements: ";
  for (int i = 0; i < 5; i++) {
    std::cout << dynamicArray[i]
              << " "; // Output the elements of the dynamic array
  }
  std::cout << std::endl;

  // Don't forget to free the memory allocated with `new` using `delete[]` to
  // avoid memory leaks.
  delete[] dynamicArray; // Deallocate the dynamic array

  return 0; // Return from the function
}

int pointers() {
  // Pointers Introduction
  // ---------------------
  // A pointer is a variable that stores the memory address of another variable.
  // Using pointers allows you to directly access and manipulate the memory
  // where a value is stored. Syntax: <data_type>* <pointer_name>;

  int var = 42;      // Regular integer variable
  int *p_var = &var; // Pointer storing the address of 'var'

  // Accessing pointer value and address
  std::cout << "Pointers Introduction: " << std::endl;
  std::cout << "Value of var: " << var << std::endl;
  std::cout << "Address of var: " << &var << std::endl;
  std::cout << "Pointer p_var: " << p_var << std::endl;
  std::cout << "Dereferenced value: " << *p_var << std::endl << std::endl;

  // Declaring and Using Pointers
  // ----------------------------
  // Declaring pointers and assigning values
  int number = 10;
  int *p_number = &number;

  // Access and print the pointer address and its dereferenced value
  std::cout << "Declaring and Using Pointers: " << std::endl;
  std::cout << "Pointer address: " << p_number << std::endl;
  std::cout << "Pointer value: " << *p_number << std::endl << std::endl;

  // Pointer to Char
  // ---------------
  // Pointers can store the address of a char variable.
  char c = 'A';
  char *p_char = &c;

  std::cout << "Pointer to Char: " << std::endl;
  std::cout << "Char value: " << c << std::endl;
  std::cout << "Pointer to char: " << static_cast<void *>(p_char) << std::endl;
  std::cout << "Dereferenced char: " << *p_char << std::endl << std::endl;

  // Program Memory Map
  // ------------------
  // Memory layout in a program:
  // - Stack: Stores local variables and function call information.
  // - Heap: Stores dynamically allocated memory.
  // - Data Segment: Stores global and static variables.
  // - Code Segment: Stores the compiled code.

  int local_var = 10;             // On stack
  int *dynamic_var = new int(20); // On heap

  std::cout << "Program Memory Map: " << std::endl;
  std::cout << "Address of local variable (stack): " << &local_var << std::endl;
  std::cout << "Address of dynamic variable (heap): " << dynamic_var
            << std::endl;

  delete dynamic_var; // Free dynamically allocated memory
  dynamic_var = nullptr;
  std::cout << std::endl;

  // Dynamic Memory Allocation
  // -------------------------
  // Dynamically allocate memory using `new`.
  int *p_dynamic = new int(42); // Dynamically allocate memory for an int

  std::cout << "Dynamic Memory Allocation: " << std::endl;
  std::cout << "Dynamically allocated value: " << *p_dynamic << std::endl;

  delete p_dynamic;    // Free the allocated memory
  p_dynamic = nullptr; // Prevent dangling pointer
  std::cout << std::endl;

  // Dangling Pointers
  // -----------------
  // A dangling pointer is a pointer that references a memory location
  // that has already been freed or deleted.
  int *p_dangle = new int(50); // Allocate memory
  delete p_dangle;             // Free the memory

  // p_dangle is now a dangling pointer
  p_dangle = nullptr; // Fix: Set the pointer to nullptr to make it safe
  std::cout
      << "Dangling Pointers: Pointer safely set to nullptr after deletion."
      << std::endl
      << std::endl;

  // When New Fails
  // --------------
  // If dynamic memory allocation fails, `new` throws a `std::bad_alloc`
  // exception.
  try {
    int *p_large = new int[1000000000000]; // Large allocation
  } catch (const std::bad_alloc &e) {
    std::cout << "When New Fails: Memory allocation failed: " << e.what()
              << std::endl;
  }
  std::cout << std::endl;

  // Null Pointer Safety
  // -------------------
  // A null pointer is a pointer that points to nothing (nullptr).
  int *p_null = nullptr;

  if (p_null == nullptr) {
    std::cout << "Null Pointer Safety: Pointer is null, safe to use!"
              << std::endl;
  } else {
    std::cout << "Pointer value: " << *p_null << std::endl;
  }
  std::cout << std::endl;

  // Memory Leaks
  // ------------
  // A memory leak occurs when dynamically allocated memory is not freed.
  int *p_leak = new int(100); // Allocate memory
  delete p_leak;              // Free the memory
  p_leak = nullptr;           // Prevent memory leak

  std::cout
      << "Memory Leaks: Memory safely released and pointer set to nullptr."
      << std::endl
      << std::endl;

  // Dynamic Arrays
  // --------------
  // Allocate and manage dynamic arrays.
  int *p_array = new int[5]; // Dynamically allocate an array of integers
  double *p_array1{new double[6]};
  int *p_array2{
      new (std::nothrow) int[6]{}}; // `std::nothrow` prevents exceptions from
  // being thrown by `new` on failure,
  // returning `nullptr` instead.

  double *p_array3{new (std::nothrow) double[6]{
      1, 2, 3, 4}}; // first initialized with 1,2,3,4--rest=0

  // Initialize and print array elements
  std::cout << "Dynamic Arrays: " << std::endl;
  for (int i = 0; i < 5; i++) {
    p_array[i] = i + 1; // Assign values to the array
    std::cout << p_array[i] << " ";
  }

  if (p_array) {
    for (size_t i{}; i < 5; ++i) {
      std::cout << "Value: " << p_array[i] << " : " << *(p_array + i)
                << std::endl; // 2 syntax options to acces array items
    }
  }
  std::cout << std::endl;

  delete[] p_array;  // Free the dynamic array
  p_array = nullptr; // Avoid dangling pointer
  std::cout << "Dynamic array memory released successfully." << std::endl;
  /*
    //////////////////////////////////////////////////////////////////////////////
    // NEVER DO
    // int * pointer {};
    // int var=56;
    // *pointer=56;
    int int_var{56};
    int *pointer_var{&int_var};
    char char_var{'H'};
    char *char_pointer = &char_var;
    char_pointer = &char_var;
    const char *message_pointer{"Hola mundo"};
    //*message_pointer = 'B';//compilation error (char is const)
    // char * = message_pointer("Hola mundo");// fails on some compilers
    std::cout << "Int Value: " << *pointer_var << std::endl
              << "Int Adress: " << pointer_var << std::endl
              << "Char Value: " << *char_pointer << std::endl
              << "Char Adress: " << char_pointer << std::endl
              << "Mesaage Pointer Value: " << *message_pointer << std::endl
              << "Full Message: " << message_pointer << std::endl;
    // char * message_pointer {"Hola mundo"};// fails on some compilers
    //
    // MEMORY ALLOCATION

    int *p_number{nullptr}; // Pointer p_number is initialized to nullptr.
    p_number = new int;     // Memory for an integer is dynamically allocated,
    and
    // p_number points to it.
    *p_number = 77; // The value 77 is assigned to the memory location that
    // p_number points to.
    delete p_number;
    p_number = nullptr;

    int *p_number1{new int};      // Memory location contains junk value
    int *p_number2{new int(22)};  // use direct initialization
    int *p_number3{new int{256}}; // use uniform initialization

    std::cout << std::endl;
    std::cout << "Initialize with memory adress at declaration: " << std::endl;

    std::cout << "p_number1: " << p_number1 << std::endl;
    std::cout << "*p_number1: " << *p_number1 << std::endl;

    std::cout << "p_number2: " << p_number2 << std::endl;
    std::cout << "*p_number2: " << *p_number2 << std::endl;

    std::cout << "p_number3: " << p_number3 << std::endl;
    std::cout << "*p_number3: " << *p_number3 << std::endl;

    // Release the dynamically allocated memory for p_number1
    // Using `delete` frees the memory block that was allocated with `new`.
    // Setting the pointer to `nullptr` ensures it doesn't become a dangling
    // pointer.
    delete p_number1;
    p_number1 = nullptr;

    // Release the dynamically allocated memory for p_number2
    // After freeing the memory, the pointer is reset to `nullptr` for safety.
    delete p_number2;
    p_number2 = nullptr;

    // Release the dynamically allocated memory for p_number3
    // The same process ensures proper memory management and avoids issues with
    // dangling pointers.
    delete p_number3;
    p_number3 = nullptr;
  */

  // PROBLEM CASES
  // --------------
  // 1. Uninitialized pointer
  // int *p_number;
  // std::cout << std::endl;
  // std::cout << "Case 1: Uninitialized pointer: " << std::endl;
  // std::cout << "p_number: " << p_number << std::endl;
  // std::cout << "*p_number: "<< * pnumber << std::endl;//CRASH

  // 2. Deleted pointer
  // std::cout << std::endl;
  // std::cout << "Case 2: Deleted pointer" << std::endl;
  // int *p_number1{new int{67}};

  // std::cout << "*p_number (before delete) : " << *p_number1 << std::endl;
  // delete ṕ_number1;
  // std::cout << "*p_number (after delete) : " << *p_number1 << std::endl;

  // 3. Multiple pointers to same adress
  // std::cout << "Case 3: Multiple pointers to same adress" << std::endl;
  // int *p_number3{new_int{83}};
  // int *p_number4{p_number4};

  // std::cout << "p_number3 - " << p_number3 << " - " << *p_number3 <<
  // std::endl; std::cout << "p_number4 - " << p_number4 << " - " << *p_number4
  // << std::endl;

  // Delete p_number3
  // delete p_number3;
  // std::cout << "p_number4(after deleting p_number3) - " << p_number4 << " - "
  // << *p_number4 << std::endl;

  // PROBLEM CASES - SOLUTIONS
  // --------------
  // 1. Initialize pointer immediately upon declaration
  std::cout << std::endl;
  std::cout << "Solution 1: " << std::endl;
  int *p_number5{};
  int *p_number6{new int{56}};
  if (p_number6 != nullptr) {
    std::cout << "*p_number6: " << *p_number6 << std::endl;
  }
  // 2. Right after calling delete, restet pointer to nullptr
  int *p_number7{new int{82}};
  std::cout << "p_number7 - " << p_number7 << " - " << *p_number7 << std::endl;
  delete p_number7;
  p_number7 = nullptr;
  if (p_number7 != nullptr) {
    std::cout << "*p_number7: " << *p_number7 << std::endl;
  }
  // 3. For multiple pointers pointing to the same adress, make sure ther is one
  // clear master pointer that owns memory, other pointer should only be able to
  // dereference when master pointer is valid.
  int *p_number8{new int{382}}; // master pointer
  int *p_number9{p_number8};

  std::cout << "p_number8 - " << p_number8 << " - " << *p_number8 << std::endl;

  if (!(p_number8 == nullptr)) {
    std::cout << "p_number9 - " << p_number9 << " - " << *p_number9
              << std::endl;
  } else {
    std::cerr << "Warning: trying invalid pointer" << std::endl;
  }

  // POSSIBLE POINTER FAILS
  // --------------
  // int * lots_of_ints { new int[100000000000]};//may give error
  // for (size_t i{}; i<10000000;++i}{
  //  int * lots_of_ints2 { new int[100000]};
  //}
  // Handle exception
  for (size_t i{}; i < 1000000; ++i) {
    // This loop iterates from 0 to 999,999 (1,000,000 times), using `size_t`
    // for safe indexing of large ranges.
    // `size_t` ensures that the index can handle large values without overflow,
    // suitable for large arrays or counts. The loop increments `i` by 1 on each
    // iteration, and continues until `i` reaches 1,000,000.

    try {
      int *lots_of_ints3{new int[1000000]};
    } catch (std::exception &ex) {
      std::cout << "Exception. " << ex.what() << std::endl;
    }
  }

  return 0;
}

int references() {
  // Introduction to References
  // In C++, a reference is an alias for another variable. A reference
  // must be initialized when it is declared, and it cannot be changed to refer
  // to another variable after it is initialized. References are often used to
  // pass arguments to functions by reference, allowing modification of the
  // original data.

  // Declaring and Using References
  // In this example, we declare an integer variable and a reference to that
  // variable.
  int num = 10;   // Declare an integer variable
  int &ref = num; // Declare a reference to the variable 'num'

  // Modifying the value using the reference.
  ref = 20; // This modifies the original 'num' through the reference

  std::cout << "Value of num after modifying through reference: " << num
            << std::endl;
  std::cout << "Value of ref: " << ref << std::endl;

  // Comparing References to Pointers
  // Unlike references, pointers can be changed to point to different variables.
  // A reference, once initialized, cannot refer to any other variable.

  int *ptr = &num; // Declare a pointer to 'num'

  std::cout << "Value of num through pointer: " << *ptr << std::endl;

  // References vs Pointers: Modifying the original variable through a pointer
  *ptr = 30; // Modify 'num' using the pointer

  std::cout << "Value of num after modifying through pointer: " << num
            << std::endl;
  std::cout << "Value of ptr: " << *ptr << std::endl;

  // References and Const
  // A reference can also be declared as 'const', which prevents it from being
  // used to modify the object it refers to.
  const int &constRef = num; // Declare a const reference to 'num'

  // Trying to modify the object through a const reference will result in an
  // error. constRef = 40; // Uncommenting this line will cause a compilation
  // error.

  std::cout << "Value of num through const reference: " << constRef
            << std::endl;

  // Multiple references to the same variable
  int &ref1 = num; // Another reference to 'num'
  int &ref2 = num; // Another reference to 'num'

  // All references reflect the changes made to the original variable
  ref2 = 50; // This will change 'num' through ref2

  std::cout << "Value of num after modifying through ref2: " << num
            << std::endl;

  // Returning from the function
  return 0;
}

int characterManipulationAndStrings() {
  // Character Manipulation And Strings Introduction
  // In C++, characters are represented using the `char` data type.
  // Strings can be represented using C-style strings (character arrays)
  // or the `std::string` class from the C++ Standard Library.

  // Character Manipulation
  // The C++ Standard Library provides several functions to manipulate
  // characters.
  char letter = 'a'; // Declare a character variable

  // Converting to uppercase
  char upper = std::toupper(letter); // Convert to uppercase
  std::cout << "Uppercase of '" << letter << "': " << upper << std::endl;

  // Checking if a character is a digit
  char digit = '5';
  if (std::isdigit(digit)) {
    std::cout << "'" << digit << "' is a digit." << std::endl;
  }

  // Checking if a character is a letter
  if (std::isalpha(letter)) {
    std::cout << "'" << letter << "' is a letter." << std::endl;
  }

  // C-String Manipulation
  // A C-string is an array of characters ending with a null character (`\0`).
  char cstr[] = "Hello"; // Declare a C-string

  // Finding the length of a C-string
  std::cout << "Length of C-string: " << std::strlen(cstr) << std::endl;

  // Modifying a C-string
  cstr[0] = 'M'; // Change the first character
  std::cout << "Modified C-string: " << cstr << std::endl;

  // C-String Concatenation And Copying
  // We can use `std::strcpy` and `std::strcat` to copy and concatenate
  // C-strings.
  char first[20] = "Hello, ";
  char second[] = "World!";

  // Concatenating strings
  std::strcat(first, second);
  std::cout << "Concatenated C-string: " << first << std::endl;

  // Copying a string
  char copy[20];
  std::strcpy(copy, first);
  std::cout << "Copied C-string: " << copy << std::endl;

  // Introducing std::string
  // The `std::string` class in C++ provides a safer and more flexible way to
  // work with strings.
  std::string str1 = "Hello";
  std::string str2 = " World!";

  // Declaring And Using std::string
  // Concatenation using `+`
  std::string fullStr = str1 + str2;
  std::cout << "Concatenated std::string: " << fullStr << std::endl;

  // Finding the length of a `std::string`
  std::cout << "Length of std::string: " << fullStr.length() << std::endl;

  // Accessing individual characters
  std::cout << "First character of fullStr: " << fullStr[0] << std::endl;

  // Modifying a `std::string`
  fullStr[0] = 'M'; // Change first character
  std::cout << "Modified std::string: " << fullStr << std::endl;

  return 0;
}

int functionsInCpp() {
    // One Definition Rule (ODR)
    // In C++, the One Definition Rule states that:
    // 1. A function can be declared multiple times, but it must have exactly one definition.
    // 2. Multiple definitions of the same function within the same translation unit lead to compilation errors.

    // First Hand On Functions
    // A simple function declaration and definition
    auto add = [](int a, int b) -> int {
        return a + b;
    }; // Using a lambda function for compactness

    // Function Declaration & Definition
    // Functions in C++ are typically declared before they are used (prototyping).
    // The definition provides the actual implementation.
    
    int result = add(5, 10); // Calling the function
    std::cout << "Sum of 5 and 10: " << result << std::endl;

    // Functions Across Multiple Files - Compilation Model Revisited
    // Functions can be split across multiple files using headers (`.h`) and source files (`.cpp`).
    // Example:
    // - myFunctions.h (contains function declarations)
    // - myFunctions.cpp (contains function definitions)
    // - main.cpp (includes the header and calls the functions)
    //
    // Compilation: `g++ main.cpp myFunctions.cpp -o program`

    // Pass By Value
    // When passing by value, a copy of the argument is made, so modifications
    // inside the function do not affect the original variable.
    int x = 10;
    auto modifyByValue = [](int num) {
        num = 50; // Changes only the local copy
    };
    modifyByValue(x);
    std::cout << "Value of x after modifyByValue: " << x << std::endl; // x remains 10

    // Pass By Pointer
    // When passing by pointer, the function receives a memory address,
    // allowing modifications to the original variable.
    auto modifyByPointer = [](int* num) {
        *num = 50; // Dereferencing pointer modifies original value
    };
    modifyByPointer(&x);
    std::cout << "Value of x after modifyByPointer: " << x << std::endl; // x is modified

    // Pass By Reference
    // When passing by reference, the function works directly with the original variable.
    auto modifyByReference = [](int& num) {
        num = 50; // Directly modifies the original variable
    };
    modifyByReference(x);
    std::cout << "Value of x after modifyByReference: " << x << std::endl; // x is modified

    return 0;
}

int lambdaFunctionsInCpp() {
    // Intro to Lambda Functions
    // Lambda functions in C++ provide a way to create anonymous functions
    // (functions without a name). They are useful for short, simple operations
    // that don't need a full function declaration.

    // Declaring and Using Lambda Functions
    // A lambda function has the syntax:
    // [capture_list] (parameters) -> return_type { function_body };
    // - capture_list: Defines which variables from the surrounding scope can be accessed.
    // - parameters: The inputs to the lambda function.
    // - return_type: (Optional) Specifies the return type of the lambda.
    // - function_body: The actual function implementation.

    // Example: A lambda function that adds two numbers
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    int sum = add(5, 10);
    std::cout << "Sum of 5 and 10 using lambda: " << sum << std::endl;

    // Capture Lists
    // A lambda function can "capture" variables from its surrounding scope.
    // - `[=]` : Captures all variables by **value** (read-only by default).
    // - `[&]` : Captures all variables by **reference** (modifiable).
    // - `[var]` : Captures only `var` by **value**.
    // - `[&var]` : Captures only `var` by **reference**.

    int x = 10, y = 20;

    // Capturing by value
    auto captureByValue = [=]() {
        std::cout << "Captured by value: x = " << x << ", y = " << y << std::endl;
    };
    captureByValue(); // x and y are copied, so modifying them inside won't affect the original variables.

    // Capturing by reference
    auto captureByReference = [&]() {
        x = 50; // Modifies the original x
        std::cout << "Captured by reference: x = " << x << std::endl;
    };
    captureByReference(); // Modifies x in the surrounding scope

    // Capture All in Context
    // If we use `[=]`, all variables in the surrounding scope are captured **by value**.
    // If we use `[&]`, all variables are captured **by reference**.

    auto captureAllByValue = [=]() {
        std::cout << "Capture all by value: x = " << x << ", y = " << y << std::endl;
    };
    captureAllByValue(); // x and y are copied

    auto captureAllByReference = [&]() {
        x += 10; // Modifies x in the original scope
        y += 10; // Modifies y in the original scope
        std::cout << "Capture all by reference: x = " << x << ", y = " << y << std::endl;
    };
    captureAllByReference(); // Modifies x and y in the original scope

    // Lambdas in STL Algorithms
    // Lambda functions are often used in STL algorithms like `std::for_each` or `std::sort`.
    std::vector<int> numbers = {5, 2, 8, 3, 1};

    std::cout << "Original numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sorting using a lambda function
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b; // Sort in ascending order
    });

    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


int main() {
  return 0;
}
