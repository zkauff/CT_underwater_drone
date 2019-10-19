#include <Servo.h>
const int maxAngle = 45;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(2); 
}

void loop() {
  for (pos = 0; pos <= 360; pos += 2) {
    // in steps of 1 degree
    float val = maxAngle * sin(pos * (2* M_PI ) / 360) + maxAngle * 2;
    Serial.println(val);
    myservo.write(val);
    delay(10);                       
  }
}
