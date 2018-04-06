/* Copyright */

#include <cstdlib>
// using atoi
#include <iostream>
#include <string>

#include "tracked.h"  // NOLINT(build/include_subdir)
#include "point.h"  // NOLINT(build/include_subdir)

bool TestCreateTracked() {
  std::cout << "\tTestCreateTracked" << std::endl;
  csce240::two_dim::Point p(0.0, 0.0);
  std::cout << "T:BP 1" << std::endl;
  csce240::Tracked r1(&p), r2(0.0, 0.0, 3.14159);
  std::cout << "T:BP 2" << std::endl;

  const csce240::Coordinate* c = r1.location();
  std::cout << "T:BP 3 @ " << c << " vs " << &p << std::endl;
  if (!c->Equals(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Point expected: " << p << ", actual: " << r1.location()
        << std::endl;
    return false;
  }

  std::cout << "\t TestCreateTracked BP 1" << std::endl;

  if (!r2.location()->Equals(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Point expected: " << p << ", actual: " << r1.location()
        << std::endl;
    return false;
  }

  std::cout << "\t TestCreateTracked BP 2" << std::endl;
//  Coordinate* loc = r1.location();
  std::cout << "\t DEBUG: r1.location() = "
        << r1.location() << " ; &p = " << &p << std::endl;
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
    std::cout << "\t Translate from " << r.location() << ", to " << p
        << " with speed " << r.speed()
        << " Expected: 1, Actual: " << r.CanTranslateTo(&p)
        << std::endl;
    return false;
  }

  p = csce240::two_dim::Point(3.1, 4.1);
  if (r.CanTranslateTo(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Translate from " << r.location() << ", to " << p
        << " with speed " << r.speed()
        << " Expected: 1, Actual: " << r.CanTranslateTo(&p)
        << std::endl;
    return false;
  }

  return true;
}


int main(int argc, char* argv[]) {
  assert(argc > 1 && "Expected integer argument");
  std::cout << "TESTING csce240::Tracked CLASS" << std::endl;

  switch (atoi(argv[1])) {
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
  default:
    assert(false && "Only args 0, 1, 2 allowed.");
  }

  return 0;
}
