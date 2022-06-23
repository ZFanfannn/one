#include "mqtt.h"
#include "network.h"

PubSubClient mqttClient;
//MQTT服务器参数
const char* mqttServer = "test.ranye-iot.net";
const int port = 1883;

const int subQoS = 1;     // 客户端订阅主题时使用的QoS级别
const bool cleanSession = false; // 清除会话（如QoS>0必须要设为false）

const char* willTopic = "willTopic";    // 遗嘱主题名称
const char* willMsg = "willMsg";        // 遗嘱主题信息
const int willQos = 0;                  // 遗嘱QoS
const int willRetain = false;           // 遗嘱保留

void MQTT::init()
{
    mqttClient.setServer(mqttServer, port); //设置MQTT的IP地址和端口
    mqttClient.setKeepAlive(10);  //心跳时间设置
    //mqttClient.setCallback(receiveCallback);//回调函数
}

//回调函数
/*
void receiveCallback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Message Received [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println("");
  Serial.print("Message Length(Bytes) ");
  Serial.println(length);
}
*/
//连接MQTT服务器
void connectMQTTserver()
{
  // 根据ESP8266的MAC地址生成客户端ID（避免与其它ESP8266的客户端ID重名）
  String clientId = "client-ESP8266-"  + WiFi.macAddress();
 
  /* 连接MQTT服务器
  boolean connect(const char* id, const char* user, 
                  const char* pass, const char* willTopic, 
                  uint8_t willQos, boolean willRetain, 
                  const char* willMessage, boolean cleanSession); 
  若让设备在离线时仍然能够让qos1工作，则connect时的cleanSession需要设置为false                
  */
  if (mqttClient.connect(clientId.c_str(),NULL,NULL, willTopic, willQos, willRetain, willMsg, cleanSession)) { 
    Serial.print("MQTT Server Connected. ClientId: ");
    Serial.println(clientId);
    Serial.print("MQTT Server: ");
    Serial.println(mqttServer);    
  } else {
    Serial.print("MQTT Server Connect Failed. Client State:");
    Serial.println(mqttClient.state());
    delay(5000);
  }   
}