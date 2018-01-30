/* Copyright 2018 */

#ifndef NOTES_04INTRO_05DEFAULT_H_  // NOLINT(build/header_guard)
#define NOTES_04INTRO_05DEFAULT_H_

#include <cstdlib>
// using rand
// using srand
#include <ctime>
// using time(nullptr)

#include <iostream>
using std::cout;
using std::endl;

// A function header with a double and int variables named Pow which raises
// double to the power of int. Set the int with a base value of 2.
double Pow(double base, int exp = 2);

#endif  // NOLINT(build/header_guard)
