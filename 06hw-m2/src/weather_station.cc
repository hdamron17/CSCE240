/* Copyright 2018 */
/* Modified by Hunter Damron */
#include "weather_station.h"  // NOLINT(build/include_subdir)

namespace csce240 {
  WeatherStation::WeatherStation() {
    SensorNet::PowerOn();
  }

  double WeatherStation::GetHumidity() const {
    return GetSensor("HUM");
  }

  double WeatherStation::GetPressure() const {
    return GetSensor("PRS");
  }

  double WeatherStation::GetTemperature() const {
    return GetSensor("TMP");
  }

  double WeatherStation::GetSensor(std::string type) const {
    for (int sensor = 0; sensor < SensorNet::k_sensor_count_; ++sensor) {
      int size = 0;
      const int kBufferSize = 10;
      char reading[kBufferSize];
      SensorNet::ReadSensor(sensor, &size, reading);
      assert(size <= kBufferSize);  // If it's not we have a problem

      if (size < kBufferSize) reading[size] = '\0';

      int space = 0;
      for (; space < size && reading[space] != ' '; ++space) {}  // Find space

      double val = 0;
      for (int i = 0; i < size && reading[i] != ' '; ++i) {
        int digit = reading[space - i - 1] - '0';
        assert(digit >= 0 && digit <= 9);
        val += digit * pow(10, i - 2);
      }

      bool match = true;
      for (int j = 0; space + j + 1 < size && j < type.size(); ++j) {
        if (type[j] != reading[space + j + 1])
          match = false;
      }
      if (match) {
        return val;
      }
    }
    return -1;
  }
}  // namespace csce240
