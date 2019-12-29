#include "Arduino.h"
#include "Wire.h"
#include "Motorizer.h"

int leftA = 0;
int leftB = 0;
int leftEnable = 0;
int rightA = 0;
int rightB = 0;
int rightEnable = 0;
int leftSpd = 0;
int rightSpd = 0;
int currMils;
int prevMils;

void Motorizer::begin(int address)
{
    Wire.begin(address);
    //TWBR = 12;
}

void Motorizer::motorize()
{
    currMils = millis();
  if (currMils - prevMils >= 5) {
    prevMils = currMils;
    Wire.beginTransmission(address);
    Wire.write(leftA);
    Wire.write(leftB);
    Wire.write(leftEnable);
    Wire.write(rightA);
    Wire.write(rightB);
    Wire.write(rightEnable);
    Wire.endTransmission();
	}
}

void Motorizer::leftForward(int leftSpd)
{
    leftA = 1;
    leftB = 0;
    leftEnable = leftSpd;
}

void Motorizer::leftBackward(int leftSpd)
{
    leftA = 0;
    leftB = 1;
    leftEnable = leftSpd;
}

void Motorizer::leftStop()
{
    leftA = 0;
    leftB = 0;
    leftEnable = 0;
}

void Motorizer::rightForward(int rightSpd)
{
    rightA = 1;
    rightB = 0;
    rightEnable = rightSpd;
}

void Motorizer::rightBackward(int rightSpd)
{
    rightA = 0;
    rightB = 1;
    rightEnable = rightSpd;
}

void Motorizer::rightStop()
{
    rightA = 0;
    rightB = 0;
    rightEnable = 0;
}