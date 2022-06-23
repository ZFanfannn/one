#ifndef MQTT_H
#define MQTT_H

#include <PubSubClient.h>
class MQTT
{
public:
	void init();
	void connectMQTTserver();
	void receiveCallback(char* topic, byte* payload, unsigned int length);
};
#endif