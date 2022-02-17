//=============================================
//Handle functions executed upon client request
//=============================================
void handleRoot()
{
 Serial.println("Sending webpage..");
 server.send(200, "text/html", webpageCode);
}
//---------------------------------------
void handlePOT()
{
 Serial.println("Sending portVal");
 String POTval = String(analogRead(A0));
 server.send(200, "text/plane", POTval);
}
//----------------------------------------
void handleLight()
{
    Serial.println("Lights");
    l_state = !l_state;
    String state;
    if(l_state)
    {
        state = "ON";
    }
    else{
        state = "OFF";
    }
    server.send(200,"text/plain",state);
}

