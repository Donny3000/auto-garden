/*
  Vegetronix_VH400.h - Library for reading samples from a Veqetronix VH400 soil
                       moisture sensor.
  Created by Donald R. Poole, Jr, August 18, 2016.
  Released into the public domain
*/
#ifndef VEGETRONIX_VH400_H
#define VEGETRONIX_VH400_H

#include <Arduino.h>

#define RES_10_BIT 1023
#define RES_12_BIT 4095
#define NUMBER_OF_MEASUREMENTS 100
#define DELAY_BETWEEN_MEASUREMENTS 1

typedef struct VH400 {
  float analogValue;
  float analogValue_sd;
  float voltage;
  float voltage_sd;
  float VWC;
  float VWC_sd;
} vegetronix_vh400_data_t;

class Vegetronix_VH400
{
public:
  Vegetronix_VH400(uint8_t pin, uint8_t res = 12);

  // This function returns Volumetric Water Content by converting the analogPin
  // value to voltage and then converting voltage to VWC using the piecewise
  // regressions provided by the manufacturer
  // at http://www.vegetronix.com/Products/VH400/VH400-Piecewise-Curve.phtml
  float readSensor(void);

  // This variant calculates the mean and standard deviation of 100 measurements
  // over 5 seconds.
  // It reports mean and standard deviation for the analog value, voltage,
  // and WVC. This function returns Volumetric Water Content by converting the
  // pin value to voltage and then converting voltage to VWC using the piecewise
  // regressions provided by the manufacturer
  // at http://www.vegetronix.com/Products/VH400/VH400-Piecewise-Curve.phtml
  void readSensorWithStats(vegetronix_vh400_data_t& data);

private:
  uint8_t pin_;
  uint8_t res_;
};

#endif
