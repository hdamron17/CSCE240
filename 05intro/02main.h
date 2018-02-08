/* Copyright 2018 */

// Update define guards
#ifndef LECT_05INTRO_02MAIN_H_  // NOLINT
#define LECT_05INTRO_02MAIN_H_  // NOLINT

// remove libraries no longer needed
// #include <cassert>
// using assert
// #include <cmath>
// using round
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// #include <sstream>
// typedef std::stringstream StrStr;
#include <string>
using std::string;

// include dollar header
#include "dollar.h"

/*
 * Generates a menu to prompt user. Should be called before each loop
 * iteration.
 */
void Prompt();

/*
 * Prompts user for double and creates and returns Dollar stuct.
 * Param:
 *  - a value allowing function's prompt to be aligned with menu/etc
 */
const Dollar GetDollarInput(const string& align = "");

#endif  // NOLINT
