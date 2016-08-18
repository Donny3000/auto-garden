#include "Vegetronix_VH400.h"

// Arrays to hold multiple measurements
uint32_t sensorDNs[NUMBER_OF_MEASUREMENTS];
float sensorVoltages[NUMBER_OF_MEASUREMENTS];
float sensorVWCs[NUMBER_OF_MEASUREMENTS];

Vegetronix_VH400::Vegetronix_VH400(uint8_t pin, uint8_t res) :
  pin_(pin), res_(res)
{
  pinMode(pin, INPUT);
  analogReadResolution(res);
}

float Vegetronix_VH400::readSensor()
{
  uint16_t value = analogRead(pin_);
  float sensorVoltage, vwc;

  if(res_ == 10)
    float sensorVoltage = value * (3.0 / RES_10_BIT);
  else if(res_ == 12)
    float sensorVoltage = value * (3.0 / RES_12_BIT);

  // Calculate vwc
  if(sensorVoltage <= 1.1)
  {
    vwc = 10 * sensorVoltage - 1;
  }
  else if(sensorVoltage > 1.1 && sensorVoltage <= 1.3)
  {
    vwc = 25 * sensorVoltage - 17.5;
  }
  else if(sensorVoltage > 1.3 && sensorVoltage <= 1.82)
  {
    vwc = 48.08 * sensorVoltage - 47.5;
  }
  else if(sensorVoltage > 1.82)
  {
    vwc = 26.32 * sensorVoltage - 7.89;
  }
  return (vwc);
}

void Vegetronix_VH400::readSensorWithStats(vegetronix_vh400_data_t &data)
{
  // Sums for calculating statistics
  uint32_t sensorDNsum = 0;
  float sensorVoltageSum = 0.0;
  float sensorVWCSum = 0.0;
  float sqDevSum_DN = 0.0;
  float sqDevSum_volts = 0.0;
  float sqDevSum_VWC = 0.0;

  // Make measurements and add to arrays
  for(uint32_t i = 0; i < NUMBER_OF_MEASUREMENTS; i++)
  {
    // Read value and convert to voltage
    uint32_t sensorDN = analogRead(pin_);
    float sensorVoltage = sensorDN*(3.0 / 1023.0);

    // Calculate VWC
    float VWC;
    if(sensorVoltage <= 1.1) {
      VWC = 10*sensorVoltage-1;
    } else if(sensorVoltage > 1.1 && sensorVoltage <= 1.3) {
      VWC = 25*sensorVoltage-17.5;
    } else if(sensorVoltage > 1.3 && sensorVoltage <= 1.82) {
      VWC = 48.08*sensorVoltage-47.5;
    } else if(sensorVoltage > 1.82) {
      VWC = 26.32*sensorVoltage-7.89;
    }

    // Add to statistics sums
    sensorDNsum += sensorDN;
    sensorVoltageSum += sensorVoltage;
    sensorVWCSum += VWC;

    // Add to arrays
    sensorDNs[i] = sensorDN;
    sensorVoltages[i] = sensorVoltage;
    sensorVWCs[i] = VWC;

    // Wait for next measurement
    delay(DELAY_BETWEEN_MEASUREMENTS);
  }

  // Calculate means
  float DN_mean = float(sensorDNsum) / float(NUMBER_OF_MEASUREMENTS);
  float volts_mean = sensorVoltageSum / float(NUMBER_OF_MEASUREMENTS);
  float VWC_mean = sensorVWCSum / float(NUMBER_OF_MEASUREMENTS);

  // Loop back through to calculate SD
  for(uint32_t i = 0; i < NUMBER_OF_MEASUREMENTS; i++)
  {
    sqDevSum_DN += pow((DN_mean - float(sensorDNs[i])), 2);
    sqDevSum_volts += pow((volts_mean - float(sensorVoltages[i])), 2);
    sqDevSum_VWC += pow((VWC_mean - float(sensorVWCs[i])), 2);
  }
  float DN_stDev = sqrt(sqDevSum_DN/float(NUMBER_OF_MEASUREMENTS));
  float volts_stDev = sqrt(sqDevSum_volts/float(NUMBER_OF_MEASUREMENTS));
  float VWC_stDev = sqrt(sqDevSum_VWC/float(NUMBER_OF_MEASUREMENTS));

  // Setup the output struct
  data.analogValue = DN_mean;
  data.analogValue_sd = DN_stDev;
  data.voltage = volts_mean;
  data.voltage_sd = volts_stDev;
  data.VWC = VWC_mean;
  data.VWC_sd = VWC_stDev;
}
