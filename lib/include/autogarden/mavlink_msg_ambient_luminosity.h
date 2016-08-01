// MESSAGE AMBIENT_LUMINOSITY PACKING

#define MAVLINK_MSG_ID_AMBIENT_LUMINOSITY 5

typedef struct __mavlink_ambient_luminosity_t
{
 float ambient_lux; ///< Ambient Light Intensity
} mavlink_ambient_luminosity_t;

#define MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN 4
#define MAVLINK_MSG_ID_5_LEN 4



#define MAVLINK_MESSAGE_INFO_AMBIENT_LUMINOSITY { \
	"AMBIENT_LUMINOSITY", \
	1, \
	{  { "ambient_lux", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ambient_luminosity_t, ambient_lux) }, \
         } \
}


/**
 * @brief Pack a ambient_luminosity message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ambient_lux Ambient Light Intensity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ambient_luminosity_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float ambient_lux)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, ambient_lux);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_ambient_luminosity_t packet;
	packet.ambient_lux = ambient_lux;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_AMBIENT_LUMINOSITY;
	return mavlink_finalize_message(msg, system_id, component_id, 4, 186);
}

/**
 * @brief Pack a ambient_luminosity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param ambient_lux Ambient Light Intensity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ambient_luminosity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float ambient_lux)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, ambient_lux);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_ambient_luminosity_t packet;
	packet.ambient_lux = ambient_lux;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_AMBIENT_LUMINOSITY;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 4, 186);
}

/**
 * @brief Encode a ambient_luminosity struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ambient_luminosity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ambient_luminosity_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ambient_luminosity_t* ambient_luminosity)
{
	return mavlink_msg_ambient_luminosity_pack(system_id, component_id, msg, ambient_luminosity->ambient_lux);
}

/**
 * @brief Send a ambient_luminosity message
 * @param chan MAVLink channel to send the message
 *
 * @param ambient_lux Ambient Light Intensity
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ambient_luminosity_send(mavlink_channel_t chan, float ambient_lux)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, ambient_lux);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY, buf, 4, 186);
#else
	mavlink_ambient_luminosity_t packet;
	packet.ambient_lux = ambient_lux;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY, (const char *)&packet, 4, 186);
#endif
}

#endif

// MESSAGE AMBIENT_LUMINOSITY UNPACKING


/**
 * @brief Get field ambient_lux from ambient_luminosity message
 *
 * @return Ambient Light Intensity
 */
static inline float mavlink_msg_ambient_luminosity_get_ambient_lux(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a ambient_luminosity message into a struct
 *
 * @param msg The message to decode
 * @param ambient_luminosity C-struct to decode the message contents into
 */
static inline void mavlink_msg_ambient_luminosity_decode(const mavlink_message_t* msg, mavlink_ambient_luminosity_t* ambient_luminosity)
{
#if MAVLINK_NEED_BYTE_SWAP
	ambient_luminosity->ambient_lux = mavlink_msg_ambient_luminosity_get_ambient_lux(msg);
#else
	memcpy(ambient_luminosity, _MAV_PAYLOAD(msg), 4);
#endif
}
