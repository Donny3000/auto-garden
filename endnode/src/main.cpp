/**
 * Auto Garden Endnode
 *
 * This firmware will collect data from the Endnode Transiever device and relay
 * the data back to the gateway for processing and logging.  The Endnode
 * firmware will also control the water valve.
 *
 * Author: Donald R. Poole, Jr.
 * Date: July 31, 2016
 */
#include "Arduino.h"
#include "Wire.h"
#include "SPI.h"
#include "../../lib/include/autogarden/mavlink.h"

#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)
  // Required for Serial on Zero based boards
  #define Serial SERIAL_PORT_USBVIRTUAL
#endif

#include <Vegetronix_VH400.h>

// RFM69 Transiever Interface
#include <RFM69.h>
#include <RFM69_ATC.h>

//******************************************************************************
//****************** Adafruit Unified Sensor Includes **************************
//******************************************************************************
#include <Adafruit_Sensor.h>
//  TSL2561 Light Sensor
#include <Adafruit_TSL2561_U.h>
//  DHT22 Temp/Humidity Sensor
#include <DHT.h>
#include <DHT_U.h>

//******************************************************************************
//*****IMPORTANT SETTINGS - YOU MUST CHANGE/CONFIGURE TO FIT YOUR HARDWARE *****
//******************************************************************************
#define NETWORKID     100  // The same on all nodes that talk to each other
#define NODEID        1    // The unique identifier of this node
#define RECEIVER      0    // The recipient of packets

//Match frequency to the hardware version of the radio on your Feather
//#define FREQUENCY     RF69_433MHZ
//#define FREQUENCY     RF69_868MHZ
#define FREQUENCY     RF69_915MHZ
#define ENCRYPTKEY    "autoGardenKey001" // Exactly the same 16 characters/bytes on all nodes!
#define IS_RFM69HCW   true // Set to 'true' if you are using an RFM69HCW module
//******************************************************************************
#define SERIAL_BAUD   115200

#if defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)
/* for Feather M0 */
  #define RFM69_CS      8
  #define RFM69_IRQ     3
  #define RFM69_IRQN    3  // Pin 3 is IRQ 3!
  #define RFM69_RST     4
#elif defined(ARDUINO_ARCH_STM32F2)
/* for Feather 32u4 */
  #define RFM69_CS      8
  #define RFM69_IRQ     7
  #define RFM69_IRQN    4  // Pin 7 is IRQ 4!
  #define RFM69_RST     4
#else
/* for Arduino Uno */
  #define RFM69_CS      10
  #define RFM69_IRQ     2
  #define RFM69_IRQN    0  // Pin 2 is IRQ 0!
  #define RFM69_RST     9
#endif

#define LED           13  // onboard blinky

// Temperature/Humidity sensor defines
#define DHTPIN        2   // Pin which is connected to the DHT sensor.
// Uncomment the type of sensor in use:
//#define DHTTYPE           DHT11     // DHT 11
#define DHTTYPE       DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)

//****************************************************************************
//******************** Objects to hold the data from the sensors *************
//****************************************************************************
uint8_t                                 mavlink_buf[MAVLINK_MAX_PACKET_LEN];
mavlink_message_t                       data_pkt;
mavlink_activate_water_pump_t           msg_activate_water_pump;
mavlink_ambient_air_humidity_t          msg_ambient_humidity;
mavlink_ambient_air_temperature_t       msg_ambient_temp;
mavlink_ambient_luminosity_t            msg_ambient_luminosity;
mavlink_soil_temperature_t              msg_soil_temp;
mavlink_soil_volumetric_water_content_t msg_soil_vwc;

//****************************************************************************
//************ Instantiate interfaces for the various pieces of hardware *****
//****************************************************************************
RFM69 radio = RFM69(RFM69_CS, RFM69_IRQ, IS_RFM69HCW, RFM69_IRQN);

// The address will be different depending on whether you leave
// the ADDR pin float (addr 0x39), or tie it to ground or vcc. In those cases
// use TSL2561_ADDR_LOW (0x29) or TSL2561_ADDR_HIGH (0x49) respectively
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

DHT_Unified dht(DHTPIN, DHTTYPE);

Vegetronix_VH400 vh400(5);
//****************************************************************************

//****************************************************************************
//**************** Routines to read samples from the sensors *****************
//****************************************************************************

//****************************************************************************
//*************************** ISR for sample timer ***************************
//****************************************************************************
void TC3_Handler()
{
}

//****************************************************************************
//************ Setup Routines for the various pieces of hardware *************
//****************************************************************************
void setupRadio(void)
{
  //while (!Serial); // wait until serial console is open, remove if not tethered to computer

  Serial.println("Feather RFM69HCW Transmitter");

  // Hard Reset the RFM module
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, HIGH);
  delay(100);
  digitalWrite(RFM69_RST, LOW);
  delay(100);

  // Initialize radio
  radio.initialize(FREQUENCY, NODEID, NETWORKID);
  if(IS_RFM69HCW)
  {
    radio.setHighPower();    // Only for RFM69HCW & HW!
  }
  radio.setPowerLevel(31); // power output ranges from 0 (5dBm) to 31 (20dBm)

  radio.encrypt(ENCRYPTKEY);

  Serial.print("\nTransmitting at ");
  Serial.print(FREQUENCY==RF69_433MHZ ? 433 : FREQUENCY==RF69_868MHZ ? 868 : 915);
  Serial.println(" MHz");
}

void setupLuminositySensor(void)
{
  /* You can also manually set the gain or enable auto-gain support */
  // tsl.setGain(TSL2561_GAIN_1X);      /* No gain ... use in bright light to avoid sensor saturation */
  // tsl.setGain(TSL2561_GAIN_16X);     /* 16x gain ... use in low light to boost sensitivity */
  tsl.enableAutoRange(true);          /* Auto-gain ... switches automatically between 1x and 16x */

  /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */

  /* Update these values depending on what you've set above! */
  Serial.println("------------------------------------");
  Serial.print  ("Gain:         "); Serial.println("Auto");
  Serial.print  ("Timing:       "); Serial.println("13 ms");
  Serial.println("------------------------------------");
}

void setupTempHumiditySensor(void)
{
  // Initialize the device
  dht.begin();
}
//****************************************************************************

void Blink(byte PIN, byte DELAY_MS, byte loops)
{
  for (byte i=0; i<loops; i++)
  {
    digitalWrite(PIN, HIGH);
    delay(DELAY_MS);
    digitalWrite(PIN, LOW);
    delay(DELAY_MS);
  }
}

void setup()
{
  Serial.begin(SERIAL_BAUD);

  // initialize the H/W
  setupRadio();
  setupLuminositySensor();
  setupTempHumiditySensor();

  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  delay(1000);  // Wait 1 second between transmits, could also 'sleep' here!

  // Create and pack the heartbeat data
  mavlink_msg_heartbeat_pack(NODEID, NODEID, &data_pkt, 78.3, 45.1, 83.6, 75.4, 10234);
  uint16_t buf_len = mavlink_msg_to_send_buffer(mavlink_buf, &data_pkt);

  radio.send(RECEIVER, mavlink_buf, buf_len, false);
  Blink(LED_BUILTIN, 50, 3);
  /*if(radio.sendWithRetry(RECEIVER, radiopacket, strlen(radiopacket)))
  {
    Serial.println("OK");
    Blink(LED_BUILTIN, 50, 3); //blink LED 3 times, 50ms between blinks
  }*/

  radio.receiveDone(); // Put radio in RX mode
  Serial.flush(); // Make sure all serial data is clocked out before sleeping the MCU
}
