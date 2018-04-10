/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#include "my_utils.h"  // NOLINT(build/include_subdir)


namespace csce240 {

namespace two_dim {
  const Point* CoordToPoint(const Coordinate* in) {
    const Point* ret = dynamic_cast<const Point *>(in);
    assert(ret);
    return ret;
  }

  const Vector* OffsetToVector(const Offset* in) {
    const Vector* ret = dynamic_cast<const Vector *>(in);
    assert(ret);
    return ret;
  }

  void CopyCoord(const Coordinate* in, Coordinate* out) {
    const Point* p = dynamic_cast<const Point *>(in);
    Point* pout = dynamic_cast<Point*>(out);
    assert(p); assert(pout);
    pout->x(p->x());
    pout->y(p->y());
  }

  void CopyOffset(const Offset* in, Offset* out) {
    const Vector* v = dynamic_cast<const Vector *>(in);
    Vector* vout = dynamic_cast<Vector*>(out);
    assert(v); assert(vout);
    vout->x(v->x());
    vout->y(v->y());
  }
}  // namespace two_dim


namespace three_dim {
  const Point* CoordToPoint(const Coordinate* in) {
    const Point* ret = dynamic_cast<const Point *>(in);
    assert(ret);
    return ret;
  }

  const Vector* OffsetToVector(const Offset* in) {
    const Vector* ret = dynamic_cast<const Vector *>(in);
    assert(ret);
    return ret;
  }

  void CopyCoord(const Coordinate* in, Coordinate* out) {
    const Point* p = dynamic_cast<const Point *>(in);
    Point* pout = dynamic_cast<Point*>(out);
    assert(p); assert(pout);
    pout->x(p->x());
    pout->y(p->y());
    pout->z(p->z());
  }

  void CopyOffset(const Offset* in, Offset* out) {
    const Vector* v = dynamic_cast<const Vector *>(in);
    Vector* vout = dynamic_cast<Vector*>(out);
    assert(v); assert(vout);
    vout->x(v->x());
    vout->y(v->y());
    vout->z(v->z());
  }
}  // namespace three_dim

}  // namespace csce240
