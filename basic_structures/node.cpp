#include <iostream>

template <typename Object> class Node {
public:
  Node(const Object &data = Object{}, Object *next = nullptr,
       Object *prev = nullptr)
      : data(data), next(next), prev(prev) {}
  Node(Object &&data = Object{}, Object *next = nullptr, Object *prev = nullptr)
      : data(std::move(data)), next(next), prev(prev) {}

private:
  Object data;
  Node<Object> *prev;
  Node<Object> *next;
};
