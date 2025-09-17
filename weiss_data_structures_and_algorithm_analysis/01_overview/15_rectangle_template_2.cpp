//
//15. Define a Rectangle class that provides getLength and getWidth.
//Using the findMax routines in Figure 1.25,
//write a main that creates an array of Rectangle and
//finds the largest Rectangle first on the basis of area and then on the basis of perimeter.
//

#include <iostream>
using namespace std;

class Rectangle0 {
public:
  int width;
  int length;
  Rectangle0(int w, int l) {
    width = w;
    length = l;
  }
  Rectangle0() {
    width = 0;
    length = 0;
  }
  bool operator>(const Rectangle0& other) const {
    return (width*length > other.width*other.length);
  }
  bool operator>=(const Rectangle0& other) const {
    return (width*length >= other.width*other.length);
  }
  bool operator==(const Rectangle0& other) const {
    return (width*length == other.width*other.length);
  }
  bool operator<(const Rectangle0& other) const {
    return (width*length < other.width*other.length);
  }
  bool operator<=(const Rectangle0& other) const {
    return (width*length <= other.width*other.length);
  }

};

class Rectangle1 {
public:
  int width;
  int length;
  Rectangle1(int w, int l) {
    width = w;
    length = l;
  }
  Rectangle1() {
    width = 0;
    length = 0;
  }
  bool operator>(const Rectangle1& other) const {
    return (width + length > other.width + other.length);
  }
  bool operator>=(const Rectangle1& other) const {
    return (width + length >= other.width + other.length);
  }
  bool operator==(const Rectangle1& other) const {
    return (width + length == other.width + other.length);
  }
  bool operator<(const Rectangle1& other) const {
    return (width + length < other.width + other.length);
  }
  bool operator<=(const Rectangle1& other) const {
    return (width + length <= other.width + other.length);
  }
};

class Rectangle {
public:
  int width;
  int length;
  Rectangle(int w, int l) {
    width = w;
    length = l;
  }
  Rectangle() {
    width = 0;
    length = 0;
  }
};

class PerimeterCompare {
public:
  bool operator() (const Rectangle& lhs, const Rectangle& rhs) const {
    return (lhs.width + lhs.length) < (rhs.width + rhs.length);
  }
};

class AreaCompare {
public:
  bool operator() (const Rectangle& lhs, const Rectangle& rhs) const {
    return (lhs.width*lhs.length) < (rhs.width*rhs.length);
  }
};


int main() {
  Rectangle rec(4,5);
  Rectangle rec1(1,19);
  PerimeterCompare pc;
  AreaCompare ac;
  cout << "rec < rec1 (perimeter): " << pc(rec,rec1) << endl;
  cout << "rec < rec1 (area): " << ac(rec,rec1) << endl;
}
