#include <iostream>

int main () {
  int var = 8;
  int* ptr = &var;
  std::cout << "Memory Adress: " << ptr << std::endl;
  std:: cout << "Value: " <<  *ptr << std::endl;
  *ptr = 99;
  std::cout << "Memory Adress: " << ptr << std::endl;
  std:: cout << "Value: " <<  *ptr << std::endl;
  // Char pointer
  char* charptr = new char[8]; // points to beggining
  //delete[] charptr; // delete data backwards
  // Double pointer
  char** doubleptr = &charptr;
}
