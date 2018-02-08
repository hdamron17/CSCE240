/* Copyright 2018 */

#ifndef LECT_06INTRO_DOLLAR2_H_  // NOLINT
#define LECT_06INTRO_DOLLAR2_H_  // NOLINT

#include <cassert>
// using assert
#include <cmath>
// using round
#include <sstream>
typedef std::stringstream StrStr;
#include <string>
using std::string;

/* A class to represent dollars.
 *  - Dollars are stored as floating points which is a count of the cents of
 *    each dollar.
 */
class Dollar {
public:
  // 1: Constructors for 0, 1 , or 2 parameters.
  Dollar() : dollars_(0), cents_(0.0) {};
  Dollar(int dollars) : dollars_(dollars), cents_(0.0) {};
  Dollar(double cents) : dollars_(0), cents_(cents) {};
  Dollar(int dollars, double cents) : dollars_(dollars), cents_(cents) {};

  /* A static method, accepting a floating point value and returning a Dollar
   * class instance.
   */
  static const Dollar ToDollar(double val);
  
  /* Returns a string value as [-]<int_value>.<int_value>, where the second
   * int_value is in [0, 99]
   */
  const string ToString() const;

  /* Returns a new Dollar instance which represents the sum of this + rhs */
  const Dollar Add(const Dollar& rhs);
private:
  // class members
  int dollars_; // remove and store everything in cents
  double cents_;
};


#endif  // NOLINT
