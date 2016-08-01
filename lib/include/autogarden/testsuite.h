/** @file
 *	@brief MAVLink comm protocol testsuite generated from autogarden.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef AUTOGARDEN_TESTSUITE_H
#define AUTOGARDEN_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_autogarden(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_autogarden(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_heartbeat_t packet_in = {
		17.0,
	45.0,
	73.0,
	101.0,
	129.0,
	};
	mavlink_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.soil_temperature = packet_in.soil_temperature;
        	packet1.soil_vwc = packet_in.soil_vwc;
        	packet1.ambient_temp = packet_in.ambient_temp;
        	packet1.ambient_humidity = packet_in.ambient_humidity;
        	packet1.luminosity = packet_in.luminosity;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_pack(system_id, component_id, &msg , packet1.soil_temperature , packet1.soil_vwc , packet1.ambient_temp , packet1.ambient_humidity , packet1.luminosity );
	mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.soil_temperature , packet1.soil_vwc , packet1.ambient_temp , packet1.ambient_humidity , packet1.luminosity );
	mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_heartbeat_send(MAVLINK_COMM_1 , packet1.soil_temperature , packet1.soil_vwc , packet1.ambient_temp , packet1.ambient_humidity , packet1.luminosity );
	mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_soil_volumetric_water_content(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_soil_volumetric_water_content_t packet_in = {
		17.0,
	};
	mavlink_soil_volumetric_water_content_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.vwc = packet_in.vwc;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_soil_volumetric_water_content_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_soil_volumetric_water_content_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_soil_volumetric_water_content_pack(system_id, component_id, &msg , packet1.vwc );
	mavlink_msg_soil_volumetric_water_content_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_soil_volumetric_water_content_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vwc );
	mavlink_msg_soil_volumetric_water_content_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_soil_volumetric_water_content_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_soil_volumetric_water_content_send(MAVLINK_COMM_1 , packet1.vwc );
	mavlink_msg_soil_volumetric_water_content_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_soil_temperature(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_soil_temperature_t packet_in = {
		17.0,
	};
	mavlink_soil_temperature_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.soil_temp = packet_in.soil_temp;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_soil_temperature_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_soil_temperature_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_soil_temperature_pack(system_id, component_id, &msg , packet1.soil_temp );
	mavlink_msg_soil_temperature_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_soil_temperature_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.soil_temp );
	mavlink_msg_soil_temperature_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_soil_temperature_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_soil_temperature_send(MAVLINK_COMM_1 , packet1.soil_temp );
	mavlink_msg_soil_temperature_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ambient_air_temperature(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ambient_air_temperature_t packet_in = {
		17.0,
	};
	mavlink_ambient_air_temperature_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.ambient_temp = packet_in.ambient_temp;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_air_temperature_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ambient_air_temperature_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_air_temperature_pack(system_id, component_id, &msg , packet1.ambient_temp );
	mavlink_msg_ambient_air_temperature_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_air_temperature_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ambient_temp );
	mavlink_msg_ambient_air_temperature_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ambient_air_temperature_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_air_temperature_send(MAVLINK_COMM_1 , packet1.ambient_temp );
	mavlink_msg_ambient_air_temperature_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ambient_air_humidity(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ambient_air_humidity_t packet_in = {
		17.0,
	};
	mavlink_ambient_air_humidity_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.ambient_humidity = packet_in.ambient_humidity;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_air_humidity_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ambient_air_humidity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_air_humidity_pack(system_id, component_id, &msg , packet1.ambient_humidity );
	mavlink_msg_ambient_air_humidity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_air_humidity_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ambient_humidity );
	mavlink_msg_ambient_air_humidity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ambient_air_humidity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_air_humidity_send(MAVLINK_COMM_1 , packet1.ambient_humidity );
	mavlink_msg_ambient_air_humidity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ambient_luminosity(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ambient_luminosity_t packet_in = {
		17.0,
	};
	mavlink_ambient_luminosity_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.ambient_lux = packet_in.ambient_lux;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_luminosity_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ambient_luminosity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_luminosity_pack(system_id, component_id, &msg , packet1.ambient_lux );
	mavlink_msg_ambient_luminosity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_luminosity_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ambient_lux );
	mavlink_msg_ambient_luminosity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ambient_luminosity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ambient_luminosity_send(MAVLINK_COMM_1 , packet1.ambient_lux );
	mavlink_msg_ambient_luminosity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_activate_water_pump(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_activate_water_pump_t packet_in = {
		5,
	72,
	};
	mavlink_activate_water_pump_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.activate = packet_in.activate;
        	packet1.duration = packet_in.duration;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_activate_water_pump_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_activate_water_pump_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_activate_water_pump_pack(system_id, component_id, &msg , packet1.activate , packet1.duration );
	mavlink_msg_activate_water_pump_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_activate_water_pump_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.activate , packet1.duration );
	mavlink_msg_activate_water_pump_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_activate_water_pump_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_activate_water_pump_send(MAVLINK_COMM_1 , packet1.activate , packet1.duration );
	mavlink_msg_activate_water_pump_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_autogarden(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_heartbeat(system_id, component_id, last_msg);
	mavlink_test_soil_volumetric_water_content(system_id, component_id, last_msg);
	mavlink_test_soil_temperature(system_id, component_id, last_msg);
	mavlink_test_ambient_air_temperature(system_id, component_id, last_msg);
	mavlink_test_ambient_air_humidity(system_id, component_id, last_msg);
	mavlink_test_ambient_luminosity(system_id, component_id, last_msg);
	mavlink_test_activate_water_pump(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // AUTOGARDEN_TESTSUITE_H
