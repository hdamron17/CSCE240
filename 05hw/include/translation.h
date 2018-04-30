/* Copyright 2018 */
/* Modified by Hunter Damron */
#ifndef _05HW_INCLUDE_TRANSLATION_H_  // NOLINT(build/header_guard)
#define _05HW_INCLUDE_TRANSLATION_H_

#include "point.h"   // NOLINT(build/include_subdir)
#include "vector.h"  // NOLINT(build/include_subdir)

namespace csce240 {

class Translation {
 public:
  virtual ~Translation() {}

  virtual bool CanTranslateTo(const CartesianCoord* start, const double speed,
      const CartesianCoord* goal) const = 0;

  virtual void Translate(const CartesianOffset* direction, const double speed,
      CartesianCoord* start) const = 0;

 protected:
  static void AddOffset(const CartesianOffset* v, CartesianCoord* pt) {
    pt->x(pt->x() + v->x());
    pt->y(pt->y() + v->y());
    pt->z(pt->z() + v->z());
  }

  static void GetOffset(const CartesianCoord* start,
      const CartesianCoord* end, CartesianOffset* path) {
    path->x(end->x() - start->x());
    path->y(end->y() - start->y());
    path->z(end->z() - start->z());
  }

  static CartesianCoord* Clone(const CartesianCoord* orig) {
    CartesianCoord* ret = new three_dim::Point();
    ret->x(orig->x());
    ret->y(orig->y());
    ret->z(orig->z());
    return ret;
  }

  static CartesianOffset* Clone(const CartesianOffset* orig) {
    CartesianOffset* ret = new three_dim::Vector();
    ret->x(orig->x());
    ret->y(orig->y());
    ret->z(orig->z());
    return ret;
  }
};

}  // namespace csce240

#endif  // _05HW_INCLUDE_TRANSLATION_H_
