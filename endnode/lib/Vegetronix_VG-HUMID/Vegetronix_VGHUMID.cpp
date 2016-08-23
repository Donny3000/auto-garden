#include <Vegetronix_VGHUMID.h>

namespace vegetronix_sensor
{
  Vegetronix_VGHUMID::Vegetronix_VGHUMID(const uint8_t pin) :
    Vegetronix_Sensor(pin)
    {
    }

    void Vegetronix_VGHUMID::readSensor(vegetronix_sensor_data_t& data)
    {
      data.analogValue = analogRead(pin_) * 1.0;
      data.voltage = data.analogValue * (REF_VOLTAGE / ADC_RESOLUTION_VALUE);
      data.value = data.voltage * 33.33;
    }

    void Vegetronix_VGHUMID::readSensorWithStats(vegetronix_sensor_data_t& data)
    {
      // Sums for calculating statistics
      uint32_t sensorDNsum = 0;
      uint32_t sensorDN;
      float sensorVoltageSum = 0.0;
      float sensorRHSum = 0.0;
      float sqDevSum_DN = 0.0;
      float sqDevSum_volts = 0.0;
      float sqDevSum_RH = 0.0;
      float sensorVoltage, RH;

      // Make measurements and add to arrays
      for(uint32_t i = 0; i < NUMBER_OF_MEASUREMENTS; i++)
      {
        // Read value and convert to voltage
        sensorDN = analogRead(pin_);
        sensorVoltage = sensorDN * (REF_VOLTAGE / ADC_RESOLUTION_VALUE);
        RH = sensorVoltage * 33.33;

        // Add to statistics sums
        sensorDNsum += sensorDN;
        sensorVoltageSum += sensorVoltage;
        sensorRHSum += RH;

        // Add to arrays
        sensorDNs_[i] = sensorDN;
        sensorVoltages_[i] = sensorVoltage;
        sensorRHs_[i] = RH;

        // Wait for next measurement
        delay(DELAY_BETWEEN_MEASUREMENTS);
      }

      // Calculate means
      float DN_mean = float(sensorDNsum) / float(NUMBER_OF_MEASUREMENTS);
      float volts_mean = sensorVoltageSum / float(NUMBER_OF_MEASUREMENTS);
      float RH_mean = sensorRHSum / float(NUMBER_OF_MEASUREMENTS);

      // Loop back through to calculate SD
      for(uint32_t i = 0; i < NUMBER_OF_MEASUREMENTS; i++)
      {
        sqDevSum_DN += pow((DN_mean - float(sensorDNs_[i])), 2);
        sqDevSum_volts += pow((volts_mean - float(sensorVoltages_[i])), 2);
        sqDevSum_RH += pow((RH_mean - float(sensorRHs_[i])), 2);
      }

      float DN_stDev = sqrt(sqDevSum_DN / float(NUMBER_OF_MEASUREMENTS));
      float volts_stDev = sqrt(sqDevSum_volts / float(NUMBER_OF_MEASUREMENTS));
      float RH_stDev = sqrt(sqDevSum_RH / float(NUMBER_OF_MEASUREMENTS));

      // Setup the output struct
      data.analogValue = DN_mean;
      data.analogValue_sd = DN_stDev;
      data.voltage = volts_mean;
      data.voltage_sd = volts_stDev;
      data.value = RH_mean;
      data.value_sd = RH_stDev;
    }
}
