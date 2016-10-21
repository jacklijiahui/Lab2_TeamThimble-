#include <ESP8266WiFi.h>
#include <Servo.h>

Servo myservo;
#define contactTo D6
#define contactBack D7
int var;
int pos=180;

void setup() {
  // put your setup code here, to run once:
  pinMode(contactTo,INPUT);
  pinMode(contactBack,OUTPUT);
  //pinMode(D0,OUTPUT);
  digitalWrite(contactBack,HIGH);
  myservo.attach(D0);  // attaches the servo on GIO16 to the servo object 
  myservo.write(pos);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  var = digitalRead(contactTo);
  digitalWrite(LED_BUILTIN,HIGH);
  
  if(var == LOW){   
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    
    for(pos = 180; pos>=0; pos-=5)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
    if(pos ==100){
      pos=180;
      myservo.write(pos);
      delay(15);
      break;
      }
 } 
    digitalWrite(contactBack,LOW);
      pos=180;
      myservo.write(pos);
    }
    else if (var == HIGH){
      digitalWrite(contactBack,HIGH);
     }

}
