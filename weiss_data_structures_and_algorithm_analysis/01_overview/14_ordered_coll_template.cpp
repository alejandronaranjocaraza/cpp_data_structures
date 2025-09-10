#include <iostream>
using namespace std;

template <typename Object> class OrderedCollection {
public:
  OrderedCollection() = default;
  void insert(const Object& elem) {
    if (size >= 100)
      return;
    arr[size] = elem;
    size++;
  }
  Object operator[](int index) const {
    return arr[index];
  }
  void remove(int index) {
    if (index < 0 || index >= size)
      return;
    for (int j = index; j < size; j++) {
      arr[j] = arr[j + 1];
    }
    size--;
  }
  bool isEmpty() const { return (size == 0); }
  void makeEmpty() { size = 0; }
  int findMin() const {
    int minInd = 0;
    for (int i = 0; i < size; i++) {
      if (arr[i] < arr[minInd])
        minInd = i;
    }
    return minInd;
  }
  int findMax() const {
    int maxInd = 0;
    for (int i = 1; i < size; i++) {
      if (arr[i] > arr[maxInd])
        maxInd = i;
    }
    return maxInd;
  }

private:
  Object arr[100];
  int size = 0;
};

int main() {
  OrderedCollection<int> arr;
  arr.insert(3);
  arr.remove(0);
  arr.insert(128);
  arr.insert(3);
  arr.insert(1);
  cout << "Min at: " << arr.findMin() << endl;
  cout << "Max at: " << arr.findMax() << endl;
  int indMin = arr.findMin();
  int indMax = arr.findMax();
  cout << "Min: " << arr[indMin] << endl;
  cout << "Max: " << arr[indMax] << endl;
  return 0;
}
