//
// BASIC C++ QUEUE ADT
// Very basic:
//  - Does not include iterators/nodes
//  - Does not support generic data type (only int)
//

#include <iostream>

const int maxSize = 50;
class Queue {
public:
  Queue() {
    m_last = 0;
    m_first = 0;
  }

  void enqueue(int value) {
    m_queue[m_last] = value;
    if (m_last>= maxSize) {
      m_last = 0;
    }
    else {
      m_last++;
    }
  }

  int dequeue() {
    if(isEmpty()) return -1;
    else {
      return m_queue[m_first++];
    }
  }
  
  bool isEmpty() {
    if(m_last==m_first) return true;
    else return false;
  }
  void print() {
    if (isEmpty()) std::cout << "Empty" << std::endl;
    else {
      for (int value : m_queue)
        std::cout << value << std::endl;
    }
  }
private:
  int m_last;
  int m_first;
  int m_queue[maxSize];
};

int main() {
  Queue myQueue;
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.dequeue();
  return 0;
}
