/* Copyright 2018 */
/* Slightly modified by Hunter Damron */
#ifndef _06HW_INCLUDE_DISPLAY_H_  // NOLINT(build/header_guard)
#define _06HW_INCLUDE_DISPLAY_H_

#include <ostream>

#include "observer.h"  // NOLINT(build/include_subdir)
#include "weather_station.h"  // NOLINT(build/include_subdir)

namespace csce240 {

/* This abstract class forms the basis for all Displays.
 *   Children may or may not have use for the setters and getters, so they may
 *   do nothing.
 */
class Display : public Observer {
 public:
  virtual double GetHumidity() const = 0;
  virtual void SetHumidity(double val) = 0;

  virtual double GetPressure() const = 0;
  virtual void SetPressure(double val) = 0;

  virtual double GetTemperature() const = 0;
  virtual void SetTemperature(double val) = 0;

  friend std::ostream& operator<<(std::ostream& cout, const Display& rhs);

 protected:
  virtual void ExtractTo(std::ostream& cout) const = 0;

  const WeatherStation *station;
};

// place operator decl in csce240 namespace
std::ostream& operator<<(std::ostream& cout, const Display& rhs);

}  // namespace csce240

#endif  // 06HW_M1_INCLUDE_DISPLAY_H_
