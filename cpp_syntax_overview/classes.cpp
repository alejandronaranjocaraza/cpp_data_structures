#include <algorithm>
#include <cmath> // For math functions
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class Cylinder {
public:
  double base_radius{1.0};
  double height{1.0};

public:
  double volume() { return 3.14 * base_radius * base_radius * height; }
};

int main() {
  Cylinder cylinder1;
  cylinder1.height = 1;
  std::cout << cylinder1.height << std::endl;
  std::cout << cylinder1.base_radius << std::endl;
  std::cout << cylinder1.volume() << std::endl;

  Cylinder *p_cylinder1 = &cylinder1;
  std::cout << (*p_cylinder1).height << std::endl;
  std::cout << p_cylinder1->height << std::endl;
  std::cout << (*p_cylinder1).base_radius << std::endl;
  std::cout << p_cylinder1->base_radius << std::endl;
  std::cout << (*p_cylinder1).volume() << std::endl;
  std::cout << p_cylinder1->volume() << std::endl;

  std::cout << p_cylinder1 << std::endl;

  // Cylinder cylinder2;
  // cylinder2.height=2;
  Cylinder *p_cylinder2 = new Cylinder;

  std::cout << (*p_cylinder2).height << std::endl;
  std::cout << p_cylinder2 -> volume() << std::endl;
  std::cout << p_cylinder2 << std::endl;
  delete p_cylinder2;
  p_cylinder2=nullptr;
  return 0;
}

//DESTRUCTURS
//POLYMORPHISM
