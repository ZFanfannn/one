#include "mqtt.h"

PubSubClient mqttClient(wifiClient);

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
    
}