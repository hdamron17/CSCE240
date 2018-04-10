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
  const Point* CoordToPoint(const Coordinate* in);
  const Vector* OffsetToVector(const Offset* in);

  void CopyCoord(const Coordinate* in, Coordinate* out);
  void CopyVector(const Offset* in, Offset* out);
}  // namespace two_dim

namespace three_dim {
  const Point* CoordToPoint(const Coordinate* in);
  const Vector* OffsetToVector(const Offset* in);

  void CopyCoord(const Coordinate* in, Coordinate* out);
  void CopyVector(const Offset* in, Offset* out);
}  // namespace three_dim

}  // namespace csce240

#endif  // _04HW_SOL_INCLUDE_MY_UTIL_H_
