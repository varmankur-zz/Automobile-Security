
/*
Logic by ankurVarma @ sashivarma58@gmail.com
*/

#include <Servo.h>
Servo myservo1;
Servo myservo2;
int pos = 0;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo1.attach(6); 
  myservo2.attach(3); 
  Serial.begin(9600); 
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance <=  10)
  {
    pos = 0;
      myservo1.write(pos);
      myservo2.write(pos);      
      delay(200);
    
  }
  else if (distance >= 10)
  {
    pos = 180;
      myservo1.write(pos);
      myservo2.write(pos);
      delay(200);
    
  }
}
