/* Copyright 2018 */
/* Modified by Hunter Damron */
#include "tracked_translation.h"  // NOLINT(build/include_subdir)

namespace csce240 {

bool TrackedTranslation::CanTranslateTo(const CartesianCoord* start,
    const double speed, const CartesianCoord* goal) const {
  CartesianOffset* path = new three_dim::Vector();

  GetOffset(start, goal, path);

  // Compares length to speed and returns true if it is smaller
  bool comp = path->GetLength() <= speed
      && floating_point::Equals(path->z(), 0);
  delete path;
  return comp;
}

void TrackedTranslation::Translate(const CartesianOffset* direction,
    const double speed, CartesianCoord* start) const {
  CartesianOffset* path = Clone(direction);
  path->z(0);

  // Compares length to speed and translates if it is smaller
  if (path->GetLength() <= speed)
    AddOffset(path, start);
  delete path;
}

namespace strict {

bool TrackedTranslation::CanTranslateTo(const CartesianCoord* start,
    const double speed, const CartesianCoord* goal) const {
  CartesianOffset* path = new two_dim::Vector();

  GetOffset(start, goal, path);

  // Compares length to speed and returns true if it is smaller
  bool comp = path->GetLength() <= speed
      && start->GetDim() == 2
      && goal->GetDim() == 2;
  delete path;
  return comp;
}

void TrackedTranslation::Translate(const CartesianOffset* direction,
    const double speed, CartesianCoord* start) const {

  // Compares length to speed and translates if it is smaller
  if (direction->GetLength() <= speed
      && direction->GetDim() == 2
      && start->GetDim() == 2)
    AddOffset(direction, start);
}

}  // namespace strict

}  // namespace csce240
