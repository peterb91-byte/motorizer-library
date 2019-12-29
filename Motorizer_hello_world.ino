/*
this is now the sketch to test the i2c motor driver using
my own custom library Motorizer
*/

#include <Wire.h>
#include <Motorizer.h>

int spd = 100;

Motorizer motor;
void setup() {
  motor.begin(1);
}

void loop() {
  motor.rightForward(spd);
  motor.leftForward(spd);
  motor.motorize();
  delay(1000);
  spd = 30;
  motor.rightBackward(spd);
  motor.leftBackward(spd);
  motor.motorize();
  delay(1000);
  spd = 200;
  
}
