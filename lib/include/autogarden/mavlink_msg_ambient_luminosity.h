// MESSAGE AMBIENT_LUMINOSITY PACKING

#define MAVLINK_MSG_ID_AMBIENT_LUMINOSITY 5

MAVPACKED(
typedef struct __mavlink_ambient_luminosity_t {
 float ambient_lux; /*< Ambient Light Intensity*/
}) mavlink_ambient_luminosity_t;

#define MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN 4
#define MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_MIN_LEN 4
#define MAVLINK_MSG_ID_5_LEN 4
#define MAVLINK_MSG_ID_5_MIN_LEN 4

#define MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_CRC 186
#define MAVLINK_MSG_ID_5_CRC 186



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AMBIENT_LUMINOSITY { \
	5, \
	"AMBIENT_LUMINOSITY", \
	1, \
	{  { "ambient_lux", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ambient_luminosity_t, ambient_lux) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AMBIENT_LUMINOSITY { \
	"AMBIENT_LUMINOSITY", \
	1, \
	{  { "ambient_lux", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_ambient_luminosity_t, ambient_lux) }, \
         } \
}
#endif

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
	char buf[MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN];
	_mav_put_float(buf, 0, ambient_lux);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN);
#else
	mavlink_ambient_luminosity_t packet;
	packet.ambient_lux = ambient_lux;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AMBIENT_LUMINOSITY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_MIN_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_CRC);
}

/**
 * @brief Pack a ambient_luminosity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ambient_lux Ambient Light Intensity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ambient_luminosity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float ambient_lux)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN];
	_mav_put_float(buf, 0, ambient_lux);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN);
#else
	mavlink_ambient_luminosity_t packet;
	packet.ambient_lux = ambient_lux;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AMBIENT_LUMINOSITY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_MIN_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_CRC);
}

/**
 * @brief Encode a ambient_luminosity struct
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
 * @brief Encode a ambient_luminosity struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ambient_luminosity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ambient_luminosity_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ambient_luminosity_t* ambient_luminosity)
{
	return mavlink_msg_ambient_luminosity_pack_chan(system_id, component_id, chan, msg, ambient_luminosity->ambient_lux);
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
	char buf[MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN];
	_mav_put_float(buf, 0, ambient_lux);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY, buf, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_MIN_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_CRC);
#else
	mavlink_ambient_luminosity_t packet;
	packet.ambient_lux = ambient_lux;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY, (const char *)&packet, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_MIN_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_CRC);
#endif
}

/**
 * @brief Send a ambient_luminosity message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ambient_luminosity_send_struct(mavlink_channel_t chan, const mavlink_ambient_luminosity_t* ambient_luminosity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ambient_luminosity_send(chan, ambient_luminosity->ambient_lux);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY, (const char *)ambient_luminosity, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_MIN_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_CRC);
#endif
}

#if MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ambient_luminosity_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float ambient_lux)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, ambient_lux);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY, buf, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_MIN_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_CRC);
#else
	mavlink_ambient_luminosity_t *packet = (mavlink_ambient_luminosity_t *)msgbuf;
	packet->ambient_lux = ambient_lux;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY, (const char *)packet, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_MIN_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_CRC);
#endif
}
#endif

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
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	ambient_luminosity->ambient_lux = mavlink_msg_ambient_luminosity_get_ambient_lux(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN? msg->len : MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN;
        memset(ambient_luminosity, 0, MAVLINK_MSG_ID_AMBIENT_LUMINOSITY_LEN);
	memcpy(ambient_luminosity, _MAV_PAYLOAD(msg), len);
#endif
}
