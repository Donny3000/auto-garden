#include "Vegetronix_THERM200.h"

namespace vegetronix_sensor
{
  Vegetronix_THERM200::Vegetronix_THERM200(uint8_t pin) :
    VegetronixSensor(), pin_(pin)
  {
    pinMode(pin_, INPUT);
  }

  void Vegetronix_THERM200::readSensor(vegetronix_sensor_data_t &data)
  {
    data.analogValue = analogRead(pin_) * 1.0;
    data.voltage = data.analogValue * (REF_VOLTAGE / ADC_RESOLUTION_VALUE);

    data.value = (data.voltage * 41.67) - 40.0;
  }

  void Vegetronix_THERM200::readSensorWithStats(vegetronix_sensor_data_t &data)
  {
    // Sums for calculating statistics
    uint32_t sensorDNsum = 0;
    uint32_t sensorDN;
    float sensorVoltageSum = 0.0;
    float sensorTempSum = 0.0;
    float sqDevSum_DN = 0.0;
    float sqDevSum_volts = 0.0;
    float sqDevSum_Temp = 0.0;
    float sensorVoltage, temp;

    // Make measurements and add to arrays
    for(uint32_t i = 0; i < NUMBER_OF_MEASUREMENTS; i++)
    {
      // Read value and convert to voltage
      sensorDN = analogRead(pin_);
      sensorVoltage = sensorDN * (REF_VOLTAGE / ADC_RESOLUTION_VALUE);
      temp = (sensorVoltage * 41.67) - 40.0;

      // Add to statistics sums
      sensorDNsum += sensorDN;
      sensorVoltageSum += sensorVoltage;
      sensorTempSum += temp;

      // Add to arrays
      sensorDNs_[i] = sensorDN;
      sensorVoltages_[i] = sensorVoltage;
      sensorTemps_[i] = temp;

      // Wait for next measurement
      delay(DELAY_BETWEEN_MEASUREMENTS);
    }

    // Calculate means
    float DN_mean = float(sensorDNsum) / float(NUMBER_OF_MEASUREMENTS);
    float volts_mean = sensorVoltageSum / float(NUMBER_OF_MEASUREMENTS);
    float temp_mean = sensorTempSum / float(NUMBER_OF_MEASUREMENTS);

    // Loop back through to calculate SD
    for(uint32_t i = 0; i < NUMBER_OF_MEASUREMENTS; i++)
    {
      sqDevSum_DN += pow((DN_mean - float(sensorDNs_[i])), 2);
      sqDevSum_volts += pow((volts_mean - float(sensorVoltages_[i])), 2);
      sqDevSum_Temp += pow((temp_mean - float(sensorTemps_[i])), 2);
    }

    float DN_stDev = sqrt(sqDevSum_DN / float(NUMBER_OF_MEASUREMENTS));
    float volts_stDev = sqrt(sqDevSum_volts / float(NUMBER_OF_MEASUREMENTS));
    float temp_stDev = sqrt(sqDevSum_Temp / float(NUMBER_OF_MEASUREMENTS));

    // Setup the output struct
    data.analogValue = DN_mean;
    data.analogValue_sd = DN_stDev;
    data.voltage = volts_mean;
    data.voltage_sd = volts_stDev;
    data.value = temp_mean;
    data.value_sd = temp_stDev;
  }
}
