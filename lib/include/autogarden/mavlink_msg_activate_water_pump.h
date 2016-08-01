// MESSAGE ACTIVATE_WATER_PUMP PACKING

#define MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP 20

typedef struct __mavlink_activate_water_pump_t
{
 uint8_t activate; ///< Activate the water pump (True/False)
 uint8_t duration; ///< Duration to activate the water pump
} mavlink_activate_water_pump_t;

#define MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN 2
#define MAVLINK_MSG_ID_20_LEN 2



#define MAVLINK_MESSAGE_INFO_ACTIVATE_WATER_PUMP { \
	"ACTIVATE_WATER_PUMP", \
	2, \
	{  { "activate", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_activate_water_pump_t, activate) }, \
         { "duration", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_activate_water_pump_t, duration) }, \
         } \
}


/**
 * @brief Pack a activate_water_pump message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param activate Activate the water pump (True/False)
 * @param duration Duration to activate the water pump
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_activate_water_pump_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t activate, uint8_t duration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, activate);
	_mav_put_uint8_t(buf, 1, duration);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_activate_water_pump_t packet;
	packet.activate = activate;
	packet.duration = duration;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP;
	return mavlink_finalize_message(msg, system_id, component_id, 2, 151);
}

/**
 * @brief Pack a activate_water_pump message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param activate Activate the water pump (True/False)
 * @param duration Duration to activate the water pump
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_activate_water_pump_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t activate,uint8_t duration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, activate);
	_mav_put_uint8_t(buf, 1, duration);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_activate_water_pump_t packet;
	packet.activate = activate;
	packet.duration = duration;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 2, 151);
}

/**
 * @brief Encode a activate_water_pump struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param activate_water_pump C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_activate_water_pump_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_activate_water_pump_t* activate_water_pump)
{
	return mavlink_msg_activate_water_pump_pack(system_id, component_id, msg, activate_water_pump->activate, activate_water_pump->duration);
}

/**
 * @brief Send a activate_water_pump message
 * @param chan MAVLink channel to send the message
 *
 * @param activate Activate the water pump (True/False)
 * @param duration Duration to activate the water pump
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_activate_water_pump_send(mavlink_channel_t chan, uint8_t activate, uint8_t duration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, activate);
	_mav_put_uint8_t(buf, 1, duration);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP, buf, 2, 151);
#else
	mavlink_activate_water_pump_t packet;
	packet.activate = activate;
	packet.duration = duration;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP, (const char *)&packet, 2, 151);
#endif
}

#endif

// MESSAGE ACTIVATE_WATER_PUMP UNPACKING


/**
 * @brief Get field activate from activate_water_pump message
 *
 * @return Activate the water pump (True/False)
 */
static inline uint8_t mavlink_msg_activate_water_pump_get_activate(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field duration from activate_water_pump message
 *
 * @return Duration to activate the water pump
 */
static inline uint8_t mavlink_msg_activate_water_pump_get_duration(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a activate_water_pump message into a struct
 *
 * @param msg The message to decode
 * @param activate_water_pump C-struct to decode the message contents into
 */
static inline void mavlink_msg_activate_water_pump_decode(const mavlink_message_t* msg, mavlink_activate_water_pump_t* activate_water_pump)
{
#if MAVLINK_NEED_BYTE_SWAP
	activate_water_pump->activate = mavlink_msg_activate_water_pump_get_activate(msg);
	activate_water_pump->duration = mavlink_msg_activate_water_pump_get_duration(msg);
#else
	memcpy(activate_water_pump, _MAV_PAYLOAD(msg), 2);
#endif
}
