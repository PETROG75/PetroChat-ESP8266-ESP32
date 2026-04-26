#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);
String list[20];
int count = 0;
String pmsg;
String msg;
String url;
String cn;
String cpm;
int reqs = 0;
int grs = 0;
void handleman();
void handlepers();
void handlecom();
void handleport();
void handlenotfound();
void handleroot();
const char* ssid = "PetroChat";
const char* pass = "petrog75";

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.softAP(ssid, pass);
Serial.print("WiFi started");
Serial.println(WiFi.softAPIP());
Serial.println("Connection Established");
server.on("/meg11", HTTP_GET, handleman);
server.on("/meg10", HTTP_POST, handlepers);
server.on("/meg4", HTTP_POST, handleport);
server.on("/meg2", HTTP_POST, handlecom);
server.on("/meg", HTTP_GET, handleroot);
server.onNotFound(handlenotfound);
server.begin();
Serial.println("Web server started");
}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
}

void handlecom(){
Serial.println("Client has sent message"); //http://192.168.4.1/meg2?data=""&client=""&pm=""&req=""&gr=""
  if(server.hasArg("data") && server.hasArg("client")){
   msg=server.arg("data");
   cn=server.arg("client"); 
   addValue(cn);
}

}
void handleroot(){
 Serial.println("Client has requested");
  url="";
  url="http://";
  url+= WiFi.softAPIP().toString();
  url+="/meg3?data=\"";
  url+=msg;
  url+="\"";
  url+="&client=\"";
  url+=cn;
  url+="\"";
  url+="&pm=\"\"&req=\"\"&gr=\"\"";
 server.send(200, "text/plain", url);
}

void handlenotfound(){
  server.send(404, "text/plain", "ERR_NOT_FOUND");
}

void handleport(){
Serial.println("Client send a friend request");
  if(server.hasArg("data") && server.hasArg("client") && server.hasArg("pm") && server.hasArg("req") && server.hasArg("gr")){
   cn=server.arg("client");
   addValue(cn);
   cpm=server.arg("pm");
   if(server.arg("req").toInt() == 1){
   reqs = 1;
   if(exists(cpm)){
    url="";
    url="http://";
    url+= WiFi.softAPIP().toString();
    url+="/meg5?data=\"";
    url+=msg;
    url+="\"";
    url+="&client=\"";
    url+=cn;
    url+="\"";
    url+="&pm=\"";
    url+=cpm;
    url+="\"";
    url+="&req=2";
    url+="&gr=2";
    server.send(200, "text/plain", url);
    reqs=0;
    grs=0;
    return;
   }
   }
   if(server.arg("gr").toInt() == 1){
    grs=1;
    url="";
    url="http://";
    url+= WiFi.softAPIP().toString();
    url+="/meg6?data=\"";
    url+=msg;
    url+="\"";
    url+="&client=\"";
    url+=cn;
    url+="\"";
    url+="&pm=\"";
    url+=cpm;
    url+="\"";
    url+="&req=3";
    url+="&gr=3";
   server.send(200, "text/plain", url);
   return;
   }
   
  }
  else{
    url="";
    url="http://";
    url+= WiFi.softAPIP().toString();
    url+="/meg?data=\"";
    url+="Error";
    url+="\"";
    url+="&client=ESP8266";
    url+="&pm=\"\"&req=\"\"&gr=\"\"";
    server.send(200, "text/plain", url);
  }
}

bool exists(String value){
  for (int i = 0; i < count; i++)
  {
    if (list[i] == value)
    {
      return true;
    }
  }
  return false;
}

void addValue(String value){
  if (count >= 20)
  {
    Serial.println("List full");
    return;
  }

  if (exists(value))
  {
    Serial.println("Already exists");
    return;
  }

  list[count] = value;
  count++;
}

bool findValue(String value){
  for (int i = 0; i < count; i++)
  {
    if (list[i] == value)
    {
      return true;
    }
  }
  return false;
}

void handlepers(){
  Serial.println("Client has sent message personal"); //http://192.168.4.1/meg2?data=""&client=""&pm=""&req=""&gr=""
  if(server.hasArg("data") && server.hasArg("client") && server.hasArg("pm")){
   pmsg=server.arg("data");
   cn=server.arg("client"); 
   addValue(cn);
   cpm=server.arg("pm");
}
}

void handleman(){
  Serial.println("Client has requested personal");
  url="";
  url="http://";
  url+= WiFi.softAPIP().toString();
  url+="/meg3?data=\"";
  url+=pmsg;
  url+="\"";
  url+="&client=\"";
  url+=cn;
  url+="\"";
  url+="&pm=\"";
  url+=cpm;
  url+="\"";
  url+="&req=8";
  url+="&gr=8";
 server.send(200, "text/plain", url);
}
