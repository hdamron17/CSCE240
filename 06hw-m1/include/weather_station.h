/* Copyright 2018 */
/* Slightly modified by Hunter Damron */
#ifndef _06HW_INCLUDE_WEATHER_STATION_H_  // NOLINT(build/header_guard)
#define _06HW_INCLUDE_WEATHER_STATION_H_

#include <cassert>
#include <string>
#include <cmath>
// using pow

#include "observable.h"  // NOLINT(build/include_subdir)
#include "sensor_net.h"  // NOLINT(build/include_subdir)

namespace csce240 {

class WeatherStation : public Observable {
 public:
  WeatherStation();
  virtual ~WeatherStation() {}

  double GetHumidity() const;
  double GetPressure() const;
  double GetTemperature() const;

 private:
  double GetSensor(std::string type) const;
};

}  // namespace csce240

#endif  // _06HW_INCLUDE_WEATHER_STATION_H_
