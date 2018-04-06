/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#include "my_utils.h"  // NOLINT(build/include_subdir)


namespace csce240 {

namespace two_dim {
  Point* CoordToPoint(const Coordinate* in) {
    return const_cast<Point *>(dynamic_cast<const Point *>(in));
  }

  Vector* OffsetToVector(const Offset* in) {
    return const_cast<Vector *>(dynamic_cast<const Vector *>(in));
  }
}  // namespace two_dim


namespace three_dim {
  Point* CoordToPoint(const Coordinate* in) {
    return const_cast<Point *>(dynamic_cast<const Point *>(in));
  }

  Vector* OffsetToVector(const Offset* in) {
    return const_cast<Vector *>(dynamic_cast<const Vector *>(in));
  }
}  // namespace three_dim

}  // namespace csce240
