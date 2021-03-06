/* Copyright 2018 */
#include "dollar2.h"

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
  sStr << "$" << dollars_ << '.';

  // shift cents two places left, round, and shift back two place right
  int cents = static_cast<int>(round(cents_*100.0)/100.0);
  if (10.0 > cents)
    sStr << "0";
  sStr << cents;
  //   and return
  return sStr.str();
}

// update to use cents, only
/* Add */
const Dollar Dollar::Add(const Dollar& rhs) {
  // create Dollar instance with sum of dollars
  Dollar sum(dollars_ + rhs.dollars_);
  // sum cents and when greater than 99, add 1 to dollars and reduce by 100
  sum.cents_ = cents_ + rhs.cents_;
  if (100.0 <= sum.cents_) {
    ++sum.dollars_;

    sum.cents_ -= 100.0;
  }

  return sum;
}
