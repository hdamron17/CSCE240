/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#ifndef _03HW_SOL_INCLUDE_TRACKED_H_  // NOLINT
#define _03HW_SOL_INCLUDE_TRACKED_H_  // NOLINT

#include "mobile_robot.h"  // NOLINT(build/include_subdir)
using csce240::MobileRobot;

#include "../lib/include/point.h"
using csce240::two_dim::Point;

#include "../lib/include/vector.h"
using csce240::two_dim::Vector;


namespace csce240 {

// Tracked extends MobileRobot to include 2d transport
class Tracked : public MobileRobot {
 public:
  explicit Tracked(const Point& pos, const double speed = 0.0)
      : MobileRobot(speed), pos_(pos) {}  // Begins robot with pose as Point
  Tracked(const double pos_x, const double pos_y, const double speed = 0.0)
      : MobileRobot(speed), pos_(Point(pos_x, pos_y)) {}  // Constr with x,y

  const Point location() const;  // Gets location of robot

  // Tests if distance to point <= speed (robot can go to point in 1 step)
  const bool CanTranslateTo(const Point& dest) const;

 protected:
  Point pos_;
};

}  // namespace csce240

#endif  // NOLINT
