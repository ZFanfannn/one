#include <Arduino.h>
#include "network.h"

static const char* ssid = "fff";
static const char* password = "ylc123123";

Network wifi;

void setup()
{
  Serial.begin(9600);
  Serial.println("hello");
  wifi.connectWifi(ssid,password);
  Serial.println(wifi.getBilibiliFans("20259914"));
}

void loop()
{

}