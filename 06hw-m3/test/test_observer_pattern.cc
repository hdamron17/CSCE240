/* Copyright 2018 LewisJS4@cse.sc.edu */

#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

#include "average_temp_display.h"
#include "display.h"
#include "observable.h"
#include "observer.h"
#include "sensor_net.h"
#include "temp_display.h"
#include "weather_station.h"


bool TestObservers(const std::vector<std::vector<double> >& expected,
    csce240::WeatherStation* station, std::vector<csce240::Display *>* displays,
    std::string* err);

int main(int argc, char* argv[]) {
  std::vector<std::vector<double> > views = {
      {17.25, 17.25},
      {17.28, 17.265},
      {17.31, 17.28}
  };
  std::string err;

  std::cout << "TESTING DISPLAYS" << std::endl;
  // create a WeatherStation
  csce240::WeatherStation station;

  // create displays and attach to WeatherStation
  std::vector<csce240::Display *> displays;
  displays.push_back(new csce240::TempDisplay(&station));
  displays.push_back(new csce240::AverageTempDisplay(&station));

  // inform station of new displays
  std::vector<csce240::Display *>::iterator disp_itr;
  for (disp_itr = displays.begin(); disp_itr != displays.end(); ++disp_itr)
    station.Add(*disp_itr);  // iterators are just fancy pointers

  // power on SensorNetwork
  csce240::SensorNet::PowerOn(); 

  // run a quick unit test before giving app a whirl
  std::cout << "  TESTING Displays: ";
  if (TestObservers(views, &station, &displays, &err))
    std::cout << "PASSED" << std::endl;
  else {
    std::cout << "FAILED" << std::endl;
    std::cout << '\t' << err << std::endl;
    return 1;
  }

  // and begin simulating minutes
  for (int i = 0; i < 5 && csce240::SensorNet::on(); ++i) {
    // simulate a minute of time passage for sensors
    csce240::SensorNet::UpdateSensor(2);

    // tell weather station something has changed
    station.Notify();

    // view updated display(s)
    for (disp_itr = displays.begin(); disp_itr != displays.end(); ++disp_itr)
      std::cout << **disp_itr << std::endl; // the itr is a pointer to a pointer
  }

  return 0;
}

bool TestObservers(const std::vector<std::vector<double> >& expected,
    csce240::WeatherStation* station, std::vector<csce240::Display *>* displays,
    std::string* err) {

  // and begin simulating minutes
  for (unsigned int i=0; i < expected.size() && csce240::SensorNet::on(); ++i) {
    // simulate a minute of time passage for sensors
    csce240::SensorNet::UpdateSensor(1);

    // tell weather station something has changed
    station->Notify();

    // ensure expected updated display(s)
    for (unsigned int j = 0; j < expected[i].size(); ++j) {
      if (expected[i][j] != displays->at(j)->GetTemperature()) {
        *err = "Expected: " + std::to_string(expected[i][j])
            + ", Actual: " + std::to_string(displays->at(j)->GetTemperature());

        return false;
      }
    }
  }
  return true;
}

