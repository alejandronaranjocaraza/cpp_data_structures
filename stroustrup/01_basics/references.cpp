#include <iostream>

void increment(int& x) {
  x++;
}

void increment2(int* ptr) {
  (*ptr)++;
}

int main () {
  int a = 2;
  int& b = a; //alias
  increment(a);
  std::cout << a << std:: endl;
  int* ptr = &a;
  increment2(ptr);
  std::cout << a << std:: endl;
}
