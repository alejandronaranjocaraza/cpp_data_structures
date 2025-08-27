#include <iostream>
using namespace std;
// 1.3 RECURSION
//
// Basic recursion rules
// 1. Base case: Can be solved without recursion
// 2. Making progress: Other than base case, solutions must make progress until reachining break
// 3. Design: Assume that all recursive calls work
// 4. Compound interest: Never duplicate work by solving same instance of a problem in seperate recursive calls.

// Simple recursive function
// - Inclues base case
// - Base case also works as function break
int f(int x) {
  if (x==0)
    return 0;
  else
    return 2*f(x-1) + x*x;
}

int run_f() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  cout << "f(" << n << ") = " << f(n) <<endl;
  return 0;
}

// 1.4 Classes
//
// Definition: Object
// - "Entity that has state, behavior, and identity. [1] [2] : 78  An object can model some part of reality or can be an invention of the design process whose collaborations with other such objects serve as the mechanisms that provide some higher-level behavior.
//
// Definition: Classes
// - Define the shared aspects of objects (class instances). Generally include identity (attributes) and behaviour (methods).
// - Notes:
//  * Public Attributes/Methods: Available outside of the class
//  * Private Attributes/Methods: Available only inside of the class ("information hiding")
//  * Constructor: Method that describes how an instance is built

class classExample {
// these are public
public:
  // constructor if no value is specified
  classExample() {
    storedValue = 0;
  }
  // constructor if value is specified
  classExample(int initialValue) {
    storedValue = initialValue;
  }
  // read() method reads value
  int read() {
    return storedValue;
  }
  // write() method writes new value
  void write(int x) {
    storedValue = x;
  }
// these are private
private:
  int storedValue;
};



int main() {
  run_f();
  classExample obj(3);
  obj.write(44);
  cout << obj.read() <<endl;
}
