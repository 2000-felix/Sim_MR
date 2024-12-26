// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;
 
int JoystickX;
int JoystickY;
int JoystickZ;
int Throttle;
int JoystickRx;
int oldrudder;
int oldroll;
int oldpitch;
int oldcolective;


void setup() {
 
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

// Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 1024);
  Joystick.setYAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);
  Joystick.setThrottleRange(0, 1024);
}

void loop() {

// Read Joystick
  //JoystickX = analogRead(A1); // Hall effect sensor connects to this analog pin
  //JoystickY = analogRead(A2); // Hall effect sensor connects to this analog pin
// Read Rudder Pedals
  //JoystickZ = analogRead(A1); // Hall effect sensor connects to this analog pin

//Throttle = analogRead(A4);

//filtro para o roll
 JoystickX = (2*oldroll + analogRead(A1))/3; 
 oldroll = JoystickX;

//filtro para o pitch
 JoystickY = (2*oldpitch + analogRead(A2))/3; 
 oldpitch = JoystickY;

//filtro para o rudder
 JoystickZ = (5*oldrudder + analogRead(A3))/6; 
 oldrudder = JoystickZ;

//filtro para o coletivo
 //Throttle = (9*oldcolective + analogRead(A4))/10; 
 //oldcolective = Throttle;

//Throttle = analogRead(A4);
JoystickRx = analogRead(A4);

// Output Controls

  Joystick.setXAxis(JoystickX);

  Joystick.setYAxis(JoystickY);

  Joystick.setZAxis(JoystickZ);

  //Joystick.setThrottle(Throttle);
Joystick.setRxAxis(JoystickRx);

  Joystick.sendState();

} 