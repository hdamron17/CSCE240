/* Copyright 2018 */
#include "01main.h"

/* Prompt */
void Prompt() {
  cout << " 1.) Set first dollar variable.\n";
  cout << " 2.) Set second dollar variable.\n";
  cout << " 3.) Add variables and display.\n";
  cout << " 4.) Quit." << endl;
  cout << " >>> ";
}

/* ToDollar */
const Dollar ToDollar(double val) {
  // extract dollars portion of val and reduce by that amount
  int dollars = static_cast<int>(val);

  // shift val two places left and store as cents
  double cents = (val - dollars) * 100.0;

  // create and return Dollar struct instance
  return Dollar(dollars, cents);
}

/* ToString */
const string ToString(const Dollar& val) {
  StrStr str_str; 

  // add dollars value to string with StringStream instance
  str_str << "$" << val.dollars;

  // shift cents two places left, round, and shift back two place right
  str_str << ".";
  int cents = static_cast<int>(round(val.cents));
  if (cents < 10)
    str_str << "0";
  str_str << cents;

  //   and return
  return str_str.str();
}

/* GetDollarInput */
const Dollar GetDollarInput(const string& align) {
  // prompt user for dollar value as floating point and assert it's non-negative
  double value;
  cout << align << "Input dollar value as positive floating point: ";
  cin >> value;
  assert(value >= 0.0);

  // cast value to int to get dollars and remove dollars from value  

  // calc cents by shifting two places left

  return ToDollar(value);
}

/* Add */
const Dollar Add(const Dollar& lhs, const Dollar& rhs) {
  // create Dollar instance with sum of dollars
  Dollar sum(lhs.dollars + rhs.dollars);
  // sum cents and when >= 100, add 1 to dollars and reduce by 100
  sum.cents = lhs.cents + rhs.cents;
  assert(sum.cents < 200.0);

  if (sum.cents > 100) {
    sum.cents -= 100;
    sum.dollars += 1;
  }

  return sum;
}

/* main */
int main(int argc, char* argv[]) {
  int input;
  Dollar first, second;

  cout << "Dollar Adder" << endl;  // Display app name
  do {
    // prompt and get input
    Prompt();
    cin >> input;

    if (cin.eof()) {
      input = 4;
      cout << endl;
      break;
    }

    if (cin.fail()) {
      input = -1;
      cin.clear();
      string dummy;
      cin >> dummy;
    }

    // switch on input as indicated in prompt menu
    switch (input) {
    case 1:
      first = GetDollarInput();
      break;
    case 2:
      second = GetDollarInput();
      break;
    case 3: // display as <dollar> + <dollar> = <dollar>
      cout << ToString(first) << " + " << ToString(second) << " = " << ToString(Add(first, second));
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
