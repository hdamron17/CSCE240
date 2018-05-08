/* Copyright 2018 */
/* Modified by Hunter Damron */
#include "average_temp_display.h"  // NOLINT(build/include_subdir)

namespace csce240 {
  void AverageTempDisplay::SetHumidity(double val) {}

  double AverageTempDisplay::GetPressure() const { return -1; }
  void AverageTempDisplay::SetPressure(double val) {}

  double AverageTempDisplay::GetTemperature() const { return -1; }
  void AverageTempDisplay::SetTemperature(double val) {}

  void AverageTempDisplay::Update() {}

  void AverageTempDisplay::ExtractTo(std::ostream& cout) const {}

}  // namespace csce240
