//
// 2. Write a function to output an arbitrary double number
// (which might be negative) using only printDigit for I/O.
//

#include <cstdio>
#include <iostream>
using namespace std;

void printDigit(int c) {
  putchar('0'+c);
}

void printInteger(double num) {
  int integ = num;
  if (integ >= 10) {
    printInteger(integ / 10);
  }
  printDigit(integ % 10);
}

void printDecimals(double num) {
  double next = num * 10;
  int nextInt = next;
  printDigit(nextInt % 10);
  if (nextInt < next) {
    printDecimals(next);
  }
}

int main() {
  double numb = -322.350991;
  int numbInt = numb;
  if (numb < 0) {
    putchar('-');
    numb = numb * (-1);
  }
  printInteger(numb);
  if (numb > numbInt) {
    putchar('.');
    printDecimals(numb);
  }
  return 0;
}
