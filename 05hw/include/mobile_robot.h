/* Copyright 2018 */
/* Modified by Hunter Damron */
#ifndef _05HW_INCLUDE_MOBILE_ROBOT_H_  // NOLINT(build/header_guard)
#define _05HW_INCLUDE_MOBILE_ROBOT_H_

#include <cassert>
// using assert

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;
using std::swap;

#include "point.h"        // NOLINT(build/include_subdir)
#include "translation.h"  // NOLINT(build/include_subdir)

namespace csce240 {

class MobileRobot {
 public:
  MobileRobot(const Translation* translation, const CartesianCoord* location,
        double speed = 0);
  virtual ~MobileRobot();

  double speed() const { return speed_; }

  const std::string id() const { return id_; }
  bool id(const std::string& id);

  bool CanTranslateTo(const CartesianCoord* goal) const;
  void Translate(const CartesianOffset* direction);

  void location(CartesianCoord* location) const;

  static bool IsUnique(const std::string& id);

 protected:
  const Translation *translation_;
  CartesianCoord *location_;
  double speed_;

  std::string id_;
  static int id_gen_;
  static vector<string> ids_;  // List of taken ids

  static string NewId();  // Generates new id of form "LOlzBot23"
  static int IndexOf(string id);  // Gets the index of id in list (-1 if not in)
  static bool RemoveId(string id);  // Removes id from list of taken
};

}  // namespace csce240

#endif  // 05HW_INCLUDE_MOBILE_ROBOT_H_
