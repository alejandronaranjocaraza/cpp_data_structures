#include <iostream>
using namespace std;

template <typename Object>
class Node {
  Object data;
  Node* prev;
  Node* next;

  //Copy constructor through const L-Value reference
  Node(const Object& d = Object{}, Node* p = nullptr, Node* n = nullptr)
  : data{d}, prev{p}, next{n} {}
  
  //Move constructor through R-Value reference
  Node(Object&& d, Node* p = nullptr, Node* n = nullptr)
  : data{std::move(d)}, prev{p}, next{n} {}

};

int main() {
  const int& i = {};
  cout << i;
}
