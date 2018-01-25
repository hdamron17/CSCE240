/*
 * Copyright 2018
 * Created by Jeremy S Lewis
 * Modified by Hunter Damron - 2018
 */

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv) {
  // create a const int to hold the size of the array
  // use the const int to create an array
  const int kSize = 100;
  int arr[kSize];

  // store integers 1 to n in the array, where n is the size of the array
  for (int i = 0; i < kSize; ++i) {
    arr[i] = i+1;
  }

  // determine the sum of the n integers stored in the array
  // display the sum
  int sum = 0;
  for (int i = 0; i < kSize; ++i) {
    sum += arr[i];
  }
  cout << "Sum: " << sum << endl;

  // create a second array and copy each value, doubled, from the first
  int second[kSize];
  for (int i = 0; i < kSize; ++i) {
    second[i] = 2 * arr[i];
  }

  // display both arrays, 1 element of each per line, tab delimited
  for (int i = 0; i < kSize; ++i) {
    cout << arr[i] << "\t" << second[i] << endl;
  }

  return 0;
}
