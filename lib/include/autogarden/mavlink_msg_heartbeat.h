// MESSAGE HEARTBEAT PACKING

#define MAVLINK_MSG_ID_HEARTBEAT 0

MAVPACKED(
typedef struct __mavlink_heartbeat_t {
 float soil_temperature; /*< The temperature reading in degrees C from soil temperature sensor.*/
 float soil_vwc; /*< The volumetric water content of the soil.*/
 float ambient_temp; /*< The ambient air temperature in degrees F.*/
 float ambient_humidity; /*< The ambient humidity of the garden.*/
 float luminosity; /*< The amount of lux in the garden.*/
}) mavlink_heartbeat_t;

#define MAVLINK_MSG_ID_HEARTBEAT_LEN 20
#define MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN 20
#define MAVLINK_MSG_ID_0_LEN 20
#define MAVLINK_MSG_ID_0_MIN_LEN 20

#define MAVLINK_MSG_ID_HEARTBEAT_CRC 102
#define MAVLINK_MSG_ID_0_CRC 102



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HEARTBEAT { \
	0, \
	"HEARTBEAT", \
	5, \
	{  { "soil_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_heartbeat_t, soil_temperature) }, \
         { "soil_vwc", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_heartbeat_t, soil_vwc) }, \
         { "ambient_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_heartbeat_t, ambient_temp) }, \
         { "ambient_humidity", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_heartbeat_t, ambient_humidity) }, \
         { "luminosity", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_heartbeat_t, luminosity) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HEARTBEAT { \
	"HEARTBEAT", \
	5, \
	{  { "soil_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_heartbeat_t, soil_temperature) }, \
         { "soil_vwc", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_heartbeat_t, soil_vwc) }, \
         { "ambient_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_heartbeat_t, ambient_temp) }, \
         { "ambient_humidity", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_heartbeat_t, ambient_humidity) }, \
         { "luminosity", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_heartbeat_t, luminosity) }, \
         } \
}
#endif

