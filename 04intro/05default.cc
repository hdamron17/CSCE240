/* Copyright 2018 */
#include "05default.h"  // NOLINT


// A function body with a double and int variables named Pow which raises
// double to the power of int. Set the int with a base value of 2.
double Pow(double base, int exp) {
  bool neg = 0;
  if (exp == 0) {
    return 1;
  } else if (exp < 0) {
    neg = 1;
    exp = -exp;
  }

  double raised = base;
  for (int i = 1; i < exp; ++i) {
    raised *= raised;
  }

  if (neg) {
    raised = 1.0 / raised;
  }

  return raised;
}

int main(int argc, char* argv[]) {
  // seed random number generate with current time
  srand(time(nullptr));

  // create a random double named base with value in [0.0, 100.0]

  // create a random int named pow with value in [-10, 10]

  // display the the value using Pow function, if pow is < 0, use default arg

  return 0;
}

