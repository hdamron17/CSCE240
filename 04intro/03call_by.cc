/* Copyright 2018 */
#include "03call_by.h"  // NOLINT

// Write function body named SwapByVal which attempts to swap ints a and b
void SwapByVal(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// Write function body SwapByRef which attempts to swap ints a and b
void SwapByRef(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main(int argc, char* argv[]) {
  // seed random number generate with current time
  srand(time(nullptr));

  // create two ints and randomly assign vals from [1, 100]
  int f = rand() % 100 + 1,  // NOLINT(runtime/threadsafe_fn)
      s = rand() % 100 + 1;  // NOLINT(runtime/threadsafe_fn)

  // display f and s's values
  cout << "f = " << f << "; s = " << s << endl;

  // call SwapByVal and show it does not.
  SwapByVal(f, s);
  cout << "f = " << f << "; s = " << s << endl;

  // call SwapByRef and show it does.
  SwapByRef(f, s);
  cout << "f = " << f << "; s = " << s << endl;

  return 0;
}

