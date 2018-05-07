#include "display.h"

namespace csce240 {

std::ostream& operator<<(std::ostream& cout, const Display& rhs) {
  rhs.ExtractTo(cout);

  return cout;
}

}  // namespace csce240


