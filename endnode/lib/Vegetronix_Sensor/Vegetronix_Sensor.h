/*
  Vegetronix_Sensor.h - Abstract Base Class to be implemented by all Vegetronix
                       sensors.
  Created by Donald R. Poole, Jr, August 22, 2016.
  Released into the public domain
*/
#ifndef VEGETRONIX_SENSOR_H
#define VEGETRONIX_SENSOR_H

#include <Arduino.h>

#if defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)
#define REF_VOLTAGE          3.3
#define ADC_RESOLUTION_VALUE 4095
#else
#define REF_VOLTAGE          5.0
#define ADC_RESOLUTION_VALUE 1023
#endif

#define NUMBER_OF_MEASUREMENTS     100
#define DELAY_BETWEEN_MEASUREMENTS 1 // Milli-seconds

namespace vegetronix_sensor
{
  typedef struct vegetronix_sensor_data {
    float analogValue;
    float analogValue_sd;
    float voltage;
    float voltage_sd;
    float value;
    float value_sd;
  } vegetronix_sensor_data_t;

  class VegetronixSensor
  {
  public:
    VegetronixSensor() {};
    virtual ~VegetronixSensor() {};


    // This method must be defined in the subclass
    virtual void readSensor(vegetronix_sensor_data_t& data) = 0;

    // Optional method that can be implemented to provide statisical data with
    // the sensor data.
    // Params
    // - data: Reference to a Vegetronix sensor data structure.
    // - numOfSamples: Number of samples of data to collect for basic statistical analysis
    // - delayBtwnSamples: How long to wait between samples in milli-seconds
    virtual void readSensorWithStats(vegetronix_sensor_data_t& data) {};
  };
}

#endif
