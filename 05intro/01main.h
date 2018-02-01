/* Copyright 2018 */

#ifndef LECT_05INTRO_01MAIN_H_  // NOLINT
#define LECT_05INTRO_01MAIN_H_  // NOLINT

#include <cassert>
// using assert
#include <cmath>
// using round
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
typedef std::stringstream StrStr;
#include <string>
using std::string;

/* A passive structure to hold dollars.
 *  - Per Google style guide, can only have the following members: constructor,
 *    destructor, Initialize(), Reset(), Validate()
 *  - Whole dollars are stored as integers, cents are stored as floating points.
 */
struct Dollar {
  // 1: Constructors for 0, 1 , or 2 parameters.
  Dollar() : dollars(0), cents(0.0) {};
  Dollar(int d) : dollars(d), cents(0.0) {};
  Dollar(int d, double c) : dollars(d), cents(c) {};

  // structure members
  int dollars;
  double cents;
};

/*
 * Generates a menu to prompt user. Should be called before each loop
 * iteration.
 */
void Prompt();

/* Accepts a floating point value and returns a Dollar struct instance. */
const Dollar ToDollar(double val);

/* Accepts a Dollar instance and returns a string value as
 * $[-]<int_value>.<int_value>, where the second int_value is in [0, 99]
 */
const string ToString(const Dollar& val);

/*
 * Prompts user for double and creates and returns Dollar stuct.
 * Param:
 *  - a value allowing function's prompt to be aligned with menu/etc
 */
const Dollar GetDollarInput(const string& align = "");

/* Returns a new Dollar instance which represents the sum of lhs + rhs */
const Dollar Add(const Dollar& lhs, const Dollar& rhs);

#endif  // NOLINT
