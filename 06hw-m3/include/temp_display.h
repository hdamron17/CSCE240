#ifndef _06HW_INCLUDE_TEMP_DISPLAY_H_
#define _06HW_INCLUDE_TEMP_DISPLAY_H_

#include <ostream>

#include "display.h"
#include "weather_station.h"

namespace csce240 {

/* A class which maintains the average temperature seen over last n temperature
 * updates in Celcius.
 */
class TempDisplay : public Display {
 public:
  /* Updated to get a reference to attach to WeatherStation
   */
  TempDisplay(const WeatherStation* station)
      : Display(station), temp_(0.0) {}

  double GetHumidity() const { return 0.0; }
  void SetHumidity(double val) { /* do nothing */ }

  double GetPressure() const { return 0.0; }
  void SetPressure(double val) { /* do nothing */ }

  double GetTemperature() const;
  void SetTemperature(double val);

 protected:
  void ExtractTo(std::ostream& cout) const;

 private:
  double temp_;
};

}  // namespace csce240

#endif
