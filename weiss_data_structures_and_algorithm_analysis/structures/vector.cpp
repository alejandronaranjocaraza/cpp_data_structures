// Taken fro chapter three in Weiss - Data Structures and Algorithm Analysis
//
// ADT DETAILS
// ------------
//
// This corresponds to an array implmentation of a List ADT (finite collection of ordered items).
// Implementations of List ADTs (including this one) are usually carried out by storing elements
// in contiguous memory.
// This results in:
//
//  - printList() can be carried out in linear time
//  - find Kth element can be carried out in contant time
//  - Adding and removing elements is potentially expensive
//    (all elements must be moved)
//
// MAIN DETAILS
// ------------
//
// 1) Vector will maintain:
//
//  - A primitive array via a pointer variable "objects" to the blocks of alocated memory
//  - The array capacity "theCapacity"
//  - The current number of elements stored in the vector "theSize"
//
// 2) Provides deep-copy semantics for the copy constructor and the operator "=".
// It will also provide a destructor to remove the primitive array.
//
// 3) Provides a resize routine that will change, when necessary, the capacity of the vector.
// This is done by obtaining a new block of memory from the old array,
// copying the old array to the new block and reclaiming old block.
//
// 4) Includes accesor and mutator versions of "[]" operator to acces elements.
//
// 5) Includes basic list routines: size(), empty(), clea(), back(), pop_back(), push_back().
//
// 6) The Vector will provide suppoort for nested types iterator and const_iterator.
// It will also provide associated begin and end methods.
//
// NO
#include <algorithm>
#include <iostream>
using namespace std;

template <typename Object>
class Vector {
public:
  //Defualt constructor
  explicit Vector(int initSize = 0) : theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY} {
    objects = new Object[theCapacity];//dymanic memory allocation for Object types
  }
  //Copy constructor
  Vector(const Vector& rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity} {
  objects = new Object[theCapacity];
  for(int k=0; k < theSize; k++) {
      objects[k] = rhs.objects[k];
    }
  }
  Vector& operator = (const Vector& rhs) {
    Vector copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  ~Vector() {
    delete [] objects;
  }

  Vector(Vector && rhs):theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects} {
    rhs.objects = nullptr;
    rhs.theSize = 0;
    rhs.theCapacity = 0;
  }
  Vector& operator= (Vector&& rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(objects, rhs.objects);
    return *this;
  }
  void resize(int newSize) {
    if(newSize > theCapacity)
      reserve( newSize*2);
    theSize = newSize;
  }
  void reserve(int newCapacity) {
    if(newCapacity < theSize)
      return;
    Object* newArray = new Object[newCapacity];
    for(int k=0; k < theSize; k++) {
      newArray[k] = std::move(objects[k]);
    }
    theCapacity = newCapacity;
    std::swap(objects, newArray);
    delete [] newArray;
  }
  Object& operator[](int index) {
    return objects[index];
  }
  const Object& operator[](int index) const {
    return objects[index];
  }
  bool empty() const {
    return size() == 0;
  }
  int size() const {
    return theSize;
  }
  int capacity() const {
    return theCapacity;
  }
  void push_back(const Object& x) {
    if(theSize == theCapacity)
      reserve(2 * theCapacity + 1);
    objects[theSize++] = x;
  }
  void push_back(Object&& x) {
    if(theSize == theCapacity) {
      reserve(2 * theCapacity + 1);
    }
    objects[theSize++] = std::move(x);
  }
  void pop_back() {
    --theSize;
  }
  const Object& back() const {
    return objects[theSize - 1];
  }

  typedef Object* iterator;
  typedef const Object* const_iterator;
  iterator begin() {
    return &objects[0];
  }
  //Constness of "this" (Object)
  const_iterator begin() const {
    return &objects[0];
  }
  iterator end() {
    return &objects[size()];
  }
  const_iterator end() const {
    return &objects[size()];
  }
  static const int SPARE_CAPACITY = 16;

private:
  int theSize;
  int theCapacity;
  Object* objects;
};

int main() {
  Vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  cout << vec.size() << endl;
  cout << vec.empty() << endl;
  cout << vec.end() << endl;
  cout << *(vec.end()-1) << endl;
  cout << vec.begin() << endl;
  cout << *vec.begin() << endl;
}
