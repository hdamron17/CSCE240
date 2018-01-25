/* Modified by Hunter Damron - 2018 */

/* Copyright 2018 */

// Include the C limits system library for INT_MAX const variable
#include <climits>

// Include the iostream system library for cout and endl.
// Introduce cout and endl from the std namespace to this file's scope.
#include <iostream>
using namespace std;

/**
 * Main method. Required entry point for all C++ executables.
 */
int main(int args, char *argv[]) {
  // Create a constant char variable to for the printable tab character.
  const char tab = '\t';

  // Create a signed int variable and assign it the largest signed int for
  //    this machine.
  // Display the message "s_int:<tab><s_int value><newline>"
  // Display the message "s_int:<tab><s_int value> + 1<newline>"
  signed int s_int = INT_MAX;
  cout << "s_int:" << tab << s_int << endl;
  cout << "s_int:" << tab << (s_int + 1) << endl;

  // Create an usigned int variable and assign it s_int's value with a static
  //    cast.
  // Display the message "u_int:<tab><u_int value><newline>"
  // Display the message "u_int:<tab><u_int value> + 1<newline>"
  unsigned int u_int = static_cast<unsigned int>(s_int);
  cout << "u_int:" << tab << u_int << endl;
  cout << "u_int:" << tab << (u_int + 1) << endl;  

  // Create a boolean and assign it the value of u_int + u_int - 2.0*s_int == 0
  // Display "u_int + u_int - 2.0*s_int == 0 : <truth_value><newline>"
  bool truth = (u_int + u_int - 2.0*s_int == 0);
  cout << "u_int + u_int - 2.0*s_int == 0 : " << truth << endl;

  // Create a single precision floating point value called garbage
  // Display garbage's value as "garbage value is <garbage_value><newline>"
  float garbage;
  cout << "garbage value is " << garbage << endl;
}

