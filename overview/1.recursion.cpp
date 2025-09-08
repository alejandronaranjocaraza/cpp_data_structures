#include <iostream>
using namespace std;
// 1.3 RECURSION
//
// Basic recursion rules
// 1. Base case: Can be solved without recursion
// 2. Making progress: Other than base case, solutions must make progress until reachining break
// 3. Design: Assume that all recursive calls work
// 4. Compound interest: Never duplicate work by solving same instance of a problem in seperate recursive calls.

// Simple recursive function
// - Inclues base case
// - Base case also works as function break
int f(int x) {
  if (x==0)
    return 0;
  else
    return 2*f(x-1) + x*x;
}

int run_f() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  cout << "f(" << n << ") = " << f(n) <<endl;
  return 0;
}

int main() {
  run_f();
}
