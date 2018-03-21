/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#include "../include/tracked.h"


namespace csce240 {

const Point Tracked::location() const {
  return pos_;
}

const bool Tracked::CanTranslateTo(const Point& dest) const {
  // Creates vector from pos_ to dest and calculates length of vector
  Vector path = Vector(dest.x() - pos_.x(), dest.y() - pos_.y());

  // Compares length to speed and returns true if it is smaller
  return path.GetLength() <= speed_;
}

}  // namespace csce240
