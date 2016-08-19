/*
  Vegetronix_THERM200.h - Library for reading samples from a Veqetronix
                          THERM200 soil temperature sensor.
  Created by Donald R. Poole, Jr, August 18, 2016.
  Released into the public domain
*/
#ifndef VEGETRONIX_THERM200_H
#define VEGETRONIX_THERM200_H

#include <Arduino.h>

#if defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)
#define REF_VOLTAGE          3.3
#define ADC_RESOLUTION_VALUE 4095
#else
#define REF_VOLTAGE          5.0
#define ADC_RESOLUTION_VALUE 1023
#endif

#define NUMBER_OF_MEASUREMENTS 100
#define DELAY_BETWEEN_MEASUREMENTS 1

namespace vegetronix
{
  typedef struct vegetronix_therm200_data {
    float analogValue;
    float analogValue_sd;
    float voltage;
    float voltage_sd;
    float temp;
    float temp_sd;
  } vegetronix_therm200_data_t;

  class Vegetronix_THERM200
  {
  public:
    Vegetronix_THERM200(uint8_t pin, uint8_t res = ADC_RESOLUTION);

    // This function returns soil temperature by converting the analogPin
    // value to voltage and then converting voltage to the linear temperature
    // reading degrees Celcius. Datasheet provided at
    // https://www.vegetronix.com/Products/THERM200
    float readSensor(void);

    // This variant calculates the mean and standard deviation of 100
    // measurements. It reports mean and standard deviation for the analog value,
    // voltage, and WVC. This function returns the soil temperature by
    // converting the pin value to voltage and then converting voltage to the
    // linear soil temperature reading in degress Celcius. Datasheet provided
    // at https://www.vegetronix.com/Products/THERM200
    void readSensorWithStats(vegetronix_therm200_data_t& data);

  private:
    uint8_t pin_;
    uint8_t res_;

    // Arrays to hold multiple measurements
    uint32_t sensorDNs_[NUMBER_OF_MEASUREMENTS];
    float sensorVoltages_[NUMBER_OF_MEASUREMENTS];
    float sensorTemps_[NUMBER_OF_MEASUREMENTS];
  };
}

#endif
