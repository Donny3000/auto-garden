#include "Vegetronix_VH400.h"

namespace vegetronix_sensor
{
  Vegetronix_VH400::Vegetronix_VH400(uint8_t pin) :
    Vegetronix_Sensor(pin)
  {
  }

  void Vegetronix_VH400::readSensor(vegetronix_sensor_data_t& data)
  {
    data.analogValue = analogRead(pin_) * 1.0;
    data.voltage = data.analogValue * (REF_VOLTAGE / ADC_RESOLUTION_VALUE);

    // Calculate vwc
    if(data.voltage <= 1.1)
    {
      data.value = 10 * data.voltage - 1;
    }
    else if(data.voltage > 1.1 && data.voltage <= 1.3)
    {
      data.value = 25 * data.voltage - 17.5;
    }
    else if(data.voltage > 1.3 && data.voltage <= 1.82)
    {
      data.value = 48.08 * data.voltage - 47.5;
    }
    else if(data.voltage > 1.82)
    {
      data.value = 26.32 * data.voltage - 7.89;
    }

  }

  void Vegetronix_VH400::readSensorWithStats(vegetronix_sensor_data_t &data)
  {
    // Sums for calculating statistics
    uint32_t sensorDNsum = 0;
    uint32_t sensorDN;
    float sensorVoltageSum = 0.0;
    float sensorVWCSum = 0.0;
    float sqDevSum_DN = 0.0;
    float sqDevSum_volts = 0.0;
    float sqDevSum_VWC = 0.0;
    float sensorVoltage, vwc;

    // Make measurements and add to arrays
    for(uint32_t i = 0; i < NUMBER_OF_MEASUREMENTS; i++)
    {
      // Read value and convert to voltage
      sensorDN = analogRead(pin_);
      sensorVoltage = sensorDN * (REF_VOLTAGE / ADC_RESOLUTION_VALUE);

      // Calculate VWC
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

      // Add to statistics sums
      sensorDNsum += sensorDN;
      sensorVoltageSum += sensorVoltage;
      sensorVWCSum += vwc;

      // Add to arrays
      sensorDNs_[i] = sensorDN;
      sensorVoltages_[i] = sensorVoltage;
      sensorVWCs_[i] = vwc;

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
      sqDevSum_DN += pow((DN_mean - float(sensorDNs_[i])), 2);
      sqDevSum_volts += pow((volts_mean - float(sensorVoltages_[i])), 2);
      sqDevSum_VWC += pow((VWC_mean - float(sensorVWCs_[i])), 2);
    }

    float DN_stDev = sqrt(sqDevSum_DN / float(NUMBER_OF_MEASUREMENTS));
    float volts_stDev = sqrt(sqDevSum_volts / float(NUMBER_OF_MEASUREMENTS));
    float VWC_stDev = sqrt(sqDevSum_VWC / float(NUMBER_OF_MEASUREMENTS));

    // Setup the output struct
    data.analogValue = DN_mean;
    data.analogValue_sd = DN_stDev;
    data.voltage = volts_mean;
    data.voltage_sd = volts_stDev;
    data.value = VWC_mean;
    data.value_sd = VWC_stDev;
  }
}
