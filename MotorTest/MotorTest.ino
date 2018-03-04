// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor2(2);
AF_DCMotor motor(4);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  motor2.setSpeed(255);
  motor2.run(RELEASE);
  motor.setSpeed(255);
  motor.run(RELEASE);
 
}

void loop() {

  motor2.run(FORWARD);
  motor.run(FORWARD);
  delay(3000);
  motor2.run(RELEASE);
  motor.run(RELEASE);
  delay(1000);
  motor2.run(BACKWARD);
  motor.run(BACKWARD);
  delay(3000);   
  motor2.run(RELEASE);
  motor.run(RELEASE);
  delay(1000);

}