/**
 * @brief Pack a heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param soil_temperature The temperature reading in degrees C from soil temperature sensor.
 * @param soil_vwc The volumetric water content of the soil.
 * @param ambient_temp The ambient air temperature in degrees F.
 * @param ambient_humidity The ambient humidity of the garden.
 * @param luminosity The amount of lux in the garden.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float soil_temperature, float soil_vwc, float ambient_temp, float ambient_humidity, float luminosity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
	_mav_put_float(buf, 0, soil_temperature);
	_mav_put_float(buf, 4, soil_vwc);
	_mav_put_float(buf, 8, ambient_temp);
	_mav_put_float(buf, 12, ambient_humidity);
	_mav_put_float(buf, 16, luminosity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
	mavlink_heartbeat_t packet;
	packet.soil_temperature = soil_temperature;
	packet.soil_vwc = soil_vwc;
	packet.ambient_temp = ambient_temp;
	packet.ambient_humidity = ambient_humidity;
	packet.luminosity = luminosity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
}

/**
 * @brief Pack a heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param soil_temperature The temperature reading in degrees C from soil temperature sensor.
 * @param soil_vwc The volumetric water content of the soil.
 * @param ambient_temp The ambient air temperature in degrees F.
 * @param ambient_humidity The ambient humidity of the garden.
 * @param luminosity The amount of lux in the garden.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float soil_temperature,float soil_vwc,float ambient_temp,float ambient_humidity,float luminosity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
	_mav_put_float(buf, 0, soil_temperature);
	_mav_put_float(buf, 4, soil_vwc);
	_mav_put_float(buf, 8, ambient_temp);
	_mav_put_float(buf, 12, ambient_humidity);
	_mav_put_float(buf, 16, luminosity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
	mavlink_heartbeat_t packet;
	packet.soil_temperature = soil_temperature;
	packet.soil_vwc = soil_vwc;
	packet.ambient_temp = ambient_temp;
	packet.ambient_humidity = ambient_humidity;
	packet.luminosity = luminosity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
}

/**
 * @brief Encode a heartbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_heartbeat_t* heartbeat)
{
	return mavlink_msg_heartbeat_pack(system_id, component_id, msg, heartbeat->soil_temperature, heartbeat->soil_vwc, heartbeat->ambient_temp, heartbeat->ambient_humidity, heartbeat->luminosity);
}

/**
 * @brief Encode a heartbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_heartbeat_t* heartbeat)
{
	return mavlink_msg_heartbeat_pack_chan(system_id, component_id, chan, msg, heartbeat->soil_temperature, heartbeat->soil_vwc, heartbeat->ambient_temp, heartbeat->ambient_humidity, heartbeat->luminosity);
}

/**
 * @brief Send a heartbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param soil_temperature The temperature reading in degrees C from soil temperature sensor.
 * @param soil_vwc The volumetric water content of the soil.
 * @param ambient_temp The ambient air temperature in degrees F.
 * @param ambient_humidity The ambient humidity of the garden.
 * @param luminosity The amount of lux in the garden.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_heartbeat_send(mavlink_channel_t chan, float soil_temperature, float soil_vwc, float ambient_temp, float ambient_humidity, float luminosity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
	_mav_put_float(buf, 0, soil_temperature);
	_mav_put_float(buf, 4, soil_vwc);
	_mav_put_float(buf, 8, ambient_temp);
	_mav_put_float(buf, 12, ambient_humidity);
	_mav_put_float(buf, 16, luminosity);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
	mavlink_heartbeat_t packet;
	packet.soil_temperature = soil_temperature;
	packet.soil_vwc = soil_vwc;
	packet.ambient_temp = ambient_temp;
	packet.ambient_humidity = ambient_humidity;
	packet.luminosity = luminosity;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#endif
}

/**
 * @brief Send a heartbeat message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_heartbeat_send_struct(mavlink_channel_t chan, const mavlink_heartbeat_t* heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_heartbeat_send(chan, heartbeat->soil_temperature, heartbeat->soil_vwc, heartbeat->ambient_temp, heartbeat->ambient_humidity, heartbeat->luminosity);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)heartbeat, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_HEARTBEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_heartbeat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float soil_temperature, float soil_vwc, float ambient_temp, float ambient_humidity, float luminosity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, soil_temperature);
	_mav_put_float(buf, 4, soil_vwc);
	_mav_put_float(buf, 8, ambient_temp);
	_mav_put_float(buf, 12, ambient_humidity);
	_mav_put_float(buf, 16, luminosity);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
	mavlink_heartbeat_t *packet = (mavlink_heartbeat_t *)msgbuf;
	packet->soil_temperature = soil_temperature;
	packet->soil_vwc = soil_vwc;
	packet->ambient_temp = ambient_temp;
	packet->ambient_humidity = ambient_humidity;
	packet->luminosity = luminosity;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#endif
}
#endif

#endif

// MESSAGE HEARTBEAT UNPACKING


/**
 * @brief Get field soil_temperature from heartbeat message
 *
 * @return The temperature reading in degrees C from soil temperature sensor.
 */
static inline float mavlink_msg_heartbeat_get_soil_temperature(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field soil_vwc from heartbeat message
 *
 * @return The volumetric water content of the soil.
 */
static inline float mavlink_msg_heartbeat_get_soil_vwc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field ambient_temp from heartbeat message
 *
 * @return The ambient air temperature in degrees F.
 */
static inline float mavlink_msg_heartbeat_get_ambient_temp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field ambient_humidity from heartbeat message
 *
 * @return The ambient humidity of the garden.
 */
static inline float mavlink_msg_heartbeat_get_ambient_humidity(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field luminosity from heartbeat message
 *
 * @return The amount of lux in the garden.
 */
static inline float mavlink_msg_heartbeat_get_luminosity(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param heartbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_heartbeat_decode(const mavlink_message_t* msg, mavlink_heartbeat_t* heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	heartbeat->soil_temperature = mavlink_msg_heartbeat_get_soil_temperature(msg);
	heartbeat->soil_vwc = mavlink_msg_heartbeat_get_soil_vwc(msg);
	heartbeat->ambient_temp = mavlink_msg_heartbeat_get_ambient_temp(msg);
	heartbeat->ambient_humidity = mavlink_msg_heartbeat_get_ambient_humidity(msg);
	heartbeat->luminosity = mavlink_msg_heartbeat_get_luminosity(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HEARTBEAT_LEN? msg->len : MAVLINK_MSG_ID_HEARTBEAT_LEN;
        memset(heartbeat, 0, MAVLINK_MSG_ID_HEARTBEAT_LEN);
	memcpy(heartbeat, _MAV_PAYLOAD(msg), len);
#endif
}
