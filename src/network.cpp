#include "network.h"
HTTPClient http;
WiFiClient wifiClient;
//连接WiFi
void Network::connectWifi(String ssid, String password)
{   int n = WiFi.scanNetworks(); //判断是否有可连接的网络
    Serial.print("available Network count:");
    Serial.print("[");
    Serial.print(n);
    Serial.print("]");
    Serial.println();

    Serial.println("networks found");
	for (int i = 0; i < n; ++i)
	{
		Serial.print(i + 1);
		Serial.print(": ");
		Serial.print(WiFi.SSID(i));             //显示WiFi名称
		Serial.print(" (");
		Serial.print(WiFi.RSSI(i));             //显示WiFi强度
		Serial.print(")");
		Serial.println(WiFi.encryptionType(i) ); //判断加密状态
		delay(10);
	}

    WiFi.mode(WIFI_STA);                         //WiFi模式
    WiFi.begin(ssid,password);                   //连接WiFi
    delay(200);
    Serial.println();
    Serial.print("connect wifi：");
    while (WiFi.status() != WL_CONNECTED)        //判断连接到状态
    {     
         delay(1000);
         Serial.print("");
         Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println(WiFi.localIP());             //返回IP地址
}

//获取粉丝数量
unsigned int Network::getBilibiliFans(String uid)
{
	String fansCount = "";
	http.begin(wifiClient,"http://api.bilibili.com/x/relation/stat?vmid="+uid);   //设置ESP8266发送HTTP请求的目标UR

	// start connection and send HTTP headerFFF
	int httpCode = http.GET();                                                    //HTTP协议通过网络向服务器发送GET请求

	// httpCode will be negative on error
	if (httpCode > 0)
	{
		// file found at server
		if (httpCode == HTTP_CODE_OK)
		{
			String payload = http.getString();
            Serial.println(payload);
			int pos = (payload.indexOf("follower"));      //string.indexOf("follower")得到第一次出現follower的f的位置  
			fansCount = payload.substring(pos + 10, payload.length() - 2); //string.substring（a,b）a和b之間的字符串
		}
	}
	else
	{
		Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
	}
	http.end();

	return atol(fansCount.c_str());  //atol()：返回转换后的长整数，如果没有执行有效的转换，则返回零。
}