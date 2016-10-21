#include <ESP8266WiFi.h>
#include <Servo.h>

WiFiServer server(80); //Initialize the server on Port 80
Servo myservo;
Servo myservoLR;

const short int LED_PIN = 16;//GPIO16
int pos=90;
int posLR=90;


void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_AP); //Our ESP8266-12E is an AccessPoint 
  WiFi.softAP("Hello_IoT", "12345678"); // Provide the (SSID, password); . 
  server.begin(); // Start the HTTP Server

  //Looking under the hood
  Serial.begin(115200); //Start communication between the ESP8266-12E and the monitor window
  IPAddress HTTPS_ServerIP= WiFi.softAPIP(); // Obtain the IP of the Server 
  Serial.print("Server IP is: "); // Print the IP to the monitor window 
  Serial.println(HTTPS_ServerIP);

  pinMode(LED_PIN, OUTPUT); //GPIO16 is an OUTPUT pin;
  digitalWrite(LED_PIN, LOW); //Initial state is ON

  myservo.attach(5);
  myservo.write(pos); //used for up and down motor 
  
  myservoLR.attach(4);
  myservoLR.write(posLR); // left and right
  delay(15);
  
}



void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if (!client) { 
  return; 
  }
  Serial.println("Somebody has connected :)");
  //Read what the browser has sent into a String class and print the request to the monitor
  String request = client.readString(); 
  //Looking under the hood 
  Serial.println(request);

  // Handle the Request

  if (request.indexOf("/UP") != -1){ 
    
    digitalWrite(LED_PIN, HIGH); 
    pos-=5;
    if(pos<=0){
      pos =0;
      }    
    myservo.write(pos);
    //myservoLR.write(posLR);
    delay(15);
    
    }
  else if (request.indexOf("/DOWN") != -1){ 
    digitalWrite(LED_PIN, LOW); 
     pos+=5;
    if(pos>=180){
      pos =180;
      }    
    myservo.write(pos);
    //myservoLR.write(posLR);
    delay(15);
    
  }
  
 
  

  //Prepare the HTML to respond and add buttons:
  String s ="HTTP/1.1 200 OK\r\n";
  s +="Content-Type: text/html\r\n\r\n";
  s +="<!DOCTYPE>\r\n<html>\r\n";
  s += "<br><br><br>"; 
  s += "<br>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type =\"button\" name=\"b1\" value=\"Turn up\" onclick=\"location.href='/UP'\">";  
  s += "<br><br>";
  s += "<input type =\"button\" name=\"b1\" value=\"Turn left\" onclick=\"location.href='/LEFT'\">";
  s += "<input type =\"button\" name=\"b1\" value=\"Turn down\" onclick=\"location.href='/DOWN'\">";
  s += "<input type =\"button\" name=\"b1\" value=\"Turn right\" onclick=\"location.href='/RIGHT'\">";  
  s +="</html>\n";

  //Serve the HTML document to the browser.

  client.flush(); //clear previous info in the stream 
  client.print(s); // Send the response to the client 
  delay(1); 
  Serial.println("Client disonnected"); //Looking under the hood
  
}












