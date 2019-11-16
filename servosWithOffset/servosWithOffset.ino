#include <Servo.h>
const int maxAngle = 15;
const float startAngle =100;
Servo servo1, servo2, servo3, servo4, servo5, servo6;  // create servo object to control a servo

const int servoPin1 = 2;
const int servoPin2 = 3;
const int servoPin3 = 4;
const int servoPin4 = 5;
const int servoPin5 = 6;
const int servoPin6 = 7;
int pos = 0;    
float offSet = 50 * M_PI / 180; //the degree offset on each of the servos
int i;
void setup() {
  Serial.begin(9600);
  servo1.attach(servoPin1); 
  servo2.attach(servoPin2); 
  servo3.attach(servoPin3);
  servo4.attach(servoPin4); 
  servo5.attach(servoPin5); 
  servo6.attach(servoPin6);
}

void loop() {
  for (pos = 0; pos <= 360; pos += 3) {
    float val = maxAngle * sin(pos * (2* M_PI ) / 360) + startAngle;
    Serial.println(val);
    //servo 1 is 5 degrees "ahead" of servo 2, which is 5 degres "ahead" of servo 3 
    servo1.write(val);
    servo4.write(180 - val);//TODO: calculate mirrored servo
    val =  maxAngle * sin(pos * (2* M_PI ) / 360 + offSet) + startAngle;
    servo2.write(val);
    servo5.write(180 - val);//TODO: calculate mirrored servo
    val =  maxAngle * sin(pos * (2* M_PI ) / 360 + offSet * 2) + startAngle;
    servo3.write(val);
    servo6.write(180 - val); //TODO: calculate mirrored servo
    delay(1);             
  }
}
