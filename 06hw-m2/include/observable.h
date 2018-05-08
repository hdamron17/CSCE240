/* Copyright 2018 */
/* Slightly modified by Hunter Damron */
#ifndef _06HW_INCLUDE_OBSERVABLE_  // NOLINT(build/header_guard)
#define _06HW_INCLUDE_OBSERVABLE_

#include "observer.h"  // NOLINT(build/include_subdir)

namespace csce240 {

class Observable {
 public:
  virtual ~Observable();

  void Add(Observer* observer);
  void Delete(Observer* observer);
  void Notify();
};

}  // namespace csce240

#endif  // _06HW_INCLUDE_OBSERVABLE_
