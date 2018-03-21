/* Copyright */

#include <cstdlib>
// using atoi
#include <iostream>
#include <string>
#include <cassert>
// using assert

#include "../include/mobile_robot.h"

bool TestCreateMobileRobot() {
  std::cout << "\tTestCreateMobileRobot" << std::endl;
  csce240::MobileRobot r1, r2(3.14159);  // Instanciate robots with default and
                                         //  explicit speeds

  if (r1.speed() != 0.0) {  // check default speed
    std::cout << "\t\t FAILED" << std::endl;
    std::cout << "\t\t Default speed expected: 0.0, actual: "
        << r1.speed() << std::endl;

    return false;
  }

  if (r2.speed() != 3.14159) {  // check explicit speed
    std::cout << "\t\t FAILED" << std::endl;
    std::cout << "\t\t Set speed expected: 3.14159, actual: "
        << r2.speed() << std::endl;

    return false;
  }

  return true;
}

bool TestIsUniqueMobileRobotId() {
  std::cout << "\tTestIsUniqueMobileRobotId" << std::endl;

  // assuming no ids exist, assure any id is unique
  if (!csce240::MobileRobot::IsUnique("id")) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t csce240::MobileRobot::IsUnique(\"id\")"
        << " Expected: 1, Actual: " << csce240::MobileRobot::IsUnique("id")
        << std::endl;

    return false;
  }

  csce240::MobileRobot r;  // create robot with auto-gen id
  std::string id = r.id();  // capture robot's id
  if (csce240::MobileRobot::IsUnique(id)) {  // ensure that id is not unique
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t csce240::MobileRobot::IsUnique(" << id
        << ") Expected: 0, Actual: " << csce240::MobileRobot::IsUnique(id)
        << std::endl;

    return false;
  }

  return true;
}

bool TestSetMobileRobotId() {
  std::cout << "\tTestSetMobileRobotId" << std::endl;
  csce240::MobileRobot r1, r2;  // create 2 robots with auto-gen ids

  if (!r1.id("id")) {  // Assuming no other ids exist, ensure that mutator
                       //  accepts an id
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t r1.id(\"id\") Expected: 1, Actual: " << r1.id("id")
        << std::endl;
    return false;
  }

  if (r2.id("id")) {  // After using "id" for previous robot name, ensure
                      //  mutator no longer accepts id
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t r2.id(\"id\") Expected: 0, Actual: " << r2.id("id")
        << std::endl;

    return false;
  }

  return true;
}

bool TestRemoveMobileRobotId() {
  std::cout << "\tTestRemoveMobileRobotId" << std::endl;
  csce240::MobileRobot r;  // create robot with auto-gen id
  std::string id = r.id();  // capture robot's id
  assert(r.id("id0") && "Mutator id failed");  // update robot id
  // ensure previous name available as unique
  if (!csce240::MobileRobot::IsUnique(id)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t csce240::MobileRobot::IsUnique(" << id
        << ") Expected: 1, Actual: " << csce240::MobileRobot::IsUnique(id)
        << std::endl;
    return false;
  }

  // open new block and create new robot
  {
    csce240::MobileRobot r;  // create robot with auto-gen id
        id = r.id();  // capture robot's id
        assert(r.id("id1") && "Mutator id failed");  // update robot id
  }
  // robot no longer exists, ensure previous name available as unique
  if (!csce240::MobileRobot::IsUnique(id)) {
    std::cout << "\t FAILED" << std::endl;
    std::cout << "\t csce240::MobileRobot::IsUnique(" << id
        << ") Expected: 1, Actual: " << csce240::MobileRobot::IsUnique(id)
        << std::endl;
    return false;
  }

  return true;
}

int main(int argc, char* argv[]) {
  assert(argc > 1 && "Expected an integer argument");
  std::cout << "TESTING csce240::MobileRobot CLASS" << std::endl;

  switch (atoi(argv[1])) {
  case 0:
    if (TestCreateMobileRobot()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 1:
    if (TestIsUniqueMobileRobotId()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 2:
    if (TestSetMobileRobotId()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  case 3:
    if (TestRemoveMobileRobotId()) {
      std::cout << "\t PASSED" << std::endl;
      return 0;
    } else {
      return 1;
    }
  default:
    assert(false && "Only args 0-3 allowed.");
  }

  return 0;
}

