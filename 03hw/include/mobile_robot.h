/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#ifndef _03HW_SOL_INCLUDE_MOBILE_ROBOT_H_  // NOLINT(build/header_guard)
#define _03HW_SOL_INCLUDE_MOBILE_ROBOT_H_

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;

#include <cassert>
// using assert;


namespace csce240 {

// MobileRobot is the base class for robots of various terms.
//   Each has a speed and an id guaranteed to be unique within a single runtime.
class MobileRobot {
 public:
  explicit MobileRobot(const double speed = 0.0);  // Generates id, sets speed
  ~MobileRobot();  // Deconstructor removes id from list of taken ids

  double speed() const;  // Speed getter

  const string id() const;  // Id getter
  bool id(const string& id);  // Sets id of robot if not take (true if changed)

  static bool IsUnique(const string& id);  // Tests whether id is already taken

 protected:
  std::string id_;
  double speed_;

 private:
  static int id_gen_;  // Static incrementor for generating new ids
  static vector<string> ids_;  // List of taken ids

  static string NewId();  // Generates new id of form "LOlzBot23"
  static int IndexOf(string id);  // Gets the index of id in list (-1 if not in)
  static bool RemoveId(string id);  // Removes id from list of taken
};

}  // namespace csce240

#endif  // _03HW_SOL_INCLUDE_MOBILE_ROBOT_H_
