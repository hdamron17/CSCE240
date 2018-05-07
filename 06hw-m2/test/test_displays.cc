/* Copyright 2018 LewisJS4@cse.sc.edu */

#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "average_temp_display.h"
#include "display.h"

struct Reading {
  Reading(double h, double p, double t)
      : humidity(h), pressure(p), temperature(t) {}

  double humidity;
  double pressure;
  double temperature;
};

bool TestAverageTempDisplay(const std::vector<Reading>& readings,
    const std::string& expected, csce240::Display* display,
    std::string* err);

int main(int argc, char* argv[]) {
  std::vector<Reading> readings = {
      Reading(5.0, 10.0, 15.0),
      Reading(10.0, 15.0, 5.0),
      Reading(15.0, 5.0, 10.0)
  };
  std::string err;

  std::cout << "TESTING DISPLAYS" << std::endl;

  std::cout << "  TESTING AverageTempDisplay: ";
  csce240::AverageTempDisplay avgTmpDisp;
  if (TestAverageTempDisplay(readings,
      "Average Temperature for last 3 readings was 10", &avgTmpDisp, &err))
    std::cout << "PASSED" << std::endl;
  else {
    std::cout << "FAILED" << std::endl;
    std::cout << '\t' << err << std::endl;
    return 1;
  }

  return 0;
}

bool TestAverageTempDisplay(const std::vector<Reading>& readings,
    const std::string& expected, csce240::Display* display,
    std::string* err) {
  std::vector<Reading>::const_iterator itr;
  for (itr = readings.begin(); itr != readings.end(); ++itr) {
    display->SetHumidity(itr->humidity);
    display->SetPressure(itr->pressure);
    display->SetTemperature(itr->temperature);
  }

  std::stringstream sstream;
  sstream << *display;

  if (sstream.str() == expected)
    return true;
  else {
    *err = "Expected: " + expected + ", Actual: " + sstream.str();

    return false;
  }
}

