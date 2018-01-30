/* Modified by Hunter Damron - 2018 */

/* Copyright 2018 */
#include <iostream>
using std::cout;
using std::endl;

//  Write a void function which displays Hello, World named HelloWorld01
void HelloWorld01() {
  cout << "Hello, World" << endl;
}

void HelloWorld02();  // Introduces name into scope before main()

int main(int argc, char* argv[]) {
  // call HelloWorld01
  HelloWorld01();

  // call HelloWorld02
  HelloWorld02();

  return 0;
}

//  Write a void function which displays Hello, World named HelloWorld02
void HelloWorld02() {
  cout << "Hello, World" << endl;
}
