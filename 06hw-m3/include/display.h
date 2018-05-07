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
  /* An Observer must know about its Observable.
   * - Display stores address of a WeatherStation instance. Do not create new
   *   memory or you will not get updates. Store a copy of the actual address
   *   in a const WeatherStation pointer.
   */
  Display(const WeatherStation*);
  virtual ~Display() {}

  virtual double GetHumidity() const = 0;
  virtual void SetHumidity(double val) = 0;

  virtual double GetPressure() const = 0;
  virtual void SetPressure(double val) = 0;

  virtual double GetTemperature() const = 0;
  virtual void SetTemperature(double val) = 0;

  /* Leaving this method virtual so that child classes may override for ease of
   * adding functionality.
   *
   * The method should call each of the setters and pass in the value from each
   * of the const WeatherStation* instance's getters, i.e.
   *   SetHumidity(<pointer to some weather station instance>->GetHumidity());
   */
  virtual void Update();

  friend std::ostream& operator<<(std::ostream& cout, const Display& rhs);

 protected:
  virtual void ExtractTo(std::ostream& cout) const = 0;
};

// place operator decl in csce240 namespace
std::ostream& operator<<(std::ostream& cout, const Display& rhs);

}  // namespace csce240

#endif
