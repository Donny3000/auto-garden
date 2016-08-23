/*
  Vegetronix_THERM200.h - Library for reading samples from a Veqetronix
                          THERM200 soil temperature sensor.
  Created by Donald R. Poole, Jr, August 18, 2016.
  Released into the public domain
*/
#ifndef VEGETRONIX_THERM200_H
#define VEGETRONIX_THERM200_H

#include <Vegetronix_Sensor.h>

namespace vegetronix_sensor
{
  class Vegetronix_THERM200 : public Vegetronix_Sensor
  {
  public:
    Vegetronix_THERM200(uint8_t pin);

    // This function returns soil temperature by converting the analogPin
    // value to voltage and then converting voltage to the linear temperature
    // reading degrees Celcius. Datasheet provided at
    // https://www.vegetronix.com/Products/THERM200
    void readSensor(vegetronix_sensor_data_t& data);

    // This variant calculates the mean and standard deviation of 100
    // measurements. It reports mean and standard deviation for the analog value,
    // voltage, and soil temperature.
    void readSensorWithStats(vegetronix_sensor_data_t& data);

  private:
    // Arrays to hold multiple measurements
    uint32_t sensorDNs_[NUMBER_OF_MEASUREMENTS];
    float sensorVoltages_[NUMBER_OF_MEASUREMENTS];
    float sensorTemps_[NUMBER_OF_MEASUREMENTS];
  };
}

#endif
