/** @file
 *	@brief MAVLink comm protocol generated from autogarden.xml
 *	@see http://mavlink.org
 */
#ifndef MAVLINK_AUTOGARDEN_H
#define MAVLINK_AUTOGARDEN_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_AUTOGARDEN.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 102, 20, 0, 0, 0}, {1, 149, 4, 0, 0, 0}, {2, 220, 4, 0, 0, 0}, {3, 78, 4, 0, 0, 0}, {4, 211, 4, 0, 0, 0}, {5, 186, 4, 0, 0, 0}, {20, 151, 2, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_AUTOGARDEN

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_soil_volumetric_water_content.h"
#include "./mavlink_msg_soil_temperature.h"
#include "./mavlink_msg_ambient_air_temperature.h"
#include "./mavlink_msg_ambient_air_humidity.h"
#include "./mavlink_msg_ambient_luminosity.h"
#include "./mavlink_msg_activate_water_pump.h"

// base include


#ifndef MAVLINK_MESSAGE_INFO
#define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_SOIL_VOLUMETRIC_WATER_CONTENT, MAVLINK_MESSAGE_INFO_SOIL_TEMPERATURE, MAVLINK_MESSAGE_INFO_AMBIENT_AIR_TEMPERATURE, MAVLINK_MESSAGE_INFO_AMBIENT_AIR_HUMIDITY, MAVLINK_MESSAGE_INFO_AMBIENT_LUMINOSITY, MAVLINK_MESSAGE_INFO_ACTIVATE_WATER_PUMP}
#endif

#if MAVLINK_COMMAND_24BIT
#include "../mavlink_get_info.h"
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_AUTOGARDEN_H
