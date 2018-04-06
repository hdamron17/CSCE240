/* Copyright */

#include <cstdlib>
// using atoi
#include <iostream>
#include <string>

#include "quad_rotor.h"  // NOLINT(build/include_subdir)
#include "point.h"  // NOLINT(build/include_subdir)

bool TestCreateQuadRotor() {
  std::cout << "\tTestCreateQuadRotor" << std::endl;
  csce240::three_dim::Point p(0.0, 0.0, 0.0);
  csce240::QuadRotor r1(&p), r2(0.0, 0.0, 0.0, 3.14159);

  if (!r1.location()->Equals(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Point expected: " << p << ", actual: " << r1.location()
        << std::endl;
    return false;
  }

  std::cout << "\t TestCreateQuadRotor BP 1" << std::endl;

  if (!r2.location()->Equals(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Point expected: " << p << ", actual: " << r1.location()
        << std::endl;
    return false;
  }

  std::cout << "\t TestCreateQuadRotor BP 2" << std::endl;
//  Coordinate* loc = r1.location();
  std::cout << "\t DEBUG: r1.location() = "
        << r1.location() << " ; &p = " << &p << std::endl;
  return true;
}

bool TestIsUniqueQuadRotorId() {
  std::cout << "\tTestIsUniqueQuadRotorId" << std::endl;

  if (!csce240::QuadRotor::IsUnique("id")) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t csce240::QuadRotor::IsUnique(\"id\")"
        << " Expected: 1, Actual: " << !csce240::QuadRotor::IsUnique("id")
        << std::endl;

    return false;
  }

  csce240::QuadRotor r(0.0, 0.0, 0.0);
  std::string id = r.id();
  if (csce240::QuadRotor::IsUnique(id)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t csce240::QuadRotor::IsUnique(" << id
        << ") Expected: 0, Actual: " << csce240::QuadRotor::IsUnique(id)
        << std::endl;

    return false;
  }

  return true;
}

bool TestSetQuadRotorId() {
  std::cout << "\tTestSetQuadRotorId" << std::endl;
  csce240::QuadRotor r1(0.0, 0.0, 0.0), r2(0.0, 0.0, 0.0);

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

bool TestQuadRotorCanTranslateTo() {
  std::cout << "\tTestQuadRotorCanTranslateTo" << std::endl;
  csce240::QuadRotor r(0.0, 0.0, 0.0, 5.0);
  csce240::three_dim::Point p(3.0, 4.0, 1.0);

  if (!r.CanTranslateTo(&p)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t Translate from " << r.location() << ", to " << p
        << " with speed " << r.speed()
        << " Expected: 1, Actual: " << r.CanTranslateTo(&p)
        << std::endl;
    return false;
  }

  p = csce240::three_dim::Point(3.1, 4.1, 0.9);
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
  std::cout << "TESTING csce240::QuadRotor CLASS" << std::endl;

  switch (atoi(argv[1])) {
  case 0:
    if (TestCreateQuadRotor()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 1:
    if (TestIsUniqueQuadRotorId()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 2:
    if (TestSetQuadRotorId()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 3:
    if (TestQuadRotorCanTranslateTo()) {
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
