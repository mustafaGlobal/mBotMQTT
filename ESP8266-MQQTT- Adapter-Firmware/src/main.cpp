#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>    
#include <SoftwareSerial.h>     

const char* mqttServer = "10.42.0.1";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length);

void setup()
{
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.setDebugOutput(false);
  wifiManager.autoConnect("FET-CAR");
  //Serial.println("Connected to internet!.");
  //Serial.println(WiFi.localIP());
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
  while(!client.connected())
  {
    //Serial.println("Connecting to MQTT");
    if(client.connect("auto", mqttUser, mqttPassword))
      Serial.println("Connected to MQTT broker");
    else
      delay(2000);
  }
  client.publish("esp/state", "0");
  client.subscribe("esp/state");
}

void callback(char* topic, byte* payload, unsigned int length) 
{
 
  //Serial.print("Message arrived in topic: ");
  //Serial.println(topic);
 
  Serial.print("Message:");
  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println("");
  const char* state = "esp/state";
  
  //Serial.println();
  //Serial.println("-----------------------");
}


void loop()
{
  client.loop();
}