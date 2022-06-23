#include <Arduino.h>
#include "network.h"
#include "mqtt.h"

static const char* ssid = "fff";
static const char* password = "ylc123123";

Network wifi;
MQTT mqtt;

void setup()
{
  Serial.begin(9600);
  Serial.println("hello");
  wifi.connectWifi(ssid,password);
  Serial.println(wifi.getBilibiliFans("20259914"));
  mqtt.init();
  //mqtt.connectMQTTserver();
}

void loop()
{

}