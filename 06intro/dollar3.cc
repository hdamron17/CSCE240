/* Copyright 2018 */
#include "dollar3.h"

/* Tests two floating point numbers for near-equality usually using the
 * relative error, but also with a lower bound on the absolute error for
 * numbers to be considered different.
 *
 * This code is based on Bruce Dawson's "Comparing Floating Point Numbers" at
 * http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm.
 */
bool fpeq(double a, double b) {
  const double maxAbsoluteError = 0.0001;
  const double maxRelativeError = 0.0001;

  if (fabs(a - b) < maxAbsoluteError) { 
    return true;
  }

  double relativeError;
  if (fabs(b) > fabs(a)) {
   relativeError = fabs((a - b) / b);
  }
  else {
   relativeError = fabs((a - b) / a);
  }

  return (relativeError <= maxRelativeError);
}

/* ToDollar */
const Dollar Dollar::ToDollar(double val) {
  // shift value two places left and store as cents
  val *= 100.0;

  // create and return Dollar struct instance
  return Dollar(val);
}

// update to use cents, only
/* ToString */
const string Dollar::ToString() const {
  StrStr sStr;

  // add dollars value to string
  sStr << (static_cast<int>(cents_) / 100);

  // round and cast to int
  int cents = static_cast<int>(round(cents_)) % 100;
  if (10.0 > cents) {
    sStr << "0";
  }
  sStr << cents;
  // and return
  return sStr.str();
}

ostream& operator<<(ostream& o_str, const Dollar& rhs) {
  return o_str;
}

// update to use cents, only
/* Add */
const Dollar Dollar::Add(const Dollar& rhs) {
  // create Dollar instance for return
  Dollar sum(cents_ + rhs.cents_);

  return sum;
}
const Dollar Dollar::operator+(const Dollar& rhs) {
  return Add(rhs);
}
