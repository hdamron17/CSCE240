#include "temp_display.h"

namespace csce240 {

double TempDisplay::GetTemperature() const {
  return temp_;
}

void TempDisplay::SetTemperature(double val) {
  temp_ = val;
}

void TempDisplay::ExtractTo(std::ostream& cout) const {
  cout << "Current Temperature is " << temp_ << "C "
       << (9.0*temp_/5.0 + 32.0) << "F";
}

}  // namespace csce240
