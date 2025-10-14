//
// BASIC C++ STACK ADT
// Very basic:
//  - Does not include iterators/nodes
//  - Does not support generic data type (only int)
//  - Does not include proper overflow protection
//

#include <iostream>

const int max_size = 50;

class Stack {
public:
  Stack() {
    m_last = 0;
  }
  bool isEmpty() const { return (m_last==0); }
  int peek() const {
    if (isEmpty())
      return -1;
    else
      return m_stack[m_last-1];
  }
  void push(const int &x) {
    if (m_last<=max_size)
      m_stack[m_last++] = x;
    else {}
  }
  int pop() {
    if (m_last == 0)
      return -1;
    else {
      return m_stack[--m_last];
    }
  }

private:
  int m_last;
  int m_stack[max_size];
};

int main() {
  Stack myStack;
  myStack.push(1);
  myStack.push(2);
  std::cout << myStack.isEmpty() << std::endl;
  std::cout << myStack.pop() << std::endl;
  std::cout << myStack.pop() << std::endl;
  std::cout << myStack.isEmpty() << std::endl;
}
