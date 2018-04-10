/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#include "tracked.h"  // NOLINT(build/include_subdir)


namespace csce240 {

bool Tracked::CanTranslateTo(const Coordinate* dest) const {
  // TODO(HD) Make sure the dest is 2dim
  // Creates vector from pos_ to dest and calculates length of vector
  Offset* path = new Vector();
  location_->GetOffset(dest, path);

  const Vector* path2d = OffsetToVector(path);

  // Compares length to speed and returns true if it is smaller
  bool comp = path->GetLength() <= speed_
      && path->GetLength() == path2d->GetLength();
  if (path) delete path;
  return comp;
}

void Tracked::Translate(const Offset* direction) {
  const Vector* v = OffsetToVector(direction);
  if (v->GetLength() <= speed_) {
    location_->AddOffset(v);
  }
}

}  // namespace csce240
