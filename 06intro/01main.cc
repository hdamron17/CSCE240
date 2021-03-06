/* Copyright 2018 */
#include "01main.h"

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

/* Prompt */
void Prompt(const string& align) {
  cout << align << "1.) Set first dollar variable.\n";
  cout << align << "2.) Set second dollar variable.\n";
  cout << align << "3.) Add variables and display.\n";
  cout << align << "4.) Quit." << endl;
  cout << align << ">>> ";
}

// Move to dollar.cc and update to method
/* ToDollar */
const Dollar ToDollar(double val) {
  // extract dollars portion of val and reduce by that amount
  int dollars = static_cast<int>(val);
  val -= dollars;

  // shift value two places left and store as cents
  double cents = 100.0*val;

  // create and return Dollar struct instance
  return Dollar(dollars, cents);
}

// Move to dollar.cc and update to method
/* ToString */
const string ToString(const Dollar& val) {
  // add dollars value to string
  StrStr sStr;
  sStr << val.dollars << '.';

  // round cents and cast to int
  int cents = static_cast<int>(round(val.cents));
  if (10.0 > cents)
    sStr << "0";
  sStr << cents;
  // and return
  return sStr.str();
}

// Update to use Dollar class
/* GetDollarInput */
const Dollar GetDollarInput(const string& align) {
  // prompt user for dollar value as floating point and assert it's non-negative
  double value;
  cout << align << "Input dollar value as positive floating point: ";
  cin >> value;
  assert(0.0 <= value);

  // cast value to int to get dollars and remove dollars from value
  int dollars = static_cast<int>(value);
  value -= dollars;

  // calc cents by shifting two places left
  double cents = value *= 100.0;

  return Dollar(dollars, cents); 
}

// Move to dollar.cc and update to method
/* Add */
const Dollar Add(const Dollar& lhs, const Dollar& rhs) {
  // create Dollar instance with sum of dollars
  Dollar sum(lhs.dollars + rhs.dollars);
  // sum cents and when greater than 99, add 1 to dollars and reduce by 100
  sum.cents = lhs.cents + rhs.cents;
  if (100.0 <= sum.cents) {
    ++sum.dollars;

    sum.cents -= 100.0;
  }

  return sum;
}

// Update to use Dollar class
int main(int argc, char* argv[]) {
  int input;
  Dollar first, second;

  cout << "Dollar Adder" << endl;  // Display app name
  do {
    // prompt and get input
    Prompt();
    cin >> input;

    // switch on input as indicated in prompt menu
    switch (input) {
    case 1:
      first = GetDollarInput();
      cout << " first: " << ToString(first) << endl;
      break;
    case 2:
      second = GetDollarInput();
      cout << " second: " << ToString(second) << endl;
      break;
    case 3:
      cout << ToString(first) << " + " << ToString(second) << " = " <<
          ToString(Add(first, second)) << endl;
      break;
    case 4:
      break;
    default:
      cout << "  That is not a valid option.\n";
      break;
    }
    cout << endl; // emmit a blank line
  } while (input != 4);
}
