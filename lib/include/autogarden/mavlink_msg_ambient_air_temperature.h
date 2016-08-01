// MESSAGE AMBIENT_AIR_TEMPERATURE PACKING

#define MAVLINK_MSG_ID_AMBIENT_AIR_TEMPERATURE 3

typedef struct __mavlink_ambient_air_temperature_t
{
 float ambient_temp; ///< Ambient Air Temperature
} mavlink_ambient_air_temperature_t;

#define MAVLINK_MSG_ID_AMBIENT_AIR_TEMPERATURE_LEN 4
#define MAVLINK_MSG_ID_3_LEN 4



#define MAVLINK_MESSAGE_INFO_AMBIENT_AIR_TEMPERATURE { \
	"AMBIENT_AIR_TEMPERATURE", \
	1, \
	{  { "ambient_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ambient_air_temperature_t, ambient_temp) }, \
         } \
}


/**
 * @brief Pack a ambient_air_temperature message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ambient_temp Ambient Air Temperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ambient_air_temperature_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float ambient_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, ambient_temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_ambient_air_temperature_t packet;
	packet.ambient_temp = ambient_temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_AMBIENT_AIR_TEMPERATURE;
	return mavlink_finalize_message(msg, system_id, component_id, 4, 78);
}

/**
 * @brief Pack a ambient_air_temperature message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param ambient_temp Ambient Air Temperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ambient_air_temperature_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float ambient_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, ambient_temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_ambient_air_temperature_t packet;
	packet.ambient_temp = ambient_temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_AMBIENT_AIR_TEMPERATURE;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 4, 78);
}

/**
 * @brief Encode a ambient_air_temperature struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ambient_air_temperature C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ambient_air_temperature_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ambient_air_temperature_t* ambient_air_temperature)
{
	return mavlink_msg_ambient_air_temperature_pack(system_id, component_id, msg, ambient_air_temperature->ambient_temp);
}

/**
 * @brief Send a ambient_air_temperature message
 * @param chan MAVLink channel to send the message
 *
 * @param ambient_temp Ambient Air Temperature
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ambient_air_temperature_send(mavlink_channel_t chan, float ambient_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, ambient_temp);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_AIR_TEMPERATURE, buf, 4, 78);
#else
	mavlink_ambient_air_temperature_t packet;
	packet.ambient_temp = ambient_temp;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_AIR_TEMPERATURE, (const char *)&packet, 4, 78);
#endif
}

#endif

// MESSAGE AMBIENT_AIR_TEMPERATURE UNPACKING


/**
 * @brief Get field ambient_temp from ambient_air_temperature message
 *
 * @return Ambient Air Temperature
 */
static inline float mavlink_msg_ambient_air_temperature_get_ambient_temp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a ambient_air_temperature message into a struct
 *
 * @param msg The message to decode
 * @param ambient_air_temperature C-struct to decode the message contents into
 */
static inline void mavlink_msg_ambient_air_temperature_decode(const mavlink_message_t* msg, mavlink_ambient_air_temperature_t* ambient_air_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP
	ambient_air_temperature->ambient_temp = mavlink_msg_ambient_air_temperature_get_ambient_temp(msg);
#else
	memcpy(ambient_air_temperature, _MAV_PAYLOAD(msg), 4);
#endif
}
