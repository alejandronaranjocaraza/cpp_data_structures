#include <iostream>

int main() {
  int number = 1;
  int arr[5] = {1,2,3,4,5};
  int *pNumber = &number;
  int *pArr = arr;
  std::cout<<"Number reference adress: "<<pNumber<<std::endl;
  std::cout<<"Number reference value: "<<*pNumber<<std::endl;
  std::cout<<"Array reference adress: "<< pArr<<std::endl;
  std::cout<<"Array reference value: "<< *pArr<<std::endl;
  
  return 0;
}
