/* Copyright 2018 */

#ifndef LECT_06INTRO_DOLLAR3_H_  // NOLINT
#define LECT_06INTRO_DOLLAR3_H_  // NOLINT

#include <cassert>
// using assert
#include <cmath>
// using round
#include <iostream>
using std::ostream;
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
  Dollar() : cents_(0.0) {};
  Dollar(int dollars) : cents_(100.0 * dollars) {};
  Dollar(double cents) : cents_(cents) {};
  Dollar(int dollars, double cents) : cents_(100*dollars + 100*cents) {};

  /* A static method, accepting a floating point value and returning a Dollar
   * class instance.
   */
  static const Dollar ToDollar(double val);
  
  /* Returns a string value as [-]<int_value>.<int_value>, where the second
   * int_value is in [0, 99]
   */
  const string ToString() const;
  friend ostream& operator<<(ostream& o_str, const Dollar& rhs); 

  /* Returns a new Dollar instance which represents the sum of this + rhs */
  const Dollar Add(const Dollar& rhs);
  const Dollar operator+(const Dollar& rhs);
private:
  // class member
  double cents_;
};


#endif  // NOLINT
