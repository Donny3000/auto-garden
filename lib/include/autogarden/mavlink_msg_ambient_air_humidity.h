// MESSAGE AMBIENT_AIR_HUMIDITY PACKING

#define MAVLINK_MSG_ID_AMBIENT_AIR_HUMIDITY 4

typedef struct __mavlink_ambient_air_humidity_t
{
 float ambient_humidity; ///< Ambient Air Humidity
} mavlink_ambient_air_humidity_t;

#define MAVLINK_MSG_ID_AMBIENT_AIR_HUMIDITY_LEN 4
#define MAVLINK_MSG_ID_4_LEN 4



#define MAVLINK_MESSAGE_INFO_AMBIENT_AIR_HUMIDITY { \
	"AMBIENT_AIR_HUMIDITY", \
	1, \
	{  { "ambient_humidity", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ambient_air_humidity_t, ambient_humidity) }, \
         } \
}


/**
 * @brief Pack a ambient_air_humidity message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ambient_humidity Ambient Air Humidity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ambient_air_humidity_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float ambient_humidity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, ambient_humidity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_ambient_air_humidity_t packet;
	packet.ambient_humidity = ambient_humidity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_AMBIENT_AIR_HUMIDITY;
	return mavlink_finalize_message(msg, system_id, component_id, 4, 211);
}

/**
 * @brief Pack a ambient_air_humidity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param ambient_humidity Ambient Air Humidity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ambient_air_humidity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float ambient_humidity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, ambient_humidity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_ambient_air_humidity_t packet;
	packet.ambient_humidity = ambient_humidity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_AMBIENT_AIR_HUMIDITY;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 4, 211);
}

/**
 * @brief Encode a ambient_air_humidity struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ambient_air_humidity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ambient_air_humidity_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ambient_air_humidity_t* ambient_air_humidity)
{
	return mavlink_msg_ambient_air_humidity_pack(system_id, component_id, msg, ambient_air_humidity->ambient_humidity);
}

/**
 * @brief Send a ambient_air_humidity message
 * @param chan MAVLink channel to send the message
 *
 * @param ambient_humidity Ambient Air Humidity
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ambient_air_humidity_send(mavlink_channel_t chan, float ambient_humidity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, ambient_humidity);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_AIR_HUMIDITY, buf, 4, 211);
#else
	mavlink_ambient_air_humidity_t packet;
	packet.ambient_humidity = ambient_humidity;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_AIR_HUMIDITY, (const char *)&packet, 4, 211);
#endif
}

#endif

// MESSAGE AMBIENT_AIR_HUMIDITY UNPACKING


/**
 * @brief Get field ambient_humidity from ambient_air_humidity message
 *
 * @return Ambient Air Humidity
 */
static inline float mavlink_msg_ambient_air_humidity_get_ambient_humidity(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a ambient_air_humidity message into a struct
 *
 * @param msg The message to decode
 * @param ambient_air_humidity C-struct to decode the message contents into
 */
static inline void mavlink_msg_ambient_air_humidity_decode(const mavlink_message_t* msg, mavlink_ambient_air_humidity_t* ambient_air_humidity)
{
#if MAVLINK_NEED_BYTE_SWAP
	ambient_air_humidity->ambient_humidity = mavlink_msg_ambient_air_humidity_get_ambient_humidity(msg);
#else
	memcpy(ambient_air_humidity, _MAV_PAYLOAD(msg), 4);
#endif
}
