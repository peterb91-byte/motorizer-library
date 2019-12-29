# motorizer-library

I designed the motorizer board and its library in my spare time because I was trying to make arduino powered football playing
robots for my son and i found myself running out of pins on my arduino and I thought "I could do with a I2C motor driver that 
would free up so many pins" so i did a quick search and found nothing so here we are.


arduino library for use with motorizer I2C motor driver.
In time I will upload both the schematic, gerber file and the slave code so anyone can make their own motorizer board.

##  How to use this library.

#### Include the library using.
```
#include<Motorizer.h>
```

#### Initialise a Motorizer board with.
```
Motorizer motor;
Motorizer dave;
ect... 
```

#### In the setup.
```
motor.begin(0x11); //insert the relevant I2C address in the brackets.
dave.begin(0x22); 
```

#### Left motor comands.
```
motor.leftStop();// this comand stops the left motor.
motor.leftForward(255);// this comand makes the left motor turn forwards at max speed 
(the speed is passed in the brackets).
motor.leftBackward(127);// this comand makes the left motor turn backwards at half speed
(will also accept int var up to 255).
```

#### Right motor comands.
```
motor.rightStop();
motor.rightForward(127);
motor.rightBackward(255);
```

#### Common comands.
```
motor.motorize();// this comand needs to be the last comand after any of the above,
its job is to actually send the instructions to the motorizer board and to make the motors turn.
```

have fun motorizing:P
