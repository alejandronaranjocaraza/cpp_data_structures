//
// 1. Selection problem: Suppose you have a group of N numbers and would like to determine the kth largest.
//
# include <iostream>
# include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
  int n = arr.size();
  bool swapped;
  for (int i=0;i<n-1;i++){
    swapped = false;
    for (int j=0;j<n-1-i;j++){
      if (arr[j] > arr[j+1]) {
        swap(arr[j],arr[j+1]);
        swapped = true;
      }
    }
    if (!swapped){
      break;
    }
  }
}

int main() {
  vector<int> numbers = {5, 7, 3, 1, 6, 2};
  cout<<"Original vector: ";
  for (int x : numbers) {cout<<x<<" ";}
  cout<<endl;
  int k = 3;
  bubbleSort(numbers);
  int n = numbers.size();
  int k_max = numbers[n-k];
  cout<<k<<"th/rd largest: "<<k_max<<endl;
}
