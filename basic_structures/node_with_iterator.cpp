#include <iostream>

template <typename Object>
struct Node {
  Object data;
  Node<Object>* next;
  Node<Object>* prev;
  Node(const Object& node_data, Node<Object>* next_node = nullptr, Node<Object>* prev_node = nullptr)
      : data(node_data), next(next_node), prev(prev_node) {}
  Node(Object&& node_data = Object{}, Node<Object>* next_node = nullptr, Node<Object>* prev_node = nullptr)
      : data(std::move(node_data)), next(next_node), prev(prev_node) {}
};

template <typename Object>
class const_iterator {
public:
  const_iterator() : current(nullptr) {}
  const_iterator(Node<Object>* nodeptr) : current(nodeptr) {}
  const Object& operator*() const{
    return retrieve();
  }
  const_iterator& operator++() {
    current = current->next;
    return *this;
  }
  const_iterator operator++(int) {
    const_iterator temp = *this;
    current = current->next;
    return temp;
  }
  const_iterator& operator--() {
    current = current->prev;
    return *this;
  }
  const_iterator operator--(int) {
    const_iterator temp = *this;
    current = current->prev;
    return temp;
  }
  bool operator==(const const_iterator& rhs) {
    return (current==rhs.current);
  }
  bool operator!=(const const_iterator& rhs) {
    return (current!=rhs.current);
  }

//protected:
  Node<Object>* current;
  Object& retrieve() const {
    return (current->data);
  }
};

int main() {
  Node<int> end;
  Node<int> node2(2, &end);
  Node<int> node1(1,&node2);
  Node<int> node0(0,&node1);
  const_iterator<int> iter(&node0);
  while(iter.current!=&end) {
    int dat = *iter;
    std::cout << dat << std::endl;
    iter++;
  }

  return 0;
}
