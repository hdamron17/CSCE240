/* Copyright 2018 */
/* Modified by Hunter Damron */
#include "quad_rotor_translation.h"  // NOLINT(build/include_subdir)

namespace csce240 {

bool QuadRotorTranslation::CanTranslateTo(const CartesianCoord* start,
    const double speed, const CartesianCoord* goal) const {
  CartesianOffset* path = new three_dim::Vector();

  GetOffset(start, goal, path);

  // Compares length to speed and returns true if it is smaller
  bool comp = path->GetLength() <= speed;
  delete path;
  return comp;
}

void QuadRotorTranslation::Translate(const CartesianOffset* direction,
    const double speed, CartesianCoord* start) const {
  // Compares length to speed and translates if it is smaller
  if (direction->GetLength() <= speed)
    AddOffset(direction, start);
}

namespace strict {

bool QuadRotorTranslation::CanTranslateTo(const CartesianCoord* start,
    const double speed, const CartesianCoord* goal) const {
  CartesianOffset* path = new three_dim::Vector();

  GetOffset(start, goal, path);

  // Compares length to speed and returns true if it is smaller
  bool comp = path->GetLength() <= speed
      && start->GetDim() == 3
      && goal->GetDim() == 3;
  delete path;
  return comp;
}

void QuadRotorTranslation::Translate(const CartesianOffset* direction,
    const double speed, CartesianCoord* start) const {

  // Compares length to speed and translates if it is smaller
  if (direction->GetLength() <= speed
      && direction->GetDim() == 3
      && start->GetDim() == 3)
    AddOffset(direction, start);
}

}  // namespace strict

}  // namespace csce240
