// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;
 
int JoystickX;
int JoystickY;


void setup() {
 
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);


// Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 1024);
  Joystick.setYAxisRange(0, 1024);
}

void loop() {

// Read Joystick
  JoystickX = analogRead(A3); // Hall effect sensor connects to this analog pin
  JoystickY = analogRead(A4); // Hall effect sensor connects to this analog pin


// Output Controls

  Joystick.setXAxis(JoystickX);

  Joystick.setYAxis(JoystickY);

  Joystick.sendState();

} 