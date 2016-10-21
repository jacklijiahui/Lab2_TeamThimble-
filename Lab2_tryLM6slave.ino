#include <ESP8266WiFi.h>
#include <Servo.h>

Servo myservo;
#define contactTo D6
#define contactBack D7
#define forceSensor D1

int var;
int pos=180;
int varFSR;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  
  pinMode(contactTo,INPUT);
  pinMode(contactBack,OUTPUT);
  pinMode(forceSensor,INPUT);
  
  //pinMode(D0,OUTPUT);
  //digitalWrite(contactBack,HIGH);
  myservo.attach(D0);  // attaches the servo on GIO16 to the servo object 
  myservo.write(pos);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(contactBack,HIGH);
  pos=180;
  myservo.write(pos);
  delay(15);

  varFSR = analogRead(forceSensor);
  Serial.print("Analog reading = ");
  Serial.println(varFSR);
  delay(100);
  
  var = digitalRead(contactTo);
  digitalWrite(LED_BUILTIN,HIGH);
  
  if(var == LOW){   
       
    for(pos = 180; pos>=0; pos-=5)     // goes from 180 degrees to 0 degrees 
  {   
    varFSR = analogRead(forceSensor);                           
    
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
    if(varFSR ==HIGH){ //pos ==100||
      pos=180;
      myservo.write(pos);
      delay(15);
      break;
      }
    } 
    digitalWrite(contactBack,LOW);
      pos=180;
      myservo.write(pos);
      delay(6000);
    }
    else {
      digitalWrite(contactBack,HIGH);
      pos=180;
      myservo.write(pos);
      delay(15);
     }

}
