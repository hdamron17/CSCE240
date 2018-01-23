/* Modified by Hunter Damron - 2018 */

/* Copyright 2018 */

// Include the C standard system library cstdlib, for random number generation
// Introduce qualified names for rand and srand into scope
#include <cstdlib>
using std::rand;
using std::srand;

// Include the C time system lib for time function
#include <ctime>
// Introduce qualified name for time into scope to get current time
using std::time;

// Include the iostream system lib
#include <iostream>

// Introduce qualified names for cin, cout, and endl
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  // Seed random number generator with current time
  srand(time(nullptr)); // see doc for parameter explanation
  // Generate a random number in [1, 100].
  int rand_num = rand() % 100 + 1;

  int guess = 0; // integer to hold guess
  // Pompt user to guess a number between 1 and 100
  // Get input from standard input stream
  cout << "Guess a number between 1 and 100: ";

  // Until the user correctly guesses the number, give high/low hints and prompt
  // for another guess.
  cin >> guess;
  while (guess != rand_num) {
    if (guess < rand_num)
      cout << "Guess is too low. Guess again: ";
    else
      cout << "Guess is too high. Guess again: ";
    cin >> guess;
  }

  // Inform the user of a correct guess
  cout << "That is the correct answer: " << rand_num << endl;

  return 0;
}
