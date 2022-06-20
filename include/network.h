#ifndef NETWORK_H
#define NETWORK_H

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

class Network
{
private:
	 
public:
	void connectWifi(String ssid, String password);
	unsigned int getBilibiliFans(String uid);
};

#endif