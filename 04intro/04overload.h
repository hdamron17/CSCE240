/* Copyright 2018 */

#ifndef NOTES_04INTRO_04OVERLOAD_H_  // NOLINT(build/header_guard)
#define NOTES_04INTRO_04OVERLOAD_H_

#include <cstdlib>
// using rand
// using srand
#include <ctime>
// using time(nullptr)

#include <iostream>
using std::cout;
using std::endl;

// A function header with two int variables, named Min
int Min(int a, int b);

// A function header with two double variables, named Min
double Min(double a, double b);

// A function header with two char variables named Min
char Min(char a, char b);

#endif  // NOLINT(build/header_guard)
