/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#ifndef _04HW_SOL_INCLUDE_TRACKED_H_  // NOLINT(build/header_guard)
#define _04HW_SOL_INCLUDE_TRACKED_H_

#include "mobile_robot.h"  // NOLINT(build/include_subdir)

#include "point.h"  // NOLINT(build/include_subdir)
using csce240::two_dim::Point;

#include "vector.h"  // NOLINT(build/include_subdir)
using csce240::two_dim::Vector;

#include "my_utils.h"  // NOLINT(build/include_subdir)
using csce240::two_dim::CopyCoord;
using csce240::two_dim::OffsetToVector;


namespace csce240 {

// Tracked extends MobileRobot to include 2d transport
class Tracked : public MobileRobot {
 public:
  // TODO(HD) add back const to Coordinate* pos
  explicit Tracked(Coordinate* pos, const double speed = 0.0)
      : MobileRobot(speed) {
          if (!location_) location_ = new Point();
          CopyCoord(pos, location_);
        }  // Pose as Coord
  Tracked(const double pos_x, const double pos_y, const double speed = 0.0)
      : MobileRobot(speed) { location_ = new Point(pos_x, pos_y); }  // From x,y
//  virtual ~Tracked();

  // Tests if distance to point <= speed (robot can go to point in 1 step)
  bool CanTranslateTo(const Coordinate* dest) const;
  void Translate(const Offset* direction);
};

}  // namespace csce240

#endif  // _04HW_SOL_INCLUDE_TRACKED_H_
