#include<Arduino.h>
#include "network.h"
#include <PubSubClient.h>
PubSubClient mqttClient;

static const char* ssid = "fff";
static const char* password = "ylc123123";

const char* mqttServer = "test.ranye-iot.net";
const int port = 1883;

const int subQoS = 1;     // 客户端订阅主题时使用的QoS级别
const bool cleanSession = false; // 清除会话（如QoS>0必须要设为false）

const char* willTopic = "willTopic";    // 遗嘱主题名称
const char* willMsg = "willMsg";        // 遗嘱主题信息
const int willQos = 0;                  // 遗嘱QoS
const int willRetain = false;           // 遗嘱保留



Network wifi;

void setup()
{
  Serial.begin(9600);
  Serial.println("hello");
  wifi.connectWifi(ssid,password);
  Serial.println(wifi.getBilibiliFans("20259914"));
  mqttClient.setServer(mqttServer, port); //设置MQTT的IP地址和端口
  mqttClient.setKeepAlive(10);  //心跳时间设置
    //mqttClient.setCallback(receiveCallback);//回调函数
  //mqtt.connectMQTTserver();
  String clientId = "client-ESP8266-"  + WiFi.macAddress();
  if (mqttClient.connect(clientId.c_str(),NULL,NULL, willTopic, willQos, willRetain, willMsg, cleanSession))
  { 
    Serial.print("MQTT Server Connected. ClientId: ");
    Serial.println(clientId);
    Serial.print("MQTT Server: ");
    Serial.println(mqttServer);    
  }
}

void loop()
{

}