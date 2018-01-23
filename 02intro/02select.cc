/* Modified by Hunter Damron - 2018 */

/* Copyright 2018 */

// Include the iostream system lib for cin, cout, and endl
#include <iostream>
// Introduce qualified names for cin, cout, and endl, to file's global scope
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  // Use single expression to display
  // "Hello Reader.
  // Welcome to C++"

  double gpa; // a double precision floating point value
  // Prompt user to enter percent GPA from CSCE146 and accept input on the same
  // line.
  cout << "Enter percent GPA from CSCE146: ";

  // Get value from console buffer into gpa variable
  cin >> gpa;

  // Use selection statement to
  //  Display:
  //   "That cannot be correct."
  //  and return 1 from main when value is negative,
  if (gpa < 0.0) {
    cout << "That cannot be correct" << endl;
    return 1;
  }

  //  Display:
  //  "What are you doing here?!"
  //  when gpa is less than a 70, and
  if (gpa < 70) {
    cout << "What are you doing here?!" << endl;
  }

  //  Display:
  //   "Welcome to Software Development."
  //  when gpa is 70.0 or greater.
  else {
    cout << "Welcome to Software Development" << endl;
  }

  unsigned short langs; // an unsigned short value
  // Prompt user with
  //  "How many programming languages have you used? "
  // without a newline.
  cout << "How many programming languages have you used? ";

  // Get value from console input and move into langs variable
  cin >> langs;

  // Use selection statement to
  //  Display
  //   "I thought you said you passed Java..."
  //  and return a 1 from main when langs value is 0,
  if (langs == 0) {
    cout << "I thought you said you passed Java..." << endl;
    return 1;
  }

  //  Display "This class may be challenging<newline>" when langs value is 1,
  else if (langs == 1) {
    cout << "This class may be challenging" << endl;
  }

  //  Display "This class will be fun<newline>" when langs value is 2,
  else if (langs == 2) {
    cout << "This class will be fun" << endl;
  }

  //  Display
  //   "This class might be interesting<newline>"
  //  when langs value is 3, and
  else if (langs == 3) {
    cout << "This class might be interesting" << endl;
  }

  //  Display
  //   "Easy mode"
  //  otherwise
  else if (langs > 3) {
    cout << "Easy mode" << endl;
  }

  return 0; // return 0 for correct exit
}
