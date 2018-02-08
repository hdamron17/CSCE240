/* Copyright 2018 */
#include "02main.h"

/* Prompt */
void Prompt() {
  cout << " 1.) Set first dollar variable.\n";
  cout << " 2.) Set second dollar variable.\n";
  cout << " 3.) Add variables and display.\n";
  cout << " 4.) Quit." << endl;
  cout << " >>> ";
}

// Update to use Dollar class
/* GetDollarInput */
const Dollar GetDollarInput(const string& align) {
  // prompt user for dollar value as floating point and assert it's non-negative
  double value;
  cout << align << "Input dollar value as positive floating point: ";
  cin >> value;
  assert(0.0 <= value);

  return Dollar::ToDollar(value);
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
      first = GetDollarInput(" ");
      cout << " first: " << first.ToString() << endl;
      break;
    case 2:
      second = GetDollarInput(" ");
      cout << " second: " << second.ToString() << endl;
      break;
    case 3:
      cout << first.ToString() << " + " << second.ToString() << " = " <<
          first.Add(second).ToString() << endl;
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
