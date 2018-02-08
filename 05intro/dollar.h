/* Copyright 2018 */

#ifndef LECT_05INTRO_DOLLAR_H_  // NOLINT
#define LECT_05INTRO_DOLLAR_H_  // NOLINT

#include <cassert>
// using assert
#include <cmath>
// using round
#include <sstream>
typedef std::stringstream StrStr;
#include <string>
using std::string;

/* A passive structure to hold dollars.
 *  - Per Google style guide, can only have the following members: constructor,
 *    destructor, Initialize(), Reset(), Validate()
 *  - Whole dollars are stored as integers, cents are stored as floating points.
 */
class Dollar {
public:
  // 1: Constructors for 0, 1 , or 2 parameters.
  Dollar() : dollars_(0), cents_(0.0) {};
  Dollar(int d_param) : dollars_(d_param), cents_(0.0) {};
  Dollar(double c_param) : dollars_(0), cents_(c_param) {};
  Dollar(int d_param, double c_param) : dollars_(d_param), cents_(c_param) {};

  /* Accepts a floating point value and returns a Dollar struct instance. */
  static const Dollar ToDollar(double val);

  /* Accepts a Dollar instance and returns a string value as
   * [-]<int_value>[.<int_value>], where the second int_value is in [0, 99]
   */
  const string ToString() const;

  /* Returns a new Dollar instance which represents the sum of lhs + rhs */
  const Dollar Add(const Dollar& other) const;

private:
  // structure members
  int dollars_;
  double cents_;
};

#endif  // NOLINT
