/* Copyright 2018 */
/* Modified by Hunter Damron */
#include "display.h"  // NOLINT(build/include_subdir)

namespace csce240 {

std::ostream& operator<<(std::ostream& cout, const Display& rhs) {
  rhs.ExtractTo(cout);

  return cout;
}

}  // namespace csce240
