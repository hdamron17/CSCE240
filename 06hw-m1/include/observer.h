/* Copyright 2018 */
/* Slightly modified by Hunter Damron */
#ifndef _06HW_INCLUDE_OBSERVER_  // NOLINT(build/header_guard)
#define _06HW_INCLUDE_OBSERVER_

namespace csce240 {

class Observer {
 public:
  virtual ~Observer() = 0;

  virtual void Update() = 0;
};

}  // namespace csce240

#endif  // _06HW_INCLUDE_OBSERVER_
