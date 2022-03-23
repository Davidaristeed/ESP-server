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
 Serial.println("Sending temp");
 String POTval = String(analogRead(A0));
 server.send(200, "text/plane", POTval);
}
void handleWater()
{
 Serial.println("Sending Water level");
 String POTval = String(analogRead(A0));
 server.send(200, "text/plane", POTval);
}
void handlePower()
{
 Serial.println("Sending Power Level");
 String POTval = String(analogRead(A0));
 server.send(200, "text/plane", POTval);
}
//----------------------------------------
void handleLight()
{
    Serial.println("Light function");
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
void handlePump()
{
    Serial.println("Pump function");
    p_state = !p_state;
    String state;
    if(p_state)
    {
        state = "ON";
    }
    else{
        state = "OFF";
    }
    server.send(200,"text/plain",state);
}
void handleFan()
{
    Serial.println("Fan function");
    f_state = !f_state;
    String state;
    if(f_state)
    {
        state = "ON";
    }
    else{
        state = "OFF";
    }
    server.send(200,"text/plain",state);
}
