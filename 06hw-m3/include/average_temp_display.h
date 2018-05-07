#ifndef _06HW_INCLUDE_AVERAGE_TEMP_DISPLAY_H_
#define _06HW_INCLUDE_AVERAGE_TEMP_DISPLAY_H_

#include <ostream>

#include "display.h"
#include "weather_station.h"

namespace csce240 {

/* A class which maintains the average temperature seen over last n temperature
 * updates in Celcius.
 */
class AverageTempDisplay : public Display {
 public:
  /* Updated to get a reference to attach to WeatherStation.
   *   Passes input pointer to parent constructor
   */
  AverageTempDisplay(const WeatherStation*);

 protected:

 private:
};

}  // namespace csce240

#endif
