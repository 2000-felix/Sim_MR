// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;
 
int JoystickX;
int JoystickY;
int JoystickZ;
int oldrudder;
int oldroll;
int oldpitch;


void setup() {
 
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  

// Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 1024);
  Joystick.setYAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);
}

void loop() {

// Read Joystick
  //JoystickX = analogRead(A2); // Hall effect sensor connects to this analog pin
  //JoystickY = analogRead(A3); // Hall effect sensor connects to this analog pin
// Read Rudder Pedals
  //JoystickZ = analogRead(A1); // Hall effect sensor connects to this analog pin

//filtro para o roll
 JoystickX = (2*oldroll + analogRead(A2))/3; 
 oldroll = JoystickX;

//filtro para o pitch
 JoystickY = (2*oldpitch + analogRead(A3))/3; 
 oldpitch = JoystickY;

//filtro para o rudder
 JoystickZ = (5*oldrudder + analogRead(A1))/6; 
 oldrudder = JoystickZ;


// Output Controls

  Joystick.setXAxis(JoystickX);

  Joystick.setYAxis(JoystickY);

  Joystick.setZAxis(JoystickZ);

  Joystick.sendState();

} 