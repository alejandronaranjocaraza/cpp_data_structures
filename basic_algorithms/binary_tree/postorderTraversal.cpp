#include <iostream>

template <typename Object>
struct Node {
  Node(const Object& data = Object{}, Node<Object>* left = nullptr, Node<Object>* right = nullptr) :
    data(data),left(left),right(right) {}
  Node(Object&& data, Node<Object>* left = nullptr, Node<Object>* right = nullptr) :
    data(std::move(data)), left(left), right(right) {}
  void addLeft(const Object& val = Object{}) {
    left = new Node<Object>(val);
  }
  void addRight(const Object& val = Object{}) {
    right = new Node<Object>(val);
  }
  Object data;
  Node<Object>* left;
  Node<Object>* right;
};

void postorderPrint(Node<int>* root) {
  if(root == nullptr) return;
  
  postorderPrint(root->left);
  postorderPrint(root->right);
  std::cout << root->data << std::endl;
}
//
//          0
//        /   \
//       1     2
//     /  \   /  \
//    3    4 5    6
//
int main() {
  Node<int>* root = new Node<int>(0);
  root->addLeft(1);
  root->addRight(2);
  Node<int>* left1 = root->left;
  Node<int>* right1 = root->right;
  left1->addLeft(3);
  left1->addRight(4);
  right1->addLeft(5);
  right1->addRight(6);
  postorderPrint(root);
  return 0;
}
