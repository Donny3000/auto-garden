// MESSAGE SOIL_VOLUMETRIC_WATER_CONTENT PACKING

#define MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT 1

MAVPACKED(
typedef struct __mavlink_soil_volumetric_water_content_t {
 float vwc; /*< Volumetric Water Content*/
}) mavlink_soil_volumetric_water_content_t;

#define MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN 4
#define MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_MIN_LEN 4
#define MAVLINK_MSG_ID_1_LEN 4
#define MAVLINK_MSG_ID_1_MIN_LEN 4

#define MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_CRC 149
#define MAVLINK_MSG_ID_1_CRC 149



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOIL_VOLUMETRIC_WATER_CONTENT { \
	1, \
	"SOIL_VOLUMETRIC_WATER_CONTENT", \
	1, \
	{  { "vwc", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_soil_volumetric_water_content_t, vwc) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOIL_VOLUMETRIC_WATER_CONTENT { \
	"SOIL_VOLUMETRIC_WATER_CONTENT", \
	1, \
	{  { "vwc", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_soil_volumetric_water_content_t, vwc) }, \
         } \
}
#endif

/**
 * @brief Pack a soil_volumetric_water_content message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vwc Volumetric Water Content
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_soil_volumetric_water_content_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float vwc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN];
	_mav_put_float(buf, 0, vwc);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN);
#else
	mavlink_soil_volumetric_water_content_t packet;
	packet.vwc = vwc;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_MIN_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_CRC);
}

/**
 * @brief Pack a soil_volumetric_water_content message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vwc Volumetric Water Content
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_soil_volumetric_water_content_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float vwc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN];
	_mav_put_float(buf, 0, vwc);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN);
#else
	mavlink_soil_volumetric_water_content_t packet;
	packet.vwc = vwc;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_MIN_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_CRC);
}

/**
 * @brief Encode a soil_volumetric_water_content struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param soil_volumetric_water_content C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_soil_volumetric_water_content_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_soil_volumetric_water_content_t* soil_volumetric_water_content)
{
	return mavlink_msg_soil_volumetric_water_content_pack(system_id, component_id, msg, soil_volumetric_water_content->vwc);
}

/**
 * @brief Encode a soil_volumetric_water_content struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param soil_volumetric_water_content C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_soil_volumetric_water_content_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_soil_volumetric_water_content_t* soil_volumetric_water_content)
{
	return mavlink_msg_soil_volumetric_water_content_pack_chan(system_id, component_id, chan, msg, soil_volumetric_water_content->vwc);
}

/**
 * @brief Send a soil_volumetric_water_content message
 * @param chan MAVLink channel to send the message
 *
 * @param vwc Volumetric Water Content
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_soil_volumetric_water_content_send(mavlink_channel_t chan, float vwc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN];
	_mav_put_float(buf, 0, vwc);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT, buf, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_MIN_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_CRC);
#else
	mavlink_soil_volumetric_water_content_t packet;
	packet.vwc = vwc;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT, (const char *)&packet, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_MIN_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_CRC);
#endif
}

/**
 * @brief Send a soil_volumetric_water_content message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_soil_volumetric_water_content_send_struct(mavlink_channel_t chan, const mavlink_soil_volumetric_water_content_t* soil_volumetric_water_content)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_soil_volumetric_water_content_send(chan, soil_volumetric_water_content->vwc);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT, (const char *)soil_volumetric_water_content, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_MIN_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_soil_volumetric_water_content_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float vwc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, vwc);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT, buf, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_MIN_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_CRC);
#else
	mavlink_soil_volumetric_water_content_t *packet = (mavlink_soil_volumetric_water_content_t *)msgbuf;
	packet->vwc = vwc;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT, (const char *)packet, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_MIN_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_CRC);
#endif
}
#endif

#endif

// MESSAGE SOIL_VOLUMETRIC_WATER_CONTENT UNPACKING


/**
 * @brief Get field vwc from soil_volumetric_water_content message
 *
 * @return Volumetric Water Content
 */
static inline float mavlink_msg_soil_volumetric_water_content_get_vwc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a soil_volumetric_water_content message into a struct
 *
 * @param msg The message to decode
 * @param soil_volumetric_water_content C-struct to decode the message contents into
 */
static inline void mavlink_msg_soil_volumetric_water_content_decode(const mavlink_message_t* msg, mavlink_soil_volumetric_water_content_t* soil_volumetric_water_content)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	soil_volumetric_water_content->vwc = mavlink_msg_soil_volumetric_water_content_get_vwc(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN? msg->len : MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN;
        memset(soil_volumetric_water_content, 0, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN);
	memcpy(soil_volumetric_water_content, _MAV_PAYLOAD(msg), len);
#endif
}
