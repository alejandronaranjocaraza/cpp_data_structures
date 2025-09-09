//
//Design a class template, Collection, that stores a collection of Objects (in an array),
//along with the current size of the collection.
//Provide public functions isEmpty, makeEmpty, insert, remove, and contains.
//contains(x) returns true if and only if an Object that is equal to x is present in the collection.
//

#include <iostream>
#include <vector>
using namespace std;

template <typename Object>
class CollectionVec {
public:
  CollectionVec() = default;
void remove(Object elem) {
    for(int i = 0; i < content.size(); i++) {
      if(content[i] == elem) {
      content.erase(content.begin() + i);
      i--;
      }
    }
  }
void add(Object elem) {
    content.push_back(elem);
  }
void show() const {
    for(Object element : content) {
      cout << element << " ";
    }
  }
bool isEmpty() const {
    return content.empty();
  }
void makeEmpty() {
    content.clear();
  }
bool contains(Object elem) {
    for(int i=0; i < content.size(); i++) {
      if (content[i] == elem) return true;
    }
    return false;
  }
private:
  vector<Object> content;
};

template <typename Object>
class CollectionArr {
public:
CollectionArr() = default;
void insert(const Object& el) {
    if (size >= 100) return;
    arr[size] = el;
    size++;
  }
void remove(int ind) {
    if (ind<0 || ind>=size) return;
    size --;
    for(int i=ind; i<size; i++) {
      arr[i] = arr[i+1];
    }
  }
bool isEmpty() const {
    if (size==0) return true;
    return false;
  }
void makeEmpty() {
    size = 0;
  }
bool contains(const Object& el) const {
    for(int i=0; i<size; i++) {
      if (arr[i] == el) return true;
    }
    return false;
  }

private:
  Object arr[100];
  int size = 0;
};

int main() {
  CollectionVec<int> col;
  cout << col.isEmpty()<<endl;
  col.add(1);
  cout << col.contains(1)<<endl;
  col.remove(1);
  col.show();
  col.makeEmpty();
  cout << col.isEmpty() << endl;
  CollectionArr<int> arr;
  arr.insert(1);
  arr.insert(2);
  cout << arr.isEmpty() << endl;
  arr.makeEmpty();
  cout << arr.isEmpty() << endl;
}
