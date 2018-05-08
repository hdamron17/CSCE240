/* Copyright 2018 */
/* Slightly modified by Hunter Damron */
#ifndef _06HW_INCLUDE_AVERAGE_TEMP_DISPLAY_H_  // NOLINT(build/header_guard)
#define _06HW_INCLUDE_AVERAGE_TEMP_DISPLAY_H_

#include <ostream>

#include "display.h"  // NOLINT(build/include_subdir)

namespace csce240 {

/* A class which maintains the average temperature in Celcius seen over the
 *   last n calls to SetTemperature.
 */
class AverageTempDisplay : public Display {
 public:
  AverageTempDisplay::AverageTempDisplay() {
    station = new WeatherStation;
  }

  virtual AverageTempDisplay::~AverageTempDisplay() {
    if (station) delete station;
  }

  virtual double GetHumidity() const;
  virtual void SetHumidity(double val);

  virtual double GetPressure() const;
  virtual void SetPressure(double val);

  virtual double GetTemperature() const;
  virtual void SetTemperature(double val);

  virtual void Update();

 protected:
  virtual void ExtractTo(std::ostream& cout) const;

 private:
  double avgHum, avgPrs, avgTmp, lastHum, lastPrs, lastTmp;
  int numHum, numPrs, numTmp;
};

}  // namespace csce240

#endif  // _06HW_INCLUDE_AVERAGE_TEMP_DISPLAY_H_
