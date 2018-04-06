/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#include "quad_rotor.h"  // NOLINT(build/include_subdir)


namespace csce240 {

bool QuadRotor::CanTranslateTo(const Coordinate* dest) const {
  // Creates vector from pos_ to dest and calculates length of vector
  Offset* path = new Vector();
  location_->GetOffset(dest, path);

  // Compares length to speed and returns true if it is smaller
  bool comp = path->GetLength() <= speed_;
  delete path;
  return comp;
}

void QuadRotor::Translate(const Offset* direction) {
  if (direction->GetLength() <= speed_) {
    location_->AddOffset(direction);
  }
}

}  // namespace csce240
