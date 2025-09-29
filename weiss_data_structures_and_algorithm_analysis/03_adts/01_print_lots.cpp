//
//1. You are given a list, L, and another list, P, containing integers sorted in ascending
//order. The operation printLots(L,P) will print the elements in L that are in positions
//specified by P. For instance, if P = 1, 3, 4, 6, the elements in positions 1, 3, 4, and 6
//in L are printed. Write the procedure printLots(L,P). You may use only the public
//STL container operations. What is the running time of your procedure?
//


#include <utility>
using namespace std;

#include <iostream>

template <typename Object> class List;

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
    return this->retrieve();
  }
  const Object& operator*() const {
    return this->operator*();
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
protected:
  iterator(Node<Object>* p) : const_iterator<Object>(p) {}
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
  typename List<Object> :: iterator begin() {
    return head->next;//!!!!!!!!!!!!!!!!
  }
  const_iterator<Object> begin() const {
    return head->next;//!!!!!!!!!!!!!!!1
  }
  typename List<Object>::iterator end() {
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
  typename List<Object>::iterator insert(iterator itr, const Object& x) {
    Node<Object>* p = itr.current;
    theSize++;
    return {p->prev = p->prev->next = new Node<Object>{ x, p->prev, p}};
  }
  iterator insert(iterator itr, Object&& x) {
    Node<Object>* p = itr.current;
    theSize++;
    return {p->prev = p->prev->next = new Node<Object>{std::move(x), p->prev, p}};
  }
  iterator erase(iterator itr) {
    Node<Object>* p = itr.current;
    iterator retVal{p->next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;
    return retVal;
  }
  iterator erase(iterator from, iterator to) {
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

void printLots(const List<int>& L,const List<int>& P) {
  for(auto iterP = P.begin(); iterP != P.end(); iterP++) {
    int pos = *iterP;
    auto iterL = L.begin();
    for(int p = 0; p < pos; p++) {
      iterL++;
    }
    std::cout << *iterL;
  }
}


int main() {
    List<int> L;
    L.push_back(11);
    L.push_back(33);
    L.push_back(55);
    L.push_back(77);
    List<int> P;
    P.push_back(1);
    P.push_back(3);
    printLots(L,P);
}
