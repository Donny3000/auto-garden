// MESSAGE SOIL_TEMPERATURE PACKING

#define MAVLINK_MSG_ID_SOIL_TEMPERATURE 2

MAVPACKED(
typedef struct __mavlink_soil_temperature_t {
 float soil_temp; /*< Soil Temperature (degrees C)*/
}) mavlink_soil_temperature_t;

#define MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN 4
#define MAVLINK_MSG_ID_SOIL_TEMPERATURE_MIN_LEN 4
#define MAVLINK_MSG_ID_2_LEN 4
#define MAVLINK_MSG_ID_2_MIN_LEN 4

#define MAVLINK_MSG_ID_SOIL_TEMPERATURE_CRC 220
#define MAVLINK_MSG_ID_2_CRC 220



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOIL_TEMPERATURE { \
	2, \
	"SOIL_TEMPERATURE", \
	1, \
	{  { "soil_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_soil_temperature_t, soil_temp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOIL_TEMPERATURE { \
	"SOIL_TEMPERATURE", \
	1, \
	{  { "soil_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_soil_temperature_t, soil_temp) }, \
         } \
}
#endif

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
	char buf[MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN];
	_mav_put_float(buf, 0, soil_temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN);
#else
	mavlink_soil_temperature_t packet;
	packet.soil_temp = soil_temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SOIL_TEMPERATURE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOIL_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_CRC);
}

/**
 * @brief Pack a soil_temperature message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param soil_temp Soil Temperature (degrees C)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_soil_temperature_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float soil_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN];
	_mav_put_float(buf, 0, soil_temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN);
#else
	mavlink_soil_temperature_t packet;
	packet.soil_temp = soil_temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SOIL_TEMPERATURE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOIL_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_CRC);
}

/**
 * @brief Encode a soil_temperature struct
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
 * @brief Encode a soil_temperature struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param soil_temperature C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_soil_temperature_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_soil_temperature_t* soil_temperature)
{
	return mavlink_msg_soil_temperature_pack_chan(system_id, component_id, chan, msg, soil_temperature->soil_temp);
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
	char buf[MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN];
	_mav_put_float(buf, 0, soil_temp);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_TEMPERATURE, buf, MAVLINK_MSG_ID_SOIL_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_CRC);
#else
	mavlink_soil_temperature_t packet;
	packet.soil_temp = soil_temp;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_TEMPERATURE, (const char *)&packet, MAVLINK_MSG_ID_SOIL_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_CRC);
#endif
}

/**
 * @brief Send a soil_temperature message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_soil_temperature_send_struct(mavlink_channel_t chan, const mavlink_soil_temperature_t* soil_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_soil_temperature_send(chan, soil_temperature->soil_temp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_TEMPERATURE, (const char *)soil_temperature, MAVLINK_MSG_ID_SOIL_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_soil_temperature_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float soil_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, soil_temp);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_TEMPERATURE, buf, MAVLINK_MSG_ID_SOIL_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_CRC);
#else
	mavlink_soil_temperature_t *packet = (mavlink_soil_temperature_t *)msgbuf;
	packet->soil_temp = soil_temp;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_TEMPERATURE, (const char *)packet, MAVLINK_MSG_ID_SOIL_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOIL_TEMPERATURE_CRC);
#endif
}
#endif

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
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	soil_temperature->soil_temp = mavlink_msg_soil_temperature_get_soil_temp(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN? msg->len : MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN;
        memset(soil_temperature, 0, MAVLINK_MSG_ID_SOIL_TEMPERATURE_LEN);
	memcpy(soil_temperature, _MAV_PAYLOAD(msg), len);
#endif
}
