// MESSAGE ACTIVATE_WATER_PUMP PACKING

#define MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP 20

MAVPACKED(
typedef struct __mavlink_activate_water_pump_t {
 uint8_t activate; /*< Activate the water pump (True/False)*/
 uint8_t duration; /*< Duration to activate the water pump*/
}) mavlink_activate_water_pump_t;

#define MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN 2
#define MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_MIN_LEN 2
#define MAVLINK_MSG_ID_20_LEN 2
#define MAVLINK_MSG_ID_20_MIN_LEN 2

#define MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_CRC 151
#define MAVLINK_MSG_ID_20_CRC 151



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ACTIVATE_WATER_PUMP { \
	20, \
	"ACTIVATE_WATER_PUMP", \
	2, \
	{  { "activate", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_activate_water_pump_t, activate) }, \
         { "duration", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_activate_water_pump_t, duration) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ACTIVATE_WATER_PUMP { \
	"ACTIVATE_WATER_PUMP", \
	2, \
	{  { "activate", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_activate_water_pump_t, activate) }, \
         { "duration", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_activate_water_pump_t, duration) }, \
         } \
}
#endif

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
	char buf[MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN];
	_mav_put_uint8_t(buf, 0, activate);
	_mav_put_uint8_t(buf, 1, duration);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN);
#else
	mavlink_activate_water_pump_t packet;
	packet.activate = activate;
	packet.duration = duration;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_MIN_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_CRC);
}

/**
 * @brief Pack a activate_water_pump message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
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
	char buf[MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN];
	_mav_put_uint8_t(buf, 0, activate);
	_mav_put_uint8_t(buf, 1, duration);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN);
#else
	mavlink_activate_water_pump_t packet;
	packet.activate = activate;
	packet.duration = duration;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_MIN_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_CRC);
}

/**
 * @brief Encode a activate_water_pump struct
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
 * @brief Encode a activate_water_pump struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param activate_water_pump C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_activate_water_pump_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_activate_water_pump_t* activate_water_pump)
{
	return mavlink_msg_activate_water_pump_pack_chan(system_id, component_id, chan, msg, activate_water_pump->activate, activate_water_pump->duration);
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
	char buf[MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN];
	_mav_put_uint8_t(buf, 0, activate);
	_mav_put_uint8_t(buf, 1, duration);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP, buf, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_MIN_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_CRC);
#else
	mavlink_activate_water_pump_t packet;
	packet.activate = activate;
	packet.duration = duration;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP, (const char *)&packet, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_MIN_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_CRC);
#endif
}

/**
 * @brief Send a activate_water_pump message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_activate_water_pump_send_struct(mavlink_channel_t chan, const mavlink_activate_water_pump_t* activate_water_pump)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_activate_water_pump_send(chan, activate_water_pump->activate, activate_water_pump->duration);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP, (const char *)activate_water_pump, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_MIN_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_CRC);
#endif
}

#if MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_activate_water_pump_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t activate, uint8_t duration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, activate);
	_mav_put_uint8_t(buf, 1, duration);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP, buf, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_MIN_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_CRC);
#else
	mavlink_activate_water_pump_t *packet = (mavlink_activate_water_pump_t *)msgbuf;
	packet->activate = activate;
	packet->duration = duration;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP, (const char *)packet, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_MIN_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_CRC);
#endif
}
#endif

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
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	activate_water_pump->activate = mavlink_msg_activate_water_pump_get_activate(msg);
	activate_water_pump->duration = mavlink_msg_activate_water_pump_get_duration(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN? msg->len : MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN;
        memset(activate_water_pump, 0, MAVLINK_MSG_ID_ACTIVATE_WATER_PUMP_LEN);
	memcpy(activate_water_pump, _MAV_PAYLOAD(msg), len);
#endif
}
