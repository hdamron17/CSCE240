/* Copyright 2018 */
#include "dollar2.h"

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

// update to use cents, only
/* ToDollar */
const Dollar Dollar::ToDollar(double val) {
  // extract dollars portion of val and reduce by that amount
  int dollars = static_cast<int>(val);
  val -= dollars;

  // shift value two places left and store as cents
  double cents = 100.0*val;

  // create and return Dollar struct instance
  return Dollar(dollars, cents);
}

// update to use cents, only
/* ToString */
const string Dollar::ToString() const {
  // add dollars value to string
  StrStr sStr;
  sStr << dollars_ << '.';

  // round cents and cast to int
  int cents = static_cast<int>(round(cents_));
  if (10.0 > cents)
    sStr << "0";
  sStr << cents;
  // and return
  return sStr.str();
}

// update to use cents, only
/* Add */
const Dollar Dollar::Add(const Dollar& rhs) {
  // create Dollar instance with sum of dollars
  Dollar sum(dollars_ + rhs.dollars_);

  // sum cents and when greater than 99, add 1 to dollars and reduce by 100
  sum.cents_ = cents_ + rhs.cents_;
  if (100.0 < sum.cents_ || fpeq(100.0, sum.cents_)) {
    ++sum.dollars_;

    sum.cents_ -= 100.0;
  }

  return sum;
}
