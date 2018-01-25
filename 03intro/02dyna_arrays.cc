/*
 * Copyright 2018
 * Created by Jeremy S Lewis
 * Modified by Hunter Damron - 2018
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void pp(int* arr, int n) {
  int cols = 5;
  for (int i = 0; i < n; ++i) {
      cout << arr[i] << "\t";
    if ((i + 1) % cols == 0) {
      cout << endl;
    }
  }
  if (n % cols != 0)
    cout << endl;
}

int main(int argc, char** argv) {
  // create an int pointer to hold a dynamic array
  int* arr = nullptr;

  // prompt user for the size of the array
  int n;
  cout << "Enter size of array: ";
  cin >> n;

  // request memory for an array of given size
  arr = new int[n];

  // fill array with integers from -100 to -100 + size
  for (int i = 0; i < n; ++i) {
    arr[i] = -100 + i;
  }

  cout << "Original array:" << endl;
  pp(arr, n);

  // double array, while retaining the original values
  int* copy = new int[2*n];
  for (int i = 0; i < n; ++i) {
    copy[i] = arr[i];
  }
  int* tmp = arr;
  arr = copy;
  delete [] tmp;

  cout << "Doubled array:" << endl;
  pp(arr, 2*n);

  // half array while retaining the original size / 2 values
  copy = new int[n/2];
  for (int i = 0; i < n/2; ++i) {
    copy[i] = arr[i];
  }
  tmp = arr;
  arr = copy;
  delete [] tmp;

  cout << "Halved array:" << endl;
  pp(arr, n/2);

  delete [] arr;

  return 0;
}
