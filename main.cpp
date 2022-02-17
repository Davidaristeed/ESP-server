//ESP32 Web Server: Reading Potentiometer Value using AJAX
//========================================================
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "webpage.h"
//---------------------------------------------------
WebServer server(80);
const char* ssid = "Mullan";
const char* password = "MullanDavid";
bool l_state = LOW;
bool f_state = false;
bool p_state = false;
const int lightBulb = 2;
//---------------------------------------------------
#include "handleFunctions.h"
//===================================================

void setup()
{ 
  pinMode(lightBulb,OUTPUT);
  Serial.begin(115200);
  //-------------------------------------------------
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while(WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    delay(1000); Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //-------------------------------------------------
  server.on("/", handleRoot);
  server.on("/readPOT", handlePOT);
  server.on("/light", handleLight);
  server.begin();
  Serial.println("HTTP server started");
}
//===================================================
void loop(void)
{
  server.handleClient(); delay(2);

  digitalWrite(lightBulb,l_state);
}


