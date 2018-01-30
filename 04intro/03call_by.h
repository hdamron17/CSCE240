/* Copyright 2018 */

#ifndef NOTES_04INTRO_03CALL_BY_H_  // NOLINT(build/header_guard)
#define NOTES_04INTRO_03CALL_BY_H_

#include <cstdlib>
// using rand
// using srand
#include <ctime>
// using time(nullptr)

#include <iostream>
using std::cout;
using std::endl;

// Write function header named SwapByVal which attempts to swap ints a and b
void SwapByVal(int a, int b);

// Write function header named SwapByRef which attempts to swap ints a and b
void SwapByRef(int& a, int& b);

#endif  // NOLINT(build/header_guard)
