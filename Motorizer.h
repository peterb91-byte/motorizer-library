/* Motorizer.h - library for i2c motor driver.
    created by Peter Beaumont 19/11/2019.
    released into the public domain.
*/

#ifndef Motorizer_h
#define Motorizer_h

#include "Arduino.h"

class Motorizer
{
    public:
        void begin(int address);
        void motorize();
        void leftForward(int leftSpd);
        void leftBackward(int leftSpd);
        void leftStop();
        void rightForward(int rightSpd);
        void rightBackward(int rightSpd);
        void rightStop();
        int leftSpd;
        int rightSpd;
	int leftEnable;
	int rightEnable;
	int address;
	int leftA;
	int leftB;
	int rightA;
	int rightB;
	int currMils;
	int prevMils;
    private:
        //int _address;
	//int _leftA;
	//int _leftB;
	//int _leftEnable;
	//int _rightA;
	//int _rightB;
	//int _rightEnable;
};

#endif