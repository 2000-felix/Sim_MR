// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;
 
int Mixture;
int Flaps;
int Brakes;
int Throttle;

int currentButtonState0;
int lastButtonState0;
int currentButtonState1;
int lastButtonState1;
int currentButtonState2;
int lastButtonState2;
int currentButtonState3;
int lastButtonState3;
int currentButtonState4;
int lastButtonState4;
int currentButtonState5;
int lastButtonState5;
int currentButtonState6;
int lastButtonState6;
int currentButtonState7;
int lastButtonState7;

void setup() {
  
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  //pinMode(9, INPUT_PULLUP); 
  //pinMode(10, INPUT_PULLUP);
  

// Initialize Joystick Library
  Joystick.begin();
  Joystick.setRxAxisRange(0, 1024); 
  Joystick.setRyAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);
  Joystick.setThrottleRange(0, 1024);
}

void loop() {

// Read Mixture
  Mixture = analogRead(A4); // Hall effect sensor connects to this analog pin

// Read Mixture
  Flaps = analogRead(A2); // Hall effect sensor connects to this analog pin

// Read Brakes
  Brakes = analogRead(A1); // Hall effect sensor connects to this analog pin

// Read Throttle
  Throttle = analogRead(A3); // Potentiometer signal connects to this analog pin


// Read Switches
int currentButtonState0 = !digitalRead(2); // Button 0
  if (currentButtonState0 != lastButtonState0)
  {
  Joystick.setButton(1, currentButtonState0);
  lastButtonState0 = currentButtonState0;
  }

int currentButtonState1 = !digitalRead(3); // Button 1
  if (currentButtonState1 != lastButtonState1)
  {
  Joystick.setButton(2, currentButtonState1);
  lastButtonState1 = currentButtonState1;
  }
  
int currentButtonState2 = !digitalRead(4); // Button 2
  if (currentButtonState2 != lastButtonState2)
  {
  Joystick.setButton(3, currentButtonState2);
  lastButtonState2 = currentButtonState2;
  }

int currentButtonState3 = !digitalRead(5); // Button 3
  if (currentButtonState3 != lastButtonState3)
  {
  Joystick.setButton(4, currentButtonState3);
  lastButtonState3 = currentButtonState3;
  }
  
int currentButtonState4 = !digitalRead(6); // Button 4
 if (currentButtonState4 != lastButtonState4)
  {
 Joystick.setButton(5, currentButtonState4);
 lastButtonState4 = currentButtonState4;
  } 

int currentButtonState5 = !digitalRead(7); // Button 5
  if (currentButtonState5 != lastButtonState5)
  {
  Joystick.setButton(6, currentButtonState5);
  lastButtonState5 = currentButtonState5;
  } 
  
//int currentButtonState6 = !digitalRead(9); // Button 6
  //if (currentButtonState6 != lastButtonState6)
  //{
  //Joystick.setButton(6, currentButtonState6);
  //lastButtonState6 = currentButtonState6;
 // }  

//int currentButtonState7 = !digitalRead(10); // Button 7
  //if (currentButtonState7 != lastButtonState7)
  //{
  //Joystick.setButton(7, currentButtonState7);
  //lastButtonState7 = currentButtonState7;
 // }  
   
// Output Controls
  Joystick.setRxAxis(Mixture);
  Joystick.setRyAxis(Flaps);
  Joystick.setZAxis(Brakes);
  Joystick.setThrottle(Throttle);

  Joystick.sendState();

} 