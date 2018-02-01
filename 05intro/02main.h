/* Copyright 2018 */

// Update define guards
#ifndef LECT_05INTRO_02MAIN_H_  // NOLINT
#define LECT_05INTRO_02MAIN_H_  // NOLINT

// remove libraries no longer needed
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

// include dollar header
#include "dollar.h"

// Move struct to its own class file dollar.h/cc and update
/* A passive structure to hold dollars.
 *  - Per Google style guide, can only have the following members: constructor,
 *    destructor, Initialize(), Reset(), Validate()
 *  - Whole dollars are stored as integers, cents are stored as floating points.
 */
struct Dollar {
  // 1: Constructors for 0, 1 , or 2 parameters.
  Dollar() : dollars(0), cents(0.0) {};
  Dollar(int d_param) : dollars(d_param), cents(0.0) {};
  Dollar(double c_param) : dollars(0), cents(c_param) {};
  Dollar(int d_param, double c_param) : dollars(d_param), cents(c_param) {};

  // structure members
  int dollars;
  double cents;
};

/*
 * Generates a menu to prompt user. Should be called before each loop
 * iteration.
 */
void Prompt();

// Move to dollar.h and update to method
/* Accepts a floating point value and returns a Dollar struct instance. */
const Dollar ToDollar(double val);

// Move to dollar.h and update to method
/* Accepts a Dollar instance and returns a string value as
 * [-]<int_value>[.<int_value>], where the second int_value is in [0, 99]
 */
const string ToString(const Dollar& val);

/*
 * Prompts user for double and creates and returns Dollar stuct.
 * Param:
 *  - a value allowing function's prompt to be aligned with menu/etc
 */
const Dollar GetDollarInput(const string& align = "");

// Move to dollar.h and update to method
/* Returns a new Dollar instance which represents the sum of lhs + rhs */
const Dollar Add(const Dollar& lhs, const Dollar& rhs);

#endif  // NOLINT
