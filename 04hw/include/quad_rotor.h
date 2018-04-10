/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#ifndef _04HW_SOL_INCLUDE_QUAD_ROTOR_H_  // NOLINT(build/header_guard)
#define _04HW_SOL_INCLUDE_QUAD_ROTOR_H_

#include "mobile_robot.h"  // NOLINT(build/include_subdir)

#include "point.h"  // NOLINT(build/include_subdir)
using csce240::three_dim::Point;

#include "vector.h"  // NOLINT(build/include_subdir)
using csce240::three_dim::Vector;

#include "my_utils.h"  // NOLINT(build/include_subdir)
using csce240::three_dim::CopyCoord;
using csce240::two_dim::OffsetToVector;

namespace csce240 {

// QuadRotor extends MobileRobot to include 2d transport
class QuadRotor : public MobileRobot {
 public:
  // TODO(HD) add back const to Coordinate* pos
  explicit QuadRotor(Coordinate* pos, const double speed = 0.0)
      : MobileRobot(speed) {
          if (!location_) location_ = new Point();
          CopyCoord(pos, location_);
        }  // Pose as Coord
  QuadRotor(const double x, const double y, const double z,
        const double speed = 0.0)
      : MobileRobot(speed) { location_ = new Point(x, y, z); }  // From x,y,z
//  virtual ~QuadRotor();

  // Tests if distance to point <= speed (robot can go to point in 1 step)
  bool CanTranslateTo(const Coordinate* dest) const;
  void Translate(const Offset* direction);
};

}  // namespace csce240

#endif  // _04HW_SOL_INCLUDE_QUAD_ROTOR_H_
