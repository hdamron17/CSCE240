/* Copyright */

#include <iostream>
using std::cout;
using std::endl;

#include <string>

#include <cassert>
// using assert;

#include <vector>
using std::vector;

#include "tracked.h"
using csce240::Tracked;


int main(int argc, char* argv[]) {
  int len = (1 << 7) + 1;
  vector<Tracked> bots;
  for (int i = 0; i < len; ++i) {
    bots.push_back(Tracked(0, 0));
  }
  assert(bots.at(len-1).id() == "lolzbot1");

  assert(MobileRobot::IsUnique("lolzboT1"));
  for (int i = 0; i < len; ++i) {
    // TODO(HD) Figure out why destructor is called alongside `push_back`
    // assert(!MobileRobot::IsUnique(bots.at(i).id()));
  }

  Tracked bot = Tracked(5, 6, 1);
  assert(bot.speed() == 1.0);
  assert(bot.location().x() == 5);
  assert(bot.location().y() == 6);

  assert(bot.CanTranslateTo(Point(5, 5)));
  assert(bot.CanTranslateTo(Point(5, 7)));
  assert(bot.CanTranslateTo(Point(6, 6)));
  assert(bot.CanTranslateTo(Point(4, 6)));
  assert(bot.CanTranslateTo(Point(5.1, 6.5)));
  assert(!bot.CanTranslateTo(Point(4, 5)));
  assert(!bot.CanTranslateTo(Point(-5, -6)));

  cout << "ALL TESTS PASSED" << endl;
  return 0;
}

