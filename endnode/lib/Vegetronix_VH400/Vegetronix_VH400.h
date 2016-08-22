/*
  Vegetronix_VH400.h - Library for reading samples from a Veqetronix VH400 soil
                       moisture sensor.
  Created by Donald R. Poole, Jr, August 18, 2016.
  Released into the public domain
*/
#ifndef VEGETRONIX_VH400_H
#define VEGETRONIX_VH400_H

#include <Vegetronix_Sensor.h>

namespace vegetronix_sensor
{
  class Vegetronix_VH400 : public VegetronixSensor
  {
  public:
    Vegetronix_VH400(uint8_t pin);

    // This function returns Volumetric Water Content by converting the analogPin
    // value to voltage and then converting voltage to VWC using the piecewise
    // regressions provided by the manufacturer
    // at http://www.vegetronix.com/Products/VH400/VH400-Piecewise-Curve.phtml
    void readSensor(vegetronix_sensor_data_t& data);

    // This variant calculates the mean and standard deviation of 100 measurements
    // over 5 seconds.
    // It reports mean and standard deviation for the analog value, voltage,
    // and WVC. This function returns Volumetric Water Content by converting the
    // pin value to voltage and then converting voltage to VWC using the piecewise
    // regressions provided by the manufacturer
    // at http://www.vegetronix.com/Products/VH400/VH400-Piecewise-Curve.phtml
    void readSensorWithStats(vegetronix_sensor_data_t& data);

  private:
    uint8_t pin_;

    // Arrays to hold multiple measurements
    uint32_t sensorDNs_[NUMBER_OF_MEASUREMENTS];
    float sensorVoltages_[NUMBER_OF_MEASUREMENTS];
    float sensorVWCs_[NUMBER_OF_MEASUREMENTS];
  };
}

#endif
