#include <iostream>
#include <utility>

template <typename Object>
class List;

template <typename Object>
class Node {
public:
  Object data;
  Node<Object>* prev;
  Node<Object>* next;

  //Copy constructor through const L-Value reference
  Node(const Object& d = Object{}, Node<Object>* p = nullptr, Node<Object>* n = nullptr)
  : data{d}, prev{p}, next{n} {}
  
  //Move constructor through R-Value reference
  Node(Object&& d, Node<Object>* p = nullptr, Node<Object>* n = nullptr)
  : data{std::move(d)}, prev{p}, next{n} {}

};

template <typename Object>
class const_iterator {
public:
  const_iterator() : current{nullptr}
    {}
  const Object& operator*() const {
    return retrieve();
  }
  const_iterator& operator++() {
    current = current->next;//shorthand (*current).next
    return *this;
  }
  const_iterator operator++(int) {
    const_iterator old = *this;
    ++(*this);
    return old;
  }
  const_iterator& operator--() {
    current = current->prev;
    return *this;
  }
  const_iterator operator--(int) {
    const_iterator old = *this;
    --(*this);
    return old;
  }
  bool operator==(const const_iterator& rhs) const {
    return (current == rhs.current);
  }
  bool operator!=(const const_iterator& rhs) const {
    return !(*this == rhs);
  }

protected:
  Node<Object>* current;
  Object& retrieve() const {
    return current->data;//shorthand for (*current).data
  }
  const_iterator(Node<Object>* p) : current{p}
    {}
  friend class List<Object>;
};

template <typename Object>
class iterator : public const_iterator<Object> {
public:
  iterator() {}
  Object& operator*() {
    return const_iterator<Object>::retrieve();
  }
  const Object& operator*() const {
    return const_iterator<Object>::operator*();
  }
  iterator& operator++() {
    this->current = this->current->next;
    return *this;
  }
  iterator operator++(int) {
    iterator old = *this;
    ++(*this);
    return old;
  }
  iterator& operator--() {
    this->current = this->current->prev;
    return *this;
  }
  iterator operator--(int) {
    iterator old = *this;
    --(*this);
    return old;
  }
protected:
  iterator(Node<Object>* p) : const_iterator<Object>{p} {}
  friend class List<Object>;
};


template <typename Object>
class List {
public:
  List() {
    init();
  }
  ~List() {
    clear();
    delete head;
    delete tail;
  }
  List(const List& rhs) {
    init();
    for(auto& x:rhs) {
      push_back(x);//!!!!!!!!!!!!!!!!!
    }
  }
  List& operator= (const List& rhs) {
    List copy = rhs;
    std::swap(*this,copy);////!!!!!!
    return *this;
  }
  List(List&& rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail} {
    rhs.theSize = 0;
    rhs.tail = nullptr;
    rhs.head = nullptr;
  }
  List& operator= (List&& rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    return *this;
  }
  iterator<Object> begin() {
    return head->next;//!!!!!!!!!!!!!!!!
  }
  const_iterator<Object> begin() const {
    return head->next;//!!!!!!!!!!!!!!!1
  }
  iterator<Object> end() {
    return tail;
  }
  const_iterator<Object> end() const {
    return tail;
  }
  int size() const {
    return theSize;
  }
  bool empty() const {
    return size()==0;
  }
  void clear() {
    while(!empty())
      pop_front();
  }
  Object& front() {
    return *begin();
  }
  const Object& front() const {
    return *begin();
  }
  Object& back() {
    return *--end();/////!!!!!!!!!!
  }
  const Object& back() const {
    return *--end();
  }
  void push_front(const Object& x) {
    insert(begin(),x);//!!!!!!!!!!
  }
  void push_front(Object&& x) {
    insert(begin(),std::move(x));
  }
  void push_back(const Object& x) {
    insert(end(),x);//!!!!!!!!!!
  }
  void push_back(Object&& x) {
    insert(end(),std::move(x));
  }
  void pop_front() {
    erase(begin());
  }
  void pop_back() {
    erase(--end());
  }
  iterator<Object> insert(iterator<Object> itr, const Object& x) {
    Node<Object>* p = itr.current;
    theSize++;
    return {p->prev = p->prev->next = new Node<Object>{ x, p->prev, p}};
  }
  iterator<Object> insert(iterator<Object> itr, Object&& x) {
    Node<Object>* p = itr.current;
    theSize++;
    return {p->prev = p->prev->next = new Node<Object>{std::move(x), p->prev, p}};
  }
  iterator<Object> erase(iterator<Object> itr) {
    Node<Object>* p = itr.current;
    iterator retVal{p->next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;
    return retVal;
  }
  iterator<Object> erase(iterator<Object> from, iterator<Object> to) {
    for(iterator itr = from; itr!=to;)
      itr = erase(itr);
    return to;
  }


private:
  int theSize;
  Node<Object> *head;
  Node<Object> *tail;

  void init() {
    theSize = 0;
    head = new Node<Object>();//pointer
    tail = new Node<Object>();//pointer
    head->next = tail;//same as (*head).next = tail;(dereference)
    tail->prev = head;//same ad (*tail).prev = head;(dereference)
  }
};

int main() {
  List<int> lst;
  lst.push_back(10);
  lst.push_front(5);
  std::cout << lst.front() << " " << lst.back() << "\n";
}
