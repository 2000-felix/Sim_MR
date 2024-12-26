// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;
 
int JoystickX;
int JoystickY;
int JoystickZ;
int Throttle;


void setup() {
 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  

// Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 1024);
  Joystick.setYAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);
  Joystick.setThrottleRange(0, 1024);
}

void loop() {

// Read Joystick
  JoystickX = analogRead(A1); // Hall effect sensor connects to this analog pin
  JoystickY = analogRead(A2); // Hall effect sensor connects to this analog pin

// Read Rudder Pedals
  JoystickZ = analogRead(A0); // Hall effect sensor connects to this analog pin


// Read Throttle
  Throttle = analogRead(A3); // Potentiometer signal connects to this analog pin


// Output Controls
if (Throttle > 500) {
  Joystick.setXAxis(JoystickX);
}
else {
  Joystick.setYAxis(JoystickY);
}
  Joystick.setZAxis(JoystickZ);
  Joystick.setThrottle(Throttle);

  Joystick.sendState();

} 