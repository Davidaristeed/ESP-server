//ESP32 Web Server: Reading Potentiometer Value using AJAX
//========================================================
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "webpage.h"
//---------------------------------------------------
WebServer server(80);
const char* ssid = "MULLAN";
const char* password = "David-Mullan";

bool l_state = LOW;
bool f_state = LOW;
bool p_state = LOW;

const int lightBulb = 2;
const int fanPot = 3;
const int pumpPot = 4;
//---------------------------------------------------
#include "handleFunctions.h"
//===================================================

void setup()
{ 
  pinMode(lightBulb,OUTPUT);
  pinMode(fanPot,OUTPUT);
  pinMode(pumpPot,OUTPUT);

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
  server.on("/water", handleWater);
  server.on("/pwr", handlePower);

  server.on("/light", handleLight);
  server.on("/pump", handlePump);
  server.on("/fan", handleFan);

  server.begin();
  Serial.println("HTTP server started");
}
//===================================================
void loop(void)
{
  server.handleClient(); delay(2);

  digitalWrite(lightBulb,l_state);
  digitalWrite(fanPot,f_state);
  digitalWrite(pumpPot,p_state);
}



