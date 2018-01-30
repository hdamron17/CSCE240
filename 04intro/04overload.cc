/* Copyright 2018 */
#include "04overload.h"  // NOLINT(build/include_subdir)


// A function body with two int variables, named Min
int Min(int a, int b) {
  return (a < b) ? a : b;
}

// A function body with two double variables, named Min
double Min(double a, double b) {
  return (a < b) ? a : b;
}

// A function body with two char variables named Min
char Min(char a, char b) {
  return (a < b) ? a : b;
}

int RandInt(int lower, int upper) {
  int range = upper - lower + 1;  // Plus 1 to include first and last numbers
  return rand() % range + lower;
}

double RandDouble(double lower, double upper) {
  double range = upper - lower;
  double uniform = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
  return uniform * range + lower;
}

char RandChar(char lower, char upper) {
  char range = upper - lower + 1;
  return rand() % range + lower;
}

int main(int argc, char* argv[]) {
  // seed random number generate with current time
  srand(time(nullptr));

  // create two elem int array and randomly assign integer vals from [1, 100]
  int int_arr[] = { RandInt(1, 100), RandInt(1, 100) };

  // create two elem double array and randomly assign FP vals from [1.0, 100.0]
  double double_arr[] = { RandDouble(1, 100), RandDouble(1, 100) };

  // create two elem char array and randomly assign integer vals from [A, Z]
  char char_arr[] = { RandChar('A', 'Z'), RandChar('A', 'Z') };

  // display the min of each set
  cout << "Min(" << int_arr[0] << ", " << int_arr[1] << ") = " \
    << Min(int_arr[0], int_arr[1]) << endl;

  // display min of int and double

  return 0;
}

