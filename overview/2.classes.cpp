// 1.4 CLASSES
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

#include <iostream>
using namespace std;

// Normal body constructor
class classExample1 {
// these are public
public:
  // constructor if no value is specified
  classExample1() {
    storedValue = 0;
  }
  // constructor if value is specified
  classExample1(int initialValue) {
    storedValue = initialValue;
  }
  // read() method reads value
  int read() const {
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

// Initializar list
class Example2 {
public:
  explicit Example2 (int initial1=0,int initial2=0)
  : storedValue1{initial1}, storedValue2{initial2} {}
  int read() const {
    return storedValue1;
  }
  void write(int x) {
    storedValue1=x;
  }
private:
  int storedValue1;
  int storedValue2;
};

// MAIN
int main() {
  // Correct explicit initialization
  Example2 example(2,2);
  cout << example.read() << endl;
  return 0;
}
