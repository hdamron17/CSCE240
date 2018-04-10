/* Copyright */

#include <cstdlib>
// using atoi
#include <iostream>
using std::cout;
using std::endl;
#include <string>

#include "tracked.h"  // NOLINT(build/include_subdir)
#include "point.h"  // NOLINT(build/include_subdir)
#include "my_utils.h"  // NOLINT(build/include_subdir)

bool TestCreateTracked() {
  std::cout << "\tTestCreateTracked" << std::endl;
  csce240::two_dim::Point p(0.0, 0.0);
  csce240::Tracked r1(&p), r2(0.0, 0.0, 3.14159);

  const csce240::Coordinate* c = r1.location();
  if (!c->Equals(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Point expected: " << p << ", actual: " << r1.location()
        << std::endl;
    return false;
  }

  if (!r2.location()->Equals(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Point expected: " << p << ", actual: " << r1.location()
        << std::endl;
    return false;
  }
//  Coordinate* loc = r1.location();
  return true;
}

bool TestIsUniqueTrackedId() {
  std::cout << "\tTestIsUniqueTrackedId" << std::endl;

  if (!csce240::Tracked::IsUnique("id")) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t csce240::Tracked::IsUnique(\"id\")"
        << " Expected: 1, Actual: " << !csce240::Tracked::IsUnique("id")
        << std::endl;

    return false;
  }

  csce240::Tracked r(0.0, 0.0);
  std::string id = r.id();
  if (csce240::Tracked::IsUnique(id)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t csce240::Tracked::IsUnique(" << id
        << ") Expected: 0, Actual: " << csce240::Tracked::IsUnique(id)
        << std::endl;

    return false;
  }

  return true;
}

bool TestSetTrackedId() {
  std::cout << "\tTestSetTrackedId" << std::endl;
  csce240::Tracked r1(0.0, 0.0), r2(0.0, 0.0);

  if (!r1.id("id")) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t r1.id(\"id\") Expected: 1, Actual: " << !r1.id("id")
        << std::endl;
    return false;
  }

  if (r2.id("id")) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t r2.id(\"id\") Expected: 0, Actual: " << r2.id("id")
        << std::endl;

    return false;
  }

  return true;
}

bool TestTrackedCanTranslateTo() {
  std::cout << "\tTestTrackedCanTranslateTo" << std::endl;
  csce240::Tracked r(0.0, 0.0, 5.0);
  csce240::two_dim::Point p(3.0, 4.0);

  if (!r.CanTranslateTo(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Translate from " << *(r.location()) << ", to " << p
        << " with speed " << r.speed()
        << " Expected: 1, Actual: " << r.CanTranslateTo(&p)
        << std::endl;
    return false;
  }

  p = csce240::two_dim::Point(3.1, 4.1);
  if (r.CanTranslateTo(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Translate from " << *(r.location()) << ", to " << p
        << " with speed " << r.speed()
        << " Expected: 1, Actual: " << r.CanTranslateTo(&p)
        << std::endl;
    return false;
  }

  return true;
}

bool TestTrackedTranslate() {
  std::cout << "\tTestTrackedTranslate" << std::endl;
  csce240::Tracked r(0.0, 0.0, 5.0);
  csce240::two_dim::Point p(3.0, 4.0);
  const csce240::two_dim::Vector v(3.0, 4.0), v1(0.1, 0.1);

  if (!r.CanTranslateTo(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Translate from " << *(r.location()) << ", to " << p
        << " with speed " << r.speed()
        << " Expected: 1, Actual: " << r.CanTranslateTo(&p)
        << std::endl;
    return false;
  } else {
    r.Translate(&v);
  }

  if (!r.location()->Equals(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Translate to " << *(r.location())
        << " with speed " << r.speed()
        << " Expected: " << p << ", Actual: " << r.location()
        << std::endl;
    return false;
  }

  p = csce240::two_dim::Point(3.1, 4.1);

  if (!r.CanTranslateTo(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Translate from " << *(r.location()) << ", to " << p
        << " with speed " << r.speed()
        << " Expected: 1, Actual: " << r.CanTranslateTo(&p)
        << std::endl;
    return false;
  } else {
    r.Translate(&v1);
  }

  if (!r.location()->Equals(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Translate to " << *(r.location())
        << " with speed " << r.speed()
        << " Expected: " << p << ", Actual: " << r.location()
        << std::endl;
    return false;
  }

  return true;
}

int main_(int i) {
  std::cout << "TESTING csce240::Tracked CLASS" << std::endl;

  switch (i) {
  case 0:
    if (TestCreateTracked()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 1:
    if (TestIsUniqueTrackedId()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 2:
    if (TestSetTrackedId()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 3:
    if (TestTrackedCanTranslateTo()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 4:
    if (TestTrackedTranslate()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  default:
    assert(false && "Only args 0, 1, 2, 3 allowed.");
  }

  return 0;
}

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    bool res = 0;
    for (int i = 0; i <= 4; ++i) {
      res |= main_(i);
    }
    return res;
  } else {
    main_(atoi(argv[1]));
  }
}
