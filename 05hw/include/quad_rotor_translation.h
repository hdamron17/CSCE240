/* Copyright 2018 */
/* Modified by Hunter Damron */
#ifndef _05HW_INCLUDE_QUAD_ROTOR_TRANSLATION_H_  // NOLINT(build/header_guard)
#define _05HW_INCLUDE_QUAD_ROTOR_TRANSLATION_H_

#include "translation.h"  // NOLINT(build/include_subdir)
#include "point.h"        // NOLINT(build/include_subdir)
#include "vector.h"       // NOLINT(build/include_subdir)

namespace csce240 {

class QuadRotorTranslation : public Translation {
 public:
  bool CanTranslateTo(const CartesianCoord* start, const double speed,
      const CartesianCoord* goal) const;

  void Translate(const CartesianOffset* direction, const double speed,
      CartesianCoord* start) const;
};

namespace strict {

class QuadRotorTranslation : public Translation {
 public:
  bool CanTranslateTo(const CartesianCoord* start, const double speed,
      const CartesianCoord* goal) const;

  void Translate(const CartesianOffset* direction, const double speed,
      CartesianCoord* start) const;
};

}  // namespace strict

}  // namespace csce240

#endif  // _05HW_INCLUDE_QUAD_ROTOR_TRANSLATION_H_
