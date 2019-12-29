 /*  
 * this sketch works now it just needs altering to drive 
 * the motor controler and the variables being given 
 * more explanetary names 
 */
#include <TinyWireS.h>
#define I2C_SLAVE_ADDRESS 0x11

const int rightA = 0;
const int rightB = 1;
const int rightEnable = 5;
const int leftEnable = 7;
const int leftB = 9;
const int leftA = 10;
int a;
int b;
int c;
int d;
int e;
int f;
volatile byte buf [6];


void setup() {
  TinyWireS.begin(I2C_SLAVE_ADDRESS);
  TinyWireS.onReceive(receiveEvent);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightEnable, OUTPUT);
  pinMode(leftEnable, OUTPUT);
}

void loop() {
  TinyWireS_stop_check();
  
}

void receiveEvent() {
  while (0 < TinyWireS.available()) {
    for (byte m = 0; m < 6; m++) {
      buf [m] = TinyWireS.read();
    }
  }
  a = buf [0];
  b = buf [1];
  c = buf [2];
  d = buf [3];
  e = buf [4];
  f = buf [5];
  
  if (a == 1) {
    digitalWrite(leftA, HIGH);
  } else {
    digitalWrite(leftA, LOW);
  }
  if (b == 1) {
    digitalWrite(leftB, HIGH);
  } else {
    digitalWrite(leftB, LOW);
  }
  if (c > 1) {
    analogWrite(leftEnable, c);
  } else {
    digitalWrite(leftEnable, LOW);
  }
  if (d == 1) {
    digitalWrite(rightA, HIGH);
  } else {
    digitalWrite(rightA, LOW);
  }
  if (e == 1) {
    digitalWrite(rightB, HIGH);
  } else {
    digitalWrite(rightB, LOW);
  }
  if (f > 1) {
    analogWrite(rightEnable, f);
  } else {
    digitalWrite(rightEnable, LOW);
  }
}
