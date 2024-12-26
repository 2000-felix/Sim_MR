// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;
 
int Mixture;
int Flaps;
int Throttle;
int Brakes;

void setup() {
 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  
  //inserir botões 3 a 9 exceto 7

// Initialize Joystick Library
  Joystick.begin();
  Joystick.setRxAxisRange(0, 1024);
  Joystick.setRyAxisRange(0, 1024);
  Joystick.setThrottleRange(0, 1024);
  Joystick.setRzAxisRange(0, 1024);
}

void loop() {

// Read Joystick
  Mixture = analogRead(A3); // Hall effect sensor connects to this analog pin
  Flaps = analogRead(A1); // Hall effect sensor connects to this analog pin

// Read Throttle
  Throttle = analogRead(A2); // Potentiometer signal connects to this analog pin

  Brakes = analogRead(A0);
// Output Controls

  Joystick.setRxAxis(Mixture);

  Joystick.setRyAxis(Flaps);

  Joystick.setRzAxis(Brakes);

  Joystick.setThrottle(Throttle);

  Joystick.sendState();

} 