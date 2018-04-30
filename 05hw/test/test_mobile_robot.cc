/* Copyright */
/* Modified by Hunter Damron */

#include <cassert>
#include <cstdlib>
// using atoi
#include <iostream>
#include <string>

#include "mobile_robot.h"
#include "quad_rotor_translation.h"
#include "tracked_translation.h"
#include "point.h"
#include "vector.h"

#define DBG(i) { cout << "DBG " << #i << endl; }

using namespace csce240;
using namespace std;

bool TestTrackedCreation();

bool TestMobileRobotIsUnique();

bool TestMobileRobotSetId();

bool TestMobileRobotCanTranslateTo(const MobileRobot* robot,
    const CartesianCoord* coord, bool expected);

bool TestMobileRobotTranslate(MobileRobot* robot,
    const CartesianOffset* offset, const CartesianCoord* expected);

int main(int argc, char* argv[]) {
  // assert(false && "The test_mobile_robot.cc is almost entirely commented out. You should update methods to work with the new class interfaces.");
  cout << "TESTING MobileRobot CLASS" << endl;
  CartesianCoord *c;
  MobileRobot *r;
  CartesianOffset *o;

  if (TestTrackedCreation())
    cout << "\t PASSED" << endl;
  else
    return 1;

  if (TestMobileRobotIsUnique())
    cout << "\t PASSED" << endl;
  else
    return 1;

  if (TestMobileRobotSetId())
    cout << "\t PASSED" << endl;
  else
    return 1;

  /* Test MobileRobot::CanTranslateTo */
  c = new two_dim::Point();  // robot origin
  r = new MobileRobot(new TrackedTranslation, c, 5.0);  // robot at origin
  delete c;  // prepare to hold expected
  c = new two_dim::Point(3.0, 4.0);  // goal location
  if (TestMobileRobotCanTranslateTo(r, c, true))  // good test
    cout << "\t PASSED" << endl;
  else
    return 1;
  delete c;

  c = new two_dim::Point(-3.01, -4.01);  // goal location
  if (TestMobileRobotCanTranslateTo(r, c, false))  // bad test
    cout << "\t PASSED" << endl;
  else
    return 1;
  delete c;

  /* Test MobileRobot::Translate */
  o = new two_dim::Vector(3.0, 4.0);
  c = new two_dim::Point(3.0, 4.0);
  if (TestMobileRobotTranslate(r, o, c)) // good test
    cout << "\t PASSED" << endl;
  o->Scale(-1.01, o);
  if (TestMobileRobotTranslate(r, o, c)) // bad test (too far so stays in same spot)
    cout << "\t PASSED" << endl;

  delete c;
  delete r;
  delete o;

  /* QuadRotor tests */
  cout << "~TestQuadRotor" << endl;
  c = new two_dim::Point(1, 1);
  r = new MobileRobot(new QuadRotorTranslation, c, 5.0);
  c->x(5.8);
  if (TestMobileRobotCanTranslateTo(r, c, true))
    cout << "\t PASSED" << endl;
  c->x(6.1);
  if (TestMobileRobotCanTranslateTo(r, c, false))
    cout << "\t PASSED" << endl;
  delete c;
  delete r;

  cout << "~strict::TestQuadRotor" << endl;
  c = new two_dim::Point(1, 1);
  r = new MobileRobot(new strict::QuadRotorTranslation, c, 5.0);
  c->x(5.8);
  if (TestMobileRobotCanTranslateTo(r, c, false))  // Because two_dim
    cout << "\t PASSED" << endl;
  c->x(6.1);
  if (TestMobileRobotCanTranslateTo(r, c, false))
    cout << "\t PASSED" << endl;
  delete c;
  delete r;

  return 0;
}

bool TestTrackedCreation() {
  bool ret = true;
  cout << "\tTestTrackedCreation" << endl;
  CartesianCoord *p = new two_dim::Point(0.0, 0.0);
  MobileRobot *r = new MobileRobot(new TrackedTranslation, p, 5.0);
  p->x(1.0);

  two_dim::Point q;
  r->location(&q);
  if (q.Equals(p)) {
    cout << "\t FAILED" << endl;
    cout << "\t Point expected: " << *p
        << ", actual: " << q << endl;

     ret = false;
  }

  delete p;
  delete r;
  return ret;
}

bool TestMobileRobotIsUnique() {
  cout << "\tTestMobileRobotIsUnique" << endl;

  if (!MobileRobot::IsUnique("id")) {
    cout << "\t FAILED" << endl;
    cout << "\t MobileRobot::IsUnique(\"id\")"
        << " Expected: 1, Actual: " << !MobileRobot::IsUnique("id")
        << endl;

    return false;
  }

  two_dim::Point c(0.0, 0.0);
  MobileRobot r(new TrackedTranslation, &c);
  string id = r.id();
  if (MobileRobot::IsUnique(id)) {
   cout << "\t FAILED" << endl;
   cout << "\t MobileRobot::IsUnique(" << id
       << ") Expected: 0, Actual: " << MobileRobot::IsUnique(id)
       << endl;

   return false;
  }

  return true;
}

bool TestMobileRobotSetId() {
  cout << "\tTestMobileRobotSetId" << endl;
  two_dim::Point p(0, 0);
  MobileRobot r1(new TrackedTranslation, &p, 0),
              r2(new TrackedTranslation, &p, 0);

  if (!r1.id("id")) {
   cout << "\t FAILED" << endl;
   cout << "\t r1.id(\"id\") Expected: 1, Actual: " << !r1.id("id")
       << endl;
   return false;
  }

  if (r2.id("id")) {
   cout << "\t FAILED" << endl;
   cout << "\t r2.id(\"id\") Expected: 0, Actual: " << r2.id("id")
       << endl;

    return false;
  }

  return true;
}

bool TestMobileRobotCanTranslateTo(const MobileRobot* robot,
    const CartesianCoord* coord, bool expected) {
  cout << "\tTestMobileRobotCanTranslateTo" << endl;

  CartesianCoord* p = new three_dim::Point();
  robot->location(p);
  if (robot->CanTranslateTo(coord) != expected) {
    cout << "\t FAILED" << endl;
    cout << "\t Translate from " << *p
        << ", to " << *coord
        << " with speed " << robot->speed()
        << " Expected: 0, Actual: " << (robot->CanTranslateTo(coord)!=expected)
        << endl;
     return false;
  }

  return true;
}

bool TestMobileRobotTranslate(MobileRobot* robot,
    const CartesianOffset* offset, const CartesianCoord* expected) {
  cout << "\tTestMobileRobotTranslate" << endl;

  robot->Translate(offset);
  CartesianCoord* p = new two_dim::Point();
  robot->location(p);
  if (!p->Equals(expected)) {
    cout << "\t FAILED" << endl;
    cout << "\t Expected: " << *expected
        << ", Actual: " << *p << endl;
     return false;
  }
  return true;
}
