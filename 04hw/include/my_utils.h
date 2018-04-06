/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#ifndef _04HW_SOL_INCLUDE_MY_UTIL_H_  // NOLINT(build/header_guard)
#define _04HW_SOL_INCLUDE_MY_UTIL_H_

#include "point.h"   // NOLINT(build/include_subdir)
#include "vector.h"  // NOLINT(build/include_subdir)


namespace csce240 {

namespace two_dim {
  Point* CoordToPoint(const Coordinate* in);
  Vector* OffsetToVector(const Offset* in);
}  // namespace two_dim

namespace three_dim {
  Point* CoordToPoint(const Coordinate* in);
  Vector* OffsetToVector(const Offset* in);
}  // namespace three_dim

}  // namespace csce240

#endif  // _04HW_SOL_INCLUDE_MY_UTIL_H_
