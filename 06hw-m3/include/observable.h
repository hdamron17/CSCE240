#ifndef _06HW_INCLUDE_OBSERVABLE_
#define _06HW_INCLUDE_OBSERVABLE_

#include <algorithm>
#include <list>

#include "observer.h"

namespace csce240 {

class Observable {
 public:
  virtual ~Observable();

  /*
   * Adds an Observer pointer to a list. Store the actual pointer, do not
   *   create new memory.
   */
  void Add(Observer*);

  /*
   * Detaches an Observer from the Observable to avoid future updates. Do not
   *   delete the object to which the pointer points. Simply remove it from the
   *   list.
   */
  void Delete(Observer*);

  /*
   * Calls the Observer::Update() method of all Observers in list.
   */
  void Notify();

 private:
  /*
   * Need an std::list<Observer *> to store observers
   */
};

}  // namespace csce240
#endif
