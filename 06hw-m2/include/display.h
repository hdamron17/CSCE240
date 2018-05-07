#ifndef _06HW_INCLUDE_DISPLAY_H_
#define _06HW_INCLUDE_DISPLAY_H_

#include <ostream>

#include "observer.h"
#include "weather_station.h"

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

#endif
