#ifndef VEGETRONIX_VGHUMID_H
#define VEGETRONIX_VGHUMID_H

#include <Vegetronix_Sensor.h>

namespace vegetronix_sensor
{
  class Vegetronix_VGHUMID : public Vegetronix_Sensor
  {
  public:
    Vegetronix_VGHUMID(const uint8_t analogPin);

    // This function returns the Relative Humidity (RH) of the air by converting
    // the analogPin value to voltage and then converting voltage to the linear
    // relative humidity range of 0-100%.
    // http://www.vegetronix.com/Products/VG-HUMID/
    void readSensor(vegetronix_sensor_data_t& data);

    // This variant calculates the mean and standard deviation of 100
    // measurements. It reports mean and standard deviation for the analog value,
    // voltage, and RH.
    void readSensorWithStats(vegetronix_sensor_data_t& data);

  private:
    // Arrays to hold multiple measurements
    uint32_t sensorDNs_[NUMBER_OF_MEASUREMENTS];
    float sensorVoltages_[NUMBER_OF_MEASUREMENTS];
    float sensorRHs_[NUMBER_OF_MEASUREMENTS];
  };
}

#endif
