// MESSAGE SOIL_TEMPERATURE PACKING

#define MAVLINK_MSG_ID_SOIL_TEMPERATURE 2

typedef struct __mavlink_soil_temperature_t
{
 float soil_temp; ///< Soil Temperature (degrees C)
} mavlink_soil_temperature_t;

#define MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN 4
#define MAVLINK_MSG_ID_2_LEN 4



#define MAVLINK_MESSAGE_INFO_SOIL_TEMPERATURE { \
	"SOIL_TEMPERATURE", \
	1, \
	{  { "soil_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_soil_temperature_t, soil_temp) }, \
         } \
}


/**
 * @brief Pack a soil_temperature message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param soil_temp Soil Temperature (degrees C)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_soil_temperature_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float soil_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, soil_temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_soil_temperature_t packet;
	packet.soil_temp = soil_temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_SOIL_TEMPERATURE;
	return mavlink_finalize_message(msg, system_id, component_id, 4, 220);
}

/**
 * @brief Pack a soil_temperature message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param soil_temp Soil Temperature (degrees C)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_soil_temperature_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float soil_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, soil_temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_soil_temperature_t packet;
	packet.soil_temp = soil_temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_SOIL_TEMPERATURE;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 4, 220);
}

/**
 * @brief Encode a soil_temperature struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param soil_temperature C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_soil_temperature_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_soil_temperature_t* soil_temperature)
{
	return mavlink_msg_soil_temperature_pack(system_id, component_id, msg, soil_temperature->soil_temp);
}

/**
 * @brief Send a soil_temperature message
 * @param chan MAVLink channel to send the message
 *
 * @param soil_temp Soil Temperature (degrees C)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_soil_temperature_send(mavlink_channel_t chan, float soil_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, soil_temp);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_TEMPERATURE, buf, 4, 220);
#else
	mavlink_soil_temperature_t packet;
	packet.soil_temp = soil_temp;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_TEMPERATURE, (const char *)&packet, 4, 220);
#endif
}

#endif

// MESSAGE SOIL_TEMPERATURE UNPACKING


/**
 * @brief Get field soil_temp from soil_temperature message
 *
 * @return Soil Temperature (degrees C)
 */
static inline float mavlink_msg_soil_temperature_get_soil_temp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a soil_temperature message into a struct
 *
 * @param msg The message to decode
 * @param soil_temperature C-struct to decode the message contents into
 */
static inline void mavlink_msg_soil_temperature_decode(const mavlink_message_t* msg, mavlink_soil_temperature_t* soil_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP
	soil_temperature->soil_temp = mavlink_msg_soil_temperature_get_soil_temp(msg);
#else
	memcpy(soil_temperature, _MAV_PAYLOAD(msg), 4);
#endif
}
