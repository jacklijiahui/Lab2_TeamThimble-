#include <ESP8266WiFi.h>
#include <Servo.h>

#define trigPin D3   //used for ultrasound
#define echoPin D4   //receive signal 
#define touchPin D5  //for touch sensor

WiFiServer server(80); //Initialize the server on Port 80
Servo servoHammer;     //Hammer motor 
Servo servoLinear;      // base motor 

const short int LED_PIN = 16;  //GPIO16 not used
int pos=0;                // the position of hammer 
int posLinear=0;          // position of track 
int flag3 = 0,flag2 = 0, flag1 = 0;   //record the times that specified distance has beed detected 
long pulse,distance;
int valTouch;             // digital input for touchsensor 
int flagHammer =1; // it should be 1 when using web 
int keyNum =0;     // which key is pressed 


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
  
  //*****************For ultrasound *******************************
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(touchPin,INPUT);
  
  
  //***********************************************
  servoHammer.attach(5);
  servoHammer.write(pos);//used for up and down motor 
  servoLinear.attach(D2);
  servoLinear.write(posLinear);   //used for base motor 
  delay(15);
 
}



void loop() {
   
   measureTheDistance();

   
// **********WIFI service ************
  WiFiClient client = server.available();
  if (!client) { 
  return; 
  }
  Serial.println("Somebody has connected :)");
  //Read what the browser has sent into a String class and print the request to the monitor
  String request = client.readString(); 
  //Looking under the hood 
  Serial.println(request);

   //Handle the Request

  if (request.indexOf("/KEY3") != -1){ 
    flagHammer =0;
    keyNum =3;
       
  } else if (request.indexOf("KEY2") != -1){ 
    flagHammer =0;
    keyNum =2;
    
  } else if (request.indexOf("KEY1") != -1){
    flagHammer =0;
    keyNum =1;
    
  } else if (request.indexOf("STOP") != -1){
    flagHammer = 1;
    keyNum = 0;
    
  } else{
    flagHammer =1;
    keyNum =0;
    
    }
  //Prepare the HTML to respond and add buttons:
  String s ="HTTP/1.1 200 OK\r\n";
  s +="Content-Type: text/html\r\n\r\n";
  s +="<!DOCTYPE>\r\n<html>\r\n";
  s += "<br><br><br>"; 
  s += "<br>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type =\"button\" name=\"b1\" value=\"Stop\" onclick=\"location.href='/STOP'\">";  
  s += "<br><br>";
  s += "<input type =\"button\" name=\"b1\" value=\"KEY1\" onclick=\"location.href='/KEY1'\">";
  s += "<input type =\"button\" name=\"b1\" value=\"KEY2\" onclick=\"location.href='/KEY2'\">";
  s += "<input type =\"button\" name=\"b1\" value=\"KEY3\" onclick=\"location.href='/KEY3'\">";  
  s +="</html>\n";

  //Serve the HTML document to the browser.

  client.flush(); //clear previous info in the stream 
  client.print(s); // Send the response to the client 
  delay(1); 
  Serial.println("Client disonnected"); //Looking under the hood

//*******************key is pressed down************************************
  if(keyNum ==3 || keyNum ==2 || keyNum ==1){
    LinearMotion();
   }
  
  pressTheKey();
  
}



//********find the right key and press down**********
void pressTheKey()
{
  if(distance > 5 && distance < 10 && keyNum==3) // Key 3 is pressed down
  {

   if(flag3 >5){
      if(flagHammer ==0)
      {
        pos = 40;
        servoHammer.write(pos);
        flagHammer = 1; //used to record wether the hammer is pressed down 
        touchOrNot();
       }
       flag3 =0;
          
    }
    else{
      flag3++;
      pos = 0;
      servoHammer.write(pos);
    }
  } 
   
   
  else if(distance > 15 && distance < 20 && keyNum==2) // Key 2 is pressed down
  {

   if(flag2 >5){
      if(flagHammer ==0)
      {
        pos = 80;
        servoHammer.write(pos);
        flagHammer = 1; //used to record wether the hammer is pressed down 
        touchOrNot();
       }
       flag2 =0;
          
    }
    else{
      flag2++;
      pos = 0;
      servoHammer.write(pos);
    }
    }  

    else if(distance > 25 && distance < 30 && keyNum==1) // Key 1 is pressed down
  {

   if(flag1 >5){
      if(flagHammer ==0)
      {
        pos = 120;
        servoHammer.write(pos);
        flagHammer = 1; //used to record wether the hammer is pressed down 
        touchOrNot();
       }
       flag1 =0;
          
    }
    else{
      flag1++;
      pos = 0;
      servoHammer.write(pos);
    }
    }  
  
}


//*********measure the distance****************** 
void measureTheDistance(){
  
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2); //make sure it unenabled 
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);      //HIGH for 10ms will trigger the pulse
  digitalWrite(trigPin,LOW); 
  pulse = pulseIn(echoPin,HIGH); 
  distance = pulse/58;    // pulse/58 = cm
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else{
    Serial.print(distance);
    Serial.print(" cm\n");
  }
  delay(100); //500

}


void touchOrNot(){
  
//  valTouch = digitalRead(touchPin);
//  if(valTouch == HIGH ){
//    pos = 0;
//    servoHammer.write(pos);
//    
//    }
      delay(1000);
      pos = 0;
      servoHammer.write(pos);
    }

void LinearMotion(){    //keep searching until the specified distance is detected 
     
    for(posLinear = 0; posLinear <= 180; posLinear += 1) // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        measureTheDistance();
        servoLinear.write(posLinear);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
    
        if(distance > 5 && distance < 10 && keyNum==3) //Key3 is find 
          { 
            if(flag3>5){
              break;
            } 
            else{
              flag3++;
              pos = 0;
              servoHammer.write(pos); 
            }                  
           }
           
         else if(distance > 15 && distance < 20 && keyNum==2) //Key2 is find 
          { 
            if(flag2>5){
              break;
            } 
            else{
              flag2++;
              pos = 0;
              servoHammer.write(pos); 
            }                  
           }
           
         else if(distance > 25 && distance < 30 && keyNum==1) //Key1 is find 
          { 
            if(flag1>5){
              break;
            } 
            else{
              flag1++;
              pos = 0;
              servoHammer.write(pos); 
            }                  
           }  
                    
         if(posLinear==180){
            posLinear =0;
         }
        }    
    }
