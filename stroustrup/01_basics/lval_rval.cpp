#include <iostream>

// Takes lvals and rvals
void printString(const std::string& str) {
  std::cout << "[lvalue]" << str << std::endl;
}

// Takes rvals
void printString(std::string&& str) {
  std::cout << "[rvalue]" << str << std::endl;
}

int main() {
  std::string str = "HELLO";
  printString(str); // defaults to first instance
  printString("BYEBYE"); // defaults to second instance
}

