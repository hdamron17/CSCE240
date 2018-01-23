/* Modified by Hunter Damron - 2018 */

// fstream system library for file i/o
#include <fstream>

// Introduce fstream from namespasce std into file's name scope
using std::fstream;

// Include header for iostream system library for console i/o
#include <iostream>

// get cout and endl from namespace std
using std::cout;
using std::endl;

// Include string system library for string data type
#include <string>

// get string from namespace std
using std::string;

int main(int argc, char* argv[]) {
  // When other than 2 arguments are provided to program,
  // - Display usage message:
  //  "Usage: 05app <input file>.in"
  // - Exit program with a 1
  if (argc != 2) {
    cout << "Usage: 05app <input file>.in" << endl;
    return 1;
  }

  int count = 0;  // # of entries
  double input = 0.0,  // an entry
      total = 0.0;  // sum of entries

  fstream fin;  // an instance of the fstream class

  // display file being opened
  cout << "Opening file \'" << argv[1] << "\'" << endl;

  // open file
  fin.open(argv[1]);

  // get count of entries
  // for each entry, read and accumulate
  while (!fin.eof()) {
    fin >> input;
    if (!fin.eof()) {
      total += input;
      count++;
    }
  }

  // display total
  // close file
  cout << "Total: " << total << endl;
  fin.close();

  return 0;
}
