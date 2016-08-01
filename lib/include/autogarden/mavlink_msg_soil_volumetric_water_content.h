// MESSAGE SOIL_VOLUMETRIC_WATER_CONTENT PACKING

#define MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT 1

typedef struct __mavlink_soil_volumetric_water_content_t
{
 float vwc; ///< Volumetric Water Content
} mavlink_soil_volumetric_water_content_t;

#define MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT_LEN 4
#define MAVLINK_MSG_ID_1_LEN 4



#define MAVLINK_MESSAGE_INFO_SOIL_VOLUMETRIC_WATER_CONTENT { \
	"SOIL_VOLUMETRIC_WATER_CONTENT", \
	1, \
	{  { "vwc", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_soil_volumetric_water_content_t, vwc) }, \
         } \
}


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
	char buf[4];
	_mav_put_float(buf, 0, vwc);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_soil_volumetric_water_content_t packet;
	packet.vwc = vwc;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT;
	return mavlink_finalize_message(msg, system_id, component_id, 4, 149);
}

/**
 * @brief Pack a soil_volumetric_water_content message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param vwc Volumetric Water Content
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_soil_volumetric_water_content_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float vwc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, vwc);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_soil_volumetric_water_content_t packet;
	packet.vwc = vwc;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 4, 149);
}

/**
 * @brief Encode a soil_volumetric_water_content struct into a message
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
 * @brief Send a soil_volumetric_water_content message
 * @param chan MAVLink channel to send the message
 *
 * @param vwc Volumetric Water Content
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_soil_volumetric_water_content_send(mavlink_channel_t chan, float vwc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_float(buf, 0, vwc);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT, buf, 4, 149);
#else
	mavlink_soil_volumetric_water_content_t packet;
	packet.vwc = vwc;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOIL_VOLUMETRIC_WATER_CONTENT, (const char *)&packet, 4, 149);
#endif
}

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
#if MAVLINK_NEED_BYTE_SWAP
	soil_volumetric_water_content->vwc = mavlink_msg_soil_volumetric_water_content_get_vwc(msg);
#else
	memcpy(soil_volumetric_water_content, _MAV_PAYLOAD(msg), 4);
#endif
}
