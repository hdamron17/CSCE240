/*
 * Copyright 2018
 * Modified by Hunter Damron
 */
#include "mobile_robot.h"  // NOLINT(build/include_subdir)


namespace csce240 {

MobileRobot::MobileRobot(double speed) {
  assert(speed >= 0);
  speed_ = speed;
  id_ = NewId();
  ids_.push_back(id_);
}

MobileRobot::~MobileRobot() {
  RemoveId(id_);
  if (location_)
    delete location_;
}

double MobileRobot::speed() const {
  return speed_;
}

const string MobileRobot::id() const {
  return id_;
}

bool MobileRobot::id(const string& id) {
  int index = IndexOf(id);
  if (index != -1)
    return false;  // If index is -1, the id is not unique
  RemoveId(id_);  // Removes current id
  id_ = id;  // Changes id to new id
  ids_.push_back(id);  // Adds new id to list
  return true;
}

const Coordinate* MobileRobot::location() const {
  return location_;  // TODO(HD) find copy constructor so not exposed
}

bool MobileRobot::IsUnique(const string& id) {
  int index = IndexOf(id);
  return index == -1;  // Return -1 means not found
}

string MobileRobot::NewId() {
  // Generates names like LolZBot42
  // Converts binary of bottom 7 bits of id_gen_ to the capitalization
  //   scheme of "lolzbot"
  // If the bits higher than 7 are not 0, the number is appended
  string templ = "lolzbot";
  int size = templ.size();
  char upcap = ('A' - 'a');  // Amount to add to convert low cap to cap

  int id_gen = id_gen_;  // Make copy of id_gen_ so we can bitshift it
  string name = templ;

  for (int i = 0; i < size; ++i) {
    int bit = id_gen & 1;  // Gets last bit of id_gen
    if (bit) {
      name[i] = name[i] + upcap;  // If the bit is 1, capitalize letter i
    }
    id_gen >>= 1;  // Shift id_gen right 1 for next lowest bit
  }

  if (id_gen != 0)
    name += to_string(id_gen);  // Add numbers for last of number

  id_gen_++;  // Increment id_gen so next id can generate

  if (!IsUnique(name))
    name = NewId();  // Recursively make a new id if this one is not unique

  return name;
}

int MobileRobot::IndexOf(string id) {
  vector<string>::iterator iter;
  iter = find(ids_.begin(), ids_.end(), id);  // Finds id and returns iterator
  if (iter != ids_.end())
    return iter - ids_.begin();  // Get difference between found pos and begin
  else
    return -1;  // If iter is the end, it was not found so return -1
}

bool MobileRobot::RemoveId(string id) {
  int index = IndexOf(id);
  if (index == -1)
    return false;  // If id is not in list, it cannot be removed
  ids_.erase(ids_.begin() + index);
  return true;
}

// Initialize static variables for id generation
int MobileRobot::id_gen_ = 0;
vector<string> MobileRobot::ids_;

}  // namespace csce240
