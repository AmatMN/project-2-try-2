#include "wifiEsp.h"

WiFiServer server(80);

void WifiEsp::wifi_Innit() 
{
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

int WifiEsp::loopWifi()
{
  int returnValue = IDLE;
  return returnValue;
}

int WifiEsp::loopWifi(int ultrasoonSensor, bool REED, int* irArray) 
{
  int returnValue = IDLE;
  return returnValue;
}

void WifiEsp::printBaseHtml(WiFiClient &client)
{
}

String WifiEsp::printIR_Data(int* irArray)
{
  String message = "";
  return message;
}